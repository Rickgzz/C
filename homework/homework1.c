#include <stdio.h>
#include <string.h>
#define MAX 1000
#define IN 1
#define OUT 0
// NO SIRVO :(

int main() {
    
  int i, l, n, m;
  
  char input[MAX];
  char output[MAX];
      
  printf("Insertar texto formato HTML: ");
  gets(input);        //cambiar esta parte****
  l = strlen(input);
  n = OUT;
  printf("\nTexto plano: ");

  for (i = 0; i<l ; ++i) {
    
    if (input[i] == '<')  //tomar solo las palabras dentro de <>
      n = IN;
    if (input[i] == '>')
      n = OUT;       
    if (n == OUT)
      output[i] = input[i]; //copiar de input a output
    
    if (output[i] == '>') //eliminar los >
        output[i] = ' ';
        
    printf("%c",output[i]); //imprimir output
    }

}
