#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int ma()
{
	Mat  src = imread("e:\\yuan.png", 1);	
	imshow("src", src);
	Mat srcgray,threshimage;
	cvtColor(src, srcgray, COLOR_BGR2GRAY);
	threshold(srcgray,threshimage,220,255,THRESH_BINARY);
	imshow("threshimage", threshimage);
	vector<vector<Point>> contours; //ÐÂ½¨ÈÝÆ÷
	vector<Vec4i> hierarchy;
	findContours(threshimage,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);
	Mat contourimage(threshimage.size(),CV_8UC3,Scalar(0));
	for(int i=0;i<contours.size();i++){
		RNG rng(getTickCount());
		Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		drawContours(contourimage,contours,i,color);
	}
	drawContours(contourimage,contours,-1,Scalar(255));
 	imshow("contoursImage",contourimage);
	waitKey(0);
	return 0;
}
