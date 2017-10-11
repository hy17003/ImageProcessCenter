#include"stdafx.h"
#include"DIBapi.h"
#include<io.h>
#include<errno.h>
#include<math.h>
#include<direct.h>
#define DIBFILETYPE ((WORD) ('M'<<8)|'B')

/***
*
* PaintDIB()
*
***/
BOOL WINAPI PaintDIB(HDC hDC,			//out DC
		     LPRECT lpDCRect,	//paint Rect area
		     HDIB hDIB,			//pointer to DIB
		     LPRECT lpDIBRect,	//the area to output
		     CPalette* pPal		//pointer to palette
		     )
{
	//BITMAPINFOHEADER
	LPSTR lpDIBHdr;
	//BIT pixels
	LPSTR lpDIBBits;
	//return
	BOOL bSuccess=FALSE;
	//DIB palette handle
	HPALETTE hPal=NULL;
	//old palette handle
	HPALETTE hOldPal=NULL;
	
	if(hDIB == NULL)
	{
		return FALSE;
	}
	
	lpDIBHdr =(LPSTR)::GlobalLock((HGLOBAL)hDIB);
	
	lpDIBBits =::FindDIBBits(lpDIBHdr);
	
	if(pPal !=NULL)
	{
		hPal =(HPALETTE)pPal->m_hObject;
		hOldPal =::SelectPalette(hDC,hPal,TRUE);
	}
	
	::SetStretchBltMode(hDC,COLORONCOLOR);
	
	if((RECTWIDTH(lpDCRect) ==RECTWIDTH(lpDIBRect)) &&
		(RECTHEIGHT(lpDCRect) ==RECTHEIGHT(lpDIBRect)))
	{
		bSuccess =::SetDIBitsToDevice(hDC,
			lpDCRect->left,
			lpDCRect->top,
			RECTWIDTH(lpDCRect),
			(int)DIBHeight(lpDIBHdr),
			lpDIBRect->left,
			lpDIBRect->top,
			0,
			(WORD)DIBHeight(lpDIBHdr),
			lpDIBBits,
			(LPBITMAPINFO)lpDIBHdr,
			DIB_RGB_COLORS);
	}
	else
	{
		bSuccess = ::StretchDIBits(hDC,
			lpDCRect->left,
			lpDCRect->top,
			RECTWIDTH(lpDCRect),
			RECTHEIGHT(lpDCRect),
			lpDIBRect->left,
			lpDIBRect->top,
			RECTWIDTH(lpDIBRect),
			RECTHEIGHT(lpDIBRect),
			lpDIBBits,
			(LPBITMAPINFO)lpDIBHdr,
			DIB_RGB_COLORS,
			SRCCOPY);
	}
	
	::GlobalUnlock((HGLOBAL)hDIB);
	
	if(hOldPal !=NULL)
	{
		::SelectPalette(hDC,hOldPal,TRUE);
	}
	
	return bSuccess;
}

BOOL WINAPI PaintDIBBits(HDC hDC,			//out DC
			 LPRECT lpDCRect,	//paint Rect area
			 HDIB hDIB,			//pointer to DIB
			 LPBYTE lpDIBBits,
			 LPRECT lpDIBRect,	//the area to output
			 CPalette* pPal		//pointer to palette
			 )
{
	//BITMAPINFOHEADER
	LPSTR lpDIBHdr;
	//return
	BOOL bSuccess=FALSE;
	//DIB palette handle
	HPALETTE hPal=NULL;
	//old palette handle
	HPALETTE hOldPal=NULL;
	
	if(hDIB == NULL)
	{
		return FALSE;
	}
	
	lpDIBHdr =(LPSTR)::GlobalLock((HGLOBAL)hDIB);
	//
	if(pPal !=NULL)
	{
		hPal =(HPALETTE)pPal->m_hObject;
		hOldPal =::SelectPalette(hDC,hPal,TRUE);
	}
	
	::SetStretchBltMode(hDC,COLORONCOLOR);
	
	if((RECTWIDTH(lpDCRect) ==RECTWIDTH(lpDIBRect)) &&
		(RECTHEIGHT(lpDCRect) ==RECTHEIGHT(lpDIBRect)))
	{
		bSuccess =::SetDIBitsToDevice(hDC,
			lpDCRect->left,
			lpDCRect->top,
			RECTWIDTH(lpDCRect),
			(int)DIBHeight(lpDIBHdr),
			lpDIBRect->left,
			lpDIBRect->top,
			0,
			(WORD)DIBHeight(lpDIBHdr),
			lpDIBBits,
			(LPBITMAPINFO)lpDIBHdr,
			DIB_RGB_COLORS);
	}
	else
	{
		bSuccess = ::StretchDIBits(hDC,
			lpDCRect->left,
			lpDCRect->top,
			RECTWIDTH(lpDCRect),
			RECTHEIGHT(lpDCRect),
			lpDIBRect->left,
			lpDIBRect->top,
			RECTWIDTH(lpDIBRect),
			RECTHEIGHT(lpDIBRect),
			lpDIBBits,
			(LPBITMAPINFO)lpDIBHdr,
			DIB_RGB_COLORS,
			SRCCOPY);
	}
	
	::GlobalUnlock((HGLOBAL)hDIB);
	
	if(hOldPal !=NULL)
	{
		::SelectPalette(hDC,hOldPal,TRUE);
	}
	
	return bSuccess;
}

