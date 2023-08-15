#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *create(struct node *start);
struct node *reverse(struct node *x);

int count(struct node *start);

void search(struct node *start); 
void display(struct node *start);
void merge(struct node *start); 
void sort(struct node *start); 
void zig_zag_display(struct node *start);
void zig_zag_merge(struct node *start);

char* list_to_string(struct node *start);
int* list_to_array(struct node *start);
void pallondrome(struct node *start);
void main()
{
    int option;
    char *str;int *arr;
    struct node *start=NULL; 
    printf("-------->Create Single Linked List :\n");
    start=create(start);
    display(start);
    while(option!=-1)
    {
        printf("\n\t++-++-++ Main Menu ++-++-++ \n");
        printf("------->>Choose Operation:\n0.Display\n1.Count.\n2.Search.\n3.List->String.\n4.List->array.\n");
        printf("5.Merge\n6.Pallindrome\n7.Sort.\n8.Reverse.\n9.Zig Zag Display.\n10.Zig Zag Merge.\n");
        printf("==================================\n");
        printf("Enter Your Choice ? ");
        scanf("%d",&option);
        switch(option)
        {
            case 0:
                display(start);
                break;
            case 1:
                printf("\n\t\tno. of nodes :%d\n",count(start));
                break;
            case 2:
                search(start);
                break;
            case 3:
                str=NULL;
                str=list_to_string(start);
                            for(int i=0;i<count(start);i++)
                            {
                                printf("%d ",str[i]);
                            }
                            printf("\n");
                break;
            case 4:
            arr=NULL;
                arr=list_to_array(start);
                            for(int i=0;i<count(start);i++)
                            {
                                printf("%d ",arr[i]);
                            }
                            printf("\n");
                break;
            case 5:
                merge(start);
                break;
            case 6:
                pallondrome(start);
                break;
            case 7:
                sort(start);
                break;
            case 8:
                start=reverse(start);
                display(start);
                break;
            case 9:
                zig_zag_display(start);
                break;
            case 10:
                zig_zag_merge(start);
                break;
        }
    }
}
struct node *reverse(struct node *x)
{
    struct node *preptr=NULL,*ptr,*nextptr=NULL;
    ptr=x;
    while(ptr!=NULL)
    {
        nextptr=ptr->next;
        ptr->next=preptr;
        preptr=ptr;
        ptr=nextptr;
    }
    x=preptr;
    return x;
}

int count(struct node *start)
{
    int cnt=0;
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        cnt++;
        ptr=ptr->next;
    }
    return cnt;
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    printf("\n\t");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
struct node *create(struct node *x)
{
    struct node *new,*ptr;
    char s;
    do{
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data :");
        scanf("%d",&new->data);
        new->next=NULL;
        if(x==NULL)
        {
            x=new;
            ptr=new;
        }
        else
        {
            ptr->next=new;
            ptr=new;
        }
        printf("Do You Want Create Another[Y/N] :");
        fflush(stdin);
        scanf("%c",&s);
    }while(s!='n');
    return x;
}
void merge(struct node *start)
{
    struct node *start1=NULL,*ptr;
    start1=create(start1);
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=start1;
    printf("After Merging :");
    display(start);
}
void search(struct node *start)
{
    struct node *ptr;
    int data,cnt=0;
    printf("Enter Data to Search :");
    scanf("%d",&data);
    ptr=start;  
    while(ptr!=NULL)
    {
        cnt++;
        if(ptr->data==data)
        {
            printf("\tData(%d) Is Found At Position(%d)",data,cnt);
            break;
        }
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("\tData(%d) Not Found",data);
    }
}
void sort(struct node *start)
{
    int num;
    struct node *temp,*min,*ptr;
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else{
        temp=start;
        while(temp->next!=NULL)
        {
            min=temp;
            ptr=temp->next;
            while(ptr!=NULL)
            {
                if(ptr->data < min->data)
                {
                    min=ptr;
                }
                ptr=ptr->next;
            }
            if(temp!=min)
            {
                num=temp->data;
                temp->data=min->data;
                min->data=num;
            }
            temp=temp->next;
        }
    }
}

void zig_zag_display(struct node *start)
{
    int m,n,c=0,i,j,temp;
    struct node *ptr=start,*qtr,*ztr;
    printf("\nEnter M and N:");
    scanf("%d %d",&m,&n);
    temp=n;
    while(ptr!=NULL)
    {
        if(c==m)
        {
            c=0;
            while(temp!=0)
            {
                if(ztr==NULL && ptr==NULL)
                {
                    qtr->next=NULL;
                }
                else if(ptr->next==NULL)
                {
                    ztr->next=NULL;
                }
                else{
                ztr->next=ptr->next;
                qtr=ptr;
                ptr=ptr->next;
                free(qtr);
                }
                temp--;
            }
            temp=n;
        }
        printf("%d ",ptr->data);
        ztr=ptr;
        ptr=ptr->next;
        c++;
    }
}
char *list_to_string(struct node *start)
{
    struct node *temp;
    int cnt=0,i=0;
    cnt=count(start);
    char *str=(char *)malloc(cnt+1);
    temp=start;
    while(temp!=NULL)
    {
        str[i]=temp->data;
        i++;
        temp=temp->next;
    }
    str[i]='\0';
    return str;
}
int* list_to_array(struct node *start)
{
    struct node *temp=start;
    int cnt=count(start);
    int i=0;
    int *arr=(int *)malloc(cnt+1);
    while(temp!=NULL)
    {   
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }
    return arr;
}
void pallondrome(struct node *x)
{
    struct node *temp;
    temp=x;
    int *arr=NULL;
    arr=list_to_array(x);
    int i=0,flag=1;
    while(temp!=NULL)
    {
        if(temp->data!=arr[i])
        {
            int flag=0;
            break;
        }
        temp=temp->next;
        i++;
    }
    if(flag)
    {
        printf("pallondrome ");
    }
    else{
        printf("not a pallondrome ");
    }

}

void zig_zag_merge(struct node *start)
{
    char confirmation;
    struct node *tempstart=NULL;
    printf("----------->Create Another List to Continue\n:");
    tempstart=create(tempstart);
    printf("\n");
    display(start);
    struct node *preptr,*qreqtr,*ptr,*qtr;
    ptr=start;
    qtr=tempstart;
    while(preptr!=NULL || qreqtr!=NULL)
    {
        preptr=ptr;
        qreqtr=qtr;
        ptr=ptr->next;
        qtr=qtr->next;
        preptr->next=qreqtr;
        if(ptr==NULL)
        {
            break;
        }         
        qreqtr->next=ptr;
        if(qtr==NULL)
        {
            break;
        }
    }
    printf("\n");
    display(start);
}