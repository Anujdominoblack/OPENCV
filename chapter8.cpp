#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>  //for using viola jones 
#include<iostream>
using namespace cv;
using namespace std;
// images face detection 
void main()
{
	string path = "Resources/t3.jpg";  //this is the path where our image is strored
	Mat img = imread(path);  //for reading the image
	// to detect the faace we are going to viola jones method of hard cascades

	CascadeClassifier facecascade;  //loading our cascade and naming it 
	facecascade.load("Resources/haarcascade_frontalface_default.xml");  //to load xml file

	if (facecascade.empty()) {
		cout << "xml file not loaded ";  //to check our xml file is loaded properly or not
	}

	//now we will create and detect faces and stores them
	 // for this we will use bounding boxes and they are rectangle

	// so we will create a vector of rectangles

	vector<Rect> faces;

	//no we will use facecascade.detectmultiscale function with arguments(input image,faces where we store,scale,and neighbours)
	facecascade.detectMultiScale(img, faces, 1.1, 10);

	//for output we will iterate through all the faces 

	for (int i = 0; i < faces.size();i++)
	{
		//writing code for rectangle 
		rectangle(img,faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("image", img);   //for displaying the output iamge
	waitKey(0);  //to close the image

}