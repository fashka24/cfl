#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "nerd_init.hpp"

using namespace std;

string dotenization(string text){
    string buffer;
    for (int i = 0; i < text.length(); ++i) {
        if (text.at(i) == '.'){
            i++;
            buffer.push_back(text.at(i));
            i++;
            while (i != text.length()-1 && text.at(i) != '.'){
                buffer.push_back(text.at(i));
                i++;
            }
            if (text.at(i) != '.') {
                buffer.push_back(text.at(i));
            } else {
                buffer.clear();
                i--;
            }
        }
    }
    return buffer;
}
void err(string text_err){
    cout << "\x1B[31m"+text_err+"\033[0m" << endl;
}

int main(int argc, char ** argv) {
    char* arg = "";
    if (argv[1] != arg) {
        std::cout << argv[1] << " <- argument [ status: in proces... ]" << std::endl;

    char* vec = argv[1];
    string code,dot_of_file;
    ifstream file (vec);
    {
        stringstream bud;
        if (file.is_open()){
            bud << file.rdbuf();
            dot_of_file = dotenization(vec);
        }else {
            string vwec = argv[1];
            err("ERROR: not found file::"+vwec);
            return -1;
        }
        file.close();
        file.clear();

        code = bud.str();
        bud.clear();

    }
        cout << dot_of_file << endl;
        if (dot_of_file == "nerd"){
            nerd_init(code);
        }else if (dot_of_file == "fhil"){
            cout << "cfl file" << endl;
        }else {
            err("ERROR: don't right dot of file::"+dot_of_file);
            return  -1;
        }

}
    return 0;
}
