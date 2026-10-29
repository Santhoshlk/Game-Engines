#pragma once

struct Rectangle
{
    // x and y are the distances from (0,0)
    float x;
    float y;
    float width;
    float height;

    Rectangle(float xdist,float ydist , float w,float h) : x(xdist) , y(ydist) , width(w) , height(h) {}

};