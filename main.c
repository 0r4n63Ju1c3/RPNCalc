
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
 * take a substring of a given string from one index to another
 * @param char *src - string that is going to be divided
 * int m - the first index
 * int n - the second index
 * @return the new string that is product of the substring
   -------------------------------------------------------------------*/
char* substr(char *src, int m, int n);

int main(){

while(true) {
    printf("RPN calculator: README\n");
    printf("The way that this calculator works is by taking in an expression and converting to RPN\n");
    printf("Important things to know: \n");
    printf("    Spaces are ONLY used for mixed numbers (3 1/2), example 3+5 is correct, 3 + 5 is not \n");
    printf("    Rational numbers have to be entered as a fraction \n");
    printf("    fractions are automatically rounded\n");
    printf("    If there is a problem the program will quit with exit code 0: \n");
    printf("    As long as there are no problems with entering, the code will run forever \n\n");

    printf("Please enter an expression: \n \n ");


    //brief explanation of how this program works
    //maybe i misread the instructions but it is my understanding that there are no decimals being passed
    //if I wanted to include a decimal, I would add a . to the operator array, and then use subtring around this point,
    //exactly how the space works but with a period instead
    //Also, I realize that i declare the same variables wthin their own scope, but C lion allows it to compile.

    //the input parsing is done by finding all of the locations of operators, and then using the index of
    //them to divide the string into small strings using substring, these smaller strings are then converted to their
    //respective node and added to the initialQ. From the initialQ, they are either added to the outputQ if they are an integer
    //or, if its an operator, the operator stack. The shunting-yard is performed ensure that each node is in the proper
    //location to make the RPN. Once the RPN is established, it is passed into another stack one at a time where the proper
    //math can be performed. This stack is the "answer" stack.



    char lineToRead[50]; //equation that is going to be read in
    fgets(lineToRead, sizeof(lineToRead), stdin); //keeps newline and null character
    printf("%sthis expression that is going to be used \n", lineToRead);

    char ops[] = {'+', '-', '*', '/', '^', '(', ')', ' '}; //array of operators
    int numOps = 0;
    int l = 0; //counter
    int leftParen = 0; //# of left paren
    int rightParen = 0; //# of right paren
    while (lineToRead[l] != '\0') {
        if (lineToRead[l] == ops[0]) {
            numOps++;
        }
        if (lineToRead[l] == ops[1]) {
            numOps++;
        }
        if (lineToRead[l] == ops[2]) {
            numOps++;
        }
        if (lineToRead[l] == ops[3]) {
            numOps++;
        }
        if (lineToRead[l] == ops[4]) {
            numOps++;
        }
        if (lineToRead[l] == ops[5]) {
            numOps++;
            leftParen++;
        }
        if (lineToRead[l] == ops[6]) {
            numOps++;
            rightParen++;
        }
        if (lineToRead[l] == ops[7]) {
            numOps++;
        }
        l++;
    }
    if (rightParen != leftParen) {
        printf("inconsistent amount of parentheses, please re-run and enter the correct amount");
        return 0;
    }
    //^ this to count how many operators there are in total ;
    printf("%d, this it number of operators including () and spaces\n\n", numOps);
    int opLocations[numOps]; //the index of operator
    char whatOp[numOps]; //the operator
    //this uses parallel arrays

    //this is going to keep track of the indexes for the operator along with which operator it is
    int j = 0; //counter
    for (int i = 0; i < 50; i++) {
        if (lineToRead[i] == ops[0]) {
            opLocations[j] = i;
            whatOp[j] = ops[0];
            j++;
        }
        if (lineToRead[i] == ops[1]) {
            opLocations[j] = i;
            whatOp[j] = ops[1];
            j++;
        }
        if (lineToRead[i] == ops[2]) {
            opLocations[j] = i;
            whatOp[j] = ops[2];
            j++;
        }
        if (lineToRead[i] == ops[3]) {
            opLocations[j] = i;
            whatOp[j] = ops[3];
            j++;
        }
        if (lineToRead[i] == ops[4]) {
            opLocations[j] = i;
            whatOp[j] = ops[4];
            j++;
        }
        if (lineToRead[i] == ops[5]) {
            opLocations[j] = i;
            whatOp[j] = ops[5];
            j++;
        }
        if (lineToRead[i] == ops[6]) {
            opLocations[j] = i;
            whatOp[j] = ops[6];
            j++;
        }
        if (lineToRead[i] == ops[7]) {
            opLocations[j] = i;
            whatOp[j] = ops[7];
            j++;
        }
    }

    int x = 0; //counter
    while (x < numOps) {
        printf("%c, at index", whatOp[x]);
        printf(" %d\n", opLocations[x]);
        x++;
    } //pretty message also allows user to see / double check


    Queue *initial = initializeQueue(); //new Queue
    j = 0; //counter
    if (opLocations[j] == 0 && j == 0) {
        Node *tobeAdded = newNodeOp(whatOp[j]);
        enqueue(tobeAdded, initial);
        j = 2;

        //if operator at beginning, then add to Queue (has to be a negative number)

        //this block of code essentially checks if the first number if negative
        //and if that first negative number is a mixed number
        if (whatOp[1] != ' ') {
            char *number = substr(lineToRead, opLocations[0] + 1, opLocations[j - 1]);
            int num = atoi(number);
            Node *tobeAdded = newNodeNum(num, 1);
            enqueue(tobeAdded, initial);

            Node *tobeAdded2 = newNodeOp(whatOp[j - 1]);
            enqueue(tobeAdded2, initial);
            //if a non mixed number follows
        } else {
            //if a mixed number follows
            j = 4; //skip appropiate number ahead
            char *mixedNumber = substr(lineToRead, 1, opLocations[j - 1]);


            int k = 0;
            while (mixedNumber[k] != ' ') {
                k++; //location of space
            }
            int z = 0;
            while (mixedNumber[z] != '/') {
                z++; //location of /
            }
            //find the space, and the /
            //then the substring is taken

            char *firstNum = substr(mixedNumber, 0, k); //substring up to space
            char *num = substr(mixedNumber, k + 1, z); //substring from space to /
            char *demum = substr(mixedNumber, z + 1, strlen(mixedNumber)); //subtring from / to end

            MixedNum *mix = malloc(sizeof(MixedNum));
            mix->whole = atoi(firstNum);
            mix->numerator = atoi(num);
            mix->denominator = atoi(demum);
            //creating a new mixed number

            Node *tobeAdded = mixedToNode(mix);
            enqueue(tobeAdded, initial);
            //adding node mixed nmber which has been converted

            Node *tobeAdded2 = newNodeOp(whatOp[j - 1]);
            enqueue(tobeAdded2, initial);
            //add the operator after

        }
    } else if (whatOp[j] == ops[7]) {
        //if operator at j == ' '
        //this checks if the first number is a mixed number
        if (j > numOps) {
            printf("please enter expression");
            return 0;
        }
        j += 3;
        char *mixedNumber = substr(lineToRead, 0, opLocations[j - 1]);
        //take substring

        //same thing as before, find location of ' ' and /
        int k = 0;
        while (mixedNumber[k] != ' ') {
            k++;
        }
        int z = 0;
        while (mixedNumber[z] != '/') {
            z++;
        }


        char *firstNum = substr(mixedNumber, 0, k);
        char *num = substr(mixedNumber, k + 1, z);
        char *demum = substr(mixedNumber, z + 1, strlen(mixedNumber));
        //make the mixed number

        MixedNum *mix = malloc(sizeof(MixedNum));
        mix->whole = atoi(firstNum);
        mix->numerator = atoi(num);
        mix->denominator = atoi(demum);
        //create mixed number node

        Node *tobeAdded = mixedToNode(mix);
        enqueue(tobeAdded, initial);
        //add it to the initial Queue
        Node *tobeAdded2 = newNodeOp(whatOp[j - 1]);
        enqueue(tobeAdded2, initial);
    } else {
        char *number = substr(lineToRead, 0, opLocations[0]);
        int num = atoi(number);
        Node *tobeAdded = newNodeNum(num, 1);
        enqueue(tobeAdded, initial);

        Node *tobeAdded2 = newNodeOp(whatOp[j]);
        enqueue(tobeAdded2, initial);

        j++;
        //if this is hit, this means that the first number is a non negative whole number
    }

    //this part divides the rest of the input string based off of operator locations
    bool isSpaceAtEnd = false; //if a mixed number is at the end
    while (j != numOps) {
        if (whatOp[j] == ' ') {
            //if a mixed number is found in the middle of the string
            int holder = j;
            j += 3;
            if (j > numOps) {
                //specifically checks if the end of input string has been reached
                //and if this last number is a mixed number
                char *mixedNumber = substr(lineToRead, opLocations[holder - 1] + 1, strlen(lineToRead));


                int k = 0;
                while (mixedNumber[k] != ' ') {
                    k++;
                }
                int z = 0;
                while (mixedNumber[z] != '/') {
                    z++;
                }
                //same thing as before

                char *firstNum = substr(mixedNumber, 0, k);
                char *num = substr(mixedNumber, k + 1, z);
                char *demum = substr(mixedNumber, z + 1, strlen(mixedNumber));


                MixedNum *mix = malloc(sizeof(MixedNum));
                mix->whole = atoi(firstNum);
                mix->numerator = atoi(num);
                mix->denominator = atoi(demum);

                Node *tobeAdded = mixedToNode(mix);
                enqueue(tobeAdded, initial);
                isSpaceAtEnd = true;
                //node is added

                break;
            } else {
                //otherwise mixed number is in MIDDLE of string
                char *mixedNumber = substr(lineToRead, opLocations[holder - 1] + 1, opLocations[j - 1]);
                //take substring

                int k = 0;
                while (mixedNumber[k] != ' ') {
                    k++;
                }
                int z = 0;
                while (mixedNumber[z] != '/') {
                    z++;
                }
                //same thing as before


                char *firstNum = substr(mixedNumber, 0, k);
                char *num = substr(mixedNumber, k + 1, z);
                char *demum = substr(mixedNumber, z + 1, strlen(mixedNumber));


                MixedNum *mix = malloc(sizeof(MixedNum));
                mix->whole = atoi(firstNum);
                mix->numerator = atoi(num);
                mix->denominator = atoi(demum);
                //mixed number is created and converted to Node

                Node *tobeAdded = mixedToNode(mix);
                enqueue(tobeAdded, initial);

                Node *tobeAdded2 = newNodeOp(whatOp[j - 1]);
                enqueue(tobeAdded2, initial);
                //operator node is added

            }
        } else {
            //otherwise it is a normal number
            char *number = substr(lineToRead, opLocations[j - 1] + 1, opLocations[j]);
            int num = atoi(number);
            Node *tobeAdded = newNodeNum(num, 1);
            enqueue(tobeAdded, initial);
            //number added

            Node *tobeAdded2 = newNodeOp(whatOp[j]);
            enqueue(tobeAdded2, initial);
            j++;
            //operator node is added and j is incremented
        }


    }

    if (isSpaceAtEnd == false) {
        //if there is no mixed number at end then the last number has to be added, this takes care of that
        char *number = substr(lineToRead, opLocations[j - 1] + 1, strlen(lineToRead));
        int num = atoi(number);
        Node *tobeAdded = newNodeNum(num, 1);
        enqueue(tobeAdded, initial);
    }

//    displayQueue(initial);

//we now have a queue off all the inputs :D and they have been tokenized
//--------------------------------------------------------------- input parsing done

    Node *current;
    current = initial->start;

    //sanitize inputs, make negative numbers negative;

    if (current->operator == '-') {
        deQueue(initial);
        current = initial->start;
        current->numerator = current->numerator * -1;
        //makes the first number negative if need be
    }

    int size = 0;
    while (size < initial->size - 2) {
        if (current->numerator == 0 && current->next->operator == '-') {
            current->next->isOp = false;
            current->next->precedence = 0;

            current->next->next->numerator = current->next->next->numerator * -1;
        }
        current = current->next;
        size++;
        //this makes all other nodes negative if need be.
    }

    current = initial->start;
    //setting current back to the start

    Queue *outputQ = initializeQueue();
    Stack *opStack = initializeStack();
    //making a new queue and stack for the ouputQ and operator stack

    bool AlreadyAdded = false; //make sure that nothing is double counted
    //this is the shunting yard algorithm
    while (current) {
        AlreadyAdded = false; //set to false at beginning
        if (current->isOp == false) {
            //if current node is not operator
            current = current->next;
            Node *added = peekQueue(initial);
            enqueue(added, outputQ); //add to queue
            deQueue(initial);
        } else {
            if (opStack->start == NULL) {
                //if operator stack is empty --> add
                current = current->next;
                Node *added = peekQueue(initial);
                Node *added1 = added;
                deQueue(initial);
                push(added1, opStack);
            } else {
                Node *stackTop = opStack->start;
                while (stackTop->precedence >= current->precedence) {
                    //the operator at top of stack is greater
                    AlreadyAdded = false; //ensure no double counting
                    if (stackTop->operator == '(' && current->operator == ')') {
                        //if operator at top is ( and current operator is )
                        pop(opStack);
                        current = current->next;
                        deQueue(initial);
                        //remove both and exit loop
                        break;
                    } else if (stackTop->operator == '(' && current->operator != ')') {
                        //if operator at top is ( and current operator is not )
                        current = current->next;
                        Node *added = peekQueue(initial);
                        Node *added1 = added;
                        deQueue(initial);
                        push(added1, opStack);

                        AlreadyAdded = true;

                        //add current operator to the stack
                        break;
                    } else {
                        //keep popping operators from the stack
                        Node *nodeToadd = peekStack(opStack);
                        enqueue(nodeToadd, outputQ);
                        pop(opStack);
                        stackTop = opStack->start;
                        if (stackTop == NULL) //if empty then break
                            break;
                    }
                }

                if (AlreadyAdded != true) {
                    //this then adds the operator to operatorStack as long as it wasnt added before
                    current = current->next;
                    Node *tobeAdded = peekQueue(initial);
                    deQueue(initial);
                    push(tobeAdded, opStack);
                }

            }
        }
    }

    //once input stream is empy and operators left in operator stack
    while (opStack->size != 0) {
        //this pops remaining operators
        Node *operatorAdded = peekStack(opStack);
        enqueue(operatorAdded, outputQ);
        pop(opStack);
        //adds to end of output Q
    }
    displayQueue(outputQ);


    Stack *answer = initializeStack(); //this is going to be the answer!

    //while something remains in outputQ
    while (outputQ->size != 0) {
        if (outputQ->start->isOp == false) {
            //if operatorQ first is not an operator add to stack
            if (outputQ->start->numerator == 0) {
                deQueue(outputQ);
                //gets rid of any placeholder values
            } else {
                Node *toAdd = outputQ->start;
                outputQ->start = outputQ->start->next;
                outputQ->size--;

                push(toAdd, answer);
                //remove from queue and add to stack
            }
        } else {
            if (outputQ->start->operator == '+') {
                Node *tobeAddedOne = peekStack(answer);
                pop(answer);
                Node *tobeAddedTwo = peekStack(answer);
                pop(answer);

                push(addition(tobeAddedTwo, tobeAddedOne), answer);
                //if operator then pop twice and do operator function together
                //add result back into the stack
            }
            if (outputQ->start->operator == '-') {
                Node *tobeAddedOne = peekStack(answer);
                pop(answer);
                Node *tobeAddedTwo = peekStack(answer);
                pop(answer);

                push(subtraction(tobeAddedTwo, tobeAddedOne), answer);
                //if operator then pop twice and do operator function together
                //add result back into the stack
            }
            if (outputQ->start->operator == '*') {
                Node *tobeAddedOne = peekStack(answer);
                pop(answer);
                Node *tobeAddedTwo = peekStack(answer);
                pop(answer);

                push(multiplication(tobeAddedTwo, tobeAddedOne), answer);
                //if operator then pop twice and do operator function together
                //add result back into the stack
            }
            if (outputQ->start->operator == '/') {
                Node *tobeAddedOne = peekStack(answer);
                pop(answer);
                Node *tobeAddedTwo = peekStack(answer);
                pop(answer);

                push(division(tobeAddedTwo, tobeAddedOne), answer);
            }
            if (outputQ->start->operator == '^') {
                Node *tobeAddedOne = peekStack(answer);
                pop(answer);
                Node *tobeAddedTwo = peekStack(answer);
                pop(answer);

                push(power(tobeAddedTwo, tobeAddedOne), answer);
                //if operator then pop twice and do operator function together
                //add result back into the stack
            }
            deQueue(outputQ);
        }


    }

    printf("\n= ");
    displayStack(answer); //print the answer
    printf("\n");

}

    return 1;


}

/** -------------------------------------------------------------------
 * take a substring of a given string from one index to another
 * @param char *src - string that is going to be divided
 * int m - the first index
 * int n - the second index
 * @return the new string that is product of the substring
   -------------------------------------------------------------------*/
char* substr(char *src, int m, int n)
{
    // get length of the destination string and use to allocate memory
    int len = n - m;

    char *dest = (char*)malloc(sizeof(char) * (len + 1));

    // extracts characters between m'th and n'th index from source string
    // and copy them into the destination string
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }

    //add null character
    *dest = '\0';


    return dest - len;
}