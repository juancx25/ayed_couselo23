#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define t_elem void*
#define STD_INIT_SIZE 2

#include <stdlib.h>
#include <stdio.h>
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
    v->length = 0;
    v->reserved_length = STD_INIT_SIZE;
    return v;
}

vector* vector_init(uint32_t reserved_length){
    vector* v = (vector*)malloc(sizeof(vector));
    v->elem = (t_elem*)calloc(reserved_length,sizeof(t_elem));
    v->length = 0;
    v->reserved_length = reserved_length;
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
    v->elem = (t_elem*)realloc(v->elem, new_reserve*sizeof(t_elem));
    v->reserved_length = new_reserve;
}

void _vector_expand(vector* v){
    uint32_t resize_factor = v->reserved_length*1.5 + 1;
    _vector_resize(v, resize_factor);
}

//this makes no sense with this implementation
/* bool vector_isfull(vector* v){
    return (v->length == v->reserved_length);
} */

bool vector_isempty(vector* v){
    return !(v->length);
}

t_elem vector_get(vector* v, uint32_t pos){
    if (pos < v->length) return v->elem[pos];
    else return NULL;
}
// Should it return the element in the position, or just a state boolean?
bool vector_set(vector* v, uint32_t pos, t_elem value){
    bool result = false;
    if (pos < v->length){
        result = true;
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
    if (pos >= v->length) return NULL;
    t_elem result = (t_elem)malloc(sizeof(t_elem));
    memcpy(result, v->elem[pos], sizeof(t_elem));
    if (pos < v->length-1){
        //memcpy(v->elem[pos], v->elem[pos+1], v->length-pos-1);
        for (int i=pos;i<v->length-1;i++){
            v->elem[i] = v->elem[i+1];
        }
    }
    v->length--;
    return result;
}

void vector_print(vector* v, void (*elem_print)(t_elem)){
    for(int i=0;i<v->length;i++){
        elem_print(vector_get(v, i));
    }
    printf("\n");
}

bool vector_swap(vector* v, uint32_t pos_a, uint32_t pos_b){
    bool result = false;
    uint32_t len = vector_length(v);
    if ((pos_a < len) && (pos_b < len)){
        t_elem tmp = vector_get(v, pos_a);
        vector_set(v, pos_a, vector_get(v, pos_b));
        vector_set(v, pos_b, tmp);
    }
    return result;
}

#endif