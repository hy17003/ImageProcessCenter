#ifndef _INSIDE_VISUAL_CPP_GeometryTrans
#define _INSIDE_VISUAL_CPP_GeometryTrans
#include "ImageCenterDib.h"

//几何变换类
class GeometryTrans:public ImgCenterDib
{
public:
    //输出图像每像素位数
	int m_nBitCountOut;

	//输出图像位图数据指针
	unsigned char * m_pImgDataOut;

	//输出图像颜色表
	LPRGBQUAD m_lpColorTableOut;
private:
	//输出图像的宽
	int m_imgWidthOut;

	//输出图像的高
	int m_imgHeightOut;

	//输出图像颜色表长度
	int m_nColorTableLengthOut;

public:
	//构造函数
	GeometryTrans();

	//带参数的构造函数
	GeometryTrans(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData);

	//析构函数
	~GeometryTrans();

	//以像素为单位返回输出图像的宽和高
	CSize GetDimensions();

	//平移
	void Move(int offsetX, int offsetY);

	//水平镜像
	void MirrorHori();

	//垂直镜像
	void MirrorVerti();

	//转置
	void ZhuanZhi();
	
	//顺时针旋转90度
	void Clockwise90();

	//逆时针旋转90度
	void Anticlockwise90();

	//旋转180
	void Rotate180();

	//旋转 
	void Rotate(int angle, int interpolationflag);//angle旋转角度

	//缩放
	void Zoom(int zoomWidthPixel, int zoomHeightPixel, int interpolationflag);//缩放

private:
	//双线性插值
	unsigned char interpolationDblLinear(unsigned char array[2][2], float xpos, float ypos);

	//立方卷积插值
	unsigned char interpolationCube(unsigned char array[4][4], float xpos, float ypos);


	//近邻插值缩放
    void ZoomNeighbor(unsigned char *pImgIn, int widthIn, int heightIn, int biBitCount,
										 unsigned char *pImgOut, int widthOut, int heightOut);
	//双线性插值缩放
	void ZoomDblLinear(unsigned char *pImgIn, int widthIn, int heightIn, int biBitCount,
										 unsigned char *pImgOut, int widthOut, int heightOut);

	//立方卷积插值缩放
	void ZoomCube(unsigned char *pImgIn, int widthIn, int heightIn, int biBitCount,
										 unsigned char *pImgOut, int widthOut, int heightOut);

	//近邻插值旋转
	void RotateNeighbor(int angle);

	//双线性插值旋转
	void RotateDblLinear(int angle);

	//立方卷积插值旋转
	void RotateCube(int angle);
};
#endif // _INSIDE_VISUAL_CPP_GeometryTrans