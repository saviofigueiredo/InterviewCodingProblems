/*
Given a binary tree converted to a linked list, convert it back to the same binary tree structure.
What information would you keep in the linked list to be able to convert it back to the same tree structure and write code for it.

             A1
          B2      C3
        D4      E6    F7

 a->b->c->d->e->f
*/
#include <iostream>
#include <unordered_map>
#include <queue>

template <typename T>
struct LinkedListNode
{
	T data;
	LinkedListNode* next;
	int rank;

	static LinkedListNode* newNode(T newNodeData, int newNodeRank)
	{
		auto node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		node->data = newNodeData;
		node->rank = newNodeRank;
		node->next = nullptr;

		return node;
	}

	void append(T newNodeData, int newNodeRank)
	{
		auto current = this;

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = newNode(newNodeData, newNodeRank);
	}

	void print()
	{
		std::cout << data;

		if (next != nullptr)
		{
			next->print();
		}
	}
};

template <typename T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	static BinaryTreeNode* newNode(T newData)
	{
		auto node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		node->data = newData;
		node->left = nullptr;
		node->right = nullptr;

		return node;
	}
};

template <typename T>
BinaryTreeNode<typename T>* convertLinkedListToBinaryTreeWithHash(LinkedListNode<typename T>* root)
{
	BinaryTreeNode<T>* binaryTreeRoot = nullptr;
	BinaryTreeNode<T>* newTreeNode = nullptr;

	std::unordered_map<int, BinaryTreeNode<T>*> rankToTreeNodeMapping;

	auto currentNode = root;

	while (currentNode != nullptr)
	{
		auto newTreeNode = BinaryTreeNode<T>::newNode(currentNode->data);
		
		rankToTreeNodeMapping.insert(std::make_pair(currentNode->rank, newTreeNode));

		if (currentNode->rank == 1)
		{
			binaryTreeRoot = newTreeNode;
		}
		else
		{
			auto parent = rankToTreeNodeMapping[currentNode->rank/2];

			if (currentNode->rank % 2 == 0)
			{
				parent->left = newTreeNode;
			}
			else
			{
				parent->right = newTreeNode;
			}
		}

		currentNode = currentNode->next;
	}

	return binaryTreeRoot;
}

template <typename T>
BinaryTreeNode<typename T>* convertLinkedListToBinaryTree(LinkedListNode<typename T>* root)
{
	BinaryTreeNode<T>* binaryTreeRoot = nullptr;
	BinaryTreeNode<T>* binaryTreeNode = nullptr;
	LinkedListNode<BinaryTreeNode<T>*>* parent = nullptr;

	LinkedListNode<T>* currentNode = root;

	while (currentNode != nullptr)
	{
		binaryTreeNode = BinaryTreeNode<T>::newNode(currentNode->data);

		if (currentNode->rank == 1)
		{
			binaryTreeRoot = binaryTreeNode;
			parent = LinkedListNode<BinaryTreeNode<T>*>::newNode(binaryTreeRoot, currentNode->rank);
		}
		else
		{
			parent->append(binaryTreeNode, currentNode->rank);

			while (parent != nullptr && parent->rank != currentNode->rank / 2)
			{
				parent = parent->next;
			}

			if (currentNode->rank % 2 == 0)
			{
				parent->data->left = binaryTreeNode;
			}
			else
			{
				parent->data->right = binaryTreeNode;
			}
		}

		currentNode = currentNode->next;
	}

	return binaryTreeRoot;
}

template <typename T>
LinkedListNode<T>* convertBinaryTreeToLinkedList(BinaryTreeNode<T>* root)
{
	std::unordered_map<BinaryTreeNode<T>*, int> nodeToRankMapping;

	LinkedListNode<T>* linkedListRoot = nullptr;
	std::queue<BinaryTreeNode<T>*> nodesToVisit;

	if (root != nullptr)
	{
		nodesToVisit.push(root);
	}

	while (nodesToVisit.empty() == false)
	{
		auto currentNode = nodesToVisit.front();
		nodesToVisit.pop();

		if (linkedListRoot == nullptr)
		{
			linkedListRoot = LinkedListNode<T>::newNode(currentNode->data, 1);
			nodeToRankMapping.insert(std::make_pair(currentNode, 1));
		}
		
		auto currentNodeRank = nodeToRankMapping[currentNode];
		if (currentNodeRank != 1)
		{
			linkedListRoot->append(currentNode->data, currentNodeRank);
		}

		if (currentNode->left != nullptr)
		{
			nodesToVisit.push(currentNode->left);
			nodeToRankMapping.insert(std::make_pair(currentNode->left, currentNodeRank * 2));
		}
		if (currentNode->right != nullptr)
		{
			nodesToVisit.push(currentNode->right);
			nodeToRankMapping.insert(std::make_pair(currentNode->right, currentNodeRank * 2 + 1));
		}
	}

	return linkedListRoot;
}

int main(int argc, char* argv[])
{
	auto linkedListRoot = LinkedListNode<char>::newNode('A', 1);
	linkedListRoot->append('B', 2);
	linkedListRoot->append('C', 3);
	linkedListRoot->append('D', 4);
	linkedListRoot->append('E', 6);
	linkedListRoot->append('F', 7);

	auto convertedTreeRoot = convertLinkedListToBinaryTree(linkedListRoot);

	auto convertedListRoot = convertBinaryTreeToLinkedList(convertedTreeRoot);
}