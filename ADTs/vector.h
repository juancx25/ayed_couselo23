#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define t_elem void*
#define STD_INIT_SIZE 2

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct{
    t_elem* elem;
    uint32_t length;
    uint32_t reserved_length;
} vector;

vector* vector_new(){
    vector* v = (vector*)malloc(sizeof(vector));
    v->elem = (t_elem*)calloc(STD_INIT_SIZE,sizeof(t_elem));
    v->reserved_length = STD_INIT_SIZE;
    return v;
}

vector* vector_init(uint32_t length){
    vector* v = (vector*)malloc(sizeof(vector));
    v->elem = (t_elem*)calloc(length,sizeof(t_elem));
    v->reserved_length = length;
    return v;
}

void vector_free(vector* v){
    free(v->elem);
    free(v);
    return;
}

t_elem vector_get(vector* v, uint32_t pos){
    return v->elem[pos];
}

bool vector_set(vector* v, uint32_t pos){
    bool result = false;
    if (pos > v->length){
        
    }
    return result;
}

#endif