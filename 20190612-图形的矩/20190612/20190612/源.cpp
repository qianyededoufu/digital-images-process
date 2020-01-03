 #include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int matn()
{
	Mat src = imread("e:\\template.png", 1);
	Mat copy = src.clone();
	Mat srcgray,srcthresh;
	cvtColor(src, srcgray, COLOR_BGR2GRAY);
	threshold(srcgray, srcthresh, 100, 255, THRESH_BINARY);//È·±£ºÚÖÐÕÒ°×
	imshow("thresh", srcthresh);
	vector<vector<Point>> contours;
	findContours(srcthresh,contours,RETR_EXTERNAL,CHAIN_APPROX_NONE);
	drawContours(copy,contours,-1,Scalar(0,255,0),2,8);
	Moments dstMoment=moments(contours[0],false);
	cout<<dstMoment.m00<<endl;
	imshow("contours", copy);
	waitKey(0); 
	return 0;
}
