#include<stdio.h>
#include<stdlib.h>
struct poly
{
        int coef;
        int expo;
        struct poly* link;
};
struct poly* ph,*qh,*rh;
struct poly* read()
{
        int n;
        struct poly*head=NULL;
        struct poly*temp;
        printf("Enter the no. of terms of the polynomial:");
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
                struct poly*node=malloc(sizeof(struct poly));
                printf("coef %d and expo %d",i,i);
                scanf("%d %d",&node->coef,&node->expo);
                if(head==NULL)
                {
                        head=node;
                        temp=head;
                }
                else
                {
                        temp->link=node;
                        temp=node;
                }

        }
        return head;
}
void display(struct poly* head)
{
        struct poly*temp;
        temp=head;
        while(temp->link!=NULL)
        {
                printf("%dX^%d +",temp->coef,temp->expo);
                temp=temp->link;
        }
        printf("%dX^%d",temp->coef,temp->expo);
}
struct poly* sum()
{
        struct poly*head;
        struct poly*node;
        struct poly*r;
        struct poly*p;
        struct poly*q;
        p=ph;
        q=qh;
        while(p!=NULL && q!=NULL)
        {
                node=malloc(sizeof(struct poly));
                if(p->expo==q->expo)
                {
                        node->expo=p->expo;
                        node->coef=p->coef+q->coef;
                        node->link=NULL;
                }
                else if(p->expo>q->expo)
                {
                        node->expo=p->expo;
                        node->coef=p->coef;
                        node->link=NULL;

                }
                else
                {
                        node->expo=q->expo;
                        node->coef=q->coef;
                        node->link=NULL;
                }
                if(head==NULL)
                {
                        head=node;
                        r=head;
                }
                else
                {
                        r->link=node;
                        r=node;
                }
        }
        while(p!=NULL)
        {
                node->expo=p->expo;
                node->coef=p->coef;
                node->link=NULL;
                if(head==NULL)
                {
                        head=node;
                        r=head;
                }
                else
                {
                        r->link=node;
                        r=node;
                }
        }
        while(q!=NULL)
        {
                node->expo=q->expo;
                        node->coef=q->coef;
                        node->link=NULL;
                if(head==NULL)
                {
                        head=node;
                        r=head;
                }
                else
                {
                        r->link=node;
                        r=node;
                }
        }
        return head;
}
void main()
{
        printf("enter the details of poly1");
        ph=read();
        printf("enter the details of poly2");
        qh=read();
        printf("\npoly1:");
        display(ph);
        printf("\npoly2:");
        display(qh);
        printf("\nsum:");
        rh=sum();
        display(rh);


}          
