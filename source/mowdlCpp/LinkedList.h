#pragma once

#include "mowdlCpp.h"

namespace mowdl
{	
	/**
	 * @brief node struct template for use in the LinkedList @see mowdlCpp::LinkedList
	 * @tparam T type of the data stored in the node
	 */
	template <typename T>
	struct LinkedListNode
	{
		T data;
		LinkedListNode<T>* next = NULL;
	};
}

namespace mowdl
{
	// Singly linked list
	template <typename T>
	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

	private:
	};

	template <typename T>
	LinkedList<T>::LinkedList()
	{
	}

	template <typename T>
	LinkedList<T>::~LinkedList()
	{
	}
}
