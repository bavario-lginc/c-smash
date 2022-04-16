// C-Smash programming language interpreter
// Written in C by Bavario
#define MAX_STRING_LEN 128
struct Interpreter {
	int currentLine;
	char exceptionMsg[MAX_STRING_LEN];
	char storageString[MAX_STRING_LEN];
	int convertedString;
	char convertToInt[MAX_STRING_LEN];
	char currentcommand[MAX_STRING_LEN];
	char printstring[MAX_STRING_LEN];
	char inputstring[MAX_STRING_LEN];
	int curflags[5];
	char varname[MAX_STRING_LEN];
	int vartype;
	char stringvalue[MAX_STRING_LEN];
	int intvalue;
	char arithmeticalValues[MAX_STRING_LEN];
	char substring[MAX_STRING_LEN];
	char buffer[MAX_STRING_LEN];
}CSI; // C-Smash Interpreter
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "windows.c"
#include <string.h>
// #include "headers/string.h"
#ifdef __APPLE__
#define RICKROLL "open https://www.youtube.com/embed/dQw4w9WgXcQ?autoplay=1"
#elif linux
#include <unistd.h>
#define RICKROLL "xdg-open https://www.youtube.com/embed/dQw4w9WgXcQ?autoplay=1"
#elif _WIN32
#include <Windows.h>
#define RICKROLL "start https://www.youtube.com/embed/dQw4w9WgXcQ?autoplay=1"
#endif

int interpreter_throw (int exceptionCode) {
	switch (exceptionCode) {
		case 0:
			printf("InternalError: %s", CSI.exceptionMsg);
			break;
		case 1:
			printf("TypeError: %s", CSI.exceptionMsg);
			break;
	}
	exit(0);
}

void interpreter_store (char *varname, int type) {
	FILE *varfp = fopen("vars.csv", "a");
	if (type == 1) {
		printf("Writing %s to memory...\n", CSI.stringvalue);
		fprintf(varfp, "%s,%i,%s\n", varname, type, CSI.stringvalue);
	} else if (type == 2) {
		printf("Writing %i to memory...\n", atoi(CSI.convertToInt));
		fprintf(varfp, "%s,%i,%i\n", varname, type, atoi(CSI.convertToInt));
	}
	fclose(varfp);
	// printf("%s", CSI.convertToInt);
	// printf("Storing %s now", varname);
}

void interpreter_get (char *varname) {
	FILE *varfp = fopen("vars.csv", "r");
	char varchunk[MAX_STRING_LEN];
	char *splitchunk;
	while(fgets(varchunk, sizeof(varchunk), varfp) != NULL) {
		splitchunk = strtok(varchunk, ",");
		if (!strcmp(splitchunk, varname)) {
			splitchunk = strtok (NULL, ",");
			CSI.vartype = atoi(splitchunk);
			splitchunk = strtok (NULL, ",");
			if (CSI.vartype == 1) { sprintf(CSI.stringvalue, "%s", splitchunk); }
			else if (CSI.vartype == 2) { CSI.intvalue = atoi(splitchunk); }
			fclose(varfp);
			return;
		}
    }
	sprintf(CSI.exceptionMsg, "Couldn't find variable \"%s\" in storage", varname);
	interpreter_throw(1);
}

void conditionalPrintf () {
	if (CSI.vartype == 1) {
		printf("%s\n", CSI.stringvalue);
	} else if (CSI.vartype == 2) {
		printf("%i\n", CSI.intvalue);
	} else if (CSI.vartype == 4) {
		// printf("Array: [");
		// index = 0;
		// while (CSI.stringarray[index] != NULL) {
			// printf("%i", CSI.stringarray[index]);
			// index++;
			// if (CSI.stringarray[index] != NULL) printf(", ");
		// } printf("]");
	} else if (CSI.vartype == 5) {
		// printf("Array: [");
		// index = 0;
		// while (CSI.intarray[index] != NULL) {
			// printf("%i", CSI.intarray[index]);
			// index++;
			// if (CSI.intarray[index] != NULL) printf(", ");
		// } printf("]");
	}
}

void interpreter_run (char command[MAX_STRING_LEN]) {
	int index = 0;
	while (command[index] != NULL) {
		CSI.currentcommand[index] = command[index];
		// printf("%i", CSI.curflags[1]);
		if (CSI.curflags[0] == NULL) {
			if (!strcmp(CSI.currentcommand, "saythis")) CSI.curflags[0] = 1;
			else if (!strcmp(CSI.currentcommand, "sayvar(")) CSI.curflags[0] = 3;
			else if (!strcmp(CSI.currentcommand, "sleep(")) CSI.curflags[0] = 5;
			else if (!strcmp(CSI.currentcommand, "exit")) exit(0);
			else if (!strcmp(CSI.currentcommand, "beginPanic")) while (true) { printf("├è"); }
			else if (!strcmp(CSI.currentcommand, "rickroll()")) system(RICKROLL);
			else if (!strcmp(CSI.currentcommand, "input(")) CSI.curflags[0] = 4;
			else if (!strcmp(CSI.currentcommand, "window(")) CSI.curflags[0] = 6;
			// else if (!strcmp(CSI.currentcommand, "append(")) CSI.curflags[0] = 8;
			else if (!strcmp(CSI.currentcommand, "//")) break;
			else if (CSI.currentcommand[index] == 61) { 
				CSI.curflags[0] = 2;
				strncpy(CSI.varname, CSI.currentcommand, index - 1);
			}
			if (CSI.currentcommand[index] == 32 || CSI.currentcommand[index] == 9 || CSI.currentcommand[index] == 40 || CSI.currentcommand[index] == 41 || CSI.currentcommand[index] == 13) {
				//Ignore the character and move on
				index++;
				continue;
			}
		}
		else if (CSI.curflags[4] != NULL) {
			if (isdigit(CSI.currentcommand[index])) { strcat(CSI.arithmeticalValues, &CSI.currentcommand[index]); }
			else if (!isdigit(CSI.currentcommand[index])) {
				if (CSI.curflags[3] == 1) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue += atoi(CSI.arithmeticalValues); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
				if (CSI.curflags[3] == 2) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue -= atoi(CSI.arithmeticalValues); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
				if (CSI.curflags[3] == 3) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue *= atoi(CSI.arithmeticalValues); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
				if (CSI.curflags[3] == 4) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue /= atoi(CSI.arithmeticalValues); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
				if (CSI.curflags[3] == 5) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue = pow(CSI.intvalue, atoi(CSI.arithmeticalValues)); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
				if (CSI.curflags[3] == 6) { CSI.intvalue = atoi(CSI.convertToInt); CSI.intvalue %= atoi(CSI.arithmeticalValues); sprintf(CSI.convertToInt, "%i", CSI.intvalue); interpreter_store(CSI.varname, 2); break; }
			}
		}
		else if (CSI.curflags[3] != NULL) {
			if (CSI.currentcommand[index] == 32 || CSI.currentcommand[index] == 9 || CSI.currentcommand[index] == 40 || CSI.currentcommand[index] == 41 || CSI.currentcommand[index] == 13) {
				//Ignore the character and move on
				index++;
				continue;
			}
			CSI.curflags[4] = (CSI.currentcommand[index] == 34 ? 1 : (CSI.currentcommand[index] == 60 ? 3 : (CSI.currentcommand[index] == 84 || CSI.currentcommand[index] == 70 ? 2 : 2)));
			if (CSI.currentcommand[index] == 84) strcat(CSI.arithmeticalValues, "1");
			else if (CSI.currentcommand[index] == 70) strcat(CSI.arithmeticalValues, "0");
			else { strcat(CSI.arithmeticalValues, &CSI.currentcommand[index]); }
		}
		else if (CSI.curflags[2] != NULL) {
			if (CSI.curflags[0] == 2) {
				if (CSI.curflags[2] == 3) {
					CSI.curflags[2] = (CSI.currentcommand[index] == 34 ? 4 : (CSI.currentcommand[index] == 84 || CSI.currentcommand[index] == 70 ? 5 : 5));
				} else if (CSI.curflags[2] == 1 && CSI.currentcommand[index] != 34) strcat(CSI.stringvalue, &CSI.currentcommand[index]);
				else if (CSI.curflags[2] == 8 && strstr(CSI.currentcommand, "input(")) {
					if (CSI.currentcommand[index] == 34 && CSI.curflags[1] == NULL) { CSI.curflags[1] = 1; index++; continue; }
					if (CSI.currentcommand[index] != 34 && CSI.curflags[1] == 1) strcat(CSI.printstring, &CSI.currentcommand[index]);
					else if (CSI.currentcommand[index] == 34 && CSI.curflags[1] == 1) { printf("%s\n", CSI.printstring); fflush(stdout); fgets(CSI.stringvalue, MAX_STRING_LEN, stdin); CSI.stringvalue[strcspn(CSI.stringvalue, "\r\n")] = 0; interpreter_store(CSI.varname, 1); break; }
					else if (CSI.currentcommand[index] == 41) { fgets(CSI.stringvalue, MAX_STRING_LEN, stdin); CSI.stringvalue[strcspn(CSI.stringvalue, "\r\n")] = 0; interpreter_store(CSI.varname, 1); break; }
				}
				else if (CSI.curflags[2] == 1 && CSI.currentcommand[index] == 34) { interpreter_store(CSI.varname, 1); break; }
				if (CSI.currentcommand[index] == 32 || CSI.currentcommand[index] == 9 || CSI.currentcommand[index] == 40 || CSI.currentcommand[index] == 41 || CSI.currentcommand[index] == 13) {
					//Ignore the character and move on
					index++;
					continue;
				}
				if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 43) CSI.curflags[3] = 1;
				else if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 45) CSI.curflags[3] = 2;
				else if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 42) CSI.curflags[3] = 3;
				else if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 47) CSI.curflags[3] = 4;
				else if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 94) CSI.curflags[3] = 5;
				else if (CSI.curflags[2] == 2 && CSI.currentcommand[index] == 37) CSI.curflags[3] = 6;
				else if (CSI.curflags[2] == 2 && isdigit(CSI.currentcommand[index])) strcat(CSI.convertToInt, &CSI.currentcommand[index]);
				else if (CSI.curflags[2] == 2 && !isdigit(CSI.currentcommand[index])) { interpreter_store(CSI.varname, 2); break; }
			} else if (CSI.curflags[0] == 6) {
				if (CSI.curflags[2] == 1 && CSI.currentcommand[index] != 34) strcat(CSI.stringvalue, &CSI.currentcommand[index]);
				else if (CSI.curflags[2] == 1 && CSI.currentcommand[index] == 34) CSI.curflags[2] = 6;
				else if (CSI.curflags[2] == 6 && CSI.currentcommand[index] == 34) CSI.curflags[2] = 7;
				else if (CSI.curflags[2] == 6 && CSI.currentcommand[index] == 41) { sprintf(CSI.exceptionMsg, "Missing at least one argument of function window"); interpreter_throw(1); }
				else if (CSI.curflags[2] == 7 && CSI.currentcommand[index] != 34) { strcat(CSI.substring, &CSI.currentcommand[index]); }
				else if (CSI.curflags[2] == 7 && CSI.currentcommand[index] == 34) { char *windowargs[] = {"", CSI.stringvalue, CSI.substring, "z", (CSI.curflags[1] == 3 ? "1" : (CSI.curflags[1] == 4 ? "2" : (CSI.curflags[1] == 5 ? "3" : "4")))}; createWindow(windowargs); break; }
			}
		}
		else if (CSI.curflags[1] != NULL) {
			if (CSI.curflags[1] == 1) {
				if (CSI.currentcommand[index] != 34) { strcat(CSI.printstring, &CSI.currentcommand[index]); }
				else {
					printf("%s\n", CSI.printstring);
					fflush(stdout);
					if (CSI.curflags[0] == 4) {
						fgets(CSI.inputstring, MAX_STRING_LEN, stdin); break;
					}
				}
			}
			else if (CSI.curflags[1] == 2 && isdigit(CSI.currentcommand[index])) strcat(CSI.printstring, &CSI.currentcommand[index]);
			else if (CSI.curflags[1] == 2 && !isdigit(CSI.currentcommand[index])) printf("%s\n", CSI.printstring);
			if (CSI.currentcommand[index] == 32 || CSI.currentcommand[index] == 9 || CSI.currentcommand[index] == 40 || CSI.currentcommand[index] == 41 || CSI.currentcommand[index] == 13) {
				//Ignore the character and move on
				index++;
				continue;
			}
			else if (CSI.curflags[0] == 6) {
				if (CSI.currentcommand[index] == 34) CSI.curflags[2] = 1;
				else { sprintf(CSI.exceptionMsg, "window() only accepts an argument of type string here"); interpreter_throw(1); }
			}
			/*else if (CSI.curflags[0] == 8) {
				if (CSI.currentcommand[index] != 34 || CSI.currentcommand[index] != 44) strcat(CSI.substring, &CSI.currentcommand[index]);
				else if (CSI.currentcommand[index] == 34 || CSI.currentcommand[index] == 44) ; // Do nothing here
				else if (CSI.currentcommand[index] == 41) printf("%s", CSI.substring);
			}*/
		}
		else if (CSI.curflags[0] != NULL) {
			if (CSI.curflags[0] == 1) {
				if (CSI.currentcommand[index] == 34) CSI.curflags[1] = 1;
				else if (isdigit(CSI.currentcommand[index])) { CSI.curflags[1] = 2; strcat(CSI.printstring, &CSI.currentcommand[index]); }
			} else if (CSI.curflags[0] == 3) {
				if (CSI.currentcommand[index] != 41) strcat(CSI.varname, &CSI.currentcommand[index]);
				else { interpreter_get(CSI.varname); conditionalPrintf(); }
			}
			else if (CSI.curflags[0] == 4) {
				if (CSI.currentcommand[index] == 34) CSI.curflags[1] = 1;
				else if (CSI.currentcommand[index] == 41) { fgets(CSI.inputstring, MAX_STRING_LEN, stdin); break; }
			}
			if (CSI.currentcommand[index] == 32 || CSI.currentcommand[index] == 9 || CSI.currentcommand[index] == 40 || CSI.currentcommand[index] == 41) {
				//Ignore the character and move on
				index++;
				continue;
			}
			// if (CSI.curflags[0] == 2) {
				// if (CSI.currentcommand[index] == 61) CSI.curflags[1] = 2;
			// }
			else if (CSI.curflags[0] == 2) {
				CSI.curflags[2] = (CSI.currentcommand[index] == 34 ? 1 : (CSI.currentcommand[index] == 60 ? 3 : (CSI.currentcommand[index] == 84 || CSI.currentcommand[index] == 70 ? 2 : (isalpha(CSI.currentcommand[index]) ? 8 : 2))));
				if (CSI.currentcommand[index] == 84) strcat(CSI.convertToInt, "1");
				else if (CSI.currentcommand[index] == 70) strcat(CSI.convertToInt, "0");
				else strcat(CSI.convertToInt, &CSI.currentcommand[index]);
			}
			else if (CSI.curflags[0] == 5) {
				if (isdigit(CSI.currentcommand[index])) strcat(CSI.convertToInt, &CSI.currentcommand[index]);
				else {
					#ifdef _WIN32
					Sleep(atoi(CSI.convertToInt) * 1000); // Ugh why
					#elif linux
					sleep(atoi(CSI.convertToInt));
					#endif
				}
			}
			else if (CSI.curflags[0] == 6) {
				if (!strcmp(CSI.storageString, "INFO")) CSI.curflags[1] = 3;
				else if (!strcmp(CSI.storageString, "WARNING")) CSI.curflags[1] = 4;
				else if (!strcmp(CSI.storageString, "QUESTION")) CSI.curflags[1] = 5;
				else if (!strcmp(CSI.storageString, "ERROR")) CSI.curflags[1] = 6;
				else strcat(CSI.storageString, &CSI.currentcommand[index]);
			}
			/*else if (CSI.curflags[0] == 8) {
				if (CSI.currentcommand[index] != 34) { sprintf(CSI.exceptionMsg, "append() only accepts an argument of type string here"); interpreter_throw(1); }
				else if (CSI.currentcommand[index] == 34) CSI.curflags[1] = 1;
			}*/
		}
		index++;
	}
	// printf("\nExited after %i times", index);
	memset(&CSI.currentLine, 0, sizeof(CSI.currentLine));
	memset(&CSI.exceptionMsg, 0, sizeof(CSI.exceptionMsg));
	memset(&CSI.storageString, 0, sizeof(CSI.exceptionMsg));
	memset(&CSI.convertedString, 0, sizeof(CSI.convertedString));
	memset(&CSI.convertToInt, 0, sizeof(CSI.convertToInt));
	memset(&CSI.currentcommand, 0, sizeof(CSI.currentcommand));
	memset(&CSI.printstring, 0, sizeof(CSI.printstring));
	memset(&CSI.inputstring, 0, sizeof(CSI.inputstring));
	memset(&CSI.curflags, 0, sizeof(CSI.curflags));
	memset(&CSI.varname, 0, sizeof(CSI.varname));
	memset(&CSI.vartype, 0, sizeof(CSI.vartype));
	memset(&CSI.stringvalue, 0, sizeof(CSI.stringvalue));
	memset(&CSI.intvalue, 0, sizeof(CSI.intvalue));
	memset(&CSI.arithmeticalValues, 0, sizeof(CSI.arithmeticalValues));
	memset(&CSI.substring, 0, sizeof(CSI.arithmeticalValues));
}

int interpreter_readFile(char *filename) {
    FILE *fp;
    char *chunk;
    if (filename == NULL) {
        sprintf(CSI.exceptionMsg, "No filename specified");
		interpreter_throw(1);
    }
    if ((fp = fopen(filename, "r")) == NULL) {
        sprintf(CSI.exceptionMsg, "Opening the file %s failed", filename);
		interpreter_throw(0);
    }
    if ((chunk = (char*) malloc(MAX_STRING_LEN * sizeof(char))) == NULL) {
        fclose(fp);
        sprintf(CSI.exceptionMsg, "Reading the file %s failed (malloc error)", filename);
		interpreter_throw(0);
    }

    while(fgets(chunk, MAX_STRING_LEN, fp) != NULL) {
        CSI.currentLine++;
        interpreter_run(chunk);
    }
    free(chunk);
	remove("vars.csv");
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
	remove("vars.csv");
	if (argc == 1 || !strcmp(argv[1], "-h")) {
		printf("This is the C-Smash interpreter. Usage:\n\nc-smash.exe (input) [-h] [-r \"command\"] [-i]\ninput\t- The input file that should be interpreted. Not needed if '-h', '-i' or '-r' is set.\n-h: Help\t- Display this help screen.\n-r: Run\tRun a command. Remember to put it in quotes!\n-i: Interactive\tOpen an interactive shell, Python style.\n");
	} else if (!strcmp(argv[1], "-r")) {
		if (argv[2] != NULL) { interpreter_run(argv[2]); }
		else { printf("Error: Couldn't find the command to execute\n"); }
	} else if (!strcmp(argv[1], "-i")) {
		char userinput[MAX_STRING_LEN];
		printf("C-Smash shell Version 0.2\nType exit() to exit the interactive shell.");
		while (true) {
			printf("\n> ");
			fgets(userinput, MAX_STRING_LEN, stdin);
			// scanf("%s", userinput);
			// printf("You typed: \"%s\"\n", userinput);
			interpreter_run(userinput);
		}
	} else {
		interpreter_readFile(argv[1]);
	}
	// char *test[] = {"", "Account Details", "dResource not available\nDo you want to try again?", "2", "2"};
	// printf("%i", createWindow(test));
}