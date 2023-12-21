//
// Created by tc021534 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include "src/List/Graph/Graph.h"

using namespace list;

const int MAX_WORDS = 50000;
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
    if (length1 != length2) return false;
    int differenceCount = 0;
    for (int i = 0; i < length1; i++) {
        if (word1[i] != word2[i]) {
            differenceCount++;
            if (differenceCount > 1) return false;
        }
    }
    return differenceCount == 1;
}

int findWordIndex(const char* word, char words[][MAX_WORD_LENGTH], int wordCount) {
    for(int i = 0; i<wordCount;i++) {
        if (stringLength(word) == stringLength(words[i]) && differByOneLetter(word,words[i])) {
            return i;
        }
    }
    return -1;
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    std::ifstream file("C:/Users/tc021534/CLionProjects/graph-puzzle-game-cesmeciktamer/dictionary.txt");
    while (file >> words[wordCount]) {
        wordCount++;
        if (wordCount >= MAX_WORDS) break;
    }
    std::string startWord, targetWord;
    std::cout << "Enter the start word:";
    std::cin >> startWord;
    std::cout << "Enter de target word:";
    std::cin >> targetWord;

    int startWordIndex = findWordIndex(startWord.c_str(),words,wordCount);
    int targetWordIndex = findWordIndex(targetWord.c_str(),words,wordCount);

    if (startWordIndex == -1 || targetWordIndex == -1) {
        std::cout << "Start or target word not found in the dictionary."<<std::endl;
        return 1;
    }


    list::Graph graph(wordCount);
    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (differByOneLetter(words[i], words[j])) {
                graph.addEdge(i, j);
            }
        }
    }

    bool* visited = new bool[wordCount]();
    int *predecessors = new int[wordCount];
    for (int i = 0; i < wordCount; i++) {
        predecessors[i] = -1;
    }

    graph.breadthFirstSearchForProjectTrial(visited,startWordIndex, predecessors);


    int current = targetWordIndex;
    while (current != -1 && current != startWordIndex) {
        std::cout << words[current] << std::endl;
        current =  predecessors[current];
    }
    if (current == startWordIndex) {
        std::cout << words[startWordIndex] << std::endl;
    }else {
        std::cout<< "No path found" << std::endl;
    }

    delete[] visited;
    delete[] predecessors;

    return 0;
}

