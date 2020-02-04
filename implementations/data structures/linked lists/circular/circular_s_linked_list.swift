//
//  main.swift
//  circular_s_linked_list
//
//  Created by Lareen Melo on 1/27/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

class Node<T: Equatable>: Equatable {
    public static func == (lhs: Node<T>, rhs: Node<T>) -> Bool {
        return lhs.value == rhs.value && lhs.next === rhs.next
    }
    
    var value: T
    var next: Node<T>? = nil
    
    init(with value: T) {
        self.value = value
    }
}


class LinkedList<T: Equatable> {
    private var head: Node<T>?
    private var tail: Node<T>?
    
    func append(_ value: T) {
        let newValue = Node(with: value)
        let currentNode = tail
        
        if head == nil {
            head = newValue
            tail = newValue
            
            newValue.next = head

        } else {
            currentNode?.next = newValue
            newValue.next = head
            tail = newValue

        }
        
    }
    
    func remove() {
        assert(head != nil)
        
        if head == tail {
            head = nil
            tail = nil
        } else {
            var predecessorNode = head
            
            while predecessorNode?.next != tail {
                predecessorNode = predecessorNode?.next
            }
            
            var currentNode = predecessorNode?.next
            predecessorNode?.next = currentNode?.next
            currentNode?.next = nil
            tail = predecessorNode
            currentNode = nil
            
        }
    }
    
    func prettyPrint() {
        var currentNode = head
        var list = ""
        
        repeat {
            if currentNode?.next == head {
                list += "\(currentNode!.value)->\(currentNode!.next!.value)"
                
            } else {
                list += "\(currentNode!.value)->"
            }
            
            currentNode = currentNode?.next
            
        } while currentNode != head
        
        print(list)
    }
}


var list = LinkedList<Int>()

list.append(1)
list.append(2)
list.append(3)
list.append(4)
list.append(6)

list.remove()
list.append(6)

list.prettyPrint()
