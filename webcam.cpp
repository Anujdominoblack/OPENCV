#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
// for videos 
//a video is basically images so we need to iterate thorugh all the images to get the videos
void main()
{
	string path = "Resources/testvideo.mp4";
	VideoCapture cap(path);
	Mat img;
		while (true) {
			cap.read(img);
			
			
				imshow("image", img);
			//for displaying the output iamge 
			waitKey(20);  //to close the image 

		}
}