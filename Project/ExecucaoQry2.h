#ifndef EXECUCAOQRY2_H
#define EXECUCAOQRY2_H

#include "Canvas.h"

/*
   Autor: Matheus Augusto Marques.
   Módulo executarQry2:
   Esse módulo contém os procedimentos necessários para manipulação de comandos do arquivo '.qry'.
 */

/*
   O procedimento executa o comando 'mv' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Migra linha de celular (num) para operadora
   opdest (su ou um). Num deve existir na operadora de origem (cc, mensagem de erro). Caso o num já exista na operadora de destino, uma mensagem de
   erro deve ser apresentada e operação não é efetuada. Se o celular estiver conectado a uma rádio-base da antiga operadora, ele deve ser desconectado e reconectado na torre mais próxima da nova operadora (supor que não
   movimentou-se)
 */
void executarQryMv(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'm?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Procura os moradores da quadra cujo cep é cep e Mostra mensagem de erro se quadra não existir. Se o morador existir, deve ser impresso nome, endereço, celular e operadora em um arquivo.
 */
void executarQryM(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'mr?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Procura os Moradores das quadras que estão inteiramente dentro da região determinada. Para cada quadra da região, Se o morador existir, deve ser impresso nome, endereço, celular e operadora do morador em um arquivo.
 */
void executarQryMr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'dm?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Imprime todos os dados do morador identificado
   pelo número do cpf. Caso o morador exista, seus dados pessoais
   endereço, o número de seu celular (se houver) e respectiva operadora, e coordenada geográfica de onde mora deve ser impresso em um arquivo.
   Além disso, colocar em um arquivo de extensão '.svg' um círculo (ou retângulo, ou outra forma geométrica) no lugar onde mora com seu cpf.
 */
void executarQryDm(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'de?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Imprime todos os dados do estabelecimento
   comercial identificado por cnpj.Se o estabelecimento existir, então seus dados
   (nome, descrição do tipo, etc), endereço e coordenada geográfica devem ser impresso em um arquivo texto. Além disso, colocar em um arquivo de extensão '.svg' um círculo (ou retângulo, ou outra forma geométrica) na coordenada geográfica do estabelimento.
 */
void executarQryDe(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'con' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Celular de número num conecta-se à rádio-base
   (da respectiva operadora) mais próxima. O
   usuário está no endereço cep/face/num.
   Obs. Não levar em consideração o raio de alcance
   da torre.
   SAIDA: arquivo .txt => Apresentar os dados do
   usuário (cpf, nome), a operadora do usuário, a
   identificação, a posicao e a distância da torre a
   qual se conectou.
   arquivo .svg => traçar uma linha entre a posição
   do usuário e a torre ao qual se conectou.
 */
void executarQryCon(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'mse?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Considere a região x,y,larg,alt. Quais são os
   moradores de uma quadra (dentro da região) que
   contenha um estabelecimento do tipo tp e que são
   do sexo sx (M ou F)?
   SAIDA: arquivo .txt => nome completo e endereço
   do morador.
 */
void executarQryMse(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'rip' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Infelizmente pessoa identificada por cpf morreu.
   Todos os dados armazenados sobre ela devem ser
   apagados (dados pessoais, dados sobre moradia e
   sobre sua linha móvel).
   SAIDA: arquivo .txt => imprimir os dados
   removidos de cada uma das estruturas. Por
   exemplo:
   RIP: José Silva, portador CPF, do sexo
   Masculino, nascido à 01/01/1920, residia no
   endereço CEP/NUM/FACE, usuário da linha
   móvel NUM da operadora SercomtUEL.
   arquivo .svg: colocar um losango preto, com um
   cruz branca no interior na residência do defunto.c
 */
void executarQryRip(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'lk?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Quais são os celulares conectados à rádio-base
   identificada por id?
   SAIDA: arquivo .txt=> listar (enumerar) o
   número dos celulares correntemente ligados à
   rádio-base.
   arquivo .svg => mostrar no mapa a rádio-base em
   questão e mostrar a posição dos celulares
   conectados a ela.
 */
void executarQryLk(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'rb?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Em que rádio-base o celular numcel está
   conectado?
 */
void executarQryRb(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'co?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Mostra, em ordem alfabética, o nome e o número
   do celular dos clientes de uma dada operadora de
   telefonia móvel. Lista os n primeiros nomes.
   SAIDA: arquivo .txt => mostra os dados de um
   cliente por linha
 */
void executarQryCo(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'lnr?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Mostra os celulares conectados as rádio-bases
   dentro da região delimitada pelo parâmetros x,
   y, larg, alt, da, se presente, operadora
   Sercomtuel (su) ou UELMobile (um).
   SAIDA: arquivo .txt => listar, para cada radio-
   base, os celulares conectados.
 */
void executarQryLnr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'ecq?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Lista os estabelecimentos de uma determinada
   quadra.
   SAIDA: arquivo .txt =>mostrar cnpj, nome, tipo e
   endereço de cada estabelecimento comercial.
 */
void executarQryEcq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'ecr?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Lista os estabelecimentos comerciais de um da
   tipo de, se presente, uma determinada região.
 */
void executarQryEcr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'tecq?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Lista os tipos de estabelecimentos comerciais de
   uma dada quadra.
   SAIDA: arquivo .txt =>mostrar, para cada tipo de
   estabelecimento comercial, listar o nome dos
   estabelecimentos daquele tipo.
 */
void executarQryTecq(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'tecr?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Quais são os tipos de estabelecimentos comerciais
   existentes numa dada região.
 */
void executarQryTecr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'dc?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Quem é o usuário da linha móvel de número num?
   SAIDA: arquivo .txt => mostrar dados pessoais
   do dono e nome da operadora .
 */
void executarQryDc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'lec?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Onde está (endereço) o celular de número num?
   SAIDA: arquivo .txt => mostrar dados pessoais
   do dono do celular e o endereço de onde o celular
   foi conectado pela última vez.
   arquivo .svg => mostrar no mapa a localização
   do celular
 */
void executarQryLec(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'lcc?' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Onde está (coordenada) o celular de número num?
   Semelhante à consulta lec?, porém, reporta a
   coordenada geográfica da localização do celular.
 */
void executarQryLcc(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);


/*
   O procedimento executa o comando 'dpr' do arquivo '.qry'. Esse procedimento realiza a seguinte operação: Desapropria região.
   Apagar quadras, hidrantes, etc dentro da região;
   desconectar celulares; etc
   SAIDA: arquivo .txt => listar o que foi removido
   arquivo .svg => elementos removidos não devem
   aparecer.
 */
void executarQryDpr(FILE *arqEntradaQry, FILE **arqSaidaT, Canvas canvas);

#endif
