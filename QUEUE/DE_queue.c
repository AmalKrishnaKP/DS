#include<stdio.h>
#define size 5
#define invalied -9999
int f=-1,r=-1,item;
int queue[10];
void insert_f(int data)
{
        if(f==(r+1)%size)
        {
                printf("full \n");
        }
        else
        {       if(f==-1)
                {
                        f=r=0;
                }
                else
                {
                        f=(f-1+size)%size;
                }
                queue[f]=data;
        }

}
void insert_r(int data)
{
        if(f==((r+1)%size))
        {
                printf("full \n");
        }
        else
        {
                r=(r+1)%size;
                queue[r]=data;
                if(r==-1)
                {
                        r=0;
                }
        }
}
int delete_f()
{
        if(f==-1)
        {
                printf("empty \n");
                return invalied;
        }
        else
        {
                item=queue[f];
                f=(f+1)%size;
                if(f==((r+1)%size))
                {
                        f=r=-1;
                }
                return item;
        }
}
int delete_r()
{
        if(f==-1)
        {
                printf("empty \n");
                return invalied;
        }
        else
        {
                item=queue[r];
                r=(r-1+size)%size;
                if(f==((r+1)%size))
                {
                        f=r=-1;
                }
                return item;
        }
}
void main()
{
        char choice;
        int n,num;
        do
        {
                printf("1.insert_f\n2.insert_r\n3.delete_f\n4.delete_r\n choice\n");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:printf("enter num\n");
                                scanf("%d",&num);
                                insert_f(num);
                        break;
                        case 2:printf("enter num\n");
                                scanf("%d",&num);
                                insert_r(num);
                        break;
                        case 3:delete_f();
                        break;
                        case 4:delete_r();

                }
                printf("rpt?()y/n");
                scanf(" %c",&choice);
        }while(choice=='y' ||choice=='Y');
}
