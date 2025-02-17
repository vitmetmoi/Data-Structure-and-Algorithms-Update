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
        (*head)->next = *head;
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
        (*head)->next = *head;
    }
    else
    {
        struct node *tmp = *head;
        while (tmp->next != *head)
        {
            tmp = tmp->next;
        }
        tmp->next = ptr;
        ptr->next = *head;
    }
}

void add_middle_node(struct node **head, int a, int b)
{
    struct node *ptr_a = create_node(a);
    struct node *ptr_b = create_node(b);
    struct node *tmp = *head;

    while (tmp->next != *head)
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

    if (tmp->next == *head)
    {
        add_first_node(head, a);
    }
}

void show(struct node *head)
{
    struct node *tmp = head;
    while (tmp->next != head)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d ", tmp->data);
}

int main()
{
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    // int arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add_middle_node(&head, a, b);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     scanf("%d", &num);
    //     add_last_node(&head, num);
    // }
    show(head);
}