/**
 * 四川大学线下编程比赛第一题：数字填充
 *  
 * 题目详情
 * peter喜欢玩数字游戏，但数独这样的游戏对他来说太简单了，于是他准备玩一个难的游戏。游戏规则是在一个N*N
 * 的表格里填数，规则：对于每个输入的N，从左上角开始，总是以对角线为起点，先横着填，再竖着填。这里给了一
 * 些样例，请在样例中找到规律并把这个N*N的表格打印出来吧。
 * 输入描述：
 * 多组测试数据（数据量在100组以内）。每组测试数据只有一行为一个整数N（1<=N<=30），表示表格的大小。
 * 输出描述：
 * 对于每组输入数据，输出N行，为填完的表格（N行，每行N个整数，每个数字之间用空格隔开。
 * 答题说明
 * 输入样例：
 * 3
 * 5
 * 输出样例：
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

void digital_filled(int n) {
	int **a; // 用于将数字存储
	int i, j, cur;

	if(n<1) {
		return ;
	}
	a = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++) {
		a[i] = (int*)malloc(sizeof(int)*n);
	}
	
	cur = 1; // 开始数字
	for(i=0;i<n;i++) {
		// 横排填充
		for(j=i;j<n;j++) {
			a[i][j] = cur++;
		}
		//竖排填充
		for(j=i+1;j<n;j++) {
			a[j][i] = cur++;
		}
	}

	// 输出
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
		cur_x = i*n*2 - i*i +1; // 当前行的对角线上的数
		for(j=0;j<n;j++) {
			cur_y = j*n*2 - j*j +1; // 当前列的对角线上的数
			if(i>j) {
				printf("%d\t", (cur_y+n-1)+(i-j)-j);
			} else {
				printf("%d\t", cur_x+j-i);	
			}
		}
		printf("\n");
	}
}