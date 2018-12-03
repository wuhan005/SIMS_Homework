#include <stdio.h>
#include <string.h>
#include <ctype.h>	//字符串判断
#include <windows.h>

#include "sqlite3.h"
#include "MyHeader.h"

int main(){

	system("mode con cols=110 lines=35");	//设置初始窗口长度
	system("color 02");	//设置控制台颜色为绿色 02
	
	char userInput;
	char tips[50];	//给用户的提示（全局）

	while (1) {
		drawMainPageUI();

		userInput = getchar();

		//判断用户输入是否是数字
		if (isdigit(userInput)) {
			
			//匹配用户输入
			switch ((int)userInput - 48){
				case 0:
					loadAddInfoPage();
					break;
				case 1:
					loadBrowseInfoPage();
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					loadDeleteInfoPage();
					break;
				case 5:
					loadAboutPage();
					break;
				case 6:
					exit(0);
					break;
				case 7:
					
					break;

				default:
					printf("%d", userInput);
					printf("您的输入有误，请重新输入：\n");
					break;
			}
			
		}else {
			printf("您的输入有误，请重新输入：\n");
		}

		//清除输入的多余字符，直到换行符
		while (1) {
			if (getchar() == '\n') {
				break;
			}
		}

		continue;
	}

    return 0;
}

