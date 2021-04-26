/**********************************************************************
Program: program 3
Author: Alex Li
Date: 3/27/18
Time spent: 30 minutes
Purpose: The purpose of this program is to organize a number of input
integers and output them in ascending order without any duplicates. I 
used a tree structure for efficiency and used the in order traversal
function to effortlessly print out the numbers in order.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#define _CRT_SECURE_NO_WARNINGS

struct node;
typedef struct node Node;

struct node {
	int data;
	Node *left;
	Node *right;
};

void clear_keyboard_buffer();
void insert(Node **pRoot, int value);
void in_order_traversal(Node* root);
Bool check_duplicate(Node **pRoot, int value);

int main(int argc, char *argv[])
{
	Node *root = NULL;
	int i;

	scanf("%d", &i);
	clear_keyboard_buffer();
	while (i != -1)
	{
		if (check_duplicate(&root, i) == FALSE)
			insert(&root, i);
		scanf("%d", &i);
	}

	in_order_traversal(root);

	scanf_s("%d", i);

	return 0;
}

void insert(Node **pRoot, int value)
{
	if ((*pRoot) == NULL)
	{
		(*pRoot) = (Node*)malloc(sizeof(Node));
		if ((*pRoot) == NULL)
		{
			printf("malloc failed");
			exit(1);
		}
		(*pRoot)->data = value;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
	}
	else if (value < (*pRoot)->data)
	{
		insert(&((*pRoot)->left), value);
	}
	else if (value >(*pRoot)->data)
	{
		insert(&((*pRoot)->right), value);
	}
	else
	{
		return;//do samey samey stuff
	}
}

Bool check_duplicate(Node **pRoot, int value)
{
	if ((*pRoot) == NULL)
	{
		return FALSE;
	}
	else if (value < (*pRoot)->data)
	{
		check_duplicate(&((*pRoot)->left), value);
	}
	else if (value >(*pRoot)->data)
	{
		check_duplicate(&((*pRoot)->right), value);
	}
	else
	{
		return TRUE;
	}
}

void in_order_traversal(Node* root)
{
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d\n", root->data);
		in_order_traversal(root->right);
	}
}

void clear_keyboard_buffer()
{
	char c;
	do
	{
		scanf("%c", &c);
	} while (c != '\n');                                        //reading character up to and including a new line
}
