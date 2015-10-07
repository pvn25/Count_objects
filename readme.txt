Folder contains :-
*code files :
pgm.h,thresholding.c,dilation.c
*Software to open pgm image:
pgmview;
*test images::blocks.pgm and stars.pgm
*Project Report
*readme.txt
-----------------------------------------------------------------
Software Required to open pgm images in Windows:-
	pgmviewer(Find Attached with folder)
	Click on pgmview.exe to open an image
-----------------------------------------------------------------
Step 1:- Thresholding an image
-----------------------------------------------------------------
A. Run thresholding.c 
   Name of input image file? will be asked
   Input:- location/blocks.pgm
   location will be where you are storing blocks.pgm or stars.pgm (the input images)
   For example D:/blocks.pgm

   Number of Objects shown is 21 in blocks.pgm(Not the final output as we have not fully processed the image).
   This is due to noise.

B. Name of Output image file will be asked
   Enter the Input:- location/any_name.pgm
  .pgm file will be created at this location that has noise

C. Open pgmviewer and select open to view the created binary image.
----------------------------------------------------------------
Step 2:- Noise Reduction through Dilation
----------------------------------------------------------------
A. Run dilation.pgm
   Name of input image file? will be asked
   Input:- location/any_name.pgm
   this input image is one with noise not blocks.pgm

B. Number of Repetitions will be asked
   Input:- Depends on the original image that we are considering
   if the general object size is large and they are clearly discernible 
   as in this case,then input <=3 , else if objects size is small
   and not clearly viewable as with stars.pgm , then input is 1 or 0

C. Name of Output image file will be asked
   Input:- location/any_othername.pgm
  .pgm file will be created at this location on which we'll apply
   connected component labelling algorithm

D. Open pgmviewer and select open to view image
------------------------------------------------------------------
Step 3:- Connected Component labelling
------------------------------------------------------------------
A. Run thresholding.c
   Name of input image file? will be asked
   Input:- location/any_othername.pgm
   this input image is the output of the above step

B. Name of Output image file will be asked
   Input:- location/final_image.pgm
   Final image will be created at the entered location
   The Number Of Objects Displayed at this step is the final answer.

C. Open pgmviewer and select open to view image