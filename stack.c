#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5
int stack[CAPACITY];

//prototype
void push(int);
int pop();
int is_Empty();
int is_Full();
int peek();
void traversal();

int choice, element, top = 0;

int main(void)
{
    while(1)
    {
        int a; int b;
        printf("Select the action you want to perform: \n");
        printf("1 to insert the element \n");
        printf("2 to retrive the element \n");
        printf("3 to peek in stack \n");
        printf("4 to traversal \n");
        printf("5 to Quit \n");
        printf("\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    printf("Give me the element: \n");
                    scanf("%d", &element);
                    push(element);
                    break;
            case 2:
                    a = pop();
                    if(a != 0)
                    {
                        printf("POP element is: %d\n",a);
                        break;
                    }
                    break;
            case 3:
                    b = peek();
                    if(b != 0)
                    {
                        printf("Top element is: %d\n",b);
                        break;
                    }
                    break;
            case 4: traversal();
                    break;

            case 5: exit(0);
            default:
                    printf("Invalid Input...\n");
        }
    }
}

void push(int ele)
{
    if(is_Full())
    {
        printf("Stack is full \n");
    }
    else
    {
        stack[top] = ele;
        printf("Insertion Successful \n");
        printf("\n");
        top++;
    }
}

int pop()
{
    if (is_Empty())
    {
        printf("Stak is Empty No element in stack \n");
        return 0;
    }
    else
    {
        top--;
        int ele = stack[top];
        return ele;
    }
}

void traversal()
{
    if (is_Empty())
    {
        printf("No element is stack and its empty \n");

    }
    else
    {
        for(int i = 0; i < top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int peek()
{
    if (is_Empty())
    {
        printf("No element is stack and its empty \n");
        return 0;

    }
    else
    {
        return stack[top - 1];
    }
}

int is_Full()
{
    if(top == CAPACITY )
    {
        //stack is full
        return 1;
    }
    else
    {
        return 0;
    }

}

int is_Empty()
{
    if (top == 0)
    {
        return 1;
    }
    else
    {
        //stack is empty
        return 0;
    }

}