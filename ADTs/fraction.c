#include "fraction.h"

fraction* fraction_new(){
    fraction* result = (fraction*)malloc(sizeof(fraction));
    result->num = 0;
    result->den = 1;
    return result;
}

fraction* fraction_init(int num, int den){
    fraction* result = fraction_new();
    fraction_setNum(result, num);
    if (fraction_setDen(result, den))
        return result;
    fraction_free(result);
    return NULL;
}

void fraction_free(fraction* f){
    if (f)
        free(f);
}

int fraction_getNum(const fraction* f){
    return f->num;
}

int fraction_getDen(const fraction* f){
    return f->den;
}

void fraction_setNum(fraction* f, int num){
    f->num = num;
    return;
} 

bool fraction_setDen(fraction* f, int den){
    bool result = false;
    if (den != 0){
        if (den < 0){
            den = -den;
            f->num = -(f->num);
        }
        f->den = den;
        result = true;
    }
    return result;
}

double fraction_getValue(const fraction* f){
    return (double)f->num/(double)f->den;
}

void fraction_print(const fraction* f){
    printf("%d/%d", f->num, f->den);
    return;
}

void fraction_simplify(fraction* f){
    int hcf = _getHCF(f->num, f->den);
    f->num /= hcf;
    f->den /= hcf;
    return;
}

int fraction_compare(const fraction* f1, const fraction* f2){
    int result = 0;
    double  r1 = fraction_getValue(f1),
            r2 = fraction_getValue(f2);
    if (r1 > r2) result = 1;
    else if (r1 < r2) result = -1;
    return result;
}

fraction* fraction_sum(const fraction* f1, const fraction* f2){
    int lcm = _getLCM(f1->den,f2->den);
    fraction* result = fraction_new();
    result->num = (f1->num * f2->den) + (f2->num * f1->den);
    result->den = lcm;
    fraction_simplify(result);
    return result;
}

fraction* fraction_subtract(const fraction* f1, const fraction* f2){
    int lcm = _getLCM(f1->den,f2->den);
    fraction* result = fraction_init((f1->num * f2->den) - (f2->num * f1->den), lcm);
    fraction_simplify(result);
    return result;
}

fraction* fraction_multiply(const fraction* f1, const fraction* f2){
    fraction* result = fraction_init(f1->num * f2->num, f1->den * f2->den);
    fraction_simplify(result);
    return result;
}

fraction* fraction_divide(const fraction* f1, const fraction* f2){
    fraction* result = fraction_init(f1->num * f2->den, f1->den * f2->num);
    fraction_simplify(result);
    return result;
}

int _getHCF(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int _getLCM(int a, int b){
    a = abs(a);
    b = abs(b);
    return (a*b)/_getHCF(a,b);
}