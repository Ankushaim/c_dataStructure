#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//Protype
bool insert(int);

typedef struct node
{
    struct node *left;
    int n;
    struct node *right;
}
node;
node* root = NULL;


int main(void)
{
    int choice;
    while(1)
    {
        printf("1: Insert Element \n");
        printf("2: Add Element at begining \n");
        printf("3: Add Element at specific location \n");
        printf("4: Length of List \n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    printf("Give Value to insert: ");
                    int value;
                    scanf("%d", &value);
                    bool check;
                    check = insert(value);
                    if(check == true)
                    {
                        printf("Insertion Successfull \n");
                    }
                    else
                    {
                        printf("Value already available or Memory issue");
                    }
                    break;
            // case 2:
            //         addatbegning();
            //         break;
            // case 3:
            //         addafter();
            //         break;
            case 2:
                    exit(0);
                    break;
            default:
                    printf("Invalid Input enter again \n\n");
        }
    }
}

bool insert(int val)
{
    node *current = root;
    node *previous = NULL;
    while(current != NULL)
    {
        previous = current;
        if(current -> n > val)
        {
            current = current -> left;
        }
        else if (current -> n < val)
        {
            current = current -> right;
        }
        else
        {
            return false;
        }
    }
    // build new node
    node *temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        return false;
    }
    temp -> n = val;
    temp -> left = NULL;
    temp -> right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        // insert new node at insertion point
        if (previous -> n > val)
        {
            previous -> left = temp;
        }
        else
        {
            previous -> right = temp;
        }
    }
    // return true
    return true;
}