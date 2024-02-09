#include "alumno.h"

char* get_noms(char* nom, const alumno* a){
  if(!AP_VAL(nom))
    return nom;
  if(!AP_VAL(a))
    return NULL;
  
  strcpy(nom,a->noms_c);
  return nom;
}
char* get_apep(char* ape, const alumno* a){
  if(!AP_VAL(ape))
    return ape;
  if(!AP_VAL(a))
    return NULL;
  
  strcpy(ape,a->apep_c);
  return ape;
}
char* get_apem(char* ape, const alumno* a){
  if(!AP_VAL(ape))
    return ape;
  if(!AP_VAL(a))
    return NULL;
  
  strcpy(ape,a->apem_c);
  return ape;
}
char* get_nomc(char* nom, const alumno* a){
  if(!AP_VAL(nom))
    return nom;
  if(!AP_VAL(a))
    return NULL;
  
  strcpy(nom,a->apep_c);
  strcat(nom," ");
  strcat(nom,a->apem_c);
  strcat(nom," ");
  strcat(nom,a->noms_c);
  return nom;
}

int get_edad(int* edad, const alumno* a){
  if(!AP_VAL(edad))
    return AP_INV;
  if(!AP_VAL(a))
    return AP_INV;
  
  *edad = a->edad;
  return OK;
}
int get_prom(float* prom, const alumno* a){
  if(!AP_VAL(prom))
    return AP_INV;
  if(!AP_VAL(a))
    return AP_INV;

  *prom = a->promedio;
  return OK;
}
                                          
int set_noms(alumno* a, const char* nom){
  if(!AP_VAL(nom))
    return AP_INV;
  if(!AP_VAL(a))
    return AP_INV;
  
  strcpy(a->noms_c,nom);
  return OK;
}

int set_apep(alumno* a, const char* ape){
  if(!AP_VAL(ape))
    return AP_INV;
  if(!AP_VAL(a))
    return AP_INV;

  strcpy(a->apep_c,ape);
  return OK;
}

int set_apem(alumno* a, const char* ape){
  if(!AP_VAL(ape))
    return AP_INV;
  if(!AP_VAL(a))
    return AP_INV;

  strcpy(a->apem_c,ape);
  return OK;
}

int set_edad(alumno* a, int edad){
  if(!AP_VAL(a))
    return AP_INV;
  if(!ED_VAL(edad))
    return ED_INV;
  
  a->edad = edad;
  return OK;
}
int set_prom(alumno* a, float promedio){
  if(!AP_VAL(a))
    return AP_INV;
  if(!PR_VAL(promedio))
    return PR_INV;
  a->promedio = promedio;
  return OK;
}
