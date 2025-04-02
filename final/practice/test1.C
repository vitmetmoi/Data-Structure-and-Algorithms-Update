#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void add_first_node(struct node **head, int data)
{
    struct node *ptr = create_node(data);
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

void add_last_node(struct node **head, int data)
{
    struct node *ptr = create_node(data);
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = ptr;
    }
}

void delete_last_node(struct node **head, int flag, int size)
{
    struct node *tmp = *head;
    for (int i = 0; i < size - flag - 1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

void show(struct node *head)
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    struct node *head = NULL;
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        add_first_node(&head, num);
    }
    delete_last_node(&head, m, n);
    show(head);
}