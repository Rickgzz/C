#include <stdio.h>
#include <string.h>
#define MAX 1000
#define IN 1
#define OUT 0
// NO FUNCIONO :(

int main() {
    
  int i, l, n;
  
  char input[MAX];
  char output[MAX];
      
  printf("Insertar texto formato HTML: ");
  gets(input);
  l = strlen(input);
  n = OUT;

  for (i = 0; i<l ; ++i) {
          
    if (input[i] == '<')
      n = IN;
      if (input[i] == '>')
        n = OUT;       
    
    if (n == IN)
      output[i] = input[i];   //checar esta parte
    }

  printf("\nTexto plano: %d", output);

}
