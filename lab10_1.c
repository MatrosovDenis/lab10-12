#include <stdio.h>
#include <stdlib.h>
#include "labs.h"

typedef struct LNode{
    int id;
    int data;
    struct LNode *next;
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
        result->id = head->last->id+1;
        scanf("%d", &(result->data));
        head->last->next = result;
        head->last = head->last->next;
        head->count++;
    }
}

LN* copy(LN* p){
    LN* n;
    n = (LN*)malloc(sizeof(LN));
    if(n!=NULL){
        n->data = p->data;
        n->id = p->id;
        n->next = NULL;
    }
}

void copyTo(head* h, int ID, int TO){
    LN* n = h->first;
    LN* tmp;
    LN* tmp2;
    LN* newN;
    for(int i = 0; i < ID-1; i++) n = n->next;
    if(TO == 0 || TO == 1){
        tmp = h->first;
        newN = copy(n);
        newN->next = tmp;
        h->first = newN;
        h->first->id = 1;
    }
    else if(TO > h->count){
        tmp = h->last;
        h->last->next = copy(n);
        h->last = h->last->next;
    }
    else{
        tmp = h->first;
        tmp2 = h->first;
        for(int i = 0; i< TO - 1; i++) tmp = tmp->next;
        for(int i = 0; i< TO - 2; i++) tmp2 = tmp->next;
        newN = copy(n);
        tmp2->next = newN;
        newN->next = tmp;
        newN->id = tmp2->id+1;
    }
    int i = 1;
    tmp = h->first;
    while(tmp!=NULL){
        tmp->id = i;
        tmp = tmp->next;
        i++;
    }
}

void PrintNodes(head* h){
    LN* now = h->first;
    while(now!=NULL){
        printf("%d: %d\n", now->id, now->data);
        now = now->next;
    }
}

int lab10()
{
    int N, ID, TO;
    printf("Please enter number of nodes: ");
    scanf("%d", &N);

    head* h;
    h = getH();
    //LN* now = h->first;
    for(int i = 0; i < N-1; i++){
        GetNode(h);
    }
    printf("Please enter ID of node, that you want to copy: ");
    scanf("%d", &ID);
    printf("Please enter position, that will have been new node: ");
    scanf("%d", &TO);

    copyTo(h, ID, TO);

    PrintNodes(h);

    return 0;
}
