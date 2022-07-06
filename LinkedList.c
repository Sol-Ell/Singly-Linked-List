/*
 * SDL_RectArray.c
 * 
 * Author: Jamshed
 */

#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

LinkedList* 
LinkedListNew ( void* value ) {
    /**
     * LinkedListNew : function creates new node
     * param   value : a pointer to the value
     *
     * return        : if allocation succeeds, returns a pointer to crated node, null pointer will be returned.
     */
    return LinkedListPushFront( NULL, value );
}

size_t 
LinkedListGetLength ( LinkedList* node ) {
    size_t length = 0;
    
    while (node != NULL) {
        length++;
        node = node->next;
    }

    return length;
}

LinkedList* 
LinkedListGetLast ( LinkedList* node ) {
    while ( node->next != NULL ) {
        node = node->next;
    }

    return node;
}

LinkedList* 
LinkedListPushFront ( LinkedList* node, void* value ) {
    void* mem = malloc( sizeof( LinkedList ) );
    if ( mem == NULL ) 
        return NULL;

    LinkedList* begin = ( LinkedList* ) mem;

    begin->value = value;
    begin->next  = node;

    return begin;
}

LinkedList* 
LinkedListPushBack ( LinkedList* node, void* value ) {
    node = LinkedListGetLast ( node );

    void* mem = malloc( sizeof( LinkedList ) );
    if ( mem == NULL )
        return  NULL;

    LinkedList* new_one = ( LinkedList* ) mem;
    new_one->value = value;

    node->next = new_one;

    return new_one;
}


void 
LinkedListDelete ( LinkedList* node,  void ( *freeValue )( void* ) ) {
    /**
     * LinkedListDelete: Deletes this and all next nodes. 
     * param  freeValue: Your function that deletes value. 
     */
    LinkedList* next_node = node;
    while ( next_node != NULL ) {
        next_node = node->next;
        freeValue( node->value );
        free     ( node        );
        node = next_node;
    }
}
