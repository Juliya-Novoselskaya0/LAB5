/*Full name : Novoselskaya Juliya
group:044691
variant 18
Design
*/
#include <iostream>
#include <string>
#include <windows.h>
#include<algorithm>

class Design
{
protected:
	std::string region, colorSpec;

public:
	Design(std::string n, std::string a)
	{
		std::cout << "costructor base class" << std::endl;
		region = n; colorSpec = a;
	}
	~Design()
	{
		std::cout << "destructor base class" << std::endl;
	}
	virtual void display() = 0;
};

class DesignInterior : public Design
{
private:
	std::string what, type;
public:
	DesignInterior(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
	{
		std::cout << "child class costructor" << std::endl;
		what = t;
		type = tp;
	}
	~DesignInterior()
	{
		std::cout << "child class destructor" << std::endl;
	}
	void display() override
	{
		std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tPremises: " << what << "\tStyle: " << type << std::endl;
	}
};

class ClothingDesign : public Design
{
private:
	std::string what,
		season;
public:
	ClothingDesign(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
	{
		std::cout << "child class costructor" << std::endl;
		what = t;
		season = tp;
	}
	~ClothingDesign()
	{
		std::cout << "child class destructor" << std::endl;
	}
	void display() override
	{
		std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tName of clothes: " << what << "\tSeason: " <<
			season << std::endl;
	}
};

class WebDesign : public Design
{
private:
	std::string what, type;
public:
	WebDesign(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
	{
		std::cout << "child class costructor" << std::endl;
		what = t;
		type = tp;
	}
	~WebDesign()
	{
		std::cout << "child class destructor" << std::endl;
	}
	void display() override
	{
		std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tDesign of wich resource: " << what << "\tStyle: " << type << std::endl;
	}
};

bool check(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), tolower);
	char alf[] = "abcdefghijklmnopqrstuvwxyz ";
	int l = 0;
	bool rez = false;
	char* v = NULL;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < strlen(alf); j++)
		{
			if (str[i] == alf[j])
			{
				l++;
				break;
			}
		}
	}
	if (str.length() == l && l > 2)
	{
		return true;
	}
	else {
		return false;
	}
}


void menu(Design* des[3])
{
	int ch = 5;
	std::cout<<std::endl;
	std::cout << "WEB-DESIGN" << std::endl;
	std::string w, s, r1,c1;
	while (check(r1) == false)
	{
		std::cout << "ENTER Appliction area:" << std::endl;
		std::getline(std::cin, r1);
	}
	while (check(c1) == false)
	{
		std::cout << "ENTER Color spectrum:" << std::endl;
		std::getline(std::cin, c1);
	}
	while (check(w) == false)
	{
		std::cout << "ENTER Design of wich resource:" << std::endl;
		std::getline(std::cin, w);
	}
	while (check(s) == false)
	{
		std::cout << "ENTER Style:" << std::endl;
		std::getline(std::cin, s);
	}
	WebDesign wd(r1, c1, w, s);
	des[0] = &wd;
	std::cout << std::endl;
	std::cout << "INTERIOR DESIGN" << std::endl;
	std::string po, st,r2,c2;
	while (check(r2) == false)
	{
		std::cout << "ENTER Appliction area:" << std::endl;
		std::getline(std::cin, r2);
	}
	while (check(c2) == false)
	{
		std::cout << "ENTER Color spectrum:" << std::endl;
		std::getline(std::cin, c2);
	}
	while (check(po) == false)
	{
		std::cout << "ENTER Premises:" << std::endl;
		std::getline(std::cin, po);
	}
	while (check(st) == false)
	{
		std::cout << "ENTER Style:" << std::endl;
		std::getline(std::cin, st);
	}
	DesignInterior di(r2, c2, po, st);
	des[1] = &di;
	std::cout << std::endl;
	std::cout << "CLOTHING DESIGN" << std::endl;
	std::string wc, sea,r3,c3;
	while (check(r3) == false)
	{
		std::cout << "ENTER Appliction area:" << std::endl;
		std::getline(std::cin, r3);
	}
	while (check(c3) == false)
	{
		std::cout << "ENTER Color spectrum:" << std::endl;
		std::getline(std::cin, c3);
	}
	while (check(wc) == false)
	{
		std::cout << "ENTER Name of clothes:" << std::endl;
		std::getline(std::cin, wc);
	}
	while (check(sea) == false)
	{
		std::cout << "ENTER Season:" << std::endl;
		std::getline(std::cin, sea);
	}
	ClothingDesign cd(r3, c3, wc, sea);
	des[2] = &cd;
		for (int i = 0; i < 3; i++)
		{
			des[i]->display();
		}
}
int main()
{
	std::string reg, col;
	std::cout << "D E S I G N " << std::endl;
	Design* d[3];
	/*while (check(reg) == false)
	{
		std::cout << "ENTER Appliction area:" << std::endl;
		std::getline(std::cin, reg);
	}
	while (check(col) == false)
	{
		std::cout << "ENTER Color spectrum:" << std::endl;
		std::getline(std::cin, col);
	}*/
		menu(d);
	return 0;
}