#include <iostream>
#include <string>
using namespace std;

void int_bin(string bin_num);
string align(string int_bin_num);
string prov_int(string int_bin_num, int point);

int main()
{
	setlocale(LC_ALL, "Rus");
	string bin_num = "";
	cout << "¬ведите двоичное число : ";
	cin >> bin_num;
	int_bin(bin_num);
}

void int_bin(string bin_num)
{
	string int_bin_num = "";
	string frac_num = "";
	string drob_num = "";
	string int_octal_num = "";
	int point = 0;
	point = bin_num.find(".");
	if (point == -1) {
		int_bin_num = bin_num;
		int_bin_num = prov_int(int_bin_num,point);
		int_octal_num = align(int_bin_num);
	}
	else {
		for (int i = 0; i < point -1; i++) {
			int_bin_num = int_bin_num + bin_num[i];
		}
		for (int i = bin_num.length(); i > point; i--) {
			frac_num = frac_num + bin_num[i];
		}
		int_bin_num = prov_int(int_bin_num,point);
		int_octal_num = align(int_bin_num);
		frac_num = prov_int(frac_num,point);
		drob_num = align(frac_num);
	}

	cout << "¬ восьмеричной системе : " << int_octal_num << "." << drob_num << endl;
}

string align(string int_bin_num)
{
	int i = 0;
	cout << " int_bin_num = " << int_bin_num << endl;
	string str_int_octal = "";
	cout << "int_bin_num.length() = " << int_bin_num.length() << endl;
	while (i < int_bin_num.length()) {
		string new_bin;
		int int_bin = 0;
		new_bin.assign(int_bin_num, i, 3);
		int_bin = atoi(new_bin.c_str());
		cout << "new_bin = " << new_bin << endl;
		cout << "int_bin = " << int_bin << endl;
		switch (int_bin)
		{
		case 0: str_int_octal = str_int_octal + "0";
			break;
		case 1: str_int_octal = str_int_octal + "1";
			break;
		case 10: str_int_octal = str_int_octal + "2";
			break;
		case 11: str_int_octal = str_int_octal + "3";
			break;
		case 100: str_int_octal = str_int_octal + "4";
			break;
		case 101: str_int_octal = str_int_octal + "5";
			break;
		case 110: str_int_octal = str_int_octal + "6";
			break;
		case 111: str_int_octal = str_int_octal + "7";
			break;
		}
		i = i + 3;
	}
	return str_int_octal;
}

string prov_int(string num, int point) // проверка на достаточность знаков в 8-й системе
{
	int num_len = 0;
	if (point != -1) num_len = num.length();
	else num_len = num.length();
	if (num_len % 3 == 0) {
		return num;
	}
	else
	{
		int x = 0;
		x = 3 - (num_len % 3);
		for (int i = 1; i <= x; i++) {
			num = "0" + num;
		}
		return num;
	}
}