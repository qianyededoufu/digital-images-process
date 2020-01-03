#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv; 
int inti()
{
	Mat  image_source = imread("e:\\lena.jpg", IMREAD_GRAYSCALE);
	Mat image_template = imread("e:\\lefteye_lena.jpg", 0);//righteye_lena.jpg
	imshow(" image_source", image_source);
	imshow("image_template ", image_template); 
	Mat image_matched;
	matchTemplate(image_source,image_template,image_matched,TM_SQDIFF);
	double minVal,maxVal;
	Point minLoc,maxLoc;
	minMaxLoc(image_matched,&minVal,&maxVal,&minLoc,&maxLoc);
	Point matchLoc;
	matchLoc=minLoc;
	Point right_botton=Point(matchLoc.x+image_template.cols,matchLoc.y+image_template.rows);
	rectangle(image_source,matchLoc,right_botton,Scalar(255));
	imshow("target",image_source);
	waitKey(0);
	return 0;
}
