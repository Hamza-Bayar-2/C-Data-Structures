#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
        struct node * next;
        int page;
}queue;
queue *front = NULL;
queue *rear = NULL;

queue * printPages()
{

        int num;
        printf("\nHow many pages would you print?\n=>");
        scanf("%d", &num);
        
        // adding page to the queue
        if (num == 0)
        {
                printf("\nThere are no pages to print!\n");
                return front;
        }
        else if(num > 0)
        {
                front = (queue *)malloc(sizeof(queue));
                front -> next = NULL;
                rear = front;
                front -> page = 1;

                for(int i = 2; i < num + 1; i++)
                {
                        queue *temp = (queue *)malloc(sizeof(queue));
                        rear -> next = temp;
                        temp -> next = NULL;
                        rear = temp;
                }
        }
        else if(num < 0)
        {
                printf("\nPlease enter a valid number!!\n");
                return front;
        }

        //remove the pages from the queue
        printf("\nThe printer is preparing\n");
        sleep(1.5);
        printf("\n===> The printer started printing <===\n\n");

        if(front -> next == NULL)
        {
                sleep(1);
                printf("(1) page printed\n");
                free(front);
                front = NULL;
                rear = front;
                sleep(1);
                return front;
        }
        else
        {
                queue * printedPage = front;
                for (int i = 1; i < num + 1; i++)
                {
                        sleep(1);
                        printedPage = front;
                        printf("(%d) page printed\n", i);
                        front = front -> next;
                        free(printedPage);

                        if(front -> next == NULL)
                        {
                                sleep(1);
                                printf("(%d) page printed\n", ++i);
                                free(front);
                                front = NULL;
                                rear = front;
                                sleep(1);
                                return front;
                        }
                }
        }        
}

int main(void)
{
        int choose;
        do
        {
                printf("\n===================");
                printf("\n1) Print pages.\n");
                printf("0) Exit.\n");

                printf("\nPlease choose one of them: (1) (0)\n");
                printf("=> ");
                scanf("%d", &choose);

                switch (choose)
                {
                        case 1: front = printPages(); break;
                        case 0: printf("\nExting..."); break;
                        default: printf("\nPlease enter a valid number!!\n\n"); break;
                }
        } while (choose != 0);
        return 0;
}
