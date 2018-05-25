
// Variáveis globais que armazenam a última posição do cursor do mouse, para
// que possamos calcular quanto que o mouse se movimentou entre dois instantes
// de tempo. Utilizadas no callback CursorPosCallback() abaixo.
double g_LastCursorPosX, g_LastCursorPosY;
// Razão de proporção da janela (largura/altura). Veja função FramebufferSizeCallback().
float g_ScreenRatio = 1.0f;
// Ângulos de Euler que controlam a rotação de um dos cubos da cena virtual
float g_AngleX = 0.0f;
float g_AngleY = 0.0f;
float g_AngleZ = 0.0f;
// "g_LeftMouseButtonPressed = true" se o usuário está com o botão esquerdo do mouse
// pressionado no momento atual. Veja função MouseButtonCallback().
bool g_LeftMouseButtonPressed = false;
// Variáveis que definem a câmera em coordenadas esféricas, controladas pelo
// usuário através do mouse (veja função CursorPosCallback()). A posição
// efetiva da câmera é calculada dentro da função main(), dentro do loop de
// renderização.
float g_CameraTheta = 0.0f; // Ângulo no plano ZX em relação ao eixo Z
float g_CameraPhi = 0.0f;   // Ângulo em relação ao eixo Y
float g_CameraDistance = 2.5f; // Distância da câmera para a origem
// Variável que controla o tipo de projeção utilizada: perspectiva ou ortográfica.
bool g_UsePerspectiveProjection = true;
// Variável que controla se o texto informativo será mostrado na tela.
bool g_ShowInfoText = true;
//Variáveis globais de referência para orientação do objeto principal. Partindo da origem
float personagemCoordX = 0;
float personagemCoordY = 0;
float personagemCoordZ = 0;
//Flags
int  flagTeclaEspaco   = 0;
//controladores
float personagemTempoSaltoInc = 0;

// Cada cópia do cubo possui uma matriz de modelagem independente,
// já que cada cópia estará em uma posição (rotação, escala, ...)
// diferente em relação ao espaço global (World Coordinates). Veja
// slide 148 do documento "Aula_08_Sistemas_de_Coordenadas.pdf".
glm::mat4 model;


