#pragma once
#include "PixelUtils.h"
class BaseFilter
{
public:
	BaseFilter(void);
	~BaseFilter(void);
protected:
	virtual int* filter(int *, int, int) = 0;

};

