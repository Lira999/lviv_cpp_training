#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>

using namespace std;

int const VERTICES {8};
int const ROOT {0};

int minDistance(int distance[], bool isVisited[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < VERTICES; v++)
     if (isVisited[v] == false && distance[v] <= min)
         min = distance[v], min_index = v;
   return min_index;
}

void findShortestPath(int graph[VERTICES][VERTICES], int src)
{
     int distance[VERTICES];
     bool isVisited[VERTICES];
     for (int i = 0; i < VERTICES; i++)
        distance[i] = INT_MAX, isVisited[i] = false;

     distance[src] = 0;

     for (int count = 0; count < VERTICES-1; count++)
     {
       int u = minDistance(distance, isVisited);
       isVisited[u] = true;

       for (int v = 0; v < VERTICES; v++)
         if (!isVisited[v] && graph[u][v] && distance[u] != INT_MAX
                           && distance[u]+graph[u][v] < distance[v])
            distance[v] = distance[u] + graph[u][v];
     }
     for (int i = 0; i < VERTICES; i++)
     	   cout << "From " << ROOT << " to " << i << ": " << distance[i] << endl;
}

int main()
{
    ifstream input_file("./src/task_2_example_graph.txt");
	int graph[VERTICES][VERTICES] {0};
	int from, to, weight;
    if (input_file.is_open()) {
		while (input_file >> from >> to >> weight) {
			graph[from][to] = weight;
			graph[to][from] = weight;
		}
		input_file.close();
	} else {
		cerr<<"Unable to open file." << endl;
	}

    findShortestPath(graph, ROOT);

    return 0;
}
