#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void changeImg(int, void* );
Mat src,srcgray,threshimage,contoursimage;
int thresh=0,max_thresh=255;
int miain()
{
	src = imread("e:\\handok.jpg", 1);//yuan.png   tubao.jpg  cartoon.png
	imshow("src", src);	
	cvtColor(src, srcgray, COLOR_BGR2GRAY);
	blur(srcgray, srcgray, Size(3, 3));
	namedWindow("contoursimage");
	createTrackbar( "lunkuo","contoursimage", &thresh, max_thresh,changeImg);
	waitKey(0);
	return 0;
}
void changeImg(int, void* ){
	threshold(srcgray, threshimage, thresh, max_thresh, THRESH_BINARY);
	imshow("threshimage", threshimage);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Mat contoursimage(threshimage.size(), CV_8UC3);
	findContours(threshimage,contours,RETR_TREE,CHAIN_APPROX_SIMPLE);
	vector<vector<Point>>hull(contours.size());
	drawContours(contoursimage,contours,-1,Scalar(255,0,0));
	for(size_t i=0;i<contours.size();i++){
		convexHull(contours[i],hull[i],true,true);
		drawContours(contoursimage,hull,i,Scalar(0,0,255));
	}
 	imshow("contoursimage", contoursimage);
}

