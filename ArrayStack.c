#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#define maxStack 10
int stackArray[maxStack] , stackCount = -1;
void popStack();
void pushStack();
void showTopStack();
void ListAllStack();
int main()
{
    int index = 0  , number;
    while(index!=5)
    {
    printf("1.pop a number from stack\n");
    printf("2.push a number in stack\n");
    printf("3.show top number in stack\n");
    printf("4.show all number in stack\n");
    printf("5.exit\n");

        scanf("%d",&index);
        switch(index)
        {
        case 1:
            popStack();
            break;
        case 2:
            pushStack();
            break;
        case 3:
            showTopStack();
            break;
        case 4:
            ListAllStack();
            break;
        case 5:
            break;
        default:
            printf("wrong situation\n");
        }
    }
}
void popStack()
{
    if(stackCount<0)
        printf("No number in stack");
    else
        printf("pop %d\n",stackArray[stackCount--]);
}
void pushStack()
{
    int number;
    if(stackCount>=maxStack-1)
        printf("full stack\n");
    else{
        printf("insert a number\n");
        scanf("%d",&number);
        stackArray[stackCount++] = number;
    }
}
void showTopStack()
{
    printf("Top number = %d\n",stackArray[stackCount-1]);
}
void ListAllStack()
{
    int i ;
    printf("from top to end\n");
    for(i=stackCount-1;i>=0;i--){
        printf("%d\n",stackArray[i]);
    }
}
