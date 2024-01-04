
//
// Created by tc021534 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma execution_character_set("utf-8");
#include <windows.h>
#include <string>
#include "src/List/Graph/Graph.h"


using namespace list;

const int MAX_WORDS = 12351;
const int MAX_WORD_LENGTH = 6;

bool differByOneLetter(const char *word1, const char *word2) {
    int length1 = std::strlen(word1);
    int length2 = std::strlen(word2);
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
        if (strcmp(word,words[i]) == 0) return i;
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(65001);

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    std::ifstream file("C:/Users/tc021534/CLionProjects/graph-puzzle-game-cesmeciktamer/dictionary.txt");
    while (file >> words[wordCount]) {
        wordCount++;
        if (wordCount >= MAX_WORDS) break;
    }
    list::Graph graph(wordCount);
    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (differByOneLetter(words[i], words[j])) {
                graph.addEdge(i, j);
            }
        }
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

    bool* visited = new bool[wordCount]();
    int* predecessorsBFS = new int[wordCount];
    int* predecessorsDijkstra = new int[wordCount];
   std::fill_n(predecessorsBFS,wordCount,-1);
    std::fill_n(predecessorsDijkstra,wordCount,-1);

    //Running BFS
   graph.breadthFirstSearch7(visited,startWordIndex, targetWordIndex,predecessorsBFS,words);

    std::fill_n(visited,wordCount, false);

    //Run dijkstra

    graph.runDijkstra2(startWordIndex,targetWordIndex,predecessorsDijkstra,words);


    delete[] visited;
    delete[] predecessorsBFS;
    delete[] predecessorsDijkstra;

    return 0;
}

