#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

Node *create_node(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void insert_node(struct Node **head, int data)
{
    struct Node *ptr = create_node(data);

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        ptr->next = *head;
        *head = ptr;
    }
}

void show_node(struct Node *head)
{
    struct Node *temp = head;
    printf("temp %d", temp->data);
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
        insert_node(&head, num);
    }
    show_node(head);
    return 0;
}