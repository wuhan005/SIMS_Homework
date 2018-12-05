//删除信息
#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void deleteData(char _ID[]);
static void showData(void);

int dataCount = 0;

sqlite3 *db = 0;	//数据库
int ret = 0;	//反馈值
char *errmsg = 0;
char **dbResult;	//返回的查询数据
int rowNum, columnNum, index;

int loadDeleteInfoPage(void) {

	sqlite3_open("./student.db", &db);	//连接数据库

	while (1) {
		system("cls");

		//上方的线
		printf("=============================================================================================================="
			   "\n\n                                           >   删  除  学  生  信  息\n\n"
			   "=============================================================================================================="
		       "\n\n"
			   "   学号   姓名        年龄  性别   出生年月     电话          E-Mail              地址\n"
			   "--------------------------------------------------------------------------------------------------------------");

		printf("\n");

		showData();		//显示数据

		printf("\n");
		printf("--------------------------------------------------------------------------------------------------------------");

		char inputID[50];

		printf("\n\n"
			"请输入要删除的学生的学号\n输入 /exit 返回首页\n\n");

		scanf("%s", inputID);

		if (strcmp(inputID, "/exit") == 0) {	//输入退出指令
			return 0;
		}else {
			deleteData(inputID);
		}

	}

	return 0;
}

static void deleteData(char _ID[50]) {
	char query[50] = "DELETE FROM `Students` WHERE `ID` = '";
		strcat(query, _ID);
		strcat(query, "'");

	ret = sqlite3_exec(db, query, &dbResult, &rowNum, &columnNum, &errmsg);
}

//显示数据
static void showData(void) {
	ret = sqlite3_get_table(db, "SELECT * FROM `Students`", &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		dataCount = columnNum;
		for (int i = 0; i < rowNum; i++) {
			printf("   %-7s%-12s%-6s%-7s%-13s%-14s%-20s%-28s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5], dbResult[index + 6], dbResult[index + 7]);
			index += 8;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}