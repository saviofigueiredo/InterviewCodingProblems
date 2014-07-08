#include <iostream>

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

		edges = (Edge**)malloc((numberOfVertices + 1)*sizeof(Edge*));

		for (auto i = 0; i <= numberOfVertices; ++i)
		{
			edges[i] = nullptr;
		}
	}

	void addEdge(int verticeFrom, int verticeTo)
	{
		if (edges[verticeFrom] == nullptr)
		{
			edges[verticeFrom] = new Edge(verticeTo);
		}
		else
		{
			edges[verticeFrom]->append(verticeTo);
		}
	}

	bool hasCycle(int root, bool* hasBeenVisited)
	{
		auto current = edges[root];

		while (current != nullptr)
		{
			if (hasBeenVisited[current->verticeTo] == true)
			{
				return true;
			}

			hasBeenVisited[current->verticeTo] = true;

			if (hasCycle(current->verticeTo, hasBeenVisited) == true)
			{
				return true;
			}

			hasBeenVisited[current->verticeTo] = false;

			current = current->next;
		}

		return false;
	}

	bool hasCycle()
	{
		bool* hasBeenVisited = (bool*)malloc((numberOfVertices + 1)*sizeof(bool));
		memset(hasBeenVisited, false, (numberOfVertices + 1)*sizeof(bool));

		for (auto v = 1; v <= numberOfVertices; ++v)
		{
			if (hasBeenVisited[v] == false)
			{
				hasBeenVisited[v] = true;

				if (hasCycle(v, hasBeenVisited) == true)
				{
					return true;
				}
			}
		}

		return false;
	}
}Graph;

int main(int argc, char* argv[])
{
	auto graph = new Graph(4);

	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(1, 4);
	graph->addEdge(2, 4);

	std::cout << "Graph does not has cycle: " << graph->hasCycle() << std::endl;

	graph = new Graph(5);

	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(2, 4);
	graph->addEdge(4, 5);
	graph->addEdge(5, 1);

	std::cout << "Graph has cycle: " << graph->hasCycle() << std::endl;
}