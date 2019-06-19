#ifndef LABS_H_INCLUDED
#define LABS_H_INCLUDED

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

int lab12(void);

#endif // LABS_H_INCLUDED

