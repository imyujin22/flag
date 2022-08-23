// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>

bool SaveBMP(const char* fileName, int width, int height, int bpp, unsigned char* pData)
{
	if (bpp != 1 && bpp != 3 && bpp != 4)
	{
		return false;
	}

	FILE* fp = NULL;

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGBQUAD palette[256];

	memset(&fileHeader, 0, sizeof(BITMAPFILEHEADER));
	memset(&infoHeader, 0, sizeof(BITMAPINFOHEADER));

	fileHeader.bfType = 0x4d42;
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (width * height * bpp);
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	if (bpp == 1)
	{
		fileHeader.bfSize += (256 * 4);
		fileHeader.bfOffBits += (256 * 4);
	}

	infoHeader.biSize = sizeof(BITMAPINFOHEADER);
	infoHeader.biWidth = width;
	infoHeader.biHeight = -height;
	infoHeader.biPlanes = 1;
	infoHeader.biBitCount = bpp * 8;
	infoHeader.biSizeImage = width * height * bpp;
	infoHeader.biXPelsPerMeter = 2834;
	infoHeader.biYPelsPerMeter = 2834;

	if (fopen_s(&fp, fileName, "wb") != 0)
	{
		return false;
	}

	if (bpp == 1)
	{
		for (int i = 0; i < 256; i++)
		{
			palette[i].rgbBlue = i;
			palette[i].rgbGreen = i;
			palette[i].rgbRed = i;
			palette[i].rgbReserved = 0;
		}
	}

	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	if (bpp == 1)
		fwrite(palette, 256 * 4, 1, fp);

	/*
	// bottom-up
	for(int i=0;i<height;i++)
	fwrite(&pData[(height-i-1)*width*bpp], width * bpp, 1, fp);
	*/

	// top-down
	fwrite(pData, width * height * bpp, 1, fp);

	fclose(fp);

	return true;
}

