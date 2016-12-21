#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>



typedef struct nodeTag
{
    int data;
    struct nodeTag* next;
} NODE;

typedef struct
{
    NODE* front;
    int count;
    NODE* rear;
}QUEUE;

bool enqueue(QUEUE* pQueue, int Indata)
{
    NODE *pNew;
    pNew = (NODE*)malloc(sizeof(NODE));
    pNew ->data = Indata;
    pNew ->next = NULL;
    if(pQueue->count == 0){
        pQueue->front  = pNew;
    }
    else
    {
        pQueue->rear->next = pNew;

    }
    pQueue->rear = pNew;
    (pQueue->count) ++;
        return true;

}

bool dequeue(QUEUE* pQueue, int* Outdata)
{
    NODE *delNode;
    if(pQueue->count==0)
        return false;
    *Outdata = pQueue->front->data;
    delNode = pQueue->front;
    (pQueue->count)--;
    if(!pQueue->count)
        pQueue->front = pQueue->rear = NULL;
    else
        pQueue->front = pQueue->front->next;

    free(delNode);

    return true;

}
bool printQueue(QUEUE* pQueue)
{
    if(!pQueue->count)
        return false;
    NODE *pCur;
    pCur = pQueue->front;
    while(pCur)
    {
        printf("%3d ",pCur->data);
        pCur = pCur->next;
    }
    printf("\n");
}
void copyQueue(QUEUE* pQueue)
{
    QUEUE *pQueueCopy;
    pQueueCopy = (QUEUE*) malloc(sizeof(QUEUE));
    pQueueCopy->front = NULL;
    pQueueCopy->count = 0;
    pQueueCopy->rear = NULL;
    NODE *pQueueNode;
    int number;
    pQueueNode = pQueue->front;
    while(pQueueNode)
    {
        number = pQueueNode->data;
        enqueue(pQueueCopy,number);
        pQueueNode = pQueueNode->next;
    }
    printf("Queue1:");
    printQueue(pQueue);
    printf("\n");
    printf("Queue2:");
    printQueue(pQueueCopy);
    printf("\n");
}
void sum_and_average(QUEUE* pQueue)
{
    int sum = 0 ;
    NODE *pCur;
    pCur = pQueue->front;
    while(pCur)
    {
        sum += pCur->data;
        pCur = pCur->next;
    }
    printf("sum = %d average = %f\n",sum,(double)sum/pQueue->count);
}
void deletes_all_negative(QUEUE* pQueue)
{
    NODE *pCur , *pPre;
    pCur = pQueue->front;
    pPre = NULL;
    while(pCur)
    {

        if(pCur->data < 0)
        {
            pPre->next = pCur->next;
            pQueue->count --;
            free(pCur);
            pCur = pPre->next;
        }
        else
        {
             pPre = pCur;
             pCur = pCur->next;
        }


    }
    printQueue(pQueue);
}
int main()
{
    int i,  j, index = 0 , number;
    bool flag;
    QUEUE *pQueue;

    pQueue = (QUEUE*) malloc(sizeof(QUEUE));
    pQueue->front = NULL;
    pQueue->count = 0;
    pQueue->rear = NULL;
    while(index!=8)
    {
        printf("\n\n請輸入選項(-1結束)：");
        printf("\n1.插入值至queue");
        printf("\n2.delete from queue");
        printf("\n3.顯示所有內容");
        printf("\n4.copy queue");
        printf("\n5.caculate sum and average");
        printf("\n6.delete negative in queue");
        printf("\n7.");
        printf("\n8.exit\n");
        scanf("%d",&index);
        switch(index)
        {
        case 1:
            scanf("%d",&number);
            enqueue(pQueue ,number);
            break;
        case 2:
            dequeue(pQueue ,&number );
            printf("top = %d\n",number);
            break;
        case 3:
            printQueue(pQueue);
            break;
        case 4:
            copyQueue(pQueue);
            break;
        case 5:
            sum_and_average(pQueue);
            break;
            case 6:
            deletes_all_negative(pQueue);
            break;
            case 7:
            break;
            case 8:
            break;
        default:
            printf("error insert\n");
        }
    }
    return 0;
}
