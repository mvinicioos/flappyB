#include <iostream>


/**
 * Posiciona Objeto no limite inferior do cenário
*/
float cenarioPosicionaObjetoInf(float limiteInferior, float tamanhoObjeto){
    return limiteInferior + (tamanhoObjeto/2);
}
/**
 * Posiciona o objeto no limite superior do cenário
*/
float cenarioPosicionaObjetoSup(float limiteSuperior, float tamanhoObjeto){
    return limiteSuperior - tamanhoObjeto/2;
}

bool cenarioColisaoPersonagemObstaculo(float personagemLocalizacao, float personagemTamanho, float obstaculoLocalizacao, float obstaculoTamanho){
    bool colisao = false;

    float personagemInicio     = personagemLocalizacao - (personagemTamanho / 2);
    float personagemFinal      = personagemLocalizacao + (personagemTamanho / 2);

    float obstaculoIntervaloInicial     = obstaculoLocalizacao - (obstaculoTamanho/2);
    float obstaculoIntervaloFinal       = obstaculoLocalizacao + (obstaculoTamanho/2);

    if((personagemFinal >= obstaculoIntervaloInicial && personagemFinal <= obstaculoIntervaloFinal) ||
      (personagemInicio >= obstaculoIntervaloInicial && personagemInicio <= obstaculoIntervaloFinal)){
        colisao = true;
    }
    

    return colisao;    
}