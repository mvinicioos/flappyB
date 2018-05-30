#include <iostream>

/**
 * Posiciona Objeto no limite inferior do cenário
*/
float cenarioPosicionaObjetoInf(float limiteInferior, float tamanhoObjeto){
    return limiteInferior + tamanhoObjeto/2;
}
/**
 * Posiciona o objeto no limite superior do cenário
*/
float cenarioPosicionaObjetoSup(float limiteSuperior, float tamanhoObjeto){
    return limiteSuperior - tamanhoObjeto/2;
}
