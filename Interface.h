#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "Jogo.h"

/*
 * Define os comandos que serão lidos pelo teclado
 */
#define COMANDO_SAIR 'q'
#define COMANDO_ESQUERDA 'a'
#define COMANDO_DIREITA 'd'
#define COMANDO_CIMA 'w'
#define COMANDO_BAIXO 's'
#define COMANDO_CONFIRMA '\n'
#define COMANDO_REINICIAR 'r'

using namespace std;

/*
 * A classe interface é usada para gerenciar a interface de usuário do jogo
 */
class Interface {
public:
 /*
  * Recebe um jogo e renderiza ele na tela
  */
 void renderiza(Jogo jogo);

 Interface() : cursorX(0), cursorY(0) {
 }

private:
 /*
  * As propriedades cursorX e cursorY gerenciam em qual posição o cursor está na tela.
  * X -> Coluna
  * Y -> linha
  */
 int cursorX;
 int cursorY;

 /*
  * Armazena o ultimo comando inserido no teclado
  */
 char ultimoComando;

 /*
  * Método usado para limpar a tela a cada rodada
  */
 void limpaTela();

 /*
  * Método usado para determinar o que precisa ser escrito na tela.
  * Recebe o tabuleiro atual e a coordenada de qual campo deve ser escrito
  */
 string simbolo(char simbolo, int x, int y);

 /*
  * Lê um comando do teclado
  */
 char leComando();
};

#endif // INTERFACE_H
