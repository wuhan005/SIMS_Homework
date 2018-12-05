#pragma once

#include <stdio.h>

//About.c
void drawAboutPage(void);
int loadAboutPage();

//AddInfo.c
int ScriptCheck(char _input[50]);
void printForm(int nowIndex);
void addData(char _data[8][50]);
int loadAddInfoPage(void);

//DeleteInfo.c
int loadDeleteInfoPage(void);

//char inputData[8][50];	//输入的字段
//int nowInputIndex = 0;
//char tips[50] = { "" };		//反馈提示

//BrowseInfo.c
int loadBrowseInfoPage(void);

//MainPage.c
void drawMainPageMeau();
void drawMainPageUI();

