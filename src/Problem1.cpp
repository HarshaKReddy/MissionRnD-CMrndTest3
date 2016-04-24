/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node{
	int data;
	node *left;
	node *right;
};
int left_side(node *, int,int);
int right_side(node *, int,int);

int left_side(node *curr, int N, int n)
{
	if (curr == NULL)
		return N;
	else
	{
		if (curr->data >= 0 && curr->data <= n)
			N = N - (curr->data);
		N = left_side(curr->left, N, n);
		N = right_side(curr->right, N, n);
	}
	return N;
}
int right_side(node *curr, int N, int n)
{
	if (curr == NULL)
		return N;
	else
	{
		if (curr->data >= 0 && curr->data <= n)
			N = N - (curr->data);
		N = left_sidt(curr->left, N, n);
		N = right_side(curr->right, N, n);
	}
	return N;
}

int get_missing_value(node *root, int n){

	int N;
	node *temp;
	temp = root;
	N = (n*(n + 1)) / 2;
	if (root != NULL)
	{
		if (temp->data >= 0 && temp->data <= n)
			N = N - temp->data;
		//n--;
	}
	else
		return -1;
	N = left_side(temp->left, N, n);
	N = right_side(temp->right, N, n);
	return N;
}
