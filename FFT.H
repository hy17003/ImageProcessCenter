#ifndef _INSIDE_VISUAL_CPP_TRANSFORM
#define _INSIDE_VISUAL_CPP_TRANSFORM
#include"ImageCenterDib.h"


//�궨�壬PI
#define PI 3.1415926

//�������ͽṹ��
struct ComplexNumber
{
	float imag;// imaginary�鲿
	float real;//ʵ��
};

//���ٸ���Ҷ�任��
class Transform_FFT:public ImgCenterDib
{
public:
	//���ͼ��ÿ����λ��
	int m_nBitCountOut;
	
	//���ͼ��λͼ����ָ��
	unsigned char * m_pImgDataOut;
	
	//���ͼ����ɫ��
	LPRGBQUAD m_lpColorTableOut;
protected:
	
	//���ͼ��Ŀ�
	int m_imgWidthOut;
	
	//���ͼ��ĸ�
	int m_imgHeightOut;
	
	//���ͼ����ɫ������
	int m_nColorTableLengthOut;
	
	//����ͼ��Ϊ��2���ݴεķ���ʱ����չͼ������Ҫ�Ļ�����ָ��
	unsigned char *m_pImgExpandBuf;
	
	//����Ҷ�任������
	ComplexNumber *m_pFFTBuf;
	
	//ͼ���Ƿ���չ�ı�־����
	bool m_isExpanded;
	
public:
	//�����������캯��
	Transform_FFT();
	
	//�������Ĺ��캯��
	Transform_FFT(CSize size, int nBitCount, LPRGBQUAD lpColorTable, 
		unsigned char *pImgData);
	
	//��������
	~Transform_FFT();
	
	//������Ϊ��λ�������ͼ��Ŀ��͸�
	CSize GetDimensions();
	
	//����ԭͼ������
	void InputImgData(CSize size, int nBitCount, LPRGBQUAD lpColorTable, 
		unsigned char *pImgData);
	
	//ͼ����Ҷ�任
	void Fourier();
	
	//����Ҷ���任
	void IFourier();
	
	//��չ��ͼ����Ҷ�任
	void FourierEx();
	
	//��չ�ĸ���Ҷ���任
	void IFourierEx();
	
protected:
	//һά���ٸ���Ҷ���任
	void FFT1D(ComplexNumber *arrayBuf, int n);
	
	//һά���ٸ���Ҷ���任
	void IFFT1D(ComplexNumber *arrayBuf, int n);
	
	//��ά���ٸ���Ҷ�任
	void ImgFFT2D(unsigned char* imgBuf, int width, int height, unsigned char *imgBufOut);
	
	//��ά���ٸ���Ҷ�任
	void ImgIFFT2D(unsigned char* imgBufOut, int width, int height);
	
	//һά���ٸ���Ҷ���任
	
	//һά���ٸ���Ҷ���任
};

#endif // _INSIDE_VISUAL_CPP_TRANSFORM