#pragma once

struct Rectangle
{
    // x and y are the distances from (0,0)
    int x;
    int y;
    int width;
    int height;

    Rectangle(int xdist,int ydist , int w,int h) : x(xdist) , y(ydist) , width(w) , height(h) {}

};