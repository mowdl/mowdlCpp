#pragma once

#include <stdexcept>
#include "mowdl.h"

namespace mowdl
{
	/**
	 * @brief Dynamic Array Template
	 * 
	 * @tparam T Array elements type
	 */
	template <typename T>
	class Array
	{
	public:
		/**
		 * @brief Construct a new Array object
		 * @param size The intial size of the array
		 */
		Array(int size);
		/**
		 * @brief Construct a new Array object with size 0
		 */
		Array();
		/**
		 * @brief Destroy the Array object
		 */
		~Array();

	private:
		T* a;					// pointer to the array
		int size = 0;			// number of items in the array
		int capacity = 16;		// capacity of the array

	private:
		/**
		 * @brief resize the array with new capacity
		 * @details description elements of the array into a new array with capacity
		 * equal to new capacity
		 * @param new_capacity new capacity
		 */
		void resize(int new_capacity);

		/**
		 * @brief Thorws an exception if index is out bound
		 * @param index 
		 */
		void isIndexOutOfBound(int index);

	public:
		/**
		 * @brief Get the Size object
		 * @details return the size of the array in O(1) time
		 * @return size of the array
		 */
		int getSize();
		
		// return the capacity of the array
		int getCapacity();							// O(1)

		// return true if the array is empty
		bool isEmpty();								// O(1)

		// return the item at index
		T at(int index);							// O(1) consatant time access unlike linked lists

		// set the item at index
		void set(int index, T item);				// O(1)

		// add item to end of array
		void push(T item);							// O(1) amortized for memory allocation when full

		// insert item at index and shift all trailling elements
		void insert(int index, T item);				// O(n) because it needs to copy

		// insert at index 0
		void prepend(T item) { insert(0, item); };	// O(1)

		// remove from end and return value;
		T pop();									// O(1)

		// delete item at index and shift trailling elements
		void deleteAtIndex(int index);				// O(n)

		// removes item from array even if exist multiple times
		void remove(T item);						// O(n)

		// find index of value or return -1 if not found
		int find(T item);							// O(n)
	};

	template <typename T>
	Array<T>::Array(int size) : size(size)
	{
		if (size <= capacity)
		{
			a = new T[16];
		}
		else
		{
			capacity = 16;
			while (capacity < size)
			{
				capacity = capacity * 2;
			}
			a = new T[capacity];
		}
	}

	template<typename T>
	Array<T>::Array()
	{
		Array(0);
	}

	template <typename T>
	Array<T>::~Array()
	{
		delete[] a;
	}

	template <typename T>
	void Array<T>::resize(int new_capacity)
	{
		T* b = new T[new_capacity];
		for (int i = 0; i < size; i++)
		{
			*(b + i) = *(a + i);
		}
		delete[] a;
		a = b;
		capacity = new_capacity;
	}

	template <typename T>
	void Array<T>::isIndexOutOfBound(int index)
	{
		if (index >= size)
		{
			throw std::invalid_argument("Index out of bound");
		}
	}

	template <typename T>
	int Array<T>::getSize()
	{
		return size;
	}

	template <typename T>
	int Array<T>::getCapacity()
	{
		return capacity;
	}

	template <typename T>
	bool Array<T>::isEmpty()
	{
		return (size == 0);
	}

	template <typename T>
	T Array<T>::at(int index)
	{
		isIndexOutOfBound(index);
		return *(a + index);
	}

	template <typename T>
	void Array<T>::set(int index, T item)
	{
		*(a + index) = item;
	}

	template <typename T>
	void Array<T>::push(T item)
	{
		if ((size + 1) > capacity)
		{
			resize(capacity * 2);
		}
		set(size, item);
		size++;
	}

	template <typename T>
	void Array<T>::insert(int index, T item)
	{
		isIndexOutOfBound(index);
		if ((size + 1) > capacity)
		{
			resize(capacity * 2);
		}
		for (int i = 0; i < size - index; i++)
		{
			*(a + size - i) = *(a + size - i - 1);
		}
		size++;
		*(a + index) = item;
	}

	template<typename T>
	T Array<T>::pop()
	{
		T value = at(size - 1);
		size--;

		if (size < (capacity / 4))
		{
			resize(capacity / 2);
		}
		return value;
	}

	template<typename T>
	void Array<T>::deleteAtIndex(int index)
	{
		for (int i = 0; i < size - index; i++)
		{
			*(a + index + i) = *(a + index + 1 + i);
		}
		size--;
		if (size < (capacity / 4))
		{
			resize(capacity / 2);
		}
	}

	template<typename T>
	void Array<T>::remove(T item)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (item == *(a + i))
			{
				deleteAtIndex(i);
			}
		}
	}

	template<typename T>
	int Array<T>::find(T item)
	{
		for (int i = 0; i < size; i++)
		{
			if (item == *(a + i))
			{
				return i;
			}
		}
		return -1;
	}
}