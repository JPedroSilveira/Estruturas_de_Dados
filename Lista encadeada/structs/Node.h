#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Book.h"

struct node{
	Book data;
    struct node *next;
};
typedef struct node Node;

Node* initialize();

int length(Node* node);

int isEmpty(Node* node);

Node* createNode(Book data);

void print(Node *node);

Node* initialInsert(Book data, Node* node);

Node* finalInsert(Book data, Node* node);

Node* middleInsert(Book data, Node* node);

Node* removeNodeByTitle(Node *node, char title[]);

Node* destroy(Node *node);

#endif // NODE_H_INCLUDED
