#ifndef _INSIDE_VISUAL_CPP_Match
#define _INSIDE_VISUAL_CPP_Match
#include "ImageCenterDib.h"

//点处理类
class Match:public ImgCenterDib
{
public:
	int m_nBitCountOut;
	unsigned char * m_pImgDataOut;
	LPRGBQUAD m_lpColorTableOut;
	int m_nColorTableLengthOut;
public:
	int m_mask[5][5];//模板，最大为5x5
	Match();
	Match(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData);
	~Match();

	CSize GetDimensions();

	//空域相关匹配函数
	CPoint matchBasedSpacial(unsigned char *imgBuf, int width, int height, int pixelByte,
										unsigned char * blockBuf, int blockW, int blockH);

	//空域相关匹配结果显示
	void matchResult(LPCTSTR cankaoImgPath, LPCTSTR jizhunImgPath, int matchStyle);


private:
	//输出图像的宽
	int m_imgWidthOut;
	//输出图像的高
	int m_imgHeightOut;
	
};
#endif // _INSIDE_VISUAL_CPP_Match