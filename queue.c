#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
        struct node *next;
        int data;
}queue;
queue *front = NULL;
queue *rear = NULL;

int enqueue()
{
        printf("\n---------------------\n");
        printf("--Add data to queue--\n");
        printf("---------------------");

        if(front == NULL)
        {
                front = (queue *)malloc(sizeof(queue));
                printf("\nPlease enter the data:\n");
                printf("=> ");
                scanf("%d", &front -> data);
                front -> next = NULL;
                rear = front;
                printf("\n");
        }
        else if (front != NULL)
        {
                queue * temp = (queue *)malloc(sizeof(queue));
                printf("\nPlease enter the data:\n");
                printf("=> ");
                scanf("%d", &temp -> data);
                rear -> next = temp;
                temp -> next = NULL;
                rear = temp;  
                printf("\n");
        }
        printf("=> (%d) added successfully! <=\n", rear -> data);
        return 0;
}

queue * dequeue(queue *rear, queue *front)
{
        printf("\n------------------------\n");
        printf("-Delete data from queue-\n");
        printf("------------------------\n");

        if(front == NULL)
                printf("The queue is EMPTY!!\n\n");

        else if(front -> next == NULL)
        {
                printf("=> (%d) deleted successfully! <=\n", front -> data);
                free(front);
                front = NULL;
                rear = front;
                return front;
        }
        else
        {
                queue * delete = front;
                front = front -> next;
                printf("=> (%d) deleted successfully! <=\n", delete -> data);
                free(delete); 
                return front;
        }
}

int listQueue(queue *front, queue *rear)
{
        queue * iter = front;
        printf("\n---------------------\n");
        printf("------The queue------\n");
        printf("---------------------\n");

        if(front == NULL)
        {
                printf("The queue is EMPTY!!\n\n");
        }
        else if (front != NULL)
        {
                printf("Front ==> %d", iter -> data);
                iter = iter -> next; 

                while(iter != NULL)
                {
                        printf("\n");
                        printf("========> %d", iter -> data);
                        iter = iter -> next;
                }

                printf(" <== Rear\n\n");                    
        }
        sleep(1);
        return 0;
}

void peek(queue *fr)
{
        
        if(front == NULL)
                printf("\nThe queue is EMPTY!!\n\n");
        else
                printf("\nFront data => %d\n", fr -> data);
}

int main(void)
{
        int choose;
        do
        {
                printf("\n1) Add data to the queue.\n");
                printf("2) Delete data from queue.\n");
                printf("3) List the queue.\n");
                printf("3) Show the front data.\n");
                printf("0) Exit.\n");

                printf("\nPlease choose one of them: (1) (2) (3) (0)\n");
                printf("=> ");
                scanf("%d", &choose);

                switch (choose)
                {
                        case 1: enqueue(); break;
                        case 2: front = dequeue(rear, front); break;
                        case 3: listQueue(front, rear); break;
                        case 4: peek(front); break;
                        case 0: printf("\nExting..."); break;
                        default: printf("\nPlease enter a valid number!!\n\n"); break;
                }
        } while (choose != 0);
        return 0;
}