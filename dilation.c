#include<stdio.h>
#include<stdlib.h>
#include "pgm.h"
#define WHITE 255
#define BLACK 0

void erode( )
{
  int counter;
  int p_x, p_y;
  int x, y, m, n;

  x_size2 = x_size1;
  y_size2 = y_size1;
  for (y = 0; y < y_size2; y++)
    for (x = 0; x < x_size2; x++)
      image2[y][x] = image1[y][x];

  for (y = 0; y < y_size1; y++) {
    for (x = 0; x < x_size1; x++) {
      if (image1[y][x] == BLACK) {
	counter = 0;
	for (m = -1; m < 2; m++) {
	  for (n = -1; n < 2; n++) {
	    p_x = x + n;
	    p_y = y + m;
	    if (p_x >= 0 && p_x < x_size1 &&
		p_y >= 0 && p_y < y_size1 &&
		image1[p_y][p_x] == WHITE)
	      counter++;
	  }
	}
	if (counter > 0)
	  image2[y][x] = WHITE;
      }
    }
  }
}


main( )
{
  int times;
  int x, y;

  load_image( );
  printf("\nNumber of repetitions = ");
  scanf("%d", &times);
  printf("\n");

  while (times--) {
    erode( );
    for (y = 0; y < y_size1; y++)
      for (x = 0; x < x_size1; x++)
	image1[y][x] = image2[y][x];
  }

  save_image( );

  return 0;
}

