#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int thresh = 80;
Mat src, srcgray,edge;
void onchange(int, void *);
RNG rng(1234);
int mai()
{
	src = imread("e:\\ju.png", 1);
if (!src.data)
	{
		cout << "图像加载失败...";
		return -1;
	}
	else
	cout << "图像加载成功..." << endl;
	imshow("原图", src);
	cvtColor(src, srcgray, COLOR_BGR2GRAY);
	GaussianBlur(srcgray, srcgray, Size(3, 3), 0);
	createTrackbar("thresh", "原图", &thresh, 255, onchange);
	onchange(0, 0);
	waitKey(0);
	return 0;
}
void onchange(int, void *)
{
	Canny(src, edge, thresh, thresh * 2, 3);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(edge, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	Mat drawingImage = Mat::zeros(edge.size(), CV_8UC3);
	src.copyTo(drawingImage);
    vector<Moments>mu(contours.size());
	for(int i=0;i<contours.size();i++){
		mu[i]=moments(contours[i],false);//计算图形的矩
	}
	vector<Point2f>mc(contours.size());
	for(int i=0;i<contours.size();i++){
		mc[i]=Point2f(mu[i].m10/mu[i].m00,mu[i].m01/mu[i].m00);
		Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		circle(drawingImage,mc[i],4,color,-1,8,0);
		cout << "通过contourArea计算轮廓面积" << contourArea(contours[i]) << endl;
		cout << "通过m00计算面积" << mu[i].m00 << endl;
		cout << "计算周长"<<arcLength(contours[i], true) << endl;

	}
	imshow("drawingImage", drawingImage);
}
