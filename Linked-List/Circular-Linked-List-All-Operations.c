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
    printf("Enter -1 to stop:");
    printf("Enter data :");
    scanf("%d",&num);
    while(num!=-1)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=num;
        if(start==NULL)
        {
            start=temp;
            temp->next=start;
            ptr=start;  
        }
        else{
            ptr->next=temp;
            ptr=temp;
            temp->next=start;
        }
        printf("Enter data :");
        scanf("%d",&num);

    }
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
    while(temp->next!=start)
    {
        if(temp->data==olddata)
        {
            temp->data=newdata;
            printf("\n\tData Updated (%d) -> (%d)\n",olddata,newdata);
            return;
        }
        temp=temp->next;
    }
    if(temp->data==olddata)
    {
        temp->data=newdata;
        printf("\n\tData Updated (%d) -> (%d)\n",olddata,newdata);
        return;
    }
    printf("\n\tSpecified Data Not Found.\n");
}
void insert_beg()
{
    int num;
    printf("Enter Data To Insert At Begining :");
    scanf("%d",&num);
    struct node *temp,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if(start==NULL)
    {
        start=temp;
        temp->next=start;
    }
    else{
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }        
        temp->next=start;
        start=temp;
        ptr->next=start;
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
    if(start==NULL)
    {
        start=temp;
        temp->next=start;
    }
    else{
        struct node *ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=start;
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
    struct node *temp,*preptr=NULL,*current=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if(start->data==data)
    {
        while(current->next!=start)
        {
            current=current->next;
        }
        temp->next=start;
        start=temp;
        current->next=start;
    }
    else{
        while(current->next!=start)
        {
            if(current->data==data)
            {
                preptr->next=temp;
                temp->next=current;
                printf("\n\tNode Successfullu Inserted Before(%d)",data);
                return;
            }
            preptr=current;
            current=current->next;
        }
        if(current->data==data)
        {
            preptr->next=temp;
            temp->next=current;
            printf("\n\tNode Successfullu Inserted Before(%d)",data);
            return;
        }
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
    while(ptr->next!=start)
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
    if(ptr->data==num)
    {
        temp->next=ptr->next;
        ptr->next=temp;
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

    if(start->next==start)
    {
        free(start);
        start=NULL;
    }
    else{
        struct node *temp=start,*ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        start=start->next;
        ptr->next=start;
        free(temp);
    }
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
    if(start->next==start)
    {
        free(start);
        start=NULL;
    }
    else{
        struct node *ptr=NULL;
        while(temp->next!=start)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=start;
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
    if(start->next==start)
    {
        printf("\n\tCase Unavailable.(Only One Node).\n");
        return;
    }
    struct node *current=start;
    int data;
    printf("Enter Data After Which Node Has To Be Inserted :");
    scanf("%d",&data);
    while(current->next!=start)
    {
        if(current->data==data)
        {
            printf("\n\tData Deleted Succesfully (%d).\n",current->next->data);
            current->next=current->next->next;
            return;
        }
        current=current->next;
    }
    if(current->data==data)
    {
        struct node *temp=start;
        start=start->next;
        free(temp);
        current->next=start;
        return;
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
    if(start->next==start)
    {
        printf("\n\tCase Unavailable.(Only One Node).\n");
        return;
    }
    struct node *ptr=start,*preptr=NULL,*hope=NULL;
    int data;
    printf("Enter Data Before Which Node Has To Be Inserted :");
    scanf("%d",&data);
        while(ptr->next!=start)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
    if(start->data==data)
    {
        preptr->next=start;
        free(ptr);
        return;
    }
    else if(start->next->data==data)
    {
        hope=start;
        start=start->next;
        free(hope);
        ptr->next=start;
        return;
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=start)
        {
            if(temp->data==data)
            {
                printf("\n\tData Deleted Succesfully (%d).\n",hope->data);
                preptr->next=temp;
                return;
            }
            preptr=hope;
            hope=temp;
            temp=temp->next;
        }
        if(temp->data==data)
        {
            printf("\n\tData Deleted Succesfully (%d).\n",hope->data);
            preptr->next=temp;
            return;
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
    struct node *temp=start;
    printf("\n\t");
    while(temp->next!=start)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->START\n",temp->data);
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