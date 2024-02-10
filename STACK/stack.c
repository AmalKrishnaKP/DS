#include<stdio.h>
#define size 3
#define invalied -99999999
int top=-1;
int item,stack[20];
void push(int data)
{
        if(top==size-1)
        {
                printf("stack overflow");
        }
        else
        {
                top++;
                stack[top]=data;
        }
}
int pop()
{
        if(top==-1)
        {
                printf("stack under flow");
                return invalied;
        }
        else
        {
                item=stack[top];
                top--;
                return item;
        }
}
void display()
{
        int i;
        if(top==-1)
        {
                printf("no elements");
        }
        else
        {
                for(i=0;i<=top;i++)
                {
                        printf("%d \n",stack[i]);
                }
        }
}
void main()
{
        char choice='y';
        int n,b;
        while(choice=='y' || choice=='Y')
        {
                printf("1.push \n2.pop \n3.display \n enter choice \n ");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:printf("enter the number to be add \n");
                                scanf("%d",&b);
                                push(b);
                        break;
                        case 2:pop();
                        break;
                        case 3:display();
                        break;
                }
                printf("do you want to repeat(y/n) \n");
                scanf(" %c",&choice);
        }
}
