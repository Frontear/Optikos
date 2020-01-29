#ifndef OPTIKOS_APPLICATION
#define OPTIKOS_APPLICATION

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace optikos {
    class Application {
    private:
        GLFWwindow* window;

    public:
        Application(const std::string& title, int width, int height);
        ~Application();

        int exec();
    };
}

#endif //OPTIKOS_APPLICATION
