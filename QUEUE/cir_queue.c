#include<stdio.h>
#define invalied -9999
#define size 5
int f=-1,r=-1;
int cqueue[10];
int item;
void enqueue(int data)
{
        if(f==((r+1)%size))
        {
                printf("queue over flow");
        }
        else
        {
                r=(r+1)%size;
                cqueue[r]=data;

                if(f==-1)
                {
                        f=0;
                }
        }
}
int dequeue()
{
        if(f==-1)
        {
                printf("queue under flow");
                return invalied;
        }
        else
        {
                item=cqueue[f];
                f=(f+1)%size;
                if(f==((r+1)%size))
                {
                        f=r=-1;
                }
        }
}
void display()
{
        int i;
        if(f==-1)
        {
                printf("empty");
        }
        else
        {
                for(i=f;i<=r;i++)
                {
                        printf("%d",cqueue[i]);
                }
        }
}
void main()
{
        char choice='Y';
        int n,num;
        do
        {
                printf("1.enqueue\n2.dequeue\n3.dislay\nchoice\n");
                scanf("%d",&n);
                        switch(n)
                        {
                                case 1:printf("enter the data\n");
                                        scanf("%d",&num);
                                        enqueue(num);
                                break;
                                case 2:dequeue();
                                break;
                                case 3:display();
                                break;
                        }
                printf("repeat(y/n)");
                scanf(" %c",&choice);
        }
        while(choice=='Y' || choice=='y');
}
