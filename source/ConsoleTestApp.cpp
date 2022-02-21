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


void mowdlCppLinkedListTest();


int main()
{
	std::cout << "hello world" << std::endl;
	
	int size = 3;

	auto queue = mowdl::QueueArray<int>(size);
	auto array = mowdl::Array<int>(size);

}


void mowdlCppLinkedListTest()
{
	std::cout << "Hello LinkedList" << std::endl;

	auto list = mowdl::LinkedList<int>(0);

	int size = 5;
	for (int i = 0; i < size; i++)
	{
		list.addBack(i);
		std::cout << "Hello " << i << std::endl;
	}

	std::cout << "Hello getSize " << list.getSize() << std::endl;
	size = list.getSize();


	list.removeAt(4);


	LOG( "size is: " << list.getSize());

	
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list.valueAt(i) << std::endl;
	}

}