// test1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int check();
public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void display();
	CMyDate operator +(CMyDate &otemp);
	CMyDate operator +(const int &d);
	CMyDate addday(CMyDate &od);
};
int CMyDate::check()
{
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp = 1;
	while (temp == 1 && month != 0 && day != 0)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month] < day)
			{
				day = day - leapYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month] < day)
			{
				day = day - flatYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		if (month > 12)
		{
			month = month - 12;
			year++;
			temp = 1;
		}
	}
	return 0;
}
CMyDate::CMyDate()
{
	year = 0;
	month = 0;
	day = 0;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
}
int CMyDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	return 0;
}
void CMyDate::display()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
CMyDate CMyDate::operator+(CMyDate &otemp)
{
	CMyDate temp;
	temp.setDate(year + otemp.year, month + otemp.month, day + otemp.day);
	return temp;
}
CMyDate CMyDate::operator+(const int &d)
{
	CMyDate temp;
	temp.setDate(year, month, day + d);
	return temp;
}
CMyDate CMyDate::addday(CMyDate &od)
{
	CMyDate temp;
	temp.setDate(year + od.year, month + od.month, day + od.day);
	return temp;
}
int main()
{
	CMyDate od1(2019, 6, 3), od2(100, 50, 90), od3;
	od3 = od1 + od2;
	od1.display();
	od2.display();
	od3.display();
	return 0;
}

