#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// �ж�һ�����ǲ�������
int isPrimeNumber(int n) {
	int i;
	// ɸ����2ż��
	if(n<2 || (n%2==0 && n!=2)) {
		return 0;
	}
	
	// 3,4,5,6,7,8Ҫע��
	for(i=2;i<=sqrt(n);i++) {
		if(n%i==0) {
			return 0;
		}
	}

	return 1;
}

// ��ӡ��С��n������
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

// ��ӡ������n��������ɸ��������ʵ��
void printPrimeNumberToN(int n) {
	char *a;
	int i, j;
	a = (char*)malloc(sizeof(char)*(n+1));// �����ڴ�
	// ��ʼ��
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
 

// ��ӡ������n��������ɸ����λ����
void printPrimeNumberToN2(int n) {
	int i, j;
	char *a;
	a = (char*)malloc((sizeof(a)+1)*(n/8));
	memset(a, 1, (sizeof(a)+1)*(n/8));
	printf("%s\n", a);
	printf("\n");
} 