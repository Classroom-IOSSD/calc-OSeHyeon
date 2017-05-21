#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	float result = 0.0f;
	int line = 0;

    int (*functionPointer) (int, int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				functionPointer = add;
				break;
				case '-':
				functionPointer = minus;
				break;
				case '*':
				functionPointer = mul;
				break;
				case '/':
				functionPointer = div;
				break;
			}		
	        result = functionPointer(operand1, operand2);	
            printf("%d %c %d = %.6f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

