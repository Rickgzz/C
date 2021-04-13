#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* this code is based on the exampe of the book and the one done by RogelioASR */

#define MAX 100  
#define NUMBER '0'

int 	getop(char []); 		
void 	push(double); 			
double 	pop(void); 				
int 	options(int, char[]); 		

char 	var;					
double 	variables[1000]; 			
int 	op1, op3;					


main() {

	int type; 
	double op2; 
	char s[MAX];
	
	while ((type = getop(s)) != EOF) {
        switch (type) {

            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break; 
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                if(s[0] != '=' && strlen(s) > 1 && variables[var] == 0)
					printf("error: unknown command %s\n", s); 
                break;
        }
    }    
} 

double 	val[MAX]; 					
int 	sp = 0; 				

void push(double f) {
	
	int ops;
	if (sp < MAX)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
	
	if(op1 && var != 0) {
		if(variables[var] == 0 || op3 == 1)
			variables[var] = f;
		else {
			printf("Do you want to overwrite the value of the variable? (%c)\n1.- YES 0.- NO \n", var);
			scanf("%i", &ops);
			if(ops)
				variables[var] = f;
		}
	op1 = 0;		
	}		
}

double pop(void) {
	
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
} 

#include <ctype.h>

int 	getch(void); 			   
void 	ungetch(int); 		

int getop(char s[]) {

	int i, c;	
	
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	i = 0;
	if (c == '-')                     
		if (!isdigit(s[++i] = c = getch())) {
			ungetch(c);               
			c = s[0];
		}
	
	if (c == ':') {
		s[++i] = c = getch();
		op3 = 1;
	}
	
	if (c == '=') {
		s[++i] = c = getch();
		op1 = 1;
	}
	
	if (isalpha(c))
		return options(c, s);
		
	if (!isdigit(c) && c != '.')
		return c; 
	
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()));
	}
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()));

	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

char 	buf[MAX]; 					
int 	bufp = 0; 					

int getch(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {

	if (bufp >= MAX)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int options(int c, char s[]) {
	
	int i = 0, o;
	double op2, n = 0;
	
	s[i] = c;
	while (isalpha(s[++i] = c = getch()));
	s[i] = '\0';
	ungetch(c);
	
	if(i == 1)
		var = tolower(s[0]);
	else 
		var = 0;
	if(variables[var] != 0)
		push(variables[var]);

	return 0;
}