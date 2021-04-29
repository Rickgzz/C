#define MAX 100

typedef struct tree {
  char* user;
  char* password;
  struct tree* rightchild;
  struct tree* leftchild;
  unsigned int depth;
} node;

node* insert(char* u, char* p, node* pos, int d);
void delete(node* position, char* a, char* p, int* n);
void alpha(node* position);
char line[MAX], password[MAX], user[MAX];
int getout();
void get (char l[MAX],char p[MAX],char u[MAX]);
