/*
 * GrayscaleFilter.h
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#ifndef GRAYSCALEFILTER_H_
#define GRAYSCALEFILTER_H_

#include "PointFilter.h"

class GrayscaleFilter: public PointFilter {
public:
	GrayscaleFilter();
	virtual ~GrayscaleFilter();

	cv::Mat filter(cv::Mat image);
	cv::Vec3b filterBGR(cv::Vec3b pixel);
};

#endif /* GRAYSCALEFILTER_H_ */
