#include <iostream>

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

int main() {
    string text = "hello.fhil.cpp";
    cout << dotenization(text) << endl;
}