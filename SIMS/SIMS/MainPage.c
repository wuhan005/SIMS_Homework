#define winConls 110
#define winLines 35

//������ҳ�˵�
void drawMainPageMeau() {

	//�˵���
	char meau[8][50] = {
		"¼��ѧ����Ϣ",
		"���ѧ����Ϣ",
		"��ѯѧ����Ϣ",
		"�޸�ѧ����Ϣ",
		"ɾ��ѧ����Ϣ",
		"����",
		"�˳�",
	};

	for (int i = 0; i < 7; i++) {

		//ÿһ�е�һ��Ҫ�ӿո��м�
		if (i % 2 == 0) {
			printf("                                  ");
		}

		printf("%d - %s        ", i, meau[i]);

		//����һ�У��ж��Ƿ���
		if ((i + 1) % 2 == 0) {
			printf("\n\n");
		}
	}

	printf("\n");	//�����Ž�����������

}

//������ҳUI
void drawMainPageUI() {
	system("cls");

	//�Ϸ�����
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("\n\n\n");

	printf("                                       ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");


	//è�� �ַ���
	printf("                                                          ,\n");
	printf("                                                        _/((\n");
	printf("                                               _.---. .'    `\\\n");
	printf("                                             .'       `      =^ \n");
	printf("                                            /      \\        .--'\n");
	printf("                                           |       /        )'-.\n");
	printf("                                           ; ,    <__..-(    '-.)\n");
	printf("                                            \\ \\-.__)     ``--._)\n");
	printf("                                             '.'-.__.-.\n");
	printf("                                               '-...-'   \n");


	printf("\n\n\n");

	drawMainPageMeau();

	printf("\n\n");

	printf("                                                              Copyright (c) 2018 John Wu / C Homework Project.\n");


	//�·�����
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("����������ѡ��\n");
}