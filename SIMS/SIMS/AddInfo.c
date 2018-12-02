#include <windows.h>
#include <stdio.h>

#include "sqlite3.h"
#define winConls 110
#define winLines 35

//���ѧ����Ϣ

char inputData[8][50];	//������ֶ�
int nowInputIndex = 0;
char tips[50] = { "" };		//������ʾ

void printForm(int nowIndex);

//������ݵ����ݿ�
void addData(char _data[8][50]) {
	sqlite3 *db = 0;	//���ݿ�
	int ret = 0;	//����ֵ
	char *errmsg = 0;

	char query[2000] = { "" };
	sprintf(query, "INSERT INTO `Students` (`ID`, `Name`, `Age`, `Sex`, `Birth`, `Tel`, `Mail`, `Address`) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')", _data[0], _data[1], _data[2], _data[3], _data[4], _data[5], _data[6], _data[7]);

	ret = sqlite3_open("./student.db", &db);	//�������ݿ�
	ret = sqlite3_exec(db, query, NULL, NULL, &errmsg);	//ִ��SQL
	sqlite3_free(errmsg);
	sqlite3_close(db);		//�Ͽ�����
}

int loadAddInfoPage(void) {

	//ÿ�ν���ʱ������ϴε�����
	for (int i = 0; i < 8; i++) {
		strcpy(inputData[i], "");
	}
	nowInputIndex = 0;


	while (1) {
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
				//nowInputIndex = 0;		//ʵ��ʹ�øо�����Ҫ���
			}
			else {
				nowInputIndex++;
			}

		}
		else if (scriptFlag == 1) {

		}
		else if (scriptFlag == -1) {		//�˳���ָ��
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
		}
		else {
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
		addData(inputData);		//SAVE

								//����ϴε�����
		for (int i = 0; i < 8; i++) {
			strcpy(inputData[i], "");
		}
		nowInputIndex = 0;

		break;
	case 2:	//UP
		if (nowInputIndex != 0) {
			nowInputIndex--;
		}
		else {
			nowInputIndex = 7;
		}
		break;
	case 3:		//DOWN
		if (nowInputIndex != 7) {
			nowInputIndex++;
		}
		else {
			nowInputIndex = 0;
		}
		break;
	}
	return 1;
}