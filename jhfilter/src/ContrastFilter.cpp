/*
 * ContrastFilter.cpp
 *
 *  Created on: 2016. 2. 22.
 *      Author: NOIDH
 */

#include "ContrastFilter.h"

ContrastFilter::ContrastFilter() {
	brightness = 1.0f;
	contrast = 1.0f;
}

ContrastFilter::~ContrastFilter() {
	// TODO Auto-generated destructor stub
}

float ContrastFilter::transferFunction(float f)
{
	f = f * brightness;
	f = (f - 0.5f) * contrast + 0.5f;
	return f;

}

float ContrastFilter::getBrightness() const {
	return brightness;
}

void ContrastFilter::setBrightness(float brightness) {
	this->brightness = brightness;
}

float ContrastFilter::getContrast() const {
	return contrast;
}

void ContrastFilter::setContrast(float contrast) {
	this->contrast = contrast;
}

