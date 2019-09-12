/* 循环：课后作业 */


/*
1059：求平均年龄
http://ybt.ssoier.cn:8088/problem_show.php?pid=1059

【题目描述】

班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。
【输入】

第一行有一个整数n（1≤ n ≤ 100），表示学生的人数。其后n行每行有1个整数，表示每个学生的年龄，取值为15到25。
【输出】

输出一行，该行包含一个浮点数，为要求的平均年龄，保留到小数点后两位。
【输入样例】

2
18
17

【输出样例】

17.50

要点： 
1. sum_age 注意是要定义为浮点或者double类型 
2. cout << fixed << setprecision(2) 用于控制输出的小数点后的精度，需要 #include <iomanip>
*/
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//	int num = 0;
//	int age;
//	double sum_age;
//	
//	cin >> num;
//	for (int i = 0; i < num; i++) {
//		cin >> age;
//		sum_age += age;
//	}
//	double average = sum_age/num;
//	cout << fixed << setprecision(2) << average << endl;
//}
//
//

/*
1071：菲波那契数
http://ybt.ssoier.cn:8088/problem_show.php?pid=1071

【题目描述】

菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。给出一个正整数k，要求菲波那契数列中第k个数是多少。
【输入】

输入一行，包含一个正整数k。（1 ≤ k ≤ 46）
【输出】

输出一行，包含一个正整数，表示菲波那契数列中第k个数的大小。
【输入样例】

19

【输出样例】

4181

要点：斐波拉切公式是 f(k) = f(k-1) + f(k-2), f(1) = 1, f(2) = 1 
可以用三个变量来操作： v3 代表 f(k), v2 代表 f(k-1), v1代表 f(k-2) 
*/

//#include <iostream>
//using namespace std;
//
//int main() {
//	int k;
//	cin >> k;
//	
//	int v1 = 1;
//	int v2 = 1;
//	int v3 = 1;
//	for (int i = 3; i <= k; i ++) {
//		v3 = v1 + v2;
//		v1 = v2;  //关键：在循环体内不断的更新v1和v2 
//		v2 = v3;
//	}
//	cout << v3 << endl;
//}

/*
要点： 用数组来解题更直观，基本可以套公式： a[k] = a[k-1] + a[k-2] 
缺点是需要定义一个比较大的数组，而且要小心输入的数字超过了数组的大小 
*/

//int main() {
//	int k;
//	cin >> k;
//	
//	int a[100];
//	a[0] = 1;
//	a[1] = 1;
//	for (int i = 2; i < k; i++) {
//		a[i] = a[i -1] + a[i - 2];
//	}
//	cout << a[k-1] << endl;
//}


/*
1088：分离整数的各个数
http://ybt.ssoier.cn:8088/problem_show.php?pid=1088

【题目描述】

给定一个整数n(1≤n≤100000000)，要求从个位开始分离出它的每一位数字。从个位开始按照从低位到高位的顺序依次输出每一位数字。
【输入】

输入一个整数，整数在1到100000000之间。
【输出】

从个位开始按照从低位到高位的顺序依次输出每一位数字。数字之间以一个空格分开。
【输入样例】

123

【输出样例】

3 2 1

要点： 一个整数n(1≤n≤100000000)，我们可以用int来表示，int的表示范围 = [ 2^31 - 1, -2^31 ], 也就是INT_MAX is 2147483647 ;  INT_MIN is (-2147483647 - 1) 
*/
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	
//	while (true) {
//		cout << n % 10;
//		n = n / 10;
//		if (n > 0) {
//			cout << " ";
//		} else {
//			break;
//		}
//	}
//	return 0;
//}

/*
1095：数 1 的个数
http://ybt.ssoier.cn:8088/problem_show.php?pid=1095

【题目描述】

给定一个十进制正整数n(1≤n≤10000)，写下从1到n的所有整数，然后数一下其中出现的数字“1”的个数。

例如当n=2时，写下1,2。这样只出现了1个“1”；当n=12时，写下1，2，3，4，5，6，7，8，9，10，11，12。这样出现了5个“1”。
【输入】

正整数n。1 ≤ n ≤ 10000。
【输出】

一个正整数，即“1”的个数。
【输入样例】

12

【输出样例】

5

要点： 这道题跟上一道有点类似，多了一个嵌套循环 
*/ 

