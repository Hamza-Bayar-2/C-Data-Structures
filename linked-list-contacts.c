#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n
{
        struct n * next;
        char phone_num[30];
        char name[30];
        char surname[30];
        char email[30];

};
typedef struct n node;

node * CreateContact (node *r)
{
        printf("\n==> Please write the name with SMALL letters \nand use only english characters <==\n\n");
        if (r == NULL)
        {
                r = (node *)malloc(sizeof(node));

                printf("Name: ");
                scanf(" %s", &r -> name);

                printf("Surname: ");
                scanf(" %s", &r -> surname);
                printf("Phone number: ");

                scanf(" %s", &r -> phone_num);

                printf("Email: ");
                scanf(" %s", &r -> email);

                r -> next = NULL;
                return r;
        }

        node * temp = (node *)malloc(sizeof(node));        

        printf("Name: ");
        scanf(" %s", &temp -> name);

        printf("Surname: ");
        scanf(" %s", &temp -> surname);

        printf("Phone number: ");
        scanf(" %s", &temp -> phone_num);

        printf("Email: ");
        scanf(" %s", &temp -> email);


        if (strncmp(r -> name, temp -> name, 4) > 0)
        {
                temp -> next = r;
                return temp;
        }
        
        node * iter = r;

        while (iter -> next != NULL && strncmp(temp -> name, iter -> next -> name, 4) > 0)
                iter = iter -> next;

        if (iter -> next == NULL)
        {
                iter -> next = temp;
                temp -> next = NULL;
                return r;
        }

        temp -> next = iter -> next;
        iter -> next = temp;

        return r;
}

void ListContact (node * r)
{
        node * iter = r;
        int i = 1;
        if (r == NULL)
                printf("\nThe contact list is EMPTY!");

        printf("\n");

        while (iter != NULL)
        {
                printf("--> %d <--\n", i);
                printf("Name: %s\n", iter -> name);
                printf("Surname: %s\n", iter -> surname);
                printf("Phon Number: %s\n", iter -> phone_num);
                printf("Email: %s\n\n", iter -> email);
                iter = iter -> next;
                i++;
        }
        
}

node * SearchContact (node *r)
{
        if (r == NULL)
        {
                printf("\nThe contact list is EMPTY!");
                return r;
        }

        printf("\n");

        node * temp = (node *)malloc(sizeof(node));
        node * iter = r;
        printf("Please enter the contact's name and surname\n");
        printf("Name: ");
        scanf(" %s", &temp -> name);
        
        printf("Surname: ");
        scanf(" %s", &temp -> surname);
        
        if (iter -> next == NULL || (strcmp(temp -> name, iter -> name) == 0 && strcmp(temp -> surname, iter -> surname) == 0))
        {
                if (strcmp(temp -> name, iter -> name) == 0 && strcmp(temp -> surname, iter -> surname) == 0)
                {
                        printf("\n==> The contact found <==\n");
                        printf("Name: %s\n", iter -> name);
                        printf("Surname: %s\n", iter -> surname);
                        printf("Phon Number: %s\n", iter -> phone_num);
                        printf("Email: %s\n\n", iter -> email);
                        return r;
                }
                else
                {
                        printf("\n==> The contact not found!! <==");
                        return r;
                }
        }

        while (strcmp(temp -> name, iter -> next -> name) != 0 || strcmp(temp -> surname, iter -> next -> surname) != 0)
        {
                iter = iter -> next;
                if (iter -> next == NULL)
                {
                        printf("\n==> The contact not found!! <==");
                        return r;
                }
        }

        printf("\n==> The contact found <==\n");
        printf("Name: %s\n", iter -> next-> name);
        printf("Surname: %s\n", iter -> next -> surname);
        printf("Phon Number: %s\n", iter -> next -> phone_num);
        printf("Email: %s\n\n", iter -> next -> email);
        return r;
}

node * DeleteContact (node * r)
{
        if (r == NULL)
        {
                printf("\nThe contact list is EMPTY!");
                return r;
        }

        printf("\n");

        node * temp = (node *)malloc(sizeof(node));
        node * iter = r;
        printf("Please enter the contact's name and surname\n");
        printf("Name: ");
        scanf(" %s", &temp -> name);

        printf("Surname: ");
        scanf(" %s", &temp -> surname);

        if (r -> next == NULL || (strcmp(temp -> name, r -> name) == 0 && strcmp(temp -> surname, r -> surname) == 0))
        {
                if (strcmp(temp -> name, r -> name) == 0 && strcmp(temp -> surname, r -> surname) == 0)
                {
                        printf("\n==> The contact deleted <==\n");
                        printf("Name: %s\n", r -> name);
                        printf("Surname: %s\n", r -> surname);
                        printf("Phon Number: %s\n", r -> phone_num);
                        printf("Email: %s\n\n", r -> email);

                        if (r -> next == NULL)
                        {
                                free(r);
                                r = NULL;

                                int j = 0;
                                node * left = r;
                                while (left != NULL)
                                {
                                        left = left -> next;
                                        j++;
                                }
                                printf("%d contact left", j);
                                return r;   
                        }

                        node * temp2 = r -> next;
                        free(r);
                        r = temp2;

                        int j = 0;
                        node * left = r;
                        while (left != NULL)
                        {
                                left = left -> next;
                                j++;
                        }
                        printf("%d contact left", j);
                        return r;
                }
                else
                {
                        printf("\n==> The contact not found!! <==");
                        return r;
                }

        }

        while (strcmp(temp -> name, iter -> next -> name) != 0 || strcmp(temp -> surname, iter -> next -> surname) != 0)
        {
                iter = iter -> next;
                if (iter -> next == NULL)
                        break;
        }

        if (iter -> next == NULL)
        {
                printf("\n==> The contact not found!! <==");
                return r;
        }
                

        printf("\n==> The contact deleted <==\n");
        printf("Name: %s\n", iter -> next -> name);
        printf("Surname: %s\n", iter -> next -> surname);
        printf("Phon Number: %s\n", iter -> next -> phone_num);
        printf("Email: %s\n\n", iter -> next -> email);
        
        node * iterdlt = iter -> next;
        iter -> next = iter -> next -> next;
        free(iterdlt);

        int j = 0;
        node * left = r;
        while (left != NULL)
        {
                left = left -> next;
                j++;
        }
        printf("%d contact left", j);
        return r;
}

int main(void)
{
        node * root;
        root = NULL;
        int choose;

        do{
                printf("\n\n--------------------");
                printf("\n------->MENU<-------\n");
                printf("--------------------\n");
                printf("1.Create new Contact\n");
                printf("2.List contact\n");
                printf("3.Search contact\n");
                printf("4.Delete contact\n");
                printf("0.Exit\n");
                printf("\nchoose one of them (1) (2) (3) (4) \n==> ");
                scanf("%d", &choose);

                switch (choose)
                {
                case 1: root = CreateContact (root); break;
                case 2: ListContact (root); break;
                case 3: root = SearchContact (root); break;
                case 4: root = DeleteContact(root); break;      
                case 0: printf("\nExiting..."); break;          
                default: printf("\nPlease enter a valid number!!\n\n"); break;
                }
        }while (choose != 0);
        
        return 0;
}