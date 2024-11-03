# Documentação do Projeto: Jogo da Velha em C++

## Sumário

- [Visão Geral](#visão-geral)
- [Estrutura do Projeto](#estrutura-do-projeto)
  - [Arquivos do Projeto](#arquivos-do-projeto)
  - [Arquitetura do Código](#arquitetura-do-código)
- [Encapsulamento no Projeto](#encapsulamento-no-projeto)
- [Comandos do Jogo](#comandos-do-jogo)
- [Como Compilar e Executar](#como-compilar-e-executar)
  - [Compilação](#compilação)
  - [Execução](#execução)

## Visão Geral

Este projeto implementa um jogo da velha em C++ com uma interface ASCII no terminal. O jogo é baseado em um tabuleiro 3x3 e suporta interação via teclado, permitindo que dois jogadores façam suas jogadas alternadamente.

### Funcionalidades Principais

- **Jogabilidade de Dois Jogadores**: Representados por dois símbolos, `X` (CRUZ) e `O` (BOLA).
- **Interface Gráfica em ASCII**: Exibe o tabuleiro em formato de console.
- **Controle de Cursor**: Mova o cursor sobre o tabuleiro com as teclas `W`, `A`, `S`, `D` e selecione a jogada com `Enter`.
- **Comandos do Jogo**: Reinicie com `R` ou saia com `Q`.

## Estrutura do Projeto

### Arquivos do Projeto

1. **main.cpp**: Arquivo principal que inicia o jogo.
2. **Interface.h e Interface.cpp**: Define e implementa a interface de usuário e a interação com o jogador.
3. **Jogo.h e Jogo.cpp**: Contêm a lógica principal do jogo, incluindo verificação de vitória e gerenciamento do tabuleiro.
4. **Jogador.h e Jogador.cpp**: Define a classe `Jogador`, representando cada jogador e seu símbolo.

### Arquitetura do Código

- **Classe `Jogo`**: Gerencia o estado do jogo e contém o tabuleiro 3x3.

  - **Métodos Principais**:
    - `Jogada(int x, int y)`: Realiza uma jogada na posição `(x, y)`.
    - `verificaResultado()`: Verifica se houve um vencedor.
    - `acabou()`: Determina se o jogo terminou.
    - `Reinicia()`: Reinicia o jogo com o tabuleiro vazio.

- **Classe `Jogador`**: Representa cada jogador, que possui um símbolo (`X` ou `O`).

- **Classe `Interface`**: Controla a exibição do jogo no terminal e a interação com o usuário.
  - **Atributos**:
    - `cursorX` e `cursorY`: Posição do cursor no tabuleiro.
    - `ultimoComando`: Guarda o último comando inserido pelo jogador.
  - **Métodos Principais**:
    - `renderiza(Jogo jogo)`: Exibe o tabuleiro no terminal e atualiza conforme o jogo avança.
    - `simbolo(char simbolo, int x, int y)`: Define como exibir o símbolo, destacando a célula onde o cursor está posicionado.
    - `limpaTela()`: Limpa o console para renderizar o tabuleiro atualizado.
    - `leComando()`: Lê um comando do teclado sem bloqueio de entrada.

## Encapsulamento no Projeto

O encapsulamento é um dos princípios fundamentais da programação orientada a objetos, e ele está presente nas principais classes deste projeto, ajudando a proteger os dados e a organizar o código.

1. **Classe `Jogo`**:

   - Os atributos `tabuleiro`, `jogadorBola`, `jogadorCruz` e `jogadorAtual` estão encapsulados dentro da classe. Esses atributos representam o estado do jogo e só podem ser acessados e modificados através dos métodos públicos da classe, como `Jogada`, `verificaResultado`, `acabou` e `Reinicia`.
   - O encapsulamento impede que o código fora da classe altere o estado do jogo diretamente, garantindo que o fluxo e as regras do jogo sejam respeitados.

2. **Classe `Interface`**:

   - Os atributos `cursorX`, `cursorY` e `ultimoComando` estão encapsulados e usados apenas internamente para gerenciar a interação com o usuário.
   - Os métodos públicos, como `renderiza` e `leComando`, controlam como a interface é exibida e como os comandos são lidos, sem permitir que o código externo interfira diretamente na posição do cursor ou nos comandos.

3. **Classe `Jogador`**:
   - A classe `Jogador` encapsula o atributo `simbolo`, que representa o símbolo que o jogador usa no jogo (`X` ou `O`). Esse símbolo é acessível apenas por meio de métodos da classe `Jogador` e por outras classes que têm permissão para utilizá-lo.
   - Esse encapsulamento garante que o símbolo de cada jogador permaneça consistente e não seja alterado diretamente.

### Benefícios do Encapsulamento

- **Segurança**: Os dados do jogo, como o estado do tabuleiro e o jogador atual, estão protegidos de alterações não autorizadas. Apenas métodos específicos da classe `Jogo` podem modificar o estado do jogo, o que evita erros acidentais e mantém a integridade do jogo.
- **Manutenção e Flexibilidade**: Encapsular a lógica do jogo e da interface facilita a manutenção do código, pois as alterações em uma parte não impactam outras áreas.
- **Clareza**: O encapsulamento permite organizar o código de forma clara e intuitiva, agrupando métodos e dados relacionados, facilitando a leitura e entendimento do código.

## Comandos do Jogo

- **Movimentação do Cursor**:
  - `W`: Move para cima.
  - `A`: Move para a esquerda.
  - `S`: Move para baixo.
  - `D`: Move para a direita.
- **Ações de Jogo**:
  - `Enter`: Confirma a jogada na posição atual do cursor.
  - `R`: Reinicia o jogo, limpando o tabuleiro.
  - `Q`: Sai do jogo.

## Como Compilar e Executar

### Compilação

No terminal, use o seguinte comando para compilar todos os arquivos:

```
  make compila
```

obs.: será executado o seguinte código:

```bash
g++ -g main.cpp Interface.cpp Jogo.cpp Jogador.cpp -o jogo-da-velha
```

![compilação](/src/cp.png)

### Execução

```
./jogo-da-velha
```

![execução](/src/ex.png)

![jogo](/src/game.png)
