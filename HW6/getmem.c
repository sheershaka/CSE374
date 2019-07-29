// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include "mem.h"
#include "mem_impl.h"

// Functions
FreeList* searchBlock(uintptr_t size);
FreeList* splitBlock(FreeList* block, uintptr_t size);
FreeList* addBlock(uintptr_t size);

// Returns a pointer to a new block of storage with at least size 
// bytes of memory. The value size must be greater than 0. 
// If size is not positive, or if for some reason getmem cannot 
// satisfy the request, it should return NULL. 
void* getmem(uintptr_t size) {
	// check if size is positive
	if (size <= 0) {
		return NULL;
	}

	// initialize the list and check it
	if (list == NULL) {
		list = (FreeList*) malloc(sizeof(FreeList));
		if (list == NULL) {
			return NULL;
		}
		list->size = 0;
		list->next = NULL;
		totalsize = 0;
	}
	// check_heap();

	// round the size to a multiple of 16 and make sure it is
	// bigger than the minimum block size.
	uintptr_t newSize = (size % 16 == 0) ? size : ((size/16) + 1)*16;
	if (newSize < MIN_SIZE) {
		newSize = MIN_SIZE;
	}

	// search block of given size
	FreeList* block = searchBlock(newSize);

	// if there is no large enough block
	if (block == NULL) {
		// add a big amount of data to the block
		if (newSize > MAX_SIZE) {
			block = addBlock(newSize);
		} else {
			block = addBlock(MAX_SIZE);
		}
		// search block of given size again
		block = searchBlock(newSize);
	}
	void* address = (void*)((uintptr_t)block + sizeof(FreeList));
	// check_heap();
	return address;
}

// adds a huge amount of space in free list and returns it
FreeList* addBlock(uintptr_t size) {
	FreeList* temp = list;
	FreeList* block = (FreeList*) malloc(sizeof(FreeList) + size);
	if (block == NULL) {
		return NULL;
	}
	totalsize = totalsize + sizeof(FreeList) + size;
	block->size = size;
	block->next = NULL;
	// sort the blocks
	while (temp->next != NULL) {
		if ((uintptr_t)block < (uintptr_t)temp->next) {
			block->next = temp->next;
			temp->next = block;
			return block;
		}
		temp = temp->next;
	}
	temp->next = block;
	return block;
}

// search a block with enough storage
FreeList* searchBlock(uintptr_t size) {
	FreeList* temp = list;
	FreeList* block = NULL;
	while (temp->next != NULL) {
		// search a block or greater or equal size
		if (temp->next->size >= size) {
			// if the block is too big then split
			if (temp->next->size - size >= MIN_SIZE) {
				return splitBlock(temp->next, size);
			} else {
				// assign that space to block
				block = temp->next;
				// remove the block's space from FreeList
				temp->next = temp->next->next;
			}
		} else {
			temp = temp->next;
		}
	}
	return block;
}

// splits the block accoring to the required size and then returns it
FreeList* splitBlock(FreeList* list, uintptr_t size) {
	uintptr_t address = (uintptr_t)list + list->size - size;
	FreeList* block =  (void*)address;
	block->size = size;
	block->next = NULL;
	list->size = list->size - size - sizeof(FreeList);
	return block;
}