#include <iostream>
#include "mowdlCpp/LinkedList.h"

int main() {
    mowdlCpp::LinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.addBack(i);
    }

    std::cout << "List size: " << list.getSize() << std::endl;

    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << "Value at index " << i << ": " << list.valueAt(i) << std::endl;
    }

    std::cout << "Front value: " << list.getFront() << std::endl;
    std::cout << "Back value: " << list.getBack() << std::endl;

    std::cout << "Popping back: " << list.popBack() << std::endl;
    std::cout << "New list size: " << list.getSize() << std::endl;

    list.reverse();

    std::cout << "Reversed list:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << "Value at index " << i << ": " << list.valueAt(i) << std::endl;
    }

    list.removeAt(2);

    std::cout << "List after removing index 2:" << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << "Value at index " << i << ": " << list.valueAt(i) << std::endl;
    }

    return 0;
}
