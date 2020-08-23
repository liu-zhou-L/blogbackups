title: 最长上升子序列(LIS)nlogn算法
author: liu_zhou
abbrlink: bf0d03cd
date: 2020-05-16 18:41:38
tags:
---
![](https://img-blog.csdnimg.cn/20200513140620345.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xpdV96aG91X3pob3U=,size_16,color_FFFFFF,t_70#pic_center)
替换其实是为后面的元素让出更多的空间，如果有更小的元素，才能插入，如果没有，则对最终结果也没有影响

```cpp
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int x, f[MAXN], n, ans = 1;//f为答案序列

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		f[i] = x;
		if(x > f[ans]) {
			f[++ans] = x;//如果小于最后一个元素，插入
		}
		else {
			int ind = lower_bound(f + 1, f + 1 + ans, x) - f;//否则，找到第一个大于等于其的元素，进行替换
			f[ind] = x;
		}
	}
	printf("%d", ans);
	return 0;
}
```