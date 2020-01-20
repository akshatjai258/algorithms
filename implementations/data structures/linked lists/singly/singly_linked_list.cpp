//
//  main.cpp
//  singly-linked-lists
//
//  Created by Lareen Melo on 1/6/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

#include <iostream>
#include <assert.h>

template <class T>
struct Node {
    T data;
    Node *next;
    
};


template <class T>
class LinkedList {
    Node<T> *head;
    int size;
    
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /// prints node in specified position
    void peek(int position) {
        Node<T> *current_node = head;
        
        assert(position < size || position > 0);
        
        while (current_node != nullptr && position--) {
            current_node = current_node->next;
        }
        
        std::cout << current_node->data << std::endl;
    }
    
    /// Inserts new node at the end of list.
    void insert(T value) {
        int _size = size;
        Node<T> *current_node = head;
        Node<T> *new_node = new Node<T>;
        
        new_node->data = value;
        new_node->next = nullptr;
        
        if(current_node == nullptr) {
            head = new_node;
            delete current_node;
            
        } else {
            while(current_node != nullptr && _size > 1) {
                current_node = current_node->next;
                _size--;
                
            }
            
            assert(current_node != nullptr);
            current_node->next = new_node;
        }
        
        size++;
    }
    
    /// inserts at specific position, it pushes the element at position to the right and replaces the position with the new value
    void insert_at(T value, int position) {
        Node<T> *current_node = head;
        Node<T> *new_node = new Node<T>;
        
        new_node->data = value;
        new_node->next = nullptr;
        
        if(current_node == nullptr) {
            head = new_node;
            size++;
        } else {
            if (position == 0) {
                new_node->next = head;
                head = new_node;
                size++;
                
            } else {
                assert(position <= size || position >= 0);
                
                if (position == size) {
                    insert(value);
                    
                } else {
                    while(current_node != nullptr && position > 1) {
                        current_node = current_node->next;
                        position--;
                    }
                    
                    new_node->next = current_node->next;
                    current_node->next = new_node;
                    size++;
                }
            }
        }
    }
    
    /// removes node at specified position.
    void remove_at(int position) {
        Node<T> *current_node = head;
        Node<T> *predecessor_node = nullptr;
        
        if (current_node == nullptr) {
            assert(current_node != nullptr);
            delete current_node;
            delete predecessor_node;
            
        }
        
        assert(position < size || position >= 0);
        
        if(position == size - 1) {
            remove();
            
        } else if(position == 0) {
            head = current_node->next;
            delete current_node;
            current_node = nullptr;
            size--;
            
        } else {
            while(current_node != nullptr && position > 0) {
                predecessor_node = current_node;
                current_node = current_node->next;
                position--;
                
            }
            
            predecessor_node->next = current_node->next;
            current_node->next = nullptr;
            delete current_node;
            current_node = nullptr;
            
            size--;
            
        }
    }
    
    /// removes last node of list.
    void remove() {
        Node<T> *current_node = head;
        Node<T> *predecessor_node = nullptr;
        int _size = size;
        
        if (current_node == nullptr) {
            assert(current_node != nullptr);
            delete current_node;
            delete predecessor_node;
            
        }
        
        if (current_node->next == nullptr) {
            head = nullptr;
            delete current_node;
            current_node = nullptr;
            
        } else {
            while (current_node != nullptr && _size > 1) {
                predecessor_node = current_node;
                current_node = current_node->next;
                _size--;
            }
            
            predecessor_node->next = nullptr;
            delete current_node;
            current_node = nullptr;
            
        }
        
        size--;
        
    }
    
    void pretty_printing() {
        Node<T> *current_node = head;
        
        if (current_node == nullptr) {
            std::cout << "LIST IS EMPTY" << std::endl;
        }
        
        while(current_node != nullptr) {
            if(current_node->next == nullptr) {
                std::cout << current_node->data << std::endl;
            } else {
                std::cout << current_node->data << "->";
            }
            current_node = current_node->next;
            
        }
    }
};

int main(int argc, const char * argv[]) {
    LinkedList<int> list;
    list.insert_at(1, 0);
    list.insert_at(2, 1);
    list.insert_at(3, 2);
    list.insert_at(4, 3);
    list.insert_at(5, 2);
    list.insert(10);
    list.insert_at(8, 2);
    list.peek(4);
    list.remove_at(5);
    list.remove();
    list.pretty_printing();
    std::cout << std::endl;
    return 0;
}
