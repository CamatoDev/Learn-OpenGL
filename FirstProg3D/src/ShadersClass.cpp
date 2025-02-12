//// FirstProg3D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
////
//
//#include <iostream>
//#include <glad/glad.h>
//#include <GLFW\glfw3.h>
//
//#include <HeaderFiles/shaders.h>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
////Pour dessiner un cube 
////float vertex[] =      //Les différent point de notre carré
////{
////    -0.5f,  0.5f,  0.5f, // point 0
////    -0.5f, -0.5f,  0.5f, // point 1
////     0.5f, -0.5f,  0.5f, // point 2
////     0.5f,  0.5f,  0.5f // point 3
////    -0.5f,  0.5f, -0.5f, // point 4
////    -0.5f, -0.5f, -0.5f, // point 5
////     0.5f, -0.5f, -0.5f, // point 6
////     0.5f,  0.5f, -0.5f // point 7
////};
////
////unsigned int indices[] =
////{ // note that we start from 0!
////    0, 1, 2, 2, 3, 0, // premier carré
////    4, 0, 3, 3, 7, 4, // second carré
////    3, 2, 6, 6, 7, 3, // Troisième carré 
////    4, 5, 6, 6, 7, 4, // Quatrième carré 
////    0, 1, 5, 5, 4, 0, // Cinquième carré 
////    5, 1, 2, 2, 6, 5, // Sixième carré 
////};
//
//////Pour dessiner un carré 
////float vertex[] =      //Les différent point de notre carré
////{
////    0.5f, 0.5f, 0.0f, // top right
////    0.5f, -0.5f, 0.0f, // bottom right
////    -0.5f, -0.5f, 0.0f, // bottom left
////    -0.5f, 0.5f, 0.0f // top left
////};
////
////unsigned int indices[] = 
////{ // note that we start from 0!
////    0, 1, 3, // first triangle
////    1, 2, 3 // second triangle
////};
//
////Pour dessiner 3 triangles 
////float vertex[] =    //Les différent point de nos triangles 
////{
////    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // Bas gauche 
////    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,     // Bas droite 
////    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,      // Haut
////    -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,      // Interieur Gauche 
////    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,      // Interieur droit  
////    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,      // Interieur Bas  
////};
////
////// Tableau de l'ordre des indice des triangles 
////int indices[] =
////{
////    0, 3, 5,
////    3, 2, 4,
////    5, 4, 1
////};
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
//    Shader ourShader("src/Shaders/default.vert", "src/Shaders/default.frag");
//
//    // Dessinez un triangle 
//    float vertex[] =      //Les différent point de notre carré
//    {
//        // positions         // colors
//        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top   
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
//    /*glGenBuffers(1, &ebo); */
//    //Activation du VBO
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
//
//    //Activation du EBO
//    /*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
//
//    //Passer les attributs du pointeur des vertex pour les positions (location, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    //Libère le VAO
//    glEnableVertexAttribArray(0);
//
//    //Passer les attributs du pointeur des vertex pour les couleurs (debut, taille, ..., ..., position du début de l'éléments suivant)
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    //Libère le VAO
//    glEnableVertexAttribArray(1);
//
//    //Desactivation du VBO, du VAO et du EBO pour éviter qu'ils ne soient accidentellements modifés
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//    /*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/
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
//        /*int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");*/ // Recherche de la location de la variable uniform
//        ourShader.use();
//        /*glUniform4f(vertexColorLocation, 0.0f, 0.5f, 0.0f, 1.0f);*/ // Creer des vaiable pour des couleurs 
//
//        //Dessiner un Objet en activant le VAO
//        glBindVertexArray(vao);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glfwSwapBuffers(window);
//    }
//
//    // Suppression des objets créés
//    glDeleteVertexArrays(1, &vao);
//    glDeleteBuffers(1, &vbo);
//    /*glDeleteBuffers(1, &ebo);*/
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