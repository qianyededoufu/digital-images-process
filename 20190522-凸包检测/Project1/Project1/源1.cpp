#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
 
int main()
{
     Mat  img_01 = Mat(400, 400, CV_8UC3,Scalar(0));
     Mat  img_02 =  Mat(400, 400, CV_8UC3,Scalar(0));
      // ��������ɵ�����
    vector<Point> points_01,points_02;
      // �������鸳ֵ
    points_01.push_back(Point(10, 10));
	points_01.push_back(Point(10,390));
    points_01.push_back(Point(390, 390));
	points_01.push_back(Point(150, 250));

    points_02.push_back(Point(10, 10));
	points_02.push_back(Point(10,390));
    points_02.push_back(Point(390, 390));
	points_02.push_back(Point(250, 150));
 
    vector<int> hull_01,hull_02;
    // ����͹��
    convexHull(points_01, hull_01, true);
    convexHull(points_02, hull_02, true);
     // ��������
    for(int i=0;i < 4;++i)
    {
        circle(img_01, points_01[i], 3, Scalar(0,255,255),FILLED, LINE_AA);
        circle(img_02, points_02[i], 3, Scalar(0,255,255), FILLED, LINE_AA);
    }
    // ����͹������
     Point point1= points_01[hull_01[hull_01.size()-1]];
    for(int i=0;i < hull_01.size();++i)
    {
        line( img_01, point1, points_01[i], Scalar(255,255,0), 1, CV_AA);
        point1 = points_01[i];
    }

     Point point2 = points_02[hull_02[hull_02.size()-1]];
    for(int i=0;i < hull_02.size();++i)
    {
        line(img_02, point2, points_02[i], Scalar(255,255,0), 1, CV_AA);
        point2 = points_02[i];
    }
        // �����͹ȱ�ݾͰ���������
    if( isContourConvex(points_01) )// ���������͹��һ�����������Ϣ�� img_01��������͹��
    {
        cout<<"img_01��������͹��"<<endl;
    }
	else
	{
        cout<<"img_01����������͹��"<<endl;
		  vector<Vec4i> defects;
        convexityDefects(points_01,  Mat(hull_01), defects  );
        // ����ȱ��
        cout<<"��"<<defects.size()<<"��ȱ��"<<endl;
        for(int i=0;i < defects.size();++i)
        {
            circle(img_01, points_01[defects[i][0]], 6, Scalar(255,0,0), 2, CV_AA);
            circle(img_01, points_01[defects[i][1]], 6, Scalar(255,0,0), 2, CV_AA);
            circle(img_01, points_01[defects[i][2]], 6, Scalar(255,0,0), 2, CV_AA);
            line(img_01, points_01[defects[i][0]], points_01[defects[i][1]], Scalar(255,0,0), 1, CV_AA);
            line(img_01, points_01[defects[i][1]], points_01[defects[i][2]], Scalar(255,0,0), 1, CV_AA);
line(img_01, points_01[defects[i][2]], points_01[defects[i][0]], Scalar(255,0,0), 1, CV_AA);
cout<<"��"<<i<<"ȱ��<"<<points_01[defects[i][0]].x<<","<<points_01[defects[i][0]].y
                <<">,<"<<points_01[defects[i][1]].x<<","<<points_01[defects[i][1]].y
                <<">,<"<<points_01[defects[i][2]].x<<","<<points_01[defects[i][2]].y<<">�������ľ���Ϊ��"<<defects[i][3]/256<<"px"<<endl;
        }
        defects.clear();
    }
    if( isContourConvex( points_02 ) )
    {
        cout<<"img_02��������͹��"<<endl;
    }else
	{
        cout<<"img_02����������͹��"<<endl;
        vector<Vec4i> defects;
        convexityDefects (points_02, Mat(hull_01),   defects  );
        // ���Ƴ�ȱ�ݵ�����
        for(int i=0;i < defects.size();++i)
        {
            circle(img_02, points_01[defects[i][0]], 6, Scalar(255,0,0), 2, CV_AA);
            circle(img_02, points_01[defects[i][1]], 6, Scalar(255,0,0), 2, CV_AA);
            circle(img_02, points_01[defects[i][2]], 6, Scalar(255,0,0), 2, CV_AA);
            line(img_02, points_01[defects[i][0]], points_01[defects[i][1]], Scalar(255,0,0), 1, CV_AA);
            line(img_02, points_01[defects[i][1]], points_01[defects[i][2]], Scalar(255,0,0), 1, CV_AA);
            line(img_02, points_01[defects[i][2]], points_01[defects[i][0]], Scalar(255,0,0), 1, CV_AA);
            // ��Ϊ img_02 û��ȱ�����Ծ�û��д��Щ���������
        }
        defects.clear();
    }
 
    imshow("img_01 ��������͹����", img_01);
    imshow("img_02 ��������͹����", img_02);
    waitKey(0);     
    return 0;
}
