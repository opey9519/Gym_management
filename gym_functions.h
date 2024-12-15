#ifndef GYM_FUNCTION_H
#define GYM_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

// Struct used for members in binary search tree
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

// Finds node with minimum value
struct node *min_value_node(struct node *node);

// Depth First Search (DFS) Algorithm to display all members
void in_order_traversal(struct node *root);

// Function to create new node
struct node *add_node(char *first_name, char *last_name, char *email, int id, int points);

// Function to add members to tree based on last name
struct node *add_member(struct node *root, char *first_name, char *last_name, char *email, int id, int points);

// Function utilizes binary search by last name
struct node *search(struct node *root, char *last_name);

// Function to delete a member by last name
struct node *delete_member(struct node *root, char *last_name);

// Collection of functions to quick add/subtract points from member
void quick_add_10_points(struct node *root);

void quick_add_50_points(struct node *root);

void quick_add_100_points(struct node *root);

void quick_add_1000_points(struct node *root);

void quick_subtract_10_points(struct node *root);

void quick_subtract_50_points(struct node *root);

void quick_subtract_100_points(struct node *root);

void quick_subtract_1000_points(struct node *root);

// Collection of functions to add/subtract specific points
void add_points(struct node *root, int points);

void subtract_points(struct node *root, int points);

#endif