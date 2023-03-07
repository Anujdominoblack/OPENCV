#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
//  this is for resizeing and cropping our image 
void main()
{
	string path = "Resources/test.png";  //this is the path where our image is strored
	Mat img = imread(path); //for reading the image

	//to  resize we have a function called resize(input,output image,the size we want to change)
	Mat imgresize;  //output image is created 
	cout << img.size() << endl; //for knowing the size of our image 

	resize(img, imgresize, Size(640, 480));//here we can scale it using by (size(),x,y)  x and y should be in double

	// to crop and image 

	Mat imagecrop;
	Rect roi(200, 100, 300, 250);//we will use rectangle data type for cropping providing it  x and y  and widht and height 
	imagecrop = img(roi);

	imshow("image resize",imgresize); //for displaying the output iamge
	imshow("image crop", imagecrop);
	
	waitKey(0);  //to close the image

}