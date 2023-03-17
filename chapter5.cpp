  //This is for the warp prespective of the image 
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
//   cause we are importing an images 

//defiinig the width and the height off the wrapped image 

float w =250,h=250;
Mat  matrix, imgwrap;
void main()
{    //first we need the points we want to warp
	string path = "Resources/cards.jpg";  //this is the path where our image is strored
	Mat img = imread(path);  //for reading the image

	Point2f src[4] = { {127,80},{223,132},{274,115},{215,63} }; //this will take input of  the iamge cordinate we want to wrap  and 
		//this is the source 

	//this is for the destination

	Point2f dst[4] = { {0.0,0.0},{w,0.0},{0.0,h},{w,h} }; 
	//now we will use a transform matrix to find the wrap 
	matrix = getPerspectiveTransform(src, dst); //this function is call for the perspective 
	 

	//now we will call warp perspective for the real transformation (input,output,our input paramter,size i.e point(widht and eheight)

	warpPerspective(img,imgwrap,matrix,Point(w,h));

	//for generating circles along the desired four points 

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255));
	}

	imshow("image", img);   //for displaying the output iamge
	imshow("wrap image",imgwrap);
	waitKey(0);  //to close the image

}