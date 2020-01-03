#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int thresh = 80;
Mat src, edge;
void onchange_thresh(int, void *);
RNG rng(1234);
int main()
{
	src = imread("e:\\aodi.jpg", 1);
	imshow("src", src);
	cvtColor(src, src, COLOR_BGR2GRAY);
	GaussianBlur(src, src, Size(3, 3), 0);
	namedWindow("contoursImage");
	createTrackbar("thresh", "contoursImage", &thresh, 250, onchange_thresh);
	onchange_thresh(0, 0);
	waitKey(0);
	return 0;
}
void onchange_thresh(int, void *)
{
	Canny(src, edge, thresh, thresh * 2, 3);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(edge, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	Mat contoursImage = Mat::zeros(edge.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{   
		double mianji=contourArea(contours[i]);
		Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		if(10<mianji<150){
			Rect rect=boundingRect(contours[i]);
			rectangle(contoursImage,rect,color);
		}
		drawContours(contoursImage, contours, i, color);
	}
	imshow("contoursImage", contoursImage);
}
