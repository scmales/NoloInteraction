#version 400 core
in vec3 vertexColor;  //和顶点着色器声明了一样的变量名字，用于接收顶点着色器的输出；
in vec2 texCoord;

out vec4 FragColor;  

uniform sampler2D texture1;
uniform sampler2D texture2;

 void main()  
 {  
     //FragColor = vec4(vertexColor, 1.0); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
	FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.2);	

 }