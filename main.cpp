//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Santiago López Ricardo **********//
//*************				 Bustamante Valdez Jéssica Dayana*//
//*************				 Martinez Torres Luis Martin******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

CFiguras mi_figura;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position
//texturas
CTexture Cielo_Text;
CTexture Arbol_Tex;
CTexture Pino_Tex;
CTexture plaza_Piso;
CTexture Cont_jard;
CTexture pasto_Jard;
CTexture lamp_tex;
CTexture cristal;
CTexture tablaroca;
CTexture hidrante;
CTexture puertaC;
CTexture banca_f;
CTexture banca_ld;
CTexture banca_li;
CTexture banca_t;
CTexture banca_a;

//Para dibujar el edificio 
CFiguras f_edificio;
CFiguras f_base;
CFiguras f_silla;
CTexture concreto;
CTexture pasto;
CTexture noComer;
CTexture nofumar;
CTexture silencio;
CTexture noCelular;
CTexture pizarron;
CTexture piso;
CTexture pared;
CTexture piso2;
CTexture techo;
CTexture sillaTextura;
CTexture metal;
CTexture mesa;
CTexture aviso;
CTexture botiquin;
CTexture botiquin2;
CTexture L_F;
CTexture L_I_t;
CTexture Loceta;
CTexture tEscaleras;

//formas
CFiguras sky;
CFiguras lRecJard;
CFiguras Arbol;
CFiguras Pino;
CFiguras Lampara;
CFiguras Hidrante;
CFiguras escaleras;
CFiguras personita;

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	//carga textura para Cielo
	Cielo_Text.LoadBMP("Texturas/01.bmp");
	Cielo_Text.BuildGLTexture();
	Cielo_Text.ReleaseImage();
	//carga textura de piso
	plaza_Piso.LoadBMP("Texturas/piso_Plaza.bmp");
	plaza_Piso.BuildGLTexture();
	plaza_Piso.ReleaseImage();
	//carga textura de contorno de jardinera
	Cont_jard.LoadBMP("Texturas/jardinera_Cont.bmp");
	Cont_jard.BuildGLTexture();
	Cont_jard.ReleaseImage();
	//carga textura de pastos en jardineras
	pasto_Jard.LoadBMP("Texturas/pasto.bmp");
	pasto_Jard.BuildGLTexture();
	pasto_Jard.ReleaseImage();
	//textura Arbol
	Arbol_Tex.LoadTGA("Texturas/arbol.tga");
	Arbol_Tex.BuildGLTexture();
	Arbol_Tex.ReleaseImage();
	//textura pino
	Pino_Tex.LoadTGA("Texturas/pino.tga");
	Pino_Tex.BuildGLTexture();
	Pino_Tex.ReleaseImage();
	//textura lampara
	lamp_tex.LoadTGA("Texturas/Lampara.tga");
	lamp_tex.BuildGLTexture();
	lamp_tex.ReleaseImage();
	//textura Lampara
	cristal.LoadTGA("Texturas/cristal.tga");
	cristal.BuildGLTexture();
	cristal.ReleaseImage();
	//textura entrada
	tablaroca.LoadTGA("Texturas/tablaroca.tga");
	tablaroca.BuildGLTexture();
	tablaroca.ReleaseImage();
	//textura puertas
	puertaC.LoadTGA("Texturas/puertaC.tga");
	puertaC.BuildGLTexture();
	puertaC.ReleaseImage();
	//textura hidrante
	hidrante.LoadTGA("Texturas/hidrante.tga");
	hidrante.BuildGLTexture();
	hidrante.ReleaseImage();
	//textura banca_frontal
	banca_f.LoadTGA("Texturas/B_Frontal.tga");
	banca_f.BuildGLTexture();
	banca_f.ReleaseImage();
	//textura banca_lateral_derecha
	banca_ld.LoadTGA("Texturas/B_Lateral_D.tga");
	banca_ld.BuildGLTexture();
	banca_ld.ReleaseImage();
	//textura banca_lateral_izquierda
	banca_li.LoadTGA("Texturas/B_Lateral_I.tga");
	banca_li.BuildGLTexture();
	banca_li.ReleaseImage();
	//textura banca_trasera
	banca_t.LoadTGA("Texturas/B_Trasera.tga");
	banca_t.BuildGLTexture();
	banca_t.ReleaseImage();
	//textura banca_superior
	banca_a.LoadTGA("Texturas/B_Aerea.tga");
	banca_a.BuildGLTexture();
	banca_a.ReleaseImage();

	//textura banca_trasera
	L_F.LoadTGA("Texturas/Lobby.tga");
	L_F.BuildGLTexture();
	L_F.ReleaseImage();
	//textura banca_superior
	L_I_t.LoadTGA("Texturas/TFace.tga");
	L_I_t.BuildGLTexture();
	L_I_t.ReleaseImage();
	//loceta
	Loceta.LoadTGA("Texturas/loceta.tga");
	Loceta.BuildGLTexture();
	Loceta.ReleaseImage();
	//loceta
	tEscaleras.LoadTGA("Texturas/Loceta_P.tga");
	tEscaleras.BuildGLTexture();
	tEscaleras.ReleaseImage();
	//Texturas para el edificio
	//textura de la fachada
	concreto.LoadTGA("Texturas/concreto.tga");
	concreto.BuildGLTexture();
	concreto.ReleaseImage();
	//señalamiento_1
	noComer.LoadTGA("Texturas/noComer.tga");
	noComer.BuildGLTexture();
	noComer.ReleaseImage();
	//señalamiento_2
	nofumar.LoadTGA("texturas/noFumar.tga");
	nofumar.BuildGLTexture();
	nofumar.ReleaseImage();
	//señalamiento_3
	silencio.LoadTGA("Texturas/silencio.tga");
	silencio.BuildGLTexture();
	silencio.ReleaseImage();
	//señalamiento_4
	noCelular.LoadTGA("Texturas/noCelular.tga");
	noCelular.BuildGLTexture();
	noCelular.ReleaseImage();
	//pizarron
	pizarron.LoadTGA("Texturas/pizarron.tga");
	pizarron.BuildGLTexture();
	pizarron.ReleaseImage();
	//textura_piso
	piso.LoadTGA("Texturas/piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();
	//textura_pared_lab
	pared.LoadTGA("Texturas/pared.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();
	//Textrura_piso_detalles
	piso2.LoadTGA("Texturas/piso2.tga");
	piso2.BuildGLTexture();
	piso2.ReleaseImage();
	//metal
	metal.LoadTGA("Texturas/metal.tga");
	metal.BuildGLTexture();
	metal.ReleaseImage();
	//textura_silla
	sillaTextura.LoadTGA("Texturas/sillaTextura.tga");
	sillaTextura.BuildGLTexture();
	sillaTextura.ReleaseImage();
	//textura_techo
	techo.LoadTGA("Texturas/techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();
	//textura_madura
	mesa.LoadTGA("Texturas/madera.tga");
	mesa.BuildGLTexture();
	mesa.ReleaseImage();
	//Botiquin
	botiquin.LoadTGA("Texturas/botiquin.tga");
	botiquin.BuildGLTexture();
	botiquin.ReleaseImage();
	//botiquin
	botiquin2.LoadTGA("Texturas/botiquin2.tga");
	botiquin2.BuildGLTexture();
	botiquin2.ReleaseImage();
	//señalamiento_5
	aviso.LoadTGA("Texturas/aviso.tga");
	aviso.BuildGLTexture();
	aviso.ReleaseImage();
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

}
//funcion que dibuja el terreno
void terreno() {
	glDisable(GL_LIGHTING);
	//piso
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, plaza_Piso.GLindex);
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-20.0, 0.0, -18.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-20.0, 0.0, 18.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(20.0, 0.0, 18.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(20.0, 0.0, -18.0);
		glEnd();
	glPopMatrix();
	glTranslatef(0.0, 0.5, 0.0);
	//jardineras
	//jardinera trasera izq
	glPushMatrix();
		glTranslatef(-9.0, 0.0, -15.0);
		lRecJard.prisma(1.0, 12.0, 0.25, Cont_jard.GLindex);
		glPushMatrix();
			glTranslatef(6.5, 0.0, 0.5);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(7.0, 0.0, 1.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.0, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(6.5, 0.0, 2.5);
			glRotatef(45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glTranslatef(1.5, 0.0, 3.0);
		lRecJard.prisma(1.0, 9.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-6.0, 0.0, -1.5);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.2426, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	//jardinera trasera Der
	glPushMatrix();
		glTranslatef(9.0, 0.0, -15.0);
		lRecJard.prisma(1.0, 12.0, 0.25, Cont_jard.GLindex);
		glPushMatrix();
			glTranslatef(-6.5, 0.0, 0.5);
			glRotatef(45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-7.0, 0.0, 1.5);
			glRotatef(90, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.0, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-6.5, 0.0, 2.5);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glTranslatef(-1.5, 0.0, 3.0);
		lRecJard.prisma(1.0, 9.0, 0.25, Cont_jard.GLindex);
		glTranslatef(6.0, 0.0, -1.5);
		glRotatef(45.0, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.2426, 0.25, Cont_jard.GLindex);
	glPopMatrix();

	//jardinera lateral_1 derecha
	glPushMatrix();
		glTranslatef(17.0, 0.0, -7.5);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 11.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.0, 0.0, -4.0);
		lRecJard.prisma(1.0, 7.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-3.5, 0.0, 2.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.0, 0.25, Cont_jard.GLindex);
		glTranslatef(0.0, 0.0, -9.0);
		glRotatef(45.0, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 5.6568, 0.25, Cont_jard.GLindex);
	glPopMatrix();

	//jardinera lateral_1 izquierda
	glPushMatrix();
		glTranslatef(-17.0, 0.0, -7.5);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 11.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.0, 0.0, 4.0);
		lRecJard.prisma(1.0, 7.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-3.5, 0.0, -2.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.0, 0.25, Cont_jard.GLindex);
		glTranslatef(0.0, 0.0, -9.0);
		glRotatef(-45.0, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 5.6568, 0.25, Cont_jard.GLindex);
	glPopMatrix();

	//jardinera lateral_2 derecha
	glPushMatrix();
		glTranslatef(15.0, 0.0, 0.0);
		lRecJard.prisma(1.0, 4.0, 0.25, Cont_jard.GLindex);
		glTranslatef(2.0, 0.0, 5.0);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 10.0, 0.25, Cont_jard.GLindex);
		//definicion de las curvas de la jardinera
		glPushMatrix();
			glTranslatef(3.5, 0.0, -4.5);
			glRotatef(-18.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.0, 0.0, -5.5);
			glRotatef(-26.655, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.5, 0.0, -6.5);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.0, 0.0, -6.0);
			glRotatef(45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.8284, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-3.5, 0.0, -4.0);
			glRotatef(63.4353, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, 0.0, -1.5);
			glRotatef(71.5652, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
	glPopMatrix();

	//jardinera lateral_2 izquierda
	glPushMatrix();
		glTranslatef(-15.0, 0.0, 0.0);
		lRecJard.prisma(1.0, 4.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.0, 0.0, 5.0);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 10.0, 0.25, Cont_jard.GLindex);
		//definicion de las curvas de la jardinera
		glPushMatrix();
			glTranslatef(3.5, 0.0, 4.5);
			glRotatef(18.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.0, 0.0, 5.5);
			glRotatef(26.655, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.5, 0.0, 6.5);
			glRotatef(45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.0, 0.0, 6.0);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.8284, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-3.5, 0.0, 4.0);
			glRotatef(-63.4353, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, 0.0, 1.5);
			glRotatef(-71.5652, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
	glPopMatrix();

	//jardinera Frontal Derecha
	glPushMatrix();
		glTranslatef(2.0, 0.0, 12.5);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 5.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.5, 0.0, 3.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 6.0, 0.25, Cont_jard.GLindex);
		glPushMatrix();
			glTranslatef(3.5, 0.0, -1.0);
			glRotatef(63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4.0, 0.0, -3.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.0, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.5, 0.0, -5.0);
			glRotatef(-63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.5, 0.0, -6.5);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.0, 0.0, -6.5);
			glRotatef(26.5650, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.5, 0.0, -5.5);
			glRotatef(18.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
	glPopMatrix();

	//jardinera Frontal Derecha
	glPushMatrix();
		glTranslatef(2.0, 0.0, 12.5);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 5.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.5, 0.0, 3.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 6.0, 0.25, Cont_jard.GLindex);
		glPushMatrix();
			glTranslatef(3.5, 0.0, -1.0);
			glRotatef(63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4.0, 0.0, -3.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.0, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.5, 0.0, -5.0);
			glRotatef(-63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.5, 0.0, -6.5);
			glRotatef(-45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.0, 0.0, -6.5);
			glRotatef(26.5650, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.5, 0.0, -5.5);
			glRotatef(18.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
	glPopMatrix();
	//jardinera Frontal izquierda
	glPushMatrix();
		glTranslatef(-2.0, 0.0, 12.5);
		glRotatef(90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 5.0, 0.25, Cont_jard.GLindex);
		glTranslatef(-2.5, 0.0, -3.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 6.0, 0.25, Cont_jard.GLindex);
		glPushMatrix();
			glTranslatef(-3.5, 0.0, -1.0);
			glRotatef(-63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.0, 0.0, -3.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.0, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-3.5, 0.0, -5.0);
			glRotatef(63.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.5, 0.0, -6.5);
			glRotatef(45, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 1.4142, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.0, 0.0, -6.5);
			glRotatef(-26.5650, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 2.2361, 0.25, Cont_jard.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.5, 0.0, -5.5);
			glRotatef(-18.435, 0.0, 1.0, 0.0);
			lRecJard.prisma(1.0, 3.1623, 0.25, Cont_jard.GLindex);
		glPopMatrix();
	glPopMatrix();
	//jardinera central
	glPushMatrix();
		glTranslatef(-8.5, 0.0, 1.5);
		glRotatef(-45, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.2426, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-6.0, 0.0, 3.5);
		glRotatef(-26.57, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 2.2360, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-3.5, 0.0, 4.5);
		glRotatef(-18.43, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 3.1723, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(8.5, 0.0, 1.5);
		glRotatef(45, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 4.2426, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(6.0, 0.0, 3.5);
		glRotatef(26.57, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 2.2360, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(3.5, 0.0, 4.5);
		glRotatef(18.43, 0.0, 1.0, 0.0);
		lRecJard.prisma(1.0, 3.1723, 0.25, Cont_jard.GLindex);
	glPopMatrix();
	//pastos
	//jardin trasero izquierdo
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(-15.0, -0.25, -15.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-3.0, -0.25, -15.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, -0.25, -14.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-2.0, -0.25, -13.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-3.0, -0.25, -12.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(-12.0, -0.25, -12.0);
		glEnd();
	glPopMatrix();
	//jardin trasero izquierdo (rectas)
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(15.0,-0.25, -15.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(3.0, -0.25, -15.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(2.0, -0.25, -14.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(2.0, -0.25, -13.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(3.0, -0.25, -12.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(12.0, -0.25, -12.0);
		glEnd();
	glPopMatrix();
	//jardin lateral izquierdo_1
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
		glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-17.0, -0.25, -13.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(-13.0, -0.25, -9.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-13.0, -0.25, -2.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-17.0, -0.25, -2.0);
		glEnd();
	glPopMatrix();
	//jardin lateral Derecho_1
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
		glPushMatrix();
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(17.0, -0.25, -13.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(13.0, -0.25, -9.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(13.0, -0.25, -2.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(17.0, -0.25, -2.0);
		glEnd();
	glPopMatrix();
	//jardin lateral izquierdo_2
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(-17.0, -0.25, 0.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-13.0, -0.25, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-12.0, -0.25, 3.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-11.0, -0.25, 5.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-10.0, -0.25, 6.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-12.0, -0.25, 8.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-14.0, -0.25, 9.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-17.0, -0.25, 10.0);
		glEnd();
	glPopMatrix();
	//jardin lateral izquierdo_2
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
			glBegin(GL_TRIANGLE_FAN);
				glTexCoord2f(0.0, 0.0); glVertex3f(17.0, -0.25, 0.0);
				glTexCoord2f(0.1, 1.0); glVertex3f(13.0, -0.25, 0.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(12.0, -0.25, 3.0);
				glTexCoord2f(0.1, 1.0); glVertex3f(11.0, -0.25, 5.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(10.0, -0.25, 6.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(12.0, -0.25, 8.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(14.0, -0.25, 9.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(17.0, -0.25, 10.0);
			glEnd();
	glPopMatrix();
	//jardin frontal Izquiero
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(-8.0, -0.25, 15.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-9.0, -0.25, 13.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-9.0, -0.25, 11.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-8.0, -0.25, 9.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-7.0, -0.25, 8.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-5.0, -0.25, 9.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, -0.25, 10.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(-2.0, -0.25, 15.0);
		glEnd();
	glPopMatrix();
	//jardin frontal Izquiero
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
		glPushMatrix();
			glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(8.0, -0.25, 15.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(9.0, -0.25, 13.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(9.0, -0.25, 11.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(8.0, -0.25, 9.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(7.0, -0.25, 8.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(5.0, -0.25, 9.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(2.0, -0.25, 10.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(2.0, -0.25, 15.0);
			glEnd();
	glPopMatrix();
	//jardin central Izquierdo
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(-3.0, -0.25, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-10.0, -0.25, 0.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-7.0, -0.25, 3.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, -0.25, 4.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-3.0, -0.25, 3.0);
		glEnd();
		glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -0.25, 5.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, -0.25, 4.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(-3.0, -0.25, 3.0);
		glEnd();
	glPopMatrix();
	//jardin central Izquierdo
	glBindTexture(GL_TEXTURE_2D, pasto_Jard.GLindex);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0.0, 0.0); glVertex3f(3.0, -0.25, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(10.0, -0.25, 0.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(7.0, -0.25, 3.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(5.0, -0.25, 4.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(3.0, -0.25, 3.0);
		glEnd();
		glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0.0, 0.0); glVertex3f(2.0, -0.25, 5.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(5.0, -0.25, 4.0);
			glTexCoord2f(0.1, 1.0); glVertex3f(3.0, -0.25, 3.0);
		glEnd();
	glPopMatrix();
}
//funcion que dibuja un arbol en la posicion especificada.
void arbol(float x, float y, float z) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	//planos para la copa
	glPushMatrix();//1
		glTranslatef(x, y, z);
		Arbol.prisma(7.0, 2.0, 0.0, Arbol_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//2
		glTranslatef(x, y, z);
		glRotatef(45, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Arbol_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//3
		glTranslatef(x, y, z);
		glRotatef(90, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Arbol_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//4
		glTranslatef(x, y, z);
		glRotatef(135, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Arbol_Tex.GLindex);
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}
//funcion que dibuja un pino en la posicion especificada
void pino(float x, float y, float z) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	//planos para la copa
	glPushMatrix();//1
		glTranslatef(x, y, z);
		Pino.prisma(7.0, 2.0, 0.0, Pino_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//2
	glTranslatef(x, y, z);
		glRotatef(45, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Pino_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//3
		glTranslatef(x, y, z);
		glRotatef(90, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Pino_Tex.GLindex);
	glPopMatrix();
	glPushMatrix();//4
		glTranslatef(x, y, z);
		glRotatef(135, 0.0, 1.0, 0.0);
		Arbol.prisma(7.0, 2.0, 0.0, Pino_Tex.GLindex);
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}
void lampara(float x, float y, float z) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	//planos para la textura
	glPushMatrix();//1
		glTranslatef(x, y, z);
		Lampara.prisma(5.0, 1.5, 0.0, lamp_tex.GLindex);
	glPopMatrix();
	glPushMatrix();//2
		glTranslatef(x, y, z);
		glRotatef(45, 0.0, 1.0, 0.0);
		Lampara.prisma(5.0, 1.5, 0.0, lamp_tex.GLindex);
	glPopMatrix();
	glPushMatrix();//3
		glTranslatef(x, y, z);
		glRotatef(90, 0.0, 1.0, 0.0);
		Lampara.prisma(5.0, 1.5, 0.0, lamp_tex.GLindex);
	glPopMatrix();
	glPushMatrix();//4
		glTranslatef(x, y, z);
		glRotatef(135, 0.0, 1.0, 0.0);
		Lampara.prisma(5.0, 1.5, 0.0, lamp_tex.GLindex);
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}
//funcion para crear la entrada de cristal
void entradaCristal() {
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.275);
	glTranslatef(0.0, -0.25, 0.0);
	glBindTexture(GL_TEXTURE_2D, cristal.GLindex);
	glPushMatrix();//lateral derecho
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(3.0, 0.0, 0.0);
			glTexCoord2f(1, 0); glVertex3f(3.0, 5.5, 0.0);
			glTexCoord2f(1, 1); glVertex3f(3.0, 5.0, 3.0);
			glTexCoord2f(0, 1); glVertex3f(3.0, 0.0, 3.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//lateral Izquierdo
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-3.0, 0.0, 0.0);
			glTexCoord2f(1, 0); glVertex3f(-3.0, 5.5, 0.0);
			glTexCoord2f(1, 1); glVertex3f(-3.0, 5.0, 3.0);
			glTexCoord2f(0, 1); glVertex3f(-3.0, 0.0, 3.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//techo oblicuo 1
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(3.0, 5.5, 0.0);
			glTexCoord2f(1, 0); glVertex3f(3.0, 5.0, 3.0);
			glTexCoord2f(1, 1); glVertex3f(-3.0, 5.0, 3.0);
			glTexCoord2f(0, 1); glVertex3f(-3.0, 5.5, 0.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//techo oblicuo 2
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(2.0, 5.0, 3.0);
			glTexCoord2f(1, 0); glVertex3f(2.0, 4.5, 5.0);
			glTexCoord2f(1, 1); glVertex3f(-2.0, 4.5, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-2.0, 5.0, 3.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	//arco
	glPushMatrix();//lateral derecho
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(2.0, 1.0, 5.0);
			glTexCoord2f(1, 0); glVertex3f(2.0, 4.5, 5.0);
			glTexCoord2f(1, 1); glVertex3f(1.25, 4.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(1.25, 1.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//lateral Izquiero
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-2.0, 1.0, 5.0);
			glTexCoord2f(1, 0); glVertex3f(-2.0, 4.5, 5.0);
			glTexCoord2f(1, 1); glVertex3f(-1.25, 4.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-1.25, 1.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//central superior
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-2.0, 4.5, 5.0);
			glTexCoord2f(1, 0); glVertex3f(2.0, 4.5, 5.0);
			glTexCoord2f(1, 1); glVertex3f(1.25, 4.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-1.25, 4.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	//muros Entrada
	glBindTexture(GL_TEXTURE_2D, tablaroca.GLindex);
	glPushMatrix();//frontal derecho
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(3.0, 0.0, 3.0);
		glTexCoord2f(1, 0); glVertex3f(3.0, 5.0, 3.0);
		glTexCoord2f(1, 1); glVertex3f(2.0, 4.5, 5.0);
		glTexCoord2f(0, 1); glVertex3f(2.0, 0.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//frontal izquierdo
		glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-3.0, 0.0, 3.0);
			glTexCoord2f(1, 0); glVertex3f(-3.0, 5.0, 3.0);
			glTexCoord2f(1, 1); glVertex3f(-2.0, 4.5, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-2.0, 0.0, 5.0);
			glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//frontal inferior derecho
		glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(2.0, -0.25, 5.0);
			glTexCoord2f(1, 0); glVertex3f(2.0, 1.0, 5.0);
			glTexCoord2f(1, 1); glVertex3f(1.25, 1.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(1.25, -0.25, 5.0);
			glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//frontal inferior derecho
		glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-2.0, -0.25, 5.0);
			glTexCoord2f(1, 0); glVertex3f(-2.0, 1.0, 5.0);
			glTexCoord2f(1, 1); glVertex3f(-1.25, 1.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-1.25, -0.25, 5.0);
			glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//loza derecha
		glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0, 0); glVertex3f(3.0, 5.0, 3.0);
			glTexCoord2f(1, 0); glVertex3f(2.0, 5.0, 3.0);
			glTexCoord2f(1, 1); glVertex3f(2.0, 4.5, 5.0);
			glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//loza derecha
		glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0, 0); glVertex3f(-3.0, 5.0, 3.0);
			glTexCoord2f(1, 0); glVertex3f(-2.0, 5.0, 3.0);
			glTexCoord2f(1, 1); glVertex3f(-2.0, 4.5, 5.0);
			glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, puertaC.GLindex);
	glPushMatrix();//puerta izq
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-1.25, 0.0, 5.0);
			glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 5.0);
			glTexCoord2f(1, 1); glVertex3f(0.0, 4.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(-1.25, 4.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//puerta der
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(1.25, 0.0, 5.0);
			glTexCoord2f(1, 0); glVertex3f(0.0, 0.0, 5.0);
			glTexCoord2f(1, 1); glVertex3f(0.0, 4.0, 5.0);
			glTexCoord2f(0, 1); glVertex3f(1.25, 4.0, 5.0);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
}
//funcion para dibujar hidrante
void draw_hidrante(float x, float y, float z) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	//planos para la copa
	glPushMatrix();//1
		glTranslatef(x, y, z);
		Hidrante.prisma(1.0, 0.25, 0.0, hidrante.GLindex);
	glPopMatrix();
	glPushMatrix();//2
		glTranslatef(x, y, z);
		glRotatef(45, 0.0, 1.0, 0.0);
		Hidrante.prisma(1.0, 0.25, 0.0, hidrante.GLindex);
	glPopMatrix();
	glPushMatrix();//3
		glTranslatef(x, y, z);
		glRotatef(90, 0.0, 1.0, 0.0);
		Hidrante.prisma(1.0, 0.25, 0.0, hidrante.GLindex);
	glPopMatrix();
	glPushMatrix();//4
		glTranslatef(x, y, z);
		glRotatef(135, 0.0, 1.0, 0.0);
		Hidrante.prisma(1.0, 0.25, 0.0, hidrante.GLindex);
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}
//funcion para creacion de Edificio
void edificio() {
	glTranslatef(0.0, -0.25, 0.0);
	//Còmienza la construccion del edificio
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(0.0, 3.0, -2.5);
		f_edificio.prisma(6.0, 4.0, 5.0, concreto.GLindex);		//Entrada
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0, 3.0, -4.0);
		f_edificio.prisma(6.0, 10.0, 8.0, concreto.GLindex);		//Planta baja Izq
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0, 8.25, -4.0);
		f_edificio.prisma(4.5, 10.0, 8.0, concreto.GLindex);		//Primer piso Izq
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0, 12.75, -4.0);
		f_edificio.prisma(4.5, 10., 8.0, concreto.GLindex);		//Segundo piso Izq
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0, 17.25, -4.0);
		f_edificio.prisma(4.5, 10.0, 8.0, concreto.GLindex);		//Tercer piso Izq
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.0, 22.75, -4.0);
		f_edificio.prisma(5.5, 10.0, 8.0, concreto.GLindex);		//Cuarto piso Izq
	glPopMatrix();

	glPushMatrix();
		glTranslatef(7.0, 3.0, -4.0);
		f_edificio.prisma(6.0, 10.0, 8.0, concreto.GLindex);		//Planta baja der
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7.0, 8.25, -4.0);
		f_edificio.prisma(4.5, 10.0, 8.0, concreto.GLindex);		//Primer piso der
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7.0, 12.75, -4.0);
		f_edificio.prisma(4.5, 10., 8.0, concreto.GLindex);		//Segundo piso der
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7.0, 17.25, -4.0);
		f_edificio.prisma(4.5, 10.0, 8.0, concreto.GLindex);		//Tercer piso der
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7.0, 22.75, -4.0);
		f_edificio.prisma(5.5, 10.0, 8.0, concreto.GLindex);		//Cuarto piso ders
	glPopMatrix();
	//Termina la construccion del edificio
	//escaleras
	glPushMatrix();
		glTranslatef(0.0, 0.50, -6.0);
		escaleras.prisma(1.0, 3.9, 4.0, tEscaleras.GLindex);
		glTranslatef(0.0, -0.25, -2.25);
		escaleras.prisma(0.75, 3.9, 0.5, tEscaleras.GLindex);
		glTranslatef(0.0, -0.25, -0.5);
		escaleras.prisma(0.50, 3.9, 0.5, tEscaleras.GLindex);
	glPopMatrix();
	//Elementos al interior de la entrada
	glBindTexture(GL_TEXTURE_2D, L_F.GLindex);
	glPushMatrix();
		glBegin(GL_QUADS);//lobby entrada
		glTexCoord2f(0.0, 0.0); glVertex3f(-3.0, -0.25, 0.01);
		glTexCoord2f(1.0, 0.0); glVertex3f(3.0, -0.25, 0.01);
		glTexCoord2f(1.0, 1.0); glVertex3f(3.0, 5.25, 0.01);
		glTexCoord2f(0.0, 1.0); glVertex3f(-3.0, 5.25, 0.01);
		glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, L_I_t.GLindex);
	glPushMatrix();
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glBegin(GL_QUADS);//lobby interior
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.25, -2.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.25, -2.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 3.25, -2.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 3.25, -2.0);
		glEnd();
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, Loceta.GLindex);
	glPushMatrix();
		glBegin(GL_QUADS);//lobby interior
		glTexCoord2f(0.0, 0.0); glVertex3f(-3.0, -0.24, 0.0);
		glTexCoord2f(5.0, 0.0); glVertex3f(3.0, -0.24, 0.0);
		glTexCoord2f(5.0, 5.0); glVertex3f(3.0, -0.24, 3.0);
		glTexCoord2f(0.0, 5.0); glVertex3f(-3.0, -0.24, 3.0);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUADS);//lobby interior
		glTexCoord2f(0.0, 0.0); glVertex3f(-3.0, -0.24, 3.0);
		glTexCoord2f(5.0, 0.0); glVertex3f(3.0, -0.24, 3.0);
		glTexCoord2f(5.0, 5.0); glVertex3f(2.0, -0.24, 5.0);
		glTexCoord2f(0.0, 5.0); glVertex3f(-2.0, -0.24, 5.0);
		glEnd();
	glPopMatrix();
	//puerta trasera
	glBindTexture(GL_TEXTURE_2D, puertaC.GLindex);
	glPushMatrix();//puerta izq
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(1.0, 1.0, -5.01);
			glTexCoord2f(1, 0); glVertex3f(0.0, 1.0, -5.01);
			glTexCoord2f(1, 1); glVertex3f(0.0, 4.0, -5.01);
			glTexCoord2f(0, 1); glVertex3f(1.0, 4.0, -5.01);
		glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();//puerta der
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(-1.0, 1.0, -5.01);
			glTexCoord2f(1, 0); glVertex3f(0.0, 1.0, -5.01);
			glTexCoord2f(1, 1); glVertex3f(0.0, 4.0, -5.01);
			glTexCoord2f(0, 1); glVertex3f(-1.0, 4.0, -5.01);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
}
void silla()
{
	glScalef(2.0, 2.0, 2.0);
	f_silla.prisma(0.40, 0.10, 0.50, sillaTextura.GLindex);
	glTranslatef(-0.15, -0.20, 0.15);
	f_silla.prisma(0.05, 0.30, 0.05, metal.GLindex);
	glTranslatef(0.3, 0.0, 0.0);
	f_silla.prisma(0.05, 0.30, 0.05, metal.GLindex);
	glTranslatef(-0.05, 0.0, -0.15);
	f_silla.prisma(0.05, 0.3, 0.05, metal.GLindex);
	glTranslatef(-0.20, 0.0, 0.0);
	f_silla.prisma(0.05, 0.3, 0.05, metal.GLindex);
	glTranslatef(0.10, 0.45, 0.25);
	f_silla.prisma(0.40, 0.50, 0.1, sillaTextura.GLindex);

}
void mesa_lab()
{
	f_silla.prisma(0.15, 3.0, 1.0, mesa.GLindex);
	glTranslatef(1.3, -0.6, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	f_silla.prisma(1.2, 0.05, 0.5, 0.0);
	glTranslatef(-1.3, 0.0, 0.0);
	f_silla.prisma(1.2, 0.05, 0.5, 0.0);
	glTranslatef(-1.3, 0.0, 0.0);
	f_silla.prisma(1.2, 0.05, 0.5, 0.0);
	glTranslatef(0.0, -0.6, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(1.3, 0.0, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(1.3, 0.0, 0.0);
	f_silla.prisma(0.1, 0.1, 1.0, 0.0);
	glTranslatef(-1.3, 0.5, 0.0);
	f_silla.prisma(0.05, 2.6, 0.05, 0.0);
}
void banca(float x, float y, float z) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glPushMatrix();
		glTranslatef(x, y, z);
		glBindTexture(GL_TEXTURE_2D, banca_f.GLindex);
		glBegin(GL_QUADS);//cara frontal
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -.5, 0.5);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
		glEnd();
	/*
	//estas son las otras caras de la banca, pero pues no se ve muy bien por lo que deje unicamente una
	//sola cara: La frontal.
	glBindTexture(GL_TEXTURE_2D, banca_t.GLindex);
	glBegin(GL_QUADS);//cara trasera
		glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
		glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, banca_li.GLindex);
	glBegin(GL_QUADS);//cara izquierda
		glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
		glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
		glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, banca_ld.GLindex);
	glBegin(GL_QUADS);//cara derecha
		glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
		glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, banca_a.GLindex);
	glBegin(GL_QUADS);//cara superior
		glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
		glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.5, 0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
		glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
	glEnd();*/
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}
void laboratorio() {
	//Construccion del Laboratorio
	glPushMatrix();
		glPushMatrix();
			glTranslatef(7.0, 3.0, -7.9);
			f_edificio.prisma(6.0, 10.0, 0.0, pared.GLindex);				//Pared Trasera
		glPopMatrix();
		glPushMatrix();
			glTranslatef(11.9, 3.0, -4.0);
			f_edificio.prisma(6.0, 0.0, 8.0, pared.GLindex);					//Pared Derecha
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.1, 3.0, -4.0);
			f_edificio.prisma(6.0, 0.0, 8.0, pared.GLindex);					//Pared Izquierda
		glPopMatrix();
		glPushMatrix();
			glTranslatef(7.0, 3.0, -0.1);
			f_edificio.prisma(6.0, 10.0, 0.0, pared.GLindex);					//Pared delantera
		glPopMatrix();
		glPushMatrix();
			glTranslatef(7.0, 0.01, -4.0);
			f_edificio.prisma(0.0, 10.0, 8.0, piso.GLindex);					//Piso
			glTranslatef(0.0,0.01,0.0);
			f_edificio.prisma(0.0, 1.0, 8.0, piso2.GLindex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(7.0, 5.5, -7.89);
			f_edificio.prisma(1.0, 0.7, 0.0, aviso.GLindex);
			glTranslatef(0.0, -2.0, 0.0);
			f_edificio.prisma(3.0, 2.5, 0.0, pizarron.GLindex);	 //Pizarron
			glTranslatef(-2.0, 1.6, 0.0);
			f_edificio.prisma(0.5, 0.5, 0.0, noComer.GLindex);		//No comer
			glTranslatef(0.5, 0.0, 0.0);
			f_edificio.prisma(0.5, 0.5, 0.0, nofumar.GLindex);	//No fumar
			glTranslatef(-0.5, -0.5, 0.0);
			f_edificio.prisma(0.5, 0.5, 0.0, silencio.GLindex);	//No silencio
			glTranslatef(0.5, 0.0, 0.0);
			f_edificio.prisma(0.5, 0.5, 0.0, noCelular.GLindex);		//No celular	
		glPopMatrix();
		//Mesas
		glPushMatrix();
			glTranslatef(4.0, 1.2, -2.0);
			mesa_lab();
			glTranslatef(0.0, 0.7, -2.0);
			mesa_lab();
			glTranslatef(0.0, 0.7, -2.0);
			mesa_lab();
			glTranslatef(6.0, 0.7, 4.0);
			mesa_lab();
			glTranslatef(0.0, 0.7, -2.0);
			mesa_lab();
			glTranslatef(0.0, 0.7, -2.0);
			mesa_lab();
		glPopMatrix();
		//Sillas
		glPushMatrix();
		glTranslatef(0.0, 1.8, 15.0);

		glPopMatrix();

	glPopMatrix();
}
void salon() {
	//escribir codigo de salon en esta seccion
}
void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	sky.skybox(130.0, 130.0, 130.0, Cielo_Text.GLindex);
	glEnable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	//elementos del escenario
	glPopMatrix();
		/*se dibujo todo el plano del terreno junto con las jardineras y sus respectivas texturas*/
		terreno();
		/*se construye el edificio junto con los elementos del Lobby, y las escaleras*/
		edificio();
		/*construye el laboratorio junto con los elementos correspondientes a el*/
		laboratorio();
		/*Las siguientes funciones reciben como parametros las ubicaciones en donde se dibujaran
		TODAS LAS UBICAIONES ESTAN CALCULADAS DE ACUERDO AL SISTEMA DE REFERENCIA DIBUJADO EN EL PLANO DEL TERRENO
		CUYO ORIGEN ESTA EN EL CENTRO DEL TERRENO*/
		//estas funciones construyen arboles en las posiciones indicadas en el argumento
		arbol(-6.5, 3.5, -13.5);
		arbol(6.5, 3.5, -13.5);
		//estas funciones construyen pinos en las posiciones indicadas en los argumentos
		pino(-14, 3.5, 6);
		pino(14, 3.5, 6);
		//contruyen lamparas en las ubicaciones indicadas en los paramentros
		lampara(5, 2.0, 16);
		lampara(-5, 2.0, 16);
		//dibuja los hidrantes en las ubicaciones indicadas
		draw_hidrante(-17, 0.25, 15);
		draw_hidrante(17, 0.25, 15);
		draw_hidrante(-17, 0.25, -15);
		draw_hidrante(17, 0.25, -15);
		//dibuja las bancas del salon en la ubicacion indicada en los argumentos
		banca(0.0, 0.5, 8.0);
		//construye la entrada principal del edificio tomando como referencia el orien del terreno
		entradaCristal();
	glPopMatrix();
	glutSwapBuffers();

}

void animacion()
{

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(720, 480);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("ProyectoFinal"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);


	glutMainLoop();          // 

	return 0;
}
