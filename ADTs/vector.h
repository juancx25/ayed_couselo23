#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define t_elem void*
#define STD_INIT_SIZE 2

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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

uint32_t vector_length(vector* v){
    return v->length;
}

void _vector_resize(vector* v, uint32_t new_reserve){
    v->elem = (t_elem*)realloc(v->elem, new_reserve);
    v->reserved_length = new_reserve;
}

void _vector_expand(vector* v){
    uint32_t resize_factor = v->reserved_length*1.5 + 1;
    _vector_resize(v, resize_factor);
}

/* bool vector_isfull(vector* v){
    return (v->length == v->reserved_length);
} */

bool vector_isempty(vector* v){
    return !(v->length);
}

t_elem vector_get(vector* v, uint32_t pos){
    return v->elem[pos];
}



bool vector_set(vector* v, uint32_t pos, t_elem value){
    bool result = false;
    if (pos < v->length){
        v->elem[pos] = value;
    }
    return result;
}

void vector_add(vector* v, t_elem value){
    if (v->length == v->reserved_length){
        _vector_expand(v);
    }
    vector_set(v, v->length++, value);
    return;
}

t_elem vector_remove(vector* v, uint32_t pos){
    t_elem result;
    if (pos < v->length){
        result = vector_get(v, pos);
        memcpy((void*)v->elem[pos], v->elem[pos+1], v->length-pos-1);
        v->length--;
    }
    return result;
}

void vector_print(vector* v, void (*elem_print)(t_elem)){
    for(int i=0;i<v->length;i++){
        elem_print(vector_get(v, i));
    }
}

#endif