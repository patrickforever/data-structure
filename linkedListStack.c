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

NODE* creates(void);         // �إ߰��|
int isEmpty(NODE *pStack);           // ���|�w��
int stacktop(NODE *pStack);   // �Ǧ^���ݤ���
NODE* add(NODE *pStack);   // �s�W����
NODE* delete(NODE *pStack);     // �R������
void list(NODE *pStack);      // ��ܩҦ����e


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

        printf("\n\n�п�J�ﶵ(-1����)�G");
        printf("\n1.���J�Ȧܰ��|");
        printf("\n2.��ܰ��|����");
        printf("\n3.�R�����ݭ�");
        printf("\n4.��ܩҦ����e");
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
