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
#include "CurvesFilter.h"
#include "HSBAdjustFilter.h"
#include "ContrastFilter.h"
#include "LevelsFilter.h"
#include "GrayscaleFilter.h"

int * convertMat2RGBArray(cv::Mat image)
{
	int width = image.cols;
	int height = image.rows;

	int * rgbArrays = new int[width * height];
	int x, y, i, r, g, b;
	for(y = 0; y < height; y ++)
		for(x = 0; x < width; x ++)
		{
			i = y * width + x;
			b = image.data[image.channels() * i ];
			g = image.data[image.channels() * i + 1];
			r = image.data[image.channels() * i + 2];
			rgbArrays[i] = r << 16 | g << 8 | b;
		}
	return rgbArrays;
}
cv::Mat convertRGBArray2Mat(int * src, int width, int height)
{
	cv::Mat out(height, width, CV_8UC3);
	int x, y, i, rgb;
	for(y = 0; y < height; y ++)
		for(x = 0; x < width; x ++)
		{
			i = y * width + x;
			rgb = src[i];
			out.at<cv::Vec3b>(y, x)[0] = rgb & 0xff;
			out.at<cv::Vec3b>(y, x)[1] = (rgb >> 8) & 0xff;
			out.at<cv::Vec3b>(y, x)[2] = (rgb >> 16) & 0xff;

		}
	delete [] src;
	return out;
}
void nativeCurvesFilter(int * src, int width, int height)
{
	CurvesFilter curvesFilter;
	Curve curves[3];

	Curve r;
	Curve g;
	Curve b;

	int length = 13;
	float * y = new float[length]{26.0f, 43.0f, 64.0f, 114.0f, 148.0f, 177.0f, 193.0f, 202.0f, 208.0f, 218.0f, 229.0f, 241.0f, 251.0f};
	float * x = new float[length]{0.0f, 15.0f, 32.0f, 65.0f, 83.0f, 109.0f, 127.0f, 146.0f, 170.0f, 195.0f, 215.0f, 234.0f, 255.0f };
	r.y = y;
	r.x = x;
	r.length = length;
    for(int i = 0 ;i<length;i++) {
        r.x[i] = (r.x[i]*100)/255/100;
        r.y[i] = (r.y[i]*100)/255/100;
    }

	y = new float[length]{0.0f, 32.0f, 72.0f, 123.0f, 147.0f, 188.0f, 205.0f, 210.0f, 222.0f, 224.0f, 235.0f, 246.0f, 255.0f };
	x = new float[length]{0.0f, 26.0f, 49.0f, 72.0f, 89.0f, 115.0f, 147.0f, 160.0f, 177.0f, 189.0f, 215.0f, 234.0f,255.0f};
	g.y = y;
	g.x = x;
	g.length = length;
    for(int i = 0 ;i<length;i++) {
        g.x[i] = (g.x[i]*100)/255/100;
        g.y[i] = (g.y[i]*100)/255/100;
    }

	y = new float[length]{29.0f, 72.0f, 124.0f, 147.0f, 162.0f, 175.0f, 184.0f, 189.0f, 195.0f, 203.0f, 216.0f, 237.0f, 247.0f};
	x = new float[length]{1.0f, 30.0f, 57.0f, 74.0f, 87.0f, 108.0f, 130.0f, 152.0f, 172.0f, 187.0f, 215.0f, 239.0f, 255.0f};
	b.y = y;
	b.x = x;
	b.length = length;
    for(int i = 0 ;i<length;i++) {
        b.x[i] = (b.x[i]*100)/255/100;
        b.y[i] = (b.y[i]*100)/255/100;
    }

    curves[0] = r;
    curves[1] = g;
    curves[2] = b;

    curvesFilter.setCurves(&curves[0], 3);


   	int * out = curvesFilter.filter(src, width, height);



    cv::imshow("", convertRGBArray2Mat(out, width, height));

    delete [] x;
    delete [] y;
}

//void nativeHSBAdjustFilter(cv::Mat image)
//{
//	HSBAdjustFilter filter;
//	filter.setSFactor(-0.03f);
//	filter.setBFactor(0.01f);
//
//	cv::Mat out = filter.filter(image);
//
//	cv::imshow("", out);
//}
//void nativeContrastFilter(cv::Mat image)
//{
//	ContrastFilter filter;
//	filter.setBrightness(1.2f);
//	filter.setContrast(1.1f);
//
//	cv::Mat out = filter.filter(image);
//
//	cv::imshow("", out);
//}
//void nativeLevelsFilter(cv::Mat image)
//{
//	LevelsFilter filter;
//	float highLevelValue = (237 * 100 / 255) * 100 / 100;
//
//	filter.setHighLevel(highLevelValue/50.0f);
//	filter.setLowLevel(0.1f);
//
//	cv::Mat out = filter.filter(image);
//
//	cv::imshow("", out);
//}
//void nativeGrayscaleFilter(cv::Mat image)
//{
//	GrayscaleFilter filter;
//
//	cv::Mat out = filter.filter(image);
//
//	cv::imshow("", out);
//}

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	//getchar();
	cv::Mat img = cv::imread("D:/iu_filter.jpg");

	int * src = convertMat2RGBArray(img);

	nativeCurvesFilter(src, img.cols, img.rows);
	//nativeHSBAdjustFilter(img);
	//nativeContrastFilter(img);
	//nativeLevelsFilter(img);
	//nativeGrayscaleFilter(img);


	//cv::Mat img = cv::Mat::zeros(256, 256, CV_8UC3);
	cv::imshow("org", img);
	while(1)
	{
		if(cv::waitKey(10) == 27) break;
	}

	return 0;
}
