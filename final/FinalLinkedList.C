#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *create_note(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void add_first_node(struct node **head, int data)
{
    struct node *ptr = create_note(data);
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
    struct node *ptr = create_note(data);
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

void add_middle_node(struct node **head, int a, int b)
{
    struct node *ptr_a = create_note(a);
    struct node *ptr_b = create_note(b);
    struct node *tmp = *head;

    while (tmp != NULL)
    {
        if (tmp->data == b)
        {
            ptr_a->next = tmp->next;
            tmp->next = ptr_a;
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }

    if (tmp == NULL)
    {
        add_first_node(head, a);
    }
}

void delete_node(struct node **head, int flag)
{
    struct node *prev = *head;
    struct node *tmp = *head;

    while (tmp != NULL)
    {
        if (tmp->data == flag)
        {
            prev = tmp;
            tmp = tmp->next;
            prev->next = tmp->next;
            break;
        }
        else
        {
            prev = tmp;
            tmp = tmp->next;
        }
    }
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

    for (int i = 0; i < m; i++)
    {
        int flag;
        scanf("%d", &flag);
        delete_node(&head, flag);
    }

    show(head);
}