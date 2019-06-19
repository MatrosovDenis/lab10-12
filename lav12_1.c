#include <stdio.h>
#include <stdlib.h>
#include "lab12.h"

head* getCH(){
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

void GetCNode(head* head){
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


void printN(head* h){
    CN* tmp = h->first;
    for(int i = 0; i < h->count; i++){
    printf("%d: %d\n", tmp->id, tmp->data);
    tmp = tmp->next;
    }
}

CN* Ccopy(CN* a){
    CN* result;
    result = (CN*)malloc(sizeof(CN));
    result->data = a->data;
    result->id = a->id;
    result->prev = NULL;
    result->next = NULL;
}

CN* takeN(head* h, int N){
    CN* result;
    CN* now = h->first;
    for(int i = 1; i < N; i++){
        now = now->next;
    }
    result = Ccopy(now);
    return result;
}

head* newN(head* h){
    head* result;
    result = (head*)malloc(sizeof(head));
    result->first = takeN(h, (h->count)/2);
    result->first->id = 1;
    CN* now = result->first;
    for(int i = (h->count)/2 - 1; i > 0; i--){
        now->next = takeN(h, i);
        now->next->id = now->id + 1;
        now->next->prev = now;
        now = now->next;
    }
    if(h->count%2 == 1){
        now->next = takeN(h, h->count/2 + 1);
        now->next->id = now->id + 1;
        now->next->prev = now;
        now = now->next;
    }
    for(int i = h->count; i > (h->count/2 + h->count%2); i--){
        now->next = takeN(h, i);
        now->next->id = now->id + 1;
        now->next->prev = now;
        now = now->next;
    }
    result->count = h->count;
    return result;
}

int lab12()
{
    int N, b;
    printf("Please enter number of nodes: ");
    scanf("%d", &N);
    printf("Please enter nodes: \n");
    head* h;
    head* newH;
    h = getCH();
    for(int i = 0; i< N-1; i++){
        GetCNode(h);
    }
    newH = newN(h);
    printf("Result is: \n");
    printN(newH);
    return 0;
}
