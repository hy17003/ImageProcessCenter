#include <complex>

using namespace std;


#include "FourierTransform.h"

#pragma comment(lib,FourierTransform)


void PhaseCorrelation(unsigned char * aRegion ,unsigned char *bRegion,int dWidth,int dHeight,int *xpos,int *ypos);

void PhaseAngleDiff(unsigned char * image1,unsigned char * image2, int imgWidth,int imgHeight);