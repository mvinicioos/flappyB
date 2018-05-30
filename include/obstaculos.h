#include <iostream>
#include <cstdlib>
//Funções de auxilio para os obstáculos gerados no jogo.

/**
 * Calcula o valor de variação dos obstaculos permitido
*/
int obstaculosValorVariacao(int valorSuperiorCenario, int valorInferiorCenario){
    return valorSuperiorCenario - valorInferiorCenario;
}

/**
 * Retorna através de dois ponteiros os valores de variação dos obstaculos do cenário 
*/
void obstaculosVariacao(int* variacaoInferior, int* variacaoSuperior, int valorDeVariacao){
    int ondeVariar = rand() % 1;
    int quantoVaria = rand() % valorDeVariacao;
    
    if(ondeVariar%2 == 0){
        *variacaoInferior = -quantoVaria;
        *variacaoSuperior = quantoVaria;
    }else{
        *variacaoInferior = quantoVaria;
        *variacaoSuperior = -quantoVaria;    
    }
}
