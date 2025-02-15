#define GLEW_DLL
#define GLFW_DLL

#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

int main()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3.\n");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "lalala", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not create window.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	GLenum ret = glewInit();
	if (GLEW_OK != ret) {
		fprintf(stderr, "ERROR", glewGetErrorString(ret));
		return 1;
	}

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.5, 0.5, 0.5, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		/*Координаты вершин*/
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(0.0, 0.5);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.5, -0.5);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0.5, -0.5);
		/*Конец координат вершин*/
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}