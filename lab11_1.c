#include <stdio.h>
#include <stdlib.h>
#include "labs.h"

typedef struct LNode{
    int id;
    int data;
    struct LNode *next;
    struct LNode *prev;
}LN;

typedef struct head{
    int count;
    LN* first;
    LN* last;
}head;

head* getH(){
    head* h;
    h = (head*)malloc(sizeof(head));
    if(h!=NULL)
    {
        h->count = 1;
        h->first = (LN*)malloc(sizeof(LN));
        scanf("%d", &h->first->data);
        h->first->id = 1;
        h->first->next = NULL;
        h->first->next = NULL;
        h->last = h->first;

    }
    return h;
}

void GetNode(head* head){
    LN* prev = head->last;
    LN* result;
    result = (LN*)malloc(sizeof(LN));
    if(result!=NULL){
        result->next = NULL;
        result->prev = head->last;
        result->id = head->last->id+1;
        scanf("%d", &(result->data));
        head->last->next = result;
        head->last = head->last->next;
        head->count++;
    }
}

void printElem(head* h){
    LN* now = h->first;
    while(now!=NULL){
        printf("%d\t", now->data);
        now = now->next;
    }
}

void deleteOne(head* h, int nID){
    if((nID > h->count) || (nID < 2)){
        printf("Invalid ID!!!\n");
    }
    else if(nID > 2){
        LN* now = h->first;
        for(int i = 0; i< nID-2; i++){
            now = now->next;
        }
        now->prev->next = now->next;
        now->next->prev = now->prev;
        free(now);
        h->count--;
    }
    else{
        LN* now = h->first;
        h->first = h->first->next;
        free(now);
    }
}

int lab11(){
    int N = 0, ID;
    printf("Enter number of element in sequence: ");
    scanf("%d", &N);
    head* h;
    printf("Enter sequence: ");
    h = getH();
    for(int i = 0; i< N-1; i++){
        GetNode(h);
    }
    printf("Enter ID: ");
    scanf("%d", &ID);
    deleteOne(h, ID);
    printElem(h);
    return 0;
}
