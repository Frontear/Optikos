#include "application.hpp"

// assumed success
optikos::Application::Application(const std::string &title, int width, int height) {
    glfwInit();
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glewInit();
}

optikos::Application::~Application() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int optikos::Application::exec() {
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);
    while (glfwWindowShouldClose(window) == GLFW_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}
