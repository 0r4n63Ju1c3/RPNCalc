//
// Created by C22Andrew.Lee on 3/15/2020.
//

/**
* ================================================================
* Name: Andrew Lee
* Section: xxx
* Project: Programming Assessment #3 - main file
* Documentation: I received help from Dr.Wilkerson who explained
 * what free does and specifically how it is used. He also explained
 * how to use a mixed number struct to make addition and subtraction
 * a lot easier.
* =================================================================
*/
#include "mathFunctions.h"

//this is a tester to test functionality
int main(){
    Queue* queue = initializeQueue();
    Node* new = newNodeNum(1, 2);
    enqueue(new, queue);

    Node* new1 = newNodeNum(3, 4);
    enqueue(new1, queue);

    Node* new2 = newNodeNum(5, 6);
    enqueue(new2, queue);

    Node* new3 = newNodeNum(7, 8);
    enqueue(new3, queue);

    Node* new4 = newNodeOp('c');
    enqueue(new4, queue);

    printf("%d / %d \n\n\n\n\n", peekQueue(queue)->numerator, peekQueue(queue)->denominator);
    deQueue(queue);

    displayQueue(queue);



    Stack* stack = initializeStack();


    Node* newStack1 = newNodeNum(1, 2);
    push(newStack1, stack);


    Node* newStack2 = newNodeNum(1, 4);
    push(newStack2, stack);

    Node* newStack0 = newNodeOp('-');
    push(newStack0, stack);

    printf("%c \n\n\n\n\n", peekStack(stack)->operator);
    pop(stack);

    displayStack(stack);


    printf("%d\n", GCD(9, 15));



    Node* sum = power(newStack2, 2);
    printf("%d / %d\n", sum->numerator, sum->denominator);

    Node* sum1 = multiplication(newStack2, newStack1);
    printf("%d / %d\n", sum1->numerator, sum1->denominator);

    Node* sum2 = division(newStack1, newStack2);
    printf("%d / %d\n", sum2->numerator, sum2->denominator);

    Node* sum3 = addition(newStack1, newStack2);
    printf("%d / %d\n", sum3->numerator, sum3->denominator);

    Node* sum4 = subtraction(newStack2, newStack1);
    printf("%d / %d\n", sum4->numerator, sum4->denominator);

//    int* one = malloc(sizeof(int));
//    *one = 5;
//    free(one);
//    int two = 1;
//    int quicksum = *one + two;
//    printf("%d", quicksum);

    MixedNum* mix = malloc(sizeof(MixedNum));
    mix->whole = 5;
    mix->denominator = 2;
    mix->numerator = 1;

    Node* mixed = mixedToNode(mix);

    printf("%d / %d \n", mixed->numerator, mixed->denominator);

    MixedNum* newMixed = nodeToMixed(mixed);
    printf("%d %d/%d \n", newMixed->whole, newMixed->numerator, newMixed->denominator);

    printf("everything worked");
}
