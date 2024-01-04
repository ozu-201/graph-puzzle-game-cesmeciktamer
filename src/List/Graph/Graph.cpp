//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include <vector>
#include <limits>
#include "Graph.h"
#include "../../Array/DisjointSet.h"
#include "../Queue.h"
#include "../../Array/Heap/MinHeap.h"
#include "iostream"
using namespace std;
namespace list {


    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);
    }

    void Graph::addEdge(int from, int to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[from].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

    void Graph::connectedComponentsDisjointSet() {
        Edge* edge;
        int toNode;
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                toNode = edge->getTo();
                if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                    sets.unionOfSets(fromNode, toNode);
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        Edge* edge;
        int toNode;
        edge = edges[fromNode].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        Edge* edge;
        int fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[fromNode].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[toNode]){
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    Path *Graph::bellmanFord(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                edge = edges[fromNode].getHead();
                while (edge != nullptr){
                    int toNode = edge->getTo();
                    int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                    edge = edge->getNext();
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                int newDistance = shortestPaths[fromNode].getDistance() + edge->getWeight();
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
        return shortestPaths;
    }

    Edge *Graph::edgeList(int& edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                edgeCount++;
                edge = edge->getNext();
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                list[index] = Edge(edge->getFrom(), edge->getTo(), edge->getWeight());
                index++;
                edge = edge->getNext();
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            Edge* edge = edges[fromNode].getHead();
            while (edge != nullptr){
                int toNode = edge->getTo();
                if (paths[toNode].getDistance() > edge->getWeight()){
                    int position = heap.search(toNode);
                    heap.update(position, edge->getWeight());
                    paths[toNode].setDistance(edge->getWeight());
                    paths[toNode].setPrevious(fromNode);
                }
                edge = edge->getNext();
            }
        }
    }

    void Graph::breadthFirstSearchForProjectTrial(bool *visited, int startNode, int* predecessors) {
        int* queue = new int[vertexCount];
        int front = 0, rear = -1;

        queue[++rear] = startNode;
        visited[startNode] = true;
        predecessors[startNode] = -1;

        while (front <= rear) {
            int currentNode = queue[front++];

            Edge* edge = edges[currentNode].getHead();
            while (edge != nullptr) {
                int toNode = edge->getTo();
                    if(!visited[toNode]) {
                        visited[toNode] = true;
                        queue[++rear] = toNode;
                        predecessors[toNode] = currentNode;

                    }
                    edge = edge->getNext();
            }
        }

    }

    void Graph::breadthFirstSearch7(bool *visited,int startNode, int targetNode, int* predecessors,char words[][MAX_WORD_LENGTH]) {
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        visited[startNode] = true;
        predecessors[startNode] = -1;
        cout <<"Visited: ";
        while (!queue.isEmpty()) {
            int currentNode = queue.dequeue()->getData();
            cout << words[currentNode] << " ";

            if (currentNode == targetNode) {
                cout << endl;
                break;
            }
            Edge* edge = edges[currentNode].getHead();
            while (edge != nullptr) {
                int toNode = edge->getTo();
                if (!visited[toNode]) {
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                    predecessors[toNode] = currentNode;
                }
                edge = edge->getNext();
            }
        }
        cout << "Shortest path from '" << words[startNode] << " 'to '" << words[targetNode] << "' (BFS): ";
        printPath2(predecessors,startNode,targetNode,words);
    }

    void Graph::runDijkstra2(int startNode, int targetNode,int* predecessors,char words[][MAX_WORD_LENGTH] ) {
        vector<int> distance(vertexCount, numeric_limits<int>::max());
        vector <bool> visited(vertexCount, false);
        distance[startNode] = 0;
            for(int count = 0; count < vertexCount-1; count++) {
                int u = -1;
                int minDistance = numeric_limits<int>::max();
                    for(int v = 0; v<vertexCount;v++) {
                        if (!visited[v] && distance[v] <= minDistance) {
                            minDistance = distance[v];
                            u = v;
                        }
                    }
                    visited[u] = true;

                    for(int v = 0; v<vertexCount;v++) {
                        if(!visited[v] && isEdge(u,v) && distance[u] != numeric_limits<int>::max() && distance[u] + 1 < distance[v]) {
                            distance[v] = distance[u] + 1;
                            predecessors[v] = u;
                        }
                    }
            }
            cout << "Shortest Path from '" << words[startNode] << "' to '" <<words[targetNode] << " '(Dijkstra): ";
            printPath2(predecessors,startNode,targetNode,words);
    }
    bool Graph::isEdge(int u, int v) {
        for(Edge* edge = edges[u].getHead(); edge!= nullptr; edge = edge->getNext()) {
            if (edge->getTo() == v) {
                return true;
            }
        }
        return false;
    }

    void Graph::printPath2(int* predecessors, int startNode, int targetNode,char words[][MAX_WORD_LENGTH]) {
        vector<string> path;
        int currentNode = targetNode;
        while (currentNode != -1) {
            path.push_back(words[currentNode]);
            currentNode = predecessors[currentNode];
        }
        if (!path.empty() && path.back() == words[startNode]) {
            for(int i = path.size()-1; i>=0;i--) {
                cout << path[i];
                    if(i > 0) {
                        cout << " ->";
                    }
            }
            cout << endl;
        }else {
            cout << "'No path found from '" << words[startNode] << " ' to '" << words[targetNode] << "'." << endl;
        }
    }
}