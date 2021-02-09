/**
 * @file main.cpp
 * @brief This is a demo of making a singly linked list
 * @details Based on ODS book examples
 * @author Seth McNeill
 * @date 2021 February 08
 * 
 */

#include <iostream>

class Node {
public:
    int data; // data in the node
    Node* nextNode; // pointer to the next node

    /**
     * Constructor
     */
    Node(int d) {
        data = d;
        nextNode = NULL;
    }
};

class SLL {
public:
    Node* head; // pointer to the first node in the list
    Node* tail; // pointer to the last node in the list
    int n; // count of how many nodes are in the list

    /**
     * Constructor
     */
    SLL() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    /**
     * Adds node to tail of list
     */
    bool addToTail(int d) {
        Node* newNode = new Node(d);
        if(n == 0) { // the list is empty
            head = newNode;
            tail = newNode;
            n++;
        }
        return(true);
    }
};

int main(int, char**) {
    SLL myList;
    std::cout << "Hello, world! Ver 2.1\n";
}
