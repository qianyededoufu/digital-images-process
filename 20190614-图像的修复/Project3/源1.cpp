#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/******���Ȧ��������ֵ����+Mask���ʹ���*******/

Point ptL, ptR; //��껭�����ο�������յ�
Mat imageSource, imageSourceCopy;
Mat ROI; //ԭͼ��Ҫ�޸������ROI
void OnMouse(int event, int x, int y, int flag, void *ustg); //���ص�����
int main2()
{
	imageSource = imread("e:\\xiake.jpg");
	if (!imageSource.data)
	{
		return -1;
	}
	imshow("ԭͼ", imageSource);
	setMouseCallback("ԭͼ", OnMouse);
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
		imshow("ԭͼ", imageSourceCopy);
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
	//��������Ҽ���ʼͼ���޸�
	if (event == EVENT_RBUTTONDOWN)
	{
		imageSourceCopy = ROI.clone();
		Mat imageGray;
		cvtColor(ROI, imageGray, COLOR_RGB2GRAY); //ת��Ϊ�Ҷ�ͼ
		Mat imageMask = Mat(ROI.size(), CV_8UC1, Scalar::all(0));

		//ͨ����ֵ��������Mask
		threshold(imageGray, imageMask, 235, 255, THRESH_BINARY);
		Mat Kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imageMask, imageMask, Kernel);  //��Mask���ʹ���
		inpaint(ROI, imageMask, ROI, 9, INPAINT_TELEA);  //ͼ���޸�
		imshow("Mask", imageMask);
		imshow("�޸���", imageSource);
	}
}
