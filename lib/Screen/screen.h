#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <TFT_22_ILI9225.h>
#include <SPI.h>

#define TFT_RST  26
#define TFT_RS   25
#define TFT_CS   15
#define TFT_SDI  13  // HSPI MOSI
#define TFT_CLK  14  // HSPI SCK
#define TFT_LED  255 // No conectado o alimentado directamente con 5V


#define FELIZ_WIDTH  176
#define FELIZ_HEIGHT 220

class Screen{
    public:
        Screen();
        void initialize();
        void drawFaceBase(int x, int y, uint16_t faceColor);
        void drawHappyFace(int x, int y);
        void drawSadFace(int x, int y);
        void drawAngryFace(int x, int y);
        void drawNeutralFace(int x, int y);
        void drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, uint16_t color);

    private:
        float scale = 2.0;
};


#endif