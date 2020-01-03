#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat src1 = imread("e:\\ju.png");       //lena.jpg
	Mat src2 = imread("e:\\ju.png");   // lena.jpg   两张都是lena图像，输出结果是0
	cvtColor(src1, src1, COLOR_BGR2GRAY);
	cvtColor(src2, src2, COLOR_BGR2GRAY);
	threshold(src1, src1, 100, 255, THRESH_BINARY);
    threshold(src2, src2, 100, 255, THRESH_BINARY);
	Canny(src1, src1, 50, 120);
	Canny(src2, src2, 50, 120);
	vector<vector<Point>>contours1, contours2;
	vector<Vec4i>hierarchy1, hierarchy2;
	findContours(src1, contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE);
	findContours(src2, contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_SIMPLE);
	double result=matchShapes(contours1[0],contours2[0],CV_CONTOURS_MATCH_I1,0);
	cout<<result<<endl;
	system("pause");
	return 0;
}
