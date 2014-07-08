/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1?s.

Examples:
Input : N = 2
Output : 3
		 // The 3 strings are 00, 01, 10

	 Input : N = 3
		 Output : 5
				  // The 5 strings are 000, 001, 010, 100, 101

				  This problem can be solved using Dynamic Programming.Let a[i] be the number of binary strings of length i which 
				  do not contain any two consecutive 1’s and which end in 0. Similarly, let b[i] be the number of such strings which end in 1. 
				  We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1. This yields the recurrence relation :
		a[i] = a[i - 1] + b[i - 1]
			b[i] = a[i - 1]

			The base cases of above recurrence are a[1] = b[1] = 1. The total number of strings of length i is just a[i] + b[i].

			Following is C++ implementation of above solution.In the following implementation, indexes start from 0. 
			So a[i] represents the number of binary strings for input length i + 1. Similarly, b[i] represents binary strings for input length i + 1.
*/
#include <iostream>

int numberBinaryStringsWithoutConsecutiveOnes(int length)
{
	int* numberBinaryStringsTerminatingZero = (int*)malloc(length*sizeof(int));
	int* numberBinaryStringsTerminatingOne = (int*)malloc(length*sizeof(int));

	numberBinaryStringsTerminatingZero[0] = 1;
	numberBinaryStringsTerminatingOne[0] = 1;

	for (auto i = 1; i < length; ++i)
	{
		numberBinaryStringsTerminatingZero[i] = numberBinaryStringsTerminatingZero[i - 1] + numberBinaryStringsTerminatingOne[i - 1];
		numberBinaryStringsTerminatingOne[i] = numberBinaryStringsTerminatingZero[i - 1];
	}

	return numberBinaryStringsTerminatingZero[length - 1] + numberBinaryStringsTerminatingOne[length - 1];
}

int main(int argc, char* argv[])
{
	std::cout << "The number of binary strings without consecutive ones with length 3 is " << numberBinaryStringsWithoutConsecutiveOnes(3) << std::endl;
	std::cout << "The number of binary strings without consecutive ones with length 2 is " << numberBinaryStringsWithoutConsecutiveOnes(2) << std::endl;
}