/** 
 * @file Remove duplicates in string without 
 *       extra memory. O(N^2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicates(char *str) {
	int len = strlen(str);

	int tail = 1;
	/* If the string is null return */
	if (str == NULL) 
		return;
	/* If the string has less than two chars. return */
	if (len < 2) 
		return;
	/* Check if there are duplicates */
	for (int i = 1; i < len; i++) {
		int j;
		for (j = 0; j < tail; j++)
		       /* Duplicate with previous element in string
			  break
			*/	
			if (str[i] == str[j])
				break;
		if (j == tail) {
			/* No duplicates with previous. Shift to the tail
			   of the string */
			str[tail] = str[i];
			tail++;
		}
	}
	/* the end of string */
	str[tail] = '\0';
} 

void print(char* str) {
	printf("String: %s\n", str);
	return;
}

int main() {
	char str1[] = "aaaaaa";
	char str2[] = "abcde";
	char str3[] = "abbaa";
	char str4[] = " a b  d  b e";

	print(str1);
	removeDuplicates (str1);
	print (str1);
	print(str2);
	removeDuplicates (str2);
	print (str2);
	print(str3);
	removeDuplicates (str3);
	print (str3);
	print(str4);
	removeDuplicates (str4);
	print (str4);
	
}