void MakeFlag_JAPAN(void)
{
	const int width = 600;
	const int height = 400;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int distance = (x - width / 2) * (x - width / 2) + (y - height / 2) * (y - height / 2);
			if (distance < 100 * 100)
			{
				// red
				bitmap[y][x][0] = 0; // blue channel
				bitmap[y][x][1] = 0; // green channel
				bitmap[y][x][2] = 255; // red channel
			}
			else {
				// white
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}
		}
	}

	SaveBMP("japan.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_FRANCE(void)
{
	const int width = 600;
	const int height = 400;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			{
				bitmap[y][x][0] = 0; // blue channel
				bitmap[y][x][1] = 0; // green channel
				bitmap[y][x][2] = 255; // red channel

				if (x < (width / 3)) {
					bitmap[y][x][0] = 255; // blue channel
					bitmap[y][x][1] = 0; // green channel
					bitmap[y][x][2] = 0; // red channel
				}

				else if (x < ((width / 3) * 2)) {
					bitmap[y][x][0] = 255; // blue channel
					bitmap[y][x][1] = 255; // green channel
					bitmap[y][x][2] = 255; // red channel
				}
			}
		}
	}


	SaveBMP("france.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_GERMANY(void)
{
	const int width = 500;
	const int height = 300;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			{
				bitmap[y][x][0] = 0; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel

				if (y < (height / 3)) {
					bitmap[y][x][0] = 0; // blue channel
					bitmap[y][x][1] = 0; // green channel
					bitmap[y][x][2] = 0; // red channel
				}

				else if (y < ((height / 3) * 2)) {
					bitmap[y][x][0] = 0; // blue channel
					bitmap[y][x][1] = 0; // green channel
					bitmap[y][x][2] = 255; // red channel
				}
			}
		}
	}
	SaveBMP("germany.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_FINIAND(void) {
	const int width = 360;
	const int height = 220;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			bitmap[y][x][0] = 255; // blue channel
			bitmap[y][x][1] = 255; // green channel
			bitmap[y][x][2] = 255; // red channel

			if ((y > ((height / 11) * 4)) && (y < ((height / 11) * 7))) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			else if (x > ((width / 18) * 5) && x < ((width / 18) * 8)) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}
		}
	}

	SaveBMP("finland.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_GREECE(void) {
	const int width = 540;
	const int height = 360;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			bitmap[y][x][0] = 255; // blue channel
			bitmap[y][x][1] = 255; // green channel
			bitmap[y][x][2] = 255; // red channel
			if (y == 397)
			{
				int a = 10;
			}
			for (int i = 0; i < 18; i = i + 4) {
				if (y >= ((height / 18) * i) && y <= ((height / 18) * (i + 2))) {
					bitmap[y][x][0] = 175; // blue channel
					bitmap[y][x][1] = 94; // green channel
					bitmap[y][x][2] = 13; // red channel
				}
			}
		}
	}

	for (int y = 0; y < (height / 18) * 10; y++) {
		for (int x = 0; x < (width / 27) * 10; x++) {
			bitmap[y][x][0] = 175; // blue channel
			bitmap[y][x][1] = 94; // green channel
			bitmap[y][x][2] = 13; // red channel

			if (y > ((height / 18) * 4) && y < ((height / 18) * 6)) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			else if (x > ((width / 27) * 4) && x < ((width / 27) * 6)) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}
		}
	}

	SaveBMP("greece.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_JAMAICA(void) {
	const int width = 600;
	const int height = 300;
	unsigned char bitmap[height][width][3];

	int i = 0;
	int j = width;

	for (int y = 0; y < height; y++) {
		i += 2;
		j -= 2;
		for (int x = 0; x < width; x++) {
			bitmap[y][x][0] = 0; // blue channel
			bitmap[y][x][1] = 0; // green channel
			bitmap[y][x][2] = 0; // red channel

			if ((x >= 2 * y) && x <= (width - (y * 2))) {
				bitmap[y][x][0] = 73; // blue channel
				bitmap[y][x][1] = 119; // green channel
				bitmap[y][x][2] = 0; // red channel
			}
			
			if ((x >= 2 * (height - y)) && x <= (width - (height - y) * 2)) {
				bitmap[y][x][0] = 73; // blue channel
				bitmap[y][x][1] = 119; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			if (x > ((width / 10) * -1) + i && x < ((width / 10) * 1) + i) {
				bitmap[y][x][0] = 28; // blue channel
				bitmap[y][x][1] = 184; // green channel
				bitmap[y][x][2] = 255; // red channel	
			}

			if (x > ((width / 10) * -1) + j && x < ((width / 10) * 1) + j) {
				bitmap[y][x][0] = 28; // blue channel
				bitmap[y][x][1] = 184; // green channel
				bitmap[y][x][2] = 255; // red channel	
			}
		}
	}

	SaveBMP("jamaica.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_United_Kingdom(void) {
	const int width = 720;
	const int height = 360;
	unsigned char bitmap[height][width][3];

	int i = 0;

	int j = width;

	for (int y = 0; y < height; y++) {

		i += 2;
		j -= 2;
		for (int x = 0; x < width; x++) {

			bitmap[y][x][0] = 125; // blue channel
			bitmap[y][x][1] = 36; // green channel
			bitmap[y][x][2] = 0; // red channel

			if (x > ((width / 30) * -3) + i && x < ((width / 30) * 3) + i) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			if (x > ((width / 30) * -2) + i && x < ((width / 30) * 0) + i && x < (width/2)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}

			if (x > ((width / 30) * 0) + i && x < ((width / 30) * 2) + i && x > (width / 2)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}

			if (x > ((width / 30) * -3) + j && x < ((width / 30) * 3) + j) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			if (x > ((width / 30) * -2) + j && x < ((width / 30) * 0) + j && x > (width / 2)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}

			if (x > ((width / 30) * 0) + j && x < ((width / 30) * 2) + j && x < (width / 2)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}

			if (y > ((height / 30) * 10) && y < ((height / 30) * 20)) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			if (x > ((width / 60) * 25) && x < ((width / 60) * 35)) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			if (y > ((height / 30) * 12) && y < ((height / 30) * 18)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}

			if (x > ((width / 60) * 27) && x < ((width / 60) * 33)) {
				bitmap[y][x][0] = 43; // blue channel
				bitmap[y][x][1] = 20; // green channel
				bitmap[y][x][2] = 207; // red channel
			}
		}
	}

	SaveBMP("united_kingdom.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_BAHRAIN(void) {
	const int width = 500;
	const int height = 300;
	unsigned char bitmap[height][width][3];
	
	int i = 0;
	//for (int y = ((height / 10) * 4); y < height; y++) 
	
	
	for (int y = 0; y < height; y++) {
		i += 2;
		for (int x = 0; x < width; x++) {
			bitmap[y][x][0] = 255; // blue channel
			bitmap[y][x][1] = 255; // green channel
			bitmap[y][x][2] = 255; // red channel

			if (x > (width / 4) + i && y <= ((height / 10) * 1)) {
				bitmap[y][x][0] = 38; // blue channel
				bitmap[y][x][1] = 17; // green channel
				bitmap[y][x][2] = 206; // red channel 
			}

			if (x > (width / 2) - i && y <= ((height / 10) * 2)) {
				bitmap[y][x][0] = 38; // blue channel
				bitmap[y][x][1] = 17; // green channel
				bitmap[y][x][2] = 206; // red channel
			}
		}	
	}

	for (int j = 2; j <= 8; j += 2) {
		i = 0;
		for (int y = ((height / 10) * j); y < height; y++) {
			i += 2;
			for (int x = 0; x < width; x++) {

				if (x > (width / 4) + i && y <= ((height / 10) * (j + 1))) {
					bitmap[y][x][0] = 38; // blue channel
					bitmap[y][x][1] = 17; // green channel
					bitmap[y][x][2] = 206; // red channel 
				}

				if (x > (width / 2) - i && y <= ((height / 10) * (j + 2))) {
					bitmap[y][x][0] = 38; // blue channel
					bitmap[y][x][1] = 17; // green channel
					bitmap[y][x][2] = 206; // red channel
				}
			}
		}
	}

	SaveBMP("bkhrain.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_CHILE(void) {
	const int width = 600;
	const int height = 400;
	unsigned char bitmap[height][width][3];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			bitmap[y][x][0] = 30; // blue channel
			bitmap[y][x][1] = 43; // green channel
			bitmap[y][x][2] = 213; // red channel

			if (y < height / 2) {
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}
		}
	}

	for (int y = 0; y < height / 2; y++) {
		for (int x = 0; x < width / 3; x++) {
			bitmap[y][x][0] = 166; // blue channel
			bitmap[y][x][1] = 57; // green channel
			bitmap[y][x][2] = 0; // red channel
		}
	}

	int start_y = (height / 6);
	int end_y = (height / 6) * 2;

	int start_x = (width / 9);
	int end_x = (width / 9) * 2;

	int i = 0;
	int j = 0;
	int q = 0;

	for (int y = start_y; y < end_y; y++) {
		if (y % 3 == 0) {
			i++;
		}

		if (y % 2 == 0) {
			q += 2;
		}
		
		if (y >= (start_y + 30)) {
			j += 2;
		}

		for (int x = start_x; x < end_x; x++) {
			if ((x >= (start_x + 33) - i) && x <= (start_x + 33) + i && y <= end_y - 15)
			{
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}
			
			if ((x >= (start_x + q) && x <= (end_x - q)) && y >= start_y + 15)
			{
				bitmap[y][x][0] = 255; // blue channel
				bitmap[y][x][1] = 255; // green channel
				bitmap[y][x][2] = 255; // red channel
			}

			if (y >= start_y + 30 && (x >= (start_x + 33) - j) && x <= (start_x + 33) + j)
			{
				bitmap[y][x][0] = 166; // blue channel
				bitmap[y][x][1] = 57; // green channel
				bitmap[y][x][2] = 0; // red channel
			}
		}
	}

	SaveBMP("chile.bmp", width, height, 3, (unsigned char*)bitmap);
}

void MakeFlag_ISRAEL(void)
{
	const int width = 600;
	const int height = 400;
	unsigned char bitmap[height][width][3];

	int i = 0;
	int j = 0;
	for (int y = 0; y < height; y++)
	{
		if (y > (height / 10) * 4 )
		{
			if (y % 3 == 0) {
				i += 2;
			}
		}

		if (y > 110) {
			if (y % 3 == 0) {
				j += 2;
			}
		}
		
		for (int x = 0; x < width; x++) {

			bitmap[y][x][0] = 255; // blue channel
			bitmap[y][x][1] = 255; // green channel
			bitmap[y][x][2] = 255; // red channel

			//À§ÀÇ Ä­
			if (y > (height / 10) && y < (((height / 10) * 3) - 20)) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			// ¹ØÀÇ Ä­
			if (y > (((height /10) * 8) - 20) && y < ((height / 10) * 9)) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			// À§ Á÷¼±
			if (y > ((height / 10) * 4) && y < (((height / 10) * 4) + 10) && x >= 230 && x < (((width / 30) * 20) - 20)) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			// ¹Ø Á÷¼±
			if (y > (((height / 10) * 5) + 30) && y < ((height / 10) * 6) && x > (((width / 30) * 10) + 20) && x < (((width / 30) * 20) - 20)) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			if (y > 160 && y < ((height / 10) * 7) &&
				x >= 220 + i && x < 230 + i) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			if (y > 160 && y < ((height / 10) * 7) &&
				x >= 380 - i && x < 390 - i) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			if (y > 115 && y < 240 &&
				x >= 300 - j && x < 310 - j) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}

			if (y > 115 && y < 240 &&
				x >= 290 + j && x < 300 + j) {
				bitmap[y][x][0] = 108; // blue channel
				bitmap[y][x][1] = 47; // green channel
				bitmap[y][x][2] = 0; // red channel
			}
		}
	}

	SaveBMP("israel.bmp", width, height, 3, (unsigned char*)bitmap);
}



int main()
{
	MakeFlag_JAPAN();
	MakeFlag_FRANCE();
	MakeFlag_GERMANY();
	MakeFlag_FINIAND();
	MakeFlag_GREECE();
	MakeFlag_JAMAICA();
	MakeFlag_United_Kingdom();
	MakeFlag_BAHRAIN();
	MakeFlag_CHILE();
	MakeFlag_ISRAEL();
}
