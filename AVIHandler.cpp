#include "StdAfx.h"
#include "AVIHandler.h"
#include <vfw.h>

#pragma comment(lib,"vfw32.lib")


AVIHandler::AVIHandler(void):gray_value(NULL),gray_value_square(NULL)
{
	this->loaded = FALSE;
}

AVIHandler::AVIHandler(CString filename):gray_value(NULL),gray_value_square(NULL)
{
	this ->loaded = FALSE;
	LoadVideo(filename);
}
AVIHandler::~AVIHandler(void)
{
	if(gray_value != NULL) free(gray_value);
	if(gray_value_square != NULL) free(gray_value_square);
}



//加载视频数据
BOOL AVIHandler::LoadVideo(CString filename)
{
		//读取AVI文件信息
	HRESULT result;
	AVIFileInit(); //使用AVI族函数读取AVI文件前应首先调用
	
	PAVIFILE pfile;//AVI文件指针
	AVIFILEINFO pfi;//AVI文件信息
	PAVISTREAM pavi;//AVI流
	AVISTREAMINFO stinfo;//AVI流信息
	
	//CString file = "d:\plane.avi";
	//打开AVI文件
	result=AVIFileOpen(&pfile,filename,OF_READ,NULL);
	//AVI文件信息
	result=AVIFileInfo(pfile,&pfi,sizeof(AVIFILEINFO));
	//获得AVI视频流
	result=AVIFileGetStream(pfile,&pavi,streamtypeVIDEO, 
		0);
	//获得AVI视频流信息
	result=AVIStreamInfo(pavi,&stinfo,sizeof(AVISTREAMINFO));
	//获得AVI包
	pgf = AVIStreamGetFrameOpen(pavi,NULL);
 
    if (pgf==NULL)
    {
		//数据出错
		return FALSE;
    }

	HRESULT hr;

	//获得特想的宽和高
	int cx=pfi.dwWidth;//图象宽、高
	int cy=pfi.dwHeight;
	
	width=cx;
	height=cy;
	length=pfi.dwLength;

	
	//使用默认长度，只处理100帧
	//length=50;

	//AVI桢格式，位图Header,位图具体格式。
	lpbm = (LPBITMAPINFOHEADER)AVIStreamGetFrame(pgf,1);
	
	defaultPad=3;

	//分配缓冲内存空间
	//非填充缓冲
	gray_value = (unsigned char*)malloc(sizeof(unsigned char)*width*height*3);
	//填充缓冲
	gray_value_square = (unsigned char*)malloc(sizeof(unsigned char)*(width+defaultPad)*(height+defaultPad)*3);

	this->loaded = TRUE;

	return TRUE;
}

//获得一个Frame
unsigned char* AVIHandler::GetSingleFrame(int i)
{
	return (unsigned char*)AVIStreamGetFrame(pgf,i)+40;
	//return NULL;
}

int AVIHandler::GetFrameCount(void)
{
	return this->length;
}


int AVIHandler::GetFrameWidth(void)
{
	return this->width;
	//return 0;
}


int AVIHandler::GetFrameHeight(void)
{
	return this->height;
	//return 0;
}

//返回图像的BMP格式数据
LPBITMAPINFOHEADER AVIHandler::GetLPBM(void)
{
	return this->lpbm;
}

BOOL AVIHandler::isLoaded(void)
{
	return this->loaded;
}
