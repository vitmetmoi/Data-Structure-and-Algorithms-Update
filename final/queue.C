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

void delete_last_node(struct node **head)
{
    if (*head != NULL)
    {
        struct node *tmp = *head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = NULL;
    }
}

void delete_first_node(struct node **head)
{
    if (*head != NULL)
    {
        struct node *ptr = NULL;
        ptr = (*head)->next;
        *head = ptr;
    }
}

void show(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty !\n");
    }
    else
    {
        struct node *tmp = head;
        while (tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
    }
}

void show_first(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty!\n");
    }
    else
    {
        struct node *tmp = head;
        printf("%d\n", tmp->data);
    }
}

int main()
{
    struct node *head = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            int num;
            scanf("%d", &num);
            add_first_node(&head, num);
        }
        else if (choice == 2)
        {
            delete_first_node(&head);
        }
        else if (choice == 3)
        {
            show_first(head);
        }
    }
}