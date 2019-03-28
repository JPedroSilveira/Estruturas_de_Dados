#ifndef NODETEST_C_INCLUDED
#define NODETEST_C_INCLUDED

#include "../structs/Node.h"

void RunNodeTests(){
    int failure = 0;

    if(!EmptyNodeTest()){
        puts("Failure in EmptyNodeTest()");
        failure++;
    }

    if(!CreateNodeTest()){
        puts("Failure in CreateNodeTest()");
        failure++;
    }

    printf("RunNodeTests results in %d failures.", failure);
}

int EmptyNodeTest(){
    Node *node;
    node = initialize();

    return isEmpty(node);
}

int CreateNodeTest(){
    Book book = {"Teste", "Teste", "Teste"};

    Node *node = createNode(book);

    if(!isEmpty(node) && isEmpty(node->next) && !strcmp(node->data.title, book.title) && !strcmp(node->data.distributor, book.distributor) && !strcmp(node->data.director, book.director)){
        return 1;
    } else {
        return 0;
    }
}

#endif // NODETEST_C_INCLUDED
