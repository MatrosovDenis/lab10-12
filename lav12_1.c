#include <stdio.h>
#include <stdlib.h>
#include "labs.h"

typedef struct CNode{
    int id;
    int data;
    struct CNode *next;
    struct CNode *prev;
}CN;

typedef struct head{
    int count;
    CN* first;
    CN* last;
}head;

typedef struct LNode{
    int id;
    int data;
    struct LNode *next;
}LN;

typedef struct lhead{
    int count;
    LN* first;
    LN* last;
}headL;

headL* getHL(){
    headL* h;
    h = (headL*)malloc(sizeof(headL));
    if(h!=NULL)
    {
        h->first = NULL;
        h->last = NULL;
        h->count = 0;
    }
}

LN* copy(CN* c){
    LN* l;
    l = (LN*)malloc(sizeof(LN));
    if(l!=NULL){
        l->next = NULL;
        l->id = 1;
        l->data = c->data;
    }
    return l;
}

head* getH(){
    head* h;
    h = (head*)malloc(sizeof(head));
    if(h!=NULL)
    {
        h->count = 1;
        h->first = (CN*)malloc(sizeof(CN));
        if(h->first!=NULL){
            h->first->id = 1;
            h->first->next = h->first;
            h->first->prev = h->last;
            scanf("%d", &h->first->data);
            h->last = h->first;
        }
    }
    return h;
}

void GetNode(head* head){
    CN* prev = head->last;
    CN* result;
    result = (CN*)malloc(sizeof(CN));
    if(result!=0){
        result->prev = head->last;
        result->next = head->first;
        head->last->next = result;
        head->first->prev = result;
        result->id = head->last->id+1;
        head->count++;
        scanf("%d", &(result->data));
        head->last = result;
    }
}

void copyCtoL(headL* l, head* c){
    LN* nowl = l->first;
    CN* nowc = c->first;
    int ID = 1;
    if(((c->count) % 2)==1){
        for(int i = 0; i< c->count/2 -1 ; i++){
            nowc = nowc->next;
        }
        l->first = copy(nowc);
        l->count++;
        for(int i = 1; i< c->count/2-1; i++){

        }
    }
    else{

    }
}

void printN(headL* h){
    LN* tmp = h->first;
    for(int i = 0; i < h->count; i++){
        printf("%d: %d\n", tmp->id, tmp->data);
        tmp = tmp->next;
    }
}

int lab12()
{
    int N, b;
    printf("Please enter number of nodes: ");
    scanf("%d", &N);
    printf("Please enter nodes: ");
    head* h;
    head* l;
    l = getHL();
    h = getH();
    for(int i = 0; i< N-1; i++){
        GetNode(h);
    }
    copyCtoL(l, h);
    printN(l);
    return 0;
}
