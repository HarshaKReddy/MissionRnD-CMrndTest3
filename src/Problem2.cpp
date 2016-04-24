/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
};
int left_side(node *, node_dll *);
int right_side(node *, node_dll *);
int check_node(node_dll *,int);
int check_node(node_dll *head, int n)
{
	node_dll *temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data != n)
			return 0;
		if (temp->data == n && temp->data!=-1)
			temp->data = -1;
		temp = temp->next;
	}
	if (temp == NULL)
		return 1;

}
int left_side(node *curr, node_dll *head)
{
	int n,n1, n2;
	if (curr == NULL)
		return -1;
	else
	{
		n = check_node(head, curr->data);
		if (n == 0)
			return 0;
		n1 = left_side(curr->left, head);
		n2 = right_side(curr->right, head);
		if (n1 == 1 && n2 == 1)
			return 1;
		else
			return 0;
	}
}
int right_side(node *curr, node_dll *head)
{
	int n,n1, n2;
	if (curr == NULL)
		return -1;
	else
	{
		n = check_node(head, curr->data);
		if (n == 0)
			return 0;
		n1 = left_side(curr->left, head);
		n2 = right_side(curr->right, head);
		if (n1 == 1 && n2 == 1)
			return 1;
		else
			return 0;
	}
}

int is_identical(struct node_dll *head, struct node *root){
	
	int n,n1, n2;
	if (root == NULL || head == NULL)
		return -1;
	n = check_node(head, root->data);
	if (n == 0)
		return 0;
	n1=left_side(root->left, head);
	n2=right_side(root->right, head);
	if (n1 == 1 && n2 == 1)
		return 1;
	else
		return 0;

}
