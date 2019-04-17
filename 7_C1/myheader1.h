#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int pic_x, pic_y;
int rx, ry;

void objectChange() {
	pic_x += rx;
	pic_y += ry;

	if (pic_x >= 1000 || pic_x <= 0)
		rx = -rx;
	if (pic_y >= 800 || pic_y <= 0)
		ry = -ry;
}

#endif // !MYHEADER_H_INCLUDED
