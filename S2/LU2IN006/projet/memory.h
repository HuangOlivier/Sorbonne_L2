#ifndef MEMORY
#define MEMORY

#include "hash.h"


typedef struct segment {
	int start;
	int size;
	struct Segment *next;
} Segment;

typedef struct memoryHandler {
	void **memory;
	int total_size;
	Segment *free_list;
	HashMap *allocated;
}

#endif
