#include <iostream>


//Verifica colisão com o piso do cenario
bool cenarioColisaoInferior(int piso, float tamanhoObjeto, float coordenadaAtual){
    bool colisao = false;

    if((piso + tamanhoObjeto) <= coordenadaAtual){
        colisao = true;
    }

    return colisao;

}
