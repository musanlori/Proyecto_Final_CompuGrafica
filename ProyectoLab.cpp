//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Bustamante Valdez Jéssica Dayana		******//
//*************	Santiago Lopez Ricardo					******//
//************* Proyecto Final de Laboraotrio*****************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

//Para dibujar el edificio 
CFiguras f_edificio; 
CFiguras f_base;
CTexture concreto;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha


CTexture tree;

CFiguras sky;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
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
						glNormal3f( 0.0f, 0.0f, 1.0f);
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
						glNormal3f( 0.0f, 0.0f, 1.0f);
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
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();


	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	concreto.LoadTGA("concreto.tga");
	concreto.BuildGLTexture();
	concreto.ReleaseImage();


	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();
			
			//EJE DE REFERENCIA
				glBegin(GL_LINES);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(100.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 100.0, 0.0);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 100.0);
				glEnd();

				glColor3f(0.16, 0.30, 0.0);
				f_base.prisma(20.0,1.0,10.0,0.0);		//Base
				glPushMatrix();
					glTranslatef(-15.0,0.0,-2.0);			//Base Izq
					glColor3f(0.16, 0.30, 0.0);
					f_base.prisma(4.0,1.0,7.0,0.0);
				glPopMatrix();
				 
				glPushMatrix();
					glTranslatef(-7.75, 0.0, -15.5);			//Base Izq trasera
					glColor3f(0.16, 0.30, 0.0);
					f_base.prisma(9.0, 1.0, 7.0, 0.0);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(15.0, 0.0, -2.0);			//Base Der
					glColor3f(0.16, 0.30, 0.0);
					f_base.prisma(4.0, 1.0, 7.0, 0.0);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(7.75, 0.0, -15.5);			//Base Der trasera
					glColor3f(0.16, 0.30, 0.0);
					f_base.prisma(9.0, 1.0, 7.0, 0.0);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-15.0, 0.0, 4.0);			//Base Izq delantera
				glColor3f(0.16, 0.30, 0.0);
				f_base.prisma(4.0, 1.0, 3.5, 0.0);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(15.0, 0.0, 4.0);			//Base Der delantera
				glColor3f(0.16, 0.30, 0.0);
				f_base.prisma(4.0, 1.0, 3.5, 0.0);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-5.0, 0.0, 12.5);			//Base Izq Del
				glColor3f(0.16, 0.30, 0.0);
				f_base.prisma(6.0, 1.0, 5.0, 0.0);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(5.0, 0.0, 12.5);			//Base Der Del
				glColor3f(0.16, 0.30, 0.0);
				f_base.prisma(6.0, 1.0, 5.0, 0.0);
				glPopMatrix();

				glColor3f(1.0,1.0,1.0);
				glPushMatrix();
					glTranslatef(0.0, 3.0, 1.5);
					f_edificio.prisma(4.0, 6, 5.0, concreto.GLindex);		//Entrada
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-6.0, 3.0, 0.0);
					f_edificio.prisma(8.0,6.0,8.0, concreto.GLindex);			//Planta baja Izq
					glTranslatef(0.0,4.75, 0.0);
					f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Primer piso Izq
					glTranslatef(0.0, 3.5, 0.0);
					f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Segundo piso Izq
					glTranslatef(0.0, 3.5, 0.0);
					f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Tercer piso Izq
					glTranslatef(0.0, 4.0, 0.0);
					f_edificio.prisma(8.0, 4.5, 8.0, concreto.GLindex);		//Cuarto piso Izq
				glPopMatrix();

				glPushMatrix();
				glTranslatef(6.0, 3.0, 0.0);
				f_edificio.prisma(8.0, 6.0, 8.0, concreto.GLindex);		//Planta baja Der
				glTranslatef(0.0, 4.75, 0.0);
				f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Primer piso Der
				glTranslatef(0.0, 3.5, 0.0);
				f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Segundo piso Der
				glTranslatef(0.0, 3.5, 0.0);
				f_edificio.prisma(8.0, 3.5, 8.0, concreto.GLindex);		//Tercer piso Der
				glTranslatef(0.0, 4.0, 0.0);
				f_edificio.prisma(8.0, 4.5, 8.0, concreto.GLindex);		//Cuarto piso Der
				glPopMatrix();

				

				
				
	glPopMatrix();
			glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
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
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Edificio Q"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
