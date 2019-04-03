#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Product.h"

struct node{
	Product data;
    struct node *next;
    struct node *previous;
};
typedef struct node Node;

Node* initialize();

int length(Node* node);

int isEmpty(Node* node);

void linkNodes(Node *fNode, Node *sNode);

Node* createNode(Product data, Node *next, Node *previous);

void printList(Node *node);

void recursivePrint(Node *node);

Node* initialInsert(Product data, Node* node);

Node* finalInsert(Product data, Node* node);

Node* middleInsert(Product data, Node* node);

Node* insertAscOrder(Product data, Node* node);

Node* removeNodeByName(Node *node, char name[]);

Node* destroy(Node *node);

#endif // NODE_H_INCLUDED
