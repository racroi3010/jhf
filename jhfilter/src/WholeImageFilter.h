/*
 * WholeImageFilter.h
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#ifndef WHOLEIMAGEFILTER_H_
#define WHOLEIMAGEFILTER_H_

#include "BaseFilter.h"

class WholeImageFilter: public BaseFilter {
public:
	WholeImageFilter();
	virtual ~WholeImageFilter();

protected:
	cv::Mat filter(cv::Mat image);

	virtual void transformRect(cv::Rect rect) = 0;
	virtual cv::Mat filterPixels(cv::Mat image, cv::Rect transformedSpace) = 0;
private:
	cv::Rect transformedSpace;
	cv::Rect originalSpace;
};

#endif /* WHOLEIMAGEFILTER_H_ */
