# Sheershak Agarwal, Ayush Kanthalia
# 20 May 2019
# HW 6 

# target
bench: bench.o freemem.o getmem.o get_mem_stats.o mem_utils.o print_heap.o
		gcc -Wall -std=c11 -g -o bench bench.o freemem.o getmem.o get_mem_stats.o mem_utils.o print_heap.o

# individual sources
bench.o: bench.c mem.h
		gcc -Wall -std=c11 -g -c bench.c

freemem.o: freemem.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c freemem.c

getmem.o: getmem.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c getmem.c

get_mem_stats.o: get_mem_stats.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c get_mem_stats.c

mem_utils.o: mem_utils.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c mem_utils.c

print_heap.o: print_heap.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c print_heap.c

# runs test
test: bench
		./bench

# removes build (source) files and backups
clean:
		rm -f *.o bench *~