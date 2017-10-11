
#include "stdafx.h"
#include "ImageRestore.h"
#include "ImageRestoreExt.h"

#include <math.h>
#include "FourierTransform.h"
#define PI 3.1415926

#pragma comment(lib,"FourierTransformLib8")
#pragma comment(lib,"ImageRestoreLib8")


ImageRestore::ImageRestore(void) : 
mask(NULL),mask_width(0),mask_height(0)
{
}

ImageRestore::~ImageRestore(void)
{
	if(mask != NULL)
		free(mask);
}


/***************************************************************************
*  MapRestoreByteVar
*  功能：投影法运动模糊恢复
*  参数：
*  imgBufIn    输入图像数据
*  imgWidth    图像宽度
*  imgHeight   图像高度
*  pxWidth     像素宽度
*  cycleCount  迭代次数
*  具体原理的理解 由卷积的步骤 H * F整体把握理解 
***************************************************************************/
void ImageRestore::MapRestoreByteVar(unsigned char *imgBufIn ,int imgWidth, int imgHeight,int pxWidth ,int cycleCount)
{

	ImageRestoreExt ire8;
	ire8.GeneratePSF(this->length,this->angle);
	ire8.MapRestoreByteVar(imgBufIn,imgWidth,imgHeight,pxWidth,cycleCount);
	

}


/***************************************************************************
* WienerRestoreByteVar
* 功能：维纳滤波运动模糊恢复
* 参数说明：
* imgBufIn  输入图像数据（8位灰度）
* imgWidth  图像宽度
* imgHeight 图像高度
* pxWidth   图像位宽（ 设置为1）
* k         参数（0- 1）
***************************************************************************/
bool ImageRestore::WienerRestoreByteVar(unsigned char *imgBufIn,int imgWidth,int imgHeight,int pxWidth,double k)
{
	if(imgBufIn == NULL || mask == NULL)
		return false;
	
	BYTE* Y = imgBufIn;

	int w=1,h=1;
	//计算大于等于原始图像大小的2的幂
	while(w < imgWidth)
	{
		w *= 2;
	}
	
	while(h < imgHeight)
	{
		h *= 2;
	}

	complex<double> *freqData= new complex<double>[w * h * pxWidth];
	FourierTransform ftm;

	//对图像进行傅里叶变换
	ftm.ImageFourierEx(imgBufIn, imgWidth, imgHeight,  freqData,1);


	//模板数据
	complex<double> *timeMaskData;
	complex<double> *freqMaskData;
	timeMaskData = new complex<double>[w * h * pxWidth];
	freqMaskData = new complex<double>[w * h * pxWidth];

	int i = 0,j = 0;

	int acce = 0;

	//填充模板，调整模板为2的整数次幂，多余的部分填充0	
	for(i = 0; i < h; i++){
		for(j = 0; j < w * pxWidth; j= j + 1){
			if(i < mask_height && j < mask_width * pxWidth){

				double Value = *((double*)mask + acce);
				acce ++ ;
				timeMaskData[w * i * pxWidth + j] = complex<double>(Value, 0.0f);
			}
			else{

				timeMaskData[w * i * pxWidth + j] = complex<double>(0.0f, 0.0f);
			}
		}
	}
	
	//对模板进行傅里叶变换
	if (ftm.Fourier(timeMaskData, w, h, freqMaskData,pxWidth) == FALSE){

		return false;	
	}

	double conf=0;
	//维纳滤波
	for(i = 0; i < h; i++){
		for(j = 0; j < w * pxWidth ; j = j + 1){

			complex<double> mask_item =freqMaskData[w * i * pxWidth + j];
			conf=(abs(mask_item) * abs(mask_item)) / ((abs(mask_item) * abs(mask_item)) + k);
			freqData[w * i * pxWidth + j]   = (freqData[w * i * pxWidth + j] * complex<double>(conf,conf) ) / mask_item;

		}
	}

	//对滤波结果进行逆变换
	if (ftm.IFourier(
		
		Y, imgWidth, imgHeight, freqData,1) == FALSE){
		return false;
	}

	delete[] freqMaskData;
	delete[] timeMaskData;
	delete[] freqData;

	return true;
}


/**************************************************************************
*函数名
*    InverseFilterByte()
*
*参数名
*   unsigned char *imgBufIn   -输入图像缓冲
*   int imgWidth              -图像宽度
*   int imgHeight             -图像高度
*   int pxWidth               -像素宽度(8位灰度图像请将该参数设置为 1)
*
*返回值
*    无
*
*说明：该函数将输入图像 imgBufIn作为输入图像，并按照计算好的点扩散函数进行
       逆滤波恢复。注意在调用该函数前，请先使用GeneratePSF产生点扩散函数。 
***************************************************************************/

