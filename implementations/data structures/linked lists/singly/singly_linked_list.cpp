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
    
public:
    LinkedList() {
        head = NULL;
    }
    
    void peek(int position) {
        Node<T> *current_node = head;
        
        while (current_node != NULL && position--) {
            current_node = current_node->next;
        }
        
        std::cout << current_node->data << std::endl;
    }
    

    void insert(T value, int position) {
        Node<T> *current_node = head;
        
        Node<T> *new_node = new Node<T>;
        new_node->data = value;
        new_node->next = NULL;
        
        if (head == NULL) {
            head = new_node;
        } else {
            if (position == 0) {
                new_node->next = head;
                head = new_node;
                
            } else {
                
                while (current_node != NULL && position > 1) {
                    current_node = current_node->next;
                    position--;
                }
                
                if (current_node == NULL) {
                    assert(current_node != NULL);
                    
                } else if (current_node->next == NULL) {
                    //FIXME: tail reference?
                    current_node->next = new_node;
                    
                } else {
                    new_node->next = current_node->next;
                    current_node->next = new_node;
                    
                }
            }
        }
    }
    
    void remove(int position) {
        
        if(head == NULL) {
            // There are no nodes to delete
            assert(head != NULL);
            
        } else {
            Node<T> *current_node = head;
            
            if(current_node->next == NULL) {
                head = NULL;
                free(current_node);
                current_node = NULL;
                
            } else {
                if(position == 0) {
                    head = current_node->next;
                    free(current_node);
                    current_node = NULL;
                    
                } else {
                    Node<T> *predecessor_node = NULL;

                    while(current_node != NULL && position >= 1) {
                        predecessor_node = current_node;
                        current_node = current_node->next;
                        position--;
                    }
                    
                    if(current_node->next == NULL) {
                        predecessor_node->next = NULL;
                        free(current_node);
                        current_node = NULL;

                    } else if(current_node == NULL){
                        assert(current_node != NULL);

                    } else {
                        predecessor_node->next = current_node->next;
                        free(current_node);
                        current_node->next = NULL;
                        
                    }
                    
                }
            }
        }
    }
    
    void pretty_printing() {
        Node<T> *current_node = head;
        
        while(current_node != NULL) {
            if(current_node->next == NULL) {
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
    
    list.insert(3, 0);
    list.insert(5, 1);
    list.insert(2, 1);
    list.insert(4, 2);
    list.insert(7, 2);
    list.insert(8, 4);
    list.remove(1);
    list.remove(1);
    list.remove(1);
    list.peek(0);
  
    list.pretty_printing();
    std::cout << std::endl;
    return 0;
}


// free vs. delete?
