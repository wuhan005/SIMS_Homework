#pragma once
//���ѧ����Ϣ

void printForm(int nowIndex);
int ScriptCheck(char _input[50]);

char inputData[8][50];	//������ֶ�
int nowInputIndex = 0;

int loadAddInfoPage(void) {
	
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

		printf("  --%s", tips);		//��ʾ

		printf("\n\n\n\n");


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
	char instruction[5][10] = {
		"/exit",
		"/save",
		"/up",
		"/down",
	};

	int insCode = -1;

	for (int i = 0; i < 5; i++) {		//��������û������ָ��
		if (!strcmp(_input, instruction[i])) {
			insCode = i;
			break;
		}
	}

	if (insCode == -1) {
		return 0;
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