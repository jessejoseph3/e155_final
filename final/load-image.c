#include <stdlib.h>
#include <stdio.h>
#include "png.h"




int loadimage(char * filename)
{
	FILE *infile = fopen(file_name, "rb");

	uch sig[8];
  
    fread(sig, 1, 8, infile);
    if (!png_check_sig(sig, 8))
        return 1;   /* bad signature */

    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL,
      NULL);
    if (!png_ptr)
        return 4;   /* out of memory */
  
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return 4;   /* out of memory */
    }

    if (setjmp(png_ptr->jmpbuf)) {
        png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
        return 2;
    }

	png_init_io(png_ptr, infile);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    //png_get_IHDR(png_ptr, info_ptr, &pwidth, &pheight, &bit_depth,
    //  &color_type, NULL, NULL, NULL);
    //*width = pwidth;
    //*height = pheight;
  
    return 0;

}