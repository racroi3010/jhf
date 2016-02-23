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

	int * filter(int * src, int width, int height);
	int filterRGB(int rgb);
};

#endif /* GRAYSCALEFILTER_H_ */
