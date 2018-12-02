#pragma once
#include "sqlite3.h"
//���ѧ����Ϣ

void printForm(int nowIndex);
int ScriptCheck(char _input[50]);

char inputData[8][50];	//������ֶ�
int nowInputIndex = 0;
char tips[50] = { "" };		//������ʾ

//���ݿ�
sqlite3 *db = 0;
int ret = 0;
const char *sql_create_table = "create table t(id int primary key,msg varchar(128))";
char *errmsg = 0;


void initDatabase() {
	ret = sqlite3_open("./student.db", &db);
	ret = sqlite3_exec(db, sql_create_table, NULL, NULL, &errmsg);
	sqlite3_free(errmsg);
	sqlite3_close(db);
}


int loadAddInfoPage(void) {
	initDatabase();
	
	//ÿ�ν���ʱ������ϴε�����
	for (int i = 0; i < 8; i++) {
		strcpy(inputData[i], "");
	}
	nowInputIndex = 0;


	while (1){
		system("cls");

		//�Ϸ�����
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   ¼  ��  ѧ  ��  ��  Ϣ\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n");

		printForm(nowInputIndex);

		printf("\n\n\n");

		//����ָ��
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}
		printf("\n\n             /save ����          /up ��һ���ֶ�          /down ��һ���ֶ�          /exit ����\n\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("\n\n   %s", tips);		//��ʾ

		printf("\n\n");


		// =============== UI ================= //

		char userInput[50];		//�û������ֵ
		scanf("%s", userInput);

		int scriptFlag = ScriptCheck(userInput);

		if (scriptFlag == 0) {		//�û�����������
			strcpy(inputData[nowInputIndex], userInput);		//�޸��ֶ�

			if (nowInputIndex == 7) {
				nowInputIndex = 0;
			}else {
				nowInputIndex++;
			}

		}
		else if (scriptFlag == 1) {

		}else if (scriptFlag == -1) {		//�˳���ָ��
			return 0;
		}

	}
}

//��ӡ����ı�
void printForm(int nowIndex) {

	char inputField[8][50] = { "ѧ��", "����", "����", "�Ա�", "��������", "�绰", "E-Mail", "��ַ" };	//�ֶ���ʾ

	for (int i = 0; i < 8; i++) {
		if (nowIndex == i) {
			printf("              > ");
		}else {
			printf("                ");
		}

		printf("%s�� %s\n\n", inputField[i], inputData[i]);
	}
}

//����û�������Ƿ���ָ��
int ScriptCheck(char _input[50]) {
	strcpy(tips, "");	//�����һ�ε���ʾ

	char instruction[5][10] = {
		"/exit",
		"/save",
		"/up",
		"/down",
	};

	int insCode = -1;

	if (_input[0] != '/') {		//�ж��û�������Ƿ���ָ��
		return 0;
	}

	for (int i = 0; i < 5; i++) {		//��������û������ָ��
		if (!strcmp(_input, instruction[i])) {
			insCode = i;
			break;
		}
	}

	if (insCode == -1) {
		strcpy(tips, "�������ָ������");
		return 1;
	}

	switch (insCode) {
	case 0:
		return -1;		//EXIT
		break;
	case 1:
		break;
	case 2:	//UP
		if (nowInputIndex != 0) {
			nowInputIndex--;
		}else {
			nowInputIndex = 7;
		}
		break;
	case 3:		//DOWN
		if (nowInputIndex != 7) {
			nowInputIndex++;
		}else{
			nowInputIndex = 0;
		}
		break;
	}
	return 1;
}