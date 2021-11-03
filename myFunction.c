//
//  myFunction.c
//  Assignment_1CMPT300
//
//  Created by Pranjal Keshari on 2020-01-28.
//  Copyright © 2020 Pranjal. All rights reserved.
//


#include "myFunction.h"



//#################################################################################################################################################################################################################################//

// For keeping track of list and node. Also adding a print function to print every function clear and precise in main.c

int endLocationTrack = 0;
int countingNodesInList = 0;
int countingExtraList = 0;

node nodeElementTrack[SIZEOFNODEPLUSTWO] = {[0 ... SIZEOFNODEPLUSONE].myEntry=NULL, [0 ... SIZEOFNODEPLUSONE].next=NULL, [0 ... SIZEOFNODEPLUSONE].prev=NULL, [0 ... SIZEOFNODEPLUSONE].currentlyThis=NULL, [0 ... SIZEOFNODE - 1].currentlyTrue=0, [SIZEOFNODE ... SIZEOFNODEPLUSONE].currentlyTrue=1};

list *leftListTrack[SIZEOFLIST] = {[0 ... SIZEOFLISTMINUSONE]=NULL};

list listTrack[SIZEOFLIST] = {[0 ... SIZEOFLISTMINUSONE].head=NULL, [0 ... SIZEOFLISTMINUSONE].tail=NULL, [0 ... SIZEOFLISTMINUSONE].curr=NULL, [0 ... SIZEOFLISTMINUSONE].nodeCount=0, [0 ... SIZEOFLISTMINUSONE].currentlyTrue=0};


//List Print is used to Print the list and Where the current pointer is pointing along with its value
void listPrint(list *pointerListCreated) {


    if (!pointerListCreated->currentlyTrue){
        printf("\nError Found because list is not active right now!\n");
    }
    
    if (!pointerListCreated) {
        printf("\nError Found because null pointer will be passed into list Print function\n");
        return;
    }


    node *firsTtemp = pointerListCreated->head;

    
    printf("\nStart Printing List \n");

    int temp9 = 0;
    
    while (firsTtemp) {
        if (firsTtemp == pointerListCreated->tail && firsTtemp->next)
            printf("\nCaution Found because node %d is current, but this->next!=NULL!!\n", temp9);
        printf("Character %d: ", temp9);

        if (!firsTtemp->currentlyThis)
            printf("\n Caution Found because node %d have not access to this column\n", temp9);
        else if (firsTtemp->currentlyThis != pointerListCreated)
            printf("\n Caution Found because node %d is not and currently This to list with head my entry = %d\n", temp9, *(int *) firsTtemp->currentlyThis->head->myEntry);

        if (!firsTtemp->currentlyTrue)
            printf("\n Caution found because node %d currentlyTrue==0!!\n", temp9);

        if (firsTtemp->myEntry)
            printf("%d\n", *(int *) (firsTtemp->myEntry));
        firsTtemp = firsTtemp->next;
        temp9++;
    }
    printf("\nList Ended \n");
    node *secondTemp = pointerListCreated->curr;

    // Checking all the possible conditions and printing the current position and it's value
    if (secondTemp >= nodeElementTrack && secondTemp < nodeElementTrack + SIZEOFNODE && secondTemp) {
        int temp7 = 0;
        while (secondTemp && secondTemp != pointerListCreated->head) {
            secondTemp = secondTemp->prev;
            temp7++;
        }
        if (pointerListCreated->curr && pointerListCreated->curr->myEntry)
            printf("Current List Pointer is now at position #%d (value: %d)\n", temp7, *(int *) pointerListCreated->curr->myEntry);
        else
            printf("Current List Pointer is now at position #%d (myEntry column is NULL)\n", temp7);
    } 

    else if (secondTemp == nodeElementTrack + SIZEOFNODEPLUSONE)
    {
        printf("Current List Pointer is currently out of bounds in the tail direction\n");
    }
    else if (!secondTemp)
    {
        printf("Current List Pointer is NULL\n");
    }

    else if (secondTemp == nodeElementTrack + SIZEOFNODE)
    {
        printf("Current List Pointer is currently out of bounds in the head direction\n");
    }
    
    else
    {
        printf("Current List Pointer is invalid. Address:  %d\n", (int) secondTemp);
    }
}


//#################################################################################################################################################################################################################################//

//Function Implementation Started From Here

//#################################################################################################################################################################################################################################//


