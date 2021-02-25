#include <stdio.h>
#include <string.h>
#define MAX 1000
#define IN 1
#define OUT 0
// DOESN'T WORK YET :(

int main() {
    
  int i, l, n, m;
  
  char input[MAX];
  char output[MAX];
      
  printf("Insert HTML text: ");
  gets(input);        //change this****
  l = strlen(input);
  n = OUT;
  printf("\nPlain text: ");

  for (i = 0; i<l ; ++i) {
    
    if (input[i] == '<')  //take only words inside <>
      n = IN;
    if (input[i] == '>')
      n = OUT;       
    if (n == OUT)
      output[i] = input[i]; //copy from input to output list
    
    if (output[i] == '>') //eliminate >
        output[i] = ' ';
        
    printf("%c",output[i]); //print output text
    }

}
