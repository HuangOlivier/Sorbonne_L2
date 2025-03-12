#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long simple_hash(const char *str) {
	unsigned long res=0;
	
	for(int i=0; str[i] != '\0';i++) {
		res += (int) (str[i]);
	}
	
	return res % TABLE_SIZE;
}

int h(const char *str, int i) {
	return (int) (simple_hash(str) + i);
}


HashMap *hashmap_create() {
	HashMap *new = malloc(sizeof(HashMap));
	new->size = TABLE_SIZE;
	new->table = malloc(sizeof(HashEntry*) * TABLE_SIZE );

	for (int i=0; i < TABLE_SIZE; i++) {
		new->table[i].value = NULL;
	}
	
	return new;
}

int hashmap_insert(HashMap *map, const char *key, void *value) {
	 HashEntry* elem = malloc(sizeof(HashEntry));;
	 elem->key = strdup(key);
	 elem->value = value;
	 
	 int i=0;
	 unsigned long k = h(key,i);
	 
	 while ((map->table[k].value != TOMBSTONE) && (map->table[k].value != NULL)) {
	 	i++;
	 	k = (h(key,i) % map->size); 	
	 }
	 map->table[k].key = elem->key;
	 map->table[k].value = elem->value;
	 return k;
}


void *hashmap_get(HashMap *map, const char *key) {
	int i=0;
	unsigned long k = h(key,i);
	
	while (map->table[k].value != NULL) {
		if(strcmp(map->table[k].key,key)==0) {
			return map->table[k].value;
		}
		i++;
		k = (h(key,i) % map->size); 	
	}
	
	return NULL;
}

int hashmap_remove(HashMap *map, const char *key) {
	for(int i=0;i<map->size;i++){
			if(strcmp(map->table[i].key,key)==0){
					map->table[i].value = TOMBSTONE;
					return 1;
			}
	}
	return 0;
}


void hashmap_destroy(HashMap *map) {
	if (map) {
		for (int i=0; i<map->size; i++) {
			free(map->table[i].key);
			free(map->table[i].value);
			//free(map->table[i]);
		}
		free(map->table);
		free(map);
	}
}


