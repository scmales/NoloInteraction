#version 400 core
in vec3 vertexColor;  //�Ͷ�����ɫ��������һ���ı������֣����ڽ��ն�����ɫ���������
in vec2 texCoord;

out vec4 FragColor;  

uniform sampler2D texture1;
uniform sampler2D texture2;

 void main()  
 {  
     //FragColor = vec4(vertexColor, 1.0); //vec4(1.0f, 0.5f, 0.2f, 1.0f);
	FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.2);	

 }