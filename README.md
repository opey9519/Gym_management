gym_management.c is a C program that manages gym members through a Binary Search Tree and implementing algorithms like Depth First Search (DFS).
Features:
  Add Members- Adding members by passing a root node, first name, last name, email, id, points. If the root node is NULL, the node will then be passed to a "add_node" function that implements the current node into the binary search tree.
               The add_members function utilizes string library functions to compare the current node you're adding to the respective binary search tree node to determine it's suitable location.

  Display Members- Displaying members by passing the root node of the binary search tree to a function called "in_order_traversal" which traverses the binary search tree using DFS to print each members credentials.
  
  Point Deduction & Point Addition- Two features for each; A 'quick' option for deductions and additions to add/subtract 10, 100, 1000 points to a searched last name. The other feature is to add/subtract a specified amount of points to a member by last name.

  Search Member- Searches for a member by providing a last name in which is searched from the root of the binary search tree through DFS until node is found and printed.

  Delete Member- Deletes member based on last name.

If none of the features are utilized you may exit the program.


gym_functions.c is a C program that includes all working functions utilzied in gym_management.c. See comments included in file to determine usage

gym_functions.h is a C header file that includes the function prototypes for gym_functions.c as well as any macros or C libraries necessary to run the program
