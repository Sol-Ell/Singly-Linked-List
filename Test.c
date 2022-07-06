#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

#define TEST_FAILED 0
#define TEST_PASSED 1

_Bool run_tests() {
	int* num1 = malloc ( sizeof ( int ) );
	*num1 = 1;

	LinkedList* list = LinkedListNew ( num1 );
	
	assert ( ( *( (int*)list->value )      == 1 ) && "Test 1 failed!");

	assert ( (LinkedListGetLength ( list ) == 1 ) && "Test 2 failed!");

	int* num2 = malloc ( sizeof ( int ) );
	*num2 = 2;

	LinkedList* last = LinkedListPushBack ( list, num2 );

	assert ( (last == LinkedListGetLast( list )) && "Test 3 failed!");
	assert ( (LinkedListGetLength ( list ) == 2) && "Test 4 failed!");

	LinkedListDelete ( list, free );

	return TEST_PASSED;
}

int main( int argc, char** argv ) {
	assert( run_tests() && "Should pass all test cases!");

	printf ( "All tests were passed!\n" );
	return EXIT_SUCCESS;
}
