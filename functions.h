//HEADERS///////////////////////////////////////////////
#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <cv.h>
#include <highgui.h>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/core/core_c.h"
#include <opencv2/legacy/compat.hpp>
#include "opencv2/imgproc/types_c.h"
#include "opencv/cv.h"
#include <opencv/cv.h>
#include <vector>

#include "cali/calibrator.h"

#ifdef WIN32
#include <windows.h>
#endif

//INLUDES OPENGL
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>        // Include OpenGL Framework headers
#include <GL/glut.h>


#define GLEW_STATIC
#define GLFW_INCLUDE_GL_3



#define FOCAL_LENGTH 760.0


using namespace cv;
using namespace std;

//CONSTANTS-------------------------------------------------------------------------
//----------------------------------------------------------------------------------
const int GL_WIN_INITIAL_X = 0;
const int GL_WIN_INITIAL_Y = 0;
int FRAME_WIDTH = 1280;
int FRAME_HEIGHT = 720;
int winWidth = FRAME_WIDTH;
int winHeight = FRAME_HEIGHT;


/*int FRAME_WIDTH = 1280;
int FRAME_HEIGHT = 720;
int winWidth = FRAME_WIDTH;
int winHeight = FRAME_HEIGHT;*/

//GLOBAL VARS0-----------------------------------------------------------------------
Calibrator cali;
//----------------------------------------------------------------------------------
double fovx, fovy; 
//------------------------------------------------------------
FileStorage fs;
Mat intrinsics, distortion;
Mat webcamImage, one,gray;
Mat rvec = Mat(Size(3,1), CV_64F);
Mat tvec = Mat(Size(3,1), CV_64F);
bool found=false;
//setup vectors to hold the chessboard corners in the chessboard coordinate system and in the image
vector<Point2d> imagePoints, imageFramePoints, imageOrigin;
vector<Point3d> boardPoints, framePoints;
VideoCapture capture;
IplImage* pFrame = cvCreateImage(cvSize(FRAME_WIDTH, FRAME_HEIGHT), IPL_DEPTH_8U, 3);


//GLOBAL VARS1-----------------------------------------------------------------------
//----------------------------------------------------------------------------------
Mat glViewMatrix;
Mat rotation;

//GLOBAL VARS2-----------------------------------------------------------------------
//----------------------------------------------------------------------------------
int boardHeight = 3;
int boardWidth = 4;
Size cbSize = Size(boardHeight,boardWidth);

bool doneYet = false;


void drawAxes(float length){
		glPushAttrib(GL_POLYGON_BIT | GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_LIGHTING);

		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(length, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, length, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, length);
		glEnd();
		glPopAttrib();
}


GLuint texture[2];

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 50.0f };

void display(void){	
	
	glPushMatrix();

	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


	glClear(GL_DEPTH_BUFFER_BIT);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	
	/*glTranslatef(-3,-5,0);     
    glColor3f(0.2, 0.8, 0.1);     
    glScalef(1,1,1);
    glutSolidTeapot(5.5);*/

    for(int i=0;i<3;i++)
    {    	      
    	glTranslatef(10, 67.5*i*1.f,0);    
    	glColor3f(0.8, 0.2, 0.8); 
    	glScalef(1,1,1);
    	glutSolidTeapot(22.5);
    	
    	for(int j=0;j<3;j++)
    	{
 
    		glTranslatef(67.5,0,0);        		    		    		
    		glColor3f(0.8, 0.2, 0.8); 
    		glScalef(1,1,1);
    		glutSolidTeapot(22.5);
    	}
		glPopMatrix();
    	
    }                
  

    glTranslatef(0,0,0);    
    glColor4f(0.8, 0.5, 0.4,0.85); 
    glRotatef(270,1.0,0.0,0.0);
    glRotatef(0,0.0,1.0,0.0);
    glRotatef(0,0.0,0.0,1.0); 
    glScalef(1,1,1);
    glutSolidSphere(45,30,30);
    //glutWireTeapot(25.5);
    //glutSolidTeapot(25.5);

  

    glBindTexture(GL_TEXTURE_2D, texture[0]); 
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_NORMALIZE);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);



    glPopMatrix();
    glFlush();


    //----------------------------------------------------         
	
} 

