#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int findRect()
{
	//1.��������ʱ��һ��ʹ�ö�ֵ��ͼ�񣬽�����ֵ���������Canny��Ե���
	Mat srcImg   = imread("e:\\aodi.jpg", 1);
	imshow("srcImg", srcImg);
	Mat copyImg = srcImg.clone();//��ԭͼ�񱸷ݣ�����������ı�ԭͼ��
cvtColor(srcImg, srcImg, COLOR_BGR2GRAY);//ת���ɻҶ�ͼ����ֵ����Ҫͼ���Ҷ�ͼ��
   threshold(srcImg, srcImg, 100, 255, THRESH_BINARY_INV); //��ֵ������֤��ɫ������ɫ����
	imshow("threshold", srcImg);
	//������������������
	vector<vector<Point>> contours;//��ż�⵽������,ÿ���������ɵ����
	vector<Vec4i> hierarchy;
	findContours(srcImg, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
	//����ÿ�������е�ÿ���㣬������ԭͼ��
	// drawContours(copyImg, contours, -1, Scalar(0, 255, 0), 1);
	for (int i = 0; i < contours.size(); i++)//����ÿ������
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
