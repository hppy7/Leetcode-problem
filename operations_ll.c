#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} sl;

sl *insert(sl *head);
sl *deletion(sl *head);
void display(sl *head);
void totalnodes(sl *head);
void evenandodd(sl *head);
void alternatell(sl *head);

sl *insert(sl *head)
{
    sl *p = head;
    sl *new_node = (sl *)malloc(sizeof(sl));
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new_node;
    }
    return head;
}

sl *deletion(sl *head)
{
    int index, i;
    printf("Enter the index to delete: ");
    scanf("%d", &index);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    sl *p = head;
    if (index == 0)
    {
        head = head->next;
        free(p);
        return head;
    }

    for (i = 0; i < index - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL || p->next == NULL)
    {
        printf("Index out of bounds.\n");
        return head;
    }

    sl *temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}

void display(sl *head)
{
    sl *p = head;
    if (p == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void totalnodes(sl *head)
{
    sl *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    printf("Total number of nodes: %d\n", count);
}

void evenandodd(sl *head)
{
    sl *p = head;
    int even_count = 0, odd_count = 0;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
            even_count++;
        else
            odd_count++;
        p = p->next;
    }
    printf("Even nodes: %d, Odd nodes: %d\n", even_count, odd_count);
}

void alternatell(sl *head)
{
    sl *p = head;
    int count = 1;
    while (p != NULL)
    {
       if(count%2==0)
       {
        printf("%d\t",p->data);
       }
       count++;
       p=p->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;
    sl *p = NULL;

    do
    {
        printf("1. Insert to left of linked list.\n");
        printf("2. Delete at index.\n");
        printf("3. Display linked list.\n");
        printf("4. Total nodes.\n");
        printf("5. Even and odd nodes.\n");
        printf("6. Alternate nodes of linked list.\n");
        printf("6. Exiting from the code.\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                p = insert(p);
                break;
            case 2:
                p = deletion(p);
                break;
            case 3:
                display(p);
                break;
            case 4:
                totalnodes(p);
                break;
            case 5:
                evenandodd(p);
                break;
            case 6:
                alternatell(p);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch >= 1 && ch <= 7);

    return 0;
}
