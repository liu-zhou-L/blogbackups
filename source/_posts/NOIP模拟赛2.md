title: NOIP模拟赛2
author: liu_zhou
abbrlink: da1ae537
tags:
  - 模拟
categories:
  - 测试
mathjax: true
date: 2020-07-27 21:42:00
---
# 字符串的展开

## 题目链接

[luoguP1098](https://www.luogu.com.cn/problem/P1098)

## 分析

简单模拟，按照题目要求来一步步实现即可

## AC代码

```cpp
#include <cstdio>
#include <cstring>

const int MAXN = 20005;

int cmd1, cmd2, cmd3, len;
char s[MAXN];

bool check_char (int x) {//判断是否满足字符串展开的条件
	return s[x] == '-' && s[x - 1] >= 'a' && s[x - 1] <= 'z' && s[x + 1] >= 'a' && s[x + 1] <= 'z' && s[x - 1] < s[x + 1];
}

bool check_num (int x) {//判断是否满足数字展开的条件
	return s[x] == '-' && s[x - 1] >= '0' && s[x - 1] <= '9' && s[x + 1] >= '0' && s[x + 1] <= '9' && s[x - 1] < s[x + 1];
}

int main() {
	//freopen("expand.in", "r", stdin);
	//freopen("expand.out", "w", stdout);
	scanf("%d%d%d", &cmd1, &cmd2, &cmd3);
	scanf("%s", s + 1);
	len = strlen(s + 1);
	putchar(s[1]);//第一个和最后一个元素单独处理
	for (int i = 2; i < len; i++) {//核心代码，按照题意来即可
		if (check_char(i)) {//字符展开的情况
			if (cmd3 == 1) {
				for (int j = s[i - 1] + 1; j <= s[i + 1] - 1; j++) {
					for (int k = 1; k <= cmd2; k++) {
						if (cmd1 == 1) {
							//printf("%c", j);
							putchar(j);
						} else if (cmd1 == 2) {
							//printf("%c", j - 32);
							putchar(j - ('a' - 'A'));
						} else if (cmd1 == 3) {
							//printf("*");
							putchar('*');
						}
					}
				}
			} else if (cmd3 == 2) {
				for (int j = s[i + 1] - 1; j >= s[i - 1] + 1; j--) {
					for (int k = 1; k <= cmd2; k++) {
						if (cmd1 == 1) {
							//printf("%c", j);
							putchar(j);
						} else if (cmd1 == 2) {
							//printf("%c", j - 32);
							putchar(j - ('a' - 'A'));
						} else if (cmd1 == 3) {
							//printf("*");
							putchar('*');
						}
					}
				}
			}
		} else if (check_num(i)) {//数字展开的情况
			if (cmd3 == 1) {
				for (int j = s[i - 1] + 1; j <= s[i + 1] - 1; j++) {
					for (int k = 1; k <= cmd2; k++) {
						if (cmd1 == 3) {
							//printf("*");
							putchar('*');
						} else {
							//printf("%c", j);
							putchar(j);
						}
					}
				}	
			} else if (cmd3 == 2) {
				for (int j = s[i + 1] - 1; j >= s[i - 1] + 1; j--) {
					for (int k = 1; k <= cmd2; k++) {
						if (cmd1 == 3) {
							//printf("*");
							putchar('*');
						} else {
							//printf("%c", j);
							putchar(j);
						}
					}
				}	
			}
		} else {//都不满足输出原字符
			//printf("%c", s[i]);
			putchar(s[i]);
		}
	}
	putchar(s[len]);
	return 0;
} 
```


---


# 作业调度方案

## 题目链接

[luoguP1065](https://www.luogu.com.cn/problem/P1065)

## 分析

按照题目所说的暴力即可，`ntime[i]`表示第 $ i $ 件物品当前最晚的完成时间，每一都从最晚的时间往后推，用一个`flag[i][j]`数组标记第 $ i $ 台机器在第 $ j $ 时是否被占用，只要没被占用就安排上

因为物品必须连续加工，中间断了一次便需要从头开始

最后对 $ ntime $ 遍历找到最大值便是答案

## AC代码(洛谷99分)

```cpp
#include <cstdio>
#include <algorithm>

int m ,n, ans = 0, s= 0, machine[25], works[505], time[25][25], ntime[25], need[25][25];
bool flag[25][505];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m * n; i++) {
		scanf("%d", &works[i]);//输入安排顺序
	}
	for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d",&need[i][j]);//第i个工件在第j道工序需要什么机器 
		}
	}
	for(int i = 1; i <= n; i++) {~
        for(int j = 1; j <= m; j++) {
            scanf("%d",&time[i][j]);//第i个工件在第j道工序时的加工时间 
		}
	}
	for (int i = 1; i <= m * n; i++) {
		machine[works[i]]++;
		for (int j = ntime[works[i]] + 1;;j++) {//从空闲时开始遍历 
			if (!flag[need[works[i]][machine[works[i]]]][j])//未占用
				s++;//时间++ 
			else
				s = 0;//因为要连续，所以只要有一点不能使用就重来 
			if (s == time[works[i]][machine[works[i]]]) {//时间足够 
				for (int k = j - s + 1; k <= j; k++){
                    flag[need[works[i]][machine[works[i]]]][k] = 1;//标记为已用 
				}
                ntime[works[i]]=j;//完成时间 
                s = 0;
                break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, ntime[i]);//遍历完成时间取最大值 
	}
	printf("%d", ans);
	return 0;
}
```

# 火柴棒等式

## 题目链接

[luoguP1149](https://www.luogu.com.cn/problem/P1149)

## 分析

简单的暴力，枚举加数 $ a $ 和 $ b $ ， $ c $ 等于 $ a+b $ ，再拆分每一个数，算出火所需火柴棍的总数，等于 $ n-4 $ 就ans++

## AC代码

```cpp
#include <cstdio>

const int NUM[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//每一个数字所需的火柴数

int n, ans = 0;

int chai(int x) {
	int ret = 0;
	if (x == 0) return NUM[0];
	while (x) {//求出每一位的火柴棍数量
		ret += NUM[x % 10];
		x /= 10;
	}
	return ret;
}

int main() {
	//freopen("matches.in", "r", stdin);
	//freopen("matches.out", "w", stdout);
	scanf("%d", &n);
//	if (n < 13) {
//		printf("0");
//	} else if (n == 13) {
//		printf("1");
//	} else if (n == 14) {
//		printf("2");
//	} else if (n == 15) {
//		printf("8");
//	} else if (n == 16) {
//		printf("9");
//	} else if (n == 17) {
//		printf("6");
//	} else if (n == 18) {
//		printf("9");
//	} else if (n == 19) {
//		printf("29");
//	} else if (n == 20) {
//		printf("39");
//	} else if (n == 21) {
//		printf("38");
//	} else if (n == 22) {
//		printf("65");
//	} else if (n == 23) {
//		printf("88");
//	} else if (n == 24) {
//		printf("128");
//	}
	n -= 4;//减去加号和等号的火柴
	for (int i = 0; i <= 999; i++) {//可以判断，i和j必定小于999
		for (int j = 0; j <= 999; j++) {
			int k = i + j;
			if (chai(i) + chai(j) + chai(k) == n) {
				//printf("%d(%d)+%d(%d)=%d(%d)\n", i, chai(i), j, chai(j), k, chai(k));
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
```

# 数三角

## 题目链接

[八中OJ-3202](http://222.180.160.110:1024/problem/3202)

## 分析

由 C2021ljs 提供。

首先在输入进来时，我们将所有的坐标过大两倍，也就是将每个网格又分成四个小格。这样的好处是什么呢？这样的话，在整个过程中就不会图(c)中被划分出的小三角形。

然后对于输入进来的木棍，我们需要标记它们连通（即之间有木棍），并且它们与木棍的中点也是连通的（网格过大后产生的），所以在输入时，我们可以将这些一起处理了。

```cpp
int lx[25][25][25][25];	//lx[i][j][x][y]表示(i,j)(x,y)之间有连线，连通

for (int i = 1; i <= n; i++) {
		int a, b, x, y;
		scanf("%d %d %d %d", &a, &b, &x, &y);
		a <<= 1; b <<= 1; x <<= 1; y <<= 1;
		lx[a][b][(a + x) >> 1][(b + y) >> 1] = 1; 
		lx[(a + x) >> 1][(b + y) >> 1][a][b] = 1; 
		lx[x][y][(a + x) >> 1][(b + y) >> 1] = 1; 
		lx[(a + x) >> 1][(b + y) >> 1][x][y] = 1; 
		//(a,b),(x,y)连线的中点坐标为((a+x)/2,(b+y)/2)
		lx[a][b][x][y] = 1;
		lx[x][y][a][b] = 1;
	}
```

接下来我们可以想， $ a $ 点与 $ b $ 点连通， $ a $ 点又与 $ c $ 点连通，那么只要 $ a,b,c $ 共线的话， $ b,c $ 不也连通（之间用木棍连接）吗？

所以我们可以枚举 $ b,c $ ,在枚举中转点  $ a $ ，再进行判断即可。

如何判断 $ a,b,c $ 共线呢？因为 $ a $ 点与 $ b $ 点连通， $ a $ 点又与 $ c $ 点连通(这也是Floyd最短路的核心思想)，所以只用判断 $ ab $ 与 $ ac $ ，斜率相同就行了(关于斜率，请自行学习一次函数)

斜率公式 $ k=\frac{y2-y1}{x2-x1}$

将坐标带入，即：

```cpp
for (int i = 0; i <= 18; i++)
	for (int j = 0; j <= 18; j++)
		for (int x = 0; x <= 18; x++)
			for (int y = 0; y <= 18; y++)
				for (int l = 0; l <= 18; l++)
					for (int r = 0; r <= 18; r++)
						if (lx[i][j][x][y] && lx[i][j][l][r] && check(i, j, x, y) 
						&& check(i, j, l, r) && ((r - j) * (x - i) == (y - j) * (l - i))) {
							lx[x][y][l][r] = 1;
							lx[l][r][x][y] = 1;
						}
```
扩大后的网格任意两点连线求完了，我们就可以枚举任意三个互不相同的点，只要三点中任意两点之间有连线且三点不共线，就能构成三角形。


## AC代码

```cpp
#include <cstdio>

const int MAXN = 35;

int n, ans = 0;
bool flag[MAXN][MAXN][MAXN][MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a[10];
		scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
		a[1] *= 2, a[2] *= 2, a[3] *= 2, a[4] *= 2;
		if (a[3] + a[4] - a[1] - a[2] == 2) {
			if (a[2] == a[4]) {
				flag[a[1] + 1][a[2]][a[3]][a[2]] = 1;
				flag[a[3]][a[2]][a[1] + 1][a[2]] = 1;
				flag[a[1] + 1][a[2]][a[1]][a[2]] = 1;
				flag[a[1]][a[2]][a[1] + 1][a[2]] = 1;
			} else if (a[1] == a[3]) {
				flag[a[1]][a[2] + 1][a[1]][a[4]] = 1;
				flag[a[1]][a[4]][a[1]][a[2] + 1] = 1;
				flag[a[1]][a[2] + 1][a[1]][a[2]] = 1;
				flag[a[1]][a[2]][a[1]][a[2] + 1] = 1;
			}	
		}
		if (a[1] + a[2] - a[3] - a[4] == 2){
			if (a[2] == a[4]) {
				flag[a[1]][a[2]][a[3] + 1][a[2]] = 1;
				flag[a[3] + 1][a[2]][a[1]][a[2]] = 1;
				flag[a[3]][a[2]][a[3] + 1][a[2]] = 1;
				flag[a[3]][a[2]][a[3] + 1][a[2]] = 1;
			} else if (a[1] == a[3]) {
				flag[a[1]][a[2]][a[1]][a[4] + 1] = 1;
				flag[a[1]][a[4] + 1][a[1]][a[2]] = 1;
				flag[a[1]][a[4] + 1][a[1]][a[4]] = 1;
				flag[a[1]][a[4]][a[1]][a[4] + 1] = 1;
			}	
		}
		if (a[1] + a[2] - a[3] - a[4] == 4) {
			flag[a[3] + 1][a[4] + 1][a[1]][a[2]] = 1;
			flag[a[1]][a[2]][a[3] + 1][a[4] + 1] = 1;
			flag[a[3]][a[4]][a[3] + 1][a[4] + 1] = 1;
			flag[a[3] + 1][a[4] + 1][a[3]][a[4]] = 1;
		}
		if (a[3] + a[4] - a[1] - a[2] == 4) {
			flag[a[1] + 1][a[2] + 1][a[3]][a[4]] = 1;
			flag[a[3]][a[4]][a[1] + 1][a[2] + 1] = 1;
			flag[a[1]][a[2]][a[1] + 1][a[2] + 1] = 1;
			flag[a[1] + 1][a[2] + 1][a[1]][a[2]] = 1;
		}
		if (a[1] + a[2] == a[3] + a[4]) {
			flag[a[1]][a[2]][(a[1] + a[3]) / 2][(a[2] + a[4]) / 2] = 1;
			flag[(a[1] + a[3]) / 2][(a[2] + a[4]) / 2][a[1]][a[2]] = 1;
			flag[a[3]][a[4]][(a[1] + a[3]) / 2][(a[2] + a[4]) / 2] = 1;
			flag[(a[1] + a[3]) / 2][(a[2] + a[4]) / 2][a[3]][a[4]] = 1;
		}
		flag[a[1]][a[2]][a[3]][a[4]] = 1;
		flag[a[3]][a[4]][a[1]][a[2]] = 1;
	}
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			for (int k = 0; k <= 18; k++) {
				for (int i1 = 0; i1 <= 18; i1++) {
					for (int j1 = 0; j1 <= 18; j1++) {
						for (int k1 = 0; k1 <= 18; k1++) {
							if (flag[i][i1][j][j1] == 1 && flag[i][i1][k][k1] == 1 && !(i == j && i1 == j1) && !(i == k && i1 == k1)) {
								if ((k1 - i1) * (j - i) - (j1 - i1) * (k - i) == 0) {
									flag[j][j1][k][k1] = 1;
									flag[k][k1][j][j1] = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 18; i++) {  //输出
        for (int j = 0; j <= 18; j++) {
            for (int k = 0; k <= 18; k++) {
                for (int i1 = 0; i1 <= 18; i1++) {
                    for (int j1 = 0; j1 <= 18; j1++) {
                        for (int k1 = 0; k1 <= 18; k1++) {
                            if (flag[i][i1][j][j1] == 1 && flag[i][i1][k][k1] == 1 && flag[j][j1][k][k1] == 1 &&
                                !(i == j && i1 == j1) && !(i == k && i1 == k1) && !(j == k && j1 == k1)) {
                                if ((k1 - i1) * (j - i) - (j1 - i1) * (k - i)) {
                                	ans++;
								}  
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans / 6);
	return 0;
}
```