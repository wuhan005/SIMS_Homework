#pragma once
#define winConls 110
#define winLines 35


//绘制首页菜单
void drawMainPageMeau() {
	
}

//绘制首页UI
void drawMainPageUI(void) {
	system("cls");
	
	//上方的线
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	//换行
	for (int i = 0; i < 5; i++) {
		printf("\n");
	}

	printf("                                       学  生  信  息  管  理  系  统\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");


	//猫咪 字符画
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