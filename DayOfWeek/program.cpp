#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

#define BasicYear 365
#define LeapYear 366

struct DateTime //struct kieu du lieu DateTime, Luu du lieu ngay thang nam
{
	int Day = 0;
	int Month = 0;
	int Year = 0;
};

int CreateID(DateTime date) //Ham ho tro viec swap
{
	int ID = date.Year * 10000 + date.Month * 100 + date.Day;
	return ID;
}

int SwapDate(DateTime &Date_A, DateTime &Date_B)//Ham dung de hoan doi vi tri cua cac nam theo thu tu
{
	DateTime DateTemp;
	if (CreateID(Date_A) > CreateID(Date_B)) {
		DateTemp = Date_A;
		Date_A = Date_B;
		Date_B = DateTemp;
		return 1;
	}
	return 0;
}

//int clean_stdin()
//{
//	while (getchar() != '\n');
//	return 1;
//}

void Input(DateTime &date) //Ham nhap du lieu dau vao co the thay doi bien toan cuc 
{
	int day = 0;
	int month = 0;
	int year = 0;
	printf("Nhap ngay can tim (dd/mm/yyyy): ");
	cin >> day;
	cin >> month;
	cin >> year;
	printf("\nNgay duoc nhap la: %d/%d/%d\n", day, month, year);
}

bool IsLeapYear(DateTime date)// Ham dung de xac dinh nam nhuan
{
	if ((date.Year % 4 == 0 && date.Year % 100 != 0) || date.Year % 400 == 0)
	{
		return true;
	}
	return false;
}

int IsMonth(DateTime date)// Ham xac dinh thang nao trong nam
{
	if (date.Month == 2) {
		if (IsLeapYear(date)) {
			return 29;
		}
		return 28;
	}
	for (int i = 1; i <= 12; i += 2) {
		if (date.Month == i)
			return 31;
		if (i == 7)
		{
			i--;
		}
	}
	for (int i = 4; i <= 11; i += 2) {
		if (date.Month == i)
			return 30;
		if (i == 6)
		{
			i++;
		}
	}
	return 0;
}

int IsDay(DateTime date) {
	int result = 0;
	if (date.Month <= 12) {
		result = date.Day;
		for (--date.Month; date.Month >= 1; date.Month--) {
		result += IsMonth(date);
		}
	}
	return result;
}

bool InputTest(DateTime date) {
	if (date.Year >= 1) {
		if (date.Day >= 1 && date.Day <= IsMonth(date))
		{
			return false;
		}
	}
	else
		return true;
}

int CountDay(DateTime Date_A, DateTime Date_B) //Ham tinh so ngay giua hai ngay duoc nhap vo trong cung 1 thang
{
	int result = 0;
	return result = Date_B.Day - Date_A.Day;
}

int CountDayToMonth(DateTime date_A, DateTime date_B)
{
	int result = 0;
	if (date_A.Month == date_B.Month) {
		result = CountDay(date_A, date_B);
	}
	else
	{
		result = date_B.Day;
		result += (IsMonth(date_A) - date_A.Day);
		for (++date_A.Month; date_A.Month < date_B.Month; date_A.Month++) {
			result += IsMonth(date_A);
		}
	}
	return result;
}

int CountDayToYear(DateTime date_A, DateTime date_B)
{
	int flag = SwapDate(date_A, date_B);
	int result = 0;
	if (date_A.Year == date_B.Year) {
		result = CountDayToMonth(date_A, date_B);
	}
	else
	{
		result = IsDay(date_B);
		if (IsLeapYear(date_A)) {
			result += (LeapYear - IsDay(date_A));
		}
		else
		{
			result += (BasicYear - IsDay(date_A));
		}
		for (++date_A.Year; date_A.Year < date_B.Year; date_A.Year++) {
			if (IsLeapYear(date_A)) {
				result += LeapYear;
			}
			else
			{
				result += BasicYear;
			}
		}
	}
	result = result * 10 + flag;
	return result;
}

void Output(DateTime date_A, DateTime date_B) {
	int flag = CountDayToYear(date_A, date_B) % 10;
	int change = (CountDayToYear(date_A, date_B) / 10) % 7;
	if (flag == 0) {
		switch (change)
		{
		case 0:
			printf("\nChu Nhat");
			break;
		case 1:
			printf("\nThu Hight");
			break;
		case 2:
			printf("\nThu 3");
			break;
		case 3:
			printf("\nThu 4");
			break;
		case 4:
			printf("\nThu 5");
			break;
		case 5:
			printf("\nThu 6");
			break;
		case 6:
			printf("\nThu 7");
			break;
		default:
			break;
		}
	}
	else {
		switch (change)
		{
		case 0:
			printf("\nChu Nhat");
			break;
		case 1:
			printf("\nThu 7");
			break;
		case 2:
			printf("\nThu 6");
			break;
		case 3:
			printf("\nThu 5");
			break;
		case 4:
			printf("\nThu 4");
			break;
		case 5:
			printf("\nThu 3");
			break;
		case 6:
			printf("\nThu Hight");
			break;
		default:
			break;
		}
	}
}


void main() {
	static DateTime dateRoot;
	dateRoot.Day = 12;
	dateRoot.Month = 05;
	dateRoot.Year = 2019;

	DateTime dateTime;
	
	/*NhapLai:
		Input(dateTime);
		if (InputTest) {
			goto NhapLai;
	}
*/
	do
	{
		Input(dateTime);
	} while (InputTest(dateTime));

	printf("Thu cua ngay %d/%d/%d: ", dateTime.Day, dateTime.Month, dateTime.Year);
	Output(dateRoot, dateTime);

	_getch();
}