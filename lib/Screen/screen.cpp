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

void Screen::drawEmotion(int emotion) {
    tft.clear();

    tft.drawBitmap(0, 0, epd_bitmap_allArray[emotion], 220, 176, COLOR_BLACK);
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
