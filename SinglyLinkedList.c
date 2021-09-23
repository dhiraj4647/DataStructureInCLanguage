/*
Name of Program: Singly Linked List
Email: dhiraj.21920116@viit.ac.in
Coder: Dhiraj Subhash Gardi
*/
//header section
#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int ,struct Node*);
void display(struct Node *);
struct Node* addFirst(int, struct Node*);
int length(struct Node*node);
struct Node* append(int , struct Node*);
struct Node* addAfter(int , int , struct Node* );
struct Node* deleteFirst(struct Node*);
struct Node* deleteAfter(int , struct Node*);
void sort(struct Node* );
struct Node* swap(int , int ,struct Node* );
struct Node* search(int , struct Node *);
void reversePrint(struct Node *);


struct Node{
int data;
int *next;};


struct Node *root=NULL;
void main()
{
    int ch,data,loc1,loc2,loc;
    while(1)
    {
      puts("1.createnode");
      puts("2.display");
      puts("3.addfirst");
      puts("4.length");
      puts("5.append");
      puts("6.addafter");
      puts("7.deletefirst");
      puts("8.deleteafter");
      puts("9.sort");
      puts("10.swap");
      puts("11.search");
      puts("12.reverse_print");

      puts("13.exit");

      printf("enter the choice\t");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
         printf("Enter the data to be added:\t");
         scanf("%d",&data);
         root=createNode(data,root);
         break;

        case 2:
        display(root);
        break;

        case 3:
        printf("Enter the data to be added:\t");
        scanf("%d",&data);
        root=addFirst(data,root);
        break;

        case 4:
        printf("length=%d\n",length(root));
        break;

        case 5:
        printf("Enter the data to be added:\t");
        scanf("%d",&data);
        root=append(data,root);
        break;

        case 6:
        printf("Enter the data to be added and at which location:\t");
        scanf("%d %d",&data,&loc);
        root=addAfter(data,loc,root);
        break;

        case 7:
        root=deleteFirst(root);
        break;

        case 8:
        printf("enter the location to be deleted");
        scanf("%d",&loc);
        root=deleteAfter(loc,root);
        break;

        case 9:
        sort(root);
        break;

        case 10:
        printf("enter the locations to be swapped");
        scanf("%d%d",&loc1,&loc2);
        root=swap(loc1,loc2,root);
        break;

        case 11:
        printf("Enter the data to be added:\t");
        scanf("%d",&data);
        root=search(data,root);
        break;

        case 12:
        reversePrint(root);
        break;

        case 13:exit(0);

        default: puts("Invalid choice");
     }
    }
}
struct Node* createNode(int data,struct Node* node)
{
   struct Node *temp,*p=node;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=data;
   temp->next=NULL;
   if(node==NULL)
   {
      node=temp;

   }
   else
   {

       while(p->next)
       {
            p=p->next;
       }
       p->next=temp;
    }
    return node;
}

void display(struct Node *node)
{
    struct Node *temp=node;
    if(node==NULL)
    {
      printf("List is empty\n");
    }
    else
    {
        while(temp)
        {
           printf("%d\t",temp->data);
           temp=temp->next;
        }
        puts("");
    }
}

struct Node* addFirst(int data,struct Node*node)
{
   struct Node *temp;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=data;
   temp->next=NULL;
   temp->next=node;
   node=temp;
   return node;
}

int length(struct Node*node)
{
   int z=0;
   struct Node *p=node;
   while(p)
   {
      p=p->next;
      z++;
   }
   return z;
}

struct Node* append(int data, struct Node*node)
{
   struct Node *temp,*p=node;
   temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=data;
   temp->next=NULL;
   if(node==NULL)
   {
      node=temp;
   }
   else
   {

      while(p->next)
      {
            p=p->next;
      }
      p->next=temp;
    }
    return node;
}

struct Node* addAfter(int data, int loc, struct Node* node)
{
    struct Node *p=node,*q;
    struct Node *temp;

    if(loc>length(node))
    {
       printf("Invalid location\n");
    }
    else
    {

      temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=data;
      temp->next=NULL;
      while(loc>1)
      {
            p=p->next;
            loc--;
      }
      if(p->next)
      {
        q=p->next;
        temp->next=q;
      }
      p->next=temp;
    }
    return node;
}

struct Node* deleteFirst(struct Node* node)
{
   struct Node *temp=node;

   if(node==NULL)
   {
      printf("List is empty\n");
   }
   else
   {
      printf("Deleted element is :%d\n",node->data);

      node=node->next;
      temp->next=NULL;
      free(temp);
    }
    return node;
}

struct Node* deleteAfter(int loc, struct Node*node)
{
    struct Node *p=node,*q;
    if(loc==0||loc>=length(node))
    {
      printf("Invalid location\n");
    }
    else
    {

      while(loc>1)
      {
           p=p->next;
           loc--;
      }
      q=p->next;
      printf("deleted data is %d\n",q->data);
      p->next=q->next;
      q->next=NULL;
      free(q);
    }
    return node;
}

void sort(struct Node* node)
{
    if(node==NULL)
    {
        printf("list is empty\n");
    }
    else
    {

        int i,j,temp;
        int c=length(node);
        struct Node *p=node,*q;
        for(i=1;i<=c-1;i++)
        {

            q=p->next;
            for(j=1;j<=c-i;j++)
            {
                if(p->data > q->data)
                {
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                q=q->next;
            }
            p=p->next;
        }
        printf("data sorted\n");

    }
}

struct Node* swap(int loc1, int loc2,struct Node* node)
{

    int temp;
    struct Node *p=node,*q=node;
    if(loc1==0||loc2==0||loc1>length(node)||loc2>length(node))
    {
      printf("Invalid locations\n");
    }
    else
    {

      while(loc1>1)
      {
            p=p->next;
            loc1--;
      }
      while(loc2>1)
      {
            q=q->next;
            loc2--;
      }
      temp=p->data;
      p->data=q->data;
      q->data=temp;
    }
    return node;
}

struct Node* search(int data, struct Node *node)
{

   struct Node *p=node;
   if(node==NULL)
   {
      printf("List is empty\n");
   }

   int found=1,c=1;
   while(p)
   {

       if(p->data ==data)
       {
            found=0;
            printf("data found at loc %d\n",c);
       }
       p=p->next;
       c++;
    }
    if(found==1)printf("data not found\n");
    return node;
}

void reversePrint(struct Node *node)
{
    if(node!=NULL)
    {
        reversePrint(node->next);
        printf("%d\t",node->data);
    }
    

}




