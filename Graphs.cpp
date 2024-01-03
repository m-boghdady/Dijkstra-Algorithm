// FILE: graphs.cpp
// Graph Library Implementation File for Asn 6

#include <fstream>		// For reading file from disk
#include <iostream>
#include <string>		// For file name
#include <iomanip>
#include "Edge.h"		// Deinition of an Edge

using namespace std;

// Constructor
Graphs::Graphs()
{
	E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const
{
	return char(s+65);
}

// Get Graph from text File (file name is stored in string fname)
// Graph is stored in adjacency matrix
void Graphs::getGraph(string fname)		
{
   // Local data ...
	weightType wi;
	ifstream source;

	source.open(fname.c_str()); 
	source >> V;	// Read no. of verices (V)
	
	// Input weights from the file into a 2-D 
	// Adjacency Matrix of V rows and V columns
	for (int r = 0; r < V; r++)
	{
		// get V weights for row [r] from file
		// put V weights in adjacency matrix at row [r]
	}
	// close file
	
	
}

// Display Adjacency Matrix
void Graphs::dispGraph() const
{
	int i,j;
	cout<<"Adjacency Matrix\n";
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
			cout<< setw(3)<< AdjMatrix[i][j] << " ";
		cout<< endl;
	}
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[]. 
void Graphs::getEdges()			
{
	int r , c;
	int i = 0;
	weightType weight;

	// Only examine weights above the diagonal 
	for (r = 0; r <= V-2; r++)
		for (c = r+1; c <= V-1; c++)
		{
			weight = AdjMatrix[r][c];
			if (weight > 0)
			{
				// save (r,c,weight) in edges[i]
				edges[i].u = r;
				edges[i].v = c;
				edges[i].w = weight;
				i++;
			}
		}

	E = i;		// Number of non-zero edges
	
}

// Get number of vertices (V)	
int Graphs::No_of_Verices() const 				
{
	return V;
}

// Get Number of Non-zero edges (E)
int Graphs::No_of_Edges() const 					
{
	return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const 			
{
	cout << Vname(e.u) << " " << Vname(e.v) << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::dispEdges() const
{
	cout<<"Graph Edges\n";
	for (int i = 0; i < E; i++) 
		printEdge(edges[i]);
}


void Graphs::DFS() {
    // Initialize all vertices as not visited
    bool visited[Vmax];
    for (int i = 0; i < Vmax; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to print DFS traversal
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visit(i, visited);
        }
    }
}

void Graphs::visit(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << Vname(v) << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < V; i++) {
        if (AdjMatrix[v][i] != 0 && !visited[i]) {
            visit(i, visited);
        }
    }
}


void Graphs::shPath(int s) {
    // Initialize distances to all vertices as infinite and processed[] as false
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX, processed[i] = false;
    }

    // Distance of source vertex from itself is always 0
    distance[s] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(distance, processed);

        // Mark the picked vertex as processed
        processed[u] = true;

        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update distance[v] only if is not in processed, there is an edge from u to v,
            // and total weight of path from s to v through u is smaller than current value of distance[v]
            if (!processed[v] && AdjMatrix[u][v] && distance[u] != INT_MAX && distance[u] + AdjMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + AdjMatrix[u][v];
                via[v] = u;
            }
        }
    }
}

int Graphs::minDistance(weightType dist[], bool processed[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (processed[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}
