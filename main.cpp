//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Ricardo Santiago López **********//
//*************				 Jessica Dayana Bustamante	******//
//*************											******//
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
CTexture tree;
CTexture plaza_Piso;
CTexture Cont_jard;
CTexture pasto_Jard;

//formas
CFiguras sky;
CFiguras lRecJard;

void arbol()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}



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
	//textura Arbol Ejemplo
	tree.LoadTGA("Texturas/tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

}

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

	glPopMatrix();
		//arbol();
		terreno();
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
