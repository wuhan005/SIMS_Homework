#pragma once

void showData(void);

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

		printf("\n   ѧ��     ����   ����   �Ա�      ��������       �绰          E-Mail                  ��ַ\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		showData();

		char ch = getchar();

		

		printf("\n\n\n");
	}

	return 0;
}

//��ʾ����
void showData(void) {
	
}