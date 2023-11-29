#include<stdio.h> // code koro na jibon ses
#include<string.h>
#include<stdlib.h>

// creating node ,, remember the node
typedef struct Node
{
    char place_name[100];
    char description[1000];
    char turn[1000];
    struct node *next;
} node;

//4 ta rastar jonno amra 4 ta head nibo and 4 ta tail nibo ,, okey ? bujhte parso to ????
node *head_of_path1, *tail_of_path1;
node *head_of_path2, *tail_of_path2;
node *head_of_path3, *tail_of_path3;
node *head_of_path4, *tail_of_path4; // kaj ses bujhte parson,,, tobe main kaj aro ache akhono cholo

void home_interface_design();
void about_us();

//egula holo amader rasta bananor function karom ato jaiga main function e korte ami parbo na
void path_1(char name[],char descrip[],char turning_point[]);
void path_2(char name[],char descrip[],char turning_point[]);
void path_3(char name[],char descrip[],char turning_point[]);
void path_4(char name[],char descrip[],char turning_point[]);

//eta holo sobar dadu bujcho? mane etar vitore oporer sobai kaj kormo korbe
void creating_the_map();

// to ekhan theke amra pabo je amader arki kothai jete hobe mane amader destination
int selected_destination();

//egula hosse sob map chapanor function
void printing_path_1(char destination[]);
void printing_path_2(char destination[]);
void printing_path_3(char destination[]);
void printing_path_4(char destination[]);

//eta hosse amader ses kaj summary kaj
void summary_bro();

int main()
{
home_recall:

    //clearing the screen .. sobai eta mone rakhba bar bar comment lekha possible na
    system("cls");

    //call for home interface design
    home_interface_design();

    //for choosing the menu from home page
    int choose_option_from_home;
    printf("\t  => Choose your choice : ");
    scanf("%d", &choose_option_from_home);

    // khela sob ekahne mane rasta khojakhoji sob ekhan theke hobe
    if( choose_option_from_home == 1)
    {
searcing_call_again:
        system("cls"); // vulle cholbe na eta die poriskar kora hoi sob

        //eta holo aktu design arki ei part tar jonno ,, soto tai function ar banailam na ,,
        printf("\t\t\t\t\t\t\t  -------------------\n");
        printf("\t\t\t\t\t\t\t  | SEARCH YOUR WAY |\n");
        printf("\t\t\t\t\t\t\t  -------------------\n");

        //call korlam rasta banaye die jaw plz
        creating_the_map();

        //call kortesi destination pawar jonno
        int destination = selected_destination();

        system("cls"); // ki bolsilam mone ache to sob always clear rakhte hobe

        //bascially ekhane amra khuje khuje rasta dekhabo to jehetu 4 ta rasta amra 4 ta function e vag kore dibo sob kisu
        //first e aktu design na holei na
        printf("\n\t\t\t\t\t\t\t  ------------\n");
        printf("\t\t\t\t\t\t\t  | YOUR WAY |\n");
        printf("\t\t\t\t\t\t\t  ------------\n\n\n\n\n");

        if(destination==1)
        {
            printf("\t\t\tClose Your Eyes , Now Open It -_-\n");
            printf("\n\n\t\t\t\t     Magic\n");
            printf("\n\n\n\t\t\t ~You are in MAIN_GATE \n\n");

            printf("\n\n\n\n\n\t\t\t\t\t\t** CONGRATULATIONS **\n");
            printf("\n\t\t\t\t\t- You have reached your destination -\n\n\n\n");
        }
        else if (destination==16 || destination==5 || destination==7 || destination==18 || destination==9)
        {
            if(destination==16) printing_path_1("KNOWLEDGE VALLLEY");
            if(destination==5) printing_path_1("ACADEMIC BUILDING - 4");
            if(destination==7) printing_path_1("PLAYGROUND - 2");
            if(destination==18) printing_path_1("AUDITORIUM");
            if(destination==9) printing_path_1("YOUNUS KHAN SCHOLAR GARDEN - 2");
        }
        else if(destination==2 || destination==6)
        {
            if(destination==2) printing_path_3("ADMISSION OFFICE");
            if(destination==6) printing_path_3("PLAYGROUND - 1");
        }
        else if(destination==13 || destination==11 || destination==12 || destination==8)
        {
            if(destination==13) printing_path_4("MOSQUE");
            if(destination==11) printing_path_4("TRANSPORT AREA");
            if(destination==12) printing_path_4("GATE 8");
            if(destination==8) printing_path_4("YOUNUS KHAN SCHOLAR GARDEN - 1");
        }
        else
        {
            if(destination==14) printing_path_2("GREEN GARDEN RESTAURANT");
            if(destination==4) printing_path_2("ACADEMIC BUILDING - 3");
            if(destination==3) printing_path_2("ACADEMIC BUILDING - 1");
            if(destination==17) printing_path_2("BONOMAYA");
            if(destination==15) printing_path_2("FOOD COURT");
            if(destination==10) printing_path_2("ROWSHAN ARA SCHOLAR GARDEN");
        }

        char decision;
        printf("\n\n\t\tSearch Again For Location (y/n) : ");
        scanf(" %c", &decision);
        if(decision=='y')
        {
            goto searcing_call_again;
        }
        else
        {
            goto home_recall;
        }

    }
    // about our team members information
    else if( choose_option_from_home == 2 )
    {
        system("cls");

        //call for about us funtion
        about_us();

        //asking to continue or exit the program
        printf("\n\t\tGo To Main Menu (y/n) : ");
        char option;
        scanf(" %c", &option);
        if( option == 'y' )
        {
            //going to the main menu
            goto home_recall;
        }
        else if ( option == 'n')
        {
            system("cls");
            return 0;
        }
    }
    else if ( choose_option_from_home == 3 )
    {
        system("cls"); // eta ki mone to ache ?? hae right sob clear

        //summary er oo akta design er dorkar ache tai na , obossoi lets design a bit
        printf("\n\t\t\t\t\t\t\t  --------------------------\n");
        printf("\t\t\t\t\t\t\t  | SUMMARY OF OUR PROJECT |\n");
        printf("\t\t\t\t\t\t\t  --------------------------\n\n\n");

        //summary hudai eto lekhar kisu nai but project full done oo to kora lagbe tai akta function call kore rakhi
        summary_bro();

        //asking to continue or exit the program
        printf("\n\t\tGo To Main Menu (y/n) : ");
        char option;
        scanf(" %c", &option);
        if( option == 'y' )
        {
            //going to the main menu
            goto home_recall;
        }
        else if ( option == 'n')
        {
            system("cls");
            return 0;
        }

    }
    // option for exiting the program
    else if ( choose_option_from_home == 4 )
    {
        //clearing the screen
        system("cls");
        return 0;
    }
    // if anyone choose the wrong option from the home page
    else
    {
        //clearing the screen
        system("cls");

        //going to home menu again
        printf("\n\n\n\t\t\t\t<> Wrong Selection , Try Again <>\n\n");
        goto home_recall;
    }

    return 0;
}
void home_interface_design()
{
    printf("\n\n\t\t\t\t\t\t\t ***Welcome to our project***\n");
    printf("\t\t\t\t\t\t\t______________________________\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t");
    for (int i=0; i<16; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t\t---NAVIGATE_X---");
    printf("\n\t\t\t\t\t\t\t\t");
    for (int i=0; i<16; i++)
    {
        printf("*");
    }
    printf("\n\n\n\n\n\n\t\t\t\t1. SEARCH YOUR WAY");
    printf("\n\n\t\t\t\t2. ABOUT US");
    printf("\n\n\t\t\t\t3. SUMMARY OF OUR PROJECT");
    printf("\n\n\t\t\t\t4. EXIT\n\n\n\n\n");
}
void about_us()
{
    printf("\t\t\t\t\t\t\t  --------------------------------\n");
    printf("\t\t\t\t\t\t\t  | INFORMATION OF GROUP MEMBERS |\n");
    printf("\t\t\t\t\t\t\t  --------------------------------\n");

    printf("\n\t\t\t\t\t\t\t  *************\n");
    printf("\t\t\t\t\t Group Name : -");
    printf("\t  << SIGN_IN >>\n");
    printf("\t\t\t\t\t\t\t  *************\n\n");


    printf("\t\t\t1.\tNAME : Masud Rana Nayeem\n");
    printf("\t\t\t\t  ID : 0242310005101849\n");
    printf("\t\t\t\tMAIL : masud231005101849@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01820050464");

    printf("\n\n\t\t\t2.\tNAME : Md. Sazzadul Islam Shaon\n");
    printf("\t\t\t\t  ID : 0242310005101028\n");
    printf("\t\t\t\tMAIL : shaon23105101028@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01793961532");

    printf("\n\n\t\t\t3.\tNAME : S M Sadman Al Siam\n");
    printf("\t\t\t\t  ID : 0242310005101123\n");
    printf("\t\t\t\tMAIL : siam23105101123@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01603539123");

    printf("\n\n\t\t\t4.\tNAME : Md Mubarak Hossain Razwan\n");
    printf("\t\t\t\t  ID : 0242310005101027\n");
    printf("\t\t\t\tMAIL : razwan23105101027@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01313323612");
    \

    printf("\n\n\t\t\t5.\tNAME : Humaira Nur Tisha\n");
    printf("\t\t\t\t  ID : 0242310005101142\n");
    printf("\t\t\t\tMAIL : tisha23105101142@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01843662523");

    printf("\n\n\t\t\t6.\tNAME : Md. Hasib Hossain\n");
    printf("\t\t\t\t  ID : 0242310005101195\n");
    printf("\t\t\t\tMAIL : hossain23105101195@diu.edu.bd\n");
    printf("\t\t\t     CONTACT : 01927230142\n\n");
}

void path_1(char name[],char descrip[],char turning_point[])
{
    node *new_rasta = malloc(sizeof(node));
    new_rasta->next = NULL;

    strcpy(new_rasta->place_name,name);
    strcpy(new_rasta->description,descrip);
    strcpy(new_rasta->turn,turning_point);

    tail_of_path1->next = new_rasta;
    tail_of_path1 = new_rasta;
}

void path_2(char name[],char descrip[],char turning_point[])
{
    node *new_rasta = malloc(sizeof(node));
    new_rasta->next = NULL;

    strcpy(new_rasta->place_name,name);
    strcpy(new_rasta->description,descrip);
    strcpy(new_rasta->turn,turning_point);

    tail_of_path2->next = new_rasta;
    tail_of_path2 = new_rasta;
}

void path_3(char name[],char descrip[],char turning_point[])
{
    node *new_rasta = malloc(sizeof(node));
    new_rasta->next = NULL;

    strcpy(new_rasta->place_name,name);
    strcpy(new_rasta->description,descrip);
    strcpy(new_rasta->turn,turning_point);

    tail_of_path3->next = new_rasta;
    tail_of_path3 = new_rasta;
}

void path_4(char name[],char descrip[],char turning_point[])
{
    node *new_rasta = malloc(sizeof(node));
    new_rasta->next = NULL;

    strcpy(new_rasta->place_name,name);
    strcpy(new_rasta->description,descrip);
    strcpy(new_rasta->turn,turning_point);

    tail_of_path4->next = new_rasta;
    tail_of_path4 = new_rasta;
}

void creating_the_map()
{
    /* to ekhane ja kahini seta holo amra sompurno daffodil ke 4 ta path e vag korsi
    so amader ekhon 4 ta link list create korbo,, and most important thing is that
    hae sobai mone rakho thik ache sob gular rastar head holo gate 2 ba main gate jeta arki,, hae gate 2
    obossoi id lagbe otherwise program run hobe na ,, sorry mane vitore jete dibe na*/

    // eta holo amader prothom rasta er jonno ,, knowledgevalley->ab4->field2->auditorium->hall2
    head_of_path1 = malloc(sizeof(node));
    head_of_path1->next = NULL;
    tail_of_path1 = malloc(sizeof(node));
    tail_of_path1 = head_of_path1;

    strcpy(head_of_path1->place_name,"MAIN GATE");
    strcpy(head_of_path1->description,"enter_here_exit_wise");
    strcpy(head_of_path1->turn,"straight 10m again straight forward-> straight 10m loaction is in your left side");

    path_1("KNOWLEDGE VALLEY","an_enlightenment","straight 10m again straight forward-> straight 10m loaction is in your left side");
    path_1("ACADEMIC BUILDING - 4","tower_of_thought","straight 5m again straight forward-> straight 5m location is infront of you");
    path_1("PLAYGROUND - 2","leap_and_run","turn left and straight along playground_2 20m-> straight along playground-2 20m location is infront of you");
    path_1("AUDITORIUM","the_brilliance_ballroom",">take right turn then straight 25m loaction is in your right side");
    path_1("YOUNUS KHAN SCHOLAR GARDEN - 2","the_brotherhood_bastion","er pore amar moner thikana dewa hobe"); // achca kaj ses ,, porer rasta banate hobe cholo


    // eta holo 2nd rastar jonno arki ,,
    head_of_path2 = malloc(sizeof(node));
    head_of_path2->next = NULL;
    tail_of_path2 = malloc(sizeof(node));
    tail_of_path2 = head_of_path2;

    strcpy(head_of_path2->place_name,"MAIN GATE");
    strcpy(head_of_path2->description,"enter_here_exit_wise");
    strcpy(head_of_path2->turn,"take right turn then straight 10m-> take right turn then straight 10m location is in your right side");

    path_2("GREEN GARDEN RESTAURANT","dine_in_style","take left turn then straight forward-> take left turn location is in your right side");
    path_2("ACADEMIC BUILDING - 3","tower_of_thought","straight 15m again straight forward-> straight 15m location is in your right side");
    path_2("ACADEMIC BUILDING - 1","tower_of_thought","straight 20m again straight forward-> location is in your right side");
    path_2("BONOMAYA","heart_haven","straight 5m again straight forward-> straight 5m location is in your left side");
    path_2("FOOD COURT","taste_the_world",">straight 10m then take right turn and straight 15m location is in your left side");
    path_2("ROWSHAN ARA SCHOLAR GARDEN","the_queen's_quarters","ekhane moner rajkonna ra bosobas kore"); // bah bah etaw ses ,, wait ekhon porer tar kaj suru cholo

    //eta holo amader third rasta er kaj arki
    head_of_path3 = malloc(sizeof(node));
    head_of_path3->next = NULL;
    tail_of_path3 = malloc(sizeof(node));
    tail_of_path3 = head_of_path3;

    strcpy(head_of_path3->place_name,"MAIN GATE");
    strcpy(head_of_path3->description,"enter_here_exit_wise");
    strcpy(head_of_path3->turn,"straight 2m again straight forward-> straight 2m location is infront of you");

    path_3("ADMISSION OFFICE","communication_hub",">straight 4m location is infront of you");
    path_3("PLAYGROUND 2","leap_and_learn","field e probes nised"); // eta ekdom ii bachcha rasta suru howar agei ses

    //kahini badh die porer rastar kaj suru koro bachcha ra
    head_of_path4 = malloc(sizeof(node));
    head_of_path4->next = NULL;
    tail_of_path4 = malloc(sizeof(node));
    tail_of_path4 = head_of_path4;

    strcpy(head_of_path4->place_name,"MAIN GATE");
    strcpy(head_of_path4->description,"enter_here_exit_wise");
    strcpy(head_of_path4->turn,"straight 5m then take right turn again straight forward 10m-> straight 5m then take right turn and staright 10m location is infront of you");

    path_4("MOSQUE","serenity in prayer,echoes in silence","take left turn then straight 15m then turn right-> take left turn then straight 15m location is in your right side");
    path_4("TRANSPORT AREA","journey_junction","straight 10m then turn right again straight froward 10m-> straight 8m then take right turn and straight 10m location is infront of you");
    path_4("GATE 8","enter_here_exit_wise",">take right turn then straight 25m location in your right side");
    path_4("YOUNUS KHAN SCHOLAR GARDEN - 1","the_brotherhood_bastion","hall e current thake na"); // to rastar kahini ses ,, ekhon suru main kaj egula to kisui na hudai
}

int selected_destination()
{
//eta korte sob theke besi somoi lagse huuuuuuuuuur
    printf("\n\t\t\tLOCATION LIST : \n");
    printf("\t\t\t--------------- \n\n");
    printf("\t\t\t\t1. MAIN GATE\t\t\t\t\t10. ROWSHAN ARA SCHOLAR GARDEN\n");
    printf("\t\t\t\t   enter_here_exit_wise\t\t\t\t    the_queen's_quarters\n\n");
    printf("\t\t\t\t2. ADMISSION OFFICE\t\t\t        11. TRANSPORT AREA\n");
    printf("\t\t\t\t   communication_hub\t\t\t            journey_junction\n\n");
    printf("\t\t\t\t3. ACADEMIC BUILDING - 1\t\t\t12. GATE 8\n");
    printf("\t\t\t\t   tower_of_thought\t\t\t\t    enter_here_exit_wise\n\n");
    printf("\t\t\t\t4. ACADEMIC BUILDING - 3\t\t\t13. MOSQUE\n");
    printf("\t\t\t\t   tower_of_thought\t\t\t\t    serenity in prayer, echoes in silence\n\n");
    printf("\t\t\t\t5. ACADEMIC BUILDING - 4\t\t\t14. GREEN GARDEN RESTAURANT\n");
    printf("\t\t\t\t   tower_of_thought\t\t\t\t    dine_in_style\n\n");
    printf("\t\t\t\t6. PLAYGROUND - 1\t\t\t\t15. FOOD COURT\n");
    printf("\t\t\t\t   leap_and_learn\t\t\t\t    taste_the_world\n\n");
    printf("\t\t\t\t7. PLAYGROUND - 2\t\t\t\t16. KNOWLEDGE VALLEY\n");
    printf("\t\t\t\t   leap_and_learn\t\t\t\t    an_enlightenment\n\n");
    printf("\t\t\t\t8. YOUNUS KHAN SCHOLAR GARDEN - 1\t\t17. BONOMAYA\n");
    printf("\t\t\t\t   the_brotherhood_bastion\t\t\t    heart_haven\n\n");
    printf("\t\t\t\t9. YOUNUS KHAN SCHOLAR GARDEN - 2\t\t18. AUDITORIUM\n");
    printf("\t\t\t\t   the_brotherhood_bastion\t\t\t    the_brilliance_ballroom\n\n\n");


    //basically amra amader sob location gula start korbo main gate theke , karon advance level er kisu parina :)
    printf("\n\t\t=> Your Current Locaton\t    : MAIN GATE\n\n");
    printf("\t\t=> Choose Your Destination  : ");
    int option_value;
    scanf("%d", &option_value);
    printf("\n\n");

    return option_value;
}

void printing_path_1(char destination[])
{
    node *temp = head_of_path1;
    while(1)
    {
        if(strcmp(temp->place_name,destination)==0)
        {
            printf("\t\t   ***- %s -***\n",temp->place_name);
            printf("\n\n\n\t\t\t\t\t\t** CONGRATULATIONS **\n");
            printf("\n\t\t\t\t\t- You have reached your destination -\n\n\n\n");
            break;
        }

        printf("\t\t\t~ %s\n",temp->place_name);
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|  ");

        //ekhane abar jhamela ache otar jonno kahini korte hobe
        node *temp2 = temp->next;
        if(strcmp(temp2->place_name,destination)==0)
        {
            int flag = 0;
            int len = strlen(temp->turn);
            printf("-> ");
            for(int i=0; i<len; i++)
            {
                if(temp->turn[i]=='>')
                {
                    flag = i;
                    break;
                }
            }
            for(int i=flag+1; i<len; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }
        else
        {
            printf("-> ");
            for(int i=0; temp->turn[i]!='-'; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }

        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");

        temp = temp->next;
    }
}

void printing_path_2(char destination[])
{
    node *temp = head_of_path2;
    while(1)
    {
       if(strcmp(temp->place_name,destination)==0)
        {
            printf("\t\t   ***- %s -***\n",temp->place_name);
            printf("\n\n\n\t\t\t\t\t\t** CONGRATULATIONS **\n");
            printf("\n\t\t\t\t\t- You have reached your destination -\n\n\n\n");
            break;
        }

        printf("\t\t\t~ %s\n",temp->place_name);
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|  ");

        //ekhane abar jhamela ache otar jonno kahini korte hobe
        node *temp2 = temp->next;
        if(strcmp(temp2->place_name,destination)==0)
        {
            int flag = 0;
            int len = strlen(temp->turn);
            printf("-> ");
            for(int i=0; i<len; i++)
            {
                if(temp->turn[i]=='>')
                {
                    flag = i;
                    break;
                }
            }
            for(int i=flag+1; i<len; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }
        else
        {
            printf("-> ");
            for(int i=0; temp->turn[i]!='-'; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }

        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");

        temp = temp->next;
    }
}

void printing_path_3(char destination[])
{
    node *temp = head_of_path3;
    while(1)
    {
        if(strcmp(temp->place_name,destination)==0)
        {
            printf("\t\t   ***- %s -***\n",temp->place_name);
            printf("\n\n\n\t\t\t\t\t\t** CONGRATULATIONS **\n");
            printf("\n\t\t\t\t\t- You have reached your destination -\n\n\n\n");
            break;
        }

        printf("\t\t\t~ %s\n",temp->place_name);
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|  ");

        //ekhane abar jhamela ache otar jonno kahini korte hobe
        node *temp2 = temp->next;
        if(strcmp(temp2->place_name,destination)==0)
        {
            int flag = 0;
            int len = strlen(temp->turn);
            printf("-> ");
            for(int i=0; i<len; i++)
            {
                if(temp->turn[i]=='>')
                {
                    flag = i;
                    break;
                }
            }
            for(int i=flag+1; i<len; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }
        else
        {
            printf("-> ");
            for(int i=0; temp->turn[i]!='-'; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }

        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");

        temp = temp->next;
    }
}

void printing_path_4(char destination[])
{
    node *temp = head_of_path4;
    while(1)
    {
        if(strcmp(temp->place_name,destination)==0)
        {
            printf("\t\t   ***- %s -***\n",temp->place_name);
            printf("\n\n\n\t\t\t\t\t\t** CONGRATULATIONS **\n");
            printf("\n\t\t\t\t\t- You have reached your destination -\n\n\n\n");
            break;
        }

        printf("\t\t\t~ %s\n",temp->place_name);
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|  ");

        //ekhane abar jhamela ache otar jonno kahini korte hobe
        node *temp2 = temp->next;
        if(strcmp(temp2->place_name,destination)==0)
        {
            int flag = 0;
            int len = strlen(temp->turn);
            printf("-> ");
            for(int i=0; i<len; i++)
            {
                if(temp->turn[i]=='>')
                {
                    flag = i;
                    break;
                }
            }
            for(int i=flag+1; i<len; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }
        else
        {
            printf("-> ");
            for(int i=0; temp->turn[i]!='-'; i++)
            {
                printf("%c",temp->turn[i]);
            }
            printf(" <-\n");
        }

        printf("\t\t\t|\n");
        printf("\t\t\t|\n");
        printf("\t\t\t|\n");

        temp = temp->next;
    }
}

summary_bro()
{
    //ekhane simple kisu add korar oo mood nai kintu ki ar korar
    printf("\t\t\tThis project is mainly based on location tracking inside the Daffodil International University . It's big campus .\n\n");
    printf("\t\t\tSo it become very tricky for new student to find anything in the campus . We covered 18 locations within these pr-\n\n");
    printf("\t\t\toject . Everytime we started from the MAIN GATE . Then you can choose your location from our well designed list . \n\n");
    printf("\t\t\tAfter choosing the destination the program will generate a map by giving instruction for your desired path . By \n\n");
    printf("\t\t\tfollowing that path you can get your destination . \n\n\n");

    printf("\n\t\t\tFor the project we have used : \n\n");
    printf("\t\t\t\t1. If-else\n\n");
    printf("\t\t\t\t2. Loops\n\n");
    printf("\t\t\t\t3. Strings\n\n");
    printf("\t\t\t\t4. Structure\n\n");
    printf("\t\t\t\t5. Dynamic Memory Allocation\n\n");
    printf("\t\t\t\t6. Link List Data Structure etc.\n\n\n");

    printf("\n\t\t\tThanks for using our program . And we really hope that you liked our project . ");
    printf("\n\n\t\t\t\t\t\t\t\t***PEACE***\n\n\n");
}


//done ,,, huuuuh
