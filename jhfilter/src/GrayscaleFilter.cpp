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
int GrayscaleFilter::filterRGB(int rgb)
{
	int a = rgb & 0xff000000;
	int r = (rgb >> 16) & 0xff;
	int g = (rgb >> 8) & 0xff;
	int b = rgb & 0xff;
//		rgb = (r + g + b) / 3;	// simple average
	rgb = (r * 77 + g * 151 + b * 28) >> 8;	// NTSC luma
	return a | (rgb << 16) | (rgb << 8) | rgb;
}
int * GrayscaleFilter::filter(int * src, int width, int height)
{
	return PointFilter::filter(src, width, height);
}
