#include <cstdio>
#include <cstring>
#include <conio.h>
#include <windows.h>

void yasuo() {
	char password[100];
	bool flag = 0;
	printf("是否设置密码？\n>0 是\n>1 否\n");
	scanf("%d", &flag);
	if (!flag) {
		printf("设置密码:");
		scanf("%s", password);
	}
	system("cls");
	printf("删除原压缩文件...\n");
	system("del blog.rar");
	FILE *list = std::fopen("data//list.yml","r");
	if (!list) {
		printf("无路径文件！\n"); 
	}
	else {
		char s[105];
		while (std::fscanf(list, "%s", s) != EOF) {
			printf("压缩%s...\n", s);
			char s_[205] = "WinRAR.exe";
			if (!flag) {
				strcat(s_, " -hp");
				strcat(s_, password);
			}
			strcat(s_, " a blog ");
			strcat(s_, s);
			system(s_);
		}
	}
	fclose(list);
	printf("按任意键继续\n"); 
	while (!_kbhit());
	_getch();
	return;
}

void hexogd() {
	system("hexo clean");
	system("hexo g -d");
	printf("按任意键继续\n"); 
	while (!_kbhit());
	_getch();
	return;
}

void hexos() {
	system("start http:////localhost:4000/");
	system("hexo s");
	return;
}

void generatessh() {
	system("ssh-keygen -t rsa -C \"liu_zhou_zhou@163.com\"");
	return; 
}

void LFwillbe() {
	system("git config --global core.autocrlf false");
	return;
}

void migrationassistant() {
	//system("npm install npm -g");
	system("npm install");
	system("npm install hexo -g");
	system("npm install hexo-deployer-git --save");
	system("npm install hexo-generator-feed --save");
	system("npm install hexo-generator-sitemap --save");
	system("git config --global user.email \"liu_zhou_zhou@163.com\"");
	system("git config --global user.name \"liuzhoulin\"");
}


int main() {
	int a;
	while (1) {
		printf(">1 压缩博客根目录\n>2 部署博客\n>3 本地预览博客\n>4 生成ssh秘钥\n>5 修复LF-will-be-replaced-by-CRLF-in-ans问题\n>6 搬迁助手\nCtrl+C 退出\n");
		scanf("%d", &a);
		system("cls");
		if (a == 1) {
			yasuo();
		} else if (a == 2) {
			hexogd();
		} else if (a == 3) {
			hexos();
		} else if (a == 4) {
			generatessh();
		} else if (a == 5) {
			LFwillbe();
		} else if (a == 6) {
			migrationassistant();
		}
		system("cls");
	}
	return 0;
} 
