#include <cstdio>
#include <cstring>
#include <conio.h>
#include <windows.h>

void yasuo() {
	char password[100];
	bool flag = 0;
	printf("�Ƿ��������룿\n>0 ��\n>1 ��\n");
	scanf("%d", &flag);
	if (!flag) {
		printf("��������:");
		scanf("%s", password);
	}
	system("cls");
	printf("ɾ��ԭѹ���ļ�...\n");
	system("del blog.rar");
	FILE *list = std::fopen("data//list.yml","r");
	if (!list) {
		printf("��·���ļ���\n"); 
	}
	else {
		char s[105];
		while (std::fscanf(list, "%s", s) != EOF) {
			printf("ѹ��%s...\n", s);
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
	printf("�����������\n"); 
	while (!_kbhit());
	_getch();
	return;
}

void hexogd() {
	system("hexo clean");
	system("hexo g -d");
	printf("�����������\n"); 
	while (!_kbhit());
	_getch();
	return;
}

void hexos() {
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
		printf(">1 ѹ�����͸�Ŀ¼\n>2 ���𲩿�\n>3 ����Ԥ������\n>4 ����ssh��Կ\n>5 �޸�LF-will-be-replaced-by-CRLF-in-ans����\n>6 ��Ǩ����\nCtrl+C �˳�\n");
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
