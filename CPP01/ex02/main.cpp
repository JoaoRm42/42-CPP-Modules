#include <iostream>

void printadress ( std::string* stringPTR, std::string& stringREF ) {
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    return ;
}

void printvalue ( std::string* stringPTR, std::string& stringREF ) {
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << &str << std::endl;
    printadress( stringPTR, stringREF);
    std::cout << str << std::endl;
    printvalue( stringPTR, stringREF );
}