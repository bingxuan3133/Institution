#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "CException.h"

void setUp() {}
void tearDown() {}

void test_Institution_reverse_should_reverse_2_Institution_elements() {
	Institution institution1;
	Institution institution2;
	
	LinkedList list;
	LinkedList reversedList;

	int numberOfElement;
	
	// Mocking
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
	
	int numberOfElement;

	// Mocking
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
	
	InstitutionType instType;
	
	instType = Unknown;
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution1, &instType));
	
	instType = College;
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution2, &instType));
}

void test_isUniversityCollege_should_return_0_if_different_type() {
	Institution institution1 = {.type = Unknown};
	Institution institution2 = {.type = College};
	
	InstitutionType instType = UniversityCollege;
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution1, &instType));
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institution2, &instType));
}

void test_Institution_select_only_select_the_UniversityCollege_type_of_institution() {
	Institution institution1 = {.type = Unknown};
	Institution institution2 = {.type = University};
	Institution institution3 = {.type = UniversityCollege};
	Institution institution4 = {.type = College};
	
	LinkedList list;
	LinkedList selectedList;
	InstitutionType instType = UniversityCollege;
	
	int numberOfElement;
	
	// Mocking
	// Expecting only institution3 will be stored in the stack
	List_removeHead_ExpectAndReturn(&list, &institution1);
	
	List_removeHead_ExpectAndReturn(&list, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);
	Stack_push_Expect(&stack, &institution3);
	
	List_removeHead_ExpectAndReturn(&list, &institution4);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution3);
	List_addTail_Expect(&selectedList, &institution3);
	
	// Call Function
	numberOfElement = Institution_select(&list,
										&selectedList,
										&instType,
										isUniversityCollege);
	
	TEST_ASSERT_EQUAL(1, numberOfElement);
}

void test_Institution_select_only_select_the_College_type_of_institution() {
	Institution institution1 = {.type = College};
	Institution institution2 = {.type = College};
	Institution institution3 = {.type = UniversityCollege};
	Institution institution4 = {.type = College};
	
	LinkedList list;
	LinkedList selectedList;
	InstitutionType instType = College;
	
	int numberOfElement;
	
	// Mocking
	// Expecting only institution1, institution2, institution4 will be stored in the stack
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);

	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);

	List_removeHead_ExpectAndReturn(&list, &institution4);
	Stack_push_Expect(&stack, &institution4);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution4);
	List_addTail_Expect(&selectedList, &institution4);
	Stack_pop_ExpectAndReturn(&stack, &institution2);
	List_addTail_Expect(&selectedList, &institution2);
	Stack_pop_ExpectAndReturn(&stack, &institution1);
	List_addTail_Expect(&selectedList, &institution1);

	// Call Function
	numberOfElement = Institution_select(&list,
										&selectedList,
										&instType,
										isUniversityCollege);
	
	TEST_ASSERT_EQUAL(3, numberOfElement);
}

void test_wasEstablishedBefore_should_return_1_if_the_institution_was_established_before_year_1980() {
	Institution institution1 = {.yearEstablished = 1900};
	Institution institution2 = {.yearEstablished = 1979};
	Institution institution3 = {.yearEstablished = 1945};
	
	int year = 1980;

	TEST_ASSERT_EQUAL(1, wasEstablishedBefore(&institution1, &year));
	TEST_ASSERT_EQUAL(1, wasEstablishedBefore(&institution2, &year));
	TEST_ASSERT_EQUAL(1, wasEstablishedBefore(&institution3, &year));
}

void test_wasEstablishedBefore_should_return_0_if_the_institution_was_established_at_year_or_after_year_1980() {
	Institution institution1 = {.yearEstablished = 1980};
	Institution institution2 = {.yearEstablished = 1993};
	Institution institution3 = {.yearEstablished = 2013};
	
	int year = 1980;

	TEST_ASSERT_EQUAL(0, wasEstablishedBefore(&institution1, &year));
	TEST_ASSERT_EQUAL(0, wasEstablishedBefore(&institution2, &year));
	TEST_ASSERT_EQUAL(0, wasEstablishedBefore(&institution3, &year));
}

void test_wasEstablishedBefore_should_should_throw_an_exception_if_the_institution_was_established_after_year_2014() {
	Institution institution1 = {.yearEstablished = 2015};
	
	int year = 1980;
	int result;
	
	int e;
	
	Try {
		result = wasEstablishedBefore(&institution1, &year);
	} Catch(e) {
		TEST_ASSERT_EQUAL(ERROR_INVALID_YEAR, e); // Will be caught because have error
	}
}

void test_wasEstablishedBefore_should_should_not_throw_an_exception_if_the_institution_was_established_at_year_or_before_year_2014() {
	Institution institution1 = {.yearEstablished = 2014};
	
	int year = 1980;
	int result;
	
	int e;
	
	Try {
		result = wasEstablishedBefore(&institution1, &year);
	} Catch(e) {
		TEST_ASSERT_EQUAL(ERROR_INVALID_YEAR, e); // Will not been caught because do not have error
	}
	
	TEST_ASSERT_EQUAL(0, result); // return 0 because it is not established before 1980
}

void test_Institution_select_only_select_the_institution_established_before_year_1980() {
	Institution institution1 = {.yearEstablished = 1970};
	Institution institution2 = {.yearEstablished = 1963};
	Institution institution3 = {.yearEstablished = 2013};
	Institution institution4 = {.yearEstablished = 1979};
	
	LinkedList list;
	LinkedList selectedList;
	
	int year = 1980;
	int result;
	
	int numberOfElement;
	
	// Mocking
	// Expecting only institution1, institution2, institution4 will be stored in the stack
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);

	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);

	List_removeHead_ExpectAndReturn(&list, &institution4);
	Stack_push_Expect(&stack, &institution4);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution4);
	List_addTail_Expect(&selectedList, &institution4);
	Stack_pop_ExpectAndReturn(&stack, &institution2);
	List_addTail_Expect(&selectedList, &institution2);
	Stack_pop_ExpectAndReturn(&stack, &institution1);
	List_addTail_Expect(&selectedList, &institution1);

	// Call Function
	numberOfElement = Institution_select(&list,
										&selectedList,
										&year,
										wasEstablishedBefore);
	
	TEST_ASSERT_EQUAL(3, numberOfElement);
}

void test_Institution_select_will_throw_an_exception_if_one_of_the_institution_was_established_after_year_2014() {
	Institution institution1 = {.yearEstablished = 1970};
	Institution institution2 = {.yearEstablished = 1963};
	Institution institution3 = {.yearEstablished = 2015};
	Institution institution4 = {.yearEstablished = 1979};
	
	LinkedList list;
	LinkedList selectedList;
	
	int year = 1980;
	int result;
	
	int e;
	
	int numberOfElement;
	
	// Mocking
	// Expecting only institution1, institution2, institution4 will be stored in the stack
	// But since institution3 has an invalid established year, program will be stop in the halfway when an exception was thrown
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);

	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);
	// End because of an exception has thrown

	// Call Function
	Try {
		numberOfElement = Institution_select(&list,
											&selectedList,
											&year,
											wasEstablishedBefore);
	} Catch (e) {
		TEST_ASSERT_EQUAL(ERROR_INVALID_YEAR, e);
	}
}

void test_Institution_select_will_not_throw_an_exception_if_none_of_the_institution_was_established_after_year_2014() {
	Institution institution1 = {.yearEstablished = 1970};
	Institution institution2 = {.yearEstablished = 1963};
	Institution institution3 = {.yearEstablished = 2014};
	Institution institution4 = {.yearEstablished = 1979};
	
	LinkedList list;
	LinkedList selectedList;
	
	int year = 1980;
	int result;
	
	int e;
	
	int numberOfElement;
	
	// Mocking
	// Expecting only institution1, institution2, institution4 will be stored in the stack
	List_removeHead_ExpectAndReturn(&list, &institution1);
	Stack_push_Expect(&stack, &institution1);

	List_removeHead_ExpectAndReturn(&list, &institution2);
	Stack_push_Expect(&stack, &institution2);
	
	List_removeHead_ExpectAndReturn(&list, &institution3);

	List_removeHead_ExpectAndReturn(&list, &institution4);
	Stack_push_Expect(&stack, &institution4);
	
	List_removeHead_ExpectAndReturn(&list, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution4);
	List_addTail_Expect(&selectedList, &institution4);
	Stack_pop_ExpectAndReturn(&stack, &institution2);
	List_addTail_Expect(&selectedList, &institution2);
	Stack_pop_ExpectAndReturn(&stack, &institution1);
	List_addTail_Expect(&selectedList, &institution1);

	// Call Function
	Try {
		numberOfElement = Institution_select(&list,
											&selectedList,
											&year,
											wasEstablishedBefore);
	} Catch (e) {
		TEST_ASSERT_EQUAL(ERROR_INVALID_YEAR, e);
	}
	
	TEST_ASSERT_EQUAL(3, numberOfElement);
}