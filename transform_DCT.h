#ifndef _INSIDE_VISUAL_CPP_TRANSFORM_DCT
#define _INSIDE_VISUAL_CPP_TRANSFORM_DCT
#include "FFT.h"

//离散余弦变换类
class transform_DCT : public Transform_FFT
{
protected:
	double *pDctBuff;
	LONG	w;				// 进行傅立叶变换的宽度（2的整数次方）
	LONG	h;				// 进行傅立叶变换的高度（2的整数次方）
	int		wp;
	int		hp;

public:
    transform_DCT();
    transform_DCT(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData);
    ~transform_DCT();

protected:	
	//处理离散余弦变换的函数
	void DCT(double *f, double *F, int power);
	void IDCT(double *F, double *f, int power);

public:
	void ImgDCT();
	void ImgIDCT();
};

#endif //_INSIDE_VISUAL_CPP_TRANSFORM_DCT
