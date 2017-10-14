//
// Created by joek on 10/4/16.
//

#include "BBB_P10.h"
#include "udp.h"

static unsigned char PixelTable[8] = {
        0x80,
        0x40,
        0x20,
        0x10,
        0x08,
        0x04,
        0x02,
        0x01
};

unsigned char bb[64*nPANEL];

void Clear_Buffer(bool fills) {
    if (fills)
        memset(bb,0xFF,sizeof(bb));
    else
        memset(bb,0x00,sizeof(bb));
}
void Scale(int x , int y , int bPixel) {
    if(x<0 || x>=(WIDTH*nPANEL) || y<0 || y>=HEIGHT) return;
    int index;
    int panel= ((x / (WIDTH*nPANEL)) + ((y / HEIGHT)));
    x=(x % (WIDTH*nPANEL))+ (panel<<5);
    y=y % HEIGHT;

    index = x/8 + y*(nPANEL << 2);

    char data = PixelTable[x & 0x07];
    if (bPixel == 0){
        bb[index] &= ~data;
    }else{
        bb[index] |= data;
    }
}
void Fill_Buffer(char *buf){
    memcpy(buf, bb, strlen(buf));
}
void drawLine(int x1, int y1, int x2, int y2) {
        int dy = y2 - y1;
        int dx = x2 - x1;
        int stepx, stepy;

        if (dy < 0) {
            dy = -dy;
            stepy = -1;
        } else {
            stepy = 1;
        }
        if (dx < 0) {
            dx = -dx;
            stepx = -1;
        } else {
            stepx = 1;
        }
        dy <<= 1;
        dx <<= 1;

        Scale(x1, y1, 1);
        if (dx > dy) {
            int fraction = dy - (dx >> 1);
            while (x1 != x2) {
                if (fraction >= 0) {
                    y1 += stepy;
                    fraction -= dx;
                }
                x1 += stepx;
                fraction += dy;
                Scale(x1, y1, 1);
            }
        } else {
            int fraction = dx - (dy >> 1);
            while (y1 != y2) {
                if (fraction >= 0) {
                    x1 += stepx;
                    fraction -= dy;
                }
                y1 += stepy;
                fraction += dx;
                Scale(x1, y1, 1);
            }
        }
}
void drawBox(int x1, int y1, int x2, int y2) {
        drawLine(x1, y1, x2, y1);
        drawLine(x2, y1, x2, y2);
        drawLine(x2, y2, x1, y2);
        drawLine(x1, y2, x1, y1);
}
void sendb(){
    SendBuffer(bb);
}

