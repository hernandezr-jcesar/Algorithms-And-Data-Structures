#ifndef _ALUMNO_H
#define _ALUMNO_H

#include <string.h>
#include "error.h"

#define TAM_NOM   50
#define TAM_APE   50
#define PRO_MAX   10.0
#define ED_INV    20
#define PR_INV    30

#define ED_VAL(a)   ((a)>0)
#define PR_VAL(a)   ((a)>0 && (a)<PRO_MAX)

typedef struct{
  char  noms_c[TAM_NOM];
  char  apep_c[TAM_APE];
  char  apem_c[TAM_APE];
  int   edad;
  float promedio;
} alumno;

char* get_noms(char* nom, const alumno* a);
char* get_apep(char* ape, const alumno* a);
char* get_apem(char* ape, const alumno* a);
char* get_nomc(char* nom, const alumno* a);
int   get_edad(int* edad, const alumno* a);
int   get_prom(float* prom, const alumno* a);

int set_noms(alumno* a, const char* nom);
int set_apep(alumno* a, const char* ape);
int set_apem(alumno* a, const char* ape);
int   set_edad(alumno* a, int edad);
int   set_prom(alumno* a, float prom);

#endif