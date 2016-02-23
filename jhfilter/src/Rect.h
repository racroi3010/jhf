/*
 * Rect.h
 *
 *  Created on: 2016. 2. 23.
 *      Author: NOIDH
 */

#ifndef RECT_H_
#define RECT_H_

class Rect {
public:
	Rect();
	Rect(int = 0, int = 0, int = 0, int = 0);
	virtual ~Rect();

	int x;
	int y;
	int width;
	int height;
};

#endif /* RECT_H_ */
