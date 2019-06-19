#ifndef LAB10_H_INCLUDED
#define LAB10_H_INCLUDED

typedef struct LONode{
    int id;
    int data;
    struct LONode *next;
}LON;

typedef struct LOhead{
    int count;
    LON* first;
    LON* last;
}LOhead;

LOhead* getH();
void GetNode(LOhead* LOhead);
LON* copy(LON* p);
void copyTo(LOhead* h, int ID, int TO);
void PrintNodes(LOhead* h);

int lab10(void);

#endif // LAB10_H_INCLUDED
