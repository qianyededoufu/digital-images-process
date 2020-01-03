#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;

int Otsu(Mat matSrc);

int main()
 {
	Mat src=imread("e:\\bike.jpg",1);
	Mat srcgray;
	Mat dst(srcgray.rows,srcgray.cols,CV_8UC1);	
	int zuijia;
	int maxValue=255;
	if (!src.data) { cout << "error" << endl; return -1; }
	imshow("src",src);
	cvtColor(src,srcgray,COLOR_RGB2GRAY);
	zuijia=Otsu(srcgray);
	threshold(srcgray,dst,zuijia,maxValue,THRESH_BINARY);
	imshow("THRESH_BINARY", dst);
	waitKey(0);
	system("pause");
	return 0;
}

int Otsu(Mat matSrc)
{
	if (CV_8UC1 != matSrc.type())
		return -1;
	int nCols = matSrc.cols;
	int nRows = matSrc.rows;
	int nPixelNum = nCols * nRows;
	// 初始化
	int pixelNum[256];
	double probability[256];
	for (int i = 0; i < 256; i++)
	{
		pixelNum[i] = 0;
		probability[i] = 0.0;
	}
	// 统计像素数和频率
	for (int j = 0; j < nRows; j++)
	{
		for (int i = 0; i < nCols; i++)
		{
			pixelNum[matSrc.at<uchar>(j, i)]++;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		probability[i] = (double)0.1*pixelNum[i] / nPixelNum;
	}
	// 计算
	int nThreshold = 0;          // 最佳阈值
	double dMaxDelta = 0.0;      // 最大类间方差
	double dMean_0 = 0.0;        // 左边平均值
	double dMean_1 = 0.0;        // 右边平均值
	double dDelta = 0.0;         // 类间方差
	double dMean_0_temp = 0.0;   // 左边平均值中间值
	double dMean_1_temp = 0.0;   // 右边平均值中间值
	double dProbability_0 = 0.0;       // 左边频率值
	double dProbability_1 = 0.0;       // 右边频率值
	for (int j = 0; j < 256; j++)
	{
		for (int i = 0; i < 256; i++)
		{
			if (i < j)// 前半部分
			{
				dProbability_0 += probability[i];
				dMean_0_temp += i * probability[i];
			}
			else      // 后半部分
			{
				dProbability_1 += probability[i];
				dMean_1_temp += i * probability[i];
			}
		}
		// 计算平均值
		// fMean_0_teamp计算的是前半部分的灰度值的总和除以总像素数，
		// 所以要除以前半部分的频率才是前半部分的平均值，后半部分同样
		dMean_0 = dMean_0_temp / dProbability_0;
		dMean_1 = dMean_1_temp / dProbability_1;
		dDelta = (double)(dProbability_0 * dProbability_1 * pow((dMean_0 - dMean_1), 2));
		if (dDelta > dMaxDelta)
		{
			dMaxDelta = dDelta;
			nThreshold = j;
		}
		// 相关参数归零
		dProbability_0 = 0.0;
		dProbability_1 = 0.0;
		dMean_0_temp = 0.0;
		dMean_1_temp = 0.0;
		dMean_0 = 0.0;
		dMean_1 = 0.0;
		dDelta = 0.0;
	}
	return nThreshold;
}
