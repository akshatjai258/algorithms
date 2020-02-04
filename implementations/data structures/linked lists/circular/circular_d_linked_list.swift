//
//  main.swift
//  circular_d_linked_list
//
//  Created by Lareen Melo on 1/27/20.
//  Copyright © 2020 Lareen Melo. All rights reserved.
//

import Foundation

class Node<T: Equatable>: Equatable {
    public static func == (lhs: Node<T>, rhs: Node<T>) -> Bool {
        return lhs.value == rhs.value && lhs.next === rhs.next && lhs.previous === rhs.previous
    }
    
    var value: T
    var next: Node<T>? = nil
    var previous: Node<T>? = nil
    
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
            newValue.previous = tail

        } else {
            currentNode?.next = newValue
            newValue.next = head
            newValue.previous = currentNode
            tail = newValue
            head?.previous = tail

        }
        
    }
    
    func remove() {
        assert(head != nil)
        
        if head == tail {
            head = nil
            tail = nil
            
        } else {
            var currentNode = tail
            let predecessorNode = currentNode?.previous
            
            predecessorNode?.next = head
            tail = predecessorNode
            currentNode?.next?.previous = tail
            
            currentNode?.previous = nil
            currentNode?.next = nil
            currentNode = nil
            
        }
    }
    
    func prettyPrint() {
        var currentNode = head
        var list = ""
        
        assert(currentNode != nil)

        
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
list.remove()
list.remove()
list.remove()
list.remove()
list.remove()


list.prettyPrint()
