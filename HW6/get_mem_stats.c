// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include "mem.h"
#include "mem_impl.h"

// Store statistics about the current state of the memory manager
// in the three integer variables whose addresses are given as arguments.
// total_size: the total amount requested from the underlying system
// total_free: the total amount of storage in bytes that is currently stored on the free list,
// 		including any space occupied by header information or links in the free blocks.
// n_free_blocks: the total number of individual blocks currently stored on the free list.
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks) {
	uintptr_t* totalfree = 0;
	uintptr_t* nfreeblocks = 0;
	FreeList* temp = list;
	while(temp != NULL) {
		totalfree = totalfree + temp->size;
		nfreeblocks++;
		temp = temp->next;
	}
	*total_size = totalsize;
	*total_free = totalfree;
	*n_free_blocks = nfreeblocks;
}