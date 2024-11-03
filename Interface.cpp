#include <cstdlib>
#include "Interface.h"
#include <iostream>
#include "Jogo.h"
#include <termios.h>
#include <unistd.h>

using namespace std;

/*
 * Limpa o console do terminal
 */
void Interface::limpaTela() {
    system("clear");
}

/*
 * Dado um determinado simbolo
 *
 * retorna o elemento para interface
 */
string Interface::simbolo(char simbolo, int x, int y) {
    /*
     * Se o cursor estiver em cima dessa cédula, exibe o símbolo de seleção
     */
    if (this->cursorX == x && this->cursorY == y) {
        return "[]";
    }

    /*
     * Se não exibe o simbolo correspondente
     */
    switch (simbolo) {
        case BOLA:
            return "()";
        case CRUZ:
            return "><";
        default:
            return "  ";
    }
}


/*
 * Renderiza o jogo
 */
void Interface::renderiza(Jogo jogo) {
    // Enquanto o jogo estiver rodando
    do {
        this->limpaTela();

        /*
         * Imprime os tabuleiro na tela
         */
        for (int i = 0; i < 3; i++) {
            char buffer[30];
            sprintf(buffer, "| %s | %s | %s |", this->simbolo(jogo.valorEm(0, i), 0, i).c_str(),
                    this->simbolo(jogo.valorEm(1, i), 1, i).c_str(),
                    this->simbolo(jogo.valorEm(2, i), 2, i).c_str());

            cout << buffer << endl;
        }

        /*
         * Exibe informações dos comandos
         */
        char buffer[1024];

        sprintf(buffer, "Jogador atual: %c", jogo.jogadorAtual->simbolo);

        cout << buffer << endl;
        cout << "Use os seguintes comandos: " << endl;
        cout << "W A S D para direções" << endl;
        cout << "ENTER para fazer a jogada" << endl;
        cout << "R para reiniciar" << endl;
        cout << "Q para sair" << endl;
        cout << "\033[?25l";

        this->ultimoComando = this->leComando();


        /*
         * Se o comando for pra esquerda
         */
        if (this->ultimoComando == COMANDO_ESQUERDA) {
            /*
             * pula para coluna da esquerda
             */
            this->cursorX--;

            /*
             * Se a nova cédula estiver preenchida, pula pra esquerda denovo
             */
            if (jogo.valorEm(this->cursorX, this->cursorY) != VAZIO) {
                this->cursorX--;
            }

            /*
             * Se estiver no máximo da esquerda, seta para primeira coluna
             */
            if (this->cursorX < 0) {
                this->cursorX = 0;
            }
        }

        if (this->ultimoComando == COMANDO_DIREITA) {
            /*
             * pula para coluna da direita
             */
            this->cursorX++;


            /*
             * Se a nova cédula estiver preenchida, pula pra direita denovo
             */
            if (jogo.valorEm(this->cursorX, this->cursorY) != VAZIO) {
                this->cursorX++;
            }

            /*
             * Se estiver no máximo da direita, seta para ultima coluna
             */
            if (this->cursorX > 2) {
                this->cursorX = 2;
            }
        }

        if (this->ultimoComando == COMANDO_BAIXO) {
            /**
             * Pula para linha de baixo
             */
            this->cursorY++;

            /*
             * Se a linha estiver preenchida, pulara para baixo denovo
             */
            if (jogo.valorEm(this->cursorX, this->cursorY) != VAZIO) {
                this->cursorY++;
            }

            /*
             * Se estiver na última linha, permanece
             */
            if (this->cursorY > 2) {
                this->cursorY = 2;
            }
        }

        if (this->ultimoComando == COMANDO_CIMA) {
            /*
             * Sobe uma linha
             */
            this->cursorY--;

            /*
             * Se estiver preenchida, sobe mais uma
             */
            if (jogo.valorEm(this->cursorX, this->cursorY) != VAZIO) {
                this->cursorY--;
            }

            /*
             * Se chegou no topo, permanece
             */
            if (this->cursorY < 0) {
                this->cursorY = 0;
            }
        }

        /*
         * Quando o usuário confirma a jogada
         */
        if (this->ultimoComando == COMANDO_CONFIRMA) {
            /*
             * Faz a jogada
             */
            jogo.Jogada(this->cursorX, this->cursorY);

            /*
             * Move o cursor para uma próxima cédula vazia
             */
            while (jogo.valorEm(this->cursorX, this->cursorY) != VAZIO) {
                this->cursorX++;

                if (this->cursorX > 2) {
                    this->cursorX = 0;
                    this->cursorY++;
                }
            }
        }

        /*
         * Se o usuário quiser reiniciar o jogo
         */
        if (this->ultimoComando == COMANDO_REINICIAR) {
            jogo.Reinicia();
        }

        /*
         * Verifica se o jogo acabou
         */
        if (jogo.acabou()) {
            this->limpaTela();

            /*
             * Exibe resultado
             */
            int resultado = jogo.verificaResultado();

            if (resultado == VAZIO) {
                cout << "Deu velha!" << endl;
                return;
            }

            if (resultado == BOLA) {
                cout << "BOLA GANHOU!" << endl;
                return;
            }

            if (resultado == CRUZ) {
                cout << "CRUZ GANHOU!" << endl;
                return;
            }
        }
    } while (this->ultimoComando != COMANDO_SAIR);
}

/*
 * Função pega na internet para ler o terminal
 */
char Interface::leComando() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON; // desativa o modo canônico
    old.c_lflag &= ~ECHO; // desativa o eco do terminal
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}


