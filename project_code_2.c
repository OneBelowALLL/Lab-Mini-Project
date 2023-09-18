#include <stdio.h>
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

//student information searching function based on id
void searching_student_info_based_on_id(struct node *head,char searching_id[]);

//student information searching function based on blood group
void searching_student_info_based_on_blood_group(struct node *head,char blood_group[]);

int main()
{
    // allocating node in memory
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));
    struct node *node4 = malloc(sizeof(struct node));
    struct node *node5 = malloc(sizeof(struct node));

    //connecting nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    //node 1 value assignment
    strcpy(node1->stu_name,"Md. Hasib Hossain");
    strcpy(node1->ID,"0242310005101195");
    strcpy(node1->Email,"hossain23105101195@diu.edu.bd");
    strcpy(node1->cell,"01927230142");
    strcpy(node1->blood_group,"O+");
    strcpy(node1->district,"Kushtia");

    //node 2 value assignment
    strcpy(node2->stu_name,"Sherin");
    strcpy(node2->ID,"0242310005101212");
    strcpy(node2->Email,"akthar23105101212@diu.edu.bd");
    strcpy(node2->cell,"01701764994");
    strcpy(node2->blood_group,"B+");
    strcpy(node2->district,"Rangpur");

    //node 3 value assignment
    strcpy(node3->stu_name,"Md. Arafat Zaman");
    strcpy(node3->ID,"0242310005101015");
    strcpy(node3->Email,"zaman23105101015@diu.edu.bd");
    strcpy(node3->cell,"01730880567");
    strcpy(node3->blood_group,"O+");
    strcpy(node3->district,"Khulna");

    //node 4 value assignment
    strcpy(node4->stu_name,"Tanbir Hasan Jewel");
    strcpy(node4->ID,"0242310005101178");
    strcpy(node4->Email,"jewel23105101178@diu.edu.bd");
    strcpy(node4->cell,"01845823231");
    strcpy(node4->blood_group,"B+");
    strcpy(node4->district,"Cox's Bazar");

    //node 5 value assignment
    strcpy(node5->stu_name,"sadman Sami");
    strcpy(node5->ID,"0242310005101921");
    strcpy(node5->Email,"sami23105101921@diu.edu.bd");
    strcpy(node5->cell,"01305277710");
    strcpy(node5->blood_group,"O+");
    strcpy(node5->district,"Dhaka");

    //assigning value of head
    struct node *head = node1;

    char searching_style[20];
    printf("Searching based on ( ID / Blood Group ) : ");
    gets(searching_style);

    if ( strcmp( searching_style,"ID") == 0 )
    {
        char searching_id[20];
        printf("Enter ID : ");
        scanf("%s", &searching_id);

        searching_student_info_based_on_id(head,searching_id);
    }

    else if ( strcmp( searching_style,"Blood Group") == 0 ) 
    {
        char blood_group[10];
        printf("Enter the Blood Group : ");
        scanf("%s", &blood_group);

        searching_student_info_based_on_blood_group(head,blood_group);
    }

    
    
    return 0;
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