#include "Institution.h"
#include "LinkedList.h"
#include "Stack.h"
#include "CException.h"
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
	Institution *temp;
	int countElement = 0;
	int i;
	
	if(inputList->head == NULL) {
		return 0;
	}
	
	while((temp = (Institution *)List_removeHead(inputList)) != NULL) { // Check & assign removed element pointer to temp at the same time
		Stack_push(&stack, temp);
		countElement++; // Count the element pushed into the stack
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
	void *temp;
	int countElement = 0;
	int i;
	
	while((temp = List_removeHead(inputList)) != NULL){ // Check & assign removed element pointer to temp at the same time
		if(compare(temp, criterion)) {
			Stack_push(&stack, temp);
			countElement++; // Count the element pushed into the stack
		}
	}
	
	for(i = 0; i < countElement; i++) {
		temp = Stack_pop(&stack);
		List_addTail(outputList, temp);
	}

	return countElement;
}
	
int isUniversityCollege(void *elem1, void *type) {
	Institution *institution = (Institution *) elem1;
	InstitutionType *institutionType = (InstitutionType *) type;

	if(institution->type == *institutionType)
		return 1;
	else
		return 0;
}


int wasEstablishedBefore(void *elem1, void *year) {
	Institution *institution = (Institution *) elem1;
	
	if (institution->yearEstablished > 2014) {
		Throw(ERROR_INVALID_YEAR);
	} else {
		if(institution->yearEstablished < *(int *)year)	
			return 1;
		else
			return 0;
	}
}