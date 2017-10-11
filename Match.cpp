#include "stdafx.h"
#include "Match.h"
#include "math.h"
Match::Match()
{

	m_nColorTableLengthOut=0;
    m_nBitCountOut=0;
	m_pImgDataOut=NULL;
	m_lpColorTableOut=NULL;
    m_imgWidthOut=0;
	m_imgHeightOut=0;
	
}

Match::Match(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData):
ImgCenterDib(size, nBitCount, lpColorTable, pImgData)
{

    m_nBitCountOut=0;
	m_pImgDataOut=NULL;
	m_lpColorTableOut=NULL;
	m_nColorTableLengthOut=0;
	m_imgWidthOut=0;
	m_imgHeightOut=0;
}

Match::~Match()
{
	if(m_pImgDataOut!=NULL){
		delete []m_pImgDataOut;
    	m_pImgDataOut=NULL;
	}
	if(m_lpColorTableOut==NULL){
		delete []m_lpColorTableOut;
		m_lpColorTableOut=NULL;
	}
}

CSize Match::GetDimensions()
{	
	if(m_pImgDataOut == NULL) return CSize(0, 0);
	return CSize(m_imgWidthOut, m_imgHeightOut);
}


//空域相关匹配函数
CPoint Match::matchBasedSpacial(unsigned char *imgBuf, int width, int height, int pixelByte,
										unsigned char * blockBuf, int blockW, int blockH)
{

	//图像每行像素的字节数
	int lineByte=(width*pixelByte+3)/4*4;
	//标准图像每行字节数
	int blockLineByte=(blockW*pixelByte+3)/4*4;

	//循环变量，基准图坐标
	int i, j;

	//循环变量，标准图坐标（待搜索的小图像）
	int i0, j0, k;

	//中间变量，每搜索一个位置记录该位置上基准图与标准图之间的相关性测度
	//本函数用两像素之差绝对值并求和作为相关性测度，所以sum值最小的位置为最佳匹配位置
	int sum;

	//用min记录具有最小sum的值, 
	int min;
	//具有最小sum的位置
	int minX, minY;

	//中间变量
	int t1, t2;

	//列搜索最大为height-blockH，行搜索最大为width-blockW，由块数据大小决定
	//超过部分不能再有相关数据了；为了节省时间，此处行方向和纵方向搜索步长为3，
	//读者可以根据需要自己调整步长，或者做为函数参数进行设置
	for(i=0;i<height-blockH;i+=3){
		for(j=0;j<width-blockW; j+=3){
			sum=0;

			//针对(i,j)匹配位置，搜索区域内的像素，为节省空间，
			//此处(i0,j0)的搜索步长也可以视情况和需要来定
			for(i0=0;i0<blockH;i0++){
				for(j0=0;j0<blockW;j0++){
					
					//每个通道数据对应相减，并计算绝对值之和，对于灰度图像即是对应像素灰度值相减，
					// 对于彩色图像，此处为三个通道对应相减
					for(k=0;k<pixelByte;k++){
						//当前参考图上对应像素第k个通道数据
						t1=*(imgBuf+(i+i0)*lineByte+(j+j0)*pixelByte+k);

						//当前基准图上对应像素第k个通道数据
						t2=*(blockBuf+i0*blockLineByte+j0*pixelByte+k);

						//差的绝对值之和
						sum += abs(t1-t2);

					}
				}
			}
			
			//第一个搜索区域，此时也是最小sum值的位置
			if(i==0&&j==0){
				min=sum;
				minX=0;
				minY=0;
			}
			else{//已经不是第一个搜索位置了
				if(min>sum){//出现一个新的最小位置，记录此时的最小值及其位置坐标
					min=sum;
					minX=j;
					minY=i;
				}
			}

		}
	}

	//返回匹配位置
	CPoint pos(minX,minY);
	return pos;
}

