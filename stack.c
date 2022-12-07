#include <stdio.h>
#include <stdlib.h>

struct node
{
        char data[20];
        struct node * next;
};
typedef struct node stack;

void listStack(stack *r)
{
        stack *iter = r;
        if(r == NULL)
                printf("The stack is EMPTY!!");
        
        while(iter != NULL)
        {
                if(iter == r)
                {
                        printf("Top data => %s\n", iter -> data);
                        iter = iter -> next;
                        if(iter == NULL)
                                break;
                }

                printf("==========> %s\n", iter -> data);
                iter = iter -> next;                           
        }      
        printf("\n");       
}

stack *push(stack *r)
{
        if (r == NULL)
        {
                r = (stack *)malloc(sizeof(stack));
                printf("please enter the top data: ");
                scanf(" %s", &r -> data);
                r -> next = NULL;
                return r;
        }
        else if (r != NULL)
        {
                stack *temp = (stack *)malloc(sizeof(stack));
                printf("please enter the top data: ");
                scanf(" %s", &temp -> data);
                temp -> next = r;
                return temp;
        }
}

stack *pop(stack *r)
{
        if(r == NULL)
        {
                printf("The stack is EMPTY!!\n");
                return r;
        }
        else if(r != NULL)
        {
                stack *iter = r;
                r = r -> next;
                printf("(%s) deleted\n", iter -> data);
                free(iter);
                return r;
        }
}

void peek(stack *r)
{
        if(r == NULL)
                printf("The stack is EMPTY!!\n");
        else
                printf("Top data => %s\n", r -> data);
}

int main(void)
{
        int choose;
        stack *top = NULL;
        stack *root = NULL;
        do
        {       
                printf("\n(1) Push data to stack\n");
                printf("(2) Pop data from stack\n");
                printf("(3) List the stack\n");
                printf("(4) Show the top data\n");
                printf("(0) Exit");
                printf("\nplease choose one of them: (1) (2) (3) (0)\n=> ");
                scanf(" %d", &choose);
                printf("\n");

                switch (choose)
                {
                        case 1: root = push(root); break;
                        case 2: root = pop(root); break;
                        case 3: listStack(root); break;
                        case 4: peek(root); break;
                        case 0: printf("Exting..."); break;
                        default: printf("please enter a valid number!!\n"); break;
                }

        } while (choose != 0);
        return 0;
}