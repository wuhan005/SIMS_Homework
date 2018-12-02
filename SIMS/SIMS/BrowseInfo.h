#pragma once

void showData(void);

int loadBrowseInfoPage(void) {
	while (1) {
		system("cls");

		//上方的线
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   浏  览  学  生  信  息\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n   学号     姓名   年龄   性别      出生年月       电话          E-Mail                  地址\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		showData();

		char ch = getchar();

		

		printf("\n\n\n");
	}

	return 0;
}

//显示数据
void showData(void) {
	
}