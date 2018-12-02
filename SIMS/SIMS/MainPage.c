#define winConls 110
#define winLines 35

//绘制首页菜单
void drawMainPageMeau() {

	//菜单项
	char meau[8][50] = {
		"录入学生信息",
		"浏览学生信息",
		"查询学生信息",
		"修改学生信息",
		"删除学生信息",
		"关于",
		"退出",
	};

	for (int i = 0; i < 7; i++) {

		//每一行第一个要加空格到中间
		if (i % 2 == 0) {
			printf("                                  ");
		}

		printf("%d - %s        ", i, meau[i]);

		//两个一行，判断是否换行
		if ((i + 1) % 2 == 0) {
			printf("\n\n");
		}
	}

	printf("\n");	//不打扰接下来的内容

}

//绘制首页UI
void drawMainPageUI() {
	system("cls");

	//上方的线
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("\n\n\n");

	printf("                                       学  生  信  息  管  理  系  统\n\n");
	printf("                                  Student Information Manage System (SIMS)\n\n\n");


	//猫咪 字符画
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


	//下方的线
	for (int i = 0; i < winConls; i++) {
		printf("=");
	}

	printf("请输入您的选择：\n");
}