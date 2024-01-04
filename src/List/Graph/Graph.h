//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include <unordered_map>
#include <string>
#include "EdgeList.h"
#include "../../General/AbstractGraph.h"

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
        std::unordered_map<std::string, int> wordToIndexMap;
    public:
        const static int MAX_WORD_LENGTH = 6;
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentsDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        void prim();

        void breadthFirstSearchForProjectTrial(bool *visited, int startNode, int *predecessors);
        void breadthFirstSearch7(bool *visited,int startNode, int targetNode, int* predecessors,char words[][MAX_WORD_LENGTH]);
        void runDijkstra2(int startNode, int targetNode,int* predecessors,char words[][MAX_WORD_LENGTH]);
        void printPath2(int* predecessors, int startNode, int targetNode,char words[][MAX_WORD_LENGTH]);
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;


        bool isEdge(int u, int v);
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
