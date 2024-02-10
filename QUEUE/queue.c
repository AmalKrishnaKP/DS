#include<stdio.h>
#define max 5
#define invalid -99999
int f=-1,r=-1;
int queue[10],item;
void enqueue(int data)
{
        if(r==(max-1))
        {
                printf("queue over flow");
        }
        else
        {
                r++;
                queue[r]=data;
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
                return invalid;
        }
        else
        {
                item=queue[f];
                f++;
                if(f==r+1)
                {
                        f=r=-1;
                }
                return item;
        }

}
void display()
{
        int i;
        if(f==-1)
        {
                printf("under flow");
        }
        else
        {
                for(i=f;i<=r;i++)
                {
                        printf("%d \n",queue[i]);
                }
        }
}
void main()
{
        char choice;
        int num,n;
        do
        {
                printf("1.enqueue \n2.dequeue \n3.display \nenter urchoice");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:printf("enter the data");
                                scanf("%d",&num);
                                enqueue(num);
                         break;
                        case 2:dequeue();
                         break;
                        case 3:display();
                        break;
                }
                printf("DO U WNT TO RPT(t/n)");
                scanf(" %c",&choice);
        }
        while(choice=='y' || choice=='Y');
}
