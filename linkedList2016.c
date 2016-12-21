#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>



typedef struct nodeTag
{
    int data;
    struct nodeTag* link;
} NODE;

int num;
int count;

NODE* insertFN(NODE* pList);
NODE* DeleteFN(NODE* pList);
NODE* DeleteNegative(NODE* pList);
NODE* DeleteAfterNode(NODE* pList);
NODE* DeleteBeforeNode(NODE* pList);
NODE* AppendList(NODE* pList);
NODE* searchList(NODE* pList, int data);
void listData(NODE* pList);


int main()
{
    int i,  j, index = 0;
    NODE *pList;

    pList = (NODE*) malloc(sizeof(NODE));
    pList = NULL;
    num = 0;
    while(index!=8)
    {
        printf("List contain %d item", num);
        if(num > 1)
            printf("s:\n");
        else
            printf(":\n");
        listData(pList);

        printf("\t1.Insert a data\n");
        printf("\t2.Delete a data\n");
        printf("\t3.Delete all nodes whose keys are negative\n");
        printf("\t4.Delete all nodes that are after a node with key\n");
        printf("\t5.Delete all nodes that are before a node with key\n");
        printf("\t6.Appends a general list to itself\n");
        printf("\t7.List all data\n");
        printf("\t8.exit\n");
        scanf("%d",&index);
        switch(index)
        {
        case 1:
            num++;
            pList = insertFN(pList);
            break;
        case 2:
            pList = DeleteFN(pList);
            break;
        case 3:
            pList = DeleteNegative(pList);
            break;
        case 4:
            pList = DeleteAfterNode(pList);
            break;
        case 5:
            pList = DeleteBeforeNode(pList);
            break;
        case 6:
            pList = AppendList(pList);
            break;
        case 7:
            listData(pList);
            break;
        case 8:
            break;
        default:
            printf("error insert\n");
        }
    }
    return 0;
}
NODE* searchList(NODE* pList, int data)
{
    NODE *pCur , *pPre;
    pPre = NULL;
    pCur = pList;
    while(pCur && data > pCur->data)
    {
        pPre = pCur;
        pCur = pCur->link;
    }
    return pPre;
}

NODE* insertFN(NODE* pList)
{
    NODE *pCur ,*pPre , *pNew;
    int number;
    pNew = (NODE*)malloc(sizeof(NODE));
    printf("insert a number \n");
    scanf("%d",&number);
    pNew->data = number;
    pNew->link = NULL;
    if(pList == NULL){
        pList = pNew;
        return pList;
    }
    pPre = searchList(pList,number);
    if(pPre  == NULL)
    {
        pNew->link = pList;
        pList = pNew;
    }
    else
    {
        pNew->link = pPre->link;
        pPre->link = pNew;
    }
    return pList;
}

NODE* DeleteFN(NODE* pList)
{
    NODE *pCur , *pPre;
    int number;
    printf("insert a number to delete\n");
    scanf("%d",&number);
    pPre = searchList(pList,number);
    num--;
    if(pPre == NULL)
    {

        pList = pList->link;
    }
    else
    {
        pCur = pPre->link;
        pPre ->link = pCur->link;
    }
    return pList;
}
NODE* DeleteNegative(NODE* pList)
{
    NODE *pCur , *pPre;
    pCur = pList ;
    pPre = NULL;
    while(pCur)
    {
        if(pCur->data < 0 && !pPre)
        {
            pList = pCur->link;

            num--;
        }
        else if(pCur->data <0)
        {
            pPre->link = pCur->link;
            num--;
        }
        else
        {
            pPre = pCur;
        }
        pCur = pCur->link;
    }
    return pList;
}
NODE* DeleteAfterNode(NODE* pList)
{
    NODE *pCur , *pPre;
    int number;
    printf("insert a number to kill after\n");
    scanf("%d",&number);
    pPre = searchList(pList,number);
    if(pPre == NULL)
    {
        pList = NULL;
        num = 0;
    }
    else
    {
        pPre->link = NULL;
    }
    return pList;
}
NODE* DeleteBeforeNode(NODE* pList)
{
    NODE *pCur , *pPre;
    int number;
    printf("insert a number to kill before\n");
    scanf("%d",&number);
    pPre = searchList(pList,number);
    if(!pPre)
    {
        pList = pList->link;
    }
    else
    {
        pCur = pPre->link;
        pCur = pCur->link;
        pList = pCur;
    }
    return pList;
}
NODE* AppendList(NODE* pList)
{
    NODE *pCur , *pPre;
    NODE *pNewList , *pNewListCur , *pNewListNode;
    pCur = pList;
    pPre = pNewList = pNewListCur = NULL;
    while(pCur)
    {
        pNewListNode = (NODE*)malloc(sizeof(NODE));
        pNewListNode->data = pCur->data;
        pNewListNode->link = NULL;
        if(!pNewList)
            pNewList = pNewListCur = pNewListNode;
        else
        {
            pNewListCur->link = pNewListNode;
            pNewListCur = pNewListCur->link;
        }
        pPre = pCur;
        pCur = pCur->link;
    }
    pPre->link = pNewList;
    return pList;
}
void listData(NODE* pList)
{
    num = 0;
    NODE *pCur;
    pCur = pList;
    while(pCur)
    {
        printf("%3d ",pCur->data);
        pCur = pCur->link;
        num++;
    }
    printf("\n");
}
