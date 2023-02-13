#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree_search.c"

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

/**************************************************************/
/*                         ÁRBOLES AVL                        */
/**************************************************************/

/**
 * Devuelve el Factor de Equilibrio (o Factor de Balanceo) de un BTN
 */
int btn_balance_factor(btn *node) {
    /**** COMPLETAR ****/
}


/**
 * Realiza una rotación a izquierda sobre un nodo.
 * (el nodo debe tener un hijo a derecha).
 */
int btn_left_rotation(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Realiza una rotación a derecha sobre un nodo.
 * (el nodo debe tener un hijo a la izquierda).
 */
int btn_right_rotation(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve 1 si verifica que el nodo es raíz de un subárbol AVL.
 * Devuelve 0 si no lo es.
 */
int btn_is_avl(btn *node) {
    /**** COMPLETAR ****/
}


/**
 * Balancea nodo de un árbol AVL.
 */
int btn_balance(btn **node) {
    /**** COMPLETAR ****/
}


/**
 * Balancea un SBT convirtiéndolo en un árbol AVL.
 */
int btn_balance_tree(btn **node) {
    if (node == NULL) return 0;
    if (*node == NULL) return 0;
    /**** COMPLETAR ****/
}


/**
 * Inserta un Nodo en un AVL
 * Esta es una versión simplificada que utiliza la función de
 * inserción de un SBT y luego balancea todo el árbol.
 * Notar que al intentar balancear todo el árbol recorre todos
 * los nodos, cuando en realidad por la inserción solo se ven
 * afectados los ancestros del nodo insertado (es decir que son
 * solo estos los que pueden quedar desbalanceados)
 */
int avl_insert_node_simple(btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Inserta un Nodo en un AVL
 * Recorre una vez hasta la insersión y cuando "vuelve" balancea
 * no usa sbt_insert_node y ni btn_balance_tree
 * solo usa btn_balance
 */
int avl_insert_node(btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree)) {
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;

    /**** COMPLETAR ****/
}

/**
 * Inserta un Valor en un AVL
 */
int avl_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un Valor de un AVL
 */
int avl_remove_value(btn **node, int value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}
