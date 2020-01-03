#include<opencv2\opencv.hpp>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("e:\\person1.png", 1);
	if(!src.data){
		cout<<"error"<<endl;
		return -1;
	}
	imshow("src", src);
	Mat kennel=Mat::ones(3,3,CV_32FC1);
	kennel=kennel/9;
	Mat dst;
	filter2D(src,dst,src.depth(),kennel,Point(-1,-1),0,BORDER_DEFAULT);
	imshow("dst",dst);
	waitKey(0);
	return 0;    
}

