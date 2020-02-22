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
class Queue {
private:
    int rear;
    int _front;
    T q[CAPACITY];
    
public:
    Queue() {
        rear = -1;
        _front = -1;
    }
    
    void dequeue() {
        if (rear == -1 && _front == -1) {
            std::cout << "underflow" << std::endl;
            return;
        }
        
        std::cout << "Deleting ";
        front();

        if (rear == _front) {
            _front = -1;
            rear = -1;
        } else {
            
            _front++;
        }
    }
    
    void enqueue(T value) {
        if (rear == -1 && _front == -1) {
            rear++;
            _front++;
            
        } else {
            if (rear < CAPACITY-1) {
                rear++;
                
            } else {
                std::cout << "overflow" << std::endl;
                return;
            }
        }
        
        q[rear] = value;
    }
    
    void front() {
        std::cout << q[_front] << std::endl;
    }
    
    void print() {
        if (_front == -1 && rear == -1) {
            std::cout << 0 << std::endl;
            
        } else {
            for(int i = _front; i <= rear; i++) {
                if (i == rear) {
                    std::cout << q[i] << "." << std::endl;
                } else {
                    std::cout << q[i] << ", ";
                }
            }
        }
    }
};


int main() {
    Queue<int> queue;
    
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);
    
    queue.dequeue();
//    queue.dequeue();
//    queue.dequeue();
//    queue.dequeue();
//    queue.dequeue();

    queue.front();
    queue.print();
    return 0;
}

