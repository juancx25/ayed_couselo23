#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - binary tree node: nodo de árbol binario.
 * SBT - Search Binary Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */
/**************************************************************/

/**
 *  Binary Tree Node Struct
 */
#define t_elem_btree int

typedef struct _btn {
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
} btn;

/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un valor t_elem_btree
 */
btn* btn_new(t_elem_btree value) {
    btn* newNode = (btn*)malloc(sizeof(btn));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Elimina un nodo, si tiene hijos elimina sus hijos también.
 */
void btn_free(btn** node) {
    if (node && *node){
        btn_free(&((*node)->left));
        btn_free(&((*node)->right));
        free(*node);
    }
}

/** 
 * Busca un nodo con un determinado elemento y devuelve su referencia
 * Se busca el nodo en pre-order (debe recorrer todo el árbol no hay un criterio de ordenamiento)
 * Debe devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL
 */ 
btn** btn_find(btn** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)) {
    btn** result = NULL;
    if (*node){
        if (cmp((*node)->value, value) == 0){
            result = node;
        }
        else{
            btn_find(&((*node)->left), value, cmp);
            btn_find(&((*node)->right), value, cmp);
        }
    }
    return result;
}

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */
int btn_isLeaf(btn *node) {
    return (!node->left && !node->right);
}

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */
int btn_count(btn *node) {
    int result = 0;
    if (node != NULL) {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
}

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert(btn **node, btn *newNode) {
    int result = 0;
    if (!*node){
        *node = newNode;
        result = 1;
    } 
    else {
        if (btn_count((*node)->left) - btn_count((*node)->right)  >  0){
            btn_insert(&((*node)->right), newNode);
            result = 1;
        }
        else {
            btn_insert(&((*node)->left), newNode);
            result = 1;
        }
    }
    return result;
}

/**
 * Agrega un valor a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert_value(btn **node, int value) {
    int result = 0;
    btn* newNode = btn_new(value);
    btn_insert(node, newNode);
    result = 1;
    return result;
}


/**
 * Determinar el nivel de un nodo.
 * - Recibe como entrada la raíz, un valor y una función de comparación de valores.
 */
int _btn_level(btn *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree)) {
    int result = -1;
    if (node){
        if (cmp(value, node->value) == 0){
            result = level;
        }
        else{
            result = _btn_level(node->left, value, level+1, cmp);
            if (result == -1) _btn_level(node->right, value, level+1, cmp);
        }
    }
    return result;
}

int btn_level(btn* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree)) {
    return _btn_level(root, value, 0, cmp);
}


/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
int _max(int a, int b) { return (a > b) ? a : b; }

/**
 * Devuelve la altura de un BTN
 */
t_elem_btree btn_height(btn *node) {
    int result = 0;
    if (node){
        int h1 = btn_height(node->left);
        int h2 = btn_height(node->right);
        if (h1 > h2){
            result = 1 + h1;
        }
        else result = 1 + h2;
    }
    return result;
}

/**
 * Recorrido de un BT en inorden
 */
void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;
    btn_inorder(node->left, btn_do, ctx);
    btn_do(node, ctx);
    btn_inorder(node->right, btn_do, ctx);
}

/**
 * Recorrido de un BT en postorder
 */
void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;
    btn_postorder(node->left, btn_do, ctx);
    btn_postorder(node->right, btn_do, ctx);
    btn_do(node, ctx);
}

/**
 * Recorrido de un BT en preorder
 */
void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;
    btn_do(node, ctx);
    btn_preorder(node->left, btn_do, ctx);
    btn_preorder(node->right, btn_do, ctx);
}


/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)) {
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);
    

    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    
    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*)) {
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
}


#endif