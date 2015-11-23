#include <stdlib.h>
#include <stdio.h>
#include "load-image.c"

static png_structp png_ptr;
static png_infop info_ptr;

void main(int argc, char *argv[])
{
	loadimage('obama.png');

	int bitDepth 	= 	png_get_bit_depth(png_ptr, info_ptr);
	int colorType	=	png_get_color_type(png_ptr, info_ptr);

	printf(bitDepth);
	printf(colorType);

	//char **row_pointers;

	//png_read_png(png_ptr, info_ptr, png_transforms, NULL);
	//row_pointers = png_get_rows(png_ptr, info_ptr);


}