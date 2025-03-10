#ifndef PARSER
#define PARSER

#include "hash.h"


typedef struct {

	char *mnemonic;
	char *operand1;
	char *operand2;
} Instruction;

typedef struct {
	Instruction **data_instructions;
	int data_count;
	Instruction **code_instructions;
	int code_count;
	HashMap *labels;
	HashMap *memory_locations;
} ParserResult;


Instruction *parse_data_instuction(const char *line, HashMap *memory_locations);
Instruction *parse_code_instruction(const char *line, HashMap *labels, int code_count);
ParserResult *parse(const char *filename);

#endif
