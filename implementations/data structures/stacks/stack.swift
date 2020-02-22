//
//  main.swift
//  queues
//
//  Created by Lareen Melo on 2/21/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

struct Stack<T> {
    var s: [T] = []
    
    mutating func push(_ value: T) {
        s.append(value)
    }
    
    mutating func pop() -> T? {
        
        return s.popLast()
    }
    
    func peek() -> T? {
        guard let top = s.last else { return nil }
        
        return top
    }
    
    func printStack() {
        for item in s {
            print(item)
        }
    }
}

var myStack = Stack<Int>()
myStack.push(5)
myStack.push(4)
myStack.push(3)
myStack.push(2)
myStack.push(1)

print("Deleting \(myStack.pop()!)")
print("Deleting \(myStack.pop()!)")

var result: Int {
    if let top = myStack.peek() {
        return top
    }
    return -1
}

print("Head: \(result)")

myStack.printStack()
