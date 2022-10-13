// ProjectOne.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "cgProgram.h" //һ��Ҫ����glew֮ǰ

#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/constants.hpp>
#include<bits/stdc++.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

using glm::vec4;

cgProgram prog;

unsigned int vboHandle[2];
unsigned int vaoHandle;

mat4 projection;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);//���ñ���ɫ��ɫ
}

void LoadShader()
{

	//����������Shader
	prog.CompileShader("Shader/basic.vs");
	prog.CompileShader("Shader/basic.fs");
	prog.Link();
}

void DrawStar(float *vertc, float *color, int c1, int c2, float cx, float cy, float R, float r, float theta, float *c)
{
	float a = 3.1415926/5;
	int countv, countc;
	countv = c1;
	countc = c2;
	for (int i = 0; i < 10; i++)
	{
		vertc[countv++] = cx;
		vertc[countv++] = cy;
		color[countc++] = c[3];
		color[countc++] = c[4];
		color[countc++] = c[5];
		countv = countv + 4;
		countc = countc + 6;
	}
	countv = c1+2;
	countc = c2+3;
	for (int i = 0; i < 5; i++)
	{
		vertc[countv++] = cx + r * cos(theta + a - 2 * i*a);
		vertc[countv++] = cy + r * sin(theta + a - 2 * i*a);
		color[countc++] = c[0];
		color[countc++] = c[1];
		color[countc++] = c[2];
		countv = countv + 4;
		countc = countc + 6;
		vertc[countv++] = cx + r * cos(theta + a - 2 * i*a);
		vertc[countv++] = cy + r * sin(theta + a - 2 * i*a);
		color[countc++] = c[3];
		color[countc++] = c[4];
		color[countc++] = c[5];
		countv = countv + 4;
		countc = countc + 6;

	}
	countv = c1+58;
	countc = c2+87;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			vertc[countv++] = cx + R * cos(theta + 2 * a - 2 * i*a);
			vertc[countv++] = cy + R * sin(theta + 2 * a - 2 * i*a);
			color[countc++] = c[3];
			color[countc++] = c[4];
			color[countc++] = c[5];
		}
		else
		{
			vertc[(countv++) % (c1+60) + c1] = cx + R * cos(theta + 2 * a - 2 * i*a);
			vertc[(countv++) % (c1 + 60) + c1] = cy + R * sin(theta + 2 * a - 2 * i*a);
			color[(countc++) % (c2+90)+c2] = c[3];
			color[(countc++) % (c2 + 90) + c2] = c[4];
			color[(countc++) % (c2 + 90) + c2] = c[5];
		}
		countv = countv + 4;
		countc = countc + 6;
		vertc[(countv++) % (c1 + 60) + c1] = cx + R * cos(theta + 2 * a - 2 * i*a);
		vertc[(countv++) % (c1 + 60) + c1] = cy + R * sin(theta + 2 * a - 2 * i*a);
		color[(countc++) % (c2 + 90) + c2] = c[0];
		color[(countc++) % (c2 + 90) + c2] = c[1];
		color[(countc++) % (c2 + 90) + c2] = c[2];
		countv = countv + 4;
		countc = countc + 6;
	}




}

