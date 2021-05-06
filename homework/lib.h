#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 20
#define USUARIOS 30


int* registrados = 0; 
int** matrix; 
int totaldesalidas=0; 
int count();
void registrar();
void entradaosalida(int, int);
void header();
void horario();