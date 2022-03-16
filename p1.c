#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}Node;

Node* getNode(int data, Node* next, Node* prev)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (!node) exit(1);
	node->next = next;
	node->prev = prev;
	node->data = data;
	return node;
}

Node* formList()
{
	Node* head = NULL, *tail = NULL;
	Node* start = (Node*)malloc(sizeof(Node));
	if (!start) exit(1);
	printf("Unesite broj elemenata liste: ");
	int n;
	if (!scanf("%d", &n)) exit(1);
	for (int i=0;i<n;i++) {
		int data;
		printf("Unesite %d. element liste: ", i+1);
		if (!scanf("%d", &data)) exit(1);
		Node* node = getNode(data, NULL, NULL);
		if (!head) head = node;
		else {
			tail->next = node;
			node->prev = tail;
		}
		tail = node;
	}
	start->data = n;
	start->prev = NULL;
	start->next = head;
	tail->next = head;
	head->prev = tail;
	return start;
}

void printForward(Node* start)
{
	Node* head = start;
	head = head->next;
	Node* temp = head;
	printf("%d ", temp->data);
	temp = temp->next;
	while (temp != head) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void printBackward(Node* start)
{
	Node* head = start;
	head = head->next;
	Node* temp = head, *tail = head->prev;
	while (temp != tail) {
		temp = temp->next;
	}
	printf("%d ", temp->data);
	temp = temp->prev;
	while (temp != tail) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
}

Node* freeList(Node* start)
{
	Node* head = start;
	head = head->next;
	Node* temp = head;
	Node* p = NULL;
	Node* tail = head->prev;
	head->prev = NULL;
	tail->next = NULL;
	while (temp) {
		p = temp;
		temp = temp->next;
		free(p);
	}
	free(start);
	printf("Uspesno dealociranje.");
}

int main()
{
	Node* start = NULL;
	start = formList();
	printForward(start);
	printBackward(start);
	start = freeList(start);
	return 0;
}