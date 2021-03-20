
/**
* ================================================================
* Name: Andrew Lee
* Section: t3
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
#include "listAsLinkedList.h"


/** -------------------------------------------------------------------
 * creates a new queue data type
 * @return - the created queue
   -------------------------------------------------------------------*/
Queue* initializeQueue(){
    Queue* head = malloc(sizeof(Queue));
    head->start = NULL;
    head->last = NULL;
    head->size = 0;


    return head;
}

/** -------------------------------------------------------------------
 * creates a new Node of number type
 * @param numerator - the numerator for the fraction
 * @param denominator - the denominator for the fraction
 * @return Node* - the created new node
   -------------------------------------------------------------------*/
Node* newNodeNum(int numerator, int denominator){
    Node* new = malloc(sizeof(Node));
    new->numerator = numerator;
    new->denominator = denominator;
    new->next = NULL;
    new->isOp = false;

    return new;
}

/** -------------------------------------------------------------------
 * creates a new Node of operator type
 * @param op - the operator character
 * @return Node* - the created new node
   -------------------------------------------------------------------*/
Node* newNodeOp(char op){
    Node* new = malloc(sizeof(Node));
    new->operator = op;
    new->next = NULL;
    new->isOp = true;

    if(op == '-' || op == '+')
        new->precedence = 1;
    if(op == '+' || op == '-')
        new->precedence = 2;
    if(op == '*' || op == '/')
        new->precedence = 3;
    if(op == '^')
        new->precedence = 4;
    if(op == '(')
        new->precedence = 5;
    if(op == ')')
        new->precedence = 0;

    return new;
}

/** -------------------------------------------------------------------
 * finds size of the queue
 * @param Queue* - the queue that is going to be measured
 * @return int - the size of the queue
   -------------------------------------------------------------------*/
int queueSize(Queue* queue){
    return queue->size;
}

/** -------------------------------------------------------------------
 * adds a node to end of the queue
 * @param new - node to be added
 * @param queue - the queue it is going to be added to
   -------------------------------------------------------------------*/
void enqueue(Node* new, Queue* queue){
    if (queue->last == NULL){
        queue->start = new;
        queue->last = new;
        queue->size++;

        return;
    }

    queue->last->next = new;
    queue->last = new;
    queue->size++;

}

/** -------------------------------------------------------------------
 * removes node from start of queue
 * @param queue - the queue node is going to be removed from
   -------------------------------------------------------------------*/
void deQueue(Queue* queue){
//    Node* temp = queue->start;
    if(queue->size == 1){
        queue->start = NULL;
        queue->last = NULL;
    }
    else
        queue->start = queue->start->next;

    queue->size--;
}

/** -------------------------------------------------------------------
 * finds node at head of queue
 * @param queue - the queue that is going to be searched
 * @return Node* - the node at head of queue
   -------------------------------------------------------------------*/
Node* peekQueue(Queue* queue){
    if(queue->size >= 1)
        return queue->start;
    return NULL;

}

/** -------------------------------------------------------------------
 * creates a new Stack data type
 * @return Stack* - the created Stack
   -------------------------------------------------------------------*/
Stack* initializeStack(){
    Stack* new = malloc(sizeof(Stack));
    new->start = NULL;
    new->last = NULL;
    new->size = 0;

    return new;
}

/** -------------------------------------------------------------------
 * adds a node to start of the Stack
 * @param new - node to be added
 * @param stack - the stack it is going to be added to
   -------------------------------------------------------------------*/
void push(Node* new, Stack* stack){
    if(stack->last == NULL) {
        stack->start = new;
        stack->last = new;
        stack->size++;
        return;
    }

    new->next = NULL;

    new->next = stack->start;
    stack->start = new;
    stack->size++;
}

/** -------------------------------------------------------------------
 * removes node from start of Stack
 * @param stack - the stack node is going to be removed from
   -------------------------------------------------------------------*/
void pop(Stack* stack){
    if(stack->size == 1){
        stack->start= NULL;
        stack->last= NULL;
        stack->size--;
        return;
    }

    stack->start = stack->start->next;
    stack->size--;

}

/** -------------------------------------------------------------------
 * finds size of the Stack
 * @param Stack* - the stack that is going to be measured
 * @return int - the size of the stack
   -------------------------------------------------------------------*/
int stackSize(Stack* stack){
    return stack->size;
}

/** -------------------------------------------------------------------
 * prints all nodes in queue
 * @param Queue* - the queue that is going to be printed
   -------------------------------------------------------------------*/
void displayQueue(Queue* empty){
    Node* print;
    print = empty->start;

    int i = 0;
    while(i < empty->size){
        if(print->isOp){
            printf("%c ", print->operator);
        } else{
            if(print->numerator == 0)
                printf("");
            else if(print->denominator == 1)
                printf("%d ", print->numerator);
            else{
                printf("%d/%d ", print->numerator, print->denominator);
            }

        }
        print = print->next;
        i++;
    }
}

/** -------------------------------------------------------------------
 * prints all nodes in Stack
 * @param Stack* - the queue that is going to be printed
   -------------------------------------------------------------------*/
void displayStack(Stack* empty){
    Node* print;
    print = empty->start;

    if(print->denominator < 0 && print->numerator >0){
        print->denominator = print->denominator*-1;
        print->numerator = print->numerator*-1;
    }

    int i = 0;
    while(i < empty->size){
        if(print->isOp){
            printf("%c ", print->operator);
        } else {
            if (print->numerator == 0)
                printf("0");
            else if (print->denominator == 1)
                printf("%d ", print->numerator);
            else if (print->numerator > print->denominator)
                printf("%d %d/%d", print->numerator / print->denominator, print->numerator % print->denominator,
                       print->denominator);
            else if(print->numerator*-1 > print->denominator)
                printf("%d %d/%d", print->numerator / print->denominator, abs( print->numerator % print->denominator*-1),
                       abs(print->denominator));
            else
                printf("%d/%d ", print->numerator, print->denominator);
        }


        print = print->next;
        i++;
    }
}

/** -------------------------------------------------------------------
 * finds node at end of Stack
 * @param Stack* - the Stack that is going to be searched
 * @return Node* - the node at end of Stack
   -------------------------------------------------------------------*/
Node* peekStack(Stack* stack){
    if(stack->size >= 1)
        return stack->start;
    return NULL;
}







