#include <iostream> 
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv; 
void diffOperation(Mat srcImage,Mat&edgeXImage,Mat &edgeYImage);
int chafen()
{
	Mat src = imread("e:\\shuiguo.png",1);
	imshow("src", src);
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(src,src,COLOR_BGR2GRAY);
	Mat edgeX(src.size(), src.type());
	Mat edgeY(src.size(), src.type());
	Mat edge(src.size(), src.type());
	diffOperation(src, edgeX, edgeY);
	imshow("edgeX", edgeX);
	imshow("edgeY", edgeY);
	addWeighted(edgeX, 0.5, edgeY, 0.5, 0, edge);
	imshow("edge", edge);
	waitKey(0);
	return 0;
}
void diffOperation(Mat srcImage, Mat&edgeXImage, Mat &edgeYImage)
{
	Mat temp = srcImage.clone();
	for (int i = 0; i < temp.rows-1; i++)
	{
		for (int j = 0; j < temp.cols-1; j++)
		{
			//计算垂直边缘
			edgeXImage.at<uchar>(i, j) = abs(temp.at<uchar>(i + 1, j) - temp.at<uchar>(i, j));
			//计算水平边缘
			edgeYImage.at<uchar>(i, j) = abs(temp.at<uchar>(i , j+ 1) - temp.at<uchar>(i, j));
		}
	}
}
