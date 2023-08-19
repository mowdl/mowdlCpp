//
// Created by mowdl on 01/10/2022.
//

#ifndef MOWDLCPP_ARRAY_H
#define MOWDLCPP_ARRAY_H

namespace mowdlCpp {

    /**
     * @brief Dynamic Array Template
     *
     * @tparam T Array elements type
     */
    template <typename T>
    class Array {
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
        inline void prepend(T item) { insert(0, item); };	// O(1)

        // remove from end and return value;
        T pop();									// O(1)

        // delete item at index and shift trailling elements
        void deleteAtIndex(int index);				// O(n)

        // removes item from array even if exist multiple times
        void remove(T item);						// O(n)

        // find index of value or return -1 if not found
        int find(T item);							// O(n)

    };

} // mowdlCpp

#endif //MOWDLCPP_ARRAY_H
