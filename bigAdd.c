#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
void bigAdd(char *number1,char *number2,char *answer)
{
    int i , j  ,length1 , length2 , step = 0 , carry=0 , sum;
    length1 = strlen(number1)-1;
    length2 = strlen(number2)-1;

    while(length1>=0 && length2>=0)
    {
        sum = carry + (number1[length1--]-'0') + (number2[length2--]-'0') ;
        //printf("sum = %d\n",sum);
        carry = sum/10;
        sum %= 10;
        answer[step++] = sum;
    }
    while(length1>=0)
    {
        sum = number1[length1--]-'0' + carry;
        //printf("length sum = %d\n",sum);
        carry = sum/10;
        sum %= 10;
        answer[step++] = sum;
    }
    while(length2>=0)
    {
        sum = number2[length2--]-'0' + carry;
        carry = sum/10;
        sum %= 10;
        answer[step++] = sum;
    }
    if(carry)
        answer[step++] = carry;
    i = step-1;
    while(i>=0)
        printf("%d",answer[i--]);
}
void bigAdd2(char *number1,char *number2,char *answer)
{
    int i , j , length1 , length2 , sum , carry=0 ,step=0;
    length1 = strlen(number1)-1;
    length2 = strlen(number2)-1;

    while(length1>=0 || length2>=0)
    {
        i = (length1>=0)? (number1[length1--]-'0') : 0;
        j = (length2>=0)? (number2[length2--]-'0') : 0;
        sum = i + j + carry;
        carry = sum /10 ;
        sum %= 10;
        answer[step++] = sum;
    }
    if(carry)
        answer[step++] = sum;
    i = step -1;
    while(i>=0)
        printf("%d",answer[i--]);
}
int main()
{
    int i , j ,nCase;
    char number1[100];
    char number2[100];
    char answer[100];
    scanf("%d",&nCase);
    while(nCase--)
    {
        scanf("%s%s",number1,number2);
        bigAdd2(number1,number2,answer);
    }


}
