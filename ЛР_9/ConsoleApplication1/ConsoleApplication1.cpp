/*
№ 9 Обработка исключений
Модифицировать проект, созданный в предыдущем практикуме №8. 
Создать иерархию классов исключений.Сгенерировать и обработать как минимум пять различных исключительных ситуаций. 
Например, не позволять при инициализации объектов передавать конструкторам неверные данные, 
обрабатывать ошибки при работе с памятью и ошибки работы с файлами, 
деление на ноль, неверный индекс, нулевой указатель и т. д.
*/

#include "stdafx.h" 
#include "iostream" 
#include <fstream>
#include "string.h" 
#include "button.h"

using namespace std;


class error
{
public:
	error()
	{}
	error(int code)
	{
		cout << "Error: " << code << endl;
		try
		{
			if (code == 1)
				throw 1;
			else if (code == 2)
				throw 2;
			else if (code == 3)
				throw 3;
			else if (code == 4)
				throw 4;
			else if (code == 5)
				throw 5;
		}

		catch (int s)
		{
			if (s == 1)
			{
				cout << "Error with type. " << endl;
				cout << "Try again. " << endl;
			}
			if (s == 2)
			{
				cout << "Error with open file. " << endl;
				cout << "Try again. " << endl;
			}
			if (s == 3)
			{
				cout << "Error with pass. " << endl;
				cout << "Try again. " << endl;
			}
			if (s == 4)
			{
				cout << "Error with symbols. " << endl;
				cout << "Try again. " << endl;
			}
			if (s == 5)
			{
				cout << "Error with key. " << endl;
				cout << "Try again. " << endl;
			}
		}
	}
};



class error_1_type : public error
{
public:
	error_1_type(int code)
	{
		try
		{
			cout << "Don't write this type!!!" << endl;
			throw error(1);
		}
		catch (error)
		{
			cout << "Try again write r,t,v: " << endl;
		};
	}
};


class error_2_file : public error
{
public:
	error_2_file(int code)

	{
		try
		{
			cout << "Error with open file." << endl;
			throw error(2);
		}

		catch (error)
		{

			cout << "Open new file." << endl;
		}
	};
};



class error_3_pass : public error
{
public:
	error_3_pass(int code)

	{
		try
		{
			cout << "Error with pass." << endl;
			throw error(3);
		}

		catch (error)
		{

			cout << "Very easy pass." << endl;
		}
	};
};


class error_4_symb : public error
{
public:
	error_4_symb(int code)

	{
		try
		{
			cout << "Error with symbols." << endl;
			throw error(4);
		}

		catch (error)
		{
			cout << "Very easy symbols." << endl;
		}
	};
};


class error_5_key : public error
{
public:
	error_5_key(int code)
	{
		try
		{
			cout << "Error with key." << endl;
			throw error(5);
		}
		catch (error)
		{
			cout << "Key very easy." << endl;
		}
	};
};


template<class T>
class String
{
private:
	T str;
	//button but;
public:

	String(T buf)
	{
		str = buf;

		//strbut = strbut1;
	}

	friend String operator<(String& x, String &y)
	{
		if (x.str.but < y.str.but) cout << "True." << endl;
		else cout << " False." << endl;
		return 0;

	}

	friend String operator+(String &x, String &y)
	{
		cout << x.str.but + y.str.but << endl;
		return 0;
	}

	friend String operator-(String& x, String&y)
	{
		x.str.but = x.str.but + 100;
		cout << x.str.but - y.str.but << endl;
		return 0;
	}

	friend String operator*(String&x, int s)
	{

		if (x.str.but/* == 5 */) x.str.but = s;
		cout << x.str.but << endl;;
		return 0;
	}

	//-------------------------------------------------------------------------------------

	friend String operator<=(String& x, String &y)
	{
		if (x.str < y.str) cout << "True." << endl;
		else cout << " False." << endl;
		return 0;

	}

	friend String operator+=(String &x, String &y)
	{
		cout << x.str + y.str << endl;
		return 0;
	}

	friend String operator-=(String& x, String&y)
	{
		x.str = x.str + 100;
		cout << x.str - y.str << endl;
		return 0;
	}

	friend String operator*=(String&x, int s)
	{

		if (x.str /*== 11*/) x.str = s;
		cout << x.str << endl;;
		return 0;
	}

	template <class TT>
	void password(TT pass)
	{
		int sum = 0;
		char key = 0; 
		int n;

		cout << "Write string: ";
		cin>>pass;
		try
		{
			if (strlen(pass) < 8) //standart emount symbols
				throw error_3_pass(3);
		}
		catch (error_3_pass)
		{}
		cin >> pass;
		cout << "================================================================================";
		cout << endl;



		try
		{
			for (int i = 0; i <= strlen(pass); i++)
			{
				if (pass[i] = 'a-z') cout << "Error. Please write other symbols." << endl;
				break;
			}
			throw error_4_symb(4);
		}
		catch (error_4_symb)
		{}
		cin >> pass;
		cout << "================================================================================";
		cout << endl;



		int znam;
		cout << "Write znam for key: ";
		cin >> znam;
		try
		{
			if (znam <= 10)
				throw error_5_key(5);
		}
		catch (error_5_key)
		{}
		cin >> znam;
		cout << "================================================================================";
		cout << endl;



		for (n = 0; n < strlen(pass); n++)
			sum += pass[n];
		key = (sum / znam) + znam;

		cout << "Key is: " << key << endl;

		for (n = 0; n < strlen(pass); n++)
			pass[n] = pass[n] ^ key; //Шифрование
		cout << "Code stringg: " << pass << "\n";

		for (n = 0; n < strlen(pass); n++)
			pass[n] = pass[n] ^ key; //Дешифровка
		cout << "Decode stringg: " << pass << "\n";
	}

};



void main()
{
	setlocale(LC_CTYPE, "rus");
	ofstream fout("first.txt");
	fout << "File number one.";
	fout.close();
	try
	{
		if (!fout.is_open())
			throw error_2_file(2);
	}
	catch (error_2_file)
	{
		cout << "Open and push in other file." << endl;
		ofstream fout("other.txt");
		fout << "File number two.";
		fout.close();
	}
	cout << "================================================================================";
	cout << endl;



	double e, u, m;
	cout << "Write r, t, v:" << endl;
	cin >> e;
	cin >> u;
	cin >> m;
	try
	{
		if ((double)e == (int)e)
			throw error_1_type(1);
	}
	catch (error_1_type)
	{
		cin >> e >> u >> m;
	}
	cout << "================================================================================";
	cout << endl;



	String<button> a(1);
	String<button> b(2);
	String<button> c(5);
	String<double> r(e);
	String<double> t(u);
	String<double> v(m);

	cout << "a < b? = ";
	(a < b);
	cout << "a + b: ";
	(a + b);
	cout << "a(+100) - b = ";
	(a - b);
	cout << "c(5) * 2 = ";
	(c * 2);
	cout << "================================================================================";
	cout << endl;



	cout << "r < t ? = ";
	(r <= t);
	cout << "r + t = ";
	(r += t);
	cout << "r - t = ";
	(r -= t);
	cout << "v(11) * 1 = ";
	(v *= 1);
	cout << "================================================================================";
	cout << endl;



	char stringg[256];
	a.password(stringg);


}
