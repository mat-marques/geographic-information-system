#ifndef STACK_H
#define STACK_H
#include <stdio.h>

typedef void* Stack;
typedef void* ItemS;
typedef void (*eraseItemS)(ItemS);

/*
   Autor: Matheus Augusto Marques.
   Tad: Stack
   Definição:
   Pilha ou Stack é um tipo especial de lista linear em que todas as operações de inserção e remoção são realizadas pela mesma extremidade chamada topo.
   Os elementos são removidos na ordem do programa inversa daquela em que foram inseridos de modo que o último elemento que entra é sempre o primeiro a ser executado , por isto este tipo de estrutura é chamada LIFO (Last In - First Out) ou FILO (First In - Last Out).
 */


/*
   Cria um pilha vazia.
   O tamanho de uma pilha vazia é zero.
 */
Stack createStack();


/*
   Retorna a quantidade de elementos armazenados na pilha.
 */
int lengthStack(Stack stack);


/*
   Insere um elemento ItemS no topo de stack.
   Retorna o inteiro 1 se a inseção foi realizada. 0 caso não.
 */
int insertTop(Stack stack, ItemS item);


/*
   Remove um elemento ItemS do topo de stack.
   Retorna o inteiro 1 se a remoção foi realizada. 0 caso não.
 */
int removeTop(Stack stack, eraseItemS func);


/*
   Retorna um elemento Items armazenado no topo de stack.
   Retorna NULL caso stack for vazia.
 */
ItemS getItemTop(Stack stack);

/*
   Apaga a base da pilha.
 */
void eraseBaseStack(Stack stack);


/*
   Apaga todos os elementos presetes na pilha. A função de remoção deve ser fornecidad pelo usuário. Caso não se deseje apagar os ItemS da pilha, basta fornecer NULL como parametro.
   Retorna o inteiro 1 se a remoção foi realizada. 0 caso não.
   Caso a remoção seja realizada stack será uma pilha vazia.
 */
int eraseStack(Stack stack, eraseItemS func);


#endif
