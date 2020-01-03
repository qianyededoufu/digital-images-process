#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv; 
int showVideo(){
	VideoCapture capture("e:\\1.mp4");
	if (capture.isOpened()==false){
		cout<<"open error!"<<endl;
		system("pause");
		return -1;
	}
	Mat edge;
	while(1){
		Mat frame;
		capture.read(frame);
		if(!frame.empty()){
			cvtColor(frame,frame,COLOR_RGB2GRAY);
			blur(frame,frame,Size(3,3));
			Canny(frame,edge,100,200);
			imshow("show",edge);
			waitKey(100);
		}
		else{
			break;
		}
	}
	return 0;

}