#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Node.h"
#include "Product.h"

Node* initialize(){
    return NULL;
}

int length(Node* node){
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

Node* createNode(Product data){
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = initialize();
    return newNode;
}

void printList(Node *node){
    Node *nodeAux;
    if(isEmpty(node)){
        puts("Lista vazia!");
    } else {
        for(nodeAux = node; nodeAux != NULL; nodeAux = nodeAux->next){
            printf("Codigo = %d - Nome = %s - Preço = %f. \n", nodeAux->data.code, nodeAux->data.name, nodeAux->data.price);
        }
    }
}

Node* initialInsert(Product data, Node* node){
    Node *newNode = createNode(data);
    newNode->next = node;

    return newNode;
}

Node* finalInsert(Product data, Node* node){
    Node *newNode = createNode(data);

    if(isEmpty(node)){
        node = newNode;
    } else {
        Node *nodeAux = node;

        while(nodeAux->next){
            nodeAux = nodeAux->next;
        }

        nodeAux->next = newNode;
    }

    return node;
}

Node* middleInsert(Product data, Node* node){
    Node *newNode = createNode(data);

    if(isEmpty(node)){
        node = newNode;
    } else {
        Node *nodeAux = node;

        int middle = abs((length(nodeAux) + 1)/2);

        for(int count = 1; count != middle; count++){
            nodeAux = nodeAux->next;
        }

        newNode->next = nodeAux->next;
        nodeAux->next = newNode;
    }

    return node;
}

Node* insertAscOrder(Product data, Node* node){
    Node *newNode = createNode(data);

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
        newNode->next = nodeAux;
        node = newNode;
    }else{
        newNode->next = nodeAux;
        previous->next = newNode;
    }

    return node;
}


Node* removeNodeByTitle(Node *node, char name[]){
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
        previous->next = nodeAux->next;
        free(nodeAux);
        return node;
    } else {
        node = nodeAux->next;
        free(nodeAux);
        return node;
    }
}

Node* destroy(Node *node){
    Node *nodeAux;

    while(!isEmpty(nodeAux)){
        nodeAux = node;
        node = node->next;
        free(nodeAux);
    }

    return node;
}
