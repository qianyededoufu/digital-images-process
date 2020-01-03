#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv; 
Mat image_matched,image_source,image_template;
double minVal,maxVal;
void onchange_thresh(int, void *);
int THR=0,maxTHR=5;
int main()
{
	image_source = imread("e:\\lena.jpg", IMREAD_GRAYSCALE);
	image_template = imread("e:\\lefteye_lena.jpg", 0);//righteye_lena.jpg
	imshow("image_source", image_source);
	imshow("image_template ", image_template); 
	namedWindow("image_source");
	createTrackbar("MODE", "image_source", &THR,maxTHR, onchange_thresh);
	waitKey(0);
	return 0;
}
void onchange_thresh(int, void *)
{
	matchTemplate(image_source,image_template,image_matched,THR);
	Point minLoc,maxLoc;
	minMaxLoc(image_matched,&minVal,&maxVal,&minLoc,&maxLoc);
	Point matchLoc;
	matchLoc=minLoc;
	Point right_botton=Point(matchLoc.x+image_template.cols,matchLoc.y+image_template.rows);
	rectangle(image_source,matchLoc,right_botton,Scalar(255));
	imshow("target",image_source);
}

