#ifndef _INSIDE_VISUAL_CPP_CImgEnhance
#define _INSIDE_VISUAL_CPP_CImgEnhance
#include "ImageCenterDib.h"

//处理图像增强类
class CImgEnhance:public ImgCenterDib  
{
public:
    int m_nBitCountOut;
	unsigned char * m_pImgDataOut;
	LPRGBQUAD m_lpColorTableOut;
	int m_nColorTableLengthOut;
public:
	//构造函数
	CImgEnhance();
	CImgEnhance(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData);
    ~CImgEnhance();
	
	//添加椒盐噪声
	void AddPepperSaltNoise();
	
	//添加高斯噪声
	void AddRandomNoise();
    
	//采用均值模板进行图像平滑
	void AvgTemplate(int TempH, int TempW, int TempCX, int TempCY, float *fpTempArray, float fCoef);
	
	//中值滤波
	BYTE FindMedianValue(unsigned char* lpbArray,int iArrayLen);
	void MedianFilter(int iFilterH, int iFilterW, int iFilterCX, int iFilterCY);
	
	//拉普拉斯锐化 转化为模板运算
	void LapTemplate(int TempH, int TempW, int TempCX, int TempCY, float *fpTempArray, float fCoef);
	
	//梯度锐化
	void GradSharp(BYTE bThre);
	
	//选择掩模平滑
	void ChooseMask();
	
	//图像信噪比SNR
	CString SNR(unsigned char* m_pImgSrcData);
	
	//图像峰值信噪比
	CString PSNR(unsigned char* m_pImgSrcData);
	
};

#endif // _INSIDE_VISUAL_CPP_CImgEnhance