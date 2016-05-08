
#ifndef COLOR
#define COLOR

typedef struct color{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
} color;

color genColor(unsigned char, unsigned char, unsigned char, unsigned char);
void freeColor(color *);

#endif /* COLOR */
