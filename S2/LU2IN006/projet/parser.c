#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Length 100

Instruction *parse_data_instuction(const char *line, HashMap *memory_locations){
	char nom[Length];
	char type[Length];
	char valeur[Length];
	int size=0;
	
	
	sscanf(line, "%s %s %s",nom, type, valeur);
	Instruction *res = malloc(sizeof(Instruction));
	res->mnemonic = strdup(nom);
	res->operand1 = strdup(type);
	res->operand2 = strdup(valeur);
	
	char *token = strtok(valeur, ",");
	while (token != NULL) {
        size++;
        token = strtok(NULL, ",");
    }

	
	//int mem_num = memory_locations->current_mem;
	//hashmap_insert(memory_locations, nom, mem_num);
	//mem_num+= size;
	
	return res;
}

Instruction *parse_code_instruction(const char *line, HashMap *labels, int code_count){
	char etiquette[Length];
	char nom[Length];
	char type[Length];
	char valeur[Length];
	
	int is_etiquette=0;
	if(strchr(line,':')){
		is_etiquette=1;
		sscanf(line, "%[^:] %s %[^,],%s", etiquette, nom, type, valeur);
	} else {
		sscanf(line, "%s %[^,],%s", nom, type, valeur);
		etiquette[0]='\0';
	}
	
	if (is_etiquette==1) {
		//hashmap_insert(labels, etiquette, code_count);
	}
}

ParserResult *parse(const char *filename) {
	FILE *f = fopen(filename,"r");
	
	ParserResult *res = malloc(sizeof(ParserResult));
	char buffer[555];
	int Data = 1;
	
	HashMap *labels;// = hashmap_create();
	HashMap *memory_locations; //= hashmap_create();
	Instruction **data_instructions = malloc(10*sizeof(Instruction*));
	Instruction **code_instructions = malloc(10*sizeof(Instruction*));
	
	res->code_count = 0;
	res->data_count = 0;
	res->labels = labels;
	res->memory_locations = memory_locations;
	
	while(fgets(buffer, 555, f)) {
		if(strcmp(buffer,".DATA\n")==0) continue;
		
		if (strcmp(buffer, ".CODE\n")==0){
			Data = 0;
			continue;
		}
		
		if(Data == 1) {
			printf("In .DATA: %s \n",buffer);
			Instruction *a = parse_data_instuction(buffer, memory_locations);
		} else {
			printf("In .CODE: %s \n",buffer);
			Instruction *b = parse_code_instruction(buffer, labels,0);
		}
		
	}
	
	fclose(f);
}


int main() {
	//parse_data_instuction("arr DB 5,6,7,8", NULL);
	parse_code_instruction("ADD BX", NULL, 0);
	parse("assembler.txt");
}
