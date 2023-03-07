#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
// basic function
void main()
{
	string path = "Resources/test.png";  //this is the path where our image is strored
	Mat img = imread(path); //for reading the image

	 //after reading the image we are converting it into greyscale to convert it into greyscale we will use cvtcolor function
	//which takes argument(inputimage,ouputimage,conversion

	//we will first degfine the image grey for greyconversion
	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY); //we are converting BGR(bluegreenred) to grey form

	//no we will add blur to our image if we want to blur our image the most commom is the gaussian blur and for that 
	//we will use the gaussian blur feature or fuction and with three arguments(image,destination or ouput image,define the sizeof kernel with size(x,y),5,0
	// 
	//we have to define the imageblur for using it as destiantion or destination image
	Mat imgblur;
	GaussianBlur(img, imgblur, Size(1, 1), 10, 10);

	//and now we will perform the edge detection and how to perform edge detection  and we will do it using canny edge detector 
	//befor canny makee the image little  blur canny take arguments as(image,imgcanny,threshold1(any num),threshold2(anynum))
	//before using the destination of canny we have to define it na so
	Mat imgcanny;
	//now we will use the canny fucntion here 
	Canny(imgblur, imgcanny, 150, 50);

	//now we will learn how to dilate or erode an image that will increase the edge thickness and then erdod the thickness
	
	//for yis we will use dilate function with three arguments(imagecanny,imageoutput,kernel)

	//we will define imageouput also and this will take canny image as input because edge is detected there 

	Mat  imgdil;

	//kernel will be defined using mat kernel = getstructuringelement(typeof shape using morph,size(our desried))
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgcanny, imgdil, kernel); //dilate function is created and called 

	//now we can do erosion also with use of erode function which take arguments as
	// erode take image dilation as input and the image erode as output and we will have to define a kernel also as we 
	// done it in image dilation
	//output image creation 
	Mat imgerode;
	erode(imgdil, imgerode, kernel);


	imshow("image", img);   //for displaying the output iamge
	imshow("image gray", imgGray);  //this function s used to show the image 
	imshow("image blur ", imgblur);//for the output window
	imshow("image canny", imgcanny);//output for edge detection
	imshow("image dilation", imgdil);//output for image dilation
	imshow("image erode ", imgerode); //output of image erode 
	waitKey(0);  //to close the image

}