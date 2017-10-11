#pragma once

#include <complex>
using namespace std; 

#ifndef FOURIERTRANSFORM_H
#define FOURIERTRANSFORM_H

class FourierTransform
{
public:
	FourierTransform(void);
public:
	~FourierTransform(void);

public:
	void FFT(complex<double> *TD, complex<double> *FD, int r);
	void IFFT(complex<double> * FD, complex<double> * TD, int r);
	BOOL Fourier(complex<double> * TD, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);
	BOOL IFourier(unsigned char *TD, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);
	//图像的傅里叶变换函数，进行图像的填充
	//complex<double> * ImageRestore::ImageFourier(CDib *dib, LONG lWidth, LONG lHeight, complex<double> * FD);
	complex<double> * ImageFourier(unsigned char *data, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);
	BOOL IFourier(double *TD, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);

	//周期延拓傅利叶变换
	complex<double> * ImageFourierEx(unsigned char *Y, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);
	complex<double> * ImageFourierEx(double *Y, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);
	BOOL ImageIFourierEx(double *TD, LONG lWidth, LONG lHeight, complex<double> * FD,int ByteCount);

};

#endif