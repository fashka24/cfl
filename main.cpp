#include <iostream>

int main(int argc, char ** argv) {
    char* arg = "";
    if (argv[1] != arg) {
        std::cout << argv[1] << " <- argument" << std::endl;
    }
    return 0;
}
