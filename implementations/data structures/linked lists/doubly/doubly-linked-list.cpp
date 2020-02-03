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
    Node<T> *tail;
    int size;
    
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
        
    }
    
    void append(T value) {
        Node<T> *new_node = new Node<T>;
        new_node->value = value;
        new_node->previous = nullptr;
        new_node->next = nullptr;
        
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            
        } else {
            Node<T> *current_node = tail;
            
            current_node->next = new_node;
            new_node->previous = current_node;
            
            tail = new_node;

        }
        
        size++;
    }
    
    void insert_at(int position, T value) {
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
                tail = new_node;
                delete current_node;
                current_node = nullptr;
                
            } else {
                new_node->next = current_node;
                current_node->previous = new_node;
                head = new_node;
            }
            size++;
            
        } else if (position == size) {
            append(value);
            
        } else {
            // index needs the be smaller than number of nodes.
            assert(position < size);
            
            while (current_node->next != nullptr && position--) {
                current_node = current_node->next;
            }
            
            Node<T> *previous_node = current_node->previous;
            
            previous_node->next = new_node;
            current_node->previous = new_node;
            
            new_node->next = current_node;
            new_node->previous = previous_node;
            size++;
        }
    }
    
    void remove() {
        // "There are no elements to delete"
        assert(head != nullptr);
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> *current_node = tail;

            current_node->previous->next = nullptr;
            tail = current_node->previous;
            current_node->previous = nullptr;
            
            delete current_node;
            current_node = nullptr;
            
        }
        
        size--;
    }
    
    void remove_at(int position) {
        Node<T> *current_node = head;
        
        // position needs to be greater or equal than 0 (valid index)
        assert(position >= 0);
        
        if (position == size - 1) {
            remove();
            
        } else if (position == 0) {
            
            if (current_node->next == nullptr) {
                head = nullptr;
                tail = nullptr;
                delete current_node;
                current_node = nullptr;
                
            } else {
                head = current_node->next;
                current_node->next->previous = nullptr;
                current_node->next = nullptr;
                
                delete current_node;
                
                current_node = nullptr;
            }
            size--;
            
        } else {
            // index needs the be smaller than number of nodes.
            assert(position < size);
            
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
            
            size--;
            
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
    list.insert_at(1, 2);
    list.append(4);
    list.append(5);
    
    list.remove();
    list.remove();
    list.remove();
    list.remove();
    list.remove();


    list.append(1);


    
    list.print();
}
