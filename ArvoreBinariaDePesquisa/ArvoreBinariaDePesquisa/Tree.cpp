#include "stdafx.h"

Node * initialize()
{
	return NULL;
}

Node * createNode(int data)
{
	Node * newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->right = initialize();
	newNode->left = initialize();
	newNode->balanceFactor = 0;

	return newNode;
}

int isEmpty(Node * node)
{
	return node == NULL;
}

int equals(Node * fnode, Node * snode)
{
	if (!isEmpty(fnode) && !isEmpty(snode)) {
		return fnode->data == snode->data;
	}
	else {
		return FALSE;
	}
}

int getModule(int value) {
	if (value < 0) {
		return value * -1;
	}
	return value;
}

int treeLength(Node * mother, int count) {
	if (!isEmpty(mother)) {
		return treeLength(mother->left, count) + treeLength(mother->right, count) + 1;
	}
	return count;
}

int treeHeight(Node * mother) {
	if (!isEmpty(mother)) {
		int leftHeight = treeHeight(mother->left);
		int rightHeight = treeHeight(mother->right);

		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
	return 0;
}

void treeBalanceCalculator(Node * mother)
{
	if (!isEmpty(mother)) {
		treeBalanceCalculator(mother->left);
		treeBalanceCalculator(mother->right);

		int leftLength = treeHeight(mother->left);
		int rightLength = treeHeight(mother->right);

		mother->balanceFactor = rightLength - leftLength;
	}
}

int getTreeBalanceFactor(Node * mother) 
{
	if (!isEmpty(mother)) {
		int leftTreeBF = getModule(getTreeBalanceFactor(mother->left));
		int rightTreeBG = getModule(getTreeBalanceFactor(mother->right));
		int motherBF = getModule(mother->balanceFactor);

		if (motherBF > leftTreeBF && motherBF > rightTreeBG) {
			return motherBF;
		} 
		else if (rightTreeBG > leftTreeBF && rightTreeBG > motherBF) {
			return rightTreeBG;
		}
		else {
			return leftTreeBF;
		}
	}

	return 0;
}

int hasDaughter(Node * mother)
{
	return hasDaughter(mother, NULL);
}

int hasDaughter(Node * mother, int * status)
{
	if (!isEmpty(mother->left) && !isEmpty(mother->right)) {
		if (status != NULL) {
			*status = HAS_TWO_DAUGHTERS;
		}
		return TRUE;
	}
	else if (!isEmpty(mother->left)) {
		if (status != NULL) {
			*status = HAS_ONLY_LEFT_DAUGHTER;
		}
		return TRUE;
	}
	else if (!isEmpty(mother->right)) {
		if (status != NULL) {
			*status = HAS_ONLY_RIGHT_DAUGHTER;
		}
		return TRUE;
	}
	else {
		if (status != NULL) {
			*status = HAS_NOT_DAUGHTER;
		}
		return FALSE;
	}
}

int isMother(Node * daughter, Node * mother)
{
	return equals(daughter, mother->left) || equals(daughter, mother->right);
}

void printCentral(Node * node)
{
	if (!isEmpty(node))
	{
		printCentral(node->left);
		printf("%d\n", node->data);
		printCentral(node->right);
	}
}

void printPosFixed(Node * node)
{
	if (!isEmpty(node))
	{
		printPosFixed(node->left);
		printPosFixed(node->right);
		printf("%d\n", node->data);
	}
}

void printPreFixed(Node * node)
{
	if (!isEmpty(node))
	{
		printf("%d\n", node->data);
		printPreFixed(node->left);
		printPreFixed(node->right);
	}
}

void amazingPrint(Node * mother, int level) {
	if (!isEmpty(mother)) {
		for (int x = 0; x < level; x++) {
			printf("=");
		}
		printf("%d \n", mother->data);
		amazingPrint(mother->left, level + 1);
		amazingPrint(mother->right, level + 1);
	}	
}

int leftInsert(Node ** mother, Node * daughter)
{
	if (!isEmpty(*mother)) {
		(*mother)->left = daughter;
		return SUCCESS;
	}
	return FAILURE;
}

int rightInsert(Node ** mother, Node * daughter)
{
	if (!isEmpty(*mother)) {
		(*mother)->right = daughter;
		return SUCCESS;
	}
	return FAILURE;
}

int insert(int data, Node ** antecedent)
{
	Node * newNode = createNode(data);

	if (isEmpty(*antecedent)) {
		*antecedent = newNode;
	}
	else {
		int status;
		Node * mother = findPossibleMother(newNode, *antecedent, &status);

		if(status == IS_RIGHT_DAUGHTER || status == IS_LEFT_DAUGHTER) {
			return FAILURE;
		} if (status == POSSIBLE_RIGHT_DAUGHTER) {
			rightInsert(&mother, newNode);
		} if (status == POSSIBLE_LEFT_DAUGHTER) {
			leftInsert(&mother, newNode);
		}
	}

	return SUCCESS;
}

Node * findPossibleMother(Node * daughter, Node * antecedent, int * status) {
	if (isEmpty(antecedent)) {
		return antecedent;
	}
	if (isMother(daughter, antecedent)) {
		if (daughter->data > antecedent->data) {
			*status = IS_RIGHT_DAUGHTER;
		}
		else {
			*status = IS_LEFT_DAUGHTER;
		}
		return antecedent;
	}
	else if (daughter->data > antecedent->data) {
		*status = POSSIBLE_RIGHT_DAUGHTER;
		if (isEmpty(antecedent->right)) {
			return antecedent;
		}
		return findPossibleMother(daughter, antecedent->right, status);
	}
	else {
		*status = POSSIBLE_LEFT_DAUGHTER;
		if (isEmpty(antecedent->left)) {
			return antecedent;
		}
		return findPossibleMother(daughter, antecedent->left, status);
	}
}

Node * findSuccessor(Node * node) {
	if (isEmpty(node)) {
		return NULL;
	}
	else if (isEmpty(node->left)) {
		return node;
	}
	else {
		return findSuccessor(node->left);
	}
}

Node * find(int data, Node * antecedent)
{
	if (isEmpty(antecedent)) {
		return NULL;
	}
	else if (antecedent->data == data) {
		return antecedent;
	}
	else if (data > antecedent->data) {
		return find(data, antecedent->right);
	}
	else {
		return find(data, antecedent->left);
	}
}

int deleteNode(Node * daughter, Node * antecedent)
{
	if (!isEmpty(daughter)) {
		int daughterStatus;
		int motherStatus;
		Node * mother = findPossibleMother(daughter, antecedent, &motherStatus);

		if (hasDaughter(daughter, &daughterStatus)) {
			if (daughterStatus == HAS_ONLY_LEFT_DAUGHTER) {
				if (motherStatus == IS_LEFT_DAUGHTER) {
					mother->left = daughter->left;
				}
				else if (motherStatus == IS_RIGHT_DAUGHTER){
					mother->right = daughter->left;
				}
				else {
					daughter->data = daughter->left->data;
				}
			}
			else if (daughterStatus == HAS_ONLY_RIGHT_DAUGHTER) {
				if (motherStatus == IS_LEFT_DAUGHTER) {
					mother->left = daughter->right;
				}
				else if (motherStatus == IS_RIGHT_DAUGHTER) {
					mother->right = daughter->left;
				}
				else {
					daughter->data = daughter->right->data;
				}
			}
			else {
				int successorMotherStatus = 0;
				Node * successor = findSuccessor(daughter);
				Node * successorMother = findPossibleMother(successor, antecedent, &successorMotherStatus);
				daughter->data = successor->data;

				if (successorMotherStatus == IS_LEFT_DAUGHTER) {
					successorMother->left = NULL;
				}
				else {
					successorMother->right = NULL;
				}
				destroy(&successor);
			}
		}
		else {
			if (motherStatus == IS_LEFT_DAUGHTER) {
				mother->left = initialize();
			}
			else if (motherStatus == IS_RIGHT_DAUGHTER) {
				mother->right = initialize();
			}
			destroy(&daughter);
		}

		return 0;
	}
	
}

int deleteNode(int data, Node * antecedent) {
	return deleteNode(find(data, antecedent), antecedent);
}

int destroy(Node ** node)
{
	if (!isEmpty(*node))
	{
		destroy(&((*node)->left));
		destroy(&((*node)->right));
		free(*node);
		*node = NULL;
		return SUCCESS;
	}
	return FAILURE;
}