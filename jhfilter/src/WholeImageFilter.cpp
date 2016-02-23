/*
 * WholeImageFilter.cpp
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#include "WholeImageFilter.h"

WholeImageFilter::WholeImageFilter() {
	// TODO Auto-generated constructor stub

}

WholeImageFilter::~WholeImageFilter() {
	// TODO Auto-generated destructor stub
}
int * WholeImageFilter::filter(int * src, int width, int height)
{
	originalSpace = new Rect(0, 0, width, height);
	transformedSpace = new Rect(0, 0, width, height);

	transformRect(*transformedSpace);

	return filterPixels(src, width, height, *transformedSpace);
}
