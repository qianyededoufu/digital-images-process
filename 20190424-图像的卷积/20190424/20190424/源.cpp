#include<opencv2\opencv.hpp>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace cv;
int imgpro()
{
	Mat src = imread("e:\\person.png", 1);
	imshow("src", src);
	Mat dst;
	int top = (int)(0.09*src.rows);
	int bottom = (int)(0.09*src.rows);
	int left = (int)(0.09*src.cols);
	int right = (int)(0.09*src.cols);
	int c=0;
	int borderType = BORDER_DEFAULT;
	RNG rng(12345);
	while (true)
	{
		c = waitKey(500);
		if (c == 27)break;//  ESC   27
		if ((char)c == 'r')borderType = BORDER_REPLICATE;
		if ((char)c == 'w')borderType = BORDER_WRAP;
		if ((char)c == 'c')borderType = BORDER_CONSTANT;
		if ((char)c == 'd')borderType = BORDER_DEFAULT;
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		copyMakeBorder(src, dst, top, bottom, left, right, borderType, color); 
		imshow("dst", dst);
	}
	return 0;    
}

