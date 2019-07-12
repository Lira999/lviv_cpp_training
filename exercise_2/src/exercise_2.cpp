#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include<unordered_set>

using namespace std;

int const ROOT = {0};

struct Edge {
	int from_vertice = {0};
	int to_vertice = {0};
	int weight = {0};
};

class Graph
{
	public:
		Graph(vector<Edge> edges, int vertices);
		~Graph() = default;
		void setShortestPathes(void);
		void printShortestPathes(void);
	private:
		vector< vector<int> > graph_matrix;
		int size;
		vector<int> distance;
		int minDistance(vector<int> distance, bool isVisited[]);
};

Graph::Graph(vector<Edge> edges, int vertices)
{
	size = vertices;
	graph_matrix.resize(size, vector<int> (size));
	for (Edge edge: edges)
		{
		    graph_matrix[edge.from_vertice][edge.to_vertice] = edge.weight;
			graph_matrix[edge.to_vertice][edge.from_vertice] = edge.weight;
		};
};

int Graph::minDistance(vector<int> distance, bool isVisited[])
{
    int min = INT_MAX, min_index = 0;
    for (int v = 0; v < size; ++v)
        if (isVisited[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;
    return min_index;
};

void Graph::setShortestPathes()
{
	bool isVisited[size] = {false};
	for (int i = 0; i < size; ++i)
	    distance.push_back(INT_MAX);
	distance[ROOT] = 0;

	for (int count = 0; count < size-1; ++count)
		{
			int u = this -> minDistance(distance, isVisited);
			isVisited[u] = true;

			for (int v = 0; v < size; ++v)
				if (!isVisited[v] && graph_matrix[u][v] && distance[u] != INT_MAX
							      && distance[u]+graph_matrix[u][v] < distance[v])
				    distance[v] = distance[u] + graph_matrix[u][v];
		}
};

void Graph::printShortestPathes()
{
	for (int i = 0; i < size; ++i)
		   cout << "From " << ROOT << " to " << i << ": " << distance[i] << endl;
};

int main()
{
	Edge edge;
	vector<Edge> edges;
	unordered_set<int> vertices;
	ifstream input_file("./src/task_2_example_graph.txt");

	if (input_file.is_open()) {
		while (input_file >> edge.from_vertice >> edge.to_vertice >> edge.weight) {
			edges.push_back(edge);
			vertices.insert(edge.from_vertice);
			vertices.insert(edge.to_vertice);
		}
		input_file.close();
	} else {
		cerr<<"Unable to open file." << endl;
	}
    Graph graph(edges, vertices.size());
    graph.setShortestPathes();
    graph.printShortestPathes();

    return 0;
}