//#include <iostream>
//using namespace std;
//
//int main() {
//	int k;
//	int n;
//	int num = 0;
//	cin >> k;
//	for (int i = 0; i <= k; i++) {
//		n = i;
//		while (n > 0) {
//			int bit = n % 10;
//			if (bit == 1) {
//				num++;
//			}
//			n = n / 10;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}


//数组：课上练习


/*
已知int数组a包含10个元素，请将数组中的第一个元素移到末尾，其余元素依次向前移动一个位置。提示：利用一个临时变量，考察数组的赋值和引用
*/ 

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a[10] = {1,2,3,4,5,6,7,8,9,10};
//	int tmp = a[0];
//	/*
//	for循环表示： 
//	a[0] = a[1];
//	a[1] = a[2];
//	a[2] = a[3];
//	...
//	a[8] = a[9];
//	*/
//	for (int i = 0; i < 9; i++) {
//		a[i] = a[i+1];
//	}
//	a[9] = tmp;
//	
//	for (int i = 0; i < 10; i++) {
//		cout << a[i] << ",";
//	}
//	return 0; 
//}

/*
已知一个二维数组a[5][2], 使用嵌套循环来计算每一行和每一列的和 
*/

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a[5][2] = {
//		{1,2},
//		{11,42},
//		{12,32},
//		{13,22},
//		{14,12}
//	};
//	
//	for (int row = 0; row < 5; row++) {
//		int row_sum = 0;
//		for (int col = 0; col < 2; col++) {
//			row_sum += a[row][col];
//		}
//		cout << row_sum << endl;
//	}
//
//	for (int col = 0; col < 2; col++) {
//		int col_sum = 0;
//		for (int row = 0; row < 5; row++) {
//			col_sum += a[row][col];
//		}
//		cout << col_sum << endl;
//	}
//	return 0;
//}


/* 数组：课后作业 */

/*
1102：与指定数字相同的数的个数
http://ybt.ssoier.cn:8088/problem_show.php?pid=1102

【题目描述】

输出一个整数序列中与指定数字相同的数的个数。
【输入】

输入包含三行：

第一行为N，表示整数序列的长度(N ≤ 100)；

第二行为N个整数，整数之间以一个空格分开；

第三行包含一个整数，为指定的数字m。

【输出】

输出为N个数中与m相同的数的个数。
【输入样例】

3
2 3 2
2

【输出样例】

2

*/
//
//#include <iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int v[100];
//	for (int i = 0; i < n; i ++) {
//		cin >> v[i];
//	}
//	int m;
//	cin >> m;
//	
//	int sum = 0;
//	for (int i = 0; i < n; i ++) {
//		if (v[i] == m) {
//			sum++;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

/*

1124：矩阵加法
http://ybt.ssoier.cn:8088/problem_show.php?pid=1124

【题目描述】

输入两个n行m列的矩阵A和B，输出它们的和A+B。
【输入】

第一行包含两个整数n和m，表示矩阵的行数和列数(1≤n≤100，1≤m≤100)。

接下来n行，每行m个整数，表示矩阵A的元素。

接下来n行，每行m个整数，表示矩阵B的元素。

相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。

【输出】

n行，每行m个整数，表示矩阵加法的结果。相邻两个整数之间用单个空格隔开。
【输入样例】

3 3
1 2 3
1 2 3
1 2 3
1 2 3
4 5 6
7 8 9

【输出样例】

2 4 6
5 7 9
8 10 12


*/


//#include <iostream>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int v[2][100][100];
//	for (int k = 0; k < 2; k++) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cin >> v[k][i][j];
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << v[0][i][j] + v[1][i][j] << " ";
//		}
//		cout << endl;
//	}
//
//}

