
/**
* ================================================================
* Name: Andrew Lee
* Section: xxx
* Project: Programming Assessment #3 - main file
* Documentation: I received help from Dr.Wilkerson who explained
 * what free does and specifically how it is used. He also explained
 * how to use a mixed number struct to make addition and subtraction
 * a lot easier. I used google to get a better understanding of how a
 * substring function would work / look like and then I looked at people's code online
 * to create the substring method below. Everything else, I made from scratch,
 * including the linkedLists as I did not follow zybooks.
* =================================================================
*/

#ifndef MYEXE_LISTASLINKEDLIST_H
#define MYEXE_LISTASLINKEDLIST_H

#endif //MYEXE_LISTASLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



//README: I intentionally defined a stack and a queue. I realize that this could have been done as a linked list that is
//all encompassing. However, I did this so I could specifically have a stack and queue data type be separate. This way,
//each data type can only be used with the functions that are written for it. However, the nodes are a universal type of
//node because they are meant to be able to be transferred between different data types.



//this is the basic node that is going to be used
//it will store all value as a fraction
//it also has the data type for char, which will hold operator
//the bool set a flag to create operator vs non operator nodes
typedef struct node{
    int numerator;
    int denominator;
    char operator;
    int precedence;
    bool isOp;
    struct node* next;
}Node;

//start of the queue
typedef struct queue{
    Node* start;
    Node* last;
    int size;
}Queue;

//start of the stack
typedef struct stack{
    Node* start;
    Node* last;
    int size;
}Stack;


/** -------------------------------------------------------------------
 * creates a new queue data type
 * @return - the created queue
   -------------------------------------------------------------------*/
Queue* initializeQueue();

/** -------------------------------------------------------------------
 * finds size of the queue
 * @param Queue* - the queue that is going to be measured
 * @return int - the size of the queue
   -------------------------------------------------------------------*/
int queueSize(Queue*);

/** -------------------------------------------------------------------
 * prints all nodes in queue
 * @param Queue* - the queue that is going to be printed
   -------------------------------------------------------------------*/
void displayQueue(Queue*);

/** -------------------------------------------------------------------
 * creates a new Node of number type
 * @param numerator - the numerator for the fraction
 * @param denominator - the denominator for the fraction
 * @return Node* - the created new node
   -------------------------------------------------------------------*/
Node* newNodeNum(int numerator, int denominator);

/** -------------------------------------------------------------------
 * adds a node to end of the queue
 * @param new - node to be added
 * @param queue - the queue it is going to be added to
   -------------------------------------------------------------------*/
void enqueue(Node* new, Queue* queue);

/** -------------------------------------------------------------------
 * removes node from start of queue
 * @param queue - the queue node is going to be removed from
   -------------------------------------------------------------------*/
void deQueue(Queue* queue);

/** -------------------------------------------------------------------
 * finds node at head of queue
 * @param queue - the queue that is going to be searched
 * @return Node* - the node at head of queue
   -------------------------------------------------------------------*/
Node* peekQueue(Queue* queue);

/** -------------------------------------------------------------------
 * creates a new Node of operator type
 * @param op - the operator character
 * @return Node* - the created new node
   -------------------------------------------------------------------*/
Node* newNodeOp(char op);

/** -------------------------------------------------------------------
 * creates a new Stack data type
 * @return Stack* - the created Stack
   -------------------------------------------------------------------*/
Stack* initializeStack();

/** -------------------------------------------------------------------
 * finds node at end of Stack
 * @param Stack* - the Stack that is going to be searched
 * @return Node* - the node at end of Stack
   -------------------------------------------------------------------*/
Node* peekStack(Stack*);

/** -------------------------------------------------------------------
 * adds a node to start of the Stack
 * @param new - node to be added
 * @param stack - the stack it is going to be added to
   -------------------------------------------------------------------*/
void push(Node* new, Stack* stack);

/** -------------------------------------------------------------------
 * prints all nodes in Stack
 * @param Stack* - the queue that is going to be printed
   -------------------------------------------------------------------*/
void displayStack(Stack*);

/** -------------------------------------------------------------------
 * removes node from start of Stack
 * @param stack - the stack node is going to be removed from
   -------------------------------------------------------------------*/
void pop(Stack* stack);

/** -------------------------------------------------------------------
 * finds size of the Stack
 * @param Stack* - the stack that is going to be measured
 * @return int - the size of the stack
   -------------------------------------------------------------------*/
int stackSize(Stack*);








