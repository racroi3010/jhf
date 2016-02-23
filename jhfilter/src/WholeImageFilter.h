/*
 * WholeImageFilter.h
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#ifndef WHOLEIMAGEFILTER_H_
#define WHOLEIMAGEFILTER_H_

#include "BaseFilter.h"
#include "Rect.h"

class WholeImageFilter: public BaseFilter {
public:
	WholeImageFilter();
	virtual ~WholeImageFilter();

protected:
	int * filter(int * src, int width, int height);

	virtual void transformRect(Rect rect) = 0;
	virtual int * filterPixels(int * src, int width, int height, Rect transformedSpace) = 0;
private:
	Rect * transformedSpace;
	Rect * originalSpace;
};

#endif /* WHOLEIMAGEFILTER_H_ */
