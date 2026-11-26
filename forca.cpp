#include <iostream>
// incluindo uma biblioteca que permite trabalhar com dados de entrada (cin - valor informado) e saida (cout - texto)

#include <time.h>
// incluindo a biblioteca que permite utilizar a funcao para gerar numeros aleatorios - srand

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
};

// funcoes "forca::nome da funcao" indica que a funcao foi definida dentro da classe
string forca::sortear(){ // a funcao precisa ser string pois o valor retornado sera uma palavra
    int n = rand()%TAM; // aqui estamos gerando um numero aleatorio com base na variavel TAM = 10
    return palavras[n]; // aqui estamos retornando a palavra sorteada da forca 
}

string forca::montarp2(string p1){
    string p2 = ""; // variavel que ira receber tracinhos de acordo com a qtdd de letras da palavra
    for(int i=0; i<p1.length(); i++){ // laco de repeticao do tamanho da palavra 
        p2 += "-"; // colocando a qtdd de letras em tracos para montar a forca
    }
    return p2; // retornando minha palavra p2 em tracinhos
}

// a funcao contem um ponteiro pois precisa retornar a letra e uma variavel bool
// mas o c++ so permite um retorno, assim o ponteiro deixa acessar o valor pelo endereco de memoria
string forca::verificarLetra(string p1, string p2, char L, bool* acertei){ 
    *acertei = false; // definindo o acertei igual a false pra ele so responder verdadeiro se for a letra certa
    for(int i=0; i<p1.length(); i++){ // laco de repeticao para percorrer a palavra 
        if(L == p1[i]){ // conferindo se minha letra e igual a letra da palavra em todas as posicoes
            p2[i] = L; // trocando o - pela minha letra informada na posicao correta caso letra seja certa
            *acertei = true; // atribuindo valor verdadeiro para nao contabilizar como jogada errada
        }
    }
    return p2; // retorna minha palavra p2 com as letras nas posicoes corretas caso tenha acertado
}

bool forca::verificaFimJogo(string p2){
    for(int i=0; i<p2.length(); i++){ // laco de repeticao para passar pela p2
        if(p2[i] == '-'){ // comparando se meu indice i da p2 e igual ao char informado ('' = char e "" = string)
            return false; // vai estar conferindo se a palavra foi completada, caso nao, perdeu
        }
    }
}

int main(){
    forca f; // criando uma nomenclatura para minha classe forca
    int jogadas; // variavel que ira contabilizar as jogadas de acordo com a quantidade de vidas que estipularmos
    string p1, p2, letras; // strings que irao receber nossas palavras e as letras 
    char L; // variavel que ira receber nossa letra informada
    bool acertei; // variavel qe ira validar se foi a letra esta certa ou nao
    srand(time(NULL));

}