#pragma once
#include "BaseFilter.h"
class PointFilter :
	public BaseFilter
{
public:
	PointFilter(void);
	~PointFilter(void);

protected:
	cv::Mat filter(cv::Mat image);
	bool canFilterIndexColorModel;

};

