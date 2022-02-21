#pragma once

#include "LinkedList.h"


namespace mowdl
{
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
			currentNode = currentNode->next;
		}
		return currentNode->data;
	}

	template <typename T>
	void LinkedList<T>::addFront(T item)
	{
		size++;
		head = new LinkedListNode<T>{item, head};
		// in case we added the first item in the list
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
		// if adding the first item use addFront
		if (size == 0)
		{
			addFront(item);
		}
		// else expand the tail
		else
		{
			size++;
			tail->next = new LinkedListNode<T>{item, NULL};
			tail = tail->next;
		}
	}

	template <typename T>
	T LinkedList<typename T>::popBack()
	{
		if (size == 0)
		{
			return NULL;
		}
		size--;
		T value = tail->data;
		auto tmp = tail;
		delete tmp;
		auto currentNode = head;
		// size-1 because the pointer to the last node is in the node before the last
		for (int i = 0; i < size - 1; i++)
		{
			currentNode = currentNode->next;
		}
		tail = currentNode;
		tail->next = NULL;
		return value;
	}

	template <typename T>
	T LinkedList<T>::getFront()
	{
		return head->data;
	}
	
	template <typename T>
	T LinkedList<T>::getBack()
	{
		return tail->data;
	}


	template <typename T>
	void LinkedList<T>::insert(int index, T item)
	{
		if ((size == 0) && (index > size))
		{
			return;
		}
		if (index == size)
		{
			addBack(item);
		}
		if (index == 0)
		{
			addFront(item);
		}

		auto currentNode = head;
		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->next;
		}
		// making a new node after currentNode with passed item pointing to the node after currentNode
		currentNode->next = new LinkedListNode<T>{item, currentNode->next};
		size++;
		
	}

	template <typename T>
	void LinkedList<T>::removeAt(int index)
	{
		if ((size == 0) || (index > size))
		{
			return;
		}
		if (index == size)
		{
			popBack();
			return;
		}
		if (index == 0)
		{
			popFront();
			return;
		}
		
		auto currentNode = head;
		for (int i = 0; i < index - 1; i++)
		{
			currentNode = currentNode->next;
		}
		auto toDelete = currentNode->next;

		currentNode->next = toDelete->next;

		delete toDelete;
	}

	template <typename T>
	T LinkedList<T>::valueFromEnd(int index)
	{
		index = size - 1 - index;
		return valueAt(index);
	}
	
	
	template <typename T>
	void LinkedList<T>::reverse()
	{
		// going thro each node and reversing its pointer
		// first node dealt with here
		tail = head;
		auto prev = head;
		head = head->next;
		prev->next = nullptr;
		auto tmp = head;
		// middle nodes dealt with here
		for (int i = 0; i < size - 2; i++)
		{
			tmp = prev;
			prev = head;
			head = head->next;
			prev->next = tmp;
		}
		// last node dealt with here
		head->next = prev;
		
	}
	


	template <typename T>
	bool LinkedList<T>::removeValue(T value)
	{
		auto currentNode = head;
		for (int i = 0; i < size; i++)
		{
			if(currentNode->data == value)
			{
				removeAt(i);
				return true;
			}
		}
		return false;
	}
}