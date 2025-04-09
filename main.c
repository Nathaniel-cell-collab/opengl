
#include "bonus.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    (void)window;
}

void init_context(sim_t *sim)
{
    GLFWmonitor *monitor = NULL;
    const GLFWvidmode *mode = NULL;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    monitor = glfwGetPrimaryMonitor();
    mode = glfwGetVideoMode(monitor);
    sim->window = glfwCreateWindow(mode->width, mode->height, "Mon Bonus", monitor, NULL);
    if (sim->window == NULL) {
        my_printf("Failed to create GLFW window\n");
        glfwTerminate();
        exit(84);
    }
    glfwMakeContextCurrent(sim->window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        exit(84);
    }
}

void init_element(sim_t *sim, unsigned int *VAO)
{
    float vertices[] = {-0.5f, 0.5f,
                         0.5f, 0.5f,
                         0.5f, -0.5f,
                         -0.5f, -0.5f};
    sim->shaderProgam = createShaderProgram();
    setupSquare(VAO, vertices, sizeof(vertices));
}

int main(void)
{
    sim_t *sim = calloc(1, sizeof(sim_t));

    init_context(sim);
    init_element(sim, &(sim->VAO));
    main_loop(sim);
    glfwTerminate();
    return 0;
}
