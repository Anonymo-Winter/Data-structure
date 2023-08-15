#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*start=NULL,*tail=NULL;
void create()
{
    struct node *temp,*ptr;
    int num;
    printf("Enter Data:");
    scanf("%d",&num);
    while(num!=-1)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;
        temp->prev=NULL;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            ptr=start;
        }
        else
        {
            ptr->next=temp;
            temp->prev=ptr;
            ptr=temp;
        }
        printf("Enter Data:");
        scanf("%d",&num);
    }
    tail=ptr;
}
void update_data()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow.\n");
        return;
    }
    int newdata,olddata;
    printf("Enter Old Data :");
    scanf("%d",&olddata);
    printf("Enter New Data :");
    scanf("%d",&newdata);

    struct node *temp=start;
    while(temp!=NULL)
    {
        if(temp->data==olddata)
        {
            temp->data=newdata;
            printf("\n\tData Updated (%d) -> (%d)\n",olddata,newdata);
            return;
        }
        temp=temp->next;
    }
    printf("\n\tSpecified Data Not Found.\n");
}
void insert_beg()
{
    int num;
    printf("Enter Data To Insert At Begining :");
    scanf("%d",&num);
    struct node *temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
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
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return;
    }
    else{
        struct node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            return;
        }
        ptr->next=temp;
        temp->prev=ptr;
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
    int num,data;
    printf("Enter Data Before Which The Node Has To Be Inserted :");
    scanf("%d",&data);
    printf("Enter data :");
    scanf("%d",&num);
    struct node *temp,*p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;
    if(start->data==data)
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
        printf("\n\tNode Successfully Inserted Before(%d)",data);
        return;
    }
    else{
        while(p!=NULL)
        {
            if(p->data==data)
            {
                p->prev->next=temp;
                temp->prev=p->prev;
                temp->next=p;
                p->prev=temp;
                printf("\n\tNode Successfully Inserted Before(%d)",data);
                return;
            }
            p=p->next;
        }
    }
    printf("\n\tSpecified Data Not Found.\n");
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
    temp->prev=NULL;
    temp->next=NULL;
    while(ptr->next!=NULL)
    {
        if(ptr->data==num)
        {
            temp->prev=ptr;
            temp->next=ptr->next;
            ptr->next->prev=temp;
            ptr->next=temp;
            printf("\n\tData Insert Successfully After (%d)\n",num);
            return;
        }
        ptr=ptr->next;
    }
    if(ptr->data==num)
    {
        ptr->next=temp;
        temp->prev=ptr;
        printf("\n\tData Insert Successfully After (%d)\n",num);
        return;
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
    int val=start->data;
    struct node *ptr=start;
    start=start->next;
    free(ptr);
    printf("\n\tDeleted (start):%d\n",val);
}
void delete_end()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    if(start->next==NULL)
    {
        free(start);
        start=NULL;
        return;
    }
    struct node *temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }    
    temp->prev->next=NULL;
    free(temp);
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
    struct node *temp=start;
    int data;
    printf("Enter Data After Which Node Has To Be Deleted :");
    scanf("%d",&data); 
    if(tail->data==data)
    {
        printf("\n\tNo Node To Delete After\n");
        return;
    }
    else if(tail->prev->data==data){
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
        printf("\n\tData Deleted Succesfully");
        return;
    }
    else{
        temp=start;
        struct node *ptr;
        while(temp!=NULL)
        {
            if(temp->data==data)
            {
                ptr=temp->next;
                temp->next=ptr->next;
                ptr->next->prev=temp;
                free(ptr);
                printf("\n\tData Deleted Succesfully");
                return;
            }
            temp=temp->next;
        }
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
    struct node *ptr=start,*hope=NULL;
    int data;
    printf("Enter Data Before Which Node Has To Be Inserted :");
    scanf("%d",&data);
    if(start->data==data)
    {
        printf("\n\tNo Node To Delete Before\n");
        return;
    }
    else if(start->next->data==data)
    {
        printf("\n\tData Successfully Deleted:%d\n",start->data);
        hope=start;
        start=start->next;
        free(hope);
        return;
    }
    else{
        while(ptr!=NULL)
        {
            if(ptr->data==data)
            {
                hope=ptr->prev;
                printf("\n\tData Successfully Deleted:%d\n",hope->data);
                ptr->prev=hope->prev;
                hope->prev->next=ptr;
                free(hope);
                return;
            }
            ptr=ptr->next;
        }
    }
    printf("\n\tSpecified Data Not Found\n");
}
void display()
{
    if(start==NULL)
    {
        printf("\n\tUnderFlow\n");
        return;
    }
    struct node *temp=start;
    printf("\n\t");
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