#pragma once
#define winConls 110
#define winLines 35


//������ҳ�˵�
void drawMainPageMeau() {
	
}

//������ҳUI
void drawMainPageUI(void) {
	system("cls");
	
	//�Ϸ�����
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	//����
	for (int i = 0; i < 5; i++) {
		printf("\n");
	}

	printf("                                       ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");


	//è�� �ַ���
	printf("                                                          ,\n");
	printf("                                                        _/((\n");
	printf("                                               _.---. .'    `\\\n");          
	printf("                                             .'       `      =^ \n");
	printf("                                            /      \        .--'\n");
	printf("                                           |       /        )'-.\n");
	printf("                                           ; ,    <__..-(    '-.)\n");
	printf("                                            \ \-.__)     ``--._)\n");
	printf("                                             '.'-.__.-.\n");
	printf("                                               '-...-'   \n");


}