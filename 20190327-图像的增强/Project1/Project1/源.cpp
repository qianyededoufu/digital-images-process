#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int imgHist(){
	Mat src=imread("e://add2.jpg",1);
	imshow("before",src);
	vector<Mat> channel; // vector<��������> �������� vector<Mat> channel;�� Mat channel[3]���ý�Ϊ���� ��������Ϊ���̶���С
	// channel[0]; �ȼ��� channel.at(0);
	split(src,channel);//����ͨ����ɫͼƬ�ֽ�Ϊ����������ͨ����Ϣ channel[0] channel[1] channel[2]
	imshow("before blue",channel[0]);
	imshow("before green",channel[1]);
	imshow("before red",channel[2]);

	/***
	Mat dst;
	cvtColor(src,dst,COLOR_BGR2GRAY);
	imshow("dst",dst);         ��Ŀ��ͼ��ת��Ϊ��ͨ���Ҷ�ͼ��

	Mat dstHist;
	equalizeHist(dst,dstHist);
	imshow("dstHist",dstHist);  //����ͨ���Ҷ�ͼ��ֱ��ͼ���⻯
	**/
	equalizeHist(channel[0],channel[0]);
	equalizeHist(channel[1],channel[1]);
	equalizeHist(channel[2],channel[2]);
	imshow("after blue",channel[0]);
	imshow("after green",channel[1]);
	imshow("after red",channel[2]);

	Mat dstHist;
	//merge(channel,3,dstHist);   //�ϲ�����ͨ����Ŀ��ͼ��洢��dstHist
	merge(channel,dstHist); //ʹ����������ֻ��Ҫ��������
	imshow("dstHist",dstHist);

	waitKey(0);
	system("pause");
	return 0;
}