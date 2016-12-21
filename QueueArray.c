#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#define maxStack 5
int queueArray[maxStack] , front = 0 , end =0;
void popQueue();
void pushQueue();
void showTopQueue();
void ListAllQueue();
int main()
{
    int index = 0  , number;
    while(index!=5)
    {
    printf("1.pop a number from queue\n");
    printf("2.push a number in queue\n");
    printf("3.show top number in queue\n");
    printf("4.show all number in queue\n");
    printf("5.exit\n");

        scanf("%d",&index);
        switch(index)
        {
        case 1:
            popQueue();
            break;
        case 2:
            pushQueue();
            break;
        case 3:
            showTopQueue();
            break;
        case 4:
            ListAllQueue();
            break;
        case 5:
            break;
        default:
            printf("wrong situation\n");
        }
    }
}
void popQueue()
{
    if(front == end || end == maxStack-1 || front== 0)
        printf("can't pop\n");
    else
        printf("pop = %d\n",queueArray[end++]);
}
void pushQueue()
{
    int number;
    if(front== maxStack-1 )
        printf("full queue\n");
    else{
        printf("insert push number\n");
        scanf("%d",&number);
        queueArray[front++] = number;
    }
}
void showTopQueue()
{
    printf("top = %d\n",queueArray[end]);
}
void ListAllQueue()
{
    int endTemp , frontTemp;
    frontTemp = front;
    endTemp = end;
    while(endTemp!= frontTemp){
        printf("%d ",queueArray[endTemp++]);
    }
    printf("\n");
}
