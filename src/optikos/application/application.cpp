#include <stdexcept>
#include "application.hpp"

typedef std::runtime_error err;

// assumed success
optikos::Application::Application(const char *title, int width, int height) {
    if (title == nullptr) {
        throw err("No valid title given");
    }

    if (width <= 0 || height <= 0) {
        throw err("Invalid dimensions given");
    }

    if (glfwInit() == GLFW_FALSE) {
        throw err("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
        throw err("Failed to create GLFW window");
    }

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        throw err("Failed to initialize GLEW");
    }
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
