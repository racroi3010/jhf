/*
 * ContrastFilter.h
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#ifndef CONTRASTFILTER_H_
#define CONTRASTFILTER_H_

#include "TransferFilter.h"

class ContrastFilter: public TransferFilter {
public:
	ContrastFilter();
	virtual ~ContrastFilter();

	float transferFunction(float f);
//	cv::Mat filter(cv::Mat image);

	float getBrightness() const;
	void setBrightness(float brightness = 1.0f);
	float getContrast() const;
	void setContrast(float contrast = 1.0f);

private:
	float brightness = 1.0f;
	float contrast = 1.0f;
};

#endif /* CONTRASTFILTER_H_ */
