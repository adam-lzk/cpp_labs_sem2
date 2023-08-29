#pragma once
#include <iostream>

class Word {
private:
    char *word = new char[255] {};
    size_t size = 0;

public:
    Word() = default;

    Word(char* Word) {
        strcpy(word, Word);
        size = strlen(Word);
    }

    Word(const char symbol, const int number) {
        strcpy(word, std::string(number, symbol).c_str());
        size = strlen(word);
    }

    Word(const char* Word, const int length) {
        strncpy(word, Word, length);
        size = strlen(word);
    }

    Word(const Word& Word) {
        strcpy(word, Word.word);
        size = Word.size;
    }

    Word(Word&& Word) noexcept {
        size = Word.size;
        word = std::move(Word.word);
        delete[] Word.word;
        Word.size = 0;
    }

    ~Word() {
        delete[] word;
    }

    char* GetWord() const { return word; }

    void SetWord(const char* Word) {
        delete[] word;
        word = new char[255];
        strcpy(word, Word);
        size = strlen(Word);
    }

    size_t GetSize() const { return size; }

    friend std::ostream& operator<<(std::ostream &out, const Word &Word) {
        out << Word.word << std::endl;
        return out;
    }

    friend bool operator>(const Word &word1, const Word &word2) {
        auto result = strcmp(word1.word, word2.word);

        if(result >= 1) {
            return true;
        }
        else return false;
    }
};
