#ifndef LAB11_H_INCLUDED
#define LAB11_H_INCLUDED

typedef struct LNode{
    int id;
    int data;
    struct LNode *next;
    struct LNode *prev;
}LN;

typedef struct Lhead{
    int count;
    LN* first;
    LN* last;
}Lhead;

Lhead* getLH();
void GetLNode(Lhead* Lhead);
void printElem(Lhead* h);
void deleteOne(Lhead* h, int nID);

int lab11(void);

#endif // LAB11_H_INCLUDED
