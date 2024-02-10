#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
struct node*head= NULL;
void push(int data)
{
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data=data;
        newnode->link=NULL;
        newnode->link=head;
        head=newnode;
}
void pop()
{
        struct node*temp;
        temp=head;
        head=temp->link;
        free(temp);
}
void display()
{
        if(head==NULL)
        {
                printf("empty");
        }
        else
        {
                struct node* temp;
                temp=head;
                while(temp!=NULL)
                {
                        printf("%d \n",temp->data);
                        temp=temp->link;
                }
        }
}
void main()
{
    int n,c;
    char ch;
    printf("1:Insert\n2:Delete\n3:Display\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the data to be inserted:");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice");
        }
        printf("Do you want to repeat(y/n)?");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
