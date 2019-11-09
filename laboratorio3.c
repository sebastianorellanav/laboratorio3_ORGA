//SIMULADOR DE PIPELINE
//SEBASTIAN ORELLANA
//20.197.746-0

#include <stdio.h>
#include <stdlib.h>

typedef struct typeR
{
	char opcode;
	int rd;
	int rs;
	int rt;
}typeR;

typedef struct typeI
{
	char opcode;
	int rs;
	int rt;
	char jumpLabel;
}typeI;

typedef struct typeJ
{
	char opcode;
	char jumpLabel;
};

typedef struct instruction
{
	char *label;
	int type;
	typeR *instructionR;
	typeI *instructionI
	typeJ *instructionJ;
}
instruction;


typedef struct pointRegister
{
	int value;
	int address;
	struct pointRegister *next;
}
pointRegister;

typedef struct Registers
{
	const int zero = 0;
	int v[2];
	int a[4];
	int t[10];
	int s[8];
	int k[2];
	struct pointRegister *sp;
	int ra;
}
Registers;


pointRegister* createPointRegister(int newDirection, int newValue)
{
	pointRegister *new = (pointRegister*)malloc(sizeof(pointRegister));
	new -> value = newValue;
	new -> direction = newDirection;
	new -> next = NULL;

	return new;
}

Registers inicializateRegisters()
{
	Registers new;
	int i;
	for (i = 0; i < 2; ++i){
		new.v[i] = 0;
		new.k[i] = 0;
	}

	for (i = 0; i < 8; ++i){
		new.s[i] = 0;
	}

	for (i = 0; i < 4; ++i){
		new.a[i] = 0;
	}

	for (i = 0; i < 2; ++i){
		new.t[i] = 0;
	}

	new.ra = 0x0035000;

	new.sp = createPointRegister(0x0010000, 0);

	return new;
}



//function to read the input file
//inputs = name
void readFile(char *fileName){
	//define variables
	char *aux;
	FILE *archive = NULL;

	// open file
  	archive = fopen(fileName, "r");

  	//check if file was opened correctly
  	if(archive == NULL){    
    	printf("  Error: No se ha podido abrir el archivo %s", fileName);
    	exit(1);
  	}

  	fscanf(archive, "%s", aux);
  	if(aux != )


  	fclose(archive);
}

void programExecution(){
	instruction *pipeline = (instruction*)malloc(5*sizeof(instruction));
	

	//Instruction Fetch
	//saco la instruccion que apunta el puntero y la guardo en el stack

	//Instruction Decode
	//identifico que es lo que tengo que hacer y que registros o direcciones o immediates voy a usar

	//Execution
	//realizar la operacion

	//Memory
	//si es lw saco el dato de memoria
	//si es sw guardo el dato en memoria

	//Write Back
	//escribo los registros



}

//function to add two integers
//inputs = destination register, content of first source register, content of second source register
void add(int *rd, int rs, int rt)
{
	*rd = rs + rt;
}

//function to subtract two integers
//inputs = destination register, content of first source register, content of second source register
void sub(int *rd, int rs, int rt)
{
	*rd = rs - rt;
}

//function to add two integers
//inputs = destination register, content of first source register, integer (immediate value)
void addi(int *rd, int rs, int immediate)
{
	*rd = rs + immediate;
}

//function to subtract two integers
//inputs = destination register, content of first source register, integer (immediate value)
void subi(int *rd, int rs, int immediate)
{
	*rd = rs - immediate;
}


void main(){
	Registers registers = inicializateRegisters();
	registers.t[1] = 2;
	registers.t[2] = 3;
	add(&(registers.t[0]),&(registers.t[1]),&(registers.t[2]));
	printf("%d\n", registers.t[0]);
}