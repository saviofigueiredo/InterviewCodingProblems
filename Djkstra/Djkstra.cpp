#include <limits.h>
#include <iostream>
#define MaxVertices 120

typedef struct EdgeNode
{
	int verticeTo;
	int weight;
	EdgeNode* next;
}EdgeNode;

typedef struct Graph
{
	EdgeNode* edges[MaxVertices + 1];
	int degree[MaxVertices + 1];
	int nVertices;
	int nEdges;
}Graph;

void initializeGraph(Graph* graph)
{
	graph->nEdges = 0;
	graph->nVertices = 0;

	for (int i = 1; i <= MaxVertices; ++i)
	{
		graph->edges[i] = nullptr;
		graph->degree[i] = 0;
	}
}

int getNextNodeToVisit(bool visited[], int distance[], Graph* graph)
{
	int minDistance = 0;
	int closestUnvisitedNode;

	for (auto i = 1; i <= graph->nVertices; ++i)
	{
		if (visited[i] == false && distance[i] <= minDistance)
		{
			minDistance = distance[i];
			closestUnvisitedNode = i;
		}
	}

	return closestUnvisitedNode;
}

void minPath(Graph* graph, int source)
{
	int parent[MaxVertices], distance[MaxVertices];
	bool visited[MaxVertices];

	for (auto i = 1; i <= graph->nVertices; ++i)
	{
		visited[i] = false;
		parent[i] = -1;
		distance[i] = INT_MAX;
	}

	distance[source] = 0;

	for (auto i = 1; i <= graph->nVertices; ++i)
	{
		int nextNodeToVisit = getNextNodeToVisit(visited, distance, graph);

		visited[nextNodeToVisit] = true;

		EdgeNode* childrenNode = graph->edges[nextNodeToVisit];

		while (childrenNode != nullptr)
		{
			if (visited[childrenNode->verticeTo] == false && distance[childrenNode->verticeTo] > distance[nextNodeToVisit] + childrenNode->weight)
			{
				parent[childrenNode->verticeTo] = nextNodeToVisit;
				distance[childrenNode->verticeTo] = distance[nextNodeToVisit] + childrenNode->weight;
			}
		}
	}
}

int main(int argc, char* argv[])
{

}