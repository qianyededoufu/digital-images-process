#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv; 
Mat roberts(Mat &srcImage);
int rober()
{
	Mat src = imread("e:\\lena.jpg",0); 
	imshow("src",src);
	Mat dst=roberts(src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}
Mat roberts(Mat &srcImage)
{
	Mat dstImage=srcImage.clone();
	int t1,t2,t;
	for(int i=0;i<srcImage.rows-1;i++){
		for(int j=0;j<srcImage.cols-1;j++){
			
				t1=(srcImage.at<uchar>(i,j) - srcImage.at<uchar>(i+1, j+1));
			    t2=(srcImage.at<uchar>(i+1,j) - srcImage.at<uchar>(i, j+1));
				t=sqrt(t1*t1+t2*t2);
				dstImage.at<uchar>(i, j)=t;

		}
	}
	return dstImage;

}
