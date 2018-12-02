#pragma once
//添加学生信息

void printForm(int nowIndex);
int ScriptCheck(char _input[50]);

char inputData[8][50];	//输入的字段
int nowInputIndex = 0;

int loadAddInfoPage(void) {
	
	//每次进入时都清空上次的数据
	for (int i = 0; i < 8; i++) {
		strcpy(inputData[i], "");
	}
	nowInputIndex = 0;

	while (1){
		system("cls");

		//上方的线
		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n                                           >   录  入  学  生  信  息\n\n");

		for (int i = 0; i < winConls; i++) {
			printf("=");
		}

		printf("\n\n");

		printForm(nowInputIndex);

		printf("\n\n\n");

		//操作指令
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}
		printf("\n\n             /save 保存          /up 上一个字段          /down 下一个字段          /exit 返回\n\n");
		for (int i = 0; i < winConls; i++) {
			printf("-");
		}

		printf("  --%s", tips);		//提示

		printf("\n\n\n\n");


		// =============== UI ================= //

		char userInput[50];		//用户输入的值
		scanf("%s", userInput);

		int scriptFlag = ScriptCheck(userInput);

		if (scriptFlag == 0) {		//用户输入是数据
			strcpy(inputData[nowInputIndex], userInput);		//修改字段

			if (nowInputIndex == 7) {
				nowInputIndex = 0;
			}else {
				nowInputIndex++;
			}

		}
		else if (scriptFlag == 1) {

		}else if (scriptFlag == -1) {		//退出的指令
			return 0;
		}

	}
}

//打印输入的表单
void printForm(int nowIndex) {

	char inputField[8][50] = { "学号", "姓名", "年龄", "性别", "出生年月", "电话", "E-Mail", "地址" };	//字段提示

	for (int i = 0; i < 8; i++) {
		if (nowIndex == i) {
			printf("              > ");
		}else {
			printf("                ");
		}

		printf("%s： %s\n\n", inputField[i], inputData[i]);
	}
}

//检测用户输入的是否是指令
int ScriptCheck(char _input[50]) {
	char instruction[5][10] = {
		"/exit",
		"/save",
		"/up",
		"/down",
	};

	int insCode = -1;

	for (int i = 0; i < 5; i++) {		//遍历检测用户输入的指令
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