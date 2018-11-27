#pragma once

//关于页面

void drawAboutPage(void) {
	system("cls");

	//上方的线
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("\n\n\n");

	printf("                                       学  生  信  息  管  理  系  统\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");

	printf("                                 大一 C 语言大作业 / Yuuki Asuna小组 制作\n\n\n");
	printf("                                              组长：吴瀚\n\n");
	printf("                                              组员：陈潇涵 李岩\n\n\n\n\n\n");

	printf("                      本项目已开源至 GitHub，https://github.com/wuhan005/SIMS_Homework\n\n");
	printf("                          采用 GNU General Public License v3.0 开源许可协议进行许可");


	printf("\n\n\n\n\n\n\n\n\n\n");

	//下方的线
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("按下 B 返回到主菜单\n");
}

int loadAboutPage() {
	while (1) {

		drawAboutPage();	//绘制界面

		char ch = getchar();

		if (ch == 'B' || ch == 'b') {
			return 0;
			break;
		}

		//去除多余字符，直到换行符。等待下一次输入。
		while (ch != '\n') {
			ch = getchar();
		}
	}
}