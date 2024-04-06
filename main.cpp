#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void err(string text_err){
    cout << "\x1B[31m"+text_err+"\033[0m" << endl;
}

int main(int argc, char ** argv) {
    char* arg = "";
    if (argv[1] != arg) {
        std::cout << argv[1] << " <- argument [ status: in proces... ]" << std::endl;

    char* vec = argv[1];
    string code;
    ifstream file (vec);
    {
        stringstream bud;
        if (file.is_open()){
            bud << file.rdbuf();
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
    cout << code << endl;
    }
    return 0;
}