void Draw()
{
	float cx, cy, R, r, theta;
	float * vertc = new float[226 * 2];
	float * color = new float[226 * 3];
	float a = 3.1415926 / 5;
	int c1, c2;
	R = 40 * sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10);
	r = 40;
	theta = 3.1415926 / 7;
	//���������ζ������꣬����������������
	int countv = 0;
	int countc = 0;

	//˫ɫ
	cx = 600;
	cy = 200;
	c1 = 0;
	c2 = 0;
	float c[6] = { 1.0,0.0,0.0,1.0,1.0,1.0 };
	DrawStar(vertc,color,c1,c2,cx,cy, R,r, theta,c);

	//�߶�
	cx = 120;
	cy = 200;
	countv = 62;
	countc = 93;
	for (int i = 0; i < 5; i++)
	{
		vertc[countv++] = cx + r * cos(theta + a - 2 * i*a);
		vertc[countv++] = cy + r * sin(theta + a - 2 * i*a);
		color[countc++] = 1.0;
		color[countc++] = 0.0;
		color[countc++] = 0.0;
		countv = countv + 2;
		countc = countc + 3;

	}
	countv = 60;
	countc = 90;
	for (int i = 0; i < 5; i++)
	{
		vertc[countv++] = cx + R * cos(theta + 2 * a - 2 * i*a); vertc[countv++] = cy + R * sin(theta + 2 * a - 2 * i*a);
		color[countc++] = 1.0;   color[countc++] = 0.0;    color[countc++] = 0.0;
		countv = countv + 2;
		countc = countc + 3;
	}

	//��ɫ
	cx = 350;
	cy = 200;
	c1 = 80;
	c2 = 120;
	c[0] = 1.0; c[1] = 0.0; c[2] = 0.0; c[3] = 1.0; c[4] = 0.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r,theta, c);


	//�ı���
	vertc[140] = 100; vertc[141] = 750;
	color[210] = 1.0; color[211] = 0.0; color[212] = 0.0;
	vertc[142] = 700; vertc[143] = 750;
	color[213] = 1.0; color[214] = 0.0; color[215] = 0.0;
	vertc[144] = 100; vertc[145] = 350;
	color[216] = 1.0; color[217] = 0.0; color[218] = 0.0;
	vertc[146] = 700; vertc[147] = 750;
	color[219] = 1.0; color[220] = 0.0; color[221] = 0.0;
	vertc[148] = 100; vertc[149] = 350;
	color[222] = 1.0; color[223] = 0.0; color[224] = 0.0;
	vertc[150] = 700; vertc[151] = 350;
	color[225] = 1.0; color[226] = 0.0; color[227] = 0.0;


	//����
	cx = 200;
	cy = 650;
	R = 60;
	theta = 3.1415926/10;
	r=R/ (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 152;
	c2 = 228;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//С��1
	cx = 300;
	cy = 710;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 212;
	c2 = 318;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//С��2
	cx = 340;
	cy = 670;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195 - 0.141897-0.2;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 272;
	c2 = 408;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//С��3
	cx = 340;
	cy = 610;
	R = 20;
	theta = 3.1415926 / 10 ;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 332;
	c2 = 498;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//С��4
	cx = 300;
	cy = 570;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195 ;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 392;
	c2 = 588;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	glGenBuffers(2, vboHandle);//���ɻ�����������

	glGenVertexArrays(1, &vaoHandle);//���ɶ������飬��vertex shader��
	glBindVertexArray(vaoHandle);//���Զ���������飬ʹ��ʱ��Ҫ������һ��

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);//����󶨣���ǰ������
	glBufferData(GL_ARRAY_BUFFER, 226 * 2 * sizeof(float), vertc, GL_STATIC_DRAW);//�ڴ����ݸ��Ƶ��Դ�
	glVertexAttribPointer((GLuint)0, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));//Vertex Shader�Ķ��������������ԣ����0�����꣩��Ӧ
	glEnableVertexAttribArray(0);  // ����Vertex��ɫ�����������0��ȡ�Դ����ݡ�

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);//���������ݣ���ɫ���Ͷ����
	glBufferData(GL_ARRAY_BUFFER, 226 * 3 * sizeof(float), color, GL_STATIC_DRAW);//�ڴ����ݸ��Ƶ��Դ�
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));//Vertex Shader�Ķ�����ɫ���루���1����ɫ�����Զ�Ӧ
	glEnableVertexAttribArray(1);  //  // ����Vertex��ɫ�����������1��ȡ�Դ����ݡ�

	glBindVertexArray(0);

	delete[] vertc;
	delete[] color;

}




void reshape(int width, int height)//���ڴ�С�仯ʱִ��
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);

	projection = glm::ortho(0.0f,(float)width,0.0f,(float)height);
}

void keyboard(unsigned char key, int x, int y)//��Ӧ����
{
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//������Ҫ��shader�����Զ�̬�л���ͬ��shader
    prog.Use();

	prog.SetUniform("ProjectionMatrix", projection);

	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLES, 0, 30);//GL_LINES�߶�
	glDrawArrays(GL_LINE_LOOP, 30, 10);//GL_LINES�߶�
	glDrawArrays(GL_TRIANGLES, 40, 30);//GL_LINES�߶�
	glDrawArrays(GL_TRIANGLES, 70, 156);//GL_LINES�߶�
	glBindVertexArray(0);

	//�ر����õ�shader
	prog.Unuse();


	//glFlush();//������ʱ����Ҫ��˵����ͼ�������������
	glutSwapBuffers();//�������壨˫����ʱʹ�ã�
}



int main(int argc, char* argv[])
{
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 600);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Project One");

	glewInit();
	init();

	LoadShader();
	Draw();
	glutDisplayFunc(display);//ͼ�λ���

	glutReshapeFunc(reshape);//���ڴ�С�仯
	glutKeyboardFunc(keyboard);//���̽���

	glutMainLoop();

	glDeleteBuffers(2, vboHandle);//�ͷ��Դ滺����
	glDeleteVertexArrays(1, &vaoHandle);//ɾ�������������

	return 0;
}
