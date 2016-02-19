//============================================================================
// Name        : jhfilter.cpp
// Author      : noidh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	//getchar();
	cv::Mat img = cv::imread("/home/my/Pictures/EL_CH.jpg");
	//cv::Mat img = cv::Mat::zeros(256, 256, CV_8UC3);
	cv::imshow("", img);
	while(1)
	{
		if(cv::waitKey(10) == 27) break;
	}

	return 0;
}
