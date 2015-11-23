#include <Math.h>

const int sobelx = {-1, 0, 1, 
					-2, 0, 2,
					-1, 0, 1};
					
const int sobely = {-1, -2, -1,
					0, 0, 0,
					1, 2, 1};

const double threshold = 0.3;

char *find_edges_grayscale()
{
	edges = (char *) malloc(height*width);
	char valueToWrite;
	double ave_diff_of_image = average_diff_of_image();
	int y;
	int x;
	double aveWindow;
	for(y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for(x = 0; x < width; x++) {
      		png_bytep px = &(row[x]);
      		if (x == 0
      			|| x == width - 1
      			|| y == 0
      			|| y == height -1){
      			valueToWrite = 0x0;
      		}
      		else {
      			aveWindow = average_difference(x,y,0,1);
      			if(aveWindow > threshold*ave_diff_of_image){
      				valueToWrite = 0xFF;
      			}
      			else{
      				valueToWrite = 0x0;
      			}
      		}
      		edges[y*width + x] = valueToWrite;
   		}
    }
}

double average_difference(int x, int y, int c, int pxsize)
{
	int i, j;
	int sum;
	for(i = -1; i < 2; i++){
		png_bytep row = row_pointers[y + i];
		for(j = -1; j < 2; j++){
			png_bytep px = &(row[x * pxsize]);
			average += (double) px[c]/9.0;
		}
	}
	double avediff = 0.0;
	for(i = -1; i < 2; i++){
		png_bytep row = row_pointers[y + i];
		for(j = -1; j < 2; j++){
			png_bytep px = &(row[x * pxsize]);
			avediff += fabs(px[c] - average)/9.0;
		}
	}
	return avediff;

}


double average_diff_of_image()
{
	double numPixels = height*width;
	double average = 0.0;
	int y;
	int x;
	for(y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for(x = 0; x < width; x++) {
      		png_bytep px = &(row[x]);
      		average += (double) px[c]/numPixels;
      		}
   		}
    }
    double ave_diff_of_image = 0.0;
    for(y = 0; y < height; y++) {
    	png_bytep row = row_pointers[y];
    	for(x = 0; x < width; x++) {
      		png_bytep px = &(row[x]);
      		ave_diff_of_image += fabs(px[c] - average)/numPixels;
      		}
   		}
    }
    return ave_diff_of_image;
}