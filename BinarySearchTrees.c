#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>



typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} TREENODE;

TREENODE* findMin(TREENODE *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left)
        return findMin(root->left);
    else
        return root;
}
TREENODE* findMax(TREENODE *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->right)
        return findMax(root->right);
    else
        return root;
}

TREENODE* BST_Insert(TREENODE* root, int dataIn)
{
    if(!root)
    {
        TREENODE *pNew;
        pNew = (TREENODE*)malloc(sizeof(TREENODE));
        pNew->data = dataIn;
        pNew->left = pNew->right = NULL;
        return pNew;
    }
    if(dataIn > root->data)
        root->right = BST_Insert(root->right,dataIn);
    else
        root->left = BST_Insert(root->left,dataIn);
    return root;
}

TREENODE* BST_deletion(TREENODE* root, int data)
{
    TREENODE *temp;
    if(!root)
        return NULL;
    else if(data < root->data)
        root->left = BST_deletion(root->left,data);
    else if(data > root->data)
        root->right = BST_deletion(root->right,data);
    else
    {
        if(root->left && root->right)
        {
            temp  = findMin(root->right);
            root->data = temp->data;
            root->right = BST_deletion(root->right,temp->data);

        }
        else
        {
            temp = root;
            if(!root->left)
                root = root->right;
            else if(!root->right)
                root = root->right;
            free(temp);
        }
    }
    return root;
}

void inOrder(TREENODE* root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%3d",root->data);
        inOrder(root->right);
    }
    return ;
}

void preOrder(TREENODE* root)
{
    if(root)
    {
        printf("%3d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    return ;
}

void postOrder(TREENODE* root)
{
    if(root)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%3d",root->data);
    }
    return ;
}

void BST_Traversal(TREENODE* root)
{
    printf("Preorder:");
    preOrder(root);
    printf("\nInorder:");
    inOrder(root);
    printf("\nPosrorder:");
    postOrder(root);
    printf("\n\n");
    return;
}

int sumAvrg(TREENODE* root, int* sum)
{
    int answer = 0;
    if(root)
    {
        *sum += root->data;
        answer++;
        answer += sumAvrg(root->left , sum);
        answer += sumAvrg(root->right , sum);
    }
    return answer;
}

int countLeaves(TREENODE* root)
{
    int answer =  0;
    if(root)
    {
        if(!root->left && !root->right){
            answer++;
            printf("leaf = %d\n",root->data);
        }
        else
        {
            answer+= countLeaves(root->right);
            answer+= countLeaves(root->left);

        }
    }
    return answer;
}

TREENODE* findSmallest(TREENODE* root)
{
    TREENODE *answer ;
    if(root)
    {
        if(!root->left)
            return root;
        answer = findSmallest(root->left);
    }
    else
        return answer;
}

int main()
{
    int index = 0 , data , count_node;
    int sum;
    double ave;
    TREENODE* root = NULL;


    while(index!=7)
    {
        printf("BST Program:\n");
        printf("1.BST insertion\n");
        printf("2.BST deletion\n");
        printf("3.BST traversal\n");
        printf("4.BST sum and average of the nodes\n");
        printf("5.BST number of leaves\n");
        printf("6.BST smallest node\n");
        printf("7.Exit\n");
        scanf("%d",&index);
        switch(index)
        {
        case 1:
            printf("Please enter intergers:");
            scanf("%d",&data);
            root = BST_Insert(root,data);
            break;
        case 2:
            printf("Please enter a data:");
            scanf("%d", &data);
            BST_deletion(root, data);
            break;
        case 3:
            BST_Traversal(root);
            break;
        case 4:
            sum = 0;
            count_node = sumAvrg(root, &sum);
            printf("Sum:%d\n", sum);
            printf("Avg:%.2f\n\n", (double)sum / count_node);
            break;
        case 5:
            sum = countLeaves(root);
            printf("%d\n\n", sum);
            break;
            case 6:
            root = findSmallest(root);
            printf("%d\n\n", root->data);
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
