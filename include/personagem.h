#include <iostream>
using namespace std;



//Deslocamento do personagem
float personagemDeslococamento(float coordenadaAtual, float deslocamento){
    return coordenadaAtual + deslocamento;
}

//Retorna o tamanho do personagem definido no eixo X
float personagemTamanhoX(glm::mat4 model){
    return model[0][0];
}
//Retorna o tamanho do personagem definido no eixo Y
float personagemTamanhoY(glm::mat4 model){
    return model[1][1];
}
//Retorna o tamanho do personagem definido no eixo Z
float personagemTamanhoZ(glm::mat4 model){
    return model[2][2];
}
