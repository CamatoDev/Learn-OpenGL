#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

uniform vec3 lightPos; // Position de la lumière
uniform vec3 lightColor; // Couleur de la lumière
uniform vec3 viewPos; // Position de la caméra

void main()
{
    // Éclairage ambiant
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Éclairage diffus
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Éclairage spéculaire
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Résultat final
    vec3 result = (ambient + diffuse + specular) * mix(texture(texture1, TexCoord), texture(texture2, TexCoord), mixValue).rgb;
    FragColor = vec4(result, 1.0);
}