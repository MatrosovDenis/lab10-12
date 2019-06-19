#ifndef LAB12_H_INCLUDED
#define LAB12_H_INCLUDED

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

head* getCH();
void GetCNode(head* head);
void printN(head* h);
CN* Ccopy(CN* a);
CN* takeN(head* h, int N);
head* newN(head* h);

int lab12(void);

#endif // LAB12_H_INCLUDED
