// make - g++ 2_1_A9.cpp -o f -std=c++17
// start - g++ 2_1_A9.cpp -o f -std=c++17 && ./f

// g++ -std=c++11 2_1_A9.cpp -o 2_1_A9

#include <iostream>
#include "2_1_A9_Header.h"

Word CreateWord() {
    std::cout << "Enter the word: " << std::endl;
    char temp[255] {};
    std::cin.getline(temp, 255);
    Word word(temp);

    return word;
}

void Task() {
    Word firstWord = CreateWord();
    Word secondWord = CreateWord();

    if(firstWord > secondWord) {
        std::cout << firstWord << std::endl;
    }
    else {
        std::cout << secondWord << std::endl;
    }
}

int main() {
    Task();

    return 0;
}