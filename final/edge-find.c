#include <stdlib.h>
#include <stdio.h>
#include "load-image.c"

static png_structp png_ptr;
static png_infop info_ptr;

char *file = "obama.png";

void main(int argc, char *argv[])
{
	int exitStatus = loadimage(file, png_ptr, info_ptr);
	printf("image loaded? %d \n",exitStatus);

	int bitDepth 	= 	png_get_bit_depth(png_ptr, info_ptr);
	int colorType	=	png_get_color_type(png_ptr, info_ptr);
	int width 		=	png_get_image_width(png_ptr, info_ptr);
	int height		=	png_get_image_height(png_ptr, info_ptr);

	printf("bitDepth: %d \n", bitDepth);
	printf("colorType: %d \n", colorType);
	printf("width: %d \n", width);
	printf("height: %d \n", height);

	//char **row_pointers;

	//png_read_png(png_ptr, info_ptr, png_transforms, NULL);
	//row_pointers = png_get_rows(png_ptr, info_ptr);


}