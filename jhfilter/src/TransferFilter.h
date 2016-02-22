#pragma once
#include "PointFilter.h"
class TransferFilter :
	public PointFilter
{
public:
	TransferFilter();
	~TransferFilter();
	cv::Mat filter(cv::Mat image);
protected:
	int * rTable, * gTable, * bTable;
	bool initialized;

	cv::Vec3b filterBGR(cv::Vec3b pixel);


	void initialize();
	int * makeTable();
	virtual float transferFunction(float v) = 0;
};

