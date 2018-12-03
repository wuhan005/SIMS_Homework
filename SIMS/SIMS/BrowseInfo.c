#define winConls 110
#define winLines 35

#include <stdio.h>
#include <windows.h>

#include "sqlite3.h"

static void showData(void);

int loadBrowseInfoPage(void) {
	while (1) {
		system("cls");

		//�Ϸ�����
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   �  ��  ѧ  ��  ��  Ϣ\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}
		printf("\n\n");

		printf(" ѧ��   ����        ����  �Ա�   ��������     �绰          E-Mail              ��ַ\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n");

		showData();		//��ʾ����

		printf("\n");

		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n ��������������� \n\n");

		getch();
		while (kbhit()){        // ����Ƿ��а���
			getch();      //��ȡ�����ַ�
		}

		return 0;
	}

	return 0;
}

//��ʾ����
static void showData(void) {
	sqlite3 *db = 0;	//���ݿ�
	int ret = 0;	//����ֵ
	char *errmsg = 0;
	char **dbResult;	//���صĲ�ѯ����
	int rowNum, columnNum, index;

	sqlite3_open("./student.db", &db);	//�������ݿ�

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