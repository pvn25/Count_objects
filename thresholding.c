#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pgm.h"
#define ZERO 0
#define NONZERO 255
const int dx[] = {1, -1, 0,  0,  1, -1, 1, -1};
const int dy[] = {0,  0, 1, -1, -1,  1, 1, -1};
int label[IMAGESIZE][IMAGESIZE];
void dfs(int x, int y, int current_label,int xsize,int ysize) {
  if (x < 0 || x == xsize) return;
  if (y < 0 || y == ysize) return;
  if (label[x][y] || !image2[x][y]) return;


  label[x][y] = current_label;


  int direction;
  for (direction = 0; direction < 8; ++direction)
    dfs(x + dx[direction], y + dy[direction], current_label,xsize,ysize);
}
void thresholding( )
{
  int hist[GRAYLEVEL];
  double probab[GRAYLEVEL], ome[GRAYLEVEL];
  double mu[GRAYLEVEL];
  double max_sig, sig[GRAYLEVEL];
  int i, x, y;
  int threshold;
  for (i = 0; i < GRAYLEVEL; i++) hist[i] = 0;
  for (y = 0; y < y_size1; y++)
    for (x = 0; x < x_size1; x++) {
      hist[image1[y][x]]++;
    }

  for ( i = 0; i < GRAYLEVEL; i ++ ) {
    probab[i] = (double)hist[i] / (x_size1 * y_size1);
  }


  ome[0] = probab[0];
  mu[0] = 0.0;
  for (i = 1; i < GRAYLEVEL; i++) {
    ome[i] = ome[i-1] + probab[i];
    mu[i] = mu[i-1] + i*probab[i];
  }

  threshold = 0;
  max_sig = 0.0;
  for (i = 0; i < GRAYLEVEL-1; i++) {
    if (ome[i] != 0.0 && ome[i] != 1.0)
      sig[i] = pow(mu[GRAYLEVEL-1]*ome[i] - mu[i], 2) /
	(ome[i]*(1.0 - ome[i]));
    else
      sig[i] = 0.0;
    if (sig[i] > max_sig) {
      max_sig = sig[i];
      threshold = i;
    }
  }

 // printf("\nthreshold value = %d\n", threshold);

  x_size2 = x_size1;
  y_size2 = y_size1;
  for (y = 0; y < y_size2; y++)
    for (x = 0; x < x_size2; x++)
      if (image1[y][x] > threshold)
	image2[y][x] = BRIGHTNESS;
      else
	image2[y][x] = 0;

	int component = 0,p,q;
  for (p = 0; p < y_size2; ++p)
    {
    for (q = 0; q < x_size2; ++q)
    {
      if (!label[p][q] && image2[p][q])
      {

          dfs(p, q, ++component,x_size2,y_size2);
      }
    }
    }

    printf("      ");
    int c,r;

   printf("Number of objects are %d\n",component);

}


main( )
{
  load_image( );
  thresholding( );
  save_image( );

  return 0;
}
