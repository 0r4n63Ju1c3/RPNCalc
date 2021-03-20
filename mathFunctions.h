
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
 * to create the substring method below. Everything else I made from scratch
 * and did not use any other resources, including the linkedLists as I did not follow Zybooks.
* =================================================================
*/

#ifndef MYEXE_MATHFUNCTIONS_H
#define MYEXE_MATHFUNCTIONS_H

#endif //MYEXE_MATHFUNCTIONS_H

#include "listAsLinkedList.h"

//this is a struct for a mixed number
//my intention is to use this as an intermediary step. ie mixedNum to Node and vice versa
typedef struct mixedNum{
    int whole;
    int numerator;
    int denominator;
}MixedNum;

/** -------------------------------------------------------------------
 * converts a mixed number to a node
 * @param mixed* - mixed number to be converted
 * @return Node* - the node to be returned
   -------------------------------------------------------------------*/
Node* mixedToNode(MixedNum* mixed);

/** -------------------------------------------------------------------
 * converts a node to mixed number
 * @param node* - node to be converted
 * @return MixedNum* - the mixed number to be returned
   -------------------------------------------------------------------*/
MixedNum* nodeToMixed(Node* node);

/** -------------------------------------------------------------------
 * adds two numbers, 1st arg + 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the sum from addition
   -------------------------------------------------------------------*/
Node* addition(Node* one, Node* two);

/** -------------------------------------------------------------------
 * adds two numbers, 1st arg - 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the difference from subtraction
   -------------------------------------------------------------------*/
Node* subtraction(Node* one, Node* two);

/** -------------------------------------------------------------------
 * multiplies two numbers, 1st arg * 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the product from multiplication
   -------------------------------------------------------------------*/
Node* multiplication(Node* one, Node* two);

/** -------------------------------------------------------------------
 * find the greatest common divisor
 * @param p - the first integer
 * @param q - the second integer
 * @return - the calculated GCD
   -------------------------------------------------------------------*/
int GCD(int p, int q);

/** -------------------------------------------------------------------
 * divides two numbers, 1st arg / 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the quotient from division
   -------------------------------------------------------------------*/
Node* division(Node* one, Node* two);

/** -------------------------------------------------------------------
 * raises a number to a power
 * @param one - the first node
 * @param raised - the power being raised to
 * @return - the product from resulting power
   -------------------------------------------------------------------*/
Node* power(Node* one, Node* two);