/***
*
* GetSystemPalette()
*
***/
HPALETTE WINAPI GetSystemPalette(void)
{
	//DC handle
	HDC hDC;
	
	//palette handle
	static HPALETTE hPal=NULL;
	
	//logic palette pointer
	LPLOGPALETTE lpLogPal;
	
	//logic palette handle
	HANDLE hLogPal;
	
	//color number
	int nColors;
	
	hDC =GetDC(NULL);
	
	if(hDC ==NULL)
		return NULL;
	
	nColors =(1<<(GetDeviceCaps(hDC,BITSPIXEL)*GetDeviceCaps(hDC,PLANES)));
	ASSERT(nColors);
	
	hLogPal =GlobalAlloc(GHND,sizeof(LOGPALETTE)+nColors*sizeof(PALETTEENTRY));
	
	if(hLogPal ==NULL)
		return NULL;
	
	lpLogPal =(LPLOGPALETTE)GlobalLock(hLogPal);
	
	lpLogPal->palVersion =PALVERSION;
	
	lpLogPal->palNumEntries =nColors;
	
	GetSystemPaletteEntries(hDC,0,nColors,(LPPALETTEENTRY)(lpLogPal->palPalEntry));
	
	hPal =CreatePalette(lpLogPal);
	
	GlobalUnlock(hLogPal);
	
	GlobalFree(hLogPal);
	
	ReleaseDC(NULL,hDC);
	
	return hPal;
}

/***
*
* FindDIBBits()
*
***/
LPSTR WINAPI FindDIBBits(LPSTR lpbi)
{
	return (lpbi+*(LPDWORD)lpbi+::PaletteSize(lpbi));
}

/***
*
* PaletteSize()
*
***/
WORD WINAPI PaletteSize(LPSTR lpbi)
{
	if(IS_WIN30_DIB(lpbi))
	{
		return (WORD)(::DIBNumColors(lpbi)*sizeof(RGBQUAD));
	}
	else
	{
		return (WORD)(::DIBNumColors(lpbi)*sizeof(RGBTRIPLE));
	}
}

/***
*
* DIBNumColors()
*
***/
WORD WINAPI DIBNumColors(LPSTR lpbi)
{
	//bits per pixel
	WORD wBitCount;
	
	if(IS_WIN30_DIB(lpbi))
	{
		//number of colors actually used
		DWORD dwClrUsed;
		
		dwClrUsed =((LPBITMAPINFOHEADER)lpbi)->biClrUsed;
		if(dwClrUsed !=0)
		{
			return (WORD)dwClrUsed;
		}
	}
	
	if(IS_WIN30_DIB(lpbi))
	{
		wBitCount =((LPBITMAPINFOHEADER)lpbi)->biBitCount;
	}
	else
	{
		wBitCount =((LPBITMAPCOREHEADER)lpbi)->bcBitCount;
	}
	
	switch(wBitCount)
	{
	case 1:
		return 2;
	case 4:
		return 16;
	case 8:
		return 256;
	default:
		return 0;
	}
}

/***
*
* DIBBitCount()
*
***/
WORD WINAPI DIBBitCount(LPSTR lpbi)
{
	WORD wBitCount;
	
	if(IS_WIN30_DIB(lpbi))
	{
		wBitCount =((LPBITMAPINFOHEADER)lpbi)->biBitCount;
	}
	else
	{
		wBitCount =((LPBITMAPCOREHEADER)lpbi)->bcBitCount;
	}
	
	return wBitCount;
}

/***
*
* DIBHeight()
*
***/
DWORD WINAPI DIBHeight(LPSTR lpDIB)
{
	LPBITMAPINFOHEADER lpbmi;
	
	LPBITMAPCOREHEADER lpbmc;
	
	lpbmi =(LPBITMAPINFOHEADER)lpDIB;
	
	lpbmc =(LPBITMAPCOREHEADER)lpDIB;
	
	if(IS_WIN30_DIB(lpDIB))
	{
		return lpbmi->biHeight;
	}
	else
	{
		return (DWORD)lpbmc->bcHeight;
	}
}

/***
*
* DIBWidth()
*
***/
DWORD WINAPI DIBWidth(LPSTR lpDIB)
{
	LPBITMAPINFOHEADER lpbmi;
	
	LPBITMAPCOREHEADER lpbmc;
	
	lpbmi =(LPBITMAPINFOHEADER)lpDIB;
	
	lpbmc =(LPBITMAPCOREHEADER)lpDIB;
	
	if(IS_WIN30_DIB(lpDIB))
	{
		return lpbmi->biWidth;
	}
	else
	{
		return (DWORD)lpbmc->bcWidth;
	}
}

/***
*
* ReadDIBFile()
*
***/
HDIB WINAPI ReadDIBFile(CFile& file)
{
	BITMAPFILEHEADER bmfHeader;
	
	DWORD dwBitsSize;
	
	HDIB hDIB;
	
	LPSTR pDIB;
	
	dwBitsSize =file.GetLength();
	
	if(file.Read((LPSTR)&bmfHeader,sizeof(bmfHeader)) !=sizeof(bmfHeader))
	{
		return NULL;
	}
	
	if(bmfHeader.bfType !=DIBFILETYPE)
	{
		return NULL;
	}
	
	hDIB =(HDIB)::GlobalAlloc(GMEM_MOVEABLE|GMEM_ZEROINIT,dwBitsSize);
	
	if(!hDIB)
	{
		return NULL;
	}
	
	pDIB =(LPSTR)::GlobalLock((HGLOBAL)hDIB);
	
	if(file.Read(pDIB,dwBitsSize-sizeof(BITMAPFILEHEADER)) !=dwBitsSize-sizeof(BITMAPFILEHEADER))
	{
		::GlobalUnlock((HGLOBAL)hDIB);
		
		::GlobalFree((HGLOBAL)hDIB);
		
		return NULL;
	}
	
	::GlobalUnlock((HGLOBAL)hDIB);
	
	return hDIB;
}

/***
*
* CreateDIBPalette()
*
***/
BOOL WINAPI CreateDIBPalette(HDIB hDIB,CPalette* pPal)
{
	LPLOGPALETTE lpPal;
	
	HANDLE hLogPal;
	
	HPALETTE hPal =NULL;
	
	int i;
	
	WORD wNumColors;
	
	LPSTR lpbi;
	
	LPBITMAPINFO lpbmi;
	
	LPBITMAPCOREINFO lpbmc;
	
	BOOL bWinStyleDIB;
	
	BOOL bResult =FALSE;
	
	if(!hDIB)
	{
		return FALSE;
	}
	
	lpbi =(LPSTR)::GlobalLock((HGLOBAL)hDIB);
	
	lpbmi =(LPBITMAPINFO)lpbi;
	
	lpbmc =(LPBITMAPCOREINFO)lpbi;
	
	wNumColors =::DIBNumColors(lpbi);
	
	if(TRUE)//wNumColors !=0)
	{
		if(wNumColors==0)
		{
			hLogPal =::GlobalAlloc(GHND,sizeof(LOGPALETTE)+sizeof(PALETTEENTRY)*256);
		}
		else
		{
			hLogPal =::GlobalAlloc(GHND,sizeof(LOGPALETTE)+sizeof(PALETTEENTRY)*wNumColors);
		}
		if(!hLogPal)
		{
			::GlobalUnlock((HGLOBAL)hDIB);
			return FALSE;
		}
		lpPal =(LPLOGPALETTE)::GlobalLock((HGLOBAL)hLogPal);
		
		lpPal->palVersion =PALVERSION;
		
		if(wNumColors==0)
		{lpPal->palNumEntries = 256;
		}
		else
		{lpPal->palNumEntries =(WORD)wNumColors;
		}
		
		
		bWinStyleDIB =IS_WIN30_DIB(lpbi);
		if(wNumColors!=0)
		{	
			for(i =0;i <(int)wNumColors;i++)
			{
				if(bWinStyleDIB)
				{
					lpPal->palPalEntry[i].peRed =lpbmi->bmiColors[i].rgbRed;
					lpPal->palPalEntry[i].peGreen =lpbmi->bmiColors[i].rgbGreen;
					lpPal->palPalEntry[i].peBlue =lpbmi->bmiColors[i].rgbBlue;
					lpPal->palPalEntry[i].peFlags =0;
				}
				
				else
				{
					lpPal->palPalEntry[i].peRed =lpbmc->bmciColors[i].rgbtRed;
					lpPal->palPalEntry[i].peGreen =lpbmc->bmciColors[i].rgbtGreen;
					lpPal->palPalEntry[i].peBlue =lpbmc->bmciColors[i].rgbtBlue;
					lpPal->palPalEntry[i].peFlags =0;
				}
			}
		}
		else
		{
			for(int i =0; i<256; i++)
			{
				lpPal->palPalEntry[i].peRed =(BYTE)i;
				lpPal->palPalEntry[i].peGreen =(BYTE)i;
				lpPal->palPalEntry[i].peBlue =(BYTE)i;
				lpPal->palPalEntry[i].peFlags =0;
			}
		}
		
		bResult =pPal->CreatePalette(lpPal);
		
		::GlobalUnlock((HGLOBAL)hLogPal);
		
		::GlobalFree((HGLOBAL)hLogPal);
	}
	
	::GlobalUnlock((HGLOBAL)hDIB);
	
	return bResult;
}
