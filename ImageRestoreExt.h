#pragma once

#ifndef IMAGERESTORE_EXT_INCLUDE
#define IMAGERESTORE_EXT_INCLUDE


class ImageRestoreExt
{

private: 
	// 点扩散函数指针
	double *mask;  
			
	// 点扩散函数离散矩阵宽度    
	int mask_width;    
			
	// 点扩散函数离散矩阵高度
	int mask_height;   

public:
	//构造函数 
	ImageRestoreExt(void);

	//析构函数
	~ImageRestoreExt(void);

public:

	//分离数据投影法恢复，8位灰度数据和24位灰度数据输入
	void MapRestoreByteVar(unsigned char *imgBufIn ,int imgWidth, int imgHeight,int pxWidth ,int cycleCount);

	//变数据长度维纳滤波恢复
	bool WienerRestoreByteVar(unsigned char *imgBufIn,int imgWidth,int imgHeight,int pxWidth,double k);

	//图像逆滤波恢复
	bool InverseFilterByte(unsigned char *imgBufIn,int imgWidth,int imgHeight,int pxWidth);

	//PSF点扩散函数矩阵生成函数
	void GeneratePSF(double length, double angle);

};
#endif