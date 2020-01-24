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

list.remove()

list.pretty_print()
