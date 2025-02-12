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
//
//unsigned int vertexShader;
//unsigned int fragmentShader;
//unsigned int shaderProgram;
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
//        // Créaation d'une matrice Vue
//        glm::mat4 view;
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//
//        // Création d'une matrice perspective 
//        glm::mat4 projection;
//        projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
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
//}