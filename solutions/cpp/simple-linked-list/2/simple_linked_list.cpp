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
        // initialise previousElement with the current head
        auto previousElement = std::move(head);
        // initialise currentElement with the Element the head points to (the second Element in the list)
        auto currentElement = std::move(previousElement->next);
        while (currentElement) {
            // initialise nextElement with the Element that currentElement points to 
            auto nextElement = std::move(currentElement->next);
            // this is the swap step where the previous element in the list is redirected in the other direction
            currentElement->next = std::move(previousElement);

            // point previousElement and currentElement to their new respective elements in the list
            previousElement = std::move(currentElement);   
            currentElement = std::move(nextElement);
        }
        // point head to the final (now becomes the first) element in the list
        head = std::move(previousElement);
    }

}  // namespace simple_linked_list
