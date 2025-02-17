#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (data == -1)
    {
        ptr = NULL;
    }
    else
    {
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
    }

    return ptr;
}

struct node *insert_node(struct node *Tree, int data)
{
    if (Tree == NULL)
    {
        Tree = create_node(data);
    }
    else if (data < Tree->data)
    {
        Tree->left = insert_node(Tree->left, data);
    }
    else if (data > Tree->data)
    {
        Tree->right = insert_node(Tree->right, data);
    }
    return Tree;
}

void NLR(struct node *Tree)
{
    if (Tree)
    {
        printf("%d ", Tree->data);
        NLR(Tree->left);
        NLR(Tree->right);
    }
}

void LNR(struct node *Tree)
{
    if (Tree)
    {
        LNR(Tree->left);
        printf("%d ", Tree->data);
        LNR(Tree->right);
    }
}
void LRN(struct node *Tree)
{
    if (Tree)
    {
        LRN(Tree->left);
        LRN(Tree->right);
        printf("%d ", Tree->data);
    }
}

int main()
{
    struct node *Tree = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        Tree = insert_node(Tree, num);
    }

    LRN(Tree);
}