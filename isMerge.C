#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the stack
struct Node
{
    char data;
    struct Node *next;
};

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, char data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node **top)
{
    if (*top != NULL)
    {
        struct Node *temp = *top;
        char data = temp->data;
        *top = temp->next;
        return data;
    }
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

int isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

int isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

int checIsMerge(char *expr)
{
    struct Node *stack = NULL;

    for (int i = 0; expr[i] != '\0'; i++)
    {

        if (!isOpeningBracket(expr[i]) && !isClosingBracket(expr[i]))
        {
            continue;
        }

        if (isOpeningBracket(expr[i]))
        {
            push(&stack, expr[i]);
        }

        else if (isClosingBracket(expr[i]))
        {

            if (isEmpty(stack))
            {
                return 0;
            }

            char lastOpening = pop(&stack);

            if (!isMatchingPair(lastOpening, expr[i]))
            {

                return 0;
            }
        }
    }

    int result = isEmpty(stack);

    return result;
}

int main()
{
    char a[10001];
    gets(a);

    printf("%d", checIsMerge(a));
    return 0;
}