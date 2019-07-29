// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include "mem.h"
#include "mem_impl.h"

// Print a formatted listing on file f showing the blocks on the free list. 
void print_heap(FILE * f) {
	FreeList* temp = list;
	if (temp == NULL) {
		fprintf(stderr, "The list is Empty");
	}
	if (f == NULL) {
		fprintf(stderr, "File can not be opened");
	}
	if (temp != NULL) {
		while (temp->next != NULL) {
			fprintf(f, "%p %lx\n", (void*)temp, temp->size);
			temp = temp->next;
		}
		fprintf(f, "%p %lx\n", (void*)temp, temp->size);
	}
}