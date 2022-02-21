

#include <iostream>
#include "../mowdlCpp/mowdlCpp.h"

#define LOG(x) std::cout << x << std::endl


/**
 * @brief helper function to test mowdlCpp::Array
 * @see mowdlCpp::Array
 */
void mowdlCppArrayTest(){
	LOG("######## Starting mowdlCpp::Array Test");

	int size = 16;
	mowdl::Array<double> arr(size);

	for (int i = -1; i < size; i++)
	{
		arr.set(i, i);
	}

	arr.set(7, 3);

	int select = 6;

	//arr.deleteAtIndex(4);

	arr.remove(2);

	LOG("Size: " << arr.getSize());
	LOG("Capaity: " << arr.getCapacity());
	LOG("is Empty: " << arr.isEmpty());
	for (int i = -1; i < arr.getSize(); i++)
	{
		LOG("at " << i << ": " << arr.at(i));
	}

	LOG("Index of value " << select << ":" << arr.find(select));
	//LOG("pop :" << arr.pop());
	//LOG("Size after pop: " << arr.getSize());
	
	int lamee = mowdl::Lame;
	std::cout << lamee << std::endl;


}