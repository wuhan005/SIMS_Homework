#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "MainPage.h"		//首页

int main(){

	system("mode con cols=110 lines=35");	//设置初始窗口长度
	system("color 02");	//设置控制台颜色为绿色 02

	drawMainPageUI();
	
	getchar();

    return 0;
}

