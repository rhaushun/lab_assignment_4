#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int cnt = 0; 
	node *nhead = head; 
	while (nhead != NULL)
	{
			cnt += 1; 
			nhead = nhead->next; 
	}
	
	return cnt; 
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int size = length(head); 
	char *string = (char*)malloc((size + 1) * sizeof(char)); 
	int i = 0; 

	node *curr = head; 
	while (curr != NULL)
	{
		string[i] = curr->letter; 
		i += 1; 
		curr = curr->next;
	}
	
	string[i] = '\0'; 
	return string; 
}

// inserts character to the linkedlist 
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *n_node = (node*)malloc(sizeof(node)); 
	n_node->letter = c; 
	n_node->next = NULL; 

	if (*pHead == NULL)
	{
			*pHead = n_node; 
	}

	else
	{
		node *n_head = *pHead; 
		while (n_head->next != NULL)
		{
			n_head = n_head->next; 
		}
		n_head->next = n_node; 
	}

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	if (pHead == NULL || *pHead == NULL) {
        return;
    }

    node* current = *pHead;
    node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}