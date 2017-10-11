#include "StdAfx.h"

#include "PhaseCorre.h"

#include "FourierTransform.h"

#define PI 3.1415926

//频谱位置转移
void FFT2Shiftd(double * FD,int w,int h){

	double * temp = new double[w*h];
	memcpy(temp,FD,sizeof(double)*w*h);  //数据转移


	for(int i = 0; i < h; i++)
	{
		// 列
		for(int j = 0; j < w; j=j+1)
		{
			double dataTemp = temp[w * i + j];
			//double dTemp = sqrt((double)FD[w * i * 3 + j*3].real() * FD[w * i * 3 + j*3].real() + 
			//	         FD[w * i * 3 + j*3].imag() * FD[w * i * 3 + j*3].imag()) / 50;
			
			// 指向DIB第(i<h/2 ? i+h/2 : i-h/2)行，第(j<w/2 ? j+w/2 : j-w/2)个象素的指针
			// 此处不直接取i和j，是为了将变换后的原点移到中心
			//lpSrc = (unsigned char*)lpDIBBits + lLineBytes * (lHeight - 1 - i) + j;
			double* lpSrc = (double*)FD + w * (h - 1 - (i < h / 2 ? i + h / 2: i - h/2)) + (j < w/2 ? j + w/2: j - w/2);
			//unsigned char* lpSrc = (unsigned char*)Y + lLineBytes * 
			//	(lHeight - 1 - (i<h/2 ? i+h/2 : i-h/2)) + (j<w/2 ? j+w/2 : j-w/2)*3;
			
			//数据输出
			*(lpSrc) = dataTemp;
			// 更新源图像
			//* (lpSrc) = (BYTE)(dTemp);
			//* (lpSrc+1) = (BYTE)(dTemp);
			//* (lpSrc+2) = (BYTE)(dTemp);
		}
	}

	delete temp;
}
//频谱位置转移
void FFT2Shift(complex<double> * FD,int w,int h){

	complex<double> * temp = new complex<double>[w*h];
	memcpy(temp,FD,sizeof(complex<double>)*w*h);  //数据转移


	for(int i = 0; i < h; i++)
	{
		// 列
		for(int j = 0; j < w; j=j++)
		{
			complex<double> dataTemp = temp[w * i + j];
			//double dTemp = sqrt((double)FD[w * i * 3 + j*3].real() * FD[w * i * 3 + j*3].real() + 
			//	         FD[w * i * 3 + j*3].imag() * FD[w * i * 3 + j*3].imag()) / 50;
			
			// 指向DIB第(i<h/2 ? i+h/2 : i-h/2)行，第(j<w/2 ? j+w/2 : j-w/2)个象素的指针
			// 此处不直接取i和j，是为了将变换后的原点移到中心
			//lpSrc = (unsigned char*)lpDIBBits + lLineBytes * (lHeight - 1 - i) + j;
			complex<double>* lpSrc = (complex<double>*)FD + w * (h - 1 - (i<h/2 ? i+h/2:i-h/2)) + (j < w/2 ? j + w/2: j - w/2);
			//unsigned char* lpSrc = (unsigned char*)Y + lLineBytes * 
			//	(lHeight - 1 - (i<h/2 ? i+h/2 : i-h/2)) + (j<w/2 ? j+w/2 : j-w/2)*3;
			
			//数据输出
			*(lpSrc) = dataTemp;
			// 更新源图像
			//* (lpSrc) = (BYTE)(dTemp);
			//* (lpSrc+1) = (BYTE)(dTemp);
			//* (lpSrc+2) = (BYTE)(dTemp);
		}
	}

	delete temp;
}


/**********************************************************
* 函数名：
*     PhaseCorrelation
* 参数：
*     unsigned char * aRegion-图像A
*     unsigned char * bRegion-图像B
*     int dWidth-图像宽度
*     int dHeight-图像高度
*     int *xpos-返回x方向位移
*     int *ypos-返回y方向位移
*
* 说明：
*     该函数利用相位相关方法对两幅图像进行配准，返回的脉冲位置就是相对平移量数值
************************************************************/
void PhaseCorrelation(unsigned char * aRegion ,unsigned char *bRegion,int dWidth,int dHeight,int *xpos,int *ypos)
{
	//频域数据
	complex<double> *aFD= new complex<double>[dWidth * dHeight];
	complex<double> *bFD= new complex<double>[dWidth * dHeight];

	FourierTransform ft;

	ft.ImageFourier(aRegion,dWidth,dHeight,aFD,1); //图像A的傅里叶变换函数
	ft.ImageFourier(bRegion,dWidth,dHeight,bFD,1); //图像B的傅里叶变换函数

	FFT2Shift(aFD,dWidth,dHeight); //
	FFT2Shift(bFD,dWidth,dHeight); //

	//相位相关
	complex<double> *gFD= new complex<double>[dWidth * dHeight];
	
	int i;
	for(i = 0; i < dHeight ; i++){
		for(int j = 0; j < dWidth ; j ++){
			complex<double> temp =aFD[i * dWidth + j] * complex<double>(bFD[i * dWidth +j].real(),-bFD[i * dWidth + j].imag());
			gFD[i * dWidth + j] = temp/abs(temp);
		}
	}
	//傅里叶变换后信息的内存处理
	delete[] aFD;
	delete[] bFD;

	//逆傅里叶变换
	double * gTD = (double*)malloc(sizeof(double)*dWidth*dHeight);
	ft.IFourier(gTD, dWidth, dHeight, gFD,1);
	delete[] gFD; //相位相关频谱内存释放
	FFT2Shiftd(gTD,dWidth,dHeight);

	//搜索脉冲峰值
	double max = -1000;
	*xpos = 0,*ypos = 0;
	for(i = 0; i<dHeight ; i++){
		for(int j = 0; j<dWidth; j ++){

			if(gTD[i * dWidth + j] > max){
				max = gTD[i * dWidth + j];
				*xpos = j;
				*ypos = i;
			}
		}
	}

	//相位相关频谱逆变换图像内存释放
	free(gTD);	
}

