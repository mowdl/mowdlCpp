#pragma once

#include "mowdlCpp.h"

namespace mowdl
{
    template <typename T>
    class QueueList : public LinkedList<T>
    {
    public:
        // add value at position tail
        void enqueue(T item);

        // returns value and removes least recently added element
        T dequeue();

        // checks if queue is empty
        bool empty();
    };

    template <typename T>
    void QueueList<T>::enqueue(T item)
    {
        addBack(item);
    }

    template <typename T>
    T QueueList<T>::dequeue()
    {
        return popFront();
    }

    template <typename T>
    bool QueueList<T>::empty()
    {
        return isEmpty();
    }

}

namespace mowdl
{
    template <typename T>
    class QueueArray : public Array<T>
    {
    private:
        int 
    public:

        QueueArray(int size);

        // add item at end of available storage
        void enqueue(T item);

        // returns value and removes least recently added element
        T dequeue();

        // checks if queue is empty
        bool empty();

        // checks if queue is full
        bool full();
    };

    // template <typename T>
    // QueueArray<T>::QueueArray(int size)
    // {
    // }

    // template <typename T>
    // void QueueArray<T>::enqueue(T item)
    // {
        
    // }

}
