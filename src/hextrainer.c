#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

enum op_type {
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_XOR,

	OP_NONE,
};

char op_symbol[] = {
	'+',
	'-',
	'*',
	'^',
};

int question()
{
	enum op_type op;
	uint32_t ans;
	uint32_t res;
	uint32_t a;
	uint32_t b;

	a = rand()%0xf;
	b = rand()%0xf;

	op = rand()%OP_NONE;
	while (op == OP_MUL)
		op = rand()%OP_NONE;

	switch (op) {
	case OP_ADD:
		res = a + b;
		break;
	case OP_SUB:
		if (a < b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		res = a - b;
		break;
	case OP_MUL:
		res = a * b;
		break;
	case OP_XOR:
		res = a ^ b;
	}

	printf("%x %c %x = ", a, op_symbol[op], b);
	scanf("%x", &ans);

	if (ans == res) {
		printf("good answer!\n\n");
		return 1;
	} else {
		printf("wrong answer!\n\n");
		return 0;
	}
}

int main()
{
	uint32_t correct;
	uint32_t total;

	srand(getpid());

	correct = 0;
	total = 10;	

	for (int i = 0; i < total; i++) {
		correct += question();
	}

	printf("%d/%d correct\n", correct, total);

	return 0;
}
