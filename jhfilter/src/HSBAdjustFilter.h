/*
 * HSBAdjustFilter.h
 *
 *  Created on: Feb 19, 2016
 *      Author: my
 */

#ifndef HSBADJUSTFILTER_H_
#define HSBADJUSTFILTER_H_

#include "PointFilter.h"
#include "ColorUtils.h"

#define PI 3.141592653589793

class HSBAdjustFilter: public PointFilter {
public:
	HSBAdjustFilter();
	HSBAdjustFilter(float r, float g, float b);
	virtual ~HSBAdjustFilter();
	float getHFactor() const;
	void setHFactor(float factor);
	float getSFactor() const;
	void setSFactor(float factor);
	float getBFactor() const;
	void setBFactor(float factor);

	int filterBGR(int pixel);
	int * filter(int * src, int width, int height);
private:
	float hFactor;
	float sFactor;
	float bFactor;
	float hsb[3];
};

#endif /* HSBADJUSTFILTER_H_ */
