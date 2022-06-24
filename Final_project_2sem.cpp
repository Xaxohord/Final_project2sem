// Final_project_2sem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>﻿#include <iostream>
#include <cassert>
#include "../Final_project_2sem/inc/mathutils/matrix.hpp"
using mtmath::Mat22d;
using mtmath::Mat33i;
using mtmath::Vec2d;
using mtmath::Mat34d;

void panel(int x) {
	int r;
	if (x == 1) {
		cout << "Определитель какой матрицы вы хотите найти?" << endl;
		cout << "1 - 2X2" << endl;
		cout << "2 - 3X3" << endl;
		cin >> r;
		if (r == 1) {
			cout << "Введите вашу матрицу 2Х2: " << endl;
			Mat22d A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Определитель матрицы: " << endl;
			cout << A.determ() << endl;
		}
		else if (r == 2) {
			cout << "Введите вашу матрицу 3Х3: " << endl;
			Mat33i A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Определитель матрицы: " << endl;
			cout << A.determ() << endl;
		}
		else {
			cout << "Неверно" << endl;
		}
	}
	else if (x == 2) {
		cout << "Какого размера вы хотите матрицу? " << endl;
		cout << "1 - 2X2" << endl;
		cout << "2 - 3X3" << endl;
		cin >> r;
		if (r == 1) {
			cout << "Введите вашу матрицу 2Х2: " << endl;
			Mat22d A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Обратная матрица: " << endl;
			auto q = A.inv();
			cout << q << endl;
		}
		else if (r == 2) {
			cout << "Введите вашу матрицу 3Х3 " << endl;
			Mat33i A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Обратная матрица: " << endl;
			auto q = A.inv();
			cout << q << endl;
		}
		else {
			cout << "Неверно" << endl;
		}
	}
	else if (x == 3) {
		cout << "Какого размера вы хотите матрицу? " << endl;
		cout << "1 - 2X2" << endl;
		cout << "2 - 3X3" << endl;
		cin >> r;
		if (r == 1) {
			cout << "Введите вашу матрицу 2Х2: " << endl;
			Mat22d A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Транспонированная матрица: " << endl;
			cout << A.trans() << endl;
		}
		else if (r == 2) {
			cout << "Введите вашу матрицу 3Х3: " << endl;
			Mat33i A;
			cin >> A;
			system("cls");
			cout << "Матрица, которую вы создали: " << endl;
			cout << A << endl;
			cout << "Транспонированная матрица: " << endl;
			cout << A.trans() << endl;
		}
		else {
			cout << "Неверно" << endl;
		}
	}
	else if (x == 4) {
		cout << "Введите первую вашу матрицу 3Х3: " << endl;
		Mat33i A;
		cin >> A;
		cout << "Введите вторую вашу матрицу 3Х3: " << endl;
		Mat33i B;
		cin >> B;
		system("cls");
		cout << "Матрицы, которые вы создали: " << endl;
		cout << A << endl;
		cout << B << endl;
		cout << "Результат сложение двух матриц: " << endl;
		cout << A + B << endl;
	}
	else if (x == 5) {
		cout << "Введите первую вашу матрицу 3Х3: " << endl;
		Mat33i A;
		cin >> A;
		cout << "Введите вторую вашу матрицу 3Х3: " << endl;
		Mat33i B;
		cin >> B;
		system("cls");
		cout << "Матрицы, которые вы создали: " << endl;
		cout << A << endl;
		cout << B << endl;
		cout << "Результат вычитания двух матриц: " << endl;
		cout << A - B << endl;
	}
	else if (x == 6) {
		cout << "Введите матрицу 3Х4: " << endl;
		Mat34d A;
		cin >> A;
		system("cls");
		cout << "Матрица, которую вы создали: " << endl;
		cout << A << endl;
		cout << "Ответ системы алгебраических уравнений, решенных методом Крамера: " << endl;
		cout << A.SLAY() << endl;
	}
	else if (x == 7) {
		cout << "Введите первую вашу матрицу 3Х3: " << endl;
		Mat33i A;
		cin >> A;
		cout << "Введите вторую вашу матрицу 3Х3: " << endl;
		Mat33i B;
		cin >> B;
		system("cls");
		cout << "Матрицы, которую вы создали: " << endl;
		cout << A << endl;
		cout << B << endl;
		cout << "Умноженная матрица: " << endl;
		auto q = A * B;
		cout << q << endl;
	}
	else {
		cout << "Неверно(" << endl;
	}
}
int main()
{
	int f;
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "Это математическая библиотека, что вы хотите сделать?" << endl << "Введите: " << endl;
	cout << "1 - если вы хотите найти определитель матрицы" << endl;
	cout << "2 - если вы хотите найти обратную матрицу" << endl;
	cout << "3 - если вы хотите транспонировать матрицу" << endl;
	cout << "4 - если вы хотите сложить 2 матрицы" << endl;
	cout << "5 - если вы хотите вычесть 2 матрицы" << endl;
	cout << "6 - если вы хотите решить СЛАУ методом Крамера" << endl;
	cout << "7 - если вы хотите умножить матрицы" << endl;
	cin >> f;
	system("cls");
	panel(f);
	system("pause");
	return 0;
}