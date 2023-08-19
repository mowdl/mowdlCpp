//
// Created by mowdl on 01/10/2022.
//

#ifndef MOWDLCPP_LINKEDLIST_H
#define MOWDLCPP_LINKEDLIST_H

namespace mowdlCpp {

    /**
 * @brief node struct template for use in the LinkedList
 * @see mowdlCpp::LinkedList
 * @tparam T type of the data stored in the node
 */
    template <typename T>
    struct LinkedListNode
    {
        T data;
        LinkedListNode<T> *next = nullptr;
    };

    template <typename T>
    class LinkedList {

    private:
        // head pointer
        struct LinkedListNode<T> *head = nullptr;
        // tail pointer
        struct LinkedListNode<T> *tail = nullptr;
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

        bool removeValue(T value);
    };

} // mowdlCpp

#endif //MOWDLCPP_LINKEDLIST_H
