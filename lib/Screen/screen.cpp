#include "screen.h"

SPIClass hspi(HSPI);
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

Screen::Screen() {}

void Screen::initialize()
{
	hspi.begin(TFT_CLK, -1, TFT_SDI, TFT_CS); // SCK, MISO, MOSI, SS
	tft.begin(hspi);

	tft.clear();
	tft.setBackgroundColor(COLOR_BLACK);
	tft.setFont(Terminal12x16);
}

void Screen::drawFaceBase(int x, int y, uint16_t faceColor)
{
	tft.fillCircle(x, y, 30 * scale, faceColor);						  // cara principal
	tft.fillCircle(x - 10 * scale, y - 10 * scale, 3 * scale, COLOR_BLACK); // ojo izquierdo
	tft.fillCircle(x + 10 * scale, y - 10 * scale, 3 * scale, COLOR_BLACK); // ojo derecho
}

void Screen::drawHappyFace(int x, int y)
{
	drawFaceBase(x, y, COLOR_YELLOW);
	tft.drawLine(x - 10 * scale, y + 10 * scale, x - 5 * scale, y + 15 * scale, COLOR_BLACK);
	tft.drawLine(x - 5 * scale, y + 15 * scale, x + 5 * scale, y + 15 * scale, COLOR_BLACK);
	tft.drawLine(x + 5 * scale, y + 15 * scale, x + 10 * scale, y + 10 * scale, COLOR_BLACK);
}

void Screen::drawSadFace(int x, int y)
{
	drawFaceBase(x, y, COLOR_YELLOW);
	tft.drawLine(x - 10 * scale, y + 15 * scale, x - 5 * scale, y + 10 * scale, COLOR_BLACK);
	tft.drawLine(x - 5 * scale, y + 10 * scale, x + 5 * scale, y + 10 * scale, COLOR_BLACK);
	tft.drawLine(x + 5 * scale, y + 10 * scale, x + 10 * scale, y + 15 * scale, COLOR_BLACK);
}

void Screen::drawAngryFace(int x, int y)
{
	drawFaceBase(x, y, COLOR_YELLOW);
	tft.drawLine(x - 15 * scale, y - 18 * scale, x - 5 * scale, y - 13 * scale, COLOR_BLACK); // ceja izq
	tft.drawLine(x + 5 * scale, y - 13 * scale, x + 15 * scale, y - 18 * scale, COLOR_BLACK); // ceja der
	tft.drawLine(x - 10 * scale, y + 12 * scale, x + 10 * scale, y + 8 * scale, COLOR_BLACK); // boca
}

void Screen::drawNeutralFace(int x, int y)
{
	drawFaceBase(x, y, COLOR_YELLOW);
	tft.drawLine(x - 10 * scale, y + 12 * scale, x + 10 * scale, y + 12 * scale, COLOR_BLACK);
}

void Screen::drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, uint16_t color)
{
	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
		{
			int byteIndex = i + (j / 8) * w;
			bool pixelOn = bitRead(pgm_read_byte(bitmap + byteIndex), j % 8);
			if (pixelOn)
			{
				tft.drawPixel(x + i, y + j, color);
			}
		}
	}
}
