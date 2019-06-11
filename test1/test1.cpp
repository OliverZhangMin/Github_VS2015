// test1.cpp : 定义控制台应用程序的入口点。
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

	// 1. 初始化
	vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	Ptr<ORB> orb = ORB::create();

	// 2. 提取特征点
	orb->detect(img1, keypoints1);
	orb->detect(img2, keypoints2);

	// 3. 计算特征描述符
	orb->compute(img1, keypoints1, descriptors1);
	orb->compute(img2, keypoints2, descriptors2);

	// 4. 对两幅图像的BRIEF描述符进行匹配，使用BFMatch，Hamming距离作为参考
	vector<DMatch> matches;
	BFMatcher bfMatcher(NORM_HAMMING);
	bfMatcher.match(descriptors1, descriptors2, matches);
	for (const auto& it : matches)
	{
		cout << "it.imgIdx : " << it.imgIdx << endl;
	}

    return 0;
}

