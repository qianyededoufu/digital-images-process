
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat  src = imread("e:\\houghzuqiu.png", 1);
	Mat srcgray, edge, dst;
	if (!src.data) { cout << "error" << endl; return -1; }
	imshow("src", src);
	cvtColor(src,srcgray,COLOR_RGB2GRAY);
	GaussianBlur(srcgray,srcgray,Size(3,3),0,0,BORDER_DEFAULT);
	vector<Vec3f>circles;
	HoughCircles(srcgray,circles,HOUGH_GRADIENT,1,10);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center;
		int radius;
		center.x=cvRound(circles[i][0]);
		center.y=cvRound(circles[i][1]);
		radius=cvRound(circles[i][2]);
		circle(src,center,3,Scalar(0,0,255),-1,8,0);
		circle(src,center,radius,Scalar(255,255,255),3,8,0);
	}
	imshow("h_edge",src);
	waitKey(0);
	return 0;
}