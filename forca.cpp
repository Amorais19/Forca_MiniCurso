#include <iostream>
// incluindo uma biblioteca que permite trabalhar com dados de entrada (cin - valor informado) e saida (cout - texto)

using namespace std;
// permite que utilizemos objetos como cin e cout como se eles pertencessem a biblioteca padrao sem precisar do std
// se nao tivesse std -> std::cout << "oi";

// vamos fazer uma separacao das partes que cuidam da interacao com o usuario (main), para a parte que define
// como o jogo deve funcionar e o que deve conter/seguir (classe)
// a classe armazena os dados (qtd palavras e vet com as palavras) e o comportamento (funcoes) do nosso jogo 

class forca{ // criando uma classe chamada forca
    public: // permite que os atributos sejam acessados diretamenta fora da classe, como na funcao main
    // alem do public tem o private que envolve o encapsulamento (dados sensiveis ocultados aos usuarios)
    const static int TAM = 10; // variavel imutavel (const) e podera ser acessada por todos na classe (static)
    string palavras[TAM] = {"macaco", "aranha", "elefante", "cavalo", "bezouro", "barata", "tigre", "urso", "abelha", "joaninha"};
    // foi criado um vetor do tipo string do tamanho informado em TAM contendo nossas palavras
    // agora serao chamada as funcoes na ordem que elas precisam ser executadas
    string sortear(); // sorteia a palavra
    string montarp2(string); // monta os tracinhos conforme a palavra escolhida
    string verificarLetra(string, string, char, bool*); // verifica se a letra informada faz parte da palavra
    bool verificaFimJogo(string); // verifica se as tentativas acabaram
}