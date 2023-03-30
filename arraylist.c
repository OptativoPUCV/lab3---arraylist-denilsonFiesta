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
    for(int k = 0; k <= l->size; k++){
      if(i==k){
        aux = *(l->data+i);
        *(l->data+i) = data;
      }
      if(k>i){
        aux2 = *(l->data+i);
        *(l->data+i) = aux;
        aux = aux2;
      }
    }  
    l->size++;
  }
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
