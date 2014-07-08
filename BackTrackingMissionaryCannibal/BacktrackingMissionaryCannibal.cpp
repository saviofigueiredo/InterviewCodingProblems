#include <vector>
#include <stack>
#include <iostream>
#include <queue>

typedef struct Node
{
	int missionaries, canibals, boat;
	Node* parent;

	bool operator==(Node s)
	{
		return s.boat == boat && s.canibals == canibals && s.missionaries == missionaries;
	}

}Node;

bool isValidState(Node newState)
{
	if (newState.canibals >= 0 && newState.missionaries >= 0 && (3 - newState.canibals >= 0) && (3 - newState.missionaries >= 0))
	{
		if (newState.canibals > newState.missionaries && newState.missionaries != 0)
		{
			return false;
		}

		if ((3 - newState.canibals) > (3 - newState.missionaries) && (3 - newState.missionaries) != 0)
		{
			return false;
		}

		return true;
	}

	return false;
}

void addSucessorsToStack(std::stack<Node*>& nodes, Node* parentNode, std::vector<Node*>& statesVisited)
{
	for (int numberOfMissinariesToMove = 0; numberOfMissinariesToMove <= 2; ++numberOfMissinariesToMove)
	{
		for (int numberOfCanibalsToMove = 0; numberOfCanibalsToMove <= 2; ++numberOfCanibalsToMove)
		{
			if (numberOfCanibalsToMove + numberOfMissinariesToMove > 2)
			{
				continue;
			}

			Node* newState = (Node*) malloc(sizeof(Node));

			if (parentNode->boat == 1)
			{
				newState->boat = 0;
				newState->missionaries = parentNode->missionaries - numberOfMissinariesToMove;
				newState->canibals = parentNode->canibals - numberOfCanibalsToMove;
			}
			else
			{
				newState->boat = 1;
				newState->missionaries = parentNode->missionaries + numberOfMissinariesToMove;
				newState->canibals = parentNode->canibals + numberOfCanibalsToMove;
			}

			if (isValidState(*newState))
			{
				if (std::find(statesVisited.begin(), statesVisited.end(), newState) == statesVisited.end())
				{
					Node* newSucessor = (Node*) malloc(sizeof(Node));
					newSucessor->parent = parentNode;
					newSucessor->missionaries = newState->missionaries;
					newSucessor->canibals = newState->canibals;
					newSucessor->boat = newState->boat;
					nodes.push(newSucessor);
				}
			}
		}
	}
}

void printResult(Node* leaf)
{
	Node* current = leaf;

	if (current && current->parent == NULL)
	{
		std::cout << "M = " << current->missionaries << " C = " << current->canibals << " B = " << current->boat << "\t";
		std::cout << "M = " << 3 - current->missionaries << " C = " << 3 - current->canibals << " B = " << 1 - current->boat << std::endl << std::endl;

		return;
	}

	if (current != NULL)
	{
		printResult(current->parent);

		if (current->boat == 1)
		{
			std::cout << "Leve " << current->missionaries - current->parent->missionaries << " M e " << current->canibals - current->parent->canibals << " C para a esquerda \t";
		}
		else
		{
			std::cout << "Leve " << (3 - current->missionaries) - (3 - current->parent->missionaries) << " M e " << (3 - current->canibals) - (3 - current->parent->canibals) << " C para a direita \t";;
		}

		std::cout << "ESQUERDA M = " << current->missionaries << " C = " << current->canibals << " B = " << current->boat << "\t\t";
		std::cout << "DIREITA M = " << 3 - current->missionaries << " C = " << 3 - current->canibals << " B = " << 1 - current->boat << std::endl << std::endl;
	}
}

void solveMissionariesCannibals()
{
	Node* root = (Node*) malloc(sizeof(struct Node));
	root->missionaries = 3;
	root->canibals = 3;
	root->boat = 1;
	root->parent = NULL;

	std::stack<Node*> nodes;
	std::vector<Node*> statesVisited;

	nodes.push(root);

	while (nodes.empty() == false)
	{
		Node* currentNode = nodes.top();
		nodes.pop();

		statesVisited.push_back(currentNode);

		if (currentNode->missionaries == 0 && currentNode->canibals == 0 && currentNode->boat == 0)
		{
			printResult(currentNode);
		}

		addSucessorsToStack(nodes, currentNode, statesVisited);
	}
}

int main(int argc, char* argv[])
{
	solveMissionariesCannibals();

	return EXIT_SUCCESS;
}