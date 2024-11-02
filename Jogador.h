#ifndef JOGADOR_H
#define JOGADOR_H

/*
 * A class jogador é uma entidade que representa um jogador
 * Basicamente só tem um atributo que é o simbolo que ele está jogando (CRUZ OU BOLA)
 */
class Jogador
{
public:
    int simbolo;

    Jogador(int simbolo) : simbolo(simbolo)
    {
    }
};

#endif // JOGADOR_H
