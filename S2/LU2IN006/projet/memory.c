#include "memory.h"

MemoryHandler *memory_init(int size) {
	MemoryHandler *new = malloc(sizeof(MemoryHandler));
	
	
	Segment *seg = malloc(sizeof(Segment));
	seg->start = 0;
	seg->size = size;
	seg->next = NULL;
	
	new->free_list = seg;
	new->allocated = NULL;
	new->total_size = size;
	
	return new;
	//void **memory ?
}

Segment* find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev) {
	Segment* tmp = handler->free_list;
	Segment* prec = NULL;
	
	while(tmp) {
		if (tmp->start <= start && tmp->start+tmp->size >= start+size) {
			*prev = prec; 
			return tmp;
		}
		
		prec = tmp;
		tmp = tmp->next;
	}
	
	return NULL;
}

int create_sement(MemoryHandler *handler, const char *name, int start, int size) {
	Segment *prec = NULL;
	Segment *n = find_free_segment(handler, start, size, &prec);
	
	if(n != NULL) {
		Segment *new_seg = malloc(sizeof(Segment));
		new_seg->start = start;
		new_seg->size = size;
		new_seg->next = NULL;
		
		hashmap_insert(handler->allocated, name, (void*) new_seg);
		
		
		//n->size / 2
		//n1->start = n->start
		//n1->size = n->start
	}
	
}



