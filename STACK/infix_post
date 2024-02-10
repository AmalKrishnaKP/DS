#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define invalied -99999
char stack[MAX],prefix[MAX],item;
int top=-1;
void push(char data)
{
        if(top==MAX-1)
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
char infix[MAX],postfix[MAX];
int precedence(char a)
{
        switch(a)
        {
                case '^':
                        return 3;
                case '*':
                case '/':
                        return 2;
                case '+':
                case '-':
                        return 1;
                default:
                        return 0;
        }
}
void main()
{
        printf("enter the infix ");
        scanf("%s",infix);
        in_post();
        printf("%s \n",postfix);
}
