//
//  main.cpp
//  doubly-linked-list
//
//  Created by Lareen Melo on 1/23/20.
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
class DoublyLinkedList {
    Node<T> *head;
    
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    
    void append(T value) {
        Node<T> *current_node = head;
        
        Node<T> *new_node = new Node<T>;
        new_node->value = value;
        new_node->previous = nullptr;
        new_node->next = nullptr;
        
        if (current_node == nullptr) {
            head = new_node;
            delete current_node;
        } else {
            while (current_node->next != nullptr) {
                current_node = current_node->next;
            }
            
            current_node->next = new_node;
            new_node->previous = current_node;
        }
    }
    
    // insert at
    
    void remove() {
        Node<T> *current_node = head;
        
        // "There are no elements to delete"
        assert(current_node != nullptr);
        
        while (current_node->next != nullptr) {
            current_node = current_node->next;
            
        }
        
        if (current_node->previous == nullptr) {
            head = nullptr;
            delete current_node;
            current_node = nullptr;
            
        } else {
            current_node->previous->next = nullptr;
            current_node->previous = nullptr;
            
            delete current_node;
            
            current_node = nullptr;
        }
    }
    
    // delete at
    
    void print() {
        Node<T> *current_node = head;
        while (current_node != nullptr) {
            if (current_node->next == nullptr) {
                std::cout << current_node->value;
            } else {
                std::cout << current_node->value << "->";
            }
            
            current_node = current_node->next;
        }
    }
};

int main() {
    DoublyLinkedList<int> list;
    
    list.append(5);
    list.append(6);
    list.append(7);
    
    list.remove();
    list.remove();
    list.remove();

    list.print();
    std::cout << std::endl;
    
    
}
