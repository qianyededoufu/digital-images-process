#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int findRect()
{
	//1.查找轮廓时，一般使用二值化图像，进行阈值化处理或者Canny边缘检测
	Mat srcImg   = imread("e:\\aodi.jpg", 1);
	imshow("srcImg", srcImg);
	Mat copyImg = srcImg.clone();//将原图像备份（查找轮廓会改变原图像）
cvtColor(srcImg, srcImg, COLOR_BGR2GRAY);//转换成灰度图（阈值化需要图像会灰度图）
   threshold(srcImg, srcImg, 100, 255, THRESH_BINARY_INV); //阈值化并保证黑色背景白色轮廓
	imshow("threshold", srcImg);
	//查找轮廓并绘制轮廓
	vector<vector<Point>> contours;//存放检测到的轮廓,每个轮廓均由点组成
	vector<Vec4i> hierarchy;
	findContours(srcImg, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
	//访问每个轮廓中的每个点，绘制在原图上
	// drawContours(copyImg, contours, -1, Scalar(0, 255, 0), 1);
	for (int i = 0; i < contours.size(); i++)//遍历每个轮廓
	{
		RotatedRect rect=minAreaRect(contours[i]);
		Point2f vertices[4];
		rect.points(vertices);
		for(int i=0;i<4;i++){
			line(copyImg,vertices[i],vertices[(i+1)%4],Scalar(255,0,0),2,LINE_AA);
		}
	}
	imshow("draw", copyImg);
	waitKey(0);
	return 0;
}
