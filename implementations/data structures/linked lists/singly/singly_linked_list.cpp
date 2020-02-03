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
    Node<T> *tail;
    int size;
    
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /// prints node in specified position
    void peek(int position) {
        Node<T> *current_node = head;
        
        assert(position < size || position > 0);
        
        while (current_node != tail && position--) {
            current_node = current_node->next;
        }
        
        std::cout << current_node->data << std::endl;
    }
    
    /// Inserts new node at the end of list.
    void insert(T value) {
        Node<T> *new_node = new Node<T>;
        
        new_node->data = value;
        new_node->next = nullptr;
        
        if(head == nullptr) {
            head = new_node;
            tail = new_node;
            
        } else {
            tail->next = new_node;
            tail = new_node;
            
        }
        
        size++;
    }
    
    /// inserts at specific position, it pushes the element at position to the right and replaces the position with the new value
    void insert_at(int position, T value) {
        Node<T> *new_node = new Node<T>;
        
        new_node->data = value;
        new_node->next = nullptr;
        
        assert(position >= 0);
        
        if (position == 0) {
            if (head == nullptr) {
                head = new_node;
                tail = new_node;
                
            } else {
                new_node->next = head;
                head = new_node;
                
            }
            
            size++;

        } else if (position == size) {
            insert(value);
        } else {
            assert(position <= size);
            
            Node<T> *current_node = head;
            
            while (current_node != tail & position > 1) {
                current_node = current_node->next;
                position--;
            }
            
            new_node->next = current_node->next;
            current_node->next = new_node;
            size++;
  
        }
    }
    
    /// removes node at specified position.
    void remove_at(int position) {
        Node<T> *current_node = head;
        Node<T> *predecessor_node = nullptr;
        
        if (head == nullptr) {
            assert(head != nullptr);
            
        }
        
        assert(position < size && position >= 0);
        
        if(position == size - 1) {
            remove();
            
        } else if(position == 0) {
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
                
            } else {
                head = current_node->next;
                delete current_node;
                current_node = nullptr;
            }
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
        Node<T> *predecessor_node = head;
        
        if (tail == nullptr) {
            assert(tail != nullptr);
            
        }
        
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            while (predecessor_node->next != tail) {
                predecessor_node = predecessor_node->next;
            }
            
            predecessor_node->next = nullptr;
            tail = predecessor_node;
            
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
        std::cout << std::endl;

    }
};

int main(int argc, const char * argv[]) {
    LinkedList<int> list;
    
    list.insert_at(0, 1);
    list.insert_at(1, 2);
    list.insert_at(1, 3);
    list.insert_at(3, 4);
    list.insert_at(4, 5);
    list.insert(10);
    list.insert_at(2, 8);
    list.peek(4);
    list.remove_at(3);
    list.remove();
    list.pretty_printing();
    return 0;
}
