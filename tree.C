#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    if (data == -1)
    {
        return NULL;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void insertNode(struct Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else if (data < (*head)->data)
    {
        insertNode(&(*head)->left, data);
    }
    else if (data > (*head)->data)
    {
        insertNode(&(*head)->right, data);
    }
    else if (data = (*head)->data)
    {
        return;
    }
}

void NLR(struct Node *head)
{
    if (head)
    {
        printf("%d ", head->data);
        NLR(head->left);
        NLR(head->right);
    }
}

void LNR(struct Node *head)
{
    if (head)
    {
        LNR(head->left);
        printf("%d ", head->data);
        LNR(head->right);
    }
}

void LRN(struct Node *head)
{
    if (head)
    {
        LRN(head->left);
        LRN(head->right);
        printf("%d ", head->data);
    }
}

int main()
{
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        insertNode(&head, num);
    }
    NLR(head);
}