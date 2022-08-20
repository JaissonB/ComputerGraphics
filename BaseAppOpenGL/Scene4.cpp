#include "Scene4.h"

CScene4::CScene4()
{
	pCamera = NULL;
	pTexto = NULL;
	pTextures = NULL;
	
	bIsWireframe = false;
	bIsCameraFPS = true;

	iFPS = 0;
	iFrames = 0;
	ulLastFPS = 0;
	szTitle[256] = 0;

	// Cria gerenciador de impressão de texto na tela
	pTexto = new CTexto();

	// Cria camera
	pCamera = new CCamera(0.0f, 1.0f, 20.0f);

	// Cria o Timer
	pTimer = new CTimer();
	pTimer->Init();

	fTimerPosY = 0.0f;
	fRenderPosY = 0.0f;

	// Carrega todas as texturas
	//pTextures = new CTexture();	

}


CScene4::~CScene4(void)
{
	if (pTexto)
	{
		delete pTexto;
		pTexto = NULL;
	}

	if (pTextures)
	{
		delete pTextures;
		pTextures = NULL;
	}

	if (pCamera)
	{
		delete pCamera;
		pCamera = NULL;
	}

	if (pTimer)
	{
		delete pTimer;
		pTimer = NULL;
	}	
}




int CScene4::DrawGLScene(void)	// Função que desenha a cena
{
	// Get FPS
	if (GetTickCount() - ulLastFPS >= 1000)	// When A Second Has Passed...
	{
		ulLastFPS = GetTickCount();				// Update Our Time Variable
		iFPS = iFrames;							// Save The FPS
		iFrames = 0;							// Reset The FPS Counter
	}
	iFrames++;									// FPS counter
	
	pTimer->Update();							// Atualiza o timer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpa a tela e o Depth Buffer
	glLoadIdentity();									// Inicializa a Modelview Matrix Atual


	// Seta as posições da câmera
	pCamera->setView();

	// Desenha grid 
	Draw3DSGrid(20.0f, 20.0f);

	// Desenha os eixos do sistema cartesiano
	DrawAxis();

	// Modo FILL ou WIREFRAME (pressione barra de espaço)	
	if (bIsWireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (INÍCIO)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glColor4f(0.0f, 0.0f, 0.25f, 0.1f);

	//Chão água
	//glPushMatrix(); //Salva a matrix atual
	//auxSolidBox(41.0, 0.4, 41.0);
	//glPopMatrix();

	//Chão grama
	glColor3ub(17, 133, 12);
	glPushMatrix(); //Salva a matrix atual
	auxSolidBox(40.0, 0.5, 40.0);
	glPopMatrix();

	//Chão da casa
	glColor3ub(179, 185, 157);
	glPushMatrix();
	glTranslatef(-4.5, 0.75, -3.5);
	auxSolidBox(25.0, 1.0, 20.0);
	glPopMatrix();

	//Grade
	glColor3ub(240, 255, 0);
	glPushMatrix();
		//Esquerda
	glTranslatef(-16.9, 1.75, -13.4);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, 2.7);
	auxSolidCylinder(0.1, 1.5);

		//Frente
	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(1.35, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.5, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(1.35, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(3.1, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

		//Direita
	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.85);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(0.0, 0.0, -2.7);
	auxSolidCylinder(0.1, 1.5);

		//Trás
	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

	glTranslatef(-3.52, 0.0, 0.0);
	auxSolidCylinder(0.1, 1.5);

		//Primeiro Corrimão Esquerdo ...
	glTranslatef(-3.69, 1.0, 18.9);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	auxSolidCylinder(0.1, 20);

		//Primeiro Corrimão Frontal ...
	glTranslatef(1.0, 0.9, 0.0);//X   Z   Y   ?
	glRotatef(90.0, 0.0, 0.0, 1.0);
	auxSolidCylinder(0.1, 10.76);

	glTranslatef(0.0, -14.08, 0.0);//X   Z   Y   ?
	auxSolidCylinder(0.1, 10.82);




	glPopMatrix();

	//Casa
	glColor3ub(247, 28, 6);
	glPushMatrix();
	glBegin(GL_QUADS);
		//Casa -> Parede da frente
	glColor3ub(169, 00, 91);
	glVertex3f(-12.5f, 1.2f, 1.5f);//baixo da janela esquerda
	glVertex3f(-6.5f, 1.2f, 1.5f);
	glVertex3f(-6.5f, 2.7f, 1.5f);
	glVertex3f(-12.5f, 2.7f, 1.5f);

	glVertex3f(-12.5f, 2.7f, 1.5f);//esquerda da janela esquerda
	glVertex3f(-10.5f, 2.7f, 1.5f);
	glVertex3f(-10.5f, 7.2f, 1.5f);
	glVertex3f(-12.5f, 7.2f, 1.5f);

	glVertex3f(-10.5f, 6.3f, 1.5f);//cima da janela esquerda
	glVertex3f(-6.5f, 6.3f, 1.5f);
	glVertex3f(-6.5f, 7.2f, 1.5f);
	glVertex3f(-10.5f, 7.2f, 1.5f);

	glVertex3f(-8.0f, 2.7f, 1.5f);//direita da janela esquerda
	glVertex3f(-6.5f, 2.7f, 1.5f);
	glVertex3f(-6.5f, 6.3f, 1.5f);
	glVertex3f(-8.0f, 6.3f, 1.5f);
	// Medida da Janela 4,5 X 2,5

	glVertex3f(-6.5f, 5.3f, 1.5f);//cima da porta
	glVertex3f(-3.0f, 5.3f, 1.5f);
	glVertex3f(-3.0f, 7.2f, 1.5f);
	glVertex3f(-6.5f, 7.2f, 1.5f);

	glVertex3f(-3.0f, 1.2f, 1.5f);//baixo da janela direita
	glVertex3f(3.0f, 1.2f, 1.5f);
	glVertex3f(3.0f, 2.7f, 1.5f);
	glVertex3f(-3.0f, 2.7f, 1.5f);

	glVertex3f(-3.0f, 2.7f, 1.5f);//esquerda da janela direita
	glVertex3f(-1.5f, 2.7f, 1.5f);
	glVertex3f(-1.5f, 7.2f, 1.5f);
	glVertex3f(-3.0f, 7.2f, 1.5f);

	glVertex3f(-1.5f, 6.3f, 1.5f);//cima da janela direita
	glVertex3f(3.0f, 6.3f, 1.5f);
	glVertex3f(3.0f, 7.2f, 1.5f);
	glVertex3f(-1.5f, 7.2f, 1.5f);

	glVertex3f(1.0f, 2.7f, 1.5f);//direita da janela direita
	glVertex3f(3.0f, 2.7f, 1.5f);
	glVertex3f(3.0f, 6.3f, 1.5f);
	glVertex3f(1.0f, 6.3f, 1.5f);

		//Casa -> Parede da direita
	glColor3ub(247, 28, 6);
	glVertex3f(3.0f, 1.2f, 1.5f);
	glVertex3f(3.0f, 1.2f, -7.5f);
	glVertex3f(3.0f, 7.2f, -7.5f);
	glVertex3f(3.0f, 7.2f, 1.5f);

		//Casa -> Parede da traseira
	glVertex3f(3.0f, 1.2f, -7.5f);
	glVertex3f(-12.5f, 1.2f, -7.5f);
	glVertex3f(-12.5f, 7.2f, -7.5f);
	glVertex3f(3.0f, 7.2f, -7.5f);

		//Casa -> Parede da esquerda
	glVertex3f(-12.5f, 1.2f, -7.5f);
	glVertex3f(-12.5f, 1.2f, 1.5f);
	glVertex3f(-12.5f, 7.2f, 1.5f);
	glVertex3f(-12.5f, 7.2f, -7.5f);

		//Casa -> Teto
	glVertex3f(-12.5f, 7.2f, 1.5f);
	glVertex3f(3.0f, 7.2f, 1.5f);
	glVertex3f(3.0f, 7.2f, -7.5f);
	glVertex3f(-12.5f, 7.2f, -7.5f);
	glPopMatrix();




		//Casa -> Telhado
	glColor3ub(12, 111, 2);
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex3f(-4.0f, 4.0f, -6.0f);
	glVertex3f(4.0f, 4.0f, -6.0f);
	glVertex3f(0.0f, 6.0f, -6.0f);
	glPopMatrix();


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                               DESENHA OS OBJETOS DA CENA (FIM)
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fTimerPosY = pTimer->GetTime() / 1000.0f;
	fRenderPosY += 0.2f;

	// Impressão de texto na tela...
	// Muda para modo de projeção ortogonal 2D
	// OBS: Desabilite Texturas e Iluminação antes de entrar nesse modo de projeção
	OrthoMode(0, 0, WIDTH, HEIGHT);


	glPushMatrix();
	glTranslatef(0.0f, HEIGHT - 100, 0.0f);	// Move 1 unidade para dentro da tela (eixo Z)

	// Cor da fonte
	glColor3f(1.0f, 1.0f, 0.0f);


	glRasterPos2f(10.0f, 0.0f);	// Posicionando o texto na tela
	if (!bIsWireframe) {
		pTexto->glPrint("[TAB]  Modo LINE"); // Imprime texto na tela
	}
	else {
		pTexto->glPrint("[TAB]  Modo FILL");
	}


	//// Camera LookAt
	glRasterPos2f(10.0f, 40.0f);
	pTexto->glPrint("Player LookAt  : %f, %f, %f", pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);

	//// Posição do Player
	glRasterPos2f(10.0f, 60.0f);
	pTexto->glPrint("Player Position: %f, %f, %f", pCamera->Position[0], pCamera->Position[1], pCamera->Position[2]);

	//// Imprime o FPS da aplicação e o Timer
	glRasterPos2f(10.0f, 80.0f);
	pTexto->glPrint("Frames-per-Second: %d ---- Timer: %.1f segundos", iFPS, (pTimer->GetTime()/1000));


	glPopMatrix();

	// Muda para modo de projeção perspectiva 3D
	PerspectiveMode();

	return true;
}




void CScene4::MouseMove(void) // Tratamento de movimento do mouse
{
	// Realiza os cálculos de rotação da visão do Player (através das coordenadas
	// X do mouse.
	POINT mousePos;
	int middleX = WIDTH >> 1;
	int middleY = HEIGHT >> 1;

	GetCursorPos(&mousePos);

	if ((mousePos.x == middleX) && (mousePos.y == middleY)) return;

	SetCursorPos(middleX, middleY);

	fDeltaX = (float)((middleX - mousePos.x)) / 10;
	fDeltaY = (float)((middleY - mousePos.y)) / 10;

	// Rotaciona apenas a câmera
	pCamera->rotateGlob(-fDeltaX, 0.0f, 1.0f, 0.0f);
	pCamera->rotateLoc(-fDeltaY, 1.0f, 0.0f, 0.0f);
}

void CScene4::KeyPressed(void) // Tratamento de teclas pressionadas
{

	// Verifica se a tecla 'W' foi pressionada e move o Player para frente
	if (GetKeyState('W') & 0x80)
	{
		pCamera->moveGlob(pCamera->Forward[0], pCamera->Forward[1], pCamera->Forward[2]);
	}
	// Verifica se a tecla 'S' foi pressionada e move o Player para tras
	else if (GetKeyState('S') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Forward[0], -pCamera->Forward[1], -pCamera->Forward[2]);
	}
	// Verifica se a tecla 'A' foi pressionada e move o Player para esquerda
	else if (GetKeyState('A') & 0x80)
	{
		pCamera->moveGlob(-pCamera->Right[0], -pCamera->Right[1], -pCamera->Right[2]);
	}
	// Verifica se a tecla 'D' foi pressionada e move o Player para direira
	else if (GetKeyState('D') & 0x80)
	{
		pCamera->moveGlob(pCamera->Right[0], pCamera->Right[1], pCamera->Right[2]);
	}
	// Senão, interrompe movimento do Player
	else
	{
	}



}

void CScene4::KeyDownPressed(WPARAM	wParam) // Tratamento de teclas pressionadas
{
	switch (wParam)
	{
	case VK_TAB:
		bIsWireframe = !bIsWireframe;
		break;

	case VK_SPACE:
		pTimer->Init();
		break;

	case VK_RETURN:
		break;

	}

}

//	Cria um grid horizontal ao longo dos eixos X e Z
void CScene4::Draw3DSGrid(float width, float length)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.3f, 0.0f);
	glPushMatrix();
	for (float i = -width; i <= length; i += 1)
	{
		for (float j = -width; j <= length; j += 1)
		{
			// inicia o desenho das linhas
			glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(i, 0.0f, j + 1);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(i + 1, 0.0f, j + 1);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(i + 1, 0.0f, j);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(i, 0.0f, j);
			glEnd();
		}
	}
	glPopMatrix();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void CScene4::DrawCube(float pX, float pY, float pZ,
	float rX, float rY, float rZ, float angle,
	float sX, float sY, float sZ,
	int texID)
{

	// Seta a textura ativa
	if (texID >= 0)
		pTextures->ApplyTexture(texID);

	glPushMatrix();
	glTranslatef(pX, pY, pZ);
	glRotatef(angle, rX, rY, rZ);
	glScalef(sX, sY, sZ);

	glBegin(GL_QUADS);
	// face frente
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.5f);

	// face trás
	glTexCoord2d(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	
	// face direita
	glTexCoord2d(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// face esquerda
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	// face baixo
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f, -0.5f,  0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);

	// face cima
	glTexCoord2d(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);
	glTexCoord2d(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);
	glTexCoord2d(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  -0.5f);

	glEnd();

	glPopMatrix();
}


void CScene4::DrawAxis()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	// Eixo X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);

	// Eixo Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(0.0f, -1000.0f, 0.0f);

	// Eixo Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(0.0f, 0.0f, -1000.0f);
	glEnd();
	glPopMatrix();
}


