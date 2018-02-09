#ifndef QUADTREE_H
#define QUADTREE_H

#include "List.h"
typedef void* QuadTree;
typedef void* ItemQt;
typedef void* Region;

/*
   Os arquivos .c que incluirem esse tad devem implementar as funções showItem,
   eraseItem e compareToQt. As funções ao serem implementadas não precisam possuir os nome listados acima, mas sim os mesmos parâmetros.
 */
typedef void (*showItem)(ItemQt);
typedef void (*eraseItem)(ItemQt);
typedef int (*compareToQt)(ItemQt, ItemQt);

/*
   Autor: Matheus Augusto Marques.
   Tad QuadTree
   Definição: Quadtree é uma estrutura de dados hierárquia bidimensional criada com o intuito de dividir uma região em quatro quadrantes. Os quadrantes que uma QuadTree pode possuir são nordeste(NE), noroeste(NW), sudeste(SE) e sudoeste(SW). Cada nó pertencente a QuadTree possui quatro filhos, no qual esses filhos representam os quadrantes.
 */


/*
   A função cria e retorna uma quadtree vazia.
   seu comprimento é zero.
 */
QuadTree createQuadTree();


/*
   O procedimento insere um item com as coordenadas x e y na QuadTree.
   Retorna a quantidade de comparações para inserir um item na árvore.
 */
long int insertQuadTree(QuadTree tree, ItemQt item, double x, double y);


/*
   O procedimento pega um elemento por vez da QuadTree e aplica no procedimento "function" implementado pelo usuário. Esse procedimento deve de alguma forma realizar alguma operação sobre o item contido no nó da QuadTree.
 */
void showQuadTree(QuadTree tree, showItem function);


/*
   A função retorna a quantidade de elementos presente na QuadTree.
   Retorna zero caso a QuadTree seja vazia.
 */
long int lenghtQuadTree(QuadTree tree);


/*
   A função remove apenas o nó da QuadTree e retorna o elemento contido nesse nó ao usuário. A função que compara se um elemento contido na árvore é igual a variável item deve ser implementado pelo usuário. A função "function" deve retornar 1 caso os elementos sejam iguais e zero caso contrário.
   qtdR é a quantidade de comparações feitas para ser removido um item da QuadTree.
 */
ItemQt removeQuadTreeItemI(QuadTree tree, ItemQt item, compareToQt function, long int *qtdR);


/*
   A função remove apenas o nó da QuadTree e retorna o elemento contido nesse nó ao usuário. A função que compara se um elemento contido na árvore é igual a variável item deve ser implementado pelo usuário. A função "function" deve retornar 1 caso os elemento sejam iguais e zero caso contrário.
   A variável list ao fim da função contém todos os elementos filhos do nó removido. Esses nós devem ser reinseridos novamente na árvore pelo usuário.
   A variável list deve ser uma lista vazia.
 */
ItemQt removeQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function, List list);


/*
   A função retorna um conjunto - estrutura de dados lista- de elementos contidos em uma região no espaço especificado pela variável region. Essa região pode ser um círculo, quadrado, retângulo etc.
   A função que compara se um elemento esta dentro de region deve ser implementado pelo usuário. A função "function" deve retornar 1 caso o elemento esteja em region e zero caso contrário.
   Retona uma lista vazia se nenhum elemento estiver em region.
 */
List getElementsByRegion(QuadTree tree, Region region, compareToQt function);



ItemQt getNearestPoint(QuadTree tree, double x, double y);



/*
   A função procura e retorna um determinado item especificado pela variável item.
   As comparações entre o os elementos da árvore e o item são feitos através da função implementada pelo usuário. A função "function" deve retornar 1 caso o elemento esteja em region e zero caso contrário.
   Caso o elemento não exista na QuadTree é retornado null.
 */
ItemQt searchQuadTreeItem(QuadTree tree, ItemQt item, compareToQt function);


/*
   A função procura e retorna um elemento na árvore através de uma dada coordenada x e y.
   Caso o elemento não exista nas coordenadas especificadas é retornado null ao usuário.
 */
ItemQt searchQuadTreeByCoordinate(QuadTree tree, double x, double y);


/*
   O procedimento apaga todos os nós da QuadTree. Quando o processo de eliminação ocorre todos os elementos da QuadTree são removidos. Os itens inseridos com a função insertQuadTree são eliminados pela função "function" implementada pelo usuário.
 */
void eraseQuadTreeNode(QuadTree tree, eraseItem function);


/*
   O procedimento apaga a base da QuadTree. Uma base é criada pela função createQuadTree.
 */
void eraseQuadTreeBase(QuadTree tree);

#endif
