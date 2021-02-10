/**
 * @file main.cpp
 * @brief This is a demo of making a singly linked list
 * @details Based on ODS book examples
 * @author Seth McNeill
 * @date 2021 February 08
 * 
 */

#include <iostream> // for cin and cout
#include <unistd.h> // for getpid
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
     */
    bool addToTail(int d) {
        Node* newNode = new Node(d);
        if(n == 0) { // the list is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->nextNode = newNode; // update the last node's next node to newNode
            tail = newNode; // update the tail pointer to newNode
        }
        n++;
        return(true);
    }

    /**
     * Returns the data from the iith node
     * 
     * @param ii the number of the node to collect data from
     */
    int get(int ii) {
        Node* curNode;
        if(head == NULL) { // the list is empty
            return(-999999);
        } else if(ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(-999998);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(-999997);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            return(curNode->data);
        }
    }

    /**
     * Adds node after the iith node
     * 
     * @param ii the node to insert after
     * @param d the data in the new node
     * @returns true if successful
     */
    bool addMiddle(int ii, int d) {
        Node* curNode;
        Node* newNode = new Node(d);
        if(head == NULL) { // the list is empty
            return(false);
        } else if(ii >= n) {
            cout << "ERROR: Asked for node beyond tail" << endl;
            return(false);
        } else if(ii < 0) {
            cout << "ERROR: Asked for negative index" << endl;
            return(false);
        } else {
            curNode = head;
            // traverse list to desired node
            for(int jj = 0; jj < ii; jj++) {
                curNode = curNode->nextNode; 
            }
            // At this point curNode points to the node we want to add after
            newNode->nextNode = curNode->nextNode;
            curNode->nextNode = newNode;
            n++;
            return(true);
        }
     }

    /**
     * Removes the head node and returns the data value from the removed node
     * 
     * @param d pointer to integer to return value
     * @returns true if successful
     */
    bool removeHead(int &d) {
        int val;
        Node* old; // save off the old node
        if(head != NULL) {
            val = head->data; // collect the data from node to be removed
            old = head; // save off pointer to node we are removing
            head = head->nextNode; // update head to new node
            delete old; // release the memory from the removed node
            n--; // decrement n to show shorter list
            d = val;
            return(true);
        } else { //list is empty
            return(false);
        }
    }

    /**
     * Returns the length of the list
     */
    int length() {
        return(n);
    }

    /**
     * Prints the list to stdout
     */
    void printList() {
        Node* curNode;
        if(head == NULL) { // the list is empty
            cout << "Empty list" << endl;
        } else { // the list is not empty
            curNode = head; // start at the beginning
            while(curNode->nextNode != NULL){
                cout << curNode->data << " -> ";
                curNode = curNode->nextNode; // update to next node
            }
            cout << curNode->data;
            cout << endl;
        }
    }
};

int main(int, char**) {
    SLL myList;
    int retData; // for data from remove
    long int nTimes = 10000000; // number of items to work with

    cout << "Process ID: " << getpid() << endl;
    cout << "Enter a number and press enter to continue";
    cin >> retData;

    for(long int ii = 0; ii < nTimes; ii++) {
        myList.addToTail(1);
    }

    cout << "Create list " << myList.length() << " long" << endl;
    cout << "Enter a number and press enter to continue: ";
    cin >> retData;
//    cout << "get(1) = " << myList.get(1) << endl;

//    myList.addMiddle(3,10);

    for(int ii = 0; ii < nTimes; ii++) {
        myList.removeHead(retData);
    }
    cout << "List is now " << myList.length() << " long" << endl;
    cout << "Enter a number and press enter to continue: ";
    cin >> retData;
}
