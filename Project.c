#include "Dict.h"
struct node
{
    long int sal;
    char gen;
};
void print(struct dictionary *head)
{
    int i;
    printf("Enter Dictionary number to be printed:-");
    scanf("%d",&i);
    struct header *temp=head->nodes[i-1];
    struct node *t;
    while(temp!=NULL)
    {
        t=(struct node*)temp->ptr;
        printf("%s   %ld    %c\n",temp->cptr,t->sal,t->gen);
        temp=temp->next;
    }
}
int main()
{
    struct dictionary *head=(struct dictionary*)malloc(sizeof(struct dictionary));
    struct node *temp,*nd;
    int ch=1,i,j;
    head->capacity=5;
    head->dict_size=-1;
    while(ch)
    {
        printf("Enter choice:-\n");
        printf("1 - Create Dictionary\n");
        printf("2 - Insert a word\n");
        printf("3 - Delete a word\n");
        printf("4 - Modify a word\n");
        printf("5 - Print words in Dictionary\n");
        printf("6 - Search\n");
        printf("7 - Merge two dictionaries\n");
        printf("8 - Destroy dictionary\n");
        printf("9 - Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=create_dict(head);
                        break;
            case 2: nd=(struct node*)malloc(sizeof(struct node));
                        char name[20];
                        printf("Enter name:-");
                        scanf("%s",&name);
                        printf("Enter salary:-");
                        scanf("%ld",&nd->sal);
                        printf("Enter Gender:-(M/F)");
                        scanf(" %c",&nd->gen);
                        head=insert_into_dict(name,nd,head);
                        break;
            case 3: head=delete_from_dict_given_key(head);
                        break;
            case 4: temp=(struct node*)update_dict_given_key(head);
                        printf("Enter new salary:-");
                        scanf("%ld",&temp->sal);
                        break;
            case 5: print(head); break;
            case 6: i=search_dict_with_key(head);
                         if(i==1)
                            printf("element found");
                         else
                            printf("Element not found");
                         break;
            case 7:  head=merge_two_dict(head);
                         break;
            case 8: destroy_dict(head);
                        break;
            case 9: ch=0; break;
            default: printf("Enter a valid input\n");
        }
    }
}
