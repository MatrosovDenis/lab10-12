#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"


LOhead* getH(){
    LOhead* h;
    h = (LOhead*)malloc(sizeof(LOhead));
    if(h!=NULL)
    {
        h->count = 1;
        h->first = (LON*)malloc(sizeof(LON));
        scanf("%d", &h->first->data);
        h->first->id = 1;
        h->first->next = NULL;
        h->last = h->first;

    }
    return h;
}

void GetNode(LOhead* LOhead){
    LON* prev = LOhead->last;
    LON* result;
    result = (LON*)malloc(sizeof(LON));
    if(result!=NULL){
        result->next = NULL;
        result->id = LOhead->last->id+1;
        scanf("%d", &(result->data));
        LOhead->last->next = result;
        LOhead->last = LOhead->last->next;
        LOhead->count++;
    }
}

LON* copy(LON* p){
    LON* n;
    n = (LON*)malloc(sizeof(LON));
    if(n!=NULL){
        n->data = p->data;
        n->id = p->id;
        n->next = NULL;
    }
}

void copyTo(LOhead* h, int ID, int TO){
    LON* n = h->first;
    LON* tmp;
    LON* tmp2;
    LON* newN;
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

void PrintNodes(LOhead* h){
    LON* now = h->first;
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

    LOhead* h;
    h = getH();
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
