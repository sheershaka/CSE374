// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include "mem.h"
#include "mem_impl.h"

// Check for possible problems with the free list data structure
// Blocks are ordered with strictly increasing memory addresses
// Block sizes are positive numbers and no smaller than whatever 
// 		minimum size you are using in your implementation
// Blocks do not overlap
// Blocks are not touching
void check_heap() {
	FreeList * temp = list->next;
	while (temp != NULL && temp->next != NULL) {
		// check if blocks are ordered
		assert((uintptr_t)temp < (uintptr_t)temp->next);
		// check if block sizes are positive
		assert(temp->size >= MIN_SIZE);

		uintptr_t end = (uintptr_t)temp + temp->size + sizeof(FreeList);
		// check if blocks are overlapping
		assert(end < (uintptr_t)temp->next);
		// check if blocks are touching
		assert(end != (uintptr_t)temp->next);
		// go to next 
		temp = temp->next;
	}
}