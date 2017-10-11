#include "stdafx.h"
#include "transform_DCT.h"
#include "math.h"

transform_DCT::transform_DCT()
{
	pDctBuff = NULL;
}

transform_DCT::transform_DCT(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData):
Transform_FFT(size, nBitCount, lpColorTable, pImgData)
{
	pDctBuff = NULL;
}

transform_DCT::~transform_DCT()
{
	if (pDctBuff != NULL)
	{
		delete[] pDctBuff;
		pDctBuff = NULL;
	}
}
/**********************************************************************
 *
 * 函数名称：
 * DCT()
 *
 * 参数：
 * double *f 时域数据指针
 * double *F 频域数据指针
 * int r 高度
 *
 * 返回值：
 * void
 *
 * 说明：
 * 利用快速傅立叶变换实现快速离散余弦变换
 *
 **********************************************************************/
void transform_DCT::DCT(double *f, double *F, int r)
{
	
	int	count;			// 离散余弦变换点数	
	int		i;				// 循环变量	
	double	dTemp;	
	
	count = 1<<r;			// 计算离散余弦变换点数	
	ComplexNumber *array = new ComplexNumber[count*2];	
	memset(array, 0, sizeof(ComplexNumber) * count * 2);	// 赋初值为0
	
	// 将时域点写入数组array
	for(i=0;i<count;i++)
	{
		array[i].real = (float)f[i];
		array[i].imag = 0;
	}

	FFT1D(array, count * 2);// 调用快速傅立叶变换		
	
	dTemp = 1 / sqrt((double)count);	// 调整系数		
	F[0] = array[0].real * dTemp;	// 求F[0]	
	dTemp *= sqrt((double)2);
	
	// 求F[u]	
	for(i = 1; i < count; i++)
	{
		F[i] = (array[i].real * cos(i*PI/(count*2)) + array[i].imag * 
			sin(i*PI/(count*2))) * dTemp;
	}
	
	delete[] array;
}
/**********************************************************************
 *
 * 函数名称：
 * ImgDCT()
 *
 * 参数：
 * 无
 *
 * 返回值：
 * void
 *
 * 说明：
 * 实现图像的离散余弦变换
 *
 **********************************************************************/
void transform_DCT::ImgDCT()
{
    unsigned char*	pSrc;	// 指向源图像的指针	
	unsigned char*  pDst;
	int	i,j;				// 循环变量
	double	dTemp;

	if(m_pImgDataOut!=NULL)
	{
		delete []m_pImgDataOut;
		m_pImgDataOut=NULL;
	}
	//计算图像每行的字节数
   	int lineByte=(m_imgWidth*m_nBitCount/8+3)/4*4;

	if(m_nBitCount!=8)
	{
		AfxMessageBox(_T("只能处理8位灰度图像!"));
		return ;
	}
	//分配内存，以保存新图像
	m_nBitCountOut=m_nBitCount;
    int lineByteOut=(m_imgWidth*m_nBitCountOut/8+3)/4*4;
	if (!m_pImgDataOut)
	{
		//为处理后的图像分配内存空间
		m_pImgDataOut=new unsigned char[lineByteOut*m_imgHeight];
	}
	int pixelByte=m_nBitCountOut/8;
	for(i=0; i<m_imgHeight; i++){
		for(j=0; j<m_imgWidth*pixelByte; j++)
			*(m_pImgDataOut+i*lineByteOut+j)= *(m_pImgData+i*lineByteOut+j);
	}
		
	// 赋初值
	w = 1;
	h = 1;
	wp = 0;
	hp = 0;
	
	// 计算进行离散余弦变换的宽度和高度（2的整数次方）
	while(w * 2 <= m_imgWidth)
	{
		w *= 2;
		wp++;
	}
	
	while(h * 2 <= m_imgHeight)
	{
		h *= 2;
		hp++;
	}
	
	double *f = new double[w * h];
	pDctBuff = new double[w * h];
	double *F = pDctBuff;
	
	
	for(i = 0; i < h; i++)			// 行
	{		
		for(j = 0; j < w; j++)		// 列
		{
			// 指向DIB第i行，第j个象素的指针
			pSrc = (unsigned char*)m_pImgData + lineByte * (m_imgHeight - 1 - i) + j;
			
			// 给时域赋值
			f[j + i * w] = *(pSrc);
		}
	}
	
	for(i = 0; i < h; i++)
	{
		// 对y方向进行离散余弦变换
		DCT(&f[w * i], &F[w * i], wp);
	}
	
	// 保存计算结果
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			f[j * h + i] = F[j + w * i];
		}
	}
	
	for(j = 0; j < w; j++)
	{
		// 对x方向进行离散余弦变换
		DCT(&f[j * h], &F[j * h], hp);
	}	
	
	for(i = 0; i < h; i++)			// 行
	{
		for(j = 0; j < w; j++)		// 列
		{
			//指向新DIB第i行第j列的像素的指针
			pDst = m_pImgDataOut + lineByte * (m_imgHeight -1 - i) + j;

			dTemp = fabs(F[j*h+i]);	// 计算频谱
			
			// 判断是否超过255
			if (dTemp > 255)
			{
				dTemp = 255;
			}
			// 复制新DIB位图的像素值
			*pDst=(BYTE)(dTemp);
		}
	}
	m_imgWidthOut=m_imgWidth;
	m_imgHeightOut=m_imgHeight;
	delete[] f;
}

/*************************************************************************
* 函数名称：
*   IDCT()
* 参数:
*   double * F	- 指向频域值的指针
*   double * f	- 指向时域值的指针
*   r－2的幂数
* 返回值:
*   无。
* 说明:
*   该函数用来实现快速离散余弦反变换。该函数也利用2N点的快速付立叶变换
* 来实现离散余弦反变换。
************************************************************************/
void transform_DCT::IDCT(double *F, double *f, int r)
{
	LONG	count;			// 离散余弦反变换点数
	int		i;				// 循环变量
	double	dTemp, d0;	

	count = 1<<r;			// 计算离散余弦变换点数
	ComplexNumber *array = new ComplexNumber[count*2];
	memset(array, 0, sizeof(ComplexNumber) * count * 2);	// 赋初值为0
	
	// 将频域变换后点写入数组array
	for(i=0;i<count;i++)
	{
		array[i].real = (float)(F[i] * cos(i*PI/(count*2)));
		array[i].imag = (float)(F[i] * sin(i*PI/(count*2)));
	}
	
	IFFT1D(array, count * 2);// 调用快速傅立叶反变换	
	
	// 调整系数
	dTemp = sqrt((double)2.0/count);
	d0 = (sqrt((double)1.0/count) - dTemp) * F[0];
	
	for(i = 0; i < count; i++)
	{
		f[i] = d0 + array[i].real * dTemp * 2 * count;
	}
	
	delete[] array;
}

/**********************************************************************
 *
 * 函数名称：
 * ImgIDCT()
 *
 * 参数：
 * 无
 *
 * 返回值：
 * void
 *
 * 说明：
 * 实现图像的离散余弦反变换
 *
 **********************************************************************/
void transform_DCT::ImgIDCT()
{
	if (pDctBuff == NULL)
	{
		AfxMessageBox(_T("请先进行DCT变换！"));
		return;
	}	
	unsigned char*  pDst;	// 指向时域图像的指针	
	int	i,j;	// 循环变量
	double	dTemp;

	if(m_pImgDataOut!=NULL)
	{
		delete []m_pImgDataOut;
		m_pImgDataOut=NULL;
	}
	//计算图像每行的字节数
   	int lineByte=(m_imgWidth*m_nBitCount/8+3)/4*4;

	//分配内存，以保存新图像
	m_nBitCountOut=m_nBitCount;
    int lineByteOut=(m_imgWidth*m_nBitCountOut/8+3)/4*4;
	if (!m_pImgDataOut)
	{
		//为处理后的图像分配内存空间
		m_pImgDataOut=new unsigned char[lineByteOut*m_imgHeight];
	}
	int pixelByte=m_nBitCountOut/8;
	for(i=0; i<m_imgHeight; i++){
		for(j=0; j<m_imgWidth*pixelByte; j++)
			*(m_pImgDataOut+i*lineByteOut+j)= *(m_pImgData+i*lineByteOut+j);
	}
	
	double *f = new double[w * h];
	double *F = pDctBuff;
	
	for(i = 0; i < h; i++)
	{
		// 对y方向进行离散余弦变换
		IDCT(&F[w * i], &f[w * i], wp);
	}
	
	// 保存计算结果
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			F[j * h + i] = f[j + w * i];
		}
	}
	
	for(j = 0; j < w; j++)
	{
		// 对x方向进行离散余弦变换
		IDCT(&F[j * h], &f[j * h], hp);
	}	
	
	for(i = 0; i < h; i++)			// 行
	{
		for(j = 0; j < w; j++)		// 列
		{
			//指向新DIB第i行第j列的像素的指针
			pDst = m_pImgDataOut + lineByte * (m_imgHeight -1 - i) + j;

			dTemp = fabs(f[i*h+j]);	// 计算频谱,转置操作
			
			// 判断是否超过255
			if (dTemp > 255)
			{
				dTemp = 255;
			}
			// 复制新DIB位图的像素值
			*pDst=(BYTE)(dTemp);
		}
	}
	m_imgWidthOut=m_imgWidth;
	m_imgHeightOut=m_imgHeight;
	delete[] f;
}