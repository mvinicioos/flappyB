#include <iostream>
#include <cstdlib>
//Funções de auxilio para os obstáculos gerados no jogo.

/**
 * Retorna através de dois ponteiros os valores de variação dos obstaculos do cenário 
 * variacaoInferior: soma ao Y do objeto inferior
 * variacaoSuperior: soma ao Y do objeto superior
*/
void obstaculosVariacao(int* variacaoInferior, int* variacaoSuperior, int valorDeVariacao){
    int ondeVariar = rand() % 3;
    int quantoVaria = rand() % valorDeVariacao;
    
    if(ondeVariar%2 == 0){
        *variacaoInferior = -quantoVaria;
        *variacaoSuperior = quantoVaria;
    }else{
        *variacaoInferior = quantoVaria;
        *variacaoSuperior = -quantoVaria;    
    }
}

/**
 * Calcula o valor de variação dos obstaculos permitido
*/
int obstaculosValorVariacao(int valorSuperiorCenario, int valorInferiorCenario){
    return valorSuperiorCenario - valorInferiorCenario;
}
