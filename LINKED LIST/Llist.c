#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
struct node*head= NULL;
void insert_begining(int data)
{
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=NULL;
        newnode->link=head;
        head=newnode;
}
void insert_end(int data)
{
        struct node*temp,*newnode;
        newnode=malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=NULL;
        if(head==NULL)
        {
                head=newnode;
        }
        else
        {
                temp=head;
                while(temp->link!=NULL)
                {
                        temp=temp->link;
                }
                temp->link=newnode;
        }
}
void insert_position(int data,int posi)
{
        struct node*temp,*newnode;
        newnode=malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=NULL;
        int p=2;
        temp=head;
        while(p<posi)
        {
                temp=temp->link;
                p++;
        }
        newnode->link=temp->link;
        temp->link=newnode;

}void delete_big()
{
        struct node*temp;
        temp=head;
        head=temp->link;
        free(temp);
}
void delete_end()
{
        struct node*temp,*prev;
        temp=head;
        while(temp->link!=NULL)
        {
                prev=temp;
                temp=temp->link;
        }
        prev->link=NULL;
        free(temp);
}
void delete_posi(int posi)
{
        int p=1;
        struct node *temp,*prev;
        temp=head;
        while(p<posi)
        {
                prev=temp;
                temp=temp->link;
                p++;
        }
        prev->link=temp->link;
        free(temp);
}
void main()
{
        insert_begining(5);
        insert_end(6);
        insert_position(7,2);
        delete_big();
}
