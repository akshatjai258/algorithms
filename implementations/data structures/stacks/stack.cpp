//
//  main.cpp
//  stacks
//
//  Created by Lareen Melo on 2/20/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

#include <iostream>

const int CAPACITY = 5;

template <class T>
class Stack {
private:
    int top;
    T s[CAPACITY]; // s -> stack

public:
    Stack() {
        top = -1;
    }
    
    void push(T value) {
        if (top < CAPACITY-1) {
            top++;
            s[top] = value;
            
        } else {
            std::cout << "overflowing with love <3." << std::endl;
            return;
        }
    }

    void pop() {
        if (top >= 0) {
            std::cout << "Deleting ";
            peek();
            
            top--;
            
        } else {
            std::cout << "underflowing with bad skin" << std::endl;
            return;
        }
    }

    void peek() {
        std::cout << s[top] << std::endl;
    }
    
    int size() {
        return top + 1;
    }
    
    void print_stack() {
        for (int i = 0; i < (top + 1); i++) {
            std::cout << s[i] << std::endl;
        }
        
        // TODO: really pretty print. like bucket :b
    }
};



int main() {
    Stack<int> my_stack;
    my_stack.push(5);
    my_stack.push(4);
    my_stack.push(3);
    my_stack.push(2);
    my_stack.push(1);
    
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();

    my_stack.peek();

    my_stack.print_stack();
    
    
    std::cout << my_stack.size() << std::endl;
    return 0;
}

