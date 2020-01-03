#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int rect()
{
	Mat image(600,700,CV_8UC3,Scalar(0,0,0));
	RotatedRect rect(Point2f(300,300),Size2f(200,500),30);
	Point2f vertices[4];
	rect.points(vertices);
	for(int i=0;i<4;i++){
		line(image,vertices[i],vertices[(i+1)%4],Scalar(255,0,0));
	}
	imshow("image",image);
	waitKey(0);
	return 0;
}
