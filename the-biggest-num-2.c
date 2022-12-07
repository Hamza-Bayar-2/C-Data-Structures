#include <stdio.h>
#include <math.h>

int main(void)
{
        int num1, num2, num3, num4, num5;

        printf("please enter 5 numbers:\n");
        printf("1 => ");
        scanf("%d", &num1);
        printf("2 => ");
        scanf("%d", &num2);
        printf("3 => ");
        scanf("%d", &num3);
        printf("4 => ");
        scanf("%d", &num4);
        printf("5 => ");
        scanf("%d", &num5);

        if (num1 >= num2)
        {
                if (num1 >= num3)
                {
                        if (num1 >= num4)
                        {
                                if (num1 >= num5)
                                printf("the biggest number is %d", num1);
                                else
                                printf("the biggest number is %d", num5);   
                        }
                        else if (num4 >= num5)
                        printf("the biggest number is %d", num4);
                        else
                        printf("the biggest number is %d", num5);     
                }
                else if (num3 >= num4)
                {
                        if (num3 >= num5)
                        printf("the biggest number is %d", num3);
                        else
                        printf("the biggest number is %d", num5);   
                }
                else if (num4 >= num5)
                printf("the biggest number is %d", num4);
                else
                printf("the biggest number is %d", num5); 
        }
        else if (num2 >= num3)
        {
                if (num2 >= num4)
                {
                        if (num2 >= num5)
                        printf("the biggest number is %d", num2);
                        else
                        printf("the biggest number is %d", num5); 
                }
                else if (num4 >= num5)
                printf("the biggest number is %d", num4);
                else
                printf("the biggest number is %d", num5);    
        }
        else if (num3 >= num4)
        {
                if (num3 >= num5)
                printf("the biggest number is %d", num3); 
                else
                printf("the biggest number is %d", num5);
        }
        else if (num4 >= num5)
        printf("the biggest number is %d", num4);
        else
        printf("the biggest number is %d", num5); 
        
        return 0;
}
