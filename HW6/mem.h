// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6
// header file

#include "mem_impl.h"

#ifndef MEM_H
#define MEM_H

#define MIN_SIZE 32
#define MAX_SIZE 12000

// Global variables
FreeList* list;
uintptr_t totalsize;

// Return a pointer to a new block of storage with at least size bytes of memory.
void* getmem(uintptr_t size);

// Return the block of storage at location p to the pool of available free storage.
void freemem(void* p);

// Store statistics about the current state of the memory manager in the three 
// 		integer variables whose addresses are given as arguments.
// total_size: the total amount requested from the underlying system
// total_free: the total amount of storage in bytes that is currently stored on the free list,
// 		including any space occupied by header information or links in the free blocks.
// n_free_blocks: the total number of individual blocks currently stored on the free list.
void get_mem_stats(
  uintptr_t* total_size,
  uintptr_t* total_free,
  uintptr_t* n_free_blocks);

// Print a formatted listing on file f showing the blocks on the free list.
void print_heap(FILE * f);

#endif