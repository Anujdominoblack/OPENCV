#include<opencv2/imgcodecs.hpp>  //these are the necessary header files
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
// this function is used for reading the images
void main()
{
	string path = "Resources/test.png";  //this is the path where our image is strored 
	Mat img = imread(path);  //for reading the image 
	imshow("image", img);   //for displaying the output iamge 
	waitKey(0);  //to close the image 
	
}
 