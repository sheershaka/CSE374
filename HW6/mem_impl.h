// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6
// header file

#ifndef MEM_IMPL_H
#define MEM_IMPL_H

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

// Struct for the Linked list of free memory
typedef struct FreeList {
	uintptr_t size;
	struct FreeList* next;
} FreeList;

// Check for possible problems with the free list data structure. 
void check_heap();

#endif