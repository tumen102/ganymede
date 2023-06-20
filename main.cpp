#include <iostream>

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

int main() {
	// Initialize GLFW and set window hints
	if(!glfwInit()) {
		std::cout << "Failed to initialize GLFW!\n";
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // glfw 3 fails to create window, use glfw 2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	glfwSetErrorCallback(error_callback);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API); // needed for GLES2
	// Initialize window object
	//GLFWwindow* window = glfwCreateWindow(200, 200, "ganymede", glfwGetPrimaryMonitor(), NULL);
	GLFWwindow* window = glfwCreateWindow(300, 200, "ganymede", NULL, NULL);
	if(window == NULL) {
		std::cout << "Failed to create GLFW Window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // enable vsync for performance + tearing

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // bitwise OR
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();
	while(!glfwWindowShouldClose(window)) {
		int width, height;
		double time = glfwGetTime();
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClearColor(1.0f, 0.8f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(0.0f, 0.5f);
		glEnd();

		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwSetWindowCloseCallback(window, [] (GLFWwindow* closing_window) {
		glfwSetWindowShouldClose(closing_window, GLFW_TRUE);
	});
	return 0;
}
