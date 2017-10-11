#include "StdAfx.h"
#include "StaticDetect.h"

/***********************************************************************
* 函数名称：
*     CStaticDetect()
*
*说明：无参数的构造函数，对成员变量进行初始化
***********************************************************************/
CStaticDetect::CStaticDetect(int nwidth, int nheight)
{
	m_nFrame = 0;
	count = 0;
	WIDTH = nwidth;
	HEIGHT = nheight;
	IMAGESIZE = WIDTH*HEIGHT;
	
	m_pCurImage = new BYTE[IMAGESIZE*3];
	memset(m_pCurImage,0,IMAGESIZE*3);
	m_pGrayImage = new BYTE[IMAGESIZE];
	memset(m_pGrayImage,0,IMAGESIZE);
	m_pBackground = new BYTE[IMAGESIZE];
	memset(m_pBackground,0,IMAGESIZE);
    m_pDiffImage = new BYTE[IMAGESIZE]; 
	memset(m_pDiffImage,0,IMAGESIZE);
	m_pDetectImage = new BYTE[IMAGESIZE*3];
	memset(m_pDetectImage,0,IMAGESIZE*3);
	m_pBackHistgram = new short int[IMAGESIZE*256];
	memset(m_pBackHistgram,0,IMAGESIZE*256*sizeof(short int));
	m_pTemplate = new UINT[IMAGESIZE];
	memset(m_pTemplate,0,IMAGESIZE*sizeof(UINT));
}

/***********************************************************************
* 函数名称：
*     ~CStaticDetect()
*
*说明：析构函数，释放资源
***********************************************************************/
CStaticDetect::~CStaticDetect()
{
	delete [ ]m_pBackHistgram;
	delete [ ]m_pDiffImage;
	delete [ ]m_pGrayImage;
	delete [ ]m_pBackground;
	delete [ ]m_pDetectImage;
	delete [ ]m_pCurImage;
	delete [ ]m_pTemplate;
}

/***********************************************************************
* 函数名称：
*     ReceiveFrame
* 
* 参数：
*     int index-帧号
*     BYTE * sBuf-输入图像缓冲
* 
* 说明：
*     接受图像进行计算
/***********************************************************************/
void CStaticDetect::ReceiveFrame(int index,BYTE* sBuf)
{
	m_nFrame = index;
	memcpy(m_pCurImage,sBuf,WIDTH*HEIGHT*3);

	//转换为灰度图像
	RGBToGray(m_pCurImage,m_pGrayImage,WIDTH,HEIGHT);

	//累加图像
	GetMultiData(m_pGrayImage,WIDTH,HEIGHT);
	
	if(m_nFrame>BACK_ALL_NUM)
	{
		if(m_nFrame==(BACK_ALL_NUM+1))
		{
			//获得背景
			GetBgImage();
			memset(m_pTemplate,0,IMAGESIZE*sizeof(UINT));
			count = 0;
		}
		else if(m_nFrame%(2*BACK_ALL_NUM)==1) //更新背景图像
		{
			GetBgImage();
			memset(m_pTemplate,0,IMAGESIZE*sizeof(UINT));
			count = 0;
		}

		//差分图像
		DiffImage(m_pGrayImage,m_pBackground,WIDTH,HEIGHT,THRESHOLD);

	}
	
}

/************************************************************************
* 函数名称：
*     RGBToGray
*
* 参数：
*     BYTE *sRGB-输入RGB图像
*     BYTE *sGray-输出灰度图像
*     int nWidth-图像宽度
*     int nHeight-图像高度
*
* 说明：将RGB图像转换为灰度图像
************************************************************************/
void CStaticDetect::RGBToGray(BYTE *sRGB,BYTE *sGray,int nWidth, int nHeight)
{
	int i,j;
	for(j=0;j<nHeight;j++)
	{
		for(i=0;i<nWidth;i++)
		{
			sGray[nWidth*j+i]=(5*sRGB[3*(nWidth*j+i)]+3*sRGB[3*(nWidth*j+i)+1]+2*sRGB[3*(nWidth*j+i)+2])/10;
		}
	}

}

/************************************************************************
* 函数名称：
*     DiffImage
* 
* 参数：
*     BYTE *SGray-输入灰度图像
*     BYTE *pGray- 输入背景图像
*     int nWidth-图像宽度
*     int nHeight-图像高度
*     int nThreshold-阈值
*
* 说明：
*      差分图像检测目标
************************************************************************/
void CStaticDetect::DiffImage(BYTE *sGray,BYTE *pGray,int nWidth, int nHeight,int nThreshold)
{
	int i,j;
	for(j=0;j<nHeight;j++)
	{
		for(i=0;i<nWidth;i++)
		{
			int diff=sGray[j*nWidth+i]-pGray[nWidth*j+i];		
			if(diff>nThreshold||diff<-nThreshold)
			{
				m_pDiffImage[j*nWidth+i]=255;
			}
			else
			{
				m_pDiffImage[j*nWidth+i]=0;
			}
		}
	}
}

/************************************************************************
* 函数名称：
*     GetMultiData
* 
* 参数：
*     BYTE *sGray-输入图像
*     int nWidth-图像宽度
*     int nHeight-图像高度
*
* 说明：多帧累加
************************************************************************/
void CStaticDetect::GetMultiData(BYTE *sGray,int nWidth, int nHeight)
{
    count++;
	for(int j=0;j<nHeight;j++)
		for(int i=0;i<nWidth;i++)
			m_pTemplate[j*nWidth+i]+=sGray[j*nWidth+i];
}

/************************************************************************
* 函数名称：
*     GetBgImage
*
* 说明：获得背景图像
************************************************************************/
void CStaticDetect::GetBgImage()
{
	int i,j,t,pixel;
	for(j=0;j<HEIGHT;j++)
	{
		for(i=0;i<WIDTH;i++)
		{
			t = j*WIDTH+i;
			pixel = UINT(m_pTemplate[t]/count+0.5);
			if(pixel>255)
				m_pBackground[t] = BYTE(255);
			else if(pixel<0)
				m_pBackground[t] = BYTE(0);
			else
				m_pBackground[t] = BYTE(pixel);
		}
	}
}
