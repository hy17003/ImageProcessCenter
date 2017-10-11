#define		BACK_ALL_NUM	100				//计算背景所需帧数
#define		BACK_SEQ_NUM	3				//计算背景循环数目
#define		THRESHOLD			20              //设置差分阈值
class CStaticDetect  
{
public:
	CStaticDetect(int nwidth, int nheight);
	virtual ~CStaticDetect();
	void ReceiveFrame(int index, BYTE* sBuf);	//主调用函数
public:
	BYTE *m_pCurImage;		 //当前图像
	BYTE *m_pDetectImage;    //检测结果图像
	
	int m_nFrame, count;
	int WIDTH, HEIGHT,IMAGESIZE;
	short int *m_pBackHistgram;		//背景颜色统计
	BYTE *m_pGrayImage;               //当前灰度图像
	BYTE *m_pBackground;	             //背景
	BYTE *m_pDiffImage;          //差分图像
	UINT *m_pTemplate;           //存取多帧数据

private:
	void RGBToGray(BYTE *sRGB,BYTE *sGray,int nWidth, int nHeight);
	void DiffImage(BYTE *sGray,BYTE *pGray,int nWidth, int nHeight,int nThreshold);
	void GetMultiData(BYTE *sGray,int nWidth, int nHeight);
	void GetBgImage();

};