bool ImageRestore::InverseFilterByte(unsigned char *imgBufIn,int imgWidth,int imgHeight,int pxWidth)
{

	if(imgBufIn == NULL || mask == NULL)
		return false;

	BYTE* Y = imgBufIn;

	int w=1,h=1;
	// 计算大于等于原始图像大小的2的幂
	while(w < imgWidth)
	{
		w *= 2;
	}
	
	while(h < imgHeight)
	{
		h *= 2;
	}

	complex<double> *freqData= new complex<double>[w * h * pxWidth];


	FourierTransform ftm;
	// 对图像进行傅里叶变换，freqData为输出结果
	ftm.ImageFourier(imgBufIn, imgWidth, imgHeight,  freqData,pxWidth);


	// 申请点扩散函数空域和频域空间
	complex<double> *timeMaskData = new complex<double>[w * h * pxWidth];
	complex<double> *freqMaskData = new complex<double>[w * h * pxWidth];


	int i = 0, j = 0;
	// 填充点扩散函数空间，调整模板为2的整数次幂，多余的部分填充0
	int acce = 0;
	for(i = 0; i < h; i++){
		for(j = 0; j < w * pxWidth; j= j + 1){
			if(i < mask_height && j < mask_width * pxWidth){

				double Value = *((double*)mask + acce);
				acce ++ ;
				timeMaskData[w * i * pxWidth + j] = complex<double>(Value, 0.0f);
			}
			else{
				timeMaskData[w * i * pxWidth + j] = complex<double>(0.0f, 0.0f);
			}
		}
	}
	
	// 对模板进行傅里叶变换
	if (ftm.Fourier(timeMaskData, w, h, freqMaskData,pxWidth) == FALSE)
		return false;	

	double conf=0;
	
	// 逆滤波
	for(i = 0; i < h; i++){
		for(j = 0; j < w * pxWidth ; j = j + 1){
			complex<double> mask=freqMaskData[w * i * pxWidth + j];

			if(mask.real() * mask.real() + mask.imag() * mask.imag()!= 0)
				freqData[w * i * pxWidth + j] = freqData[w * i * pxWidth + j] / mask;
			else
				freqData[w * i * pxWidth + j] = 0;

		}
	}

	// 对滤波结果进行逆变换
	if (ftm.IFourier(Y, imgWidth, imgHeight, freqData, pxWidth) == FALSE)
		return false;

	// 释放缓冲区
	delete[] timeMaskData;
	delete[] freqMaskData;
	delete[] freqData;


	return true;

}


/***************************************************************************
* GeneratePSF
* 功能：产生点扩散函数矩阵
* length   模糊长度
* angle    模糊角度
* 说明：采用先验信息的恢复方法是首先根据模糊信息产生电扩散函数
*       再使用逆滤波等恢复程序进行运动模糊恢复。
***************************************************************************/
void ImageRestore::GeneratePSF(double length, double angle)
{
	this->angle = angle;
	this->length = length;

	float half = length;
	double phi = (double)(angle/180)*PI;  //转化为弧度
	double cosphi = cos(phi);
	double sinphi = sin(phi);
	int xsign = cosphi?(cosphi>0?1:-1):0;

	if(cosphi<0) 
		xsign = -1;

	//线宽度
	int linewdt = 1;

	//计算一半图像的长和宽
	int sx = (int)(half * cosphi * xsign + linewdt + 0.5);
	int sy = (int)(half * sinphi + linewdt + 0.5);
	mask_width = sx;
	mask_height = sy;

	//距离计算空间
	//分配相应的内存空间
	if(mask != NULL)
		free(mask);
	
	mask = (double*)malloc(sizeof(double)*sx*sy);

	double **dist2line_matrix = (double**)malloc(sizeof(double*)*sy); //行组织

	int i = 0,j = 0;
	//指针指向每一行的首地址
	if(xsign == 1){
		for(i = 0; i< sy ; i++){
			dist2line_matrix[i] = mask + i * sx;
		}
	}
	else{
		for(i = sy - 1; i >= 0 ; i--){
			dist2line_matrix[i] = mask + (sy - i - 1) * sx;
		}
	}

	//弧度定义变量
	double rad = 0;

	//--考虑到：对于90到180之间，只是在x方向的反向，因此在控制逻辑上只需控制x遍历顺序即可
	int x_position = 0,x_start = 0;

	x_start = 0;

	//定义从一个点到旋转线的最短距离
	//距离垂直于旋转线
	for(i = 0; i < sy ; i ++){

		x_position = x_start;  

		for(j = 0; j < sx; j++){
			//线距离
			dist2line_matrix[i][j] = i * abs(cosphi) - j * sinphi;
			//半径距离
			rad = sqrt((double)(double)(i * i + j * j));

			if(rad >= half && abs(dist2line_matrix[i][j]) <= linewdt){
				int x2lastpix = half - abs((x_position + dist2line_matrix[i][j] * sinphi) / cosphi);
				dist2line_matrix[i][j] = sqrt((double)dist2line_matrix[i][j] * dist2line_matrix[i][j] + x2lastpix * x2lastpix);
				
			}
			
			dist2line_matrix[i][j] = linewdt - abs(dist2line_matrix[i][j]);
			
			if(dist2line_matrix[i][j] < 0) dist2line_matrix[i][j]=0;

			x_position ++;

		}
	}
	

	double sum = 0;
	for(i = 0; i < sy ; i ++){
		for(j = 0; j < sx; j++){
			sum += dist2line_matrix[i][j];
		}
	}

	//对矩阵数据进行归一化处理
	for(i = 0; i < sy ; i ++){
		for(j = 0; j < sx; j++){
			dist2line_matrix[i][j] /= sum;
		}
	}

	//删除二维矩阵
	delete[] dist2line_matrix;

	return;
}
