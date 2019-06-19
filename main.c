#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"
#include "lab11.h"
#include "lab12.h"

int main(){
    int N;
    scanf("%d", &N);
    switch(N){
case 10:
     lab10();
    break;
case 11:
     lab11();
    break;
case 12:
     lab12();
    break;
    }
    return 0;
}
