#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<ctype.h>

#define LINE_MAX 1024
void SetSize(unsigned uCol, unsigned uLine);
void SetPos(int x, int y);
int ReadLine(char* path, int color);
void Welcome(int color);
void MainMenu(int color);
int Choice();
