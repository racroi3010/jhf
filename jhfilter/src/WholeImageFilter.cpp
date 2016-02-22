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
cv::Mat WholeImageFilter::filter(cv::Mat image)
{
	int width = image.cols;
	int height = image.rows;

	originalSpace = cv::Rect(0, 0, width, height);
	transformedSpace = cv::Rect(0, 0, width, height);

	transformRect(transformedSpace);

	return filterPixels(image, transformedSpace);
}
