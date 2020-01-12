#include "config.h"
#include <time.h>
#include <math.h>

int question(char typeChar, int type, int random) {
	int limit;
	if (typeChar == '+' || typeChar == '-') {
		limit = 99;
	} else {
		limit = 10;
	}

	srand(time(NULL) * random);
	int numOne = rand() % limit + 1;
	srand(rand());
	int numTwo = rand() % limit + 1;

	float answer;
	switch (type) {
		case 1:
			answer = numOne + numTwo; break;
		case 2:
			answer = numOne - numTwo; break;
		case 3:
			answer = numOne * numTwo; break;
		case 4:
			answer = round((double)numOne / numTwo * 100); break;
	}

	float attempt;
	printf("\nQuestion: %d %c %d = ", numOne, typeChar, numTwo);
	while (scanf_s("%f", &attempt) != 1) {
		printf("Insert number: ");
	}

	if (type != 4 && attempt == answer) {
		printf("Correct!\n");
		return 1;
	} else if (type != 4 && attempt != answer) {
		printf("Wrong. The correct answer was %d.\n", (int)answer);
		return 0;
	} else if (type == 4 && attempt * 100 == answer) {
		printf("Correct!\n");
		return 1;
	} else {
		printf("Wrong. The correct answer was %.2f.\n", (double)answer / 100);
		return 0;
	}
}