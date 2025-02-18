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

void add_at_first(struct node **head, int data)
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

void delete_node(struct node **head, int n, int amount)
{
    struct node *tmp = *head;
    for (int i = 0; i < n - amount - 1; i++)
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
        add_at_first(&head, num);
    }

    delete_node(&head, n, m);
    show(head);
}