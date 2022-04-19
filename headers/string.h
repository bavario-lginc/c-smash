#include <string.h> // Includes strcat() etc
#include <stdlib.h>

char *strreplace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

int strcount (char *original, char *substring) {
    int count = 0;
    while(original = strstr(original, substring))
    {
       count++;
       original++;
    }
    return count;
}

char *strmultiply (int pow, char *original, int amount) {
    if (!pow) {
        for (int i = 0; i <= amount - 1; i++) {
            strcat(CSI.buffer, original);
        }
        char *returnvalue = CSI.buffer;
        return returnvalue;
    } else {
        int i = 0;
        char toString[2] = "\0";
        while (original[i] != NULL) {
            for (int pos = 0; pos <= amount - 1; pos++) {
                toString[0] = original[i];
                strcat(CSI.buffer, toString);
            }
            i++;
        }
        char *returnvalue = CSI.buffer;
        return returnvalue;
    }
}

char *strescape (char *original) {
	original = strreplace(original, "\\a", "\a");
	original = strreplace(original, "\\b", "\b");
	original = strreplace(original, "\\e", "\e");
	original = strreplace(original, "\\f", "\f");
	original = strreplace(original, "\\n", "\n");
	original = strreplace(original, "\\r", "\r");
	original = strreplace(original, "\\t", "\t");
	original = strreplace(original, "\\v", "\v");
	return original;
}
