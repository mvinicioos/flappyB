#version 330 core

// Atributos de fragmentos recebidos como entrada ("in") pelo Fragment Shader.
// Neste exemplo, este atributo foi gerado pelo rasterizador como a
// interpola��o da cor de cada v�rtice, definidas em "shader_vertex.glsl" e
// "main.cpp".
in vec4 position_world;
in vec4 normal;

// Posi��o do v�rtice atual no sistema de coordenadas local do modelo.
in vec4 position_model;

// Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
in vec2 texcoords;

// Matrizes computadas no c�digo C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Identificador que define qual objeto est� sendo desenhado no momento
#define SPHERE 0
#define PERSONAGEM  1
#define VACA  2
#define PAREDE  3
#define OBSTACULO  4
#define CHAO  5
uniform int object_id;

// Par�metros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;

// Vari�veis para acesso das imagens de textura
uniform sampler2D TextureImage0;
uniform sampler2D TextureImage1;
uniform sampler2D TextureImage2;
uniform sampler2D TextureImage3;/*
uniform sampler2D TextureImage4;
uniform sampler2D TextureImage5;
uniform sampler2D TextureImage6;
*/
// O valor de sa�da ("out") de um Fragment Shader � a cor final do fragmento.
out vec3 color;

// Constantes
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    // Obtemos a posi��o da c�mera utilizando a inversa da matriz que define o
    // sistema de coordenadas da c�mera.
    vec4 origin = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 camera_position = inverse(view) * origin;

    // O fragmento atual � coberto por um ponto que percente � superf�cie de um
    // dos objetos virtuais da cena. Este ponto, p, possui uma posi��o no
    // sistema de coordenadas global (World coordinates). Esta posi��o � obtida
    // atrav�s da interpola��o, feita pelo rasterizador, da posi��o de cada
    // v�rtice.
    vec4 p = position_world;

    // Normal do fragmento atual, interpolada pelo rasterizador a partir das
    // normais de cada v�rtice.
    vec4 n = normalize(normal);

    // Vetor que define o sentido da fonte de luz em rela��o ao ponto atual.
    vec4 l = normalize(vec4(1.0,1.0,0.0,0.0));

    // Vetor que define o sentido da c�mera em rela��o ao ponto atual.
    vec4 v = normalize(camera_position - p);



    // Coordenadas de textura U e V
    float U = 0.0;
    float V = 0.0;
    vec3 Kd0 = texture(TextureImage0, vec2(U,V)).rgb;
    // Equa��o de Ilumina��o
    float lambert = max(0,dot(n,l));

    // Vetor que define half-vector para Blinn-Phong
    vec4 hf = normalize(v+l);
    // spotlight
    vec4 sp = vec4(0.0, -1.0, 0.0, 0.0);
    vec4 sp_pos = vec4(0.0, 2.0, 1.0, 1.0);
    float sp_gap = 3.14159265359/6;
    vec4 s = normalize(sp_pos - p);
    // Vetor que define o sentido da reflex�o especular ideal.
    vec4 r = 2 * n * dot(n, s); // PREENCHA AQUI o vetor de reflex�o especular ideal
    // Par�metros que definem as propriedades espectrais da superf�cie
    vec3 Kd; // Reflet�ncia difusa
    vec3 Ks; // Reflet�ncia especular
    vec3 Ka; // Reflet�ncia ambiente
    float q; // Expoente especular para o modelo de ilumina��o de Phong


    if ( object_id == SPHERE )
    {
        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;
        vec4 p=position_model-bbox_center;

        float px=position_model.x;
        float py=position_model.y;
        float pz=position_model.z;

        float ro=length(p);
        float theta=atan(px, pz);
        float phi=asin(py/ro);

        U = (theta+M_PI)/(2*M_PI);
        V = (phi+M_PI_2)/M_PI;
        color = Kd0 * (lambert + 0.01);
        vec3 Kd1 = texture(TextureImage3, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01)+Kd1 * (1-pow(lambert,0.2));
    }
    else if ( object_id == PERSONAGEM )
    {

        float minx = bbox_min.x;
        float maxx = bbox_max.x;

        float miny = bbox_min.y;
        float maxy = bbox_max.y;

        float minz = bbox_min.z;
        float maxz = bbox_max.z;

        U=(position_model.x-minx)/(maxx-minx);
        V=(position_model.y-miny)/(maxy-miny);
        Kd0 = texture(TextureImage0, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01);
}
    else if ( object_id == VACA )
    {
        Kd = vec3(0.08f,0.4f,0.8f);
        Ks = vec3(0.8f,0.8f,0.8f);
        Ka = Kd/2.0f;
        q = 32.0;

        vec3 I = vec3(1.0,1.0,1.0); // PREENCH AQUI o espectro da fonte de luz
        vec3 Ia = vec3(0.3,0.3,0.3); // PREENCHA AQUI o espectro da luz ambiente
        vec3 lambert_diffuse_term = Kd * I * max(0, dot(n, l)); // PREENCHA AQUI o termo difuso de Lambert
        vec3 ambient_term = Ka * Ia; // PREENCHA AQUI o termo ambiente
        vec3 phong_specular_term  = Ks * I * pow(max(0, dot(n,hf)), q);
        color = lambert_diffuse_term + ambient_term + phong_specular_term;
    }

    else if ( object_id == PAREDE )
    {
        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;
        vec4 p=position_model-bbox_center;

        float px=position_model.x;
        float py=position_model.y;
        float pz=position_model.z;

        float ro=length(p);
        float theta=atan(px, pz);
        float phi=asin(py/ro);

        U = (theta+M_PI)/(2*M_PI);
        V = (phi+M_PI_2)/M_PI;
        Kd0 = texture(TextureImage1, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01);
        vec3 Kd1 = texture(TextureImage2, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01)+Kd1 * (1-pow(lambert,0.2));
    }
    else if ( object_id == OBSTACULO )
    {
        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;
        vec4 p=position_model-bbox_center;

        float px=position_model.x;
        float py=position_model.y;
        float pz=position_model.z;

        float ro=length(p);
        float theta=atan(px, pz);
        float phi=asin(py/ro);

        U = (theta+M_PI)/(2*M_PI);
        V = (phi+M_PI_2)/M_PI;
        Kd0 = texture(TextureImage1, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01);
        vec3 Kd1 = texture(TextureImage2, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01)+Kd1 * (1-pow(lambert,0.2));
    }

    else if ( object_id == CHAO )
    {
        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;
        vec4 p=position_model-bbox_center;

        float px=position_model.x;
        float py=position_model.y;
        float pz=position_model.z;

        float ro=length(p);
        float theta=atan(px, pz);
        float phi=asin(py/ro);

        U = (theta+M_PI)/(2*M_PI);
        V = (phi+M_PI_2)/M_PI;
        Kd0 = texture(TextureImage2, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01);
        vec3 Kd1 = texture(TextureImage1, vec2(U,V)).rgb;
        color = Kd0 * (lambert + 0.01)+Kd1 * (1-pow(lambert,0.2));
    }


    color = pow(color, vec3(1.0,1.0,1.0)/2.2);
}
