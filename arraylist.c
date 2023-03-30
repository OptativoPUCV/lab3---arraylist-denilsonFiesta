#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

void expandir(ArrayList * l){
  if(l->capacity==l->size){
    l->capacity *=2;
    l->data =  (void**) realloc(l->data, l->capacity*sizeof(void*) );
  }
}

ArrayList *createList(void) {

  ArrayList* nuevaLista = (ArrayList*) calloc(1, sizeof(ArrayList));

  nuevaLista->data =  (void**) calloc(2, sizeof(void*));
  nuevaLista->capacity = 2;
  nuevaLista->size = 0;
  
  return nuevaLista;
}

void append(ArrayList * l, void * data){

  expandir(l);
  *(l->data+l->size) = data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(!(i>l->size) ){
    expandir(l); 
    void* aux;
    void* aux2;
    aux = *(l->data+i);
    *(l->data+i) = data;
    l->size++;
    for(int k = i+1; k < l->size; k++){
      aux2 = *(l->data+k);
      *(l->data+k) = aux;
      aux = aux2;
    }  
    
  }
}

void* pop(ArrayList * l, int i){

  void* datito = *(l->data + i); 
  
  for(int k = i; k < l->size ; k++){
    *(l->data + k)  = *(l->data+k+1);
  }
  
  return datito;
}

void* get(ArrayList * l, int i){

  if(i >= l->size) return NULL;

  if(i < 0) return *(l->data + l->size + i );
  else return *(l->data + i);  
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
