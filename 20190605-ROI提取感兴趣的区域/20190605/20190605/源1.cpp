#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Rect g_rect;
bool g_DrawFlag = false;
RNG g_rng(12345);
//矩形绘制函数
void on_MouseHandle(int event, int x, int y, int flag, void* param);
void MouseEvent();
void DrawRectangle(Mat& img, Rect box);
int main()
{
	MouseEvent();
	waitKey(0);
	return 0;
}
void MouseEvent()
{
	//准备参数
	g_rect = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 600, CV_8UC3,Scalar::all(0)), tempImage;
	srcImage.copyTo(tempImage);	
	//设置鼠标操作回调函数
	namedWindow("Win");
	setMouseCallback("Win", on_MouseHandle, (void*)&srcImage);
	//绘画
	while (1)
	{
		srcImage.copyTo(tempImage);
		if (g_DrawFlag) 	DrawRectangle(tempImage, g_rect);
		imshow("Win", tempImage);
		if (waitKey(10) == 27) break;//ESC 退出
	}
}
//鼠标回调事件
void on_MouseHandle(int event, int x, int y, int flag, void* param)
{
	Mat& image = *(Mat*)param;
	switch (event)
	{
	case EVENT_LBUTTONDOWN://左键按下
		g_DrawFlag = true;		
		g_rect = Rect(x, y, 0, 0);//设置g_rect的初始值在同一个点
	break; 

	case EVENT_MOUSEMOVE://移动
		if (g_DrawFlag) {
			//计算，g_rect宽高=鼠标当前位置坐标-g_rect左上角的坐标
			g_rect.width = x - g_rect.x;
			g_rect.height = y - g_rect.y;
		}
		break;
	
	case EVENT_LBUTTONUP://左键抬起
		g_DrawFlag = false;
		//当g_rect宽高小于0,起始点xy坐标置为较小靠左上角的点,宽高取绝对值
		if (g_rect.width < 0) {
			g_rect.x += g_rect.width;
			g_rect.width *= -1;		
		}
		if (g_rect.height < 0) {
			g_rect.y += g_rect.height;
			g_rect.height *= -1;
		}
		//画矩形
		DrawRectangle(image, g_rect);
		break;
	}
}
void DrawRectangle(Mat& img, Rect box)
{
	//rectangle画矩形,tl左上角的点，br右下角的点,Scalar设置颜色，设置为3通道,g_rng.uniform(0, 255)随机颜色
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}
