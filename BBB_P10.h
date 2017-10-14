//
// Created by joek on 10/4/16.
//
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#ifndef BBB_P10_BBB_P10_H
#define BBB_P10_BBB_P10_H
#define WIDTH   32
#define HEIGHT  16
#define nPANEL  1

void Clear_Buffer(bool fill);
void Fill_Buffer(char *buf);
void drawBox(int x1, int y1, int x2, int y2);
void drawLine(int x1, int y1, int x2, int y2);
void sendb();
#endif //BBB_P10_BBB_P10_H
