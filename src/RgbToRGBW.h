


#include <Arduino.h>
#include <FastLED.h>
/*
struct colorRgbw
{
    union{
        unsigned int    red;
        unsigned int    r;
    };
    union{
        unsigned int    green;
        unsigned int    g;
    };
    union{
        unsigned int    blue;
        unsigned int    b;
    };
    union{
        unsigned int    white;
        unsigned int    w;
    };
};
*/


struct colorRgbw {
	union {
		struct {
            union {
                uint8_t r;
                uint8_t red;
            };
            union {
                uint8_t g;
                uint8_t green;
            };
            union {
                uint8_t b;
                uint8_t blue;
            };
            union {
                uint8_t w;
                uint8_t white;
            };
        };
		uint8_t raw[4];
        uint32_t rnum;
	};
};



unsigned int    saturation(colorRgbw rgbw){
    float low = min(rgbw.r, min(rgbw.g,rgbw.b));
    float high = max(rgbw.r, max(rgbw.g,rgbw.b));
    return round(100 * ((high - low)/high));
}

unsigned int    getWhite(colorRgbw rgbw){
    return (255- saturation(rgbw)) / 255 * (rgbw.r + rgbw.g + rgbw.b) / 3;
}

unsigned int    getWhite(colorRgbw rgbw, int8_t redMax, int8_t greenMax, int8_t blueMax){
    rgbw.r = (float)rgbw.r / 255.0 * (float)redMax;
    rgbw.g = (float)rgbw.g / 255.0 * (float)greenMax;
    rgbw.b = (float)rgbw.b / 255.0 * (float)blueMax;
    return (255- saturation(rgbw)) / 255 * (rgbw.r + rgbw.g + rgbw.b) / 3;
    return 0;
}

colorRgbw    crgbToRgbw(CRGB  colors){
    uint8_t white = 0;
    colorRgbw rgbw = {colors.r, colors.g, colors.b, white};
    rgbw.w = getWhite(rgbw);
    return rgbw;

}

colorRgbw   rgbToRgbw(uint8_t red, uint8_t green, uint8_t blue){
    uint8_t white = 0;
    colorRgbw rgbw = {red, green, blue, white};
    rgbw.w = getWhite(rgbw);
    return rgbw;
}

colorRgbw   rgbToRgbw(uint8_t red,uint8_t redmax, uint8_t green,uint8_t greenmax, uint8_t blue, uint8_t bluemax){
    uint8_t white = 0;
    colorRgbw rgbw = {red, green, blue, white};
    rgbw.w = getWhite(rgbw, redmax, greenmax, bluemax);
    return rgbw;
}


/*
struct CRGBW {
	union {
		struct {
            union {
                uint8_t r;
                uint8_t red;
            };
            union {
                uint8_t g;
                uint8_t green;
            };
            union {
                uint8_t b;
                uint8_t blue;
            };
            union {
                uint8_t w;
                uint8_t white;
            };
        };
		uint8_t raw[4];
	};
};*/