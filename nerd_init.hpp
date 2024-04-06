#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
void nerd_init(string argument) {
    string code = argument;

    string result;
    for (int i = 0; i < code.length(); ++i) {
        if (isspace(code.at(i))) {
            if (code.at(i) == ' ') {
                result.push_back(' ');
            }
        } else if (code.at(i) == '<') {
            string buf;
            i++;
            while (code.at(i) != '>') {
                buf.push_back(code.at(i));
                i++;
            }
            if (buf == "p") {
                result.push_back('\n');
            } else if (buf == "down_tab") {
                for (int j = 0; j < 5; ++j) {
                    result.push_back('\n');
                }
            } else if (buf == "tab") {
                result.push_back('\t');
            } else {
                cerr << "WARN: not found teg '" + buf + "'" << endl;
            }
            buf.clear();
        } else if (code.at(i) == '\\') {
            if (code.at(i + 1) == 'n') {

                result.push_back('\n');
                i++;
            } else if (code.at(i + 1) == 'e') {
                result.push_back('\n');
                result.push_back('\n');
                i++;
            } else if (code.at(i + 1) == 't') {
                result.push_back('\t');
                i++;
            } else if (code.at(i + 1) == 'f') {
                result.push_back('\f');
                i++;
            } else if (code.at(i + 1) == '\"') {
                result.push_back('\"');
                i++;
            } else if (code.at(i + 1) == '\'') {
                result.push_back('\'');
                i++;
            } else {
                result.push_back(code.at(i));
            }
        } else { result += code.at(i); }
    }
    cout << result << endl;
}