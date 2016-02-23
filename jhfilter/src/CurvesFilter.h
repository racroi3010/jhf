#pragma once
#include "TransferFilter.h"
#include "Curve.h"

class CurvesFilter :
	public TransferFilter
{
public:
	CurvesFilter();
	~CurvesFilter();


	void setCurve(Curve curve);
	void setCurves(Curve * curve, int length);
	Curve * getCurves();
	int * filter(int * src, int width, int height);
	float transferFunction(float f);
private:
	Curve * curves;
	int length;
protected:
	void initialize();


};

