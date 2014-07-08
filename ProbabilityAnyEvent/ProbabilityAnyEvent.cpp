#include <iostream>

double probabilityAnyEvent(double* events, int n)
{
	if (n == 1)
	{
		return events[n -1];
	}

	double previousProbability = probabilityAnyEvent(events, n - 1);

	return previousProbability + events[n - 1] + previousProbability*events[n - 1];
}

int main(int argc, char* argv[])
{
	double *events;
	int numberOfEvents;

	std::cout << "How many events?" << std::endl;
	std::cin >> numberOfEvents;

	events = (double*)malloc(numberOfEvents * sizeof(double));

	for (auto event = 0; event < numberOfEvents; ++event)
	{
		std::cout << "What is the probability for the event " << event << std::endl;
		std::cin >> events[event];
	}

	double probability = probabilityAnyEvent(events, numberOfEvents);

	std::cout << "The probability of happening for any of the previous events is " << probability << std::endl;
}