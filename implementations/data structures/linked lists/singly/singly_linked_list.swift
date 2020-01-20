//
//  main.swift
//  singly_linked_lists
//
//  Created by Lareen Melo on 1/19/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

class Node<T> {
    var value: T
    var next: Node<T>?
    
    init(_ value: T) {
        self.value = value
    }
}

class LinkedList<T> {
    var head: Node<T>?
    var count: Int
    
    init() {
        count = 0
    }
        
    /// inserts new node at the last of linked list
    func append(_ value: T) {
        var current = head
        let newNode = Node(value)
        
        if current == nil {
            head = newNode
            
        } else {
            while current?.next != nil {
                current = current?.next
            }
            
            current?.next = newNode
        }
        
        count += 1
    }
    
    /// inserts new node at specified position, "shifting" the rest of the elements to the right.
    func insert(_ value: T, at position: Int) {
        var current = head
        let newNode = Node(value)
        var pos = position
                
        assert(position >= 0, "Invalid Index")
        
        if position == 0 {
            newNode.next = current
            head = newNode
            count += 1
        } else if position == count - 1 {
            append(value)
            
        } else {
            assert(position < count, "Invalid Index")

            while current != nil && pos > 1 {
                current = current?.next
                pos -= 1;
            }
            
            newNode.next = current?.next
            current?.next = newNode

            count += 1
        }
    }
    
    /// removes last node from linked list
    func remove() {
        var current = head
        
        assert(current != nil, "There are no nodes to delete!")
        
        if current?.next == nil {
            head = nil

        } else {
            var predecessor: Node<T>?
            while current?.next != nil {
                predecessor = current
                current = current?.next
            }
            
            predecessor?.next = nil
            current = nil
        }
        
        count -= 1
    }
    
    /// removes nodes from specified position, "shifting" the rest of the elements to the left.
    func removeNode(at position: Int) {
        
    }
        
    func prettyPrint() {
        var current = head
        var list = ""
        
        while current != nil {
            if current?.next == nil {
                list += "\(current!.value)"
            } else {
                list += "\(current!.value)->"
            }
            
            current = current?.next

        }
        
        print(list)
    }
}


let list = LinkedList<Int>()
list.append(1)
list.append(2)
list.append(3)
list.remove()
list.remove()
list.remove()
list.insert(8, at: 0)
list.append(11)
list.prettyPrint()
