/*
 * LevelsFilter.h
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#ifndef LEVELSFILTER_H_
#define LEVELSFILTER_H_

#include "WholeImageFilter.h"

class LevelsFilter: public WholeImageFilter {
public:
	LevelsFilter();
	virtual ~LevelsFilter();

	cv::Mat filter(cv::Mat image);

	cv::Mat filterPixels(cv::Mat, cv::Rect);
	cv::Vec3b filterBGR(cv::Vec3b);
	void transformRect(cv::Rect rect);

	float getHighLevel() const;
	void setHighLevel(float highLevel);
	float getHighOutputLevel() const;
	void setHighOutputLevel(float highOutputLevel);
	float getLowLevel() const;
	void setLowLevel(float lowLevel);
	float getLowOutputLevel() const;
	void setLowOutputLevel(float lowOutputLevel);

private:
	int ** lut;
	float lowLevel;
	float highLevel;
	float lowOutputLevel;
	float highOutputLevel;
};

#endif /* LEVELSFILTER_H_ */
