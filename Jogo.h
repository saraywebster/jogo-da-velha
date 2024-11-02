#ifndef JOGO_H
#define JOGO_H
#include "Jogador.h"

/*
 * Esses são os simbolos que serão gravados em memória para uma das possibilidades de um campo
 * VAZIO é um campo que ainda não foi selecionado
 */
const char BOLA = 'O';
const char CRUZ = 'X';
const char VAZIO = ' ';

class Jogo {
 /*
  *  Esse método verifica se uma determinada combinação ganha o jogo ou não
  *
  */
 int verificaCombinacao(int casa1, int casa2, int casa3);

 /*
  * Armazena instâncias dos jogadores
  */
 Jogador jogadorBola;
 Jogador jogadorCruz;

 /*
  * O tabuleiro é uma simples matriz vetorial 3x3
  */
 char tabuleiro[3][3];

public:
 /*
  * Ponteiro que determina qual o jogador está com a vez
  */
 Jogador *jogadorAtual;

 /*
  * Inicializa um jogo com tabuleiro vazio e com um jogador para cada simbolo
  */
 Jogo(): jogadorBola(BOLA), jogadorCruz(CRUZ), tabuleiro{
          {VAZIO, VAZIO, VAZIO},
          {VAZIO, VAZIO, VAZIO},
          {VAZIO, VAZIO, VAZIO},
         } {
  this->jogadorAtual = &this->jogadorCruz;
 };

 char valorEm(int x, int y);

 /*
  * Recebe a coordenada da jogada atual
  */
 int Jogada(int x, int y);

 /*
  * Verifica quem ganhou
  * BOLA
  * CRUZ
  * ou se deu velha
  */
 int verificaResultado();

 /*
  * Verifica se o jogo acabou
  * Se alguém ganhou
  * ou deu velha
  */
 int acabou();

 /*
  * Reinicia o jogo
  */
 void Reinicia();
};


#endif //JOGO_H
