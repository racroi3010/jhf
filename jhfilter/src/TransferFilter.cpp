
#include "TransferFilter.h"


TransferFilter::TransferFilter()
{
	initialized = false;

}


TransferFilter::~TransferFilter()
{
	delete [] rTable;
	delete [] gTable;
	delete [] bTable;
}

int TransferFilter::filterRGB(int rgb)
{
	int a = rgb & 0xff000000;
	int r = (rgb >> 16) & 0xff;
	int g = (rgb >> 8) & 0xff;
	int b = rgb & 0xff;
	r = rTable[r];
	g = gTable[g];
	b = bTable[b];
	return a | (r << 16) | (g << 8) | b;
}
int * TransferFilter::filter(int * src, int width, int height)
{
	if(!initialized)
	{
		initialize();
	}
	return PointFilter::filter(src, width, height);
}
void TransferFilter::initialize()
{
	initialized = true;
	rTable = gTable = bTable = makeTable();
}
int * TransferFilter::makeTable()
{
	int * table = new int[256];
	for(int i = 0; i < 256; i ++)
	{
		table[i] = PixelUtils::clamp((int)( 255 * transferFunction(i/255.0f)));
	}
	return table;
}
