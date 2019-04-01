#ifndef NODETEST_C_INCLUDED
#define NODETEST_C_INCLUDED

#include "../structs/Node.h"

void runNodeTests(){
    int failure = 0;

    if(!emptyNodeTest()){
        addFailure("emptyNodeTest", &failure);
    }

    if(!createNodeTest()){
        addFailure("createNodeTest", &failure);
    }

    if(!initialInsertTest()){
        addFailure("initialInsertTest", &failure);
    }

    if(!initialInsertWithEmptyListTest()){
        addFailure("initialInsertWithEmptyListTest", &failure);
    }

    if(!finalInsertTest()){
        addFailure("finalInsertTest", &failure);
    }

    if(!finalInsertWithEmptyListTest()){
        addFailure("finalInsertWithEmptyListTest", &failure);
    }

    if(!middleInsertInAListOfTwoTest()){
        addFailure("middleInsertInAListOfTwoTest", &failure);
    }

    if(!middleInsertInAListOfThreeTest()){
        addFailure("middleInsertInAListOfThreeTest", &failure);
    }

    if(!middleInsertInAListOfZeroTest()){
        addFailure("middleInsertInAListOfZeroTest", &failure);
    }

    if(!insertAscOrderInAListEmptyList()){
        addFailure("insertAscOrderInAListEmptyList", &failure);
    }

    if(!insertAscOrderInAListWithOneBiggerElement()){
        addFailure("insertAscOrderInAListWithOneBiggerElement", &failure);
    }

    if(!insertAscOrderInAListWithASmallerAndABiggerElement()){
        addFailure("insertAscOrderInAListWithASmallerAndABiggerElement", &failure);
    }

    if(!insertInAscOrderFourElementsWithoutOrderInAEmptyList()){
        addFailure("insertInAscOrderFourElementsWithoutOrderInAEmptyList", &failure);
    }

    if(!insertABiggerNumberInAListWithSmallers()){
        addFailure("insertABiggerNumberInAListWithSmallers", &failure);
    }

    if(!removeNodeByTitleWithAListOfOneElementTest()){
        addFailure("removeNodeByTitleWithAListOfOneElementTest", &failure);
    }

    if(!removeNodeByTitleWithAListOfTwoElementsTest()){
        addFailure("removeNodeByTitleWithAListOfTwoElementsTest", &failure);
    }

    printf("\nRunNodeTests results in %d failures. \n", failure);
}

void addFailure(char functionName[], int *failure){
    printf("Failure in %s function! \n", functionName);
    (*failure)++;
}

int emptyNodeTest(){
    Node *node;
    node = initialize();

    return isEmpty(node);
}

int createNodeTest(){
    Product product = {1, "Test", 10.0};

    Node *node = createNode(product);

    if(!isEmpty(node) && isEmpty(node->next) && !strcmp(node->data.name, product.name)){
        return 1;
    }

    return 0;
}

int initialInsertTest(){
    Product productOne = {1, "Test", 10.0};
    Product productTwo = {2, "Test 2", 10.0};
    Product productThree = {3, "Test 3", 10.0};

    Node *node = createNode(productThree);

    node = initialInsert(productTwo, node);
    node = initialInsert(productOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)
       && !strcmp(node->next->data.name, productTwo.name)
       && !strcmp(node->next->next->data.name, productThree.name)){
        return 1;
    }

    return 0;
}

int initialInsertWithEmptyListTest(){
    Product product = {1, "Test", 10.0};

    Node *node = initialize();

    node = initialInsert(product, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, product.name)){
        return 1;
    }

    return 0;
}

int finalInsertTest(){
    Product productOne = {1, "Test", 10.0};
    Product productTwo = {2, "Test 2", 10.0};
    Product productThree = {3, "Test 3", 10.0};

    Node *node = createNode(productOne);

    node = finalInsert(productTwo, node);
    node = finalInsert(productThree, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)
       && !strcmp(node->next->data.name, productTwo.name)
       && !strcmp(node->next->next->data.name, productThree.name)){
        return 1;
    }

    return 0;
}

int finalInsertWithEmptyListTest(){
    Product productOne = {1, "Test", 10.0};

    Node *node = initialize();

    node = finalInsert(productOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfTwoTest(){
    Product productOne = {1, "Test", 10.0};
    Product productTwo = {2, "Test 2", 10.0};
    Product productThree = {3, "Test 3", 10.0};

    Node *node = createNode(productOne);

    node = finalInsert(productThree, node);

    node = middleInsert(productTwo, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)
       && !strcmp(node->next->data.name, productTwo.name)
       && !strcmp(node->next->next->data.name, productThree.name)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfThreeTest(){
    Product productOne = {1, "Test", 10.0};
    Product productTwo = {2, "Test 2", 10.0};
    Product productThree = {3, "Test 3", 10.0};
    Product productFour = {4, "Test 4", 10.0};

    Node *node = createNode(productOne);

    node = finalInsert(productTwo, node);
    node = finalInsert(productFour, node);

    node = middleInsert(productThree, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)
       && !strcmp(node->next->data.name, productTwo.name)
       && !strcmp(node->next->next->data.name, productThree.name)
       && !strcmp(node->next->next->next->data.name, productFour.name)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfZeroTest(){
    Product productOne = {1, "Test", 10.0};

    Node *node = initialize();

    node = middleInsert(productOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productOne.name)){
        return 1;
    }

    return 0;
}

int removeNodeByTitleWithAListOfOneElementTest(){
    Product productOne = {1, "Test", 10.0};

    Node *node = initialize();

    node = initialInsert(productOne, node);

    node = removeNodeByTitle(node, productOne.name);

    if(isEmpty(node)){
        return 1;
    }

    return 0;
}

int removeNodeByTitleWithAListOfTwoElementsTest(){
    Product productOne = {1, "Test", 10.0};
    Product productTwo = {2, "Test 2", 10.0};

    Node *node = initialize();

    node = initialInsert(productOne, node);
    node = initialInsert(productTwo, node);

    node = removeNodeByTitle(node, productOne.name);

    if(!isEmpty(node)
       && !strcmp(node->data.name, productTwo.name)){
        return 1;
    }

    return 0;
}

void insertAscOrderInAListEmptyList(){
    Product productOne = {1, "Test 1", 10.0};
    Node *node = initialize();

    node = insertAscOrder(productOne, node);

    printf("Inserir em lista vazia ordenado: \n");
    printList(node);
    printf("\n");

    if(!isEmpty(node) && isEmpty(node->next) && node->data.code == productOne.code) {
        return 1;
    }

    return 0;
}

int insertAscOrderInAListWithOneBiggerElement(){
    Product productOne = {1, "Test 1", 10.0};
    Product productTwo = {2, "Test 2", 10.0};

    Node *node = initialize();

    node = insertAscOrder(productTwo, node);
    node = insertAscOrder(productOne, node);

    printf("Inserir em lista com um elemento maior que o inserido de forma ordenada: \n");
    printList(node);
    printf("\n");

    if(!isEmpty(node) && node->data.code == productOne.code && node->next->data.code == productTwo.code) {
        return 1;
    }

    return 0;
}

int insertAscOrderInAListWithASmallerAndABiggerElement(){
    Product productOne = {1, "Test 1", 10.0};
    Product productTwo = {2, "Test 2", 27.0};
    Product productThree = {3, "Test 3", 15.0};

    Node *node = initialize();

    node = insertAscOrder(productThree, node);
    node = insertAscOrder(productOne, node);
    node = insertAscOrder(productTwo, node);

    printf("Inserir em lista com um elemento maior e um menor de forma ordenada: \n");
    printList(node);
    printf("\n");

    if(!isEmpty(node)
       && node->data.code == productOne.code
       && node->next->data.code == productTwo.code
       && node->next->next->data.code == productThree.code) {
        return 1;
    }

    return 0;
}

int insertInAscOrderFourElementsWithoutOrderInAEmptyList(){
    Product productOne = {1, "Mouse", 90.0};
    Product productTwo = {2, "HD Externo", 300.0};
    Product productThree = {3, "Teclado", 120.0};
    Product productFour = {4, "Pen Drive", 50.0};

    Node *node = initialize();

    node = insertAscOrder(productThree, node);
    node = insertAscOrder(productOne, node);
    node = insertAscOrder(productFour, node);
    node = insertAscOrder(productTwo, node);

    printf("Inserir de forma ordenada crescente em uma lista vazia quatro elementos em desordem: \n");
    printList(node);
    printf("\n");

    if(!isEmpty(node)
       && node->data.code == productOne.code
       && node->next->data.code == productTwo.code
       && node->next->next->data.code == productThree.code
       && node->next->next->next->data.code == productFour.code) {
        return 1;
    }

    return 0;
}

int insertABiggerNumberInAListWithSmallers(){
    Product productOne = {1, "Test 1", 90.0};
    Product productTwo = {2, "Test 2", 300.0};
    Product productThree = {3, "Test 3", 120.0};
    Product productFour = {4, "Test 4", 50.0};
    Product productFive = {5, "Test 5", 70.0};

    Node *node = initialize();

    node = insertAscOrder(productThree, node);
    node = insertAscOrder(productOne, node);
    node = insertAscOrder(productFour, node);
    node = insertAscOrder(productTwo, node);
    node = insertAscOrder(productFive, node);

    printf("Inserir de forma ordenada crescente em uma lista vazia cinco elementos, sendo o maior inserido por último: \n");
    printList(node);
    printf("\n");

    if(!isEmpty(node)
       && node->data.code == productOne.code
       && node->next->data.code == productTwo.code
       && node->next->next->data.code == productThree.code
       && node->next->next->next->data.code == productFour.code
       && node->next->next->next->next->data.code == productFive.code) {
        return 1;
    }

    return 0;
}
#endif // NODETEST_C_INCLUDED
