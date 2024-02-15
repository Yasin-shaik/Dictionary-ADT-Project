#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct header
{
    char cptr[20];
    void *ptr;
    struct header *next;
};
struct dictionary
{
    struct header *nodes[5];
    int dict_size;
    int capacity;
};
struct dictionary *create_dict(struct dictionary *dict)
{
    if(dict->dict_size==dict->capacity-1)
        printf("New dictionary Cannot be Created\n");
    else
    {
        dict->dict_size+=1;
        dict->nodes[dict->dict_size]=NULL;
        return dict;
    }
}
struct header *insert_into_dict(char name[],void *p,struct dictionary *h)
{
    int i;
    printf("enter dictionary number you want to insert into?");
    scanf("%d",&i);
    if(i>h->dict_size+1)
        printf("Dictionary Not available");
    else
    {
        struct header *head=h->nodes[i-1];
        struct header *nd=(struct header *)malloc(sizeof(struct header));
        strcpy(nd->cptr,name);
        nd->ptr=p;
        nd->next=NULL;
        if((head==NULL)||(strcmp(nd->cptr,head->cptr)<=0))
        {
            nd->next=head;
            head=nd;
        }
        else
        {
            struct header *curr=head,*prev=NULL;
            while((curr!=NULL)&&(strcmp(nd->cptr,head->cptr)>0))
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=nd;
            nd->next=curr;
        }
        h->nodes[i-1]=head;
    }
    return h;
}
struct dictionary *delete_from_dict_given_key(struct dictionary *head)
{
    if(head->dict_size==-1)
            printf("Dictionary not Available");
    else
    {
        int i;
        printf("Enter dictionary number to be deleted from:-");
        scanf("%d",&i);
        if(i<=head->dict_size+1)
        {
            char name[20];
            printf("Enter name to be deleted:-");
            scanf("%s",&name);
            struct header *curr=head->nodes[i-1],*prev=NULL;
            if(strcmp(curr->cptr,name)==0)
            {
                prev=curr;
                curr=curr->next;
                free(prev);
                head->nodes[i-1]=curr;
            }
            else{
            while(curr!=NULL)
            {
                if(strcmp(curr->cptr,name)==0)
                    break;
                else
                {
                    prev=curr;
                    curr=curr->next;
                }
            }
            prev->next=curr->next;
            free(curr);
            }
        }
        else
                printf("No such dictionary available");
    }
    return head;
}
void *update_dict_given_key(struct dictionary *head)
{
    int i;
    printf("Enter dictionary number to be modified:-");
    scanf("%d",&i);
    char name[20];
    printf("Enter name of whom the details to be modified:-");
    scanf("%s",&name);
    struct header *temp=head->nodes[i-1];
    while((temp!=NULL)&&(strcmp(name,temp->cptr)!=0))
            temp=temp->next;
    return temp->ptr;
}
int search_dict_with_key(struct dictionary *head)
{
    int i;
    printf("Enter dictionary number to  be searched in:-");
    scanf("%d",&i);
    struct header *temp=head->nodes[i-1];
    char name[20];
    printf("Enter name to be searched:-");
    scanf("%s",&name);
    while(temp!=NULL)
    {
        if(strcmp(temp->cptr,name)==0)
            return 1;
        temp=temp->next;
    }
    return 0;
}
void destroy_dict(struct dictionary *head)
{
    int i;
    printf("Enter dictionary number to  be destroyed:-");
    scanf("%d",&i);
    struct header *temp=head->nodes[i-1],*h;
    while(temp!=NULL)
    {
        h=temp;
        temp=temp->next;
        free(h);
    }
    head->nodes[i-1]=NULL;
}
struct dictionary *merge_two_dict(struct dictionary *dict)
{
    create_dict(dict);
    struct header *head1,*head2,*head3;
    int i,j;
    printf("Enter dictionary numbers to be merged:-");
    scanf("%d%d",&i,&j);
    head1=dict->nodes[i-1];
    head2=dict->nodes[j-1];
    head3=dict->nodes[dict->dict_size];
    while((head1!=NULL)&&(head2!=NULL))
    {
        struct header *nd=(struct header*)malloc(sizeof(struct header));
        nd->next=NULL;
        if(strcmp(head1->cptr,head2->cptr)<0)
        {
            strcpy(nd->cptr,head2->cptr);
            nd->ptr=head2->ptr;
            head2=head2->next;
        }
        else
        {
            strcpy(nd->cptr,head1->cptr);
            nd->ptr=head1->ptr;
            head1=head1->next;
        }
        if(head3==NULL)
            head3=nd;
        else
        {
            nd->next=head3;
            head3=nd;
        }
    }
    while(head1!=NULL)
    {
        struct header *nd=(struct header*)malloc(sizeof(struct header));
        strcpy(nd->cptr,head1->cptr);
        nd->ptr=head1->ptr;
        nd->next=NULL;
        if(head3==NULL)
            head3=nd;
        else
        {
            nd->next=head3;
            head3=nd;
        }
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        struct header *nd=(struct header*)malloc(sizeof(struct header));
        strcpy(nd->cptr,head2->cptr);
        nd->ptr=head2->ptr;
        nd->next=NULL;
        if(head3==NULL)
            head3=nd;
        else
        {
            nd->next=head3;
            head3=nd;
        }
        head2=head2->next;
    }
    dict->nodes[dict->dict_size]=head3;
    return dict;
}
