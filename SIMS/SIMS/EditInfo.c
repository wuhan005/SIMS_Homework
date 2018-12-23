//�޸���Ϣ
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

		//�Ϸ�����
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   ��  ��  ѧ  ��  ��  Ϣ\n\n");

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

		printf("\n\n ������Ҫ�޸ĵ�ѧ��ѧ�� \n\n");

		char editID[20];
		scanf("%s", editID);

		editDetail(editID);		//�޸���ϸҳ �޸�
	}

	return 0;
}

//�޸���ϸҳ
static int editDetail(char _ID[20]) {

	int nowIndex = 0;	//��ǰ��������
	char stuData[8][50];	//ѧ����Ϣ
	char _input[50];

	sqlite3 *db = 0;	//���ݿ�
	int ret = 0;	//����ֵ
	char *errmsg = 0;
	char **dbResult;	//���صĲ�ѯ����
	char sqlQuery[50] = "SELECT * FROM `Students` WHERE `ID` = '";	//SQL���
	int rowNum, columnNum;

	sqlite3_open("./student.db", &db);	//�������ݿ�
	strcat(sqlQuery, _ID);
	strcat(sqlQuery, "'");

	//======================= �������ݿ���ϸѧ����Ϣ =======================
	ret = sqlite3_get_table(db, sqlQuery, &dbResult, &rowNum, &columnNum, &errmsg);
	if (ret == SQLITE_OK) {
		for (int i = 0; i < 8; i++) {
			//�����ݼ��뵽 stuData
			strcpy(stuData[i], dbResult[i + 8]);
		}
		sqlite3_free_table(dbResult);
	}

	while (1) {
		system("cls");

		//======================= UI =======================
		//�Ϸ�����
		printf("=============================================================================================================");

		printf("\n\n                                           >   ��  ��  ѧ  ��  ��  Ϣ\n\n");

		printf("=============================================================================================================");

		printf("\n\n");

		//======================= UI =======================


		//======================= ��ʾ�� =======================
		char inputField[8][50] = { "ѧ��", "����", "����", "�Ա�", "��������", "�绰", "E-Mail", "��ַ" };	//�ֶ���ʾ
		for (int i = 0; i < 8; i++) {
			if (nowIndex == i) {
				printf("              > ");
			}
			else {
				printf("                ");
			}

			printf("%s�� %s\n\n", inputField[i], stuData[i]);
		}

		printf("\n");

		printf("\n\n");

		scanf("%s", &_input);

		//����
		char instruction[5][10] = {
			"/exit",
			"/save",
			"/up",
			"/down",
		};

		int insCode = -1;

		if (_input[0] != '/') {		//�ж��û�������Ƿ���ָ��
			strcpy(stuData[nowIndex], _input);	//����Ĳ���ָ������ֶ�ֵ
			continue;
		}

		for (int i = 0; i < 4; i++) {		//��������û������ָ��
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