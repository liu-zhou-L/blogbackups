title: 区间DP
author: liu_zhou
abbrlink: 628fb573
tags:
  - dp
mathjax: true
categories:
  - 算法
date: 2020-07-22 15:09:00
---

# 概念

>区间类动态规划是线性动态规划的扩展，它在分阶段地划分问题时，与阶段中元素出现的顺序和由前一阶段的哪些元素合并而来由很大的关系。令状态 $ f(i,j) $ 表示将下标位置  到  的所有元素合并能获得的价值的最大值，那么 $ f(i,j)=max{f(i,k)+f(k+1,j)+cost} $ ，$ cost $  为将这两组元素合并起来的代价。

# 特点

**合并** ：即将两个或多个部分进行整合，当然也可以反过来；
**特征** ：能将问题分解为能两两合并的形式；
**求解** ：对整个问题设最优值，枚举合并点，将问题分解为左右两个部分，最后合并两个部分的最优值得到原问题的最优值。

# 练习题

## 石子合并1
[石子合并1](http://222.180.160.110:1024/problem/3265)

### 分析

区间DP板题，使用前缀和进行优化，可通过下图进行理解

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9zMS5heDF4LmNvbS8yMDIwLzA3LzE4L1UyTVE5cy5wbmc?x-oss-process=image/format,png)

在此图中，g，h，i，j为题目所给的每堆的重量，k，l，m为长度为二时的最优策略...
如果要求区间k的值，则可以通过区间g和h求出，而点D则为分割点，其它线段以此类推，需要枚举的是分割点，以此最终求出答案

### AC代码
```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;

int n, m[MAXN][MAXN], a[MAXN], s[MAXN] = {};//m[i][j]表示合并第i到第j个元素的最小费用

int qujianhe(int start, int end) { return s[end] - s[start - 1]; }//求区间和

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];//前缀和
	}
	for (int len = 2; len <= n; len++) {//枚举合并的堆数量
		for (int i = 1; i <= n - len + 1; i++) {//枚举合并的第一个元素
			m[i][i + len - 1] = 0x3f3f3f;
			for (int j = i; j < i + len - 1; j++) {//枚举分割的点
				m[i][i + len - 1] = std::min(m[i][i + len - 1], m[i][j] + m[j + 1][i + len - 1] + qujianhe(i, i + len - 1));
				//状态转移方程 m[i][j] = min(m[i][j], m[i][j] + m[k + 1][j] + qujianhe(i, j))
				//m[i][j] + m[k + 1][j]为合并两小堆的分别的代价的和，qujianhe(i, j)为将两小堆合并的代价和
			}
		}
	}
	printf("%d", m[1][n]);
	return 0;
}
```

## 最长回文串

[最长回文串](http://222.180.160.110:1024/problem/7092)

### 分析

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020072021015988.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xpdV96aG91X3pob3U=,size_16,color_FFFFFF,t_70)


![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9zMS5heDF4LmNvbS8yMDIwLzA3LzIwL1U0NU1nUC5wbmc?x-oss-process=image/format,png)

### AC代码
```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 3005;

int strl, f[MAXN][MAXN];
char str[MAXN];

int main() {
	scanf("%s", str);
	strl = strlen(str);
	for (int i = 0; i < strl; i++) {
		f[i][i] = 1;
	}
	for (int len = 2; len <= strl; len++) {
		for (int i = 0; i <= strl - len; i++) {
			if (str[i] == str[i + len - 1]) {
				if (f[i + 1][i + len - 2] == len - 2) {
					f[i][i + len - 1] = len;
				} else {
					f[i][i + len - 1] = std::max(f[i + 1][i + len - 1], f[i][i + len - 2]);
				}
			} else {
				f[i][i + len - 1] = std::max(f[i + 1][i + len - 1], f[i][i + len - 2]);
			}
		} 
	}
	printf("%d", f[0][strl - 1]);
	return 0;
}
```


