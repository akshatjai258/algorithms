//
//  main.swift
//  doubly_linked_list
//
//  Created by Lareen Melo on 1/23/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

class Node<T> {
    var value: T
    var previous: Node<T>?
    var next: Node<T>?
    
    init(value: T) {
        self.value = value
    }
}

class DoublyLinkedList<T> {
    var head: Node<T>?
    private var count: Int {
        var c = 0
        var currentNode = head
        
        while currentNode != nil {
            c += 1
            currentNode = currentNode?.next
        }
        
        return c
    }
    
    func append(_ value: T) {
        var currentNode = head
        
        let newNode = Node<T>(value: value)
        
        if currentNode == nil {
            head = newNode
            currentNode = nil
        } else {
            while currentNode?.next != nil {
                currentNode = currentNode?.next
            }
            
            currentNode?.next = newNode
            newNode.previous = currentNode
        }
        
    }
    
    // inserts after a valid position
    func insert(_ value: T, at position: Int) {
        var currentNode = head
        var pos = position
        let newNode = Node<T>(value: value)
        
        assert(position >= 0, "Position needs to be greater than 0. Invalid Index.")
        
        if position == 0 {
            if currentNode == nil {
                head = newNode
                currentNode = nil
                
            } else {
                newNode.next = currentNode
                currentNode?.previous = newNode
                head = newNode
                
            }
        } else if position == count - 1 {
            append(value)
            
        } else {
            assert(position < count, "Invalid Index.")
            
            while currentNode?.next != nil && pos > 1 {
                currentNode = currentNode?.next
                pos -= 1
            }
            
            let nextNode = currentNode?.next
            nextNode?.previous = newNode
            newNode.next = nextNode
            
            currentNode?.next = newNode
            newNode.previous = currentNode
            
        }
    }
    
    func remove() {
        var currentNode = head
        
        assert(currentNode != nil, "List is empty. Cannot delete any nodes!")
        
        while currentNode?.next != nil {
            currentNode = currentNode?.next
        }
        
        if currentNode?.previous == nil {
            head = nil
            currentNode = nil
            
        } else {
            currentNode?.previous?.next = nil
            currentNode?.previous = nil
            currentNode = nil
            
        }
    }
    
    func remove(at position: Int) {
        var pos = position
        var currentNode = head
        
        assert(position >= 0, "Position needs to be greater than 0. Invalid Index.")

        if position == 0 {
            if currentNode?.next == nil {
                currentNode = nil
                head = nil
                
            } else {
                currentNode?.next?.previous = nil
                head = currentNode?.next
                currentNode?.next = nil
                currentNode = nil
            }
            
        } else if position == count - 1 {
            remove()
            
        } else {
            assert(position < count, "Invalid Index.")
            
            while currentNode?.next != nil && pos > 1 {
                currentNode = currentNode?.next
                pos -= 1
            }
            
            let previousNode = currentNode?.previous
            let nextNode = currentNode?.next
            
            previousNode?.next = nextNode
            nextNode?.previous = previousNode
            
            currentNode?.next = nil
            currentNode?.previous = nil
            currentNode = nil
            
        }
    }
    
    func pretty_print() {
        var currentNode = head
        var list = ""
        
        while currentNode != nil {
            if currentNode?.next == nil {
                list += "\(currentNode!.value)"
            } else {
                list += "\(currentNode!.value)->"
            }
            currentNode = currentNode?.next
        }
        
        print(list)
    }
}


var list = DoublyLinkedList<Int>()
list.append(1)
list.append(2)
list.append(3)
list.append(4)
list.append(5)

list.insert(0, at: 3)
list.remove(at: 4)

list.remove()

list.pretty_print()
