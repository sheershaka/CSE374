// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include "mem.h"
#include "mem_impl.h"

void merge(FreeList* curr, int n);

// Return the block of storage at location p to the pool of 
// available free storage. If p is NULL, then the call to 
// freemem has no effect and returns immediately. If p has 
// some value other than one returned by getmem, or if the 
// block it points to has previously been released by another 
// call to freemem, then the operation of freemem is undefined.
void freemem(void* p) {
	FreeList* to_free = (FreeList*) (p - sizeof(FreeList));
	FreeList* temp = list;
	if (temp != NULL) {
		while (temp->next != NULL && (uintptr_t) temp->next < (uintptr_t) to_free) {
			temp = temp->next;
		}
		FreeList* last = temp->next;
		temp->next = to_free;
		to_free->next = last;
		merge(temp, 2);
	} else {
		list = to_free;
	}
	check_heap();
}

void merge(FreeList* curr, int n) {
	if (n != 0 && curr->next != NULL) {
		if ((void*) (uintptr_t) curr + curr->size + sizeof(FreeList) 
		== (void*) curr->next) {
			curr->size += curr->next->size + sizeof(FreeList);
			curr->next = curr->next->next;
			merge(curr, n - 1);
		} else if (n != 1) {
			merge(curr->next, n - 1);
		}
	}
}