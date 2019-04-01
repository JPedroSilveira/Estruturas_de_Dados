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

    if(!removeNodeByTitleWithAListOfOneElementTest()){
        addFailure("removeNodeByTitleWithAListOfOneElementTest", &failure);
    }

    if(!removeNodeByTitleWithAListOfTwoElementsTest()){
        addFailure("removeNodeByTitleWithAListOfTwoElementsTest", &failure);
    }

    printf("RunNodeTests results in %d failures.", failure);
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
    Book book = {"Test", "Test", "Test"};

    Node *node = createNode(book);

    if(!isEmpty(node) && isEmpty(node->next) && !strcmp(node->data.title, book.title) && !strcmp(node->data.distributor, book.distributor) && !strcmp(node->data.director, book.director)){
        return 1;
    }

    return 0;
}

int initialInsertTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};
    Book bookTwo = {"Test 2", "Test 2", "Test 2"};
    Book bookThree = {"Test 3", "Test 3", "Test 3"};

    Node *node = createNode(bookThree);

    node = initialInsert(bookTwo, node);
    node = initialInsert(bookOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)
       && !strcmp(node->next->data.title, bookTwo.title)
       && !strcmp(node->next->next->data.title, bookThree.title)){
        return 1;
    }

    return 0;
}

int initialInsertWithEmptyListTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};

    Node *node = initialize();

    node = initialInsert(bookOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)){
        return 1;
    }

    return 0;
}

int finalInsertTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};
    Book bookTwo = {"Test 2", "Test 2", "Test 2"};
    Book bookThree = {"Test 3", "Test 3", "Test 3"};

    Node *node = createNode(bookOne);

    node = finalInsert(bookTwo, node);
    node = finalInsert(bookThree, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)
       && !strcmp(node->next->data.title, bookTwo.title)
       && !strcmp(node->next->next->data.title, bookThree.title)){
        return 1;
    }

    return 0;
}

int finalInsertWithEmptyListTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};

    Node *node = initialize();

    node = finalInsert(bookOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfTwoTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};
    Book bookTwo = {"Test 2", "Test 2", "Test 2"};
    Book bookThree = {"Test 3", "Test 3", "Test 3"};

    Node *node = createNode(bookOne);

    node = finalInsert(bookThree, node);

    node = middleInsert(bookTwo, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)
       && !strcmp(node->next->data.title, bookTwo.title)
       && !strcmp(node->next->next->data.title, bookThree.title)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfThreeTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};
    Book bookTwo = {"Test 2", "Test 2", "Test 2"};
    Book bookThree = {"Test 3", "Test 3", "Test 3"};
    Book bookFour = {"Test 4", "Test 4", "Test 4"};

    Node *node = createNode(bookOne);

    node = finalInsert(bookTwo, node);
    node = finalInsert(bookFour, node);

    node = middleInsert(bookThree, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)
       && !strcmp(node->next->data.title, bookTwo.title)
       && !strcmp(node->next->next->data.title, bookThree.title)
       && !strcmp(node->next->next->next->data.title, bookFour.title)){
        return 1;
    }

    return 0;
}

int middleInsertInAListOfZeroTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};

    Node *node = initialize();

    node = middleInsert(bookOne, node);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookOne.title)){
        return 1;
    }

    return 0;
}

int removeNodeByTitleWithAListOfOneElementTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};

    Node *node = initialize();

    node = initialInsert(bookOne, node);

    node = removeNodeByTitle(node, bookOne.title);

    if(isEmpty(node)){
        return 1;
    }

    return 0;
}

int removeNodeByTitleWithAListOfTwoElementsTest(){
    Book bookOne = {"Test 1", "Test 1", "Test 1"};
    Book bookTwo = {"Test 2", "Test 2", "Test 2"};

    Node *node = initialize();

    node = initialInsert(bookOne, node);
    node = initialInsert(bookTwo, node);

    node = removeNodeByTitle(node, bookOne.title);

    if(!isEmpty(node)
       && !strcmp(node->data.title, bookTwo.title)){
        return 1;
    }

    return 0;
}
#endif // NODETEST_C_INCLUDED