void glutDisplay(void){

    //capture.read(webcamImage);										//store image to matrix    
    cali.read(webcamImage);
	cvtColor(webcamImage,gray,COLOR_BGR2GRAY);			//make a gray copy of the webcam image			
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//DIBUJAR LA IMAGEN DE OPENCV EN OPENGL
	Mat tempimage;
	flip(webcamImage,tempimage,0);
	for (int i = 0; i < tempimage.size().width; i++)
		for (int j = 0; j < tempimage.size().height; j++)
			swap(tempimage.ptr<Vec3b>(j)[i][0], tempimage.ptr<Vec3b>(j)[i][2]);
	glDrawPixels(tempimage.size().width, tempimage.size().height, GL_RGB, GL_UNSIGNED_BYTE, tempimage.ptr());	
	//drawAxes(10);

	pFrame = new IplImage(webcamImage);
	//found = findChessboardCorners(gray, cbSize, imagePoints, CALIB_CB_FAST_CHECK);			 //detect chessboard corners		 	
	found = cali.findCirclesGrid(gray, cbSize, imagePoints);
	//CvTermCriteria criteria = cvTermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 100, 1.0e-4f);
	//SI SE ENCUENTRA EL PATRON

	if ( found )
	{
		solvePnP( Mat(boardPoints), Mat(imagePoints), intrinsics, distortion, rvec, tvec, false );	//find the camera extrinsic parameters		
		projectPoints(framePoints, rvec, tvec, intrinsics, distortion, imageFramePoints ); 	 //project the reference frame onto the image
		Rodrigues(rvec, rotation);	
		

		//DIBUJAR EN LA VENTANA OPENCV	
		circle(webcamImage, (Point) imagePoints[0], 20 ,CV_RGB(255,0,0) );				 //DRAWING						 			
		line(webcamImage, imageFramePoints[0], imageFramePoints[1], CV_RGB(255,0,0), 2 );
		line(webcamImage, imageFramePoints[0], imageFramePoints[2], CV_RGB(0,255,0), 2 );
		line(webcamImage, imageFramePoints[0], imageFramePoints[3], CV_RGB(0,0,255), 2 );	


//---------------------------------------------------proyection-----------------------------


	Mat projMat = Mat::zeros(4, 4, CV_64FC1);	
	float zfar = 10000.f, znear = 0.1f;
	//cout << cameraMatrix.at<double>(0, 0) << " " << cameraMatrix.at<double>(0, 1) << " " << cameraMatrix.at<double>(0, 2) << " " << cameraMatrix.at<double>(1, 1) << " " << cameraMatrix.at<double>(1, 2) << endl;

	projMat.at<double>(0, 0) = 2 * intrinsics.at<double>(0, 0) / tempimage.size().width;
	projMat.at<double>(0, 1) = 2 * intrinsics.at<double>(0, 1) / tempimage.size().width;
	projMat.at<double>(0, 2) = -1 + (2 * intrinsics.at<double>(0, 2) / tempimage.size().width); // en la diapo del profe es su negativo se equivoco
	projMat.at<double>(1, 1) = 2 * intrinsics.at<double>(1, 1) / tempimage.size().height;
	projMat.at<double>(1, 2) = -1 + (2 * intrinsics.at<double>(1, 2) / tempimage.size().height);// en la diapo del profe es su negativo se equivoco
	projMat.at<double>(2, 2) = -(zfar + znear) / (zfar - znear);
	projMat.at<double>(2, 3) = -2 * zfar*znear / (zfar - znear);
	projMat.at<double>(3, 2) = -1;

	double projectionMatrix[16];
	//La matriz projMat sacamos su transpuesta y lo metemos todo a un arreglo
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			projectionMatrix[4 * j + i] = projMat.at<double>(i, j);


/*
glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glLoadMatrixd(projectionMatrix);
	glViewport(0, 0, tempimage.size().width, tempimage.size().height);
	//gluPerspective(39.0f, float(imageSize.width) / float(imageSize.height), 0.01f, 1000.0f);  YA NO LO USAMOS EN VEZ DE ESO PONEMOS glLoadMatrixd(projectionMatrix);
	glLoadMatrixd(projectionMatrix);
	*/

//-------------------------------------------------------------------------------------------------



		//SETEAR MATRIZ VIEWPORT
		glViewport(0, 0, tempimage.size().width, tempimage.size().height);
		//set projection matrix using intrinsic camera params
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//fovx = 45.3727;fovy = 36.5031;
		gluPerspective(39.0f, float(FRAME_WIDTH) / float(FRAME_HEIGHT), 0.01f, 1000.0f);
		Mat viewMatrix = cv::Mat::zeros(4, 4, CV_64FC1);
	
		for (int row = 0; row < 3; ++row) {
			for (int col = 0; col < 3; ++col){
				viewMatrix.at<double>(row, col) = rotation.at<double>(row, col);
			}
			viewMatrix.at<double>(row, 3) = tvec.at<double>(row, 0);		
		}
		viewMatrix.at<double>(3, 3) = 1.0f;		

		cv::Mat cvToGl = cv::Mat::zeros(4, 4, CV_64F);
		cvToGl.at<double>(0, 0) = 1.0f;
		cvToGl.at<double>(1, 1) = -1.0f;
		cvToGl.at<double>(2, 2) = -1.0f;
		cvToGl.at<double>(3, 3) = 1.0f;
		viewMatrix = cvToGl * viewMatrix;		
		
		transpose(viewMatrix, glViewMatrix); 


		//DIBUJAR TEAPOT
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glLoadMatrixd(&glViewMatrix.at<double>(0,0));		
		glPushMatrix();		
		display();	//dibuja teapot
		glPopMatrix();	
	
	}
	imshow("OpenCV Webcam", webcamImage);			  
    glutSwapBuffers();
    waitKey(1);
}

void glutResize(int width, int height)
{
	if (height == 0 || width == 0) return;  //Nothing is visible then, so return
	FRAME_WIDTH = width;
	FRAME_HEIGHT = height;
	winWidth = width;
	winHeight = height;
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, width, height);
	
}

void myidle(void)
{
		
	glutPostRedisplay();	
	waitKey(1);	
}

