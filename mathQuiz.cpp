#include "config.h"
#include "questionGenerator.h"


void main() {
	
	printf("Welcome to the simple math quiz program!\n");

//	let user chose type of questions
	int type;
	int a;
	char typeChar;
	char* typeString;
	printf("Which questions would you solve?\n");
	printf("====================================================\n");
	printf("1.Addition 2.Subtraction 3.Multiplication 4.Division\n");
	printf("====================================================\n");

//	if anything other than 1~4 is entered, request re-enter
	while (scanf_s("%d", &type) != 1) {		// if letter is entered
		do { a = getchar(); } while (a != '\n' && a != EOF);	// clear input buffer
		printf("Please enter the number between 1 and 4: ");
	}
	while (type < 1 || type > 4) {			// if other integer is entered
		printf("Please enter the number between 1 and 4: ");
		scanf_s("%d", &type);
	}

//	confirm & inform the type of questions
	switch (type) {
		case 1:
			printf("You chose Addition problem.\n");
			typeString = (char*)malloc(sizeof(char) * 9);
			strcpy_s(typeString, 9, "Addition");
			typeChar = '+';
			break;
		case 2:
			printf("You chose Subtraction problem.\n");
			typeString = (char*)malloc(sizeof(char) * 12);
			strcpy_s(typeString, 12, "Subtraction");
			typeChar = '-';
			break;
		case 3:
			printf("You chose Multiplication problem.\n");
			typeString = (char*)malloc(sizeof(char) * 15);
			strcpy_s(typeString, 15, "Multiplication");
			typeChar = 'x';
			break;
		case 4:
			printf("You chose Division problem.\n");
			printf("You MUST round your answer to two decimal place.\n");
			typeString = (char*)malloc(sizeof(char) * 9);
			strcpy_s(typeString, 9, "Division");
			typeChar = '/';
			break;
		default:
			typeString = (char*)malloc(sizeof(int) * 1);
	}

//	number of questions to solve
	int num;
	int b;
	printf("========================================\n");
	printf("How many questions do you want to solve?\n");
	printf("========================================\n");

	//	if anything other than positive integer is entered, request re-enter
	while (scanf_s("%d", &num) != 1) {			// if letter is entered
		do { b = getchar(); } while (b != '\n' && b != EOF);	// clear input buffer
		printf("Please enter a valid, positive integer:");
	}
	while (num < 1) {							// if non-positive integer is entered
		printf("Please enter a positive integer:");
		scanf_s("%d", &num);
	}

	int correct = 0;
	int solved = 0;
	int startTime = time(NULL);
	for (int i = 0; i < num; i++) {
		if (question(typeChar, type, solved) == 1) {
			correct++;
		}
		solved++;
	}
	int endTime = time(NULL);

	printf("\nYou solved %d %s questions with %4.1f%% accuracy(%d correct, %d wrong) in %dmin. %dsec.\n", num, typeString, (double)correct / num * 100, correct, num - correct, (endTime - startTime) / 60, (endTime - startTime) % 60);

}