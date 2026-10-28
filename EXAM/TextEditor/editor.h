#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class TextEditor
{
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data;
    Position parser;
    vector<pair<vector<string>, Position>> history;

public:
    TextEditor(): parser({0, 0}) {data.push_back("\n");}

    void move(Position dest)
    {
        if(dest.first <= 0){
            dest.first = 0;
        }else if(dest.first >= data.size()){
            dest.first = data.size() - 1;
        }

        if(dest.second <= 0){
            dest.second = 0;
        }else if(dest.second >= data[dest.first].size()){
            dest.second = data[dest.first].size() - 1;
        }

        parser = dest;
    }

    void write(const std::string &str)
    {
        history.push_back(make_pair(data, parser));

        string now = data[parser.first];
        string qian = now.substr(0, parser.second);
        string hou = now.substr(parser.second, now.size() - parser.second);

        data[parser.first] = qian + str + hou;
        parser.second += str.size();
    }

    void newline()
    {
        history.push_back(make_pair(data, parser));

        string now = data[parser.first];
        string qian = now.substr(0, parser.second);
        string hou = now.substr(parser.second, now.size() - parser.second);

        data[parser.first] = qian + '\n';
        data.insert(data.begin() + parser.first + 1, hou);

        parser.first ++;
        parser.second = 0;
    }

    void del()
    {
        history.push_back(make_pair(data, parser));
        if(parser.first == 0 && parser.second == 0){
            return;
        }
        

        if(parser.second == 0){
            string now = data[parser.first];
            string& qh = data[parser.first - 1];

            parser.second = qh.size() - 1;

            qh.pop_back();
            qh += now;

            data.erase(data.begin() + parser.first);

            parser.first --;

            return;
        }

        string& now = data[parser.first];
        parser.second --;
        now.erase(now.begin() + parser.second);

        return;
    }
    void screenShot()
    {
        cout << "### SCREENSHOT BEGIN ###" << endl;

        if(data.empty()){
            cout << "*" << endl;
        }else{
            for(int i = 0; i < data.size(); i ++){
                if(i != parser.first){
                    cout << data[i];
                }else{
                    string pl = data[i];
                    string qian = pl.substr(0, parser.second);
                    string hou = pl.substr(parser.second, pl.size() - parser.second);

                    cout << qian << "*" << hou;
                }
            }
        }

        cout << "### SCREENSHOT END ###" << endl;
    }
    void undo()
    {
        if(history.empty()){
            return;
        }

        data = history.back().first;
        parser = history.back().second;

        history.pop_back();
    }

    void apply(const std::string &opt)
    {
        stringstream ss(opt);
        string cmt;
        ss >> cmt;

        if(cmt == "MOVE"){
            int x;
            int y;

            ss >> x >> y;

            move({x, y});
            return;
        }

        if(cmt == "WRITE"){
            string wt;
            ss >> wt;

            write(wt);
            return;
        }

        if(cmt == "NEWLINE"){
            newline();
            return;
        }

        if(cmt == "DELETE"){
            del();
            return;
        }

        if(cmt == "UNDO"){
            undo();
            return;
        }

        if(cmt == "SCREEN"){
            screenShot();
            return;
        }

    }
};