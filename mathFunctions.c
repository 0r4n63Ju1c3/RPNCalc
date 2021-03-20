
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
#include "mathFunctions.h"

/** -------------------------------------------------------------------
 * divides two numbers, 1st arg / 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the quotient from division
   -------------------------------------------------------------------*/
Node* division(Node* one, Node* two){
    Node* divisor = malloc(sizeof(Node));
    divisor->numerator = one->numerator  * two->denominator;
    divisor->denominator = one->denominator * two->numerator;

    int gcd = GCD(divisor->numerator, divisor->denominator);
    divisor->numerator = divisor->numerator / gcd;
    divisor->denominator = divisor->denominator / gcd;

    return divisor;
}


/** -------------------------------------------------------------------
 * multiplies two numbers, 1st arg * 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the product from multiplication
   -------------------------------------------------------------------*/
Node* multiplication(Node* one, Node* two){
    Node* product = malloc(sizeof(Node));
    product->numerator = one->numerator * two->numerator;
    product->denominator = one->denominator * two->denominator;

    int gcd = GCD(product->numerator, product->denominator);
    product->numerator = product->numerator / gcd;
    product->denominator = product->denominator / gcd;

    return product;
}

/** -------------------------------------------------------------------
 * find the greatest common divisor
 * @param p - the first integer
 * @param q - the second integer
 * @return - the calculated GCD
   -------------------------------------------------------------------*/
int GCD(int p, int q){
    return q == 0? p:GCD(q, p%q);
}

/** -------------------------------------------------------------------
 * adds two numbers, 1st arg + 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the sum from addition
   -------------------------------------------------------------------*/
Node* addition(Node* one, Node* two){
    Node* sum = malloc(sizeof(Node));
    int denum = one->denominator * two->denominator;
    int oneNumerator = one->numerator * two->denominator;
    int twoNumerator = two->numerator * one->denominator;

    int numerator =  oneNumerator + twoNumerator;
    int gcd = GCD(numerator, denum);
    numerator = numerator / gcd;
    denum = denum / gcd;

    sum->numerator = numerator;
    sum->denominator = denum;

    return sum;
}

/** -------------------------------------------------------------------
 * adds two numbers, 1st arg - 2nd arg
 * @param one - the first node
 * @param two - the second node
 * @return - the difference from subtraction
   -------------------------------------------------------------------*/
Node* subtraction(Node* one, Node* two){
    Node* difference = malloc(sizeof(Node));
    int denum = one->denominator * two->denominator;
    int oneNumerator = one->numerator * two->denominator;
    int twoNumerator = two->numerator * one->denominator;

    int numerator =  oneNumerator - twoNumerator;
    int gcd = GCD(numerator, denum);
    numerator = numerator / gcd;
    denum = denum / gcd;

    difference->numerator = numerator;
    difference->denominator = denum;

    return difference;
}

/** -------------------------------------------------------------------
 * raises a number to a power
 * @param one - the first node
 * @param raised - the power being raised to
 * @return - the product from resulting power
   -------------------------------------------------------------------*/
Node* power(Node* one, Node* two){
    MixedNum* productMixed = malloc(sizeof(MixedNum));

    double oNe = (double) one->numerator / (double) one->denominator;
    double tWo = (double) two->numerator / (double) two->denominator;

    double fraction;
    double fracta;
    double result = pow(oNe, tWo);
    int whole = (int) result;
    fracta= modf(result, &fraction);

    int nmner = (int)(fracta*100);
    productMixed->whole = whole;
    productMixed->numerator = nmner;
    productMixed->denominator = 100;

    Node* product = mixedToNode(productMixed);

    int gcd = GCD(product->numerator, product->denominator);
    product->numerator = product->numerator / gcd;
    product->denominator = product->denominator / gcd;

    return product;
}

/** -------------------------------------------------------------------
 * converts a mixed number to a node
 * @param mixed* - mixed number to be converted
 * @return Node* - the node to be returned
   -------------------------------------------------------------------*/
Node* mixedToNode(MixedNum* mixed){
    Node* mixedNum = malloc(sizeof(Node));
    if(mixed->whole == 0){
        mixedNum->numerator = mixed->numerator;
        mixedNum->denominator = mixed->denominator;
    }else{
        mixedNum->numerator = (mixed->whole * mixed->denominator) + mixed->numerator;
        mixedNum->denominator = mixed->denominator;
    }


    return mixedNum;
}

/** -------------------------------------------------------------------
 * converts a node to mixed number
 * @param node* - node to be converted
 * @return MixedNum* - the mixed number to be returned
   -------------------------------------------------------------------*/
MixedNum* nodeToMixed(Node* node){
    if(node->numerator <= node->denominator)
        return NULL;

    MixedNum* mixed = malloc(sizeof(MixedNum));
    mixed->whole = node->numerator / node->denominator;
    mixed->numerator = node->numerator % node->denominator;
    mixed->denominator = node->denominator;

    return mixed;
}


