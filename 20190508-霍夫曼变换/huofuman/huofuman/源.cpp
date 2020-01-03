#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat  src = imread("e:\\houghhouse.png", 1);
	Mat srcgray, edge;
	if (!src.data) { cout << "error" << endl; return -1; }
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(src, srcgray, COLOR_RGB2GRAY);
	imshow("src", src);
	Canny(srcgray,edge,50,150,3);
	vector<Vec2f> lines;
	HoughLines(edge,lines,1,CV_PI/180,10000);
	for(size_t i=0;i<lines.size();i++){
		double rho=lines[i][0],theta=lines[i][0];
		double x=rho*cos(theta),y=rho*sin(theta);
		Point p1,p2;
		p1.x=cvRound(x-1000*sin(theta)); //cvRound方法用于取整
		p1.y=cvRound(y+1000*cos(theta));
		p2.x=cvRound(x+1000*sin(theta));
		p2.y=cvRound(y-1000*cos(theta));
		line(edge,p1,p2,Scalar(255,0,0));
	}
	imshow("houghLine",edge);
	waitKey(0);
	return 0;
}
