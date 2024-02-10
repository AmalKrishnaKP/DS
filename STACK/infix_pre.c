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
void in_post()
{
        int i,j=0;
        char symbol,next;
        for(i=0;i<=(strlen(infix)-1);i++)
        {
                symbol=infix[i];
                switch(symbol)
                {
                        case '(':
                                push(symbol);
                        break;
                        case ')':while((next=pop())!='(')
                                {
                                        postfix[j++]=next;
                                }
                        break;
                        case '*':
                        case '^':
                        case '/':
                        case '+':
                        case '-':
                                while(precedence(symbol)<=precedence(stack[top]))
                                {
                                        postfix[j++]= pop();
                                }
                                push(symbol);
                        break;
                        default:
                                postfix[j++]=symbol;
                }
        }
        while(top!=-1)
        {
                postfix[j++]=pop();
        }
        postfix[j++]='\0';
}
void pree()
{
        int i=0;
        int k=0;
        for(i=0;i<strlen(postfix);i++)
        {
                push(postfix[i]);
        }
        while(top!=-1)
        {
                prefix[k++]=pop();
        }
}
void main()
{
        printf("enter the infix ");
        scanf("%s",infix);
        in_post();
        pree();
        printf("%s \n",postfix);
        printf("%s \n",prefix);
}
