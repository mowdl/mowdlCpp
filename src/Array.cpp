//
// Created by mowdl on 01/10/2022.
//

#include "mowdlCpp/Array.h"
#include <stdexcept>

namespace mowdlCpp {

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
} // mowdlCpp