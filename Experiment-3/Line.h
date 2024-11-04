#pragma once
#include<windows.h>
#include<bits/stdc++.h>
#include "Point.h"
#include "State_macros.h"
#include "Variables.h"
#include "GeometryRelations.h"

// #define DEBUG
#include "debug.h"
using namespace std;

struct Line
{
    int left, right, button, top;
    POINT s,e;
    double a,b,c;   // ax + by + c = 0
    static RECT rect;
    static COLORREF color;
    Line()
    {
        a=b=c=0;
        s=e={0,0};
    }
    Line(POINT A, POINT B)
    {
        s=A, e=B;
        auto [x1,y1]=A;
        auto [x2,y2]=B;
        left=min(x1,x2), right=max(x1,x2);
        button=min(y1,y2), top=max(y1,y2);
        a=y1-y2, b=x2-x1, c=x1*y2 - x2*y1;
    }
    double slolpe() // 斜率
    { return double(e.y-s.y)/double(e.x-s.x); }
};

void Bresenham_Line(HDC hdc, POINT A, POINT B, COLORREF color);
void MidPoint_Line(HDC hdc, POINT A, POINT B, COLORREF color);

void Draw_line(HWND hWnd, vector<POINT> &arr, int state);
