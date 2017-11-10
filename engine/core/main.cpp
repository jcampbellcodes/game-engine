// main game loop!

#include "../tests/dynamicarray_tests.h"
#include "../util/containers/dynamic_array.h"
#include <stdio.h>
void dynamic_array_tests()
{
	DynamicArray<int> arr;
	for (int i = 0; i < 100; i++)
	{
		arr.push_back(i);
	}
	for (int i = 99; i >= 0; i--)
	{
		printf("Array at: %d\n", arr.at(i));
	}
};


int main()
{
	dynamic_array_tests();
	/*
	while (true)
	{
		/*
		 *  TODO --> write an event/callback system and several 'test' classes that talk to each other using this system
		 *  We will need relevant data structures, a timeline class, a timer utility class, and a messaging system
 		 *
	}*/
	return 0;
}