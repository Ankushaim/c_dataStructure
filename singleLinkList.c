#include <stdio.h>
#include <stdlib.h>

//prototypes
void append(void);
int length(void);
void display();
void addatbegning();
void addafter(void);
void delete_node(void);

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *root = NULL;
int len;

int main(void)
{
    int choice;
    while(1)
    {
        printf("1: Append Element \n");
        printf("2: Add Element at begining \n");
        printf("3: Add Element at specific location \n");
        printf("4: Length of List \n");
        printf("5: Display \n");
        printf("6: Delete Element \n");
        printf("7: Quit the program \n\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    append();
                    break;
            case 2:
                    addatbegning();
                    break;
            case 3:
                    addafter();
                    break;
            case 4:
                    len = length();
                    printf("Lenght of List is: %d \n\n", len);
                    break;
            case 5:
                    display();
                    break;
            case 6:
                    delete_node();
                    break;
            case 7:
                    exit(0);
                    break;
            default:
                    printf("Invalid Input enter again \n\n");
        }
    }
}


void append(void)
{
    node *temp;
    int value;

    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        fprintf(stderr, "Not enough Memory \n");
        //return 1;
    }
    printf("Give me the value: ");
    scanf("%d",&value);
    temp-> number = value;
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *check;
        check = root;
        while (check->next != NULL)
        {
            check = check-> next;
        }
        check-> next = temp;
    }
}

int length()
{
    int counter = 0;
    node *temp;
    temp = root;
    while(temp != NULL)
    {
        temp = temp -> next;
        counter++;
    }
    return counter;
}

void display()
{
    node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List is Empty please insert some elements...");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp-> number);
            temp = temp -> next;
        }
        printf("\n\n");
    }
}


void addatbegning()
{
    int value;
    node *temp;
    temp = root;
    temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        fprintf(stderr, "Not enough Memory \n");
        //return 1;
    }
    printf("Give me the value: ");
    scanf("%d",&value);
    temp-> number = value;
    temp->next = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
}


void delete_node(void)
{
    node *temp;
    printf("Give the Node number which you want to remove: ");
    int n;
    scanf("%d", &n);
    printf("\n");
    if (root == NULL || n == 0 || n > length())
    {
        printf("No element in List or Provide valid node number..\n");
    }
    else
    {
        if (n == 1)
        {
            temp = root;
            root = temp -> next;
            temp -> next = NULL;
            free(temp);
        }
        else
        {
            node *p;
            p = root;
            temp = root;
            int i = 1;
            while (i < (n - 1))
            {
                temp = temp -> next;
                i++;
            }
            p = temp ->next;
            temp -> next = p -> next;
            p -> next = NULL;
            free(p);
        }
    }
}


void addafter(void)
{
    node *temp, *p;
    temp = root;
    int n;
    printf("Give me value: ");
    scanf("%d", &n);
    int l = length();

    if ( n > l || n < 1)
    {
        printf("Please provide valid node > 0 or <= %d \n", l);
    }
    else
    {
        int i = 1;
        while (i < n)
        {
            temp = temp -> next;
            i++;
        }
        p = (node*) malloc(sizeof(node));
        int value;
        printf("Give me data: ");
        scanf("%d", &value);
        p -> number = value;
        p -> next = NULL;

        p -> next = temp -> next;
        temp -> next = p;
    }
}