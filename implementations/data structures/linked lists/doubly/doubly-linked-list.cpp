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
    
    int count() {
        int count = 0;
        
        Node<T> *current_node = head;
        
        while (current_node != nullptr) {
            current_node = current_node->next;
            count++;
        }
        
        return count;
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
    
    void insert_at(T value, int position) {
        int number_of_nodes = count();
        Node<T> *current_node = head;
        
        Node<T> *new_node = new Node<T>;
        new_node->value = value;
        new_node->previous = nullptr;
        new_node->next = nullptr;
        
        // position needs to be greater or equal than 0 (valid index)
        assert(position >= 0);
        
        if (position == 0) {
            if (current_node == nullptr) {
                head = new_node;
                delete current_node;
                current_node = nullptr;
                
            } else {
                new_node->next = current_node;
                current_node->previous = new_node;
                head = new_node;
            }
            
        } else if (position == number_of_nodes) {
            append(value);
            
        } else {
            // index needs the be smaller than number of nodes.
            assert(position < number_of_nodes);
            
            while (current_node->next != nullptr && position--) {
                current_node = current_node->next;
            }
            
            Node<T> *previous_node = current_node->previous;
            
            previous_node->next = new_node;
            current_node->previous = new_node;
            
            new_node->next = current_node;
            new_node->previous = previous_node;
        }
    }
    
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
    
    void remove_at(int position) {
        int number_of_nodes = count();
        Node<T> *current_node = head;
        
        // position needs to be greater or equal than 0 (valid index)
        assert(position >= 0);
        
        if (position == number_of_nodes - 1) {
            remove();
            
        } else if (position == 0) {
            
            if (current_node->next == nullptr) {
                head = nullptr;
                delete current_node;
                current_node = nullptr;
                
            } else {
                head = current_node->next;
                current_node->next->previous = nullptr;
                current_node->next = nullptr;
                
                delete current_node;
                
                current_node = nullptr;
            }
            
        } else {
            // index needs the be smaller than number of nodes.
            assert(position < number_of_nodes);
            
            while (current_node->next != nullptr && position--) {
                current_node = current_node->next;
            }
            
            Node<T> *previous_node = current_node->previous;
            Node<T> *next_node = current_node->next;
            
            previous_node->next = next_node;
            next_node->previous = previous_node;
            
            current_node->next = nullptr;
            current_node->previous = nullptr;
            
            delete current_node;
            
            current_node = nullptr;
            
        }
    }
    
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
        
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> list;
    
    list.append(1);
    list.append(3);
    list.insert_at(2, 1);
    
    list.print();
}
