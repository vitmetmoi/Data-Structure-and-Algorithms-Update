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

void insert_node_end(struct Node **head, int data)
{
    struct Node *ptr = create_node(data);

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = ptr;
        // *head = ptr;
    }
}
void show_node(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete_last_node(struct Node **head, int n, int amount)
{
    struct Node *tmp = *head;
    for (int i = 0; i < n - amount; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    *head = tmp;
}

void delete_first_node(struct Node **head, int n, int amount)
{
    struct Node *tmp = *head;
    for (int i = 0; i < n - amount; i++)
    {
        tmp = tmp->next;
    }

    struct Node *newNode = NULL;

    // printf("test %d", tmp->data);
    while (tmp != NULL)
    {
        insert_node_end(&newNode, tmp->data);
        tmp = tmp->next;
    }
    *head = newNode;
    // *head = tmp;
}

void delete_middle_node(struct Node **head, int number)
{
    struct Node *tmp = *head;
    struct Node *prev = *head;
    while (tmp != NULL)
    {
        prev = tmp;
        if (tmp->data == number)
        {
            printf("tmp: %d", tmp->data);

            prev = tmp->next;
        }
        tmp = tmp->next;
    }
}

void insert_middle_node(struct Node **head, int a, int b)
{
    struct Node *tmp = *head;
    struct Node *ptr_a = create_node(a);
    struct Node *ptr_b = create_node(b);
    while (tmp != NULL)
    {

        if (tmp->data == b)
        {
            ptr_a->next = tmp->next;
            tmp->next = ptr_a;
            break;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        insert_node(head, a);
    }
}

int main()
{

    // struct Node *head = NULL;
    // int n;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     int a, b;
    //     scanf("%d", &a);
    //     scanf("%d", &b);
    //     insert_middle_node(&head, a, b);
    // }
    // show_node(head);

    // Delete first node

    // struct Node *head = NULL;
    // int n, amount;
    // scanf("%d", &n);
    // scanf("%d", &amount);
    // for (int i = 0; i < n; i++)
    // {
    //     int number;
    //     scanf("%d", &number);
    //     insert_node(&head, number);
    // }
    // delete_first_node(&head, n, amount);
    // show_node(head);

    // delete middle node

    struct Node *head = NULL;
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        int number;
        scanf("%d", &number);
        insert_node(&head, number);
    }

    for (int i = 0; i < m; i++)
    {
        int number;
        scanf("%d", &number);
        delete_middle_node(&head, number);
    }

    show_node(head);

    return 0;
}

/*
4

2 5

6 2

7 3

9 7
*/