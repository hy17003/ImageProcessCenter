#include "stdafx.h"
#include "Watershed.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/***********************************************************************
* 函数名称：
* Watershed()
*
*说明：无参数的构造函数，对成员变量进行初始化
***********************************************************************/
Watershed::Watershed()
{
	m_pImgDataOut=NULL;//输出图像位图数据指针为空

	m_lpColorTableOut=NULL;//输出图像颜色表指针为空
	
	m_nColorTableLengthOut=0;//输出图像颜色表长度为0

    m_nBitCountOut=0;//输出图像每像素位数为0	

	m_imgWidthOut=0;//输出图像的宽为0

	m_imgHeightOut=0;//输出图像的高为0

	//队列缓冲区长度，没调用watershed前不申请队列缓冲区
	queueLng=0;

	objectCount=0;//分类目标数置0
}

/***********************************************************************
* 函数名称：
* Watershed()
*
*函数参数：
*  CSize size -图像大小（宽、高）
*  int nBitCount  -每像素所占位数
*  LPRGBQUAD lpColorTable  -颜色表指针
*  unsigned char *pImgData  -位图数据指针
*
*返回值：
*   无
*
*说明：本函数为带参数的构造函数，给定位图的大小、每像素位数、颜色表
*      及位图数据，调用ImgCenterDib()对基类成员初始化，并初始化派生类的
*      数据成员
***********************************************************************/
Watershed::Watershed(CSize size, int nBitCount, LPRGBQUAD lpColorTable, 
					 unsigned char *pImgData):
          ImgCenterDib(size, nBitCount, lpColorTable, pImgData)
{
	m_pImgDataOut=NULL;//输出图像位图数据指针为空

	m_lpColorTableOut=NULL;//输出图像颜色表指针为空
	
	m_nColorTableLengthOut=0;//输出图像颜色表长度为0

    m_nBitCountOut=0;//输出图像每像素位数为0	

	m_imgWidthOut=0;//输出图像的宽为0

	m_imgHeightOut=0;//输出图像的高为0

	//队列缓冲区长度，没调用watershed前不申请队列缓冲区
	queueLng=0;

	objectCount=0;//分类目标数置0
}


/***********************************************************************
* 函数名称：
*   ~Watershed()
*
*说明：析构函数，释放资源
***********************************************************************/
Watershed::~Watershed()
{
	//释放输出图像及其颜色表缓冲区
	if(m_pImgDataOut!=NULL){
		delete []m_pImgDataOut;
    	m_pImgDataOut=NULL;
	}
	if(m_lpColorTableOut==NULL){
		delete []m_lpColorTableOut;
		m_lpColorTableOut=NULL;
	}
	//释放队列缓冲区
	if(queueLng!=0){
		//循环变量，数组下标
		int i,j;
		//清除队列缓冲区
		for(i=0; i<256;i++){
			for(j=0;j<4;j++){
				delete []queue[i][j];
			}
		}

	}
	
}

/***********************************************************************
* 函数名称：
* GetDimensions()
*
*函数参数：
*  无
*
*返回值：
*   图像的尺寸，用CSize类型表达
*
*说明：返回输出图像的宽和高
***********************************************************************/
CSize Watershed::GetDimensions()
{	
	if(m_pImgDataOut == NULL) return CSize(0, 0);
	return CSize(m_imgWidthOut, m_imgHeightOut);
}

/***********************************************************************
* 函数名称：
* Pop()
*
*函数参数：
*  int gradient  -出队元素的灰度值，gradient行的队列
*  int mark  -出队元素的标记，mark列的队列
*  CPoint* pPopPoint  -出队元素的坐标指针
*
*返回值：
*  无
*
*说明：一共有256*4个队列，队列中每一个元素是一个CPoint类型的量，用来存放
*      图像像素的坐标，该函数使第gradient行mark列的队列出队一个元素，元素坐标
*      在指针pPopPoint中返回
***********************************************************************/
void Watershed::Pop(int gradient,int mark,CPoint* pPopPoint)
{
	//第gradient灰度级标记为mark的队列的队头
	int top=headPointer[gradient][mark];

	//第gradient灰度级标记为mark的队列的队头出队
	pPopPoint->x=(queue[gradient][mark]+top)->x;
	pPopPoint->y=(queue[gradient][mark]+top)->y;

	//第gradient灰度级标记为mark的队列的队尾
	int tail=tailPointer[gradient][mark];

	//如果队头指针和队尾相遇，则队列空
	if(top==tail){
		headPointer[gradient][mark]=0;
		tailPointer[gradient][mark]=-1;
	}
	else{//否则，队头指针累加
		headPointer[gradient][mark] += 1;
		//循环队列，每次进队要作求模处理
		headPointer[gradient][mark] = headPointer[gradient][mark]%queueLng;
	}
	
}

/***********************************************************************
* 函数名称：
* Push()
*
*函数参数：
*  int gradient  -进队元素的灰度值，gradient行的队列
*  int mark  -进队元素的标记，mark列的队列
*  CPoint pushPoint  -进队元素的坐标
*
*返回值：
*  无
*
*说明：一共有256*4个队列，队列中每一个元素是一个CPoint类型的量，用来存放
*      图像像素的坐标，该函数使第gradient行mark列的队列进队一个元素，元素坐标
*      为pushPoint的值
***********************************************************************/
void Watershed::Push(int gradient,int mark,CPoint pushPoint)
{
	//队尾指针加1
	tailPointer[gradient][mark] +=1;

	//对该队列求模处理
	tailPointer[gradient][mark]=tailPointer[gradient][mark]%queueLng;

	//中间变量，队尾指针
	int tail=tailPointer[gradient][mark];

	//新元素进队
	(queue[gradient][mark]+tail)->x=pushPoint.x;
	(queue[gradient][mark]+tail)->y=pushPoint.y;
}

/***********************************************************************
* 函数名称：
* IsEmpty()
*
*函数参数：
*  int gradient  -gradient行的队列
*  int mark  -mark列的队列
*
*返回值：
*   1代表真，0代表假
*
*说明：判断第gradient行mark列的队列是否为空，若返回值为1则队列空，否则不空
***********************************************************************/
bool Watershed::IsEmpty(int gradient,int mark) 
{	
	if(tailPointer[gradient][mark]==-1)
	    return true;
	else return false;
}

/***********************************************************************
* 函数名称：
* IsOverflow()
*
*函数参数：
*  int gradient  -gradient行的队列
*  int mark  -mark列的队列
*
*返回值：
*   1代表真，0代表假
*
*说明：判断第gradient行mark列的队列是否满，若返回值为1则队列满，否则不满
***********************************************************************/
bool Watershed::IsOverflow(int gradient,int mark) 
{
	//队头指针
	int head=headPointer[gradient][mark];
	
	//队尾元素指针加1
	int tail=(tailPointer[gradient][mark]+1)%queueLng;

	if(tailPointer[gradient][mark]!=-1 && tail==head)
	    return true;
	else return false;
}

/***********************************************************************
* 函数名称：
* InitQueue()
*
*函数参数：
*  unsigned char* pGradient -图像的梯度图
*  unsigned char* pMarker  -图像的标记图
*  int width  -图像的宽
*  int height  -图像的高
*
*返回值：
*   无
*
*说明：给定梯度图和标记图，对队列进行初始化
***********************************************************************/
void Watershed::InitQueue(unsigned char* pGradient, unsigned char* pMarker, 
						  int width,int height)
{
	//每行像素字节数
	int linebyte=(width+3)/4*4;

	//循环变量
	int i,j,k;

	//二维数组direct代表8邻域坐标与中心像素点在x和y方向上的偏移,
	//其中第一列为x方向的偏移,第二列为y方向的偏移
	int direct[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

	//中间变量，灰度值和标记
	int gradient, mark;

	//要进队的元素
	CPoint pushPoint;

	//初始化队头和队尾指针
	for(i=0;i<256;i++){
		for(j=0;j<=objectCount;j++){
			tailPointer[i][j]=-1;
			headPointer[i][j]=0;
		}
	}

	//当前处理像素的邻域点
	CPoint neighborPoint;
	for(i=0;i<height;i++){//图像边缘不处理
		for(j=0;j<width;j++){
			mark=pMarker[i*linebyte+j];
			if(mark!=0){//找到一个标记点			
				for(k=0;k<8;k++){
					neighborPoint.x=j+direct[k][0];
					neighborPoint.y=i+direct[k][1];

					//不在图像范围内的点，跳过
					if(neighborPoint.x<0||neighborPoint.x>width-1
						||neighborPoint.y<0||neighborPoint.y>height-1)
						continue;

					//该标记点是该区域的边缘点，则进队
					if(*(pMarker+ neighborPoint.y*linebyte+neighborPoint.x)==0||
						*(pMarker+ neighborPoint.y*linebyte+neighborPoint.x)!=mark){
						gradient=*(pGradient+ i*linebyte+j);
						
						if(IsOverflow(gradient,mark)){
							CString str;
							str.Format(_T("%d"),gradient);
							CString str1=_T("第")+ str + _T("个队溢出！");
							::MessageBox(0,str1,MB_OK,0);
							return;
						}
						else {
							pushPoint.x=j;
							pushPoint.y=i;
							Push(gradient,mark,pushPoint);
						}
						
						break;
					}
				}
			
			}//if end
		}//for(j)  end
	}//for(i) end
}

/***********************************************************************
* 函数名称：
* WatershedTrans()
*
*函数参数：
*  unsigned char* pGradient -图像的梯度图
*  unsigned char* pMarker  -图像的标记图
*  int width  -图像的宽
*  int height  -图像的高
*  bool flag_contour  -标志变量，1代表在不同类目标间加上分水岭线(叠坝)，0代表不加
*
*返回值：
*   无
*
*说明：给定梯度图和标记图，对图像进行水域生长，生长结果存入标记图pMarker中
***********************************************************************/
void Watershed::WatershedTrans(unsigned char* pGradient, unsigned char* pMarker, 
						  int width,int height,bool flag_contour)
{
	//每行像素字节数
	int linebyte=(width+3)/4*4;

	//循环变量，图像的坐标
	int i,j;

	//二维数组direct代表8邻域坐标与中心像素点在x和y方向上的偏移,
	//其中第一列为x方向的偏移,第二列为y方向的偏移
	int direct[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

	// 循环变量，direct数组8邻域下标（第1维）
	int k;

	//进队点、出队点和当前处理像素的邻域点
	CPoint pushPoint,popPoint, neighborPoint;

	//标志变量，1代表当前像素点是目标的轮廓点，否则不是
	bool contourFlg;

	//标志变量，1代表当前像素点是所处生长区域的边缘但不一定是所在目标的轮廓，
	//否则不是
	bool edgeFlg;

	//初始化队列
	InitQueue(pGradient,pMarker,width,height);

	//像素的灰度值和标记
	int gradient, mark;
	
	//记录当前找到的要进队的点灰值
	int minGradient;

	//水域生长
	for(i=0;i<256;i++){
		for(j=0;j<objectCount+1;j++){
			while(!IsEmpty(i,j)){
				//出队一个元素
				Pop(i,j,&popPoint);
				minGradient=256;
				pushPoint.x=-1;
				pushPoint.y=-1;
				for(k=0;k<8;k++){ 
					neighborPoint.x=popPoint.x+direct[k][0];
					neighborPoint.y=popPoint.y+direct[k][1];

					//邻域点不在图像内，则跳过
					if(neighborPoint.y<0||neighborPoint.y>height-1
						||neighborPoint.x<0||neighborPoint.x>width-1)
						continue;

					mark=*(pMarker+neighborPoint.y*linebyte+neighborPoint.x);
					if(mark==0){
						gradient=*(pGradient+neighborPoint.y*linebyte+neighborPoint.x);
						if(gradient<minGradient){
							minGradient=gradient;
							pushPoint.x=neighborPoint.x;
							pushPoint.y=neighborPoint.y;
						}
					}
					
				} //for(k) end
				
				//处理待进队的新点
				if(pushPoint.x!=-1&&pushPoint.y!=-1){
					*(pMarker+pushPoint.y*linebyte+pushPoint.x)=j;
					edgeFlg=0;
					contourFlg=0;

					//判断该新点是否边缘点或轮廓点
					for(k=0;k<8;k++){
						neighborPoint.x=pushPoint.x+direct[k][0];
						neighborPoint.y=pushPoint.y+direct[k][1];

						//邻域点不在图像内，则跳过
						if(neighborPoint.y<0||neighborPoint.y>height-1
							||neighborPoint.x<0||neighborPoint.x>width-1)
							continue;

						mark=*(pMarker+neighborPoint.y*linebyte+neighborPoint.x);
						if( mark==0  ){
							edgeFlg=1;							
						}	
						if(  mark!=j && mark!=objectCount+1 &&mark!=0){
							contourFlg=1;
						}
					}
					if(flag_contour){//不同类间加分水岭线的标志(叠坝)
						if(contourFlg) 
							*(pMarker+pushPoint.y*width+pushPoint.x)=objectCount+1;
					}
					if(edgeFlg){										
						if(minGradient<i){
							if(IsOverflow(i,j)){
								CString str;
								str.Format(_T("%d"),minGradient);
								CString str1=_T("第")+ str + _T("个队溢出！");
								::MessageBox(0,str1,MB_OK,0);
								return;
							}
							
							Push(i,j,pushPoint);
						}					
						else{
							if(IsOverflow(minGradient,j)){
								CString str;
								str.Format(_T("%d"),minGradient);
								CString str1=_T("第")+ str + _T("个队溢出！");
								::MessageBox(0,str1,MB_OK,0);
								return;
							}
							Push(minGradient,j,pushPoint);
							
						}	
					}
				}

				//处理刚才出队的点，若该点仍然是边缘点，则重新进队
				edgeFlg=0;
				contourFlg=0;

				//判断被弹出点是否边缘点且非轮廓
				for(k=0;k<8;k++){
					neighborPoint.x=popPoint.x+direct[k][0];
					neighborPoint.y=popPoint.y+direct[k][1];

					//邻域点不在图像范围内，则跳过
					if(neighborPoint.y<0||neighborPoint.y>height-1
						||neighborPoint.x<0||neighborPoint.x>width-1)
						continue;
					mark=*(pMarker+neighborPoint.y*linebyte+neighborPoint.x);
					if( mark==0  ){
						edgeFlg=1;
					}
					if(  mark!=j && mark!=objectCount+1 &&mark!=0){
						contourFlg=1;
					}
				}				
				
				if(flag_contour){//不同类间加分水岭线的标志(叠坝)
					if(contourFlg) //轮廓线标志
						*(pMarker+popPoint.y*linebyte+popPoint.x)=objectCount+1;						
				}
				if(edgeFlg){				
					if(IsOverflow(i,j)){
						CString str;
						str.Format(_T("%d"),minGradient);
						CString str1=_T("第")+ str + _T("个队溢出！");
						::MessageBox(0,str1,MB_OK,0);
						return;
					}
					Push(i,j,popPoint);
				}
				
				
			}//while end
			
		}// for(j) end

	}//for(i) end

}

/***********************************************************************
* 函数名称：
* GenerateMarkerByPos()
*
*函数参数：
*  unsigned char* pMarker  -图像的标记图
*  int width  -图像的宽
*  int height  -图像的高
*  CPoint position[]   -指定种子点数组
*  int objectCount   -分类数
*
*返回值：
*   无
*
*说明：给定种子点数组position及分类数objectCount，产生标记图pMarker
***********************************************************************/
void Watershed::GenerateMarkerByPos(unsigned char* pMarker, int width,
							int height, CPoint position[], int objectCount)
{
	//每行像素字节数
	int linebyte=(width+3)/4*4;

	//初始化标记图置0，0代表未作标记的点(等待生长的点)
	memset(pMarker, 0, linebyte*height);

	//循环变量
	int k;
	//将第k个指定点置成标记k，
	for(k=0;k<objectCount;k++){
		*(pMarker+position[k].y*linebyte+position[k].x)=k+1;
	}
}

/***********************************************************************
* 函数名称：
* Sobel()
*
*函数参数：
*  unsigned char* imgBuf  -图像数据
*  int width  -图像的宽
*  int height  -图像的高
*  unsigned char *gradient  -梯度图
*
*返回值：
*   无
*
*说明：给定图像数据，进行sobel变换，得到的梯度图存入gradient缓冲区，此处
*      没有调用前面ImgSegment类中的Sobel()，是为了Watershed类的集成性，便
*      于代码移植
***********************************************************************/
void Watershed::Sobel(unsigned char *imgBuf, int width, int height,
					  unsigned char *gradient)
{
	//每行像素字节数
	int linebyte=(width+3)/4*4;

	//梯度图像缓冲区初始化置0。
	memset(gradient, 0, linebyte*height);

	//循环变量，图像的坐标
	int i, j;

	//中间变量
	int x, y, t;

	for(i=1;i<height-1; i++){
		for(j=1; j<width-1; j++){
			//x方向梯度
			x=*(imgBuf+(i+1)*linebyte+j-1)+2**(imgBuf+(i+1)*linebyte+j)
				+*(imgBuf+(i+1)*linebyte+j+1) -*(imgBuf+(i-1)*linebyte+j-1)
				-2**(imgBuf+(i-1)*linebyte+j)-*(imgBuf+(i-1)*linebyte+j+1);

			//y方向梯度
			y=*(imgBuf+(i+1)*linebyte+j-1)+2**(imgBuf+i*linebyte+j-1)
				+*(imgBuf+(i-1)*linebyte+j)-*(imgBuf+(i+1)*linebyte+j+1)
				-2**(imgBuf+i*linebyte+j+1)-*(imgBuf+(i-1)*linebyte+j+1);

			//梯度
			t=sqrt((double)x*x+y*y);
			if(t>255) t=255;
			*(gradient+i*linebyte+j)=t;
		}
	}
}

/***********************************************************************
* 函数名称：
* WatershedSegment()
*
*函数参数：
*  CPoint position[]  -种子点数组
*  int classCount  -分类数
*  int contourFlg  -标志性变量，1为叠坝（加轮廓线），0为不叠坝（不加轮廓线）
*
*返回值：
*   无
*
*说明：给定种子点及分类数，对输入图像进行水域分割函数
***********************************************************************/
void Watershed::WatershedSegment(CPoint position[], int classCount, int contourFlg)
{
	//释放m_pImgDataOut指向的图像数据空间
	if(m_pImgDataOut!=NULL){
		delete []m_pImgDataOut;
    	m_pImgDataOut=NULL;
	}
	//释放颜色表空间
	if(m_lpColorTableOut!=NULL){
		delete []m_lpColorTableOut;
		m_lpColorTableOut=NULL;
	}

	//输出图像为标记图像的输出,此处为灰度类型
	m_nBitCountOut=m_nBitCount;
	m_nColorTableLengthOut=ComputeColorTabalLength(m_nBitCountOut);
	if(m_nColorTableLengthOut!=0){
    	m_lpColorTableOut=new RGBQUAD[m_nColorTableLengthOut];
		memcpy(m_lpColorTableOut,m_lpColorTable,
              sizeof(RGBQUAD)*m_nColorTableLengthOut);
	}

	//输出图像的宽高,与输入图像相等
	m_imgWidthOut=m_imgWidth;
	m_imgHeightOut=m_imgHeight;
	int lineByte=(m_imgWidth*m_nBitCountOut/8+3)/4*4;
	m_pImgDataOut=new unsigned char[lineByte*m_imgHeight];


	//queueLng表示队列的长度，为节省空间，其值为图像像素总数的1/16，实际处理中队
	//列最长还可能远远小于本程序设定的值，或者采用指针方式实现队列更为合理 
	queueLng=m_imgWidth*m_imgHeight/16;

	//标记数
	objectCount=classCount;

	//循环变量
	int i, j;

	//申请队列缓冲区
	for(i=0;i<256;i++){
		for(j=0;j<4;j++)
    		queue[i][j]=new CPoint[queueLng];

	}

	//通过指定点参数产生标记,此时m_pImgDataOut内是初始标记图
	GenerateMarkerByPos(m_pImgDataOut, m_imgWidth, m_imgHeight, 
		position, objectCount);


	//申请缓冲区，存放sobel变换梯度图
	unsigned char *sobelBuf=new unsigned char[lineByte*m_imgHeight];
	Sobel(m_pImgData, m_imgWidth, m_imgHeight, sobelBuf);

	//水域变换，变换后m_pImgDataOut内存放的是水域生长以后的标记图，即分割结果
	WatershedTrans(sobelBuf, m_pImgDataOut, m_imgWidth, m_imgHeight,contourFlg);

	//标记图按一定比例显示
	for(i=0;i<m_imgHeight;i++){
		for(j=0;j<m_imgWidth;j++){
			if(*(m_pImgDataOut+i*lineByte+j)==objectCount+1)
				*(m_pImgDataOut+i*lineByte+j)=255;
				else
	     		*(m_pImgDataOut+i*lineByte+j)= 
				(*(m_pImgDataOut+i*lineByte+j)-1)*255/objectCount;
		}
	}

	//清除梯度图缓冲区
	delete []sobelBuf;

	//清除队列缓冲区
	if(queueLng!=0){
		for(i=0;i<256;i++){
			for(j=0;j<4;j++){
				//释放队列缓冲区
				delete []queue[i][j];
			}
			
		}
		queueLng=0;
	}
}



/*
//用直方图方法生成标记图,threshInterval阈值段数组
void Watershed::calculateMarker(unsigned char* pImgBuf, unsigned char* pMarker, int width,int height, int threshInterval[], int objectCount)
{
	//每行像素字节数
	int linebyte=(width+3)/4*4;

	//初始化标记图置0，0代表未作标记的点(等待生长的点)
	memset(pMarker, 0, linebyte*height);
	
	//循环变量
	int i,j,k;
	unsigned char t;
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			for(k=0;k<objectCount;k++){
				//坐标为(i,j)像素的指针
				t=*(pImgBuf+i*linebyte+j);
				if(t>=threshInterval[k*2+0]  &&  t<threshInterval[k*2+1])//第k类目标灰度区间
					*(pMarker+i*linebyte+j)=k+1;
			}
		}
	}
	
}

void Watershed::WatershedSegment1(int threshInterval[], int classCount, int contourFlg)
{
	if(classCount<2||classCount>3){
		::MessageBox(0,_T("分类数只能是2或3"),MB_OK,0);
		return;
	}
	//释放m_pImgDataOut指向的图像数据空间
	if(m_pImgDataOut!=NULL){
		delete []m_pImgDataOut;
    	m_pImgDataOut=NULL;
	}
	//释放颜色表空间
	if(m_lpColorTableOut!=NULL){
		delete []m_lpColorTableOut;
		m_lpColorTableOut=NULL;
	}

	//输出图像为标记图象的输出,此处为灰度类型
	m_nBitCountOut=8;
	m_nColorTableLengthOut=ComputeColorTabalLength(m_nBitCountOut);
	if(m_nColorTableLengthOut!=0){
    	m_lpColorTableOut=new RGBQUAD[m_nColorTableLengthOut];
		for(int i=0; i<m_nColorTableLengthOut;i++){
			m_lpColorTableOut[i].rgbBlue=i;
			m_lpColorTableOut[i].rgbGreen=i;
			m_lpColorTableOut[i].rgbRed=i;
			m_lpColorTableOut[i].rgbReserved=0;
		}
	}

	//输出图像的宽高,与输入图像相等
	m_imgWidthOut=m_imgWidth;
	m_imgHeightOut=m_imgHeight;
	int lineByte=(m_imgWidth*m_nBitCountOut/8+3)/4*4;
	m_pImgDataOut=new unsigned char[lineByte*m_imgHeight];

	//进队的像素是每个区域的边缘像素，边缘像素的数目要小于区域的像素数
	//而图像又被分成classCount个目标类，因此每个队列的最长远小于图像像素的总数
	//maxQueueBufLng用来作为申请队列缓冲区大小的依据，为节省空间，此处maxQueueBufLng的值为图像像素总数除以16
	//实际处理中队列最长还可能远远小于本程序设定的值
	maxQueueBufLng=m_imgWidth*m_imgHeight/16;

	//标记数
	objectCount=classCount;
	//循环变量
	int i, j;

	//申请队列缓冲区
	for(i=0;i<256;i++){
		for(j=0;j<4;j++)
    		queue[i][j]=new CPoint[maxQueueBufLng];

	}

	//通过指定点参数产生标记图,此时m_pImgDataOut是初始标记图
    calculateMarker(m_pImgData, m_pImgDataOut, m_imgWidth, m_imgHeight, threshInterval, objectCount);

	//申请缓冲区，存放梯度图
	unsigned char *sobelBuf=new unsigned char[lineByte*m_imgHeight];

	//计算sobel梯度图
	sobel(m_pImgData, m_imgWidth, m_imgHeight, sobelBuf);

	//水域变换
	waterShed(sobelBuf, m_pImgDataOut, m_imgWidth, m_imgHeight,contourFlg);
	//显示
	for(i=0;i<m_imgHeight;i++){
		for(j=0;j<m_imgWidth;j++){
			if(*(m_pImgDataOut+i*lineByte+j)==objectCount+1)
				*(m_pImgDataOut+i*lineByte+j)=255;
				else
	     		*(m_pImgDataOut+i*lineByte+j)= 
				(*(m_pImgDataOut+i*lineByte+j)-1)*255/objectCount;
		}
	}
	
	

	//清除梯度缓冲区
	delete []sobelBuf;


	//清除队列缓冲区
	if(maxQueueBufLng!=0){
		for(i=0;i<256;i++){
			for(j=0;j<4;j++){
			//申请队列缓冲区
			delete []queue[i][j];
			}
			
		}
		maxQueueBufLng=0;
	}
}

  
	*/