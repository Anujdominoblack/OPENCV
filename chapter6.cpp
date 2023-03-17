#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

/// /////////////////////////////COLOR DETECTION //////////////////////////////////

int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main()
{
	string path = "Resources/lambo.jpg";  //this is the path where our image is strored

	//first we will convert this image type to hsv image 

	Mat imgHSV,mask;
	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);
  //for reading the image 

	//now we will create our trackbar so we dont need to check all the hsv values over and over 

	//we will create a new window for that using namedindow("name",size)
	namedWindow("trackbar", (640, 200));

	//now we will create a trackbar for controlling the values using createtrackbar (what functionality,name,address,maximumvalue

	createTrackbar("hmin", "trackbar", &hmin, 179);
	createTrackbar("hmax", "trackbar", &hmax, 179);
	createTrackbar("smin", "trackbar", &smin, 255);
	createTrackbar("smax", "trackbar", &smax, 255);
	createTrackbar("vmin", "trackbar", &vmin, 255);
	createTrackbar("vmax", "trackbar", &vmax, 255);

	//for this work evertything shoild be inside the while loop
	while (true) {

		Scalar lower(hmin, smin, vmin);   //hmine means hue minimum,smin means saturation min and v min means value minimum

		Scalar upper(hmax, smax, vmax);   //hmax means hue maximum,smax means saturation maximum and v max means value maximum

		//after converting to hsv we will use inrange function to actually collect our color by
		// inRange(hsv(input),lowerlimit,upperlimit,output)
		inRange(imgHSV, lower, upper, mask);
		imshow("image", img);   //for displaying the output iamge
		imshow("image hsv", imgHSV);//output for the HSV image 
		imshow("mask", mask);
		waitKey(1);  //to close the image
	}

}