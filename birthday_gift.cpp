#include<string>
#include <iostream>
#include <windows.h>
using namespace std;
#define ll long long
#define maxx 1000005
#define inf 1000000009;
#define mod 998244353
int minWid = 17;
int space = 3;
int sleep1 = 2000;
int sleep2 = 100;
int sleep3 = 1000;

string card[] = {
	" \\   /\\+++/\\   / \n",
	"  \\ |       | / \n",
	"   \\ \\_____/ / \n",
	"    |       | \n",
};
string cat[] = {
	" /\\+++/\\  ",
	"|       | ",
	" \\_____/  ",
	" /    /    ",
};
string cat2 =
"  /\\                      /\\  \n"
" /  \\++++++++++++++++++++/  \\  \n"
"/                            \\ \n"
"|       /\\           /\\      | \n"
"|       \\/           \\/      | \n"
"\\              v             / \n"
" \\                          /  \n"
"  \\________________________/  \n";

void printSpace(int num){
	for (int i = 1; i <= num; i++)
		cout << " ";
}
void printCat(string s, int pos, int f){
	printSpace(pos * (minWid + space));
	for (int i = 1; i <= minWid; i++)
		cout << "-";
	cout << endl;
	printSpace(pos * (minWid + space));
	cout << "|";
	printSpace(6);
	cout << s;
	printSpace(6);
	cout << "|" << endl;
	printSpace(pos * (minWid + space));
	for (int i = 1; i <= minWid; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i<4; i++) {
		printSpace(pos * (minWid + space));
		cout << card[i];
		if (f){
			if (i == 0){
				printSpace(pos * (minWid + space));
				cout << "    | *   * | " << endl;
			}
		}
	}
}
//pos=0 left 1 centre 2 right
void printfFlowingCat(int num, int num2, int num3){
	for (int k = 1; k <= num3; k++){
		for (int i = 0; i < 4; i++) {
			for (int j = (num + k * 6) % 10; j < cat[i].length(); j++)
				cout << cat[i][j];
			for (int j = 1; j <= num2; j++)
				cout << cat[i];
			for (int j = 0; j < (num + k * 6) % 10; j++)
				cout << cat[i][j];
			cout << endl;
		}
	}
}
void countdown(){
	for (int i = 3; i > 0; i--){
		for (int j = 1; j <= 5; j++)
			printf("\n");
		printf("                        %d\n", i);
		Sleep(sleep1);
		system("cls");
	}
}
void part2(string s, int num){
	printCat(s, num, 0);
	Sleep(sleep3);
	system("cls");
	for (int k = 1; k <= 10; k++){
		for (int i = 1; i <= 3; i++)
			printf("\n");
		if (k % 5 > 2){
			for (int i = 1; i <= 10; i++)
				printf("   喵");
		}
		printf("\n");
		printfFlowingCat(k, 5, 1);
		Sleep(sleep2);
		system("cls");
	}
}
void part3(){
	for (int i = 1; i <= 40; i++){
		if (i <= 20){
			if (i % 4 == 0){
				printCat("我儿", 0, 0);
				printCat("生日", 1, 0);
				printCat("快乐", 0, 0);
			}
			if (i % 4 == 1){
				printCat("我儿", 2, 0);
				printCat("生日", 1, 0);
				printCat("快乐", 2, 0);
			}
			if (i % 4 == 2){
				printCat("我儿", 0, 0);
				printCat("生日", 1, 0);
				printCat("快乐", 2, 0);
			}
			if (i % 4 == 3){
				printCat("我儿", 2, 0);
				printCat("生日", 1, 0);
				printCat("快乐", 0, 0);
			}
		}
		else{
			printCat("我儿", 0, 0);
			printCat("生日", 1, ((i % 8) <= 4));
			printCat("快乐", 2, 0);
		}
		printfFlowingCat(i, 5, 1);
		Sleep(sleep2);
		system("cls");
	}
	cout << cat2;
}
signed main(){
	countdown();
	part2("我儿",0);
	part2("生日",1);
	part2("快乐",2);
	part3();
	printf("                                  -END-\n");
	system("pause");
	return 0;
}