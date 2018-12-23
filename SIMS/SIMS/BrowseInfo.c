#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void showData(int);
int nowType = 0;

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
		printf("\n\n");

		printf(" 学号   姓名        年龄  性别   出生年月     电话          E-Mail              地址\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n");

		showData(nowType);		//显示数据

		printf("\n");

		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n 输入 E 来返回 \n");
		printf(" A：按学号排序  B：按年龄排序 \n\n");

		char input = getchar();
		switch(input) {
			case 'E':
			case 'e':
				return 0;
				break;
			case 'A':
			case 'a':
				nowType = 1;
				break;
			case 'B':
			case 'b':
				nowType = 2;
				break;
		}
			
		while (kbhit()){        // 检查是否有按键
			getch();      //读取流中字符
		}

		continue;
	}

	return 0;
}

//显示数据
static void showData(int _type) {
	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;
	char **dbResult;	//返回的查询数据
	int rowNum, columnNum, index;
	
	char sqlQuery[100] = "SELECT * FROM `Students`";

	//设置排序方式
	switch (_type) {
		case 1:
			strcat(sqlQuery, " ORDER BY `ID` ASC");
			break;
		case 2:
			strcat(sqlQuery, " ORDER BY `Age` ASC");
			break;
	}

	sqlite3_open("./student.db", &db);	//连接数据库

	ret = sqlite3_get_table(db, sqlQuery, &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf(" %-7s%-12s%-6s%-7s%-13s%-14s%-20s%-30s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5], dbResult[index + 6], dbResult[index + 7]);
			index += 8;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}