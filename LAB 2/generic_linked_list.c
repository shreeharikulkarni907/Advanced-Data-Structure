#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    void *data;
    struct node *next;
};
void push(struct node **head,void *data,size_t data_size)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data=malloc(data_size); //returns pointer to the block of memory
    new_node->next=(*head);

    int i;
    for(i=0;i<data_size;i++)
    {
        *(char *)(new_node->data + i)=*(char *)(data + i); //assuming char is one byte
    }
    (*head)=new_node;
}
void printlist(struct node **head,void(*fptr)(void *))
{
    struct node *last=*head;
    while(last!=NULL)
    {
        (*fptr)(last->data);
        last=last->next;
    }
}
void printInt(void *n)
{
    printf("%d\t",*(int *)n);
}
void printFloat(void *n)
{
    printf("%f\t",*(float *)n);
}
int main()
{
    int n;
    struct node *head=NULL;
    printf("Enter the number of elements of the Integer array\n");
    scanf("%d",&n);
    int int_arr[n];
    //float float_arr[n];
    printf("Enter the integer elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&int_arr[i]);
    }
    printf("Enter the number of elements of the float array\n");
    scanf("%d",&n);
    float float_arr[n];
    printf("Enter the floating point elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&float_arr[i]);
    }
    unsigned int_size=sizeof(int);
    unsigned float_size=sizeof(float);

    for(int i=n-1;i>=0;i--)
    {
        push(&head,&int_arr[i],int_size);
    }
    printf("Created list is\n");
    printlist(&head,printInt);
    printf("\n");

    for(int i=n-1;i>=0;i--)
    {
        push(&head,&float_arr[i],float_size);
    }
    printf("Created list is \n");
    printlist(&head,printFloat);
}
