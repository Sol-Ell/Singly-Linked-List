/**
 * Name        : LinkedList.h
 * Author      : Jamshed
 * Version     : 0.1
 * Copyright   : GNU General Public License v3.0
 * Description : An implementation of Singly Linked List in C.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedList {
	void*              value;
	struct LinkedList* next;
};

typedef struct LinkedList LinkedList;

LinkedList* LinkedListNew       (                   void* value );
size_t      LinkedListGetLength ( LinkedList* node              );
LinkedList* LinkedListGetLast   ( LinkedList* node              );
LinkedList* LinkedListPushFront ( LinkedList* node, void* value );
LinkedList* LinkedListPushBack  ( LinkedList* node, void* value );

void        LinkedListDelete    ( LinkedList* node, void ( *freeValue )( void* ) );

#endif 
