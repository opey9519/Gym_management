#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

// Struct to hold member data via binary search tree
struct node
{
    char first_name[MAX_LEN + 1];
    char last_name[MAX_LEN + 1];
    char email[MAX_LEN + 1];
    int id;
    int points;

    struct node *left;
    struct node *right;
};

// Function to create new node
struct node *add_node(char *first_name, char *last_name, char *email, int id, int points)
{
    struct node *new_member;
    new_member = malloc(sizeof(struct node));

    strcpy(new_member->first_name, first_name);
    strcpy(new_member->last_name, last_name);
    strcpy(new_member->email, email);
    new_member->id = id;
    new_member->points = points;

    new_member->left = NULL;
    new_member->right = NULL;

    return new_member;
}

// Function to add members to tree based on last name
struct node *add_member(struct node *root, char *first_name, char *last_name, char *email, int id, int points)
{
    if (root == NULL) // If no node add node
    {
        return add_node(first_name, last_name, email, id, points);
    }
    else
    {
        if (strcmp(root->last_name, last_name) > 0) // If root last name > new last name, place left
        {
            root->left = add_member(root->left, first_name, last_name, email, id, points);
        }
        else // If root last name < new last name, place right
        {
            root->right = add_member(root->right, first_name, last_name, email, id, points);
        }

        return root;
    }
}

// Function utilizes binary search by last name
struct node *search(struct node *root, char *last_name)
{
    if (root == NULL || strcmp(root->last_name, last_name) == 0)
    {
        return root;
    }
    if (strcmp(root->last_name, last_name) > 0)
    {
        return search(root->left, last_name);
    }

    return search(root->right, last_name);
}

// Function to delete a member by last name
struct node *delete_member(struct node *root, char *last_name)
{
    if (root == NULL)
    {
        return root;
    }

    if (strcmp(last_name, root->last_name) < 0)
    {
        root->left = delete_member(root->left, last_name);
    }
    else if (strcmp(last_name, root->last_name) > 0)
    {
        root->right = delete_member(root->right, last_name);
    }
    else
    {
        // Node with one or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        struct node *temp = min_value_node(root->right);

        // Copy the in-order successor's data to this node
        strcpy(root->first_name, temp->first_name);
        strcpy(root->last_name, temp->last_name);
        strcpy(root->email, temp->email);
        root->id = temp->id;
        root->points = temp->points;

        // Delete the in-order successor
        root->right = delete_member(root->right, temp->last_name);
    }

    return root;
}

int main()
{
    printf("Welcome to Iron Enthusiast's Powerlifting Gym!\n\n");

    return 0;
}