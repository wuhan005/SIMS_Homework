//修改信息
#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void showData(void);
static int editDetail(char _ID[20]);

int loadEditInfoPage(void) {
	while (1) {
		system("cls");

		//上方的线
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   修  改  学  生  信  息\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}
		printf("\n\n");

		printf(" 学号   姓名        年龄  性别   出生年月     电话          E-Mail              地址\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n");

		showData();		//显示数据

		printf("\n");

		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n 请输入要修改的学生学号 \n\n");

		char editID[20];
		scanf("%s", editID);

		editDetail(editID);		//修改详细页 修改
	}

	return 0;
}

//修改详细页
static int editDetail(char _ID[20]) {

	int nowIndex = 0;	//当前操作索引
	char stuData[8][50];	//学生信息
	char _input[50];

	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;
	char **dbResult;	//返回的查询数据
	char sqlQuery[50] = "SELECT * FROM `Students` WHERE `ID` = '";	//SQL语句
	int rowNum, columnNum;

	sqlite3_open("./student.db", &db);	//连接数据库
	strcat(sqlQuery, _ID);
	strcat(sqlQuery, "'");

	//======================= 加载数据库详细学生信息 =======================
	ret = sqlite3_get_table(db, sqlQuery, &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		for (int i = 0; i < 8; i++) {
			//将数据加入到 stuData
			strcpy(stuData[i], dbResult[i + 8]);
		}
		sqlite3_free_table(dbResult);
	}

	while (1) {
		system("cls");

		//======================= UI =======================
		//上方的线
		printf("=============================================================================================================");

		printf("\n\n                                           >   修  改  学  生  信  息\n\n");

		printf("=============================================================================================================");

		printf("\n\n");

		//======================= UI =======================


		//======================= 显示表单 =======================
		char inputField[8][50] = { "学号", "姓名", "年龄", "性别", "出生年月", "电话", "E-Mail", "地址" };	//字段提示
		for (int i = 0; i < 8; i++) {
			if (nowIndex == i) {
				printf("              > ");
			}
			else {
				printf("                ");
			}

			printf("%s： %s\n\n", inputField[i], stuData[i]);
		}

		printf("\n");

		printf("\n\n");

		scanf("%s", &_input);

		//控制
		char instruction[5][10] = {
			"/exit",
			"/save",
			"/up",
			"/down",
		};

		int insCode = -1;

		if (_input[0] != '/') {		//判断用户输入的是否是指令
			strcpy(stuData[nowIndex], _input);	//输入的不是指令，更新字段值
			continue;
		}

		for (int i = 0; i < 4; i++) {		//遍历检测用户输入的指令
			if (!strcmp(_input, instruction[i])) {
				insCode = i;
				break;
			}
		}

		if (insCode == 0) {
			break;
		}

		if (insCode == 1) {

			break;
		}

		switch (insCode) {
			case 2:
				
				break;
			case 3:

				break;
		}


	}

}

//显示数据
static void showData(void) {
	sqlite3 *db = 0;	//数据库
	int ret = 0;	//反馈值
	char *errmsg = 0;
	char **dbResult;	//返回的查询数据
	int rowNum, columnNum, index;

	sqlite3_open("./student.db", &db);	//连接数据库

	ret = sqlite3_get_table(db, "SELECT * FROM `Students`", &dbResult, &rowNum, &columnNum, &errmsg);
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