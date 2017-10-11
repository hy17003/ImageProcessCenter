#ifndef __WATERSHED_H__
#define __WATERSHED_H__

#include "ImageCenterDib.h"

//水域变换类
class Watershed:public ImgCenterDib
{
public:	
	int m_nBitCountOut;//输出图像每像素位数

	unsigned char * m_pImgDataOut;//输出图像位图数据指针

	LPRGBQUAD m_lpColorTableOut;//输出图像颜色表

	int objectCount;	//目标数,生长中需要标记的种类数

private:
	int m_imgWidthOut;//输出图像的宽
	
	int m_imgHeightOut;//输出图像的高

	int m_nColorTableLengthOut;//输出图像颜色表长度
	
	CPoint *queue[256][4];//队列
	
	int queueLng;//队列缓冲区的长度

	int headPointer[256][4];//队首指针 

	int tailPointer[256][4];//队尾指针
	
public:
	Watershed();//不带参数的构造函数

	//带参数的构造函数
	Watershed(CSize size, int nBitCount, LPRGBQUAD lpColorTable,
		        unsigned char *pImgData);

	~Watershed();//析构函数

	CSize GetDimensions();//获取输出图像的尺寸
	
	//水域分割
	void WatershedSegment(CPoint position[], int classCount, int contourFlg);

private:
	//出队
	void Pop(int grey,int mark,CPoint* pPopPoint);

	//入队
	void Push(int gray,int mark,CPoint pushPoint);

	//判断队空
	bool IsEmpty(int gray,int mark);

	//判断队满
	bool IsOverflow(int gray,int mark);

	//sobel变换
	void Sobel(unsigned char *imgBuf, int width, int height, unsigned char *gradient);

	//队列初始化
	void InitQueue(unsigned char* pGradient, unsigned char* pMarker, int width,int height);

	//水域变换
	void WatershedTrans(unsigned char* pGradient, unsigned char* pMarker, int width,int height,bool flag_contour);

	//通过指定点产生标记
	void GenerateMarkerByPos(unsigned char* pMarker, int width,int height, 
		CPoint position[], int objectCount);
};
#endif