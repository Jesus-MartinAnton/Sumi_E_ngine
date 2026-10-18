#include <spdlog/spdlog.h>
#include <glfw/glfw3.h>
#include <vulkan/vulkan.h>

int main() {
	spdlog::info("¡Iniciando SumiEngine!");

	//1.- Inicializar GLFW
	if (!glfwInit()) {
		spdlog::error("Error al inicializar GLFW");
		return -1;
	}

	//2.- Configurar GLFW para usar Vulkan
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "SumiEngine", nullptr, nullptr);

	if (!window) {
		spdlog::error("Error al crear la ventana GLFW");
		glfwTerminate();
		return -1;
	}

	//3.- Comprobar que Vulkan responde detectando la GPU
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	spdlog::info("Número de extensiones de Vulkan disponibles: {}", extensionCount);

	spdlog::info("Ventana creada con exito. Cerrando en 3 segundos...");
	//Bucle para mantener la ventana abierta
	double startTime = glfwGetTime();
	while (!glfwWindowShouldClose(window) && (glfwGetTime() - startTime <= 3.0)) {
		glfwPollEvents();
	}

	//4.- Limpiar y cerrar
	glfwDestroyWindow(window);
	glfwTerminate();

	spdlog::info("SumiEngine cerrado correctamente.");
	return 0;
}