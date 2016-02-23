#pragma once
#include "BaseFilter.h"
class PointFilter :
	public BaseFilter
{
public:
	PointFilter();
	virtual ~PointFilter();

protected:
	int * filter(int * src, int width, int height);
	virtual int filterRGB(int rgb) = 0;
	bool canFilterIndexColorModel;

};

