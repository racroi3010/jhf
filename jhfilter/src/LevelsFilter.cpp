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
int * LevelsFilter::filter(int * src, int width, int height)
{
	return WholeImageFilter::filter(src, width, height);
}
int * LevelsFilter::filterPixels(int * src, int width, int height, Rect transformedSpace)
{
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
		lut = 0;
	}
	int x, y;
	int * out = new int[width * height];
	for(y = 0; y < height; y ++)
		for(x = 0; x < width; x ++)
		{
			i = y * width + x;
			out[i] = filterRGB(src[i]);

		}
	for(i = 0; i < 3; i ++){
		delete [] lut[i];
	}
	delete [] lut;

	return out;
}
int LevelsFilter::filterRGB(int rgb)
{
	if(lut)
	{
		int a = rgb & 0xff000000;
		int r = lut[0][(rgb >> 16) & 0xff];
		int g = lut[1][(rgb >> 8) & 0xff];
		int b = lut[2][rgb & 0xff];

		return a | (r << 16) | (g << 8) | b;
	}
	return rgb;

}
void LevelsFilter::transformRect(Rect rect)
{

}