//
void Match::matchResult(LPCTSTR  cankaoImgPath, LPCTSTR jizhunImgPath,  int matchStyle)
{
	//读入基准图，该函数是基类ImgCenterDib中的函数成员，实现过程在xfyDib.cpp文件中
	//该函数调用后，m_pImgData, m_imgWidth, m_imgHeight存放的是基准图数据
	Read(jizhunImgPath);

	//基准图数据变量
	int blockBitCount=m_nBitCount;
	int blockW=m_imgWidth;
	int blockH=m_imgHeight;

	//基准图每行像素字节数
	int blockLineByte=(blockW*blockBitCount/8+3)/4*4;

	//申请空间存放基准图图像数据
	unsigned char *blockBuf=new unsigned char[blockLineByte*blockH];
	memcpy(blockBuf, m_pImgData, blockLineByte*blockH);

	//读入参考图，该函数调用后，m_pImgData, m_imgWidth, m_imgHeight存放的是参考图图像数据
	Read(cankaoImgPath);

	//基准图与参考图图像格式不统一
	if(m_nBitCount!=blockBitCount){
		//释放空间
		delete []blockBuf;
		//返回
		return;
	}

	//每像素字节数
	int pixelByte=m_nBitCount/8;

	//匹配位置变量
	CPoint macthPos;
		macthPos.x=0;
	macthPos.y=0;

	if(matchStyle==0)  //空间相关匹配
		macthPos=matchBasedSpacial(m_pImgData, m_imgWidth, m_imgHeight, pixelByte,
										blockBuf, blockW, blockH);
/*	else if(matchStyle==1)//频域匹配
此处要加上相位匹配和角点匹配

*/

	if(m_pImgDataOut!=NULL){
		delete []m_pImgDataOut;
    	m_pImgDataOut=NULL;
	}

	//输出图像与输入图像为同一类型,此处为灰度类型
	m_nBitCountOut=m_nBitCount;
	m_nColorTableLengthOut=ComputeColorTabalLength(m_nBitCountOut);
	if(m_nColorTableLengthOut!=0){
    	m_lpColorTableOut=new RGBQUAD[m_nColorTableLengthOut];
		memcpy(m_lpColorTableOut,m_lpColorTable,sizeof(RGBQUAD)*m_nColorTableLengthOut);
	}

	//输出图像的宽高，与参考图大小相同
	m_imgWidthOut=m_imgWidth;
	m_imgHeightOut=m_imgHeight;

	// 参考图每行像素字节数
	int lineByte=(m_imgWidth*blockBitCount/8+3)/4*4;
	m_pImgDataOut=new unsigned char[lineByte*m_imgHeightOut];

	memcpy( m_pImgDataOut,m_pImgData, lineByte*m_imgHeightOut);

	//将基准图的位置画在参考图中，以显示匹配结果的正确性

	//两个循环变量
	int i, k;

	//将基准图上下边界在参考图对应行的像素置黑色，即每个通道赋0
	for(i=0;i<blockW;i++){
		for(k=0;k<pixelByte; k++){
			*(m_pImgDataOut+(macthPos.y+0)*lineByte+(macthPos.x+i)*pixelByte+k)=0;
		}
		for(k=0;k<pixelByte; k++){
			*(m_pImgDataOut+(macthPos.y+blockH-1)*lineByte+(macthPos.x+i)*pixelByte+k)=0;
		}
	}

	//将基准图左右边界在参考图对应列的像素置黑色，即每个通道赋0
	for(i=0;i<blockH;i++){
		for(k=0;k<pixelByte; k++){
			*(m_pImgDataOut+(macthPos.y+i)*lineByte+(macthPos.x+0)*pixelByte+k)=0;
		}
		for(k=0;k<pixelByte; k++){
			*(m_pImgDataOut+(macthPos.y+i)*lineByte+(macthPos.x+blockW)*pixelByte+k)=0;
		}
	}

	//清除空间
	 delete []blockBuf;

}
