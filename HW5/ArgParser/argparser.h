#pragma once
#include "flagargument.h"
#include "valueargument.h"

#include <memory>
#include <map>
#include <iostream>
#include <vector>
#include <optional>
#include <string>
#include <sstream>
#include <type_traits>

class ArgParser {
private:
    std::string program_description_;
    std::vector<std::unique_ptr<IArgument>> arguments_;
    std::map<std::string, IArgument*> long_name_map_;
    std::map<char, IArgument*> short_name_map_;
    bool help_wanted_ = false;

    void Unknown(std::string arg){
        std::cout << "Error: Unknown argument: " << arg << std::endl;
    }
    void No_value(std::string name){
        std::cout << "Error: Argument " << name << " requires a value." << std::endl;
    }

public:
    ArgParser(const std::string& description) : program_description_(description) {
        addFlag('h', "help", "Show this help message.");
    }

    void addFlag(char s, const std::string& l, const std::string& d) {
        // do something
        arguments_.push_back(std::make_unique<FlagArgument>(s, l, d));
        long_name_map_[l] = arguments_.back().get();
        short_name_map_[s] = arguments_.back().get();
    }

    template<typename T>
    void addValue(char s, const std::string& l, const std::string& d, T def_val) {
        // do something
        arguments_.push_back(std::make_unique<ValueArgument<T>>(s, l, d, def_val));
        long_name_map_[l] = arguments_.back().get();
        short_name_map_[s] = arguments_.back().get();
    }

    bool parse(int argc, char* argv[]) {
        bool ret = true;

        std::vector<std::string> args(argv + 1, argv + argc);

        for (size_t i = 0; i < args.size(); i++){
            std::string str = args[i];

            if(str.substr(0,2) == "--"){
                int p = str.find("=");
                std::string argname;
                if (p == std::string::npos){
                    argname = str.substr(2);
                    i ++;
                }else{
                    argname = str.substr(2, p - 2);
                    args[i] = str.substr(p + 1, str.size() - p - 1);
                }

                auto it = long_name_map_.find(argname);
                if (it == long_name_map_.end()){
                    Unknown("--" + argname);
                    return false;
                }else{
                    if (!it->second->parse(args, i)){
                        No_value(it->second->long_name_);
                        return false;
                    }
                }
            }else{
                int p = str.find("=");
                std::string argname;
                if (p == std::string::npos){
                    i++;
                    argname = str.substr(1);
                }else{
                    argname = str.substr(1, p - 1);
                    args[i] = str.substr(p + 1, str.size() - p - 1);
                }
                if (argname.size() >= 2){
                    Unknown("-" + argname);
                    return false;
                }
                char c = argname[0];
                auto it = short_name_map_.find(c);
                if (it == short_name_map_.end()){
                    Unknown("-" + argname);
                    return false;
                }else{
                    if (!it->second->parse(args, i)){
                        No_value(it->second->long_name_);
                        return false;
                    }
                }
            }
        }

        help_wanted_ = get<bool>("help").value_or(false);

        return ret;
    }

    template<typename T>
    std::optional<T> get(const std::string& name) const {
        auto it = long_name_map_.find(name);
        if (it == long_name_map_.end()) {
            return std::nullopt;
        }

        IArgument* arg = it->second;

        if constexpr (std::is_same_v<T, bool>) {
            if (auto* flag_arg = dynamic_cast<FlagArgument*>(arg)) {
                return flag_arg->value;
            }
        }

        if (ValueArgument<T>* val_arg = dynamic_cast<ValueArgument<T>*>(arg)) {
            return val_arg->value;
        }

        return std::nullopt;
    }

    bool wantsHelp() const { return help_wanted_; }
    
    void printHelp() const {
        std::cout << program_description_ << "\n\nUsage:\n";
        for (const auto& arg : arguments_) {
            std::cout << arg->get_info() << std::endl;
        }
    }
};