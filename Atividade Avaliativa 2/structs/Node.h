#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Product.h"

struct node{
	Product data;
    struct node *next;
};
typedef struct node Node;

Node* initialize();

int length(Node* node);

int isEmpty(Node* node);

Node* createNode(Product data);

void printList(Node *node);

Node* initialInsert(Product data, Node* node);

Node* finalInsert(Product data, Node* node);

Node* middleInsert(Product data, Node* node);

Node* insertAscOrder(Product data, Node* node);

Node* removeNodeByTitle(Node *node, char title[]);

Node* destroy(Node *node);

#endif // NODE_H_INCLUDED
