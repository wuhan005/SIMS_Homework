#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void searchData(void);

char **dbResult;	//返回的查询数据
char input[50];     //用户输入的查询内容
int isFirst = 1;

int loadSearchInfoPage(void) {
	while (1) {
		system("cls");

		//上方的线
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   查  询  学  生  信  息\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}
		printf("\n\n");

		printf(" 学号   姓名        年龄  性别   出生年月     电话          E-Mail              地址\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n");

		searchData(input);		//显示查询的数据数据

		printf("\n");

		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n输入要查询的学生姓名或学号\n输入 /exit 返回首页\n\n");

        scanf("%s", input);
        isFirst = 0;

        if(strcmp(input, "/exit") == 0){  //退出指令
            return 0;
        }
	}

	return 0;
}

static void searchData(char _input[50]){
    if(isFirst){    //第一次查询
        printf("          请输入数据");
    }else{
        sqlite3 *db = 0;	//数据库
        int ret = 0;	//反馈值
        char *errmsg = 0;
        int rowNum, columnNum, index;

        sqlite3_open("./student.db", &db);	//连接数据库

        char query[200] = "SELECT * FROM `Students` WHERE `ID` = '";
        strcat(query, _input);
        strcat(query, "' OR `Name` = '");
        strcat(query, _input);
        strcat(query, "'");

        ret = sqlite3_get_table(db, query, &dbResult, &rowNum, &columnNum, &errmsg);
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
}