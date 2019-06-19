#include <stdio.h>
#include <stdlib.h>
#include "lab11.h"

Lhead* getLH(){
    Lhead* h;
    h = (Lhead*)malloc(sizeof(Lhead));
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

void GetLNode(Lhead* Lhead){
    LN* prev = Lhead->last;
    LN* result;
    result = (LN*)malloc(sizeof(LN));
    if(result!=NULL){
        result->next = NULL;
        result->prev = Lhead->last;
        result->id = Lhead->last->id+1;
        scanf("%d", &(result->data));
        Lhead->last->next = result;
        Lhead->last = Lhead->last->next;
        Lhead->count++;
    }
}

void printElem(Lhead* h){
    LN* now = h->first;
    while(now!=NULL){
        printf("%d\t", now->data);
        now = now->next;
    }
}

void deleteOne(Lhead* h, int nID){
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
    Lhead* h;
    printf("Enter sequence: ");
    h = getLH();
    for(int i = 0; i< N-1; i++){
        GetLNode(h);
    }
    printf("Enter ID: ");
    scanf("%d", &ID);
    deleteOne(h, ID);
    printElem(h);
    return 0;
}
