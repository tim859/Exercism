#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

    std::size_t List::size() const {
        // return the correct size of the list.
        return currentSize;
    }
    
    // pushes an Element with `entry` as data to the front of the list.
    void List::push(int entry) {
        // create a new element
        auto newElement = std::make_unique<Element>(entry);
        // point the new elements Element.next ptr to the current head
        newElement->next = std::move(head);
        // make the new element the new head
        head = std::move(newElement);
        // update size of list
        ++currentSize;
    }
        
    // returns the data value of the first element in the list then discards that element.
    int List::pop() {
        // get the data value of the first element in the list
        auto previousHeadValue = head->data;
        // point the head to the second element in the list which therefore becomes the first
        head = std::move(head->next);
        // update size of list
        --currentSize;
        return previousHeadValue;
    }
    
    // reverse the order of the elements in the list.
    void List::reverse() {
        // ensure there are at least 2 elements in the list
        if (currentSize <= 1)
            return;
        auto previousElement = std::move(head);
        auto currentElement = std::move(previousElement->next);
        while (currentElement) {
            auto nextElement = std::move(currentElement->next);
            currentElement->next = std::move(previousElement);
            previousElement = std::move(currentElement);   
            currentElement = std::move(nextElement);
        }
        head = std::move(previousElement);
    }

}  // namespace simple_linked_list
