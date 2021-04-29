#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib.h"


int main() 
{
  extern char line[];
  node* n = NULL;
  node* binarytree = NULL; 
  int i, j, l = 0;
  char* u;
  char* p;
  int indicator=0, spacecounter=0;
  printf("INSTRUCTIONS\n");
  printf("To add a user: add (user password)\n");
  printf("To remove a user: del (user password)\n");
  printf("To print the tree: print\n");

  while ((l = getout()) == 0) 
  {
      spacecounter=0;
    for (j=0; j<MAX; j++)
    {
        if (line[j]==' '||line[j]=='\t')
        {
            spacecounter++;
     }
    }
    if (strstr(line, "del") != NULL&&strlen(line)>=7&&spacecounter==2) 
    {
      get(line, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++)
      {
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++)
      {
          p[i]=password[i];
      }
      
      indicator=0;
      delete(binarytree, u, p, &indicator);
      if (indicator==0)
      {
          printf("check that all is correct\n\n");
      }

      indicator=0;
      spacecounter=0;
      }
    
    else if (strstr(line, "add") != NULL&&strlen(line)>=7&&spacecounter==2) 
    {
      get(line, password, user);
      u = (char*)malloc(sizeof(int*) * strlen(user));
      p = (char*)malloc(sizeof(int*) * strlen(password));
      for (i=0; i<strlen(user);i++)
      {
          u[i]=user[i];
      }
      for (i=0; i<strlen(password);i++)
      {
          p[i]=password[i];
      }
      
      if (strlen(password)>0&&strlen(user)>0)
      {
      n = insert(u,p, binarytree, 0); 
	  if (binarytree == NULL) 
	  {
	    binarytree = n;
	    }
	   spacecounter=0;
      }
      else if (strlen(password)<=0||strlen(user)<=0)
      {
          printf ("Check your input\n\n");
      }
     }
      
    else if (strstr(line, "print") != NULL&&strlen(line)==4) 
    {
      alpha(binarytree);
      printf("\n\n");
      spacecounter=0;
    }
    else
    {
        printf("Check your input\n\n");
        spacecounter=0;
    }
  }
  return 0;
 }


int getout() 
{
  extern char line[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) 
  {
        line[i++] = c;
  }
  line[i] = '\0';
  return c == EOF;
}

void alpha(node* position) 
{
  if (position != NULL) 
  {
    alpha(position->leftchild);
    if (position->password!=NULL)
    {
    printf("%s ", position->user);
    }
    alpha(position->rightchild);
 }
}

void delete(node* position, char* u, char* p, int* n)
{
    if (position != NULL) 
    {
        delete (position->leftchild, u, p, n);
        delete (position->rightchild, u, p, n);
        if (strcmp(position->user, u) == 0&&strcmp(position->password, p) == 0){
            position->password=NULL;
            printf("User (%s) has been removed\n\n", u);
            *n = 1;
  }
 }
}

void get (char l[MAX],char p[MAX],char u[MAX])
{
    int a = 4, b = 0, c=0;
    while (l[a]!=' '&&l[a]!='\t')
    {
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int length = strlen(u);
    a++;
    while (l[a]!=' '&&l[a]!='\t'&&l[a]!='\0')
    {
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int length2 = strlen(p);
}

node* insert(char* u, char* p, node* pos, int d) 
{
  node* temp;
  if (pos == NULL) 
  {
    pos = (node*)malloc(sizeof(node));
    pos->user = u;
    pos->password = p;
    pos->depth = d;
    printf ("user: (%s) password: (%s\n\n)", u, p);
  } 
  else 
  {
    if (strcmp(pos->user, u) == 0) 
    {
      if (pos->password!=NULL)
      {
      printf("This user is already registered\n\n");
      }
      else
      {
          pos->password = p;
          printf ("user: (%s) password: (%s\n\n)", u, p);
     }
    } 
    else if (strcmp(pos->user, u)>0) 
    {
      temp = insert(u, p, pos->leftchild, d + 1);
      if (pos->leftchild == NULL) 
      {
	pos->leftchild = temp;
     }
    } 
    else if (strcmp(pos->user, u)<0)
    {
      temp = insert(u, p, pos->rightchild, d + 1); 
      if (pos->rightchild == NULL) 
      {
	pos->rightchild = temp;
    }
   }
  }
  return pos;
}

/*This code completly is based completly on the one done by Rulgamer07*/
