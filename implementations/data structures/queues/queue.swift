//
//  main.swift
//  queues
//
//  Created by Lareen Melo on 2/21/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

struct Queue<T> {
    var q: [T] = []
    
    mutating func enqueue(_ value: T) {
        q.append(value)
    }
    
    mutating func dequeue() -> T? {
        guard q.count != 0 else { return nil }
        guard let element = q.first else { return nil }
        q.removeFirst()
        
        return element
    }
    
    func front() -> T? {
        guard let front = q.first else { return nil }
        
        return front
    }
    
    func printQueue() {
        for item in q {
            print(item)
        }
    }
}


var myQueue = Queue<Int>()
myQueue.enqueue(5)
myQueue.enqueue(4)
myQueue.enqueue(3)
myQueue.enqueue(2)
myQueue.enqueue(1)

print("Deleting \(myQueue.dequeue()!)")
print("Deleting \(myQueue.dequeue()!)")
print("Deleting \(myQueue.dequeue()!)")


var result: Int {
    if let number = myQueue.front() {
        return number
    }
    return -1
    
}

print("Front of list: \(result)")

myQueue.printQueue()


