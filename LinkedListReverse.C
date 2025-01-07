#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void push_node(struct Node **head, int data)
{

    struct Node *ptr = create_node(data);
    if (*head == NULL)
    {
        *head = ptr;
        ptr->next = *head;
    }
    else
    {
        ptr->next = *head;
        *head = ptr;
    }
}

void show(struct Node *head)
{

    struct Node *tmp = head;
    while (tmp->next != head)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void add_at_last(struct Node **head, int data)
{
    struct Node *ptr = create_node(data);
    if (*head == NULL)
    {
        (*head) = ptr;
        ptr->next = (*head);
    }
    else
    {

        struct Node *tmp = *head;
        while (tmp->next != *head)
        {
            tmp = tmp->next;
        }

        tmp->next = ptr;
        ptr->next = *head;
        // printf("test %d\n", tmp->data);
    }
}

int main()
{

    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int number;
        scanf("%d", &number);
        push_node(&head, number);
    }
    show(head);
}