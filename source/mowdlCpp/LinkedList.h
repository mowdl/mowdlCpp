#pragma once

#include "mowdlCpp.h"

namespace mowdl
{	
	/**
	 * @brief node struct template for use in the LinkedList 
	 * @see mowdlCpp::LinkedList
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
	/**
	 * @brief Singly linked list
	 * @tparam T type of data in the list
	 */
	template <typename T>
	class LinkedList
	{
	private:
		// head pointer
		struct LinkedListNode<T>* head = NULL;
		// tail pointer
		struct LinkedListNode<T>* tail = NULL;
		// number of nodes in list
		int size;

	public:
		/**
		 * @brief Construct a 0 sized list
		 */
		LinkedList();
		/**
		 * @brief Construct a list with 'size' nodes
		 * @param size 
		 */
		LinkedList(int size);
		/**
		 * @brief Destroy the Linked List object and freeing memory
		 */
		~LinkedList();

		// Member function
		
		/**
		 * @brief returns number of data elements in the list
		 * @return int number of elements in list
		 */
		int getSize();

		/**
		 * @brief return true if the list is empty
		 * @return bool
		 */
		bool isEmpty();


		/**
		 * @brief returns item at index
		 * @return T
		 */
		T valueAt(int index);

		/**
		 * @brief adds an item to the front of the list
		 * @param item
		 */
		void addFront(T item);

		/**
		 * @brief remove front item and returns its value
		 * @return T the removed item
		 */
		T popFront();

		/**
		 * @brief adds an item to the back of the list
		 * @param item
		 */
		void addBack(T item);

		/**
		 * @brief remove back item and returns its value
		 * @return T the removed item
		 */
		T popBack();

		/**
		 * @brief Get the first item
		 * @return T 
		 */
		T getFront();
		
		/**
		 * @brief Get the last item
		 * @return T 
		 */
		T getBack();

		/**
		 * @brief inserts item at index
		 * @param index 
		 * @param item 
		 */
		void insert(int index, T item);

		/**
		 * @brief removes item at index
		 * @param index 
		 */
		void removeAt(int index);

		/**
		 * @brief returns the item at nth position from the end of the list
		 * 
		 * @param index 
		 * @return T 
		 */
		T valueFromEnd(int index);

		/**
		 * @brief reverses the list
		 */
		void reverse();
	};

	template <typename T>
	LinkedList<T>::LinkedList() : size(0)
	{
	}

	template <typename T>
	LinkedList<T>::~LinkedList()
	{
		auto currentNodePointer = head;
		while (head != NULL)
		{
			head = head->next;
			delete currentNodePointer;
			currentNodePointer = head;
		}
		
	}

	template <typename T>
	LinkedList<T>::LinkedList(int size) : size(size)
	{
		if (size < 0)
		{
			
		}

		else if (size != 0)
		{
			// initialize first node
			head = new struct LinkedListNode<T>;
			// pointer to keep track of where we are in the list
			auto currentNodePointer = head;
			// starting at i = 1 because we already initalized the first node
			for (int i = 1; i < size; i++)
			{
				currentNodePointer->next = new struct LinkedListNode<T>;
				currentNodePointer = currentNodePointer->next;
			}
			tail = currentNodePointer;
			
		}
		
	}

	template <typename T>
	int LinkedList<T>::getSize()
	{
		return size;
	}

	template <typename T>
	bool LinkedList<T>::isEmpty()
	{
		return (size == 0);
	}

	
	template <typename T>
	T LinkedList<T>::valueAt(int index)
	{
		auto currentNode = head;
		for (int i = 0; i < index; i++)
		{
			currentNode = head->next;
		}
		return currentNode->data;
	}

	template <typename T>
	void LinkedList<T>::addFront(T item)
	{
		size++;
		head = new LinkedListNode<T>{item, head};
		if (size == 1)
		{
			tail = head;
		}
	}

	template <typename T>
	T LinkedList<T>::popFront()
	{
		size--;
		auto firstNodeToDelete = head;
		// storing first item before deleting the node
		T item = head->data;
		// moving head pointer to second node
		head = head->next;
		delete firstNodeToDelete;
		return item;
	}

	template <typename T>
	void LinkedList<T>::addBack(T item)
	{
		size++;
		tail->next = new LinkedListNode<T>{item; NULL};
		tail = tail->next;
	}

	template <typename T>
	T LinkedList<typename T>::popBack()
	{
		if (size == 0)
		{
			return NULL;
		}
		std::cout << size << std::endl;
		size--;
		T value = tail->data;
		delete tail;
		auto currentNode = head;
		// size-1 because the pointer to the last node is in the node before the last
		for (int i = 0; i < size ; i++)
		{
			currentNode = currentNode->next;
		}
		tail = currentNode;
		tail->next = NULL;
		return value;
	}
	
}
