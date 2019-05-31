#include <stdio.h>
#include <stdlib.h> 

#pragma once

const int IS_RIGHT_DAUGHTER = 0;
const int IS_LEFT_DAUGHTER = 1;
const int POSSIBLE_RIGHT_DAUGHTER = 3;
const int POSSIBLE_LEFT_DAUGHTER = 4;
const int SUCCESS = 1;
const int FAILURE = 0;
const int HAS_TWO_DAUGHTERS = 1;
const int HAS_ONLY_LEFT_DAUGHTER = 2;
const int HAS_ONLY_RIGHT_DAUGHTER = 3;
const int HAS_NOT_DAUGHTER = 4;

struct node {
	int data;
	int balanceFactor;
	struct node * right;
	struct node * left;
};
typedef struct node Node;

Node * initialize();

Node * createNode(int data);

int isEmpty(Node * node);

int equals(Node * fnode, Node * snode);

int treeLength(Node * mother, int count);

int treeHeight(Node * mother);

void treeBalanceCalculator(Node * mother);

int getTreeBalanceFactor(Node * mother);

int hasDaughter(Node * mother);

int hasDaughter(Node * mother, int * status);

int isMother(Node * daughter, Node * antecedent);

void printCentral(Node * node);

void printPosFixed(Node * node);

void printPreFixed(Node * node);

void amazingPrint(Node * mother, int level);

int leftInsert(Node ** mother, Node * daughter);

int rightInsert(Node ** mother, Node * daughter);

int insert(int data, Node ** antecedent);

Node * findPossibleMother(Node * daughter, Node * antecedent, int * status);

Node * find(int data, Node * antecedent);

int deleteNode(Node * daughter, Node * antecedent);

int deleteNode(int data, Node * antecedent);

int destroy(Node ** node);