/***********************************************************************
* 函数名称：
*     PhaseAngleDiff
*
* 函数参数：
*     unsigned char * image1-图像1
*     unsigned char * image2-图像2
*     int imgWidth-图像宽度
*     int imgHeight-图像高度
* 说明：
*     使用相角差方法的运动矢量检测
***********************************************************************/
void PhaseAngleDiff(unsigned char * image1,unsigned char * image2, int imgWidth,int imgHeight)
{
	//频域信息
	complex<double> *aFD= new complex<double>[imgWidth * imgHeight];
	complex<double> *bFD= new complex<double>[imgWidth * imgHeight];

	FourierTransform ft;

	//对图像进行傅里叶变换
	ft.ImageFourier(image1,imgWidth,imgHeight,aFD,1); // 图像1傅里叶变换
	FFT2Shift(aFD,imgWidth,imgHeight);  // 移动频谱
	ft.ImageFourier(image2,imgWidth,imgHeight,bFD,1); // 图像2傅里叶变换
	FFT2Shift(bFD,imgWidth,imgHeight);	// 移动频谱

	//求相角差
	float angle1,angle2;
	float *diff = new float[imgWidth * imgHeight]; // 相角差
	int i = 0;
	for(i = 0 ; i < imgWidth * imgHeight; i ++){
		angle1 = atan2(aFD[i].imag(),aFD[i].real());
		angle2 = atan2(bFD[i].imag(),bFD[i].real());
		int n = floor(angle1 / (2 * PI));
		diff[i] = angle2 - (angle1 - n * 2 * PI);
		n = floor(diff[i] / (2 * PI));
		diff[i] = diff[i] - n * 2 * PI;
	}
	delete[] aFD,bFD;  //释放频域数据
	float *xline = new float[imgWidth];
	float *yline = new float[imgHeight];
	//在x方向映射相角差
	for(i = 0; i < imgWidth ; i++)
	{
		xline[i] = diff[(imgHeight / 2) * imgWidth + i];
	}
	//在y方向映射相角差
	for(i = 0; i < imgHeight ; i++)
	{
		yline[i] = diff[i * imgWidth + imgWidth / 2];
	}
	delete[] diff;
	float currcx = 0;
	float currcy = 0;
	//unwrap后输出数据
	float *xlinew = new float[imgWidth];
	float *ylinew = new float[imgHeight];
	//同时对x和y方向映射的相角差进行unwrap
	int winWidth = 20; //信息窗口大小
	for(i = imgWidth / 2 - winWidth ;i < imgWidth / 2 + winWidth; i ++)
	{
		if(abs(xline[i] - (xline[i - 1])) > 6.0){
			if(xline[i] - (xline[i - 1]) > 0){
			 currcx -= 2 * PI;
			}else
				currcx += 2 * PI;
		}
		if(abs(yline[i] - (yline[i - 1])) > 6.0){
			if(yline[i] - (yline[i - 1]) > 0){
				currcy -= 2 * PI;
			}else
				currcy += 2 * PI;
		}
		xlinew[i] = xline[i] + currcx;
		ylinew[i] = yline[i] + currcy;
	}
	delete[] xline,yline;

	float xvar = 0,yvar = 0; 
	CString str;
	xvar = xlinew[imgWidth / 2 - winWidth];// + fabs(6.0 - (int)xlinew[imgWidth / 2 + winWidth - 1]);
	yvar = ylinew[imgWidth / 2 - winWidth];// + fabs(6.0 - (int)ylinew[imgWidth / 2 + winWidth - 1]);
	
	str.Format(_T("相对于第一幅图像\n x方向移动为%d，y方向移动为%d。"),int(xvar+0.5),int(yvar+0.5));
	CString temp;
	for(i = imgWidth / 2 - winWidth ;i < imgWidth / 2 + winWidth; i ++)
	{
		//temp.Format(_T("(%f %f)\n"),xlinew[i],ylinew[i]);
		//str.Insert(str.GetLength(),temp.GetBuffer(temp.GetLength()));
		TRACE("%f %f;\n",xlinew[i],ylinew[i]);
	}
	AfxMessageBox(str.GetBuffer(str.GetLength()));

	//对ylinew和xline求最小二乘拟合，求斜率
	//程序略	
	delete[] xlinew,ylinew; 
}
