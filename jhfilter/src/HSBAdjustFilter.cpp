/*
 * HSBAdjustFilter.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: my
 */

#include "HSBAdjustFilter.h"

HSBAdjustFilter::HSBAdjustFilter() {
	this->hFactor = 0.0f;
	this->sFactor = 0.0f;
	this->bFactor = 0.0f;
}
HSBAdjustFilter::HSBAdjustFilter(float r, float g, float b) {
	this->hFactor = r;
	this->sFactor = g;
	this->bFactor = b;
	this->canFilterIndexColorModel = true;
}
HSBAdjustFilter::~HSBAdjustFilter() {
	// TODO Auto-generated destructor stub
}

float HSBAdjustFilter::getBFactor() const {
	return bFactor;
}

void HSBAdjustFilter::setBFactor(float factor) {
	bFactor = factor;
}

float HSBAdjustFilter::getHFactor() const {
	return hFactor;
}

void HSBAdjustFilter::setHFactor(float factor) {
	hFactor = factor;
}

float HSBAdjustFilter::getSFactor() const {
	return sFactor;
}

void HSBAdjustFilter::setSFactor(float factor) {
	sFactor = factor;
}
int HSBAdjustFilter::filterBGR(int rgb)
{
//	cv::Vec3f hsv = ColorUtils::BGR2HSV(pixel);
//
//	hsv[0] += hFactor;
//	while(hsv[0] < 0)
//	{
//		hsv[0] += PI*2;
//	}
//
//	hsv[1] += sFactor;
//	hsv[1] = hsv[1] < 0 ? 0.0f : (hsv[1] > 1.0f ? 1.0f : hsv[1]);
//
//	hsv[2] += bFactor;
//	hsv[2] = hsv[2] < 0 ? 0.0f : (hsv[2] > 1.0f ? 1.0f : hsv[2]);
//
//	return ColorUtils::HSV2BGR(hsv);
	return 0;
}
int * HSBAdjustFilter::filter(int * src, int width, int height)
{
	return PointFilter::filter(src, width, height);
}

