#include "Jogo.h"

/*
 * Recebe uma nova jogada
 */
int Jogo::Jogada(int x, int y) {
    // se a coordenada x for inválida
    // retorna 0 indicando que a jogada não foi feita
    if (x > 2) {
        return 0;
    }

    // se a coordenada y for inválida
    // retorna 0 indicando que a jogada não foi feita
    if (y > 2) {
        return 0;
    }

    // se a cédula estiver ocupada, retorna 0 indicando que a jogada não foi feita
    int simbolo = this->tabuleiro[x][y];

    if (simbolo != VAZIO) {
        return 0;
    }

    // dado que a jogada é válida

    // insere o simbolo no tabuleiro
    this->tabuleiro[x][y] = this->jogadorAtual->simbolo;

    // inverte o jogador com a vez apontado para o adversário
    if (this->jogadorAtual->simbolo == this->jogadorCruz.simbolo) {
        this->jogadorAtual = &this->jogadorBola;
    } else {
        this->jogadorAtual = &this->jogadorCruz;
    }

    return 1;
}

/*
 * Verifica uma determinada combinação representada por uma 3-upla de simbolos
 */
int Jogo::verificaCombinacao(int casa1, int casa2, int casa3) {
    if (casa1 == casa2 && casa1 == casa3) {
        return casa1;
    }

    return VAZIO;
}

/*
 * verifica o resultado
 */
int Jogo::verificaResultado() {
    /*
     * Mapeia as coordenadas de todas 3-uplas possíveis de serem combinadas para ganhar o jogo
     * Linhas, colunas e diagonais
     */
    int combinacoesValidas[][3][2] = {
        {{0, 0}, {1, 0}, {2, 0}}, // primeira linha
        {{0, 1}, {1, 1}, {2, 1}}, // segunda linha
        {{0, 2}, {1, 2}, {2, 2}}, // terceira linha

        {{0, 0}, {0, 1}, {0, 2}}, // primeira coluna
        {{1, 0}, {1, 1}, {1, 2}}, // segunda coluna
        {{2, 0}, {2, 1}, {2, 2}}, // terceira coluna

        {{0, 0}, {1, 1}, {2, 2}}, // diagonal1
        {{0, 2}, {1, 1}, {2, 0}}, // diagonal2
    };

    /*
     * Testa cada uma das combinações
     */
    for (int i = 0; i < 8; i++) {
        int casa1 = this->tabuleiro[combinacoesValidas[i][0][0]][combinacoesValidas[i][0][1]];
        int casa2 = this->tabuleiro[combinacoesValidas[i][1][0]][combinacoesValidas[i][1][1]];
        int casa3 = this->tabuleiro[combinacoesValidas[i][2][0]][combinacoesValidas[i][2][1]];

        int resultado = this->verificaCombinacao(casa1, casa2, casa3);

        /*
         * se o resultado for diferente de VAZIO, temos um vencedor
         */
        if (resultado != VAZIO) {
            return resultado;
        }
    }

    return VAZIO;
}

/*
 * Verifica se o jogo acabou
 */
int Jogo::acabou() {
    /*
     * Se existe um ganhador, o jogo acabou
     */

    int resultado = this->verificaResultado();

    if (resultado != VAZIO) {
        return 1;
    }

    /**
     * Se não existe um ganhador e existe alguma cédula VAZIA, então o jogo ainda não acabou
     */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->tabuleiro[i][j] == VAZIO) {
                return 0;
            }
        }
    }

    /* se todas cédulas estão preenchidas o jogo acabou
     *
     */
    return 1;
}

/*
 * reinicia o jogo
 */
void Jogo::Reinicia() {
    /*
     * Limpa as cédulas
     */

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->tabuleiro[i][j] = VAZIO;
        }
    }

    /*
     * Cruz começa
     */
    this->jogadorAtual = &this->jogadorCruz;
}

/*
 * Verifica o valor em uma data posição
 */
char Jogo::valorEm(int x, int y) {
    return this->tabuleiro[x][y];
}

