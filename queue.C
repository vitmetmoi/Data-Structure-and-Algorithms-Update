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
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

void pop_node(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void show_node(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" ");
        }
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
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            pop_node(&head);
        }
        else
        {
            int num;
            scanf("%d", &num);
            push_node(&head, num);
        }
    }

    show_node(head);
    return 0;
}