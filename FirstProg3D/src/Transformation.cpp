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
//
//
//unsigned int vbo;
//unsigned int vao;
//unsigned int ebo;
//
//unsigned int vertexShader;
//unsigned int fragmentShader;
//unsigned int shaderProgram;
//
//int main()
//{
//    //Definition d'une matrice de rotation et d'une autre de mise à echelle 
//    /*glm::mat4 trans;
//    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
//    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));*/
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
//    Shader ourShader("src/Shaders/transform.vert", "src/Shaders/transform.frag");
//
//    // Dessinez un triangle 
//    float vertex[] =      //Les différent point de notre carré
//    {
//        // positions         // colors          //Textures 
//        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
//        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
//        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
//        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
//    };
//
//    unsigned int indices[] =
//    {
//        0, 1, 3, // first triangle
//        1, 2, 3  // second triangle
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
//    //Génération du EBO
//    glGenBuffers(1, &ebo);
//    //Activation du VBO
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
//
//    //Activation du EBO
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    //Passer les attributs du pointeur des vertex pour les positions (location, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    //Libère le VAO
//    glEnableVertexAttribArray(0);
//
//    //Passer les attributs du pointeur des vertex pour les couleurs (debut, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    //Libère le VAO
//    glEnableVertexAttribArray(1);
//
//    //Passer les attributs du pointeur des vertex pour les couleurs (debut, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    //Pour la texture
//    glEnableVertexAttribArray(2);
//
//    //Desactivation du VBO, du VAO et du EBO pour éviter qu'ils ne soient accidentellements modifés
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
//
//    while (!glfwWindowShouldClose(window))
//    {
//        glfwPollEvents();
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
//        //Dessiner un Objet en activant le VAO
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        //Premier contenair
//        //Definition d'une matrice de rotation et d'une autre de repositionnement
//        glm::mat4 trans;
//        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
//        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//        // Modification de la taille et de la rotation via la matrice translation créer 
//        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
//        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
//
//        glBindVertexArray(vao);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        //Second contenair
//        //Definition d'une matrice de rotation et d'une autre de repositionnement
//        glm::mat4 trans1;
//        trans1 = glm::translate(trans1, glm::vec3(-0.5f, 0.5f, 0.0f));
//        float scaleAmount = static_cast<float>(sin(glfwGetTime()));
//        trans1 = glm::scale(trans1, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
//        // Modification de la taille et de la rotation via la matrice translation créer 
//        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans1));
//
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//        glfwSwapBuffers(window);
//    }
//
//    // Suppression des objets créés
//    glDeleteVertexArrays(1, &vao);
//    glDeleteBuffers(1, &vbo);
//    glDeleteBuffers(1, &ebo);
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
//}