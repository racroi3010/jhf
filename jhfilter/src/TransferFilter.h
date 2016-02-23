#pragma once
#include "PointFilter.h"
class TransferFilter :
	public PointFilter
{
public:
	TransferFilter();
	~TransferFilter();
	int * filter(int * src, int width, int height);
protected:
	int * rTable, * gTable, * bTable;
	bool initialized;

	int filterRGB(int rgb);


	void initialize();
	int * makeTable();
	virtual float transferFunction(float v) = 0;
};

