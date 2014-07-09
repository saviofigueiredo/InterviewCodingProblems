#include <iostream>
#include <list>
#include <ctime>
#include <string>

template <typename T>
struct Node
{
	Node* next;
	Node* previous;
	T data;

	template <typename T>
	static Node* newNode(T data)
	{
		auto node = (Node*)malloc(sizeof(Node));

		node->data = data;
		node->previous = nullptr;
		node->next = nullptr;

		return node;
	}
};

typedef struct Station
{
	int id;
	float strength;
}Station;

typedef struct Radio
{
	std::list<Station*> stations;

	std::list<Station*>::iterator posStationIterator;

	void moveNextStation()
	{
		++posStationIterator;

		if (posStationIterator == stations.end())
		{
			posStationIterator = stations.begin();
		}
	}

	Station* getCurrent()
	{
		return *posStationIterator;
	}

	static Radio* newRadio()
	{
		auto newRadio = new Radio();

		srand(unsigned int(time(nullptr)));

		auto count = (rand() % 10) + 10;

		for (auto i = 0; i < count; ++i)
		{
			auto station = (Station*)malloc(sizeof(Station));

			station->id = i + 1;
			station->strength = float(rand() % 30);

			newRadio->stations.push_back(station);
		}

		newRadio->posStationIterator = newRadio->stations.begin();

		return newRadio;
	}

	void printStations()
	{
		for (auto it = stations.begin(); it != stations.end(); ++it)
		{
			auto currentStation = (*it);

			std::cout << "Station: " << currentStation->id << " Strength: " << currentStation->strength << std::endl;
		}
	}

	std::list<int> getSixMostStrengthStations()
	{
		Node<Station*>* head = nullptr;
		Node<Station*>* tail = nullptr;

		auto firstStation = getCurrent();

		head = Node<Station*>::newNode(firstStation);
		tail = head;
		int numberStationsStored = 1;

		moveNextStation();

		for (moveNextStation(); firstStation != getCurrent(); moveNextStation())
		{
			auto currentStation = getCurrent();
			
			if (numberStationsStored < 6 || currentStation->strength > tail->data->strength)
			{
				auto node = tail;
				while (node != nullptr && node->data->strength < currentStation->strength)
				{
					node = node->previous;
				}

				auto newNode = Node<Station*>::newNode(currentStation);

				if (node == nullptr) // if should be inserted at head
				{
					newNode->next = head;
					head->previous = newNode;
					head = newNode;
				}
				else if (node == tail) // if should be inserted at tail
				{
					newNode->previous = tail;
					tail->next = newNode;
					tail = newNode;
				}
				else // if should be inserted inside the list
				{
					newNode->previous = node;
					newNode->next = node->next;
					
					if (node->next != nullptr)
					{
						node->next->previous = newNode;
					}

					node->next = newNode;
				}
				++numberStationsStored;

				if (numberStationsStored > 6) // if should remove the last element
				{
					auto newTail = tail->previous;
					free(tail);
					newTail->next = nullptr;
					tail = newTail;
					--numberStationsStored;
				}
			}
		}

		std::list<int> stationIds;

		for (auto node = head; node != nullptr; node = node->next)
		{
			stationIds.push_back(node->data->id);
		}

		return stationIds;
	}
}Radio;

int main(int argc, char* argv[])
{
	auto radio = Radio::newRadio();

	radio->printStations();

	auto stations = radio->getSixMostStrengthStations();

	for (auto it = stations.begin(); it != stations.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}