#include <stdio.h>
#include <string.h>
#define MAX 1000
#define IN 1
#define OUT 0
// NO FUNCIONO :(
char quitar(char);

int main() {
    
      int i, l, n;
      
      char input[MAX];
      char output[MAX];
     
      printf("Insertar texto formato HTML: ");
      gets(input);
      l = strlen(input);
      n = OUT;
      
     printf("\nTexto plano: ");
     
     for (i = 0; i<l ; ++i) {
          
          if (input[i] == '<')
             n = IN;
          if (input[i] == '>')
             n = OUT;       
          if (n == OUT)
             output[i] = input[i];
             //quitar(output[i]);
             printf("%c",output[i]); // checar  
          }
     
     }


char quitar(char) {
     int m;
     
     for (m = 0; m<30 ; ++m) {
         
         if (output[m]=='<')
             (output[m] = '_');
             }
             
     return output[m];
    }
