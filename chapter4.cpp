#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;


//this is for how to draw various shapes and put  names or text


void main()
{
	//we are not going to use any image rather we are goging to create our own image
	 
	//create blank image
	//define image (size,type)
	Mat image(512, 512, CV_8UC3,Scalar(255, 255, 255));//here 8 means 8 bit mean range  from 0 to 255 
	//if unsigned u means unsigned and C3 means 3 channels of color BGR and then the color this image will have 

	//when we define color of image we will define it as scalar and inside parentesis we will give them value of colors

	// for blue 255,0,0
	//for purple 255,0,255
	//for white 255,255,255
	//for black 0,0,0

	// now we are going to create a circle first

	//we will do it by calling circle(the input image,origin point for this use Point(),sizeof circle,colorof circle

	circle(image, Point(126, 126), 75, Scalar(0, 69, 255),10);//the last value 20 is for increasing the thickness 
	//for filled circle write FILLED instead of thickness

	//now we will draw a rectangle 
	//we will do  it by recatngle(inputimage,define two points by Point( top left corner,bottom right corner),point(),scalar()
	rectangle(image, Point(100, 100), Point(250, 150), Scalar(0, 0,0),5);

	//draw a line 
	//we will use line(image,Point(starting),Point(ending point) both of them with cordinates,scalar for  color

	line(image, Point(100, 120), Point(250, 120), Scalar(255, 255, 255),10); //y cordinate should be constant for the horziontal line
	  
	//fo putting text we will use puttext(image,what we want to display,point(x1,y1) starting point,font,scale,scalar()

	putText(image, "this is me learning open cv", Point(10, 300), FONT_HERSHEY_COMPLEX_SMALL, 1.3, Scalar(0, 0, 0), 3);


	imshow("image", image);

	waitKey(0);  //to close the image


}