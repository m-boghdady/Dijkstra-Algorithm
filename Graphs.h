#ifndef GRAPHS_H
#define GRAPHS_H
#include <string>
#include <climits> // For INT_MAX
#include "Edge.h"
using namespace std;

const int Vmax = 50;                    // Maximum number of vertices
const int Emax = Vmax*(Vmax-1)/2;       // Maximum number of edges

class Graphs
{
public:
    // Member Functions
    Graphs();
    ~Graphs();
    char Vname(const int s) const;      // Map vertex number to a name (character)
    void getGraph(string fname);        // Get Graph from text File (fname)
    void dispGraph() const;             // Display Ajacency Matrix
    int  No_of_Verices() const;         // Get number of vertices (V)
    int  No_of_Edges() const;           // Get Number of Non-zero edges (E)
    void dispEdges() const;             // Display Graph edges
    void DFS();                         // Depth First Search Traversal (DFS)
    void shPath(int s);                 // Shortest paths from node (s)

private:
    int V, E;                           // No.of vertices (V) and edges (E) 
    weightType AdjMatrix[Vmax][Vmax];   // Adjacency Matrix
    Edge edges[Emax];                   // Array of non-zero edges
    weightType distance[Vmax];          // Distance array for shortest paths
    int via[Vmax];                      // Via array for shortest paths
    bool processed[Vmax];               // processed array for shortest paths
    int order;                          // Order of Visit of a node in the DFS
    int val[Vmax];                      // Array holding order of traversal of nodes
    void getEdges();                    // Get Non-Zero edges from adjacency matrix  
    void printEdge(Edge e) const;       // Output an edge (e)
    void printPath(int s, int i) const; // Print path from source (s) to destination (i)
    void visit(int k);                  // Node Visit Function (needed for DFS)
    void visit(int v, bool visited[]);  // Recursive function for DFS
    int minDistance(weightType dist[], bool processed[]); // Helper for Dijkstra's Algorithm
};

#endif // GRAPHS_H
