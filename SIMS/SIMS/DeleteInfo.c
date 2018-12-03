//ɾ����Ϣ
#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void deleteData(char _ID[]);
static void showData(void);

int nowIndex = 0;
int dataCount = 0;

sqlite3 *db = 0;	//���ݿ�
int ret = 0;	//����ֵ
char *errmsg = 0;
char **dbResult;	//���صĲ�ѯ����
int rowNum, columnNum, index;

int loadDeleteInfoPage(void) {

	sqlite3_open("./student.db", &db);	//�������ݿ�

	while (1) {
		system("cls");

		//�Ϸ�����
		printf("=============================================================================================================="
			   "\n\n                                           >   ɾ  ��  ѧ  ��  ��  Ϣ\n\n"
			   "=============================================================================================================="
		       "\n\n"
			   "   ѧ��   ����        ����  �Ա�   ��������     �绰          E-Mail              ��ַ\n"
			   "--------------------------------------------------------------------------------------------------------------");

		printf("\n");

		showData();		//��ʾ����

		printf("\n");
		printf("--------------------------------------------------------------------------------------------------------------");

		char inputID[50];

		printf("\n\n"
			"������Ҫɾ����ѧ����ѧ��\n\n");

		scanf("%s", inputID);

		if (strcmp(inputID, "/exit") == 0) {	//�����˳�ָ��

		}
		deleteData(inputID);

		//getchar();

		//return 0;
	}

	return 0;
}

static void deleteData(char _ID[50]) {
	char query[50] = "DELETE FROM `Students` WHERE `ID` = '";
		strcat(query, _ID);
		strcat(query, "'");

	ret = sqlite3_exec(db, query, &dbResult, &rowNum, &columnNum, &errmsg);
}

//��ʾ����
static void showData(void) {
	ret = sqlite3_get_table(db, "SELECT * FROM `Students`", &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		index = columnNum;
		dataCount = columnNum;
		for (int i = 0; i < rowNum; i++) {
			if (nowIndex == i) {
				printf(" > %-7s%-12s%-6s%-7s%-13s%-14s%-20s%-28s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5], dbResult[index + 6], dbResult[index + 7]);
			}else {
				printf("   %-7s%-12s%-6s%-7s%-13s%-14s%-20s%-28s", dbResult[index], dbResult[index + 1], dbResult[index + 2], dbResult[index + 3], dbResult[index + 4], dbResult[index + 5], dbResult[index + 6], dbResult[index + 7]);
			}
			index += 8;
			printf("\n");
		}
	}
	sqlite3_free_table(dbResult);
}