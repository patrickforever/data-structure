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

NODE* creates(void);         // 建立堆疊
int isEmpty(NODE *pStack);           // 堆疊已空
int stacktop(NODE *pStack);   // 傳回頂端元素
NODE* add(NODE *pStack);   // 新增元素
NODE* delete(NODE *pStack);     // 刪除元素
void list(NODE *pStack);      // 顯示所有內容


int main()
{
    int i,  j, index = 0;
    NODE *pStack;

    pStack = creates();
    num = 0;
    while(index!=5)
    {
        printf("List contain %d item", num);
        if(num > 1)
            printf("s:\n");
        else
            printf(":\n");
        list(pStack);

        printf("\n\n請輸入選項(-1結束)：");
        printf("\n1.插入值至堆疊");
        printf("\n2.顯示堆疊頂端");
        printf("\n3.刪除頂端值");
        printf("\n4.顯示所有內容");
        printf("\n5.exit\n");
        scanf("%d",&index);
        switch(index)
        {
        case 1:
            num++;
            pStack = add(pStack);
            break;
        case 2:
            printf("top = %d\n",stacktop(pStack));
            break;
        case 3:
            pStack = delete(pStack);
            break;
        case 4:
            list(pStack);
            break;
        case 5:
            break;
        default:
            printf("error insert\n");
        }
    }
    return 0;
}
NODE* creates(void)
{
    NODE *pNewStack;
    pNewStack = (NODE*) malloc(sizeof(NODE));
    pNewStack = NULL;
    return pNewStack;
}
int isEmpty(NODE *pStack)
{
    if(pStack==NULL)
        return 1;
    else
        return 0;
}
int stacktop(NODE *pStack)
{
    int number;
    number = pStack->data;
    return number;

}
NODE* add(NODE *pStack)
{
    int number ;
    NODE *pNew , *pCur ;
    pNew = (NODE*)malloc(sizeof(NODE));
    scanf("%d",&number);
    pNew ->data = number;
    pNew ->link = NULL;
    if(!pStack)
    {
        pStack = pNew;
    }
    else
    {
        pNew ->link = pStack;
        pStack = pNew;
    }
    return pStack;
}
NODE* delete(NODE *pStack)
{
    if(isEmpty(pStack) == 0)
    {
        pStack = pStack->link;
    }
    else
        return NULL;
}
void list(NODE *pStack)
{
    NODE *pCur;
    pCur = pStack;
    while(pCur)
    {
        printf("%3d ",pCur->data);
        pCur = pCur->link;
    }
    printf("\n");
    return ;
}
