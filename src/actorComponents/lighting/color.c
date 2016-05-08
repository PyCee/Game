
#include "color.h"


color genColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	color col;
	col.red = r;
	col.green = g;
	col.blue = b;
	col.alpha = a;
	return col;
}
void freeColor(color *col)
{

}
