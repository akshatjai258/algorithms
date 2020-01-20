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
    
    // create count
    
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
    }
    
    /// inserts new node at specified position, "shifting" the rest of the elements to the right.
    
    /// removes last node from linked list
    func remove() {
        var current = head
        
        assert(current != nil)
        
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
    }
    
    /// removes nodes from specified position, "shifting" the rest of the elements to the left.
    
    func prettyPrint() {
        var currentNode = head
        
        while currentNode != nil {
            print(currentNode!.value)
            currentNode = currentNode?.next
            //            print(currentNode?.value)
        }
    }
}


let list = LinkedList<Int>()
list.append(1)
list.append(2)
list.append(3)
list.remove()
list.remove()
list.remove()
list.remove()
list.prettyPrint()
