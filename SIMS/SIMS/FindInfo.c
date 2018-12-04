//查询数据
#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

//int nowIndex = 0;
//int dataCount = 0;

int loadFindInfoPage(void) {

	//sqlite3_open("./student.db", &db);	//连接数据库

	while (1) {
		system("cls");

		//上方的线
		printf("=============================================================================================================="
			"\n\n                                           >   查  询  学  生  信  息\n\n"
			"=============================================================================================================="
			"\n\n"
			);

		char inputID[50];

		printf("\n\n"
			"请输入要查询的学生的学号或姓名\n输入 /exit 返回首页\n\n");

		scanf("%s", inputID);

		if (strcmp(inputID, "/exit") == 0) {	//输入退出指令
			return 0;
		}else {
			
		}

	}

	return 0;
}