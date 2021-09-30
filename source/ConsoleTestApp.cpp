/**
 * @file ConsoleTestApp.cpp
 * @author mowdl (github.com/mowdl)
 * @brief Testing the classes in mowdlCpp
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <iostream>
#include "mowdlCpp/mowdlCpp.h"

#define LOG(x) std::cout << x << std::endl

int main()
{
	int size = 17;
	mowdl::Array<int> arr(size);

	for (int i = 0; i < size; i++)
	{
		arr.set(i, i);
	}

	arr.set(8, 3);

	int select = 7;

	//arr.deleteAtIndex(5);

	arr.remove(3);

	LOG("Size: " << arr.getSize());
	LOG("Capaity: " << arr.getCapacity());
	LOG("is Empty: " << arr.isEmpty());
	for (int i = 0; i < arr.getSize(); i++)
	{
		LOG("at " << i << ": " << arr.at(i));
	}

	LOG("Index of value " << select << ":" << arr.find(select));
	//LOG("pop :" << arr.pop());
	//LOG("Size after pop: " << arr.getSize());
	
	int lamee = mowdl::Lame;
	std::cout << lamee << std::endl;

}
