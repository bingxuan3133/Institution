#include "Institution.h"
#include "LinkedList.h"
#include "Stack.h"
#include <malloc.h>
#include <stdio.h>

Stack stack;

/**
 * Reverse the order of element
 * Input:
 * 		inputList	is a list of institutions
 *		outputList	is a list of institutions in reversed order
 * Return:
 *		the number of element reversed
 */
int Institution_reverse(LinkedList *inputList, LinkedList *outputList) {
	void *temp;
	int countElement = 0;
	int i;
	
	if(inputList->head == NULL) {
		return 0;
	}
	
	while((temp = List_removeHead(inputList)) != NULL){
		Stack_push(&stack, temp);
		countElement++;
	}
	
	for(i = 0; i < countElement; i++) {
		temp = Stack_pop(&stack);
		List_addTail(outputList, temp);
	}
	
	return countElement;
}

int Institution_select(LinkedList *inputList,
						LinkedList *outputList,
						void *criterion,
						int (*compare)(void *, void *)) {
	
	return 0;
}
	
int isUniversityCollege(void *elem1, void *type) {
	Institution *institution = (Institution *) elem1;
	InstitutionType institutionType = (InstitutionType) type;
	
	printf("institutionType: %d\n", institutionType);
	
	if(institution->type == institutionType)
		return 1;
	else
		return 0;
}