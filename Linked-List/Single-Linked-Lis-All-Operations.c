#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start=NULL;
void create()
{
    struct node *temp,*ptr;
    int num;
    // printf("Enter -1 To stop :");
    printf("Enter Data :");
    scanf("%d",&num);
    while(num!=-1)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            ptr=start;
        }
        else{
            ptr->next=temp;
            ptr=temp;
        }
        printf("Enter Data :");
        scanf("%d",&num);
    }
}
void update_data()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    int num;
    printf("Enter Old Data:");
    int oldnum;
    scanf("%d",&oldnum);
    printf("Enter New Data :");
    scanf("%d",&num);
    struct node *temp=start;
    while(temp!=NULL)
    {
        if(temp->data==oldnum)
        {
            temp->data=num;
            printf("\n\tData Updated Successfully.\n");
            return;
        }
        temp=temp->next;
    }
    printf("\n\tOld Data NOt Found.\n");
}
void insert_beg()
{
    int num;
    printf("Enter Data To Insert At Begining :");
    scanf("%d",&num);
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else{
        temp->next=start;
        start=temp;
    }
    printf("\n\tData Successfully inserted at BEGINING.\n");
}
void insert_end()
{
    int num;
    printf("Enter Data To Insert At End :");
    scanf("%d",&num);
    struct node *temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else{
        struct node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("\n\tData Successfully inserted at ENDING.\n");
}
void insert_before()
{
    if(start==NULL)
    {
        printf("\n\tCase Unavailable.\n");
        return;
    }
    int num;
    printf("Enter Data Before Which Node Has To Inserted :");
    scanf("%d",&num);
    int data;
    printf("Enter Data :");
    scanf("%d",&data);
    struct node *temp,*preptr=NULL,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(start->data==num)
    {
        temp->next=start;
        start=temp;
    }
    else{
        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                preptr->next=temp;
                temp->next=ptr;
                printf("\n\tData Insert Successfully Before (%d)\n",num);
                return;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
        printf("\n\tSpecified Data Not Found.\n");
    }
}
void insert_after()
{
    if(start==NULL)
    {
        printf("\n\tCase Unavailable.\n");
        return;
    }
    int num;
    printf("Enter Data After Which Node Has To Inserted :");
    scanf("%d",&num);
    int data;
    printf("Enter Data :");
    scanf("%d",&data);
    struct node *temp,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr!=NULL)
    {
        if(ptr->data==num)
        {
            temp->next=ptr->next;
            ptr->next=temp;
            printf("\n\tData Insert Successfully After (%d)\n",num);
            return;
        }
        ptr=ptr->next;
    }
    printf("\n\tSpecified Data Not Found.\n");
}
void delete_beg()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    struct node *temp=start;
    int val=start->data;
    start=start->next;
    free(temp);
    printf("\n\tDeleted (start):%d\n",val);
}
void delete_end()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    struct node *temp=start;
    int val;
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }
    else{
        struct node *ptr=NULL;
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
    }
    printf("\n\tSuccessfully deleted End\n");
}
void delete_after()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    if(start->next==NULL)
    {
        printf("\n\tCase Unavailable.(Only One Node).\n");
        return;
    }
    struct node *current=start;
    int data;
    printf("Enter Data After Which Node Has To Be Inserted :");
    scanf("%d",&data);
    while(current!=NULL)
    {
        if(current->data==data)
        {
            printf("\n\tData Deleted Succesfully (%d).\n",current->next->data);
            current->next=current->next->next;
            return;
        }
        current=current->next;
    }
    printf("\n\tSpecified Data Not Found.\n");
}
void delete_before()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    if(start->next==NULL)
    {
        printf("\n\tCase Unavailable.(Only One Node).\n");
        return;
    }
    struct node *ptr=start,*preptr=NULL,*hope=NULL;
    int data;
    printf("Enter Data Before Which Node Has To Be Inserted :");
    scanf("%d",&data);
    if(start->data==data)
    {
        printf("\n\tNo Node Found To Delete.\n");
        return;
    }
    else if(start->next->data==data)
    {
        hope=start;
        start=start->next;
        free(hope);
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->data==data)
            {
                printf("\n\tData Deleted Succesfully (%d).\n",hope->data);
                preptr->next=ptr;
                return;
            }
            preptr=hope;
            hope=ptr;
            ptr=ptr->next;
        }
        printf("\n\tSpecified Data Not Found.\n");
    }
}
void display()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    printf("\n\t");
    struct node *temp=start;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void main()
{
    int option;
    while(1)
    {
        printf("\n++++++ Main Menu ++++++++\n");
        printf("1.Create List\n2.Updata data\n3.Insert Beg\n4.Insert End\n5.Insert Before\n6.Insert After\n7.Delete beg\n8.Delete ending\n9.Del after\n10.Del before\n11.Del Entire\n12.Exit\n");
        printf("===========================\nEnter option >");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                create();
                break;
            case 2:
                update_data();
                break;
            case 3:
                insert_beg();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_before();
                break;
            case 6:
                insert_after();
                break;
            case 7:
                delete_beg();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                delete_after();
                break;
            case 10:
                delete_before();
                break;
            case 11:
                free(start);
                start=NULL;
                break;
            case 12:
                printf("\n\tAdios Amigos\n");
                exit(1);
        }
        display();
    }
}
//AnonymoWinter
