#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec3 aColor;
layout (location = 1) in vec2 aTexCoord;
out vec4 vertexColor;
out vec3 ourColor;
out vec2 TexCoord;
uniform mat4 transform;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float XValue;
void main()
{
   gl_Position = projection*view*model*vec4(aPos, 1.0);//

   //gl_Position = projection*view*model*vec4(aPos.x+XValue, aPos.y, aPos.z, 1.0);
  //gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
 
   vertexColor = vec4(aColor, 1.0);
   ourColor = aColor;
   TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}