#include <iostream>

#define PegA 'A'
#define PegB 'B'
#define PegC 'C'

void hanoi(int disks, char source, char spare, char dest)
{
	if (disks == 1)
	{
		std::cout << "Move disco " << disks << " de " << source << " para " << dest << std::endl;
	}
	else
	{
		hanoi(disks - 1, source, dest, spare);

		std::cout << "Move disco " << disks << " de " << source << " para " << dest << std::endl;

		hanoi(disks - 1, spare, source, dest);
	}
}

int main(int argc, char* argv[])
{
	int disks = 4;

	hanoi(disks, PegA, PegB, PegC);

	return 0;
}