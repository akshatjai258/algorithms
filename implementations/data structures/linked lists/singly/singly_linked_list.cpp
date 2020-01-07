//
//  main.cpp
//  singly-linked-lists
//
//  Created by Lareen Melo on 1/6/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

#include <iostream>
#include <assert.h>


/* LINKED LISTS
 
 linear data structure of ordered objects called nodes.
 A node contains a data and a references to either its successor and/or predecessor (following / previous nodes).
 
 methods:
 a) insert [O(1)]:
 How to insert? We search the last inserted node and then we append. Essentially, add a new node and its references and allocate.
 What if's?
 - Is empty?
 - In between two numbers?
 - First?
 - Last?
 - Non-valid index?
 
 b) delete [O(1)]
 How to delete? Remove node references and deallocate.
 
 c) access [O(N)]
 Returns node[i] (for testing purposes, but essentially just make sure it exists).
 Index has to be valid
 
 d) search [O(N)]
 searchs through the linked list.
 It stops at the last inserted node or until node is found.
 */


// overall a linked list has nodes, so create the node structure
template <class T>
struct node {
    T data;
    node *next;
    
};


template <class T>
class linked_list {
    node<T> *head;
    
public:
    linked_list() {
        head = NULL;
    }
    
    void peek(int position) {
        node<T> *current_node = head;
        
        while (current_node != NULL && position--) {
            current_node = current_node->next;
        }
        
        std::cout << current_node->data << std::endl;
    }
    
    // access
    // returns elemt in i
    
    // search
    //    node<T> current_node = head;
    //    while(current_node != nullptr && position--) {
    //        current_node = current_node.next;
    //
    //    }
    
    void insert(T value, int position) {
        position--;
        node<T> *current_node = head;
        
        node<T> *new_node = new node<T>;
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
                    std::cout << "AINT NOBODY PRAYING FOR ME!" << std::endl;
                    
                } else if (current_node->next == NULL) {
                    //TODO: tail reference?
                    current_node->next = new_node;
                    
                } else {
                    new_node->next = current_node->next;
                    current_node->next = new_node;
                    
                }
            }
        }
    }
    
    void remove(int position) {
        position --;
        
        if(head == NULL) {
            std::cout << "THERE ARE NO NODES TO DELETE" << std::endl;
            
        } else {
            node<T> *current_node = head;
            
            if(current_node->next == NULL) {
                head = NULL;
                free(current_node);
                current_node = NULL;
                
            } else {
                node<T> *predecessor_node = NULL;
                
                if(position == 0) {
                    head = current_node->next;
                    free(current_node);
                    current_node = NULL;
                    
                } else {
                    while(current_node != NULL && position--) {
                        predecessor_node = current_node;
                        current_node = current_node->next;
                    }
                    
                    if(current_node->next == NULL) {
                        predecessor_node->next = NULL;
                        free(current_node);
                        current_node = NULL;
                        std::cout << "here" << std::endl;
                    } else if(current_node == NULL){
                        std::cout << "Out of boundary maybe?" << std::endl;
                        
                    } else {
                        predecessor_node->next = current_node->next;
                        free(current_node);
                        current_node->next = NULL;
                        
                    }
                    
                }
            }
        }
    }
    
    // pretty print
    void pretty_printing() {
        node<T> *current_node = head;
        
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
    linked_list<int> list;
    
    list.insert(3, 1);
    list.insert(5, 2);
    list.insert(4, 3);
    list.insert(7, 4);
    list.insert(8, 5);
    list.remove(1);
    list.remove(4);
    list.peek(1);
    
    
    
    
    list.pretty_printing();
    std::cout << std::endl;
    return 0;
}


// free vs. delete?
// refactor
// fix the 0 or 1 index pls, thanks
