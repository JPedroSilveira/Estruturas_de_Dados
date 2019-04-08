#ifndef NODETEST_H_INCLUDED
#define NODETEST_H_INCLUDED

void runNodeTests();

void addFailure(char functionName[], int *failure);

int emptyNodeTest();

int createNodeTest();

int initialInsertTest();

int initialInsertWithEmptyListTest();

int finalInsertTest();

int finalInsertWithEmptyListTest();

int middleInsertInAListOfTwoTest();

int middleInsertInAListOfThreeTest();

int middleInsertInAListOfZeroTest();

int removeNodeByTitleWithAListOfOneElementTest();

int removeNodeByTitleWithAListOfTwoElementsTest();

int removeNodeByTitleWithAListOfThreeElementsTest();

int removeNodeByTitleWithAListOfFiveElementsTest();

int insertAscOrderInAListEmptyList();

int insertAscOrderInAListWithOneBiggerElement();

int insertAscOrderInAListWithASmallerAndABiggerElement();

int insertInAscOrderFourElementsWithoutOrderInAEmptyList();

int insertABiggerNumberInAListWithSmallers();

int createOrderedListWithFourNodes();

#endif // NODETEST_H_INCLUDED
