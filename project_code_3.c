#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//creating node for student informatin
struct node {
    char stu_name[50];
    char ID[20];
    char Email[50];
    char cell[20];
    char blood_group[10];
    char district[20];
    struct node *next;
};

//function for taking information as input
void input_taking(struct node *newnode);

//function for creating and connecting node
void creaing_and_connecting_nodes(struct node **current);

//student information searching function based on id
void searching_student_info_based_on_id(struct node *head,char searching_id[]);

//student information searching function based on blood group
void searching_student_info_based_on_blood_group(struct node *head,char blood_group[]);

int main()
{
    struct node *node1 = malloc(sizeof(struct node));
    node1->next = NULL;

    struct node *current = node1;
    struct node *head = node1;

    int n;
    printf("how many student's information you want to add : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        if ( i == 1 )
        {
            printf("\n\nEnter number %d student's inforamtion\n\n",i);
            input_taking(node1);
        }

        else {
            printf("\n\nEnter number %d student's inforamtion\n\n",i);
            creaing_and_connecting_nodes(&current);
        }
    }

     // to know how to search the information
    char searching_style[20];
    printf("\n\n\nSearching based on ( ID / Blood ) : ");
    scanf("%s", &searching_style);

     // for id based search
    if ( strcmp( searching_style,"ID") == 0 )
    {
        char searching_id[20];
        printf("\n\nEnter ID : ");
        scanf("%s", &searching_id);

        searching_student_info_based_on_id(head,searching_id);
    }

     // for blood group based search
    else if ( strcmp( searching_style,"Blood") == 0 ) 
    {
        char blood_group[10];
        printf("\n\nEnter the Blood Group : ");
        scanf("%s", &blood_group);

        searching_student_info_based_on_blood_group(head,blood_group);
    }

    return 0;
}
//function definiton
void input_taking(struct node *newnode)
{
    printf("Enter student's name : ");
    scanf("%s", &newnode->stu_name);

    printf("Enter student's ID : ");
    scanf("%s", &newnode->ID);

    printf("Enter student's Email : ");
    scanf("%s", &newnode->Email);

    printf("Enter student's Cellphone : ");
    scanf("%s", &newnode->cell);

    printf("Enter student's Blood Group : ");
    scanf("%s", &newnode->blood_group);

    printf("Enter student's District : ");
    scanf("%s", &newnode->district);
}
// definition of function
void creaing_and_connecting_nodes(struct node **current)
{
    struct node *newnode = malloc (sizeof(struct node));
    newnode->next = NULL;

    input_taking(newnode);

    (*current)->next = newnode;
    *current = newnode;
}
//function definition
void searching_student_info_based_on_id(struct node *head,char searching_id[])
{
    //searching the node of the searched student
    while(head != NULL)
    {
        if( strcmp(head->ID,searching_id) == 0 )
        {
            break;
        }

        head = head->next;
    }
    
    //when id doesnt exist in the node
    if ( head == NULL )
    {
        printf("\n\nNOT FOUND\n\n");
        return;
    }

    //printing student information
    printf("\n\nInformation of the student : \n");
    printf("Name        : %s\n",head->stu_name);
    printf("ID          : %s\n",head->ID);
    printf("Email       : %s\n",head->Email);
    printf("Cell        : %s\n",head->cell);
    printf("Blood Group : %s\n",head->blood_group);
    printf("District    : %s\n\n",head->district);
}

//function definition

void searching_student_info_based_on_blood_group(struct node *head,char blood_group[])
{
    int count = 0;

    while ( head != NULL )
    {
        //searching node with the matched blood group
        if( strcmp( head->blood_group,blood_group) == 0 )
        {
            count++;

           //printing student information
           printf("\n\nInformation of the student : \n");
           printf("Name        : %s\n",head->stu_name);
           printf("ID          : %s\n",head->ID);
           printf("Email       : %s\n",head->Email);
           printf("Cell        : %s\n",head->cell);
           printf("Blood Group : %s\n",head->blood_group);
           printf("District    : %s\n\n",head->district);
        }

        head = head->next;
    }

    //if student doesnt found
    if ( count == 0 )
    {
        printf("\nNOT FOUND\n\n");
    }
}