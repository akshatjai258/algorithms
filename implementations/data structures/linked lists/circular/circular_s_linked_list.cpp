//
//  main.cpp
//  circular_d_linked_list
//
//  Created by Lareen Melo on 1/27/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

#include <iostream>
#include <assert.h>

template <class T>
struct Node {
    T value;
    Node *next;
};

template <class T>
class CircularLinkedList {
    Node<T> *head;
    
public:
    CircularLinkedList() {
        head = nullptr;
    }
    
    void append(T value) {
        Node<T> *current = head;
        Node<T> *new_node = new Node<T>;
        new_node->value = value;
        new_node->next = head;
        
        if (current == nullptr) {
            head = new_node;
            new_node->next = head;
            delete current;
            current = nullptr;
            
        } else {
            while (current->next != head) {
                current = current->next;
            }
            
            current->next = new_node;
            
        }
    }
    
    void remove() {
        Node<T> *current = head;
        
        assert(current != nullptr);
        
        if (current->next == head) {
            head = nullptr;
            delete current;
            current = nullptr;
        } else {
            Node<T> *previous = nullptr;
            while (current->next != head) {
                previous = current;
                current = current->next;
                
            }
            
            // current now is the last node
            current->next = nullptr;
            previous->next = head;
            delete current;
            current = nullptr;
            
        }
    }
    
    void print() {
        Node<T> *current = head;
        
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

    circular_list.print();
    return 0;
}
