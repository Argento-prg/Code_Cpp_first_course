#include "pch.h"
#include "functions.h"

using namespace std;

double change(int n, double u, double v) {
	static int i = 1;//�������
	static double sum = 0;//�����
	static double a;//�������� ���������� �������������� ����� �1
	static double b;//�������� ���������� �������������� ����� �2
	static int temp1;//���������
	double s = 0;//��������� ���������� ��� ��������
	double temp = 0;//����������, ������� ����� ������� ���������� ���������� a
	if (i == 1) {
		a = u;
		b = v;
		sum = 0;
		temp1 = 1;
	}
	s = (a*b) / (temp1 *= (i + 1));
	temp = a;
	a = 2 * b + a;
	b = 2 * (temp*temp) + b;
	sum += s;
	i++;
	if (i > n) {
		a = 0;
		b = 0;
		i = 1;
		return sum;
	}
	else {
		return change(n, a, b);
	}
}
double proverka(double u, double v, int n) {
	double a = 0;
	double b = 0;
	double sum = 0;
	int temp1 = 0;
	double temp = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			a = u;
			b = v;
			temp1 = 1;
		}
		else {
			temp = a;
			a = 2 * b + a;
			b = 2 * (temp*temp) + b;
			temp1 *= i;
		}
		sum = sum + (a*b) / (temp1*(i + 1));
	}
	return sum;
}
L protector(int i) {
	int flag = 0;
	L first;
	char str[80];
	do {
		flag = 0;
		if (i == 1 || i == 2) {
			cout << "(�� -999,99 �� 999,99)(������ ����� �������!!)" << endl;
			if (i == 1) {
				cout << "\n������� ������ �������������� �����: ";
			}
			else {
				cout << "\n������� ������ �������������� �����: ";
			}
			cin.getline(str, 79);
			if (!atof(str)) {
				cout << "�� ����� ������������ ��������! ��������� ����\n\n";
				flag++;
			}
			else {
				first.n = atof(str);
				if (first.n > 999.99 || first.n < -999.99) {
					cout << "�� ����� ������������ ��������! ��������� ����\n\n";
					flag++;
				}
			}
		}else {
			cout << "\n������� ����������� �����(�� 0 �� 8): ";
			cin.getline(str, 79);
			if (!atoi(str)) {
				cout << "�� ����� ������������ ��������! ��������� ����\n\n";
				flag++;
			}
			else {
				first.m = atoi(str);
				if (first.m < 0 || first.m > 8) {
					cout << "�� ����� ������������ ��������! ��������� ����\n\n";
					flag++;
				}
			}
		}
	} while (flag != 0);
	return first;
}
void output(int n, double u, double v, double result_1, double result_2, int flag_1, int flag_2, int &flag_write) {
	if (flag_1 > 0 || flag_2 > 0) {
		cout << "��� u = " << u << " ; v = " << v << " ; n = " << n << endl;
		if (flag_1 > 0) {
			cout << "\n��������� ��������: " << result_1 << endl;
		}
		else {
			cout << "\n����� �������� �� ��� �� ������!" << endl;
		}
		if (flag_2 > 0) {
			cout << "\n��������� �����: " << result_2 << endl;
		}
		else {
			cout << "\n����� ���� �� ��� �� ������!" << endl;
		}
		if (flag_1 > 0 && flag_2 > 0 && flag_write == 0) {
			cout << "\n�� ������ �������� ������ � ����(������� yes or no)?" << endl;
			string str_temp;
			cout << "\n��� �����: ";
			getline(cin, str_temp);
			while (str_temp.length() == 0 || (str_temp != "yes" && str_temp != "no")) {
				cin.clear();
				cin.sync();
				cout << "�� ����� ������������ ��������!" << endl;
				cout << "\n��� �����: ";
				getline(cin, str_temp);
			}
			if (str_temp == "yes") {
				cout << "\n������� �������� �����(� �����������): ";
				getline(cin, str_temp);
				while (str_temp.length() == 0) {
					cin.clear();
					cin.sync();
					cout << "�� ������ �� �����!" << endl;
					cout << "\n������� �������� �����(� �����������): ";
					getline(cin, str_temp);
				}
				ofstream file(str_temp, ios::app);
				if (file.is_open()) {
					cout << "���� ��� ������ ������ ������� ������!" << endl;
					file << "��� u = " << u << " ; v = " << v << " ; n = " << n << endl;
					file << "\n��������� ��������: " << result_1 << endl;
					file << "\n��������� �����: " << result_2 << endl;
					file << "\n";
					cout << "\n������ ������� �������� � ����" << endl;
					flag_write++;
					file.close();
				}
				else {
					cout << "���� �� ������� �������, ������ �� ����� �������� � ����" << endl;
				}

			}
		}
	}
	else {
		cout << "��  ��� �� ������ ���� ������!" << endl;
	}
}
void about() {
	cout << "������� 15. ������� � �������� � 99\n������ 1.0\n2019 �.\n����������� ������� ����" << endl;

}
void help() {
	cout << "�������:\n�����:\na[1] = u, b[1] = v, a[k] = 3*b[k-1] + a[k-1];\nb[k] = 2*(a[k-1])^2 + b[k-1]; k = 2, 3....\n\n";
	cout << "���� �������������� u, v � ����������� n. �����:\n\n�����[�� k �� n]((a[k]*b[k])/(k+1)!) ��� k = 1, 2....." << endl;
}