#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0

main(){

  int c,i=0;
  char str[100];


  while((c = getchar()) != EOF) { 

    switch (c){                       //elimina todos las puntuaciones
      case 'a': case 'c': case 'e': case 'g': case 'i': case 'k': case 'm': case 'o': case 'q': case 's': case 'u': case 'w': case 'y': case '(': case ')': case ' ': case '"':
      case 'b': case 'd': case 'f': case 'h': case 'j': case 'l': case 'n': case 'p': case 'r': case 't': case 'v': case 'x': case 'z': case '{': case '}': case '0': case '2': case '4': case '6': case '8':
      case 'A': case 'C': case 'E': case 'G': case 'I': case 'K': case 'M': case 'O': case 'Q': case 'S': case 'U': case 'W': case 'Y': case '[': case ']': case '1': case '3': case '5': case '7': case '9': 
      case 'B': case 'D': case 'F': case 'H': case 'J': case 'L': case 'N': case 'P': case 'R': case 'T': case 'V': case 'X': case 'Z': case '\n': case '\t':
        str[i++] = c;
        str[i] = '\0';
    }   
  }

  int l = strlen(str);
  int d =2, par=OUT;


  for (int i = 0; i < l; i++){        //si estan dentro de un parentesis no pasa nada

    if(str[i]=='(' || str[i]=='{' || str[i]=='['){
      par=IN;
    }
    if(str[i]==')' || str[i]=='}' || str[i]==']'){
      par=OUT;    
    }
    if (str[i]=='"'){                  //si estan dentro de unas comillas no pasa nada
      d++;
    }

    if(par==OUT && (d%2)==0){          

      switch(str[i]){                  //cambiar los numeros por X
            
      case '0': case '2': case '4': case '6': case '8':
      case '1': case '3': case '5': case '7': case '9': 
        str[i] = 'X';
        break;
      }
    }
  }
 
  for(int i=0,j=0;i<l+1;i++){           //elimina las agrupaciones de X
        
    if ((str[i] != 'X') || (str[i+1] != 'X')){
      str[j++] = str[i];
    }
  }

  printf("%s\n", str);                    //imprimir el array modificado
}
