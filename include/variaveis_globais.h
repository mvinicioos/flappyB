// Razão de proporção da janela (largura/altura). Veja função FramebufferSizeCallback().
float g_ScreenRatio = 1.0f;

// Ângulos de Euler que controlam a rotação de um dos cubos da cena virtual
float g_AngleX = 0.0f;
float g_AngleY = 0.0f;
float g_AngleZ = 0.0f;

// "g_LeftMouseButtonPressed = true" se o usuário está com o botão esquerdo do mouse
// pressionado no momento atual. Veja função MouseButtonCallback().
bool g_LeftMouseButtonPressed = false;
bool g_RightMouseButtonPressed = false; // Análogo para botão direito do mouse
bool g_MiddleMouseButtonPressed = false; // Análogo para botão do meio do mouse

//teclas de controle
bool g_WKeyPressed = false;
bool g_AKeyPressed = false;
bool g_SKeyPressed = false;
bool g_DKeyPressed = false;


// Variáveis que definem a câmera em coordenadas esféricas, controladas pelo
// usuário através do mouse (veja função CursorPosCallback()). A posição
// efetiva da câmera é calculada dentro da função main(), dentro do loop de
// renderização.
float g_CameraTheta = 0.0f; // Ângulo no plano ZX em relação ao eixo Z
float g_CameraPhi = 0.0f;   // Ângulo em relação ao eixo Y
float g_CameraDistance = 3.5f; // Distância da câmera para a origem

float freeCam = 0; //Controle free câmera
bool freeCam2 = false;
bool g_ENTERKeyPresseed = false;
bool g_ENTERKeyPresseed2 = false;

// para implementar a free cam, utilizamos como global:
glm::vec4 camera_position_c  = glm::vec4(8.0f,1.5f,0.0f,1.0f);
glm::vec4 camera_view_vector = glm::vec4(-250.0f,0.0f,0.0f,1.0f) - camera_position_c;
glm::vec4 camera_up_vector   = glm::vec4(0.0f,1.0f,0.0f,0.0f); // Vetor "up" fixado para apontar para o "céu" (eito Y global)
glm::vec4 vectorNormalized = glm::normalize(crossproduct(camera_view_vector, camera_up_vector));

// para implementar olhada ao redor do mouse
bool firstMouse = true;

// Variáveis que controlam rotação do antebraço
float g_ForearmAngleZ = 0.0f;
float g_ForearmAngleX = 0.0f;

// Variáveis que controlam translação do torso
float g_TorsoPositionX = 0.0f;
float g_TorsoPositionY = 0.0f;

// Variável que controla o tipo de projeção utilizada: perspectiva ou ortográfica.
bool g_UsePerspectiveProjection = true;

// Variável que controla se o texto informativo será mostrado na tela.
bool g_ShowInfoText = true;


// Variáveis que definem um programa de GPU (shaders). Veja função LoadShadersFromFiles().
GLuint vertex_shader_id;
GLuint fragment_shader_id;
GLuint program_id = 0;
GLint model_uniform;
GLint view_uniform;
GLint projection_uniform;
GLint object_id_uniform;
GLint bbox_min_uniform;
GLint bbox_max_uniform;


// Número de texturas carregadas pela função LoadTextureImage()
GLuint g_NumLoadedTextures = 0;

// Pilha que guardará as matrizes de modelagem.
std::stack<glm::mat4>  g_MatrixStack;

int menu = 1;
int menuSelPersonagem = 0;
float menuSeletor = 0.1;
//-----------------------------------------------------------------------[PERSONAGEM]
//Variáveis globais de referência para orientação do personagem principal.
float personagemCoordX = 0;
float personagemCoordY = 5;
float personagemCoordZ = 0;
//Flags
int  flagTeclaEspaco   = 0;
//controladores
float personagemTempoSaltoInc = 0;
int personagemSeletor = 0;
//-----------------------------------------------------------------------[OBSTACULOS]
GLuint vertex_array_object_id;
//Primeiro objeto
float obstaculosAcoordX = 5;
float obstaculosAcoordY = 0;
float obstaculosAcoordZ = 0;

//Segundo Objeto
float obstaculosBcoordX = 10;
float obstaculosBcoordY = 0;
float obstaculosBcoordZ = 0;
