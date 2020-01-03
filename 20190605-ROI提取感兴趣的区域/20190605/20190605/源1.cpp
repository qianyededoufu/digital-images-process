#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Rect g_rect;
bool g_DrawFlag = false;
RNG g_rng(12345);
//���λ��ƺ���
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
	//׼������
	g_rect = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 600, CV_8UC3,Scalar::all(0)), tempImage;
	srcImage.copyTo(tempImage);	
	//�����������ص�����
	namedWindow("Win");
	setMouseCallback("Win", on_MouseHandle, (void*)&srcImage);
	//�滭
	while (1)
	{
		srcImage.copyTo(tempImage);
		if (g_DrawFlag) 	DrawRectangle(tempImage, g_rect);
		imshow("Win", tempImage);
		if (waitKey(10) == 27) break;//ESC �˳�
	}
}
//���ص��¼�
void on_MouseHandle(int event, int x, int y, int flag, void* param)
{
	Mat& image = *(Mat*)param;
	switch (event)
	{
	case EVENT_LBUTTONDOWN://�������
		g_DrawFlag = true;		
		g_rect = Rect(x, y, 0, 0);//����g_rect�ĳ�ʼֵ��ͬһ����
	break; 

	case EVENT_MOUSEMOVE://�ƶ�
		if (g_DrawFlag) {
			//���㣬g_rect���=��굱ǰλ������-g_rect���Ͻǵ�����
			g_rect.width = x - g_rect.x;
			g_rect.height = y - g_rect.y;
		}
		break;
	
	case EVENT_LBUTTONUP://���̧��
		g_DrawFlag = false;
		//��g_rect���С��0,��ʼ��xy������Ϊ��С�����Ͻǵĵ�,���ȡ����ֵ
		if (g_rect.width < 0) {
			g_rect.x += g_rect.width;
			g_rect.width *= -1;		
		}
		if (g_rect.height < 0) {
			g_rect.y += g_rect.height;
			g_rect.height *= -1;
		}
		//������
		DrawRectangle(image, g_rect);
		break;
	}
}
void DrawRectangle(Mat& img, Rect box)
{
	//rectangle������,tl���Ͻǵĵ㣬br���½ǵĵ�,Scalar������ɫ������Ϊ3ͨ��,g_rng.uniform(0, 255)�����ɫ
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}
