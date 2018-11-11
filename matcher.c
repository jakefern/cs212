/**
 * You can modify this file.
 */
//NO STRING.H ALLOWED

// If you go to two office hours, you get 5 points extra credit for BOTH assignment 3 & project 3
// OR respond to questions on Piazza (either / or).

#include "matcher.h"
#include <stdio.h>
/**
 * Your helper functions can go below this line
 */

char next_char(char* x) { //might be for '.' operator?
	return *(x + 1);

}

int is_plus_operator(char opPlus) { //make other functions for the other operators.
	return (opPlus == '+');

}


int is_q_operator(char opQ){ //for '?''
	return (opQ == '?');
}

int is_period_operator(char opPer){
	return (opPer == '.');
}

int is_slash(char opSlash){
	return (opSlash == '\\');
}

/**
 * Your helper functions can go above this line
 */


/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */


int matches_leading(char *partial_line, char *pattern) { //USE RECURSION, LOOK UP STRCMP RECURSION ASSIGNMENT
	if (*pattern == '\0') {
		return 1;
	}
	if (*partial_line == '\0'){ 
		return 0;
	}

	if (is_slash(*pattern)){
		if (next_char(pattern) == *partial_line){ //checks for other operators
			return matches_leading(partial_line+1, pattern+2);
		} else {
			return 0;
		}
	}
	
	if (is_period_operator(*pattern)){
		return matches_leading(partial_line+1, pattern+1);
	}



	if (is_q_operator(*pattern)){
		if(*partial_line == *(pattern-1)){
			return matches_leading(partial_line+1, pattern+1);
		} else {
			return matches_leading(partial_line, pattern+1);
		}
	}

	if (is_plus_operator(*pattern)){
	    if (*partial_line == *(pattern - 1)) {
	        if (next_char(partial_line) == next_char(pattern)){
	            return matches_leading(partial_line+1, pattern+1);
	        }
	        int i = 0;
	        while(*(partial_line + i) == *(pattern - 1)) {
	            i++;
	        }
	        return matches_leading(partial_line+i, pattern+1);
	    }
	    return matches_leading(partial_line+1, pattern);
	}


	if (*pattern == *partial_line) {
		return matches_leading(partial_line+1, pattern+1);
	} else {
		return 0;
	}


	return 0;

	//return matches_leading(partial_line+1, pattern);
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {
	//printf("%s\n", line);
	while (*line != '\0') {
		if (matches_leading(line, pattern)) {
			return 1; // 1 means True
		}
		line++;
	}

    return 0; // 0 means False
}

