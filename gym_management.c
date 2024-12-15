#include "gym_functions.h"
#include "gym_functions.c"

int main()
{
    // Gym Owner
    struct node *admin = add_node("Gavin", "Wilson", "GavinWilson@gym.com", 123456789, 9999999);

    // Key Variable
    char input;
    char point_input;
    char point_choice;
    char first_name[MAX_LEN + 1];
    char last_name[MAX_LEN + 1];
    char email[MAX_LEN + 1];
    int id;
    int points;

    // Gym Introduction
    printf("Welcome to Iron Enthusiast's Powerlifting Gym!\n");
    printf("Options:\n");
    printf("  'a' - Add a new member\n");
    printf("  'd' - Display all members\n");
    printf("  's' - Search for a member by last name\n");
    printf("  'p' - Quickadd/add quicksubtract/subtract points\n");
    printf("  'x' - Delete member\n");
    printf("  'e' - Exit\n");

    scanf(" %c", &input);

    while (input != 'e')
    {
        switch (input)
        {
        case 'a':
            printf("What is your the new member's First Name, Last Name, Email, Id and Points?\n");
            printf("First Name: ");
            scanf("%s", first_name);

            printf("Last Name: ");
            scanf("%s", last_name);

            printf("Email: ");
            scanf("%s", email);

            printf("\nId: ");
            scanf("%d", &id);

            printf("\nPoints: ");
            scanf("%d", &points);

            add_member(admin, first_name, last_name, email, id, points);
            break;

        case 'd':
            printf("Displaying Members...\n");
            in_order_traversal(admin);
            break;

        case 'p':
            printf("\nPoint deduction (-). Point addition (+) ");
            printf("\nFor whom? ");
            scanf("%s", last_name);
            struct node *pStudent = search(admin, last_name);
            if (pStudent == NULL)
            {
                printf("Member not found!");
                break;
            }
            scanf(" %c", &point_input);
            int points_change;
            switch (point_input)
            {
            case '+':
                printf("\nQuickadd (y/n)? ");
                scanf(" %c", &point_choice);
                if (point_choice == 'y')
                {
                    printf("\nHow many points? ");
                    scanf("%d", &points_change);
                    if (points_change == 10)
                    {
                        quick_add_10_points(pStudent);
                    }
                    else if (points_change == 100)
                    {
                        quick_add_100_points(pStudent);
                    }
                    else if (points_change == 1000)
                    {
                        quick_add_1000_points(pStudent);
                    }
                    else
                    {
                        add_points(pStudent, points_change);
                    }
                }
                break;

            case '-':
                printf("\nQuicksubtract (y/n)? ");
                scanf(" %c", &point_choice);
                if (point_choice == 'y')
                {
                    printf("\nHow many points? ");
                    scanf(" %c", &point_choice);
                    if (points_change == 10)
                    {
                        quick_subtract_10_points(pStudent);
                    }
                    else if (points_change == 100)
                    {
                        quick_subtract_100_points(pStudent);
                    }
                    else if (points_change == 1000)
                    {
                        quick_subtract_1000_points(pStudent);
                    }
                    else
                    {
                        subtract_points(pStudent, points_change);
                    }
                }
                break;

            default:
                break;
            }
            printf("Total points for %s %s: %d", pStudent->first_name, pStudent->last_name, pStudent->points);

        case 's':
            printf("What is the last name of the member? ");
            scanf("%s", last_name);
            search(admin, last_name);
            break;

        case 'x':
            printf("Last name: ");
            scanf("%s", last_name);
            delete_member(admin, last_name);
            break;

        default:
            printf("Invalid option try again.\n");
            break;
        }

        printf("Options:\n");
        printf("  'a' - Add a new member\n");
        printf("  'd' - Display all members\n");
        printf("  's' - Search for a member by last name\n");
        printf("  'p' - Quickadd/add quicksubtract/subtract points\n");
        printf("  'x' - Delete member\n");
        printf("  'e' - Exit\n");
        scanf(" %c", &input);
    }

    return 0;
}