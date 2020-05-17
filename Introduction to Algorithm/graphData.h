#pragma once
#include "graph_node.h"
#include "graph_edge.h"
#include <map>
#include <string>


class GraphData
{

public:
    //is oriented graph
    bool isOriented;
    //boolean adjacency matrix
    bool** booleanMatrix;
    //distance adjacency matrix
    Distance** distanceMatrix;
    //adjacency list array
    GraphNode* adjList;
    //store edges array/list
    Edge** edges;
    //name to index map
    std::map<std::string, int>name2index;
    //index to name map
    std::map<int, std::string>index2name;
    int numVertex;
    int numEdge;


    GraphData();
    ~GraphData();
    //set adjacency matrix using 0-1 for not connecting and connecting
    void inputBoolMatrix();
    //set adjacency matrix using distance,-1 for INF
    void inputDistanceMatrix();
    //print adjacency matrix(distance)
    void printDistanceMatrix(int w = 4, std::string info = "\nThe distance matrix is:\n", Distance** distance = NULL);
    // false:input manually; true:0-1,1-2...
    void setNameIndexMap(int isDefault = true);
    //print bool matrix
    void printBooleanMatrix(int w = 4);
    //print adjacency list(distance)
    void printAdjList(int w = 4);
    bool setListFromMatrix();
    void setEdgesFromMatrix();
    //print edges
    void printEdges();
    int** BFS(Vertex vertex);
    int** DFS(Vertex vertex);
    int** DFSvisit(Vertex vertex, int time, Color color[], int** ans);
    GraphNode* MSTkruskal();
    GraphNode* MSTprim();
    void TopoLogicalSort();
    void getTwoVertexShortPath();
    void getAllPairShortPath();
    Distance getAdjDistance(Vertex a, Vertex b);
};