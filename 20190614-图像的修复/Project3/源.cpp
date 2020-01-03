#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat src,srcgray;
int thresh=0,maxthresh=250;

void onchange(int, void *);
int main()
{
	src = imread("d:\\xiake.jpg",1);
	if (!src.data)	return -1;	
	imshow("原图", src);
	cvtColor(src,srcgray,COLOR_BGR2GRAY);
	namedWindow("原图");
	createTrackbar("thresh", "原图", &thresh,maxthresh, onchange);
	onchange(0,0);
	waitKey(0);
	system("pause");
	return 0;
}
void onchange(int, void *)
{
	Mat mask(src.size(),CV_8UC1,Scalar(0));
	threshold(srcgray,mask,thresh,250,THRESH_BINARY);
	Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3)); //建立为矩形的3*3的核
	dilate(mask,mask,kernel);  //膨胀操作
	Mat dst;
	inpaint(src,mask,dst,5,INPAINT_NS);
 	imshow("mask", mask);
	imshow("after inpaint", dst);
}
