#include "simple_linked_list.h"

#include <stdexcept>

#include <iostream>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element *e = new Element(entry);

    e->next = head;
    head = e;
    ++current_size;
}

int List::pop() {
    Element *e = head;
    int ret = e->data;

    head = e->next;

    delete e;
    --current_size;

    return ret;
}

void List::reverse() {
    List other{};
    Element *cur = head;

    while (cur) {
        int v = cur->data;

        other.push(v);
        cur = cur->next;
    }

    std::swap(head, other.head);
}

List::~List() {
    while (head)
    {
        pop();
    }
}

}  // namespace simple_linked_list
