/**
 * �Ĵ���ѧ���±�̱�����һ�⣺�������
 *  
 * ��Ŀ����
 * peterϲ����������Ϸ����������������Ϸ������˵̫���ˣ�������׼����һ���ѵ���Ϸ����Ϸ��������һ��N*N
 * �ı�������������򣺶���ÿ�������N�������Ͻǿ�ʼ�������ԶԽ���Ϊ��㣬�Ⱥ������������������һ
 * Щ�����������������ҵ����ɲ������N*N�ı���ӡ�����ɡ�
 * ����������
 * ����������ݣ���������100�����ڣ���ÿ���������ֻ��һ��Ϊһ������N��1<=N<=30������ʾ���Ĵ�С��
 * ���������
 * ����ÿ���������ݣ����N�У�Ϊ����ı��N�У�ÿ��N��������ÿ������֮���ÿո������
 * ����˵��
 * ����������
 * 3
 * 5
 * ���������
 * 1 2 3
 * 4 6 7
 * 5 8 9
 * 1  2  3  4  5
 * 6 10 11 12 13
 * 7 14 17 18 19
 * 8 15 20 22 23
 * 9 16 21 24 25
 */

#include<stdio.h>
#include<stdlib.h>

void digital_filled(int n);
void digital_filled_2(int n);

int main(int argc, char *args[]) {
	digital_filled_2(10);
	return 0;
}

void digital_filled(int n) {
	int **a; // ���ڽ����ִ洢
	int i, j, cur;

	if(n<1) {
		return ;
	}
	a = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++) {
		a[i] = (int*)malloc(sizeof(int)*n);
	}
	
	cur = 1; // ��ʼ����
	for(i=0;i<n;i++) {
		// �������
		for(j=i;j<n;j++) {
			a[i][j] = cur++;
		}
		//�������
		for(j=i+1;j<n;j++) {
			a[j][i] = cur++;
		}
	}

	// ���
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void digital_filled_2(int n){
	int i, j, cur_x, cur_y;
	if(n<1) {
		return ;
	}
	for(i=0;i<n;i++) {
		cur_x = i*n*2 - i*i +1; // ��ǰ�еĶԽ����ϵ���
		for(j=0;j<n;j++) {
			cur_y = j*n*2 - j*j +1; // ��ǰ�еĶԽ����ϵ���
			if(i>j) {
				printf("%d\t", (cur_y+n-1)+(i-j)-j);
			} else {
				printf("%d\t", cur_x+j-i);	
			}
		}
		printf("\n");
	}
}