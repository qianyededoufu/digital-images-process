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
	char filename[50];
	cin>>filename;
	src = imread(filename, 1);//src = imread("e:\\xuanzhuang.png", 1);
	imshow("src", src);
	cvtColor(src, src, COLOR_BGR2GRAY);
	GaussianBlur(src, src, Size(3, 3), 0);
	namedWindow("contoursImage",0);
	createTrackbar("thresh", "contoursImage", &thresh, 255, onchange_thresh);
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
	Mat contoursImage(edge.rows,edge.cols,CV_8UC3,Scalar(0,0,0));
	for (int i = 0; i<contours.size(); i++)
	{
	 	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));//任意值
	 	//drawContours(contoursImage, contours, i, color);
		RotatedRect rect = minAreaRect(contours[i]);
		Point2f vertices[4];
		rect.points(vertices);
		for (int i = 0; i < 4; i++)
		{
			line(contoursImage, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 2, LINE_AA);
		}
	}	
	imshow("contoursImage", contoursImage);
}
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
	char filename[50];
	cin>>filename;
	src = imread(filename, 1);//src = imread("e:\\xuanzhuang.png", 1);
	imshow("src", src);
	cvtColor(src, src, COLOR_BGR2GRAY);
	GaussianBlur(src, src, Size(3, 3), 0);
	namedWindow("contoursImage",0);
	createTrackbar("thresh", "contoursImage", &thresh, 255, onchange_thresh);
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
	Mat contoursImage(edge.rows,edge.cols,CV_8UC3,Scalar(0,0,0));
	for (int i = 0; i<contours.size(); i++)
	{
	 	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));//任意值
	 	//drawContours(contoursImage, contours, i, color);
		RotatedRect rect = minAreaRect(contours[i]);
		Point2f vertices[4];
		rect.points(vertices);
		for (int i = 0; i < 4; i++)
		{
			line(contoursImage, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 2, LINE_AA);
		}
	}	
	imshow("contoursImage", contoursImage);
}
Mat convertTo3Channels(const Mat& binImg)
{
    Mat three_channel = Mat::zeros(binImg.rows,binImg.cols,CV_8UC3);
    vector<Mat> channels;
    for (int i=0;i<3;i++)
    {
        channels.push_back(binImg);
    }
    merge(channels,three_channel);
    return three_channel;
}
