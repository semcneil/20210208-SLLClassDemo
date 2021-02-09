/**
 * @file main.cpp
 * @brief This is a demo of making a singly linked list
 * @details Based on ODS book examples
 * @author Seth McNeill
 * @date 2021 February 08
 * 
 */

#include <iostream>
using namespace std;

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
     * 
     * @param d integer to add to tail of list
     */
    bool addToTail(int d) {
        Node* newNode = new Node(d);
        if(n == 0) { // the list is empty
            head = newNode;
            tail = newNode;
            n++;
        } else { // list is not empty
            tail->nextNode = newNode; // point tail node to newNode
            tail = newNode; // point tail to newNode
            n++; // increment counter
        }
        return(true);
    }

    /**
     * Removes the head node and returns the data from it
     */
    int removeHead() {
        int val;
        Node* old;
        if(head != NULL) {
            val = head->data; // collect the value
            old = head; // collect pointer to head node to delete it
            head = head->nextNode; // move the head pointer
            delete old; // free the memory used by this node required since created with new
            n--; // without this get a segfault
            return(val);
        } else {
            return(-999999); // need to pass by reference and return bool to fix this
        }
    }

    /**
     * prints the contents of the singly linked list
     */
    void printList() {
        Node* curNode;
        //if(n == 0) { // the list is empty
        if(head == NULL) { // the list is empty could also check that head != NULL
            cout << "Empty list" << endl;
        } else {
            curNode = head;
            //for(int ii = 0; ii < n; ii++){ // since n is known
            while(curNode->nextNode != NULL) { // not dependent on n
                cout << curNode->data;
                if(curNode->nextNode != NULL){
                    cout << " -> ";
                }
                curNode = curNode->nextNode;
            }
            cout << curNode->data; // required for while loop method
            cout << endl;
        }
    }
};

int main(int, char**) {
    SLL myList;

    myList.printList();
    myList.addToTail(1);
    myList.printList();
    myList.addToTail(2);
    myList.printList();
    myList.addToTail(3);
    myList.printList();
    myList.addToTail(4);
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
    cout << "removed " << myList.removeHead() << endl;
    myList.printList();
}
