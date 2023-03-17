#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
// images 
void  getshapes(Mat imgdil,Mat img)   //function for detecting the shapes 
{    //we will call the findcontour function to find the shapes
	 //it works as findcontour(inputimage,contours,hierachy,method,and chain

	vector<vector<Point>> contour;
	  // use it with proper image vector<vector<Point>> conpoly(contour.size());
	vector<Vec4i> hierachy; //its a open cv data type means it have four integer value vector
	findContours(imgdil, contour, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//for output
	drawContours(img, contour, -1, Scalar(255, 0, 255),2);  //img for on which we want to draw -1 for all  thickness of 2

	//to remove something we have a filter and if an area is above certain value then it should detect it as an object
	 
	// and we will create a loop for that puepose 

	for (int i = 0; i < contour.size(); i++)  //as contour is of a vector class 
	{
		int area = contourArea(contour[i]); //contour area is a fucntion to find the area of  a particuLar contour 
		cout << area << endl;

		 // use it with proper image 
		  /**if (area > 1000)
		{  //now for the bounding box 
			//for this we will use perimeter
			float peri = arcLength(contour[i], true); //boolean for knowing is it closed for  not 

			// now for the no of corner points or curve this polygon has 
			approxPolyDP(contour[i],conpoly[i],0.02*peri,true);   //n array to keep the updated value 
			drawContours(img, contour, -1, Scalar(255, 0, 255), 2); //when have multiplt shapes replace -1 by i
		}/**/
	}

 }



void main()
{
	string path = "Resources/shapes.jpg";  //this is the path where our image is strored
	Mat imgGray;
	Mat img = imread(path);  //for reading the image
	//for detcting shape first we have to detect it edges using canny edge detector but for that we have to blur it and grey convert
	
	 //THIS IS THE PREPROCESSING OF THE IMAGE BEFORE SHAPE DETECTION
	cvtColor(img, imgGray, COLOR_BGR2GRAY); //we are converting BGR(bluegreenred) to grey form
    Mat imgblur;
	GaussianBlur(imgGray, imgblur, Size(1, 1), 10, 10);
    Mat imgcanny;
	//now we will use the canny fucntion here 
	Canny(imgblur, imgcanny, 150, 50);
	Mat  imgdil;
	//kernel will be defined using mat kernel = getstructuringelement(typeof shape using morph,size(our desried))
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgcanny, imgdil, kernel); //dilate function is created and called 

	//PREPROCESSING ENDS

	getshapes(imgdil, img);//image we want to find shapes on  and the image on which we want to draw

	imshow("image", img);   //for displaying the output iamge
	/*imshow("image gray", imgGray);
	imshow("image blur", imgblur);
	imshow("image canny", imgcanny);
	imshow("image dilate", imgdil);*/
	waitKey(0);  //to close the image

}
