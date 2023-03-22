#include <stdio.h>

// "responses.c" v1.0
// Author: Mick Arrogante
// 2023 S1 Digital Solutions
// Assessment Item #2 PRACTICE

/*
	Function 1. 
	Implement this function to: 
		- Square x and subtract 3 from the result
		- Return the result
*/ 
int question_1(int x) {
	return (x * x) - 3;
}

/*
	Function 2.
		* Note that the parameter, len, represents the length of the array
	Implement this function to: 
		- Count the number of 'c' characters that are in the array, a,
		- Return 0 if the number of 'c' characters is odd
		- Return 1 if the number is even
*/ 
int question_2(char a[], int len) {
	int CCount = 0;
	for(int i = 0; i <= len; ++i){
		if(a[i] == 'c'){
			++CCount;
		}
	}
	return (CCount + 1) % 2;
}

/*
	Function 3.
	Implement this function to: 
		- Return 1 if EITHER:
			- i has a value greater than 23 OR
			- i is positive and divisible by 5
		- Return 0 if EITHER:
			- i is negative and not divisible by 5 OR
			- i is a non-zero number divisible by 3
		- Return -1 in any other case not covered above
*/ 

int question_3(int i) {
	if(i > 23 || ( (i >= 0) && i % 5 ==0) ){
		return 1;
	}else if( (i <= 0))
	return -999;
}

/*
	Function 4.
		* Node is a structure with two members: (int) data and (node *) next
	Implement this function to: 
		- Return the number of nodes containing 0 in the list
	Examples of input/output:
		- List(1,2,3) : 0
		- List(1,0,2,0,3,0) : 3
		- List(0) : 1
*/ 

int question_4(struct node *head) {
	printf("NOT DONE!");
	return -999;
}



int main(void){
	printf("%i \n",question_1(5));

	printf("%i \n",question_2("deghgucccccc",12));
}