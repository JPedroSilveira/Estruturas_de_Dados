#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Node.h"
#include "Product.h"

Node* initialize(){
    return NULL;
}

int listLength(Node* node){
    int count = 0;

    if(!isEmpty(node)){
        count++;
        while(node->next){
            count++;
            node = node->next;
        }
    }

    return count;
}

int isEmpty(Node* node){
    return !node;
}

Node* createNode(Product data, Node *next, Node *previous){
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = next;
    newNode->previous = previous;
    return newNode;
}

Node* getLastNode(Node *node){
    Node *nodeAux = node;
    while(!isEmpty(nodeAux->next)){
        nodeAux = nodeAux->next;
    }

    return nodeAux;
}

void printList(Node *node){
    if(isEmpty(node)){
        puts("Lista vazia!");
    } else {
        Node *nodeAux;
        for(nodeAux = node; nodeAux != NULL; nodeAux = nodeAux->next){
            printf("Codigo = %d - Nome = %s - Preço = %f. \n", nodeAux->data.code, nodeAux->data.name, nodeAux->data.price);
        }
    }
}

void printListReverse(Node *node){
    if(isEmpty(node)){
        puts("Lista vazia!");
    } else {
        Node *nodeAux = getLastNode(node);

        while(!isEmpty(nodeAux)){
            printf("Codigo = %d - Nome = %s - Preço = %f. \n", nodeAux->data.code, nodeAux->data.name, nodeAux->data.price);
            nodeAux = nodeAux->previous;
        }
    }
}

void recursivePrint(Node *node){
    if(!isEmpty(node)){
        printf("Codigo = %d - Nome = %s - Preço = %f. \n", node->data.code, node->data.name, node->data.price);
        recursivePrint(node->next);
    }
}

void linkNodes(Node *fNode, Node *sNode){
    fNode->next = sNode;
    sNode->previous = fNode;
}

Node* initialInsert(Product data, Node* node){
    Node *newNode = createNode(data, node, NULL);

    if(!isEmpty(node)){
        node->previous = newNode;
    }

    return newNode;
}

Node* finalInsert(Product data, Node* node){
    Node *newNode = createNode(data, NULL, NULL);

    if(isEmpty(node)){
        node = newNode;
    } else {
        Node *nodeAux = node;

        while(nodeAux->next){
            nodeAux = nodeAux->next;
        }

        linkNodes(nodeAux, newNode);
    }

    return node;
}

Node* middleInsert(Product data, Node* node){
    Node *newNode = createNode(data, NULL, NULL);

    if(isEmpty(node)){
        node = newNode;
    } else {
        Node *nodeAux = node;

        int middle = abs((listLength(nodeAux) + 1)/2);

        for(int count = 1; count != middle; count++){
            nodeAux = nodeAux->next;
        }

        linkNodes(newNode, nodeAux->next);

        linkNodes(nodeAux, newNode);
    }

    return node;
}

Node* insertAscOrder(Product data, Node* node){
    Node *newNode = createNode(data, NULL, NULL);

    if(isEmpty(node)){
        return newNode;
    }

    Node *nodeAux = node;
    Node *previous = initialize();

    while(!isEmpty(nodeAux) && nodeAux->data.code <= data.code){
        previous = nodeAux;
        nodeAux = nodeAux->next;
    }

    if(isEmpty(previous)){
        linkNodes(newNode, nodeAux);
        node = newNode;
    }else{
        if(!isEmpty(nodeAux)){
            linkNodes(newNode, nodeAux);
        }

        linkNodes(previous, newNode);
    }

    return node;
}


Node* removeNodeByName(Node *node, char name[]){
    if(isEmpty(node)){
        return node;
    }

    Node *previous = initialize();
    Node *nodeAux = node;

    while(!isEmpty(nodeAux) && strcmp(nodeAux->data.name, name)){
        previous = nodeAux;
        nodeAux = nodeAux->next;
    }

    if(!isEmpty(previous)){
        if(!isEmpty(nodeAux->next)){
            linkNodes(previous, nodeAux->next);
        } else {
            previous->next = initialize();
        }

        free(nodeAux);

        return node;
    } else {
        node = nodeAux->next;
        free(nodeAux);
        return node;
    }
}

Node* destroy(Node *node){
    Node* nodeAux;

    while(!isEmpty(node)){
        nodeAux = node;
        node = node->next;
        free(nodeAux);
    }

    return node;
}
