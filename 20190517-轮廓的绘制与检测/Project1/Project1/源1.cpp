#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int minRect()
{
	Mat srcImage(Size(600, 600), CV_8UC3, Scalar(0));
	RNG &rng = theRNG();
	char key;
	while (1)
	{
		key = waitKey(0);
		if (key == 27)	break;
		else srcImage = Scalar::all(0);
		//随机生成一些点,首先就是随机生成点的总数量
		int g_nPointCount = rng.uniform(3, 30);
		//接下来就是随机生成一些点的坐标
		vector<Point> points;
		for (int i = 0; i < g_nPointCount; i++)
		{
			Point midPoint;
			midPoint.x = rng.uniform(srcImage.cols / 4, srcImage.cols * 3 / 4);
			midPoint.y = rng.uniform(srcImage.rows / 4, srcImage.rows * 3 / 4);
			points.push_back(midPoint);
		}
		//显示刚刚随机生成的那些点
		for (int i = 0; i < g_nPointCount; i++)
		{
			circle(srcImage, points[i], 0, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 3);
		}

//补充   一个轮廓   最下旋转矩形   代码
		RotatedRect rect=minAreaRect(points);
		Point2f vertices[4];
		rect.points(vertices);
		for(int i=0;i<4;i++){
			line(srcImage,vertices[i],vertices[(i+1)%4],Scalar(255,0,0));
		}
	    imshow("【绘制结束后的图像】", srcImage);		
	}
	waitKey(0);
	return 0;
}
