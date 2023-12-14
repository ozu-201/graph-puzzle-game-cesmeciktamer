//
// Created by tc021534 on 12/14/2023.
//
#include "List/Graph/Graph.h"
#include <cstring>
#include "iostream"
#include "fstream"

const int MAX_WORDS = 10000;
const int MAX_WORD_LENGTH = 6;


int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

bool differByOneLetter(const char *word1, const char *word2) {
    int length1 = stringLength(word1);
    int length2 = stringLength(word2);
    if (length1 != length2)
        return false;
    int differenceCount = 0;
    for (int i = 0; i < length1; i++) {
        if (word1[i] != word2[i]) {
            differenceCount++;
            if (differenceCount > 1)
                return false;
        }
    }
    return differenceCount == 1;
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    std::ifstream file("dictionary.txt");
    while (file >> words[wordCount]) {
        wordCount++;
        if (wordCount >= MAX_WORDS)
            break;
    }
    list::Graph graph(wordCount);

    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (differByOneLetter(words[i], words[j])) {
                graph.addEdge(i, j);
            }
        }
    }
   // list::Graph ~graph();
    return 0;
}

