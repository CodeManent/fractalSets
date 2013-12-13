#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <memory>

#include "Fractal.h"
#include "Cantor.h"
#include "Peano.h"
#include "Koch.h"
#include "KochTriangle.h"
#include "KochSquare.h"

//A typedef to help ease the iteration of fractal's lines.
typedef std::vector<Line>::const_iterator line_iterator;



//Fractal *fractal = &peano;
std::auto_ptr<Fractal> fractal(new Peano());



// Displays the fractal in the window.
// We iterate over the fractal's lines and just draw each and every one.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	const std::vector<Line> &set = fractal->getLines();

	// Starts drawing lines.
	glBegin(GL_LINES);

	//For every line segment of the fractal
	for(line_iterator l = set.begin(); l != set.end(); ++l)
	{
		//Grab its poits
		const Point &p0 = l->p0;
		const Point& p1 = l->p1;

		// and draw the lines
		glVertex2f(p0.x, p0.y);
		glVertex2f(p1.x, p1.y);
	}

	//ends drawing.
	glEnd();

	// and Updates the scren by swapping the screen buffers
	glutSwapBuffers();
}



// Helper function.
// With every keypress we generate the next-generation fractal and disolay it on the screen.
// On ESC the program shuts down
// 1-5 selects the fractal to be used.
void keyboard(unsigned char key, int, int)
{
	switch(key)
	{
	case '1':
		fractal.reset(new Cantor());
		break;
	case '2':
		fractal.reset(new Peano());
		break;
	case '3':
		fractal.reset(new Koch());
		break;
	case '4':
		fractal.reset(new KochTriangle());
		break;
	case '5':
		fractal.reset(new KochSquare());
		break;

	case 27: // ESC
		exit(0);

	default:
		fractal->step();
	}
	glutPostRedisplay();
}


// The entry function.
int main(int argc, char* argv[])
{
	try{
		// Initilaiszes the graphics subsythem.
		glutInit(&argc, argv);

		// We use double buffered mode to avoid flickering.
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

		// Creates the window in witch the fractal is going to be drawn.
		glutInitWindowSize(800, 800);
		glutCreateWindow(argv[0]);

		// Sets the drawing and keyboard handling functions.
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);

		// aaaaaand enters the main loop!!
		glutMainLoop();
	}
	catch(const std::exception &e)
	{
		std::cerr << "An exception has been raised" << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
