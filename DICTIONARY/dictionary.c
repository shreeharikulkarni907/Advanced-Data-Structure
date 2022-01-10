#include<stdio.h>
#include<stdlib.h>

#define max 10
typedef struct list
{
    int data;
    struct list *next;
}node;

node *ptr[max];
node *root[max];
node *temp[max];


void insert(int key)
{
    int index=(int)(key%max);

    ptr[index]=(node*)malloc(sizeof(node));
    ptr[index]->data=key;

    if(root[index]==NULL)
    {
       root[index]=ptr[index];
       root[index]->next=NULL;
       temp[index]=ptr[index];
    }
    else
    {
       temp[index]=root[index];
       while(temp[index]->next!=NULL)
       {
           temp[index]=temp[index]->next;
       }
       temp[index]->next=ptr[index];
    }
}

void search(int key)
{
    int flag=0;
    int index=(int)(key%max);

    temp[index]=root[index];

    while(temp[index]!=NULL)
    {
       if(temp[index]->data==key)
       {
          printf("Search Found\n");
          flag=1;
          break;
       }
        temp[index]=temp[index]->next;

    }
    if(flag==0)
    {
       printf("KEY CANNOT BE FOUND\n");
    }

}

void delete_val(int key)
{
    int index=(int)(key%max);

    temp[index]=root[index];
    while(temp[index]->data!=key && temp[index]!=NULL)
    {
        ptr[index]=temp[index];
        temp[index]=temp[index]->next;
    }
    ptr[index]->next=temp[index]->next;
    printf("VALUE DELETED IS %d ",temp[index]->data);
    free(temp[index]);
}

int main()
{
   int choice;
   int data;
   do
   {
       printf("1:INSERT\n");
       printf("2:SEARCH\n");
       printf("3:DELETE\n");
       printf("4:EXIT\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           printf("Enter the data you want to insert\n");
           scanf("%d",&data);
           insert(data);
           break;

           case 2:
           printf("Enter the data you want to search\n");
           scanf("%d",&data);
           search(data);
           break;

           case 3:
           printf("Enter the data you want to delete\n");
           scanf("%d",&data);
           delete_val(data);
           break;


       }

   }while(choice!=4);

}
