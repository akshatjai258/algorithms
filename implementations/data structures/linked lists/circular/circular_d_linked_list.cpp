//
//  main.cpp
//  circular_d_linked_list
//
//  Created by Lareen Melo on 2/3/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

#include <iostream>
#include <assert.h>

template <class T>
struct Node {
    T value;
    Node *next;
    Node *previous;
};

template <class T>
class CircularLinkedList {
    Node<T> *head;
    Node<T> *tail;
    
public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void append(T value) {
        Node<T> *new_node = new Node<T>;
        
        new_node->value = value;
        new_node->next = head;
        new_node->previous = nullptr;
        
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            new_node->next = head;
            new_node->previous = tail;
            
        } else {
            Node<T> *current = tail;
            
            current->next = new_node;
            new_node->previous = current;
            tail = new_node;
            head->previous = tail;
            
        }
    }
    
    void remove() {
        assert(head != nullptr);
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            
        } else {
            Node<T> *current = tail;
            Node<T> *previous = current->previous;
            
            previous->next = head;
            tail = previous;
            current->next->previous = tail;
            
            current->previous = nullptr;
            current->next = nullptr;
            
            delete current;
            current = nullptr;
            
        }
    }

    
    // prints list references, last element's reference is first
    void print() {
        Node<T> *current = head;
        
        if (current == nullptr) {
            std::cout << "emtpy list" << std::endl;
        }

        do {
            if (current->next == head) {
                std::cout << current->value << std::endl;
                
            } else {
                std::cout << current->value << "->";
            }
            current = current->next;

        } while (current != head);
    }
};

int main() {
    CircularLinkedList<int> circular_list;
    circular_list.append(0);
    circular_list.append(1);
    circular_list.append(2);
    circular_list.append(3);
    circular_list.append(4);
    circular_list.append(5);

    circular_list.remove();
    circular_list.remove();
    circular_list.remove();
    circular_list.remove();
//    circular_list.remove();
//    circular_list.remove();

    circular_list.print();
    return 0;
}
