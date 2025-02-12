//// FirstProg3D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
////
//#define STB_IMAGE_IMPLEMENTATION
//#include <iostream>
//#include <glad/glad.h>
//#include <GLFW\glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <HeaderFiles/shaders.h>
//#include <HeaderFiles/stb_image.h>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//
//unsigned int vbo;
//unsigned int vao;
//
//unsigned int vertexShader;
//unsigned int fragmentShader;
//unsigned int shaderProgram;
//
////Position de la caméra
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
////Positionnement de la souris 
//bool firstMouse = true;
//float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//float pitch = 0.0f;
//float lastX = 800.0f / 2.0;
//float lastY = 600.0 / 2.0;
//float fov = 45.0f;
//
//float deltaTime = 0.0f; // Time between current frame and last frame
//float lastFrame = 0.0f; // Time of last frame
//
//int main()
//{
//    int screenWidth = 800;
//    int screenHeight = 600;
//
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "FirstAppOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window." << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    //Création du contexte et activation du contexte sur la fenêtre 
//    glfwMakeContextCurrent(window);
//
//    //Appelle de la fonction de redimensionnemnt automatique du viewport (zone de dessin)
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    //Chargement d'OpenGL 
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    //Preparation de la zone où on dessine dans la fenêtre
//    glViewport(0, 0, 800, 600);
//
//    // Création et compilation du Shader Program
//    Shader ourShader("src/Shaders/coord.vert", "src/Shaders/coord.frag");
//
//    // Dessinez un triangle 
//    float vertex[] =      //Les différent point de notre carré
//    {
//        // positions        //Textures 
//      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//       0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//       0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//       0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//       0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//       0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//       0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//      -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//       0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//       0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//       0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//       0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//       0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//       0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//       0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//       0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//       0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//       0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//       0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//       0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//      -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//    glm::vec3 cubePositions[] = {
//      glm::vec3(0.0f,  0.0f,  0.0f),
//      glm::vec3(2.0f,  5.0f, -15.0f),
//      glm::vec3(-1.5f, -2.2f, -2.5f),
//      glm::vec3(-3.8f, -2.0f, -12.3f),
//      glm::vec3(2.4f, -0.4f, -3.5f),
//      glm::vec3(-1.7f,  3.0f, -7.5f),
//      glm::vec3(1.3f, -2.0f, -2.5f),
//      glm::vec3(1.5f,  2.0f, -2.5f),
//      glm::vec3(1.5f,  0.2f, -1.5f),
//      glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//    //Génération du VAO
//    glGenVertexArrays(1, &vao);
//    //Avtivation du VAO 
//    glBindVertexArray(vao);
//
//    //Génération du VBO 
//    glGenBuffers(1, &vbo);
//
//    //Activation du VBO
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
//
//    //Passer les attributs du pointeur des vertex pour les positions (location, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    //Libère le VAO
//    glEnableVertexAttribArray(0);
//
//    //Passer les attributs du pointeur des vertex pour les couleurs (debut, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    //Pour la texture
//    glEnableVertexAttribArray(1);
//
//    //Desactivation du VBO, du VAO et du EBO pour éviter qu'ils ne soient accidentellements modifés
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    // Création et chargement de la texture
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // Creation de l'imgage 
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load("ressources/textures/container.jpg", &width, &height, &nrChannels, 0);
//    // Initialisation de la texture
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//
//    // Libération de l'espace mémoire de l'image
//    stbi_image_free(data);
//
//    // Création et chargement de la deuxième texture
//    stbi_set_flip_vertically_on_load(true);
//    unsigned int texture2;
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    data = stbi_load("ressources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
//    // Initialisation de la texture
//    if (data)
//    {
//        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//
//    // Libération de l'espace mémoire de l'image
//    stbi_image_free(data);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        glfwPollEvents();
//
//        //Gestion du temps entre les frames
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        processInput(window);
//
//        //Couleur de l'arrière plan 
//        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //Activation du Shader
//        ourShader.use(); // n’oubliez pas d’activer le shader avant de définir les variables uniformes
//        glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // définition manuelle
//        ourShader.setInt("texture2", 1); // ou avec la classe de shader
//
//        // Créaation d'une matrice Vue LookAt 
//        glm::mat4 view;
//        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//
//        // Création d'une matrice perspective 
//        glm::mat4 projection;
//        projection = glm::perspective(glm::radians(fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
//
//        int viewLoc = glGetUniformLocation(ourShader.ID, "view");
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//        int projectionLoc = glGetUniformLocation(ourShader.ID, "projection");
//        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // Test de la profondeur 
//        glEnable(GL_DEPTH_TEST);
//        // On efface le tampon de profondeur avant chaque rendu
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        //Dessiner un Objet en activant le VAO
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        glBindVertexArray(vao);
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // Création d'une matrice de modèle permettant de placer nos sommets dans l’espace monde
//            glm::mat4 model;
//            model = glm::translate(model, cubePositions[i]);
//            float angle = 20.0f * i;
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            int modelLoc = glGetUniformLocation(ourShader.ID, "model");
//            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//
//        glfwSwapBuffers(window);
//    }
//
//    // Suppression des objets créés
//    glDeleteVertexArrays(1, &vao);
//    glDeleteBuffers(1, &vbo);
//    glDeleteProgram(shaderProgram);
//
//    //Destruction de la fenêtre avant la fermeture du programme 
//    glfwDestroyWindow(window);
//    //
//    glfwTerminate();
//    return 0;
//}
//
////Recuperer directement les nouvelles dimension de la fenêtre (pour le redimensionnement auto)
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
////Recuperer les touche du clavier
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    //Position de la souris lorsque la fenêtre viens de prendre le focus 
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//    lastX = xpos;
//    lastY = ypos;
//
//    float sensitivity = 0.05;
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glm::vec3 front;
//    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    front.y = sin(glm::radians(pitch));
//    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//    cameraFront = glm::normalize(front);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    if (fov >= 1.0f && fov <= 45.0f)
//        fov -= yoffset;
//    if (fov <= 1.0f)
//        fov = 1.0f;
//    if (fov >= 45.0f)
//        fov = 45.0f;
//}