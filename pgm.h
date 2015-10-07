#define IMAGESIZE  1024
#define BRIGHTNESS  255
#define GRAYLEVEL       256
#define FILENAME    256
#define BUFFERSIZE  256

unsigned char image1[IMAGESIZE][IMAGESIZE],
  image2[IMAGESIZE][IMAGESIZE];
int x_size1, y_size1,
  x_size2, y_size2;

void load_image( );
void save_image( );
void load_imagef(char *);
void save_imagef(char *);


void load_image( )
{
  char file_name[FILENAME];
  char buffer[BUFFERSIZE];
  FILE *fp;
  int max_gray;
  int x, y;
  printf("Name of input image file? : ");
  scanf("%s", file_name);
  fp = fopen(file_name, "rb");
  if (NULL == fp) {
    printf("     The file doesn't exist!\n\n");
    exit(1);
  }
  fgets(buffer, BUFFERSIZE, fp);
  if (buffer[0] != 'P' || buffer[1] != '5') {
    printf("     Mistaken file format, not P5!\n\n");
    exit(1);
  }

  x_size1 = 0;
  y_size1 = 0;
  while (x_size1 == 0 || y_size1 == 0) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d %d", &x_size1, &y_size1);
    }
  }

  max_gray = 0;
  while (max_gray == 0) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d", &max_gray);
    }
  }

  printf("\n     Image width = %d, Image height = %d\n", x_size1, y_size1);
  printf("     Maximum gray level = %d\n\n",max_gray);
  if (x_size1 > IMAGESIZE || y_size1 > IMAGESIZE) {
    printf("     Image size exceeds %d x %d\n\n",
	   IMAGESIZE, IMAGESIZE);
    printf("     Please use smaller images!\n\n");
    exit(1);
  }
  if (max_gray != BRIGHTNESS) {
    printf("     Invalid value of maximum gray level!\n\n");
    exit(1);
  }

  for (y = 0; y < y_size1; y++) {
    for (x = 0; x < x_size1; x++) {
      image1[y][x] = (unsigned char)fgetc(fp);
    }
  }
  printf("-------------------------------------\n\n");
  fclose(fp);
}

void save_image( )
{
  char file_name[FILENAME];
  FILE *fp;
  int x, y;

  printf("Name of output image file? : ");
  scanf("%s",file_name);
  fp = fopen(file_name, "wb");

  fputs("P5\n", fp);
  fputs("# Created by Image Processing\n", fp);
  fprintf(fp, "%d %d\n", x_size2, y_size2);
  fprintf(fp, "%d\n", BRIGHTNESS);

  for (y = 0; y < y_size2; y++) {
    for (x = 0; x < x_size2; x++) {
      fputc(image2[y][x], fp);
    }
  }
  printf("\n-------------------------------\n\n");
  fclose(fp);
}

void load_imagef(char *filename)
{
  char buffer[BUFFERSIZE];
  FILE *fp;
  int max_gray;
  int x, y;

  fp = fopen(filename, "rb");
  if (NULL == fp) {
    printf("     The file doesn't exist!\n\n");
    exit(1);
  }
  fgets(buffer, BUFFERSIZE, fp);
  if (buffer[0] != 'P' || buffer[1] != '5') {
    printf("     Mistaken file format, not P5!\n\n");
    exit(1);
  }
  x_size1 = 0;
  y_size1 = 0;
  while (x_size1 == 0 || y_size1 == 0) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d %d", &x_size1, &y_size1);
    }
  }
  max_gray = 0;
  while (max_gray == 0) {
    fgets(buffer, BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d", &max_gray);
    }
  }
  if (x_size1 > IMAGESIZE || y_size1 > IMAGESIZE) {
    printf("     Image size exceeds %d x %d\n\n",
	   IMAGESIZE, IMAGESIZE);
    printf("     Please use smaller images!\n\n");
    exit(1);
  }
  if (max_gray != BRIGHTNESS) {
    printf("     Invalid value of maximum gray level!\n\n");
    exit(1);
  }
  for (y = 0; y < y_size1; y++) {
    for (x = 0; x < x_size1; x++) {
      image1[y][x] = (unsigned char)fgetc(fp);
    }
  }
  fclose(fp);
}

void save_imagef(char *filename)
{
  FILE *fp;
  int x, y;

  fp = fopen(filename, "wb");
  fputs("P5\n", fp);
  fputs("# Created by Image Processing\n", fp);
  fprintf(fp, "%d %d\n", x_size2, y_size2);
  fprintf(fp, "%d\n", BRIGHTNESS);
  for (y = 0; y < y_size2; y++) {
    for (x = 0; x < x_size2; x++) {
      fputc(image2[y][x], fp);
    }
  }
  fclose(fp);
}
