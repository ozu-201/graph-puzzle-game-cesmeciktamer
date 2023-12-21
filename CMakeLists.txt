cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-cesmeciktamer)

set(CMAKE_CXX_STANDARD 17)
#add_library(graph-puzzle-game-cesmeciktamer src/List/Node.cpp src/List/Node.h src/List/LinkedList.cpp src/List/LinkedList.h src/List/Hash.cpp src/List/Hash.h src/List/Queue.cpp src/List/Queue.h src/List/Stack.cpp src/List/Stack.h src/List/Graph/Edge.cpp src/List/Graph/Edge.h)
add_executable(graph-puzzle-game-cesmeciktamer
        main.cpp
        src/List/Graph/Edge.cpp
        src/List/Graph/EdgeList.cpp
        src/List/Graph/Graph.cpp
        src/List/Hash.cpp
        src/List/LinkedList.cpp
        src/List/Node.cpp
        src/List/Queue.cpp
        src/List/Stack.cpp
        src/General/AbstractGraph.cpp
        src/General/Path.cpp
        src/Array/Graph/Graph.cpp
        src/Array/Heap/MinHeap.cpp
        src/Array/Heap/Heap.cpp
        src/Array/Heap/HeapNode.cpp
        src/Array/DisjointSet.cpp
        src/Array/Element.cpp
        src/Array/Hash.cpp
        src/Array/Queue.cpp
        src/Array/Set.cpp
        src/Array/Stack.cpp
        src/Array/Heap/DHeap.h src/Array/Heap/DHeap.cpp src/Array/Heap/MaxDHeap.cpp src/Array/Heap/MaxHeap.cpp src/Array/Heap/MinDHeap.cpp)



#add_library(graph-puzzle-game-cesmeciktamer src/List/Node.cpp src/List/Node.h src/List/LinkedList.cpp src/List/LinkedList.h src/Array/Element.cpp src/Array/Element.h src/Array/Stack.cpp src/Array/Stack.h src/List/Stack.cpp src/List/Stack.h src/Array/Queue.cpp src/Array/Queue.h src/List/Queue.cpp src/List/Queue.h src/Array/Hash.cpp src/Array/Hash.h src/List/Hash.cpp src/List/Hash.h src/Array/Heap/Heap.cpp src/Array/Heap/Heap.h src/Array/Heap/HeapNode.cpp src/Array/Heap/HeapNode.h src/Array/Heap/DHeap.cpp src/Array/Heap/DHeap.h src/Array/Set.cpp src/Array/Set.h src/Array/DisjointSet.cpp src/Array/DisjointSet.h src/Array/Graph/Graph.cpp src/Array/Graph/Graph.h src/List/Graph/Edge.cpp src/List/Graph/Edge.h src/List/Graph/EdgeList.cpp src/List/Graph/EdgeList.h src/List/Graph/Graph.cpp src/List/Graph/Graph.h src/General/Path.cpp src/General/Path.h src/General/AbstractGraph.cpp src/General/AbstractGraph.h src/Array/Heap/MaxHeap.cpp src/Array/Heap/MaxHeap.h src/Array/Heap/MaxDHeap.cpp src/Array/Heap/MaxDHeap.h src/Array/Heap/MinHeap.cpp src/Array/Heap/MinHeap.h src/Array/Heap/MinDHeap.cpp src/Array/Heap/MinDHeap.h)