/*
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v)
either connects a vertex from U to V or a vertex from V to U.  In other words, for every edge (u, v),
either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color.
Note that it is possible to color a cycle graph with even cycle using two colors.

Write a program that should return true if a graph is bipartite and false otherwise.
*/
#include <iostream>

enum Colors
{
	Undefined,
	Red,
	Black
};

typedef struct Edge
{
	Edge* next;
	int verticeTo;

	Edge(int v)
	{
		verticeTo = v;
		next = nullptr;
	}

	void append(int v)
	{
		if (next == nullptr)
		{
			next = new Edge(v);
		}
		else
		{
			next->append(v);
		}
	}
}Edge;

typedef struct Graph
{
	Edge** edges;
	int numberOfVertices;

	Graph(int n)
	{
		numberOfVertices = n;

		edges = (Edge**)malloc((numberOfVertices + 1)*sizeof(Edge));

		for (auto i = 0; i <= numberOfVertices; ++i)
		{
			edges[i] = nullptr;
		}
	}

	void addEdge(int vertice, int verticeTo)
	{
		if (edges[vertice] == nullptr)
		{
			edges[vertice] = new Edge(verticeTo);
		}
		else
		{
			edges[vertice]->append(verticeTo);
		}
	}

	bool isBipartite(int root, Colors* verticesColors)
	{
		auto edge = edges[root];

		while (edge != nullptr)
		{
			if (verticesColors[edge->verticeTo] == Colors::Undefined)
			{
				if (verticesColors[root] == Colors::Red)
				{
					verticesColors[edge->verticeTo] = Colors::Black;
				}
				else
				{
					verticesColors[edge->verticeTo] = Colors::Red;
				}

				if (isBipartite(edge->verticeTo, verticesColors) == false)
				{
					return false;
				}

				edge = edge->next;
			}
			else if (verticesColors[edge->verticeTo] == verticesColors[root])
			{
				return false;
			}
		}

		return true;
	}

	bool isBipartite()
	{
		Colors *verticesColors = (Colors*)malloc((numberOfVertices + 1)*sizeof(Colors));
		memset(verticesColors, 0, (numberOfVertices + 1)*sizeof(Colors));

		for (auto i = 1; i < numberOfVertices; ++i)
		{
			if (verticesColors[i] == Colors::Undefined)
			{
				verticesColors[i] = Colors::Red;

				if (isBipartite(i, verticesColors) == false)
				{
					return false;
				}
			}
		}

		return true;
	}
}Graph;

int main(int main, char* argv[])
{
	auto graph = new Graph(4);

	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(1, 4);
	graph->addEdge(2, 4);

	std::cout << "Graph should not be bipartite: " << graph->isBipartite() << std::endl;

	graph = new Graph(5);

	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(2, 4);
	graph->addEdge(4, 5);

	std::cout << "Graph should be bipartite: " << graph->isBipartite() << std::endl;
}