#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// 判断一个数是不是质数
int isPrimeNumber(int n) {
	int i;
	// 筛除非2偶数
	if(n<2 || (n%2==0 && n!=2)) {
		return 0;
	}
	
	// 3,4,5,6,7,8要注意
	for(i=2;i<=sqrt(n);i++) {
		if(n%i==0) {
			return 0;
		}
	}

	return 1;
}

// 打印最小的n个质数
void printPrimeNumber(int n) {
	int i=2;
	if(n<1) {
		return ;
	}
	while(n) {
		if(isPrimeNumber(i)) {
			printf("%d\t", i);
			n--;
		}
		i++;
	}
	printf("\n");
}

// 打印不大于n的质数，筛法，数组实现
void printPrimeNumberToN(int n) {
	char *a;
	int i, j;
	a = (char*)malloc(sizeof(char)*(n+1));// 分配内存
	// 初始化
	for(i=0;i<n;i++) {
		a[i] = 1;
	}
	a[0] = 0;
	a[1] = 0;
	for(i=2;i<=sqrt(n);i++) {
		if(a[i]) {
			for(j=i;j<=n/i;j++) {
				a[i*j] = 0;
			}
		}
	}
	for(i=2;i<n;i++) {
		if(a[i]) {
			printf("%d\t", i);
		}
	}
 	printf("\n");
}
 

// 打印不大于n的质数，筛法，位操作
void printPrimeNumberToN2(int n) {
	int i, j;
	char *a;
	a = (char*)malloc((sizeof(a)+1)*(n/8));
	memset(a, 1, (sizeof(a)+1)*(n/8));
	printf("%s\n", a);
	printf("\n");
} 