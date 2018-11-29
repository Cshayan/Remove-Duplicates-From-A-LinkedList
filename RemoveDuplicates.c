//Programme to delete the duplicate elements from a linked list
#include<stdio.h>
#include<conio.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
//create function to create the linked list
void create(struct node **start1,int num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if((*start1)==NULL)
    {
        (*start1)=temp;
    }
    else
    {
        curr=(*start1);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
//display function to print the list
void display(struct node *start1)
{
  printf("\nList is:- \n");
    struct node *curr=start1;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n\n\n");
}
void removeDuplicates(struct node *start)
{
    struct node *curr,*next_next;
    curr=start;

    if(curr==NULL) return;

    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            next_next=curr->next->next;
            free(curr->next);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    printf("\nAfter removing the duplicates, ");
    display(start);
}
int main()
{
     struct node *start=NULL;
    int n,num;
    printf("Enter the no of nodes to be created:- ");
    scanf("%d",&n);
    int i;
    printf("\nEnter the elements:- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        create(&start,num);
    }
    display(start);
    removeDuplicates(start);
}
