/* Activity: Implements the PRIMS algorithm to construct the MST.
INTRODUCTION: It falls under a class of algorithms called greedy algorithms that find the local optimum in the hopes of finding a global optimum. We start from one vertex and keep adding edges with the lowest weight until we reach our goal. The steps for implementing Prim's algorithm are as follows:
1. Initialize the minimum spanning tree with a vertex chosen at random.
2. Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree.
3. Keep repeating step 2 until we get a minimum spanning tree. */

#include <climits>
#include<iostream>
using namespace std;

#define V 5 // Number of vertices in the graph

// A utility function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++) {
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
  }
  return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
  cout<<"\n Edge \t| Weight \n\t| " << endl;
  for (int i = 1; i < V; i++) {
    cout<<""<< parent[i]<<" -> "<< i<<"  | "<<graph[i][parent[i]]<<endl;
  }
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
  // Array to store constructed MST
  int parent[V];
  // Key values used to pick minimum weight edge in cut
  int key[V];
  // To represent set of vertices included in MST
  bool mstSet[V];
  // Initialize all keys as INFINITE
  for (int i = 0; i < V; i++) {
    key[i] = INT_MAX, mstSet[i] = false;
  }
  // Always include first 1st vertex in MST. Make key 0 so that this vertex is picked as first vertex.
  key[0] = 0;
  parent[0] = -1; // First node is always root of MST
  // The MST will have V vertices
  for (int count = 0; count < V - 1; count++) {
    // Pick the minimum key vertex from the set of vertices not yet included in MST
    int u = minKey(key, mstSet);
    // Add the picked vertex to the MST Set
    mstSet[u] = true;
    // Update key value and parent index of the adjacent vertices of the picked vertex.
    // Consider only those vertices which are not yet included in MST
    for (int v = 0; v < V; v++) {
      // graph[u][v] is non zero only for adjacent vertices of m
      // mstSet[v] is false for vertices not yet included in MST
      // Update the key only if graph[u][v] is smaller than key[v]
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }
  // print the constructed MST
  printMST(parent, graph);
}

// driver program to test above function
int main() {
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                      { 2, 0, 3, 8, 5 },
                      { 0, 3, 0, 0, 7 },
                      { 6, 8, 0, 0, 9 },
                      { 0, 5, 7, 9, 0 } };

  // Print the solution
  primMST(graph);

  return 0;
}

//GRAPH_TAKEN:
//         2
//   [0]--------[1]---|
//     |       / |    |
//     |      /  |3   |
//    6|   8 /   |    |
//     |    /    |    |
//     |   /     |    |
//     |  /      |    |
//    [3]       [2]   |5 
//     |         |    |
//     |         |7   |
//    9|         |    |
//     |         |    |
//     |--------[4]---|
//

