//
//  LIST.h
//  Assignment_1CMPT300
//
//  Created by Pranjal Keshari on 2020-01-28.
//  Copyright © 2020 Pranjal. All rights reserved.
//


//#################################################################################################################################################################################################################################//

//Important Header Files
#ifndef myFunction_h
#define myFunction_h
#pragma once

#include <stdlib.h>
#include <stdio.h>


//#################################################################################################################################################################################################################################//

//Creating a Structure node
typedef struct node {
    void *myEntry;
    struct node *prev;
    struct node *next;
    int currentlyTrue;
    struct list *currentlyThis;
} node;
//Creating a structure list
typedef struct list {
    node *curr;
    node *head;
    node *tail;
    int nodeCount;
    int currentlyTrue;
} list;


//#################################################################################################################################################################################################################################//

//Creating constant to fix the size of node and list
#ifndef DEBUG
#define SIZEOFLIST 150
#define SIZEOFNODE 600
#define SIZEOFNODEPLUSTWO 602
#define SIZEOFNODEPLUSONE 601
#define SIZEOFLISTMINUSONE 149
#endif


//#################################################################################################################################################################################################################################//

//Function 1
list *ListCreate(void);
//Function 2
int ListCount(const list *pointerListCreated);
//Function 3
void *ListFirst(list *pointerListCreated);
//Function 4
void *ListLast(list *pointerListCreated);
//Function 5
void *ListNext(list *pointerListCreated);
//Function 6
void *ListPrev(list *pointerListCreated);
//Function 7
void *ListCurr(list *pointerListCreated);
//Function 8
int ListAdd(list *pointerListCreated, void *elementCreated);
//Function 9
int ListInsert(list *pointerListCreated, void *elementCreated);
//Function 10
int ListAppend(list *pointerListCreated, void *elementCreated);
//Function 11
int ListPrepend(list *pointerListCreated, void *elementCreated);
//Function 12
void *ListRemove(list *pointerListCreated);
//Function 13
void ListConcat(list *list1, list *list2);
//Function 14
void ListFree(list *pointerListCreated, void (*itemFree)(void));
//Function 15
void *ListTrim(list *pointerListCreated);
//Function 16
void *ListSearch(list *pointerListCreated, int (*comparator)(), void *comparisonArg);



//#################################################################################################################################################################################################################################//


#endif /* LIST_h */


//#################################################################################################################################################################################################################################//
