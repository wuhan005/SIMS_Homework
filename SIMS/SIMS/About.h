#pragma once

//����ҳ��

void drawAboutPage(void) {
	system("cls");

	//�Ϸ�����
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("\n\n\n");

	printf("                                       ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");

	printf("                                 ��һ C ���Դ���ҵ / Yuuki AsunaС�� ����\n\n\n");
	printf("                                              �鳤�����\n\n");
	printf("                                              ��Ա�����캭 ����\n\n\n\n\n\n");

	printf("                      ����Ŀ�ѿ�Դ�� GitHub��https://github.com/wuhan005/SIMS_Homework\n\n");
	printf("                          ���� GNU General Public License v3.0 ��Դ���Э��������");


	printf("\n\n\n\n\n\n\n\n\n\n");

	//�·�����
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("���� B ���ص����˵�\n");
}

int loadAboutPage() {
	while (1) {

		drawAboutPage();	//���ƽ���

		char ch = getchar();

		if (ch == 'B' || ch == 'b') {
			return 0;
			break;
		}

		//ȥ�������ַ���ֱ�����з����ȴ���һ�����롣
		while (ch != '\n') {
			ch = getchar();
		}
	}
}