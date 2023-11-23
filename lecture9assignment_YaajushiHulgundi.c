
// THe Dijkstra algorithm is used to find the shortest path from a source to all its vertices in a graph.
// Since it only finds the shortest paths, there are ways to make sure it keeps track and stores all the paths it takes too. 
// You can create a seperate array to do this. The parent of a vertex is -1 and if we find the shortest path through a vertex x, 
// we can make x the new parent of the vertex we are currently on. SO we can create an array that stores all the parent vertexes of a vertex z in a shortest path.
// It also updates the parent in the dijkstra algorithm. 
 // source: https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/

//i am using professors codes for dijkstra for this. 

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

void pathinfo(int parentarr[], int i) {
    if (parentarr[i] == -1) {
        // Base case: reached the source vertex
        printf("%d", i);
        return;
    } else {
        // Recursively print the path
        pathinfo(parentarr, parentarr[i]);
        printf(" -> %d", i);
    }
}

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // Print the paths using your pathinfo function
    printf("Vertex \t\t Distance \t\t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t %d \t\t\t", i, dist[i]);
        pathinfo(parent, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
 //this will work for directed graphs as dijkstra algorithm works for both directed and undirected. In a directed graph, the edges all have directions
 //therefore you cna only move from one point to another if there is a directional edge from one vertex to another. In the code, the adjacency matrix is 
 // representing a directed graph, where graph[i][j] is O if there is no directed edge that starts from i and goes to j.
 //the code tracks the parent vertex for each vertex in the shortest path tree and it allows the tree to fully reconstruct after the algorithm completes. 


 // TIME AND SPACE COMPLEXITY:
 //the time complexity is O(n^2). it can be improved to O((V+E)logV). If we move to an adjacency list, we can traverse all vertices using BFS. We use a min heap 
 //to store the values that have not yet found the shortest path for. Min heap can be used as a priority queue ( which is the data structure relevant) and it gets the 
 // minimum distance vertex from a set of vertices that have not found the shortest path for. 
 // you can create a min heap of size V (v is the number of vertices) 
 // min heap has the source vertex as the root and all the other ones are defined as INF
 // for a non empty min heap: 
    // get the vertex with the shortest distance node and call this x
    // for a vertex z of x, if z is min heap and the distance is > than weight of (x-z)+value x, then update the new value of z. 

// source: https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/