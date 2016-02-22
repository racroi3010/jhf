/*
 * GrayscaleFilter.cpp
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#include "GrayscaleFilter.h"

GrayscaleFilter::GrayscaleFilter() {
	// TODO Auto-generated constructor stub

}

GrayscaleFilter::~GrayscaleFilter() {
	// TODO Auto-generated destructor stub
}
cv::Vec3b GrayscaleFilter::filterBGR(cv::Vec3b pixel)
{
//	int rgb = (pixel[2] * 77 + pixel[1] * 151 + pixel[0] * 28) >> 8;	// NTSC luma
//
//	int r = (rgb >> 16) & 0xff;
//	int g = (rgb >> 8) & 0xff;
//	int b = rgb & 0xff;

//	return cv::Vec3b(b, g, r);

	int gray = (pixel[0] + pixel[1] + pixel[2])/3;
	return cv::Vec3b(gray, gray, gray);
}
cv::Mat GrayscaleFilter::filter(cv::Mat image)
{
	return PointFilter::filter(image);
}
