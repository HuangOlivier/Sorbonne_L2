#include "memory.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
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
}

Segment* find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev) {
	Segment* tmp = handler->free_list;
	
	while(tmp) {
		if (tmp->start <= start && tmp->start+tmp->size >= start+size) {
			return tmp;
		}
		*prev = tmp;
		tmp = tmp->next;
	}
	
	return NULL;
}

int create_segment(MemoryHandler *handler, const char *name, int start, int size) {
	Segment *prec = NULL;
	Segment *n = find_free_segment(handler, start, size, &prec);
	
	if(n != NULL) {
		Segment *new_seg = malloc(sizeof(Segment));
		new_seg->start = start;
		new_seg->size = size;
		new_seg->next = NULL;
		hashmap_insert(handler->allocated, name, (void*) new_seg);

		Segment *new1 = malloc(sizeof(Segment));
		new1->start = n->start;
		new1->size =start - n->start; 
		new1->next =n;

		n->start =start + size;
		n->size =n->size - size;

		if (prec) {
			prec->next = new1;
		} else {
			handler->free_list = new1;
		}
	}
	return 0;// ne sais pas quoi retourner
}
	

int remove_segment(MemoryHandler *handler, const char *name){
	Segment *new = hashmap_get(handler->allocated, name);
	hashmap_remove(handler->allocated,name);
	Segment *seg_free=handler->free_list;
	Segment *prec;

	while (seg_free && seg_free->start < new->start) {
        prec = seg_free;
        seg_free = seg_free->next;
    }

    if (prec && prec->start + prec->size == new->start) {
        prec->size +=new->size;
        free(new);
        new = prec;
    } else {
        new->next = seg_free;
        if (prec) prec->next = new;
        else handler->free_list = new;
    }

    if (seg_free && new->start + new->size == seg_free->start) {
        new->size += seg_free->size;
        new->next =seg_free->next;
        free(seg_free);
    }
	return 0;
}

