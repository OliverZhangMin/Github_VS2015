// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img1 = imread("F:\\src1.png");
	Mat img2 = imread("F:\\src2.png");

	// 1. ��ʼ��
	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	Ptr<ORB> orb = ORB::create();

	// 2. ��ȡ������
	orb->detect(img1, keypoints1);
	orb->detect(img2, keypoints2);

	// 3. ��������������
	orb->compute(img1, keypoints1, descriptors1);
	orb->compute(img2, keypoints2, descriptors2);

	// 4. ������ͼ���BRIEF����������ƥ�䣬ʹ��BFMatch��Hamming������Ϊ�ο�
	vector<DMatch> matches;
	BFMatcher bfMatcher(NORM_HAMMING);
	bfMatcher.match(descriptors1, descriptors2, matches);
	for (const auto& it : matches)
	{
		cout << "it.imgIdx : " << it.imgIdx << endl;
	}

    return 0;
}

