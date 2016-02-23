
#include "PointFilter.h"
PointFilter::PointFilter()
{
	canFilterIndexColorModel = false;
}


PointFilter::~PointFilter()
{
}

int * PointFilter::filter(int * src, int width, int height)
{
	int x, y, i;

	int * out = new int[width * height];

	for(y = 0; y < height; y ++)
		for(x = 0; x < width; x ++)
		{
			i = y * width + x;
			out[i] = filterRGB(src[i]);
		}

	return out;

}
