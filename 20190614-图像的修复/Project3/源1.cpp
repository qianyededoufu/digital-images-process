#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/******鼠标圈定区域阈值处理+Mask膨胀处理*******/

Point ptL, ptR; //鼠标画出矩形框的起点和终点
Mat imageSource, imageSourceCopy;
Mat ROI; //原图需要修复区域的ROI
void OnMouse(int event, int x, int y, int flag, void *ustg); //鼠标回调函数
int main2()
{
	imageSource = imread("e:\\xiake.jpg");
	if (!imageSource.data)
	{
		return -1;
	}
	imshow("原图", imageSource);
	setMouseCallback("原图", OnMouse);
	waitKey();
}
void OnMouse(int event, int x, int y, int flag, void *ustg)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		ptL = Point(x, y);
		ptR = Point(x, y);
	}
	if (flag == EVENT_FLAG_LBUTTON)
	{
		ptR = Point(x, y);     
		imageSourceCopy = imageSource.clone();
		rectangle(imageSourceCopy, ptL, ptR, Scalar(255, 0, 0));
		imshow("原图", imageSourceCopy);
	}
	if (event == EVENT_LBUTTONUP)
	{
		if (ptL != ptR)
		{
			ROI = imageSource(Rect(ptL, ptR));
			imshow("ROI", ROI);
			waitKey();
		}
	}
	//单击鼠标右键开始图像修复
	if (event == EVENT_RBUTTONDOWN)
	{
		imageSourceCopy = ROI.clone();
		Mat imageGray;
		cvtColor(ROI, imageGray, COLOR_RGB2GRAY); //转换为灰度图
		Mat imageMask = Mat(ROI.size(), CV_8UC1, Scalar::all(0));

		//通过阈值处理生成Mask
		threshold(imageGray, imageMask, 235, 255, THRESH_BINARY);
		Mat Kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imageMask, imageMask, Kernel);  //对Mask膨胀处理
		inpaint(ROI, imageMask, ROI, 9, INPAINT_TELEA);  //图像修复
		imshow("Mask", imageMask);
		imshow("修复后", imageSource);
	}
}