/*
Function 1 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
list *ListCreate(void) {
    if (endLocationTrack >= SIZEOFLIST)
        return NULL;

    if (countingExtraList)
    {
        list *finalListTemp = leftListTrack[countingExtraList - 1];
        finalListTemp->currentlyTrue = 1;
        leftListTrack[countingExtraList - 1] = NULL;
        countingExtraList--;
        return finalListTemp;
    } 
    else {
        listTrack[endLocationTrack].currentlyTrue = 1;
        return &(listTrack[endLocationTrack++]);
    }
}


//Function 1 end here and return


//#################################################################################################################################################################################################################################//



/*
Function 2 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
int ListCount(const list *pointerListCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || !pointerListCreated->head != !pointerListCreated->tail){
        return -1;
    }
    return pointerListCreated->nodeCount;
}

//Function 2 end here and return

//#################################################################################################################################################################################################################################//



/*
Function 3 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListFirst(list *pointerListCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || !pointerListCreated->head != !pointerListCreated->tail){
        return NULL;
    }
    pointerListCreated->curr = pointerListCreated->head;
    return pointerListCreated->head && pointerListCreated->head->currentlyThis == pointerListCreated ? pointerListCreated->head->myEntry : NULL;
}


//Function 3 end here and return


//#################################################################################################################################################################################################################################//



/*
Function 4 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListLast(list *pointerListCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || !pointerListCreated->head != !pointerListCreated->tail){
        return NULL;
    }

    pointerListCreated->curr = pointerListCreated->tail;
    return pointerListCreated->tail && pointerListCreated->tail->currentlyThis == pointerListCreated ? pointerListCreated->tail->myEntry : NULL;
}


//Function 4 end here and return


//#################################################################################################################################################################################################################################//


/*
Function 5 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListNext(list *pointerListCreated) {
    
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || !pointerListCreated->head != !pointerListCreated->tail || !pointerListCreated->curr || !pointerListCreated->curr->currentlyTrue ||
        ((pointerListCreated->curr < nodeElementTrack || pointerListCreated->curr >= nodeElementTrack + SIZEOFNODEPLUSTWO) && pointerListCreated->curr))
        return NULL;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;
    
    void *finalTempCreat;

    
    if (pointerListCreated->curr == pointerListCreated->tail) {
        pointerListCreated->curr = nodeElementTrack + SIZEOFNODEPLUSONE;
        finalTempCreat = NULL;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODE) {
        pointerListCreated->curr = pointerListCreated->head;
        if (pointerListCreated->head){
            finalTempCreat = pointerListCreated->head->myEntry;
        }
        else{
            finalTempCreat = NULL;
        }
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODEPLUSONE) {
        finalTempCreat = NULL;
    } else {
        pointerListCreated->curr = pointerListCreated->curr->next;
        finalTempCreat = pointerListCreated->curr->myEntry;
    }
    return finalTempCreat;
}


//Function 5 end here and return


//#################################################################################################################################################################################################################################//



/*
Function 6 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListPrev(list *pointerListCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail) || !pointerListCreated->curr || !pointerListCreated->curr->currentlyTrue ||
        ((pointerListCreated->curr < nodeElementTrack || pointerListCreated->curr >= nodeElementTrack + SIZEOFNODEPLUSTWO) && pointerListCreated->curr))
        return NULL;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    void *finalTempCreat;

    
    if (pointerListCreated->curr == pointerListCreated->head) {
        pointerListCreated->curr = nodeElementTrack + SIZEOFNODE;
        finalTempCreat = NULL;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODEPLUSONE) {
        pointerListCreated->curr = pointerListCreated->tail;
        if (pointerListCreated->tail)
            finalTempCreat = pointerListCreated->tail->myEntry;
        else
            finalTempCreat = NULL;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODE) {
        finalTempCreat = NULL;
    } else {
        pointerListCreated->curr = pointerListCreated->curr->prev;
        finalTempCreat = pointerListCreated->curr->myEntry;
    }
    return finalTempCreat;
}


//Function 6 end here and return

//#################################################################################################################################################################################################################################//



/*
Function 7 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListCurr(list *pointerListCreated) {
    return pointerListCreated && pointerListCreated->currentlyTrue && !(!pointerListCreated->head != !pointerListCreated->tail) && pointerListCreated->curr && pointerListCreated->curr->currentlyTrue &&
           pointerListCreated->curr >= nodeElementTrack &&
           pointerListCreated->curr < nodeElementTrack + SIZEOFNODE && pointerListCreated->curr->currentlyThis == pointerListCreated
           ? pointerListCreated->curr->myEntry : NULL;
}

//Function 7 end here and return

//#################################################################################################################################################################################################################################//



/*
Function 8 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
int ListAdd(list *pointerListCreated, void *elementCreated) {
    
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || !pointerListCreated->head != !pointerListCreated->tail)
        return -1;

    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    
    if ((!pointerListCreated->curr || pointerListCreated->curr < nodeElementTrack || pointerListCreated->curr >= nodeElementTrack + SIZEOFNODEPLUSTWO) &&
        pointerListCreated->head)
        return -1;

    if (countingNodesInList > SIZEOFNODE - 1)
        return -1;
    node *nodePointerTemp = nodeElementTrack + countingNodesInList++;
    nodePointerTemp->myEntry = elementCreated;
    nodePointerTemp->currentlyTrue = 1;
    nodePointerTemp->currentlyThis = pointerListCreated;

   
    if (!pointerListCreated->head)
    {
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODEPLUSONE) {
        pointerListCreated->tail->next = nodePointerTemp;
        nodePointerTemp->prev = pointerListCreated->tail;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODE) {
        pointerListCreated->head->prev = nodePointerTemp;
        nodePointerTemp->next = pointerListCreated->head;
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    } else {
        nodePointerTemp->next = pointerListCreated->curr->next;
        nodePointerTemp->prev = pointerListCreated->curr;
        pointerListCreated->curr->next = nodePointerTemp;

        if (pointerListCreated->curr == pointerListCreated->tail)
            pointerListCreated->tail = nodePointerTemp;
        else
            nodePointerTemp->next->prev = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    pointerListCreated->nodeCount++;
    return 0;
}


//Function 8 end here and return


//#################################################################################################################################################################################################################################//



/*
Function 9 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
int ListInsert(list *pointerListCreated, void *elementCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail))
        return -1;

    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    if ((!pointerListCreated->curr || pointerListCreated->curr < nodeElementTrack || pointerListCreated->curr >= nodeElementTrack + SIZEOFNODEPLUSTWO) &&
        pointerListCreated->head)
        return -1;

    
    if (countingNodesInList > SIZEOFNODE - 1)
        return -1;
    node *nodePointerTemp = nodeElementTrack + countingNodesInList++;
    nodePointerTemp->myEntry = elementCreated;
    nodePointerTemp->currentlyTrue = 1;
    nodePointerTemp->currentlyThis = pointerListCreated;

    
    if (!pointerListCreated->head)
    {
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODEPLUSONE) {
        pointerListCreated->tail->next = nodePointerTemp;
        nodePointerTemp->prev = pointerListCreated->tail;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    else if (pointerListCreated->curr == nodeElementTrack + SIZEOFNODE) {
        pointerListCreated->head->prev = nodePointerTemp;
        nodePointerTemp->next = pointerListCreated->head;
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    } else {
        nodePointerTemp->prev = pointerListCreated->curr->prev;
        nodePointerTemp->next = pointerListCreated->curr;
        pointerListCreated->curr->prev = nodePointerTemp;

        if (pointerListCreated->curr == pointerListCreated->head)
            pointerListCreated->head = nodePointerTemp;
        else
            nodePointerTemp->prev->next = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    }
    pointerListCreated->nodeCount++;
    return 0;
}


//Function 9 end here and return



//#################################################################################################################################################################################################################################//



/*
Function 10 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
int ListAppend(list *pointerListCreated, void *elementCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail))
        return -1;

    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    
    if (countingNodesInList > SIZEOFNODE - 1){
        return -1;
    }

    node *nodePointerTemp = nodeElementTrack + countingNodesInList++;
    nodePointerTemp->myEntry = elementCreated;
    nodePointerTemp->currentlyTrue = 1;
    nodePointerTemp->currentlyThis = pointerListCreated;

    if (!pointerListCreated->head)
    {
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    } 
    else {
        nodePointerTemp->prev = pointerListCreated->tail;
        pointerListCreated->tail->next = nodePointerTemp;
        pointerListCreated->tail = nodePointerTemp; 
        pointerListCreated->curr = nodePointerTemp;
    }
    pointerListCreated->nodeCount++;
    return 0;
}


//Function 10 end here and return



//#################################################################################################################################################################################################################################//



/*
Function 11 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
int ListPrepend(list *pointerListCreated, void *elementCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail))
        return -1;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;


    if (countingNodesInList > SIZEOFNODE - 1)
        return -1;

    node *nodePointerTemp = nodeElementTrack + countingNodesInList++;
    nodePointerTemp->myEntry = elementCreated;
    nodePointerTemp->currentlyTrue = 1;
    nodePointerTemp->currentlyThis = pointerListCreated;

    if (!pointerListCreated->head)
    {
        pointerListCreated->head = nodePointerTemp;
        pointerListCreated->tail = nodePointerTemp;
        pointerListCreated->curr = nodePointerTemp;
    } else {
        nodePointerTemp->next = pointerListCreated->head;
        pointerListCreated->head->prev = nodePointerTemp;
        pointerListCreated->head = nodePointerTemp; 
        pointerListCreated->curr = nodePointerTemp;
    }
    pointerListCreated->nodeCount++;
    return 0;
}


//Function 11 end here and return


//#################################################################################################################################################################################################################################//


/*
Function 12 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListRemove(list *pointerListCreated) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail) || countingNodesInList > SIZEOFNODE)
        return NULL;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    if (!pointerListCreated->head || !pointerListCreated->curr || !pointerListCreated->curr->currentlyTrue || pointerListCreated->curr < nodeElementTrack ||
        pointerListCreated->curr >= nodeElementTrack + countingNodesInList)
        return NULL;

    int removingTailTemp = pointerListCreated->curr == pointerListCreated->tail ? 1 : 0;
    int boolDeletingAtHead = pointerListCreated->curr == pointerListCreated->head ? 1 : 0;
    node deletionNode = *pointerListCreated->curr;
    if (removingTailTemp && boolDeletingAtHead)
    {
        pointerListCreated->head = NULL;
        pointerListCreated->tail = NULL;
    } else if (removingTailTemp) {
        pointerListCreated->curr->prev->next = NULL;
        pointerListCreated->tail = pointerListCreated->curr->prev;
    } else if (boolDeletingAtHead) {
        pointerListCreated->curr->next->prev = pointerListCreated->head;
        pointerListCreated->head = pointerListCreated->head->next;
        pointerListCreated->head->prev = NULL;
    }
    else {
        pointerListCreated->curr->prev->next = pointerListCreated->curr->next;
        pointerListCreated->curr->next->prev = pointerListCreated->curr->prev;
    }

    node *previousNodeTemp2 = nodeElementTrack + countingNodesInList - 1;
    if (pointerListCreated->curr != previousNodeTemp2 && previousNodeTemp2->currentlyTrue) {
        *pointerListCreated->curr = *previousNodeTemp2;
        list *affectedList = previousNodeTemp2->currentlyThis;
        if (affectedList->head == previousNodeTemp2)
            affectedList->head = pointerListCreated->curr;
        if (affectedList->tail == previousNodeTemp2)
            affectedList->tail = pointerListCreated->curr;
        if (affectedList->curr == previousNodeTemp2)
            affectedList->curr = pointerListCreated->curr;
        if (previousNodeTemp2->prev)
            previousNodeTemp2->prev->next = pointerListCreated->curr;
        if (previousNodeTemp2->next)
            previousNodeTemp2->next->prev = pointerListCreated->curr;
    }
    previousNodeTemp2->currentlyTrue = 0;
    previousNodeTemp2->myEntry = NULL;
    previousNodeTemp2->next = NULL;
    previousNodeTemp2->prev = NULL;
    previousNodeTemp2->currentlyThis = NULL;
    countingNodesInList--; 
    pointerListCreated->nodeCount--;

    if (removingTailTemp)  
        pointerListCreated->curr = deletionNode.prev;
    else if (boolDeletingAtHead)
        pointerListCreated->curr = pointerListCreated->head;  
    return deletionNode.myEntry;
}


//Function 12 end here and return


//#################################################################################################################################################################################################################################//


/*
Function 13 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void ListConcat(list *firstListForConcat, list *secondListForConcat) {
    if (!firstListForConcat || !firstListForConcat->currentlyTrue || (!firstListForConcat->head != !firstListForConcat->tail) || countingNodesInList > SIZEOFNODE)
        return;
    if (!secondListForConcat || !secondListForConcat->currentlyTrue || (!secondListForConcat->head != !secondListForConcat->tail))
        return;
    if ((firstListForConcat->head && firstListForConcat->head->currentlyThis != firstListForConcat) || (firstListForConcat->tail && firstListForConcat->tail->currentlyThis != firstListForConcat))
        return;
    if ((secondListForConcat->head && secondListForConcat->head->currentlyThis != secondListForConcat) || (secondListForConcat->tail && secondListForConcat->tail->currentlyThis != secondListForConcat))
        return;

    firstListForConcat->nodeCount += secondListForConcat->nodeCount;
    if (firstListForConcat->head && secondListForConcat->head) 
    {
        firstListForConcat->tail->next = secondListForConcat->head;
        secondListForConcat->head->prev = firstListForConcat->tail;
        firstListForConcat->tail = secondListForConcat->tail;
    } else if (secondListForConcat->head) 
    {
        firstListForConcat->head = secondListForConcat->head;
        firstListForConcat->tail = secondListForConcat->tail;
    }
    node *nodePointerCreated3 = secondListForConcat->head;
    while (nodePointerCreated3) {
#ifdef DEBUG
        if (nodePointerCreated3->currentlyThis != secondListForConcat)
            printf("\n Caution Found because node with myEntry %d does not currentlyThis to secondListForConcat. Moreover, It currentlyThiss to list with head myEntry = %d\n",
                   *(int *) nodePointerCreated3->myEntry, *(int *) nodePointerCreated3->currentlyThis->head->myEntry);
#endif 
        nodePointerCreated3->currentlyThis = firstListForConcat;
        nodePointerCreated3 = nodePointerCreated3->next;
    }

    if (secondListForConcat != listTrack + endLocationTrack - 1) {
        leftListTrack[countingExtraList++] = secondListForConcat;
    } else {
        endLocationTrack--; 
    }
    secondListForConcat->currentlyTrue = 0;
    secondListForConcat->tail = NULL;
    secondListForConcat->nodeCount = 0;
    secondListForConcat->curr = NULL;
    secondListForConcat->head = NULL;
}


//Function 13 end here and return


//#################################################################################################################################################################################################################################//


/*
Function 14 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void ListFree(list *pointerListCreated, void (*itemFree)()) {
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail) || countingNodesInList > SIZEOFNODE)
        return;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated))
        return;

    pointerListCreated->curr=pointerListCreated->head;
    int endCreated4=0;
    while(pointerListCreated->head&&!endCreated4)
    {
        if(pointerListCreated->head==pointerListCreated->tail)
            endCreated4=1;
        if(pointerListCreated->head->myEntry)
            (*itemFree)(pointerListCreated->head->myEntry);
        ListRemove(pointerListCreated);
    }

    
    if (pointerListCreated != listTrack + endLocationTrack - 1) {
        leftListTrack[countingExtraList++] = pointerListCreated;
    } else {
        endLocationTrack--;
    }
    pointerListCreated->currentlyTrue = 0;
    pointerListCreated->tail = NULL;
    pointerListCreated->nodeCount = 0;
    pointerListCreated->curr = NULL;
    pointerListCreated->head = NULL;
}


//Function 14 end here and return


//#################################################################################################################################################################################################################################//


/*
Function 15 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListTrim(list *pointerListCreated) {
    
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail)||!pointerListCreated->head)
        return NULL;
    
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;
    if(pointerListCreated->tail->next)
        return NULL;

    pointerListCreated->curr=pointerListCreated->tail;
    return ListRemove(pointerListCreated);
}


//Function 15 end here and return



//#################################################################################################################################################################################################################################//



/*
Function 16 is created below. I took care of all the conditions provided
in the assignment one. Moreover, It checked by creating a different 
test cases so that It will run in all conditions with maximum Efficiency 
with a very less amount of time.
*/
void *ListSearch(list *pointerListCreated, int (*comparator)(), void *comparisonArg) {
    
    if (!pointerListCreated || !pointerListCreated->currentlyTrue || (!pointerListCreated->head != !pointerListCreated->tail))
        return NULL;
    if ((pointerListCreated->head && pointerListCreated->head->currentlyThis != pointerListCreated) || (pointerListCreated->tail && pointerListCreated->tail->currentlyThis != pointerListCreated) ||
        (pointerListCreated->curr >= nodeElementTrack && pointerListCreated->curr < nodeElementTrack + SIZEOFNODE &&
         pointerListCreated->curr->currentlyThis != pointerListCreated))
        return NULL;

    pointerListCreated->curr=pointerListCreated->head;
    while(pointerListCreated->curr)
    {
        if(pointerListCreated->curr->myEntry && (*comparator)(pointerListCreated->curr->myEntry,comparisonArg))
        {
            return pointerListCreated->curr->myEntry;
        }
        pointerListCreated->curr=pointerListCreated->curr->next;
    }
    pointerListCreated->curr=nodeElementTrack + SIZEOFNODEPLUSONE;
    return NULL;
}


//Function 16 end here and return



//###################################################################################################The End#######################################################################################################################//



