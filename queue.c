#include <stdio.h>
#include <stdlib.h>

//Prototypes
void insert(void);
void delete_element(void);
void traverse(void);

#define CAPACITY 5
int queue[CAPACITY];
int front = 0, rear = 0;

int main(void)
{
    int choice;

    while(1)
    {
        printf("1: To Insert emelemt.\n");
        printf("2: To Delete element\n");
        printf("3: To display elements\n");
        printf("4: To Quit..\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    insert();
                    break;
            case 2:
                    delete_element();
                    break;
            case 3:
                    traverse();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("Invalid input try again..\n");
        }
    }
}

void insert()
{
    if (rear == CAPACITY)
    {
        printf("You are in queue but the Queue is full\n");
    }
    else
    {
        int temp;
        printf("Give me value: ");
        scanf("%d", &temp);
        queue[rear] = temp;
        rear++;
    }
}

void delete_element()
{
    if (front == rear)
    {
        printf("Queue is empty you dumb..\n");
    }
    else
    {
        for(int i = 0; i < (rear - 1); i++)
        {
            if(i == 0)
            {
                printf("Deleted Element is: %d \n", queue[i]);
            }
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void traverse()
{
    if (front == rear)
    {
        printf("Again...Queue is empty you dumb\n");
    }
    else
    {
        printf("Queue elements are: ");
        for(int i = 0; i < rear; i++)
        {
            printf("%d, ", queue[i]);
        }
        printf("\n\n");
    }
}