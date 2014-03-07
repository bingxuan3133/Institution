#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <malloc.h>

void setUp() {}
void tearDown() {}

void test_Institution_reverse_should_reverse_2_Institution_elements() {
	Institution institution1;
	Institution institution2;
	
	LinkedList list;
	LinkedList reversedList;
	
	list.head = &institution1;
	list.tail = &institution2;
	
	int numberOfElement;
	
	// Expect parameter of mock
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);
	
	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution2);
	List_addTail_Expect(&reversedList, &institution2);
	
	Stack_pop_ExpectAndReturn(&stack, &institution1);
	List_addTail_Expect(&reversedList, &institution1);

	// Call function
	numberOfElement = Institution_reverse(&list, &reversedList);
	
	TEST_ASSERT_EQUAL(2, numberOfElement);
}

void test_Institution_reverse_should_reverse_3_Institution_elements() {
	Institution institution1;
	Institution institution2;
	Institution institution3;
	
	LinkedList list;
	LinkedList reversedList;
	
	list.head = &institution1;
	list.tail = &institution3;
	
	int numberOfElement;

	// Expect parameter of mock
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);
	
	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);
	Stack_push_Expect(&stack, &institution3);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution3);
	List_addTail_Expect(&reversedList, &institution3);
	
	Stack_pop_ExpectAndReturn(&stack, &institution2);
	List_addTail_Expect(&reversedList, &institution2);
	
	Stack_pop_ExpectAndReturn(&stack, &institution1);
	List_addTail_Expect(&reversedList, &institution1);

	// Call function
	numberOfElement = Institution_reverse(&list, &reversedList);
	
	TEST_ASSERT_EQUAL(3, numberOfElement);
}

void test_isUniversityCollege_should_return_1_if_same_type() {
	Institution institution1 = {.type = Unknown};
	Institution institution2 = {.type = College};
	
	InstitutionType instType = Unknown;
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution1, &instType));
	
	instType = College;
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution2, &instType));

}