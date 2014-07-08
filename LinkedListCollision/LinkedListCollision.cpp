#include <iostream>
#include <unordered_map>

typedef struct Node
{
	Node* next;
	int data;
}Node;

Node* newNode(int data)
{
	auto node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = nullptr;

	return node;
}

void append(Node* root, Node* nodeToAppend)
{
	if (root->next == nullptr)
	{
		root->next = nodeToAppend;
		return;
	}

	append(root->next, nodeToAppend);
}

void print(Node* current)
{
	if (current == nullptr)
	{
		return;
	}

	std::cout << current->data << " ";
	print(current->next);
}

int getSize(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return getSize(root->next) + 1;
}

Node* getCollisionCountingNodes(Node* l1, Node* l2)
{
	int sizeL1 = getSize(l1);
	int sizeL2 = getSize(l2);

	if (sizeL1 > sizeL2)
	{
		for (auto i = 0; i < sizeL1 - sizeL2; ++i)
		{
			l1 = l1->next;
		}
	}
	else if (sizeL1 < sizeL2)
	{
		for (auto i = 0; i < sizeL2 - sizeL1; ++i)
		{
			l2 = l2->next;
		}
	}

	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1 == l2)
		{
			break;
		}
		
		l1 = l1->next;
		l2 = l2->next;
	}

	return l1;
}

Node* getCollisionWithHash(Node* l1, Node* l2)
{
	std::unordered_map<Node*, bool> map;

	auto current = l1;

	while (current)
	{
		map.insert(std::make_pair(current, true));
		current = current->next;
	}

	current = l2;

	while (current)
	{
		if (map.find(current) != map.end())
		{
			return current;
		}

		current = current->next;
	}

	return nullptr;
}

Node* getCollisionWithNestedLoop(Node* l1, Node* l2)
{
	for (auto currentN1 = l1; currentN1 != nullptr; currentN1 = currentN1->next)
	{
		for (auto currentN2 = l2; currentN2 != nullptr; currentN2 = currentN2->next)
		{
			if (currentN1 == currentN2)
			{
				return currentN1;
			}
		}
	}

	return nullptr;
}

int main(int argc, char* argv[])
{
	auto l1 = newNode(1);
	append(l1, newNode(3));
	append(l1, newNode(5));
	append(l1, newNode(7));
	append(l1, newNode(9));
	append(l1, newNode(11));

	auto l2 = newNode(2);
	append(l2, newNode(4));
	append(l2, l1->next->next->next);

	//auto collision = getCollisionCountingNodes(l1, l2);
	// auto collision = getCollisionWithHash(l1, l2);
	
	auto collision = getCollisionWithNestedLoop(l1, l2);

	if (collision != nullptr)
	{
		std::cout << collision->data;
	}
	else
	{
		std::cout << "No collision has been found!";
	}

	print(l1);
}