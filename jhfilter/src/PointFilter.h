#pragma once
#include "BaseFilter.h"
class PointFilter :
	public BaseFilter
{
public:
	PointFilter();
	virtual ~PointFilter();

protected:
	cv::Mat filter(cv::Mat image);
	virtual cv::Vec3b filterBGR(cv::Vec3b pixel) = 0;
	bool canFilterIndexColorModel;

};

