#pragma once
#include "iargument.h"
#include <optional>
#include <sstream>
#include <type_traits>

template<typename T>
class ValueArgument : public IArgument {
public:
    std::optional<T> value;
    T default_value;
    
    ValueArgument(char s, const std::string& l, const std::string& d, T def_val)
        : IArgument(s, l, d), value(def_val), default_value(def_val) {}

    bool parse(const std::vector<std::string>& args, size_t& index) override {
        if (index >= args.size())
            return false;

        std::string str = args[index];
        if (str[0] == '-')
            return false;
        
        std::stringstream sst;
        sst << str;
        T val;
        if (!(sst >> val))
            return false;
            
        value = val;
        return true;
    }

    std::string get_info() const override {
        std::ostringstream default_value_stream;
        default_value_stream << default_value;

        return "  -" + 
               std::string(1, short_name_) +
               ", --" + 
               long_name_ +
               "=<value>\t" +
               description_ +
               " (default: " +
               default_value_stream.str() +
               ")";
    }
};