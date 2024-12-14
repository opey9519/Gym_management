#include "gym_functions.h"
#include "gym_functions.c"

int main()
{
    // Gym Owner
    struct node *admin = add_node("Gavin", "Wilson", "GavinWilson@gym.com", 123456789, 9999999);

    // Key Variable
    char input;
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
    printf("  'p' - quickadd/add quicksubtract/subtract points\n");
    printf("  'e' - Exit\n");

    scanf("%c", &input);

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

        case 's':
            printf("What is the last name of the member? ");
            scanf("%s", last_name);
            search(admin, last_name);
            break;

        // case 'p':
        //     printf("");
        //     break;

        default:
            break;
        }

        printf("Options:\n");
        printf("  'a' - Add a new member\n");
        printf("  'd' - Display all members\n");
        printf("  's' - Search for a member by last name\n");
        printf("  'e' - Exit\n");
        scanf("%c", &input);
    }

    return 0;
}