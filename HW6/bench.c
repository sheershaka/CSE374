// Sheershak Agarwal, Ayush Kanthalia
// 20 May 2019
// HW 6

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>

#include "mem.h"

// Testing program which executes large number of calls to
// functions getmem and freemem to allocate and free blocks of
// random sizes and in random order.
// @prints: total CPU time used by the bechmark test in seconds,
// total amount of storage acquired from underlying system by the
// memory manager during the test, total number of blocks on the
// free storage list at this point in the test, average number of
// bytes in the free storage blocks at this point in the test.
int main(int argc, char** argv) {
    int ntrials = 10000;
    int pctget = 50;
    int pctlarge = 10;
    int small_limit = 200;
    int large_limit = 20000;
    int random_seed = time(NULL);

    if (argc > 7) {
        fprintf(stderr, "Error. Too many arguments.\n");
        exit(EXIT_FAILURE);
    }
    if (argc > 1) {
        ntrials = atoi(argv[1]);
    }
    if (argc > 2) {
        pctget = atoi(argv[2]);
    }
    if (argc > 3) {
        pctlarge = atoi(argv[3]);
    }
    if (argc > 4) {
        small_limit = atoi(argv[4]);
    }
    if (argc > 5) {
        large_limit = atoi(argv[5]);
    }
    if (argc > 6) {
        random_seed = atoi(argv[6]);
    }

    srand(random_seed);

    void** allocated_blocks = (void**)malloc(ntrials * sizeof (void*));
    int index = 0;
    uintptr_t free_blocks;
    uintptr_t total_allocated;
    uintptr_t total_free;
    uintptr_t input_size;
    clock_t start = clock();
    double total_runtime;
    for (int i = 0; i < ntrials; i++) {
        // if true, calls getmem otherwise freemem
        if (rand() % 100 >= pctget) {
            if (rand() % 100 >= pctlarge) {
                input_size = (rand() % small_limit) + 1;
            } else {
                input_size = (rand() % (large_limit - small_limit)) + small_limit;
            }
            allocated_blocks[index] = getmem(input_size);
            index++;
        } else {
            if (index > 0) {
                int num = rand() %  index;
                freemem(allocated_blocks[num]);
                allocated_blocks[num] = NULL;
                index--;
            }
        }
        // print stats
        int tenth = (int) (ntrials / 10);
        if (i != 0 && (i % tenth == 0)) {
            get_mem_stats(&total_allocated, &total_free, &free_blocks);
            printf("Total allocated: %lu\n", total_allocated);
            printf("Total free: %lu\n", total_free);
            printf("Free blocks: %lu\n", free_blocks);
            printf("Average bytes per free block: %lu\n",
            (uintptr_t) (total_free / free_blocks));
            clock_t end = clock();
            total_runtime = (double) (end - start) / (double) CLOCKS_PER_SEC;
            printf("CPU time: %f\n", total_runtime);
        }
    }
    exit(EXIT_SUCCESS);
}