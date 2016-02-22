/*
 * LevelsFilter.cpp
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#include "LevelsFilter.h"

LevelsFilter::LevelsFilter() {
	lowLevel = 0;
	highLevel = 1;

	lowOutputLevel = 0;
	highOutputLevel = 1;
}

LevelsFilter::~LevelsFilter() {
	// TODO Auto-generated destructor stub
}

float LevelsFilter::getHighLevel() const {
	return highLevel;
}

void LevelsFilter::setHighLevel(float highLevel) {
	this->highLevel = highLevel;
}

float LevelsFilter::getHighOutputLevel() const {
	return highOutputLevel;
}

void LevelsFilter::setHighOutputLevel(float highOutputLevel) {
	this->highOutputLevel = highOutputLevel;
}

float LevelsFilter::getLowLevel() const {
	return lowLevel;
}

void LevelsFilter::setLowLevel(float lowLevel) {
	this->lowLevel = lowLevel;
}

float LevelsFilter::getLowOutputLevel() const {
	return lowOutputLevel;
}

void LevelsFilter::setLowOutputLevel(float lowOutputLevel) {
	this->lowOutputLevel = lowOutputLevel;
}
cv::Mat LevelsFilter::filter(cv::Mat image)
{
	return WholeImageFilter::filter(image);
}
cv::Mat LevelsFilter::filterPixels(cv::Mat image, cv::Rect transformedSpace)
{
	int width = image.cols;
	int height = image.rows;

	int i, j;
	if(width * height > 0){
		lut = new int*[3];
		for(i = 0; i < 3; i ++){
			lut[i] = new int[256];
		}
		float low = lowLevel * 256;
		float high = highLevel * 256;
		if(low == high)
		{
			high ++;
		}
		for(i = 0; i < 3; i ++)
			for(j = 0;j < 256; j ++)
			{
				lut[i][j] = PixelUtils::clamp((int)(255 * (lowOutputLevel + (highOutputLevel - lowOutputLevel) * (j - low)/(high - low))));
			}
	}
	else
	{
		lut = NULL;
	}
	int x, y;
	cv::Vec3b pixel, filteredPixel;
	cv::Vec3b* rowBGR = 0, * rowBGRout = 0;
	cv::Mat outImage = cv::Mat::zeros(image.size(), image.type());
	for(y = 0; y < height; y ++)
	{
		rowBGR = image.ptr<cv::Vec3b>(y);
		rowBGRout = outImage.ptr<cv::Vec3b>(y);
		for(x = 0; x < width; x ++)
		{
			pixel = rowBGR[x];

			filteredPixel = filterBGR(pixel);

			for(i = 0; i < 3; i ++)
			{
				rowBGRout[x][i] = filteredPixel[i];

			}
		}

	}
	for(i = 0; i < 3; i ++){
		delete [] lut[i];
	}
	delete [] lut;

	return outImage;
}
cv::Vec3b LevelsFilter::filterBGR(cv::Vec3b bgr)
{
	if(lut != NULL)
	{
		int r = lut[0][bgr[2]];
		int g = lut[0][bgr[1]];
		int b = lut[0][bgr[0]];
		return cv::Vec3b(b, g, r);
	}
	return bgr;

}
void LevelsFilter::transformRect(cv::Rect rect)
{

}


