// ProjectOne.cpp : 定义控制台应用程序的入口点。
//
#include "cgProgram.h" //一定要放在glew之前

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
	glClearColor(0.0, 0.0, 0.0, 1.0);//设置背景色白色
}

void LoadShader()
{

	//编译与链接Shader
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
	//定义三角形顶点坐标，法向量及纹理坐标
	int countv = 0;
	int countc = 0;

	//双色
	cx = 600;
	cy = 200;
	c1 = 0;
	c2 = 0;
	float c[6] = { 1.0,0.0,0.0,1.0,1.0,1.0 };
	DrawStar(vertc,color,c1,c2,cx,cy, R,r, theta,c);

	//线段
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

	//单色
	cx = 350;
	cy = 200;
	c1 = 80;
	c2 = 120;
	c[0] = 1.0; c[1] = 0.0; c[2] = 0.0; c[3] = 1.0; c[4] = 0.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r,theta, c);


	//四边形
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


	//大星
	cx = 200;
	cy = 650;
	R = 60;
	theta = 3.1415926/10;
	r=R/ (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 152;
	c2 = 228;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//小星1
	cx = 300;
	cy = 710;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 212;
	c2 = 318;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//小星2
	cx = 340;
	cy = 670;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195 - 0.141897-0.2;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 272;
	c2 = 408;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//小星3
	cx = 340;
	cy = 610;
	R = 20;
	theta = 3.1415926 / 10 ;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 332;
	c2 = 498;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	//小星4
	cx = 300;
	cy = 570;
	R = 20;
	theta = 3.1415926 / 10 - 0.5404195 ;
	r = R / (sin(3.1415926 * 3 / 10) / sin(3.1415926 / 10));
	c1 = 392;
	c2 = 588;
	c[0] = 1.0; c[1] = 1.0; c[2] = 0.0; c[3] = 1.0; c[4] = 1.0; c[5] = 0.0;
	DrawStar(vertc, color, c1, c2, cx, cy, R, r, theta, c);

	glGenBuffers(2, vboHandle);//生成缓冲区，数据

	glGenVertexArrays(1, &vaoHandle);//生成顶点数组，与vertex shader绑定
	glBindVertexArray(vaoHandle);//可以多个顶点数组，使用时需要激活哪一个

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);//激活（绑定）当前缓冲区
	glBufferData(GL_ARRAY_BUFFER, 226 * 2 * sizeof(float), vertc, GL_STATIC_DRAW);//内存数据复制到显存
	glVertexAttribPointer((GLuint)0, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));//Vertex Shader的顶点坐标输入属性（序号0，坐标）对应
	glEnableVertexAttribArray(0);  // 允许Vertex着色器中输入变量0读取显存数据。

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);//缓冲区数据（颜色）和顶点绑定
	glBufferData(GL_ARRAY_BUFFER, 226 * 3 * sizeof(float), color, GL_STATIC_DRAW);//内存数据复制到显存
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));//Vertex Shader的顶点颜色输入（序号1，颜色）属性对应
	glEnableVertexAttribArray(1);  //  // 允许Vertex着色器中输入变量1读取显存数据。

	glBindVertexArray(0);

	delete[] vertc;
	delete[] color;

}




void reshape(int width, int height)//窗口大小变化时执行
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);

	projection = glm::ortho(0.0f,(float)width,0.0f,(float)height);
}

void keyboard(unsigned char key, int x, int y)//响应键盘
{
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//启用需要的shader，可以动态切换不同的shader
    prog.Use();

	prog.SetUniform("ProjectionMatrix", projection);

	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLES, 0, 30);//GL_LINES线段
	glDrawArrays(GL_LINE_LOOP, 30, 10);//GL_LINES线段
	glDrawArrays(GL_TRIANGLES, 40, 30);//GL_LINES线段
	glDrawArrays(GL_TRIANGLES, 70, 156);//GL_LINES线段
	glBindVertexArray(0);

	//关闭所用的shader
	prog.Unuse();


	//glFlush();//单缓冲时必须要，说明绘图命令（函数）结束
	glutSwapBuffers();//交换缓冲（双缓冲时使用）
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
	glutDisplayFunc(display);//图形绘制

	glutReshapeFunc(reshape);//窗口大小变化
	glutKeyboardFunc(keyboard);//键盘交互

	glutMainLoop();

	glDeleteBuffers(2, vboHandle);//释放显存缓冲区
	glDeleteVertexArrays(1, &vaoHandle);//删除顶点数组对象

	return 0;
}
