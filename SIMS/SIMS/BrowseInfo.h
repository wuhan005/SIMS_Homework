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
		printf("\n\n");

		printf("   学号     姓名  年龄   性别     出生年月          电话              E-Mail                    地址\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n");

		showData();		//显示数据

		printf("\n");

		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n 输入任意键来返回 \n\n");
		getchar();

		return 0;
	}

	return 0;
}

//显示数据
void showData(void) {
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
			printf("%7s%9s%6s%7s%13s%14s%20s%32s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5], dbResult[index + 6], dbResult[index + 7]);
			index += 8;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}