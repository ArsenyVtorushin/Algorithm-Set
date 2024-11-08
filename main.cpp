#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

class MyClass
{
public:
	MyClass() = default;
	MyClass(int val) :val_(val) {}
	MyClass(double val) :val_(::ceil(val)) {} // ceil - ���������� (�� �)
	~MyClass() = default;

	void setVal(int val) { val_ = val; }
	void setVal(double val) { val_ = ::ceil(val); }
	int getVal()const { return val_; }

	MyClass& operator =(const MyClass& other) = default;
	bool operator <(const MyClass& other)const
	{
		return val_ < other.val_;
	}

private:
	int val_;
};

int main()
{
	std::vector<MyClass> collection;
	collection.reserve(15);

	for (int i = 0; i < collection.capacity(); i++)
	{
		double tmp = 1 + ::rand() % 10;
		tmp += 1. / (1 + ::rand() % 10); //cstdlib
		// � ���������� tmp �������� ����� �� 1 �� 10
		// � ������� ������ �� 0,1 �� 1,0

		collection.emplace_back(tmp); // emplace_back ��������� ����� ���������, � push_back - ���� ������� ������� ������ � ��� ��� ����������
	}

	for (int i = 0; i < collection.size(); i++)
	{
		std::cout << collection[i].getVal() << ' ';
	}

	/*std::sort(collection.begin(), collection.end());
	std::cout << '\n';

	for (int i = 0; i < collection.size(); i++)
	{
		std::cout << collection[i].getVal() << ' ';
	}*/

	std::cout << "\n";

	// ����� ����� ��� ���� ������� � set �� ������
	//������������ �� <
	std::multiset<MyClass> sortedCollection;

	// std::set - ������ �������� � ��������������� ���� 
	// � ������ ������ ���������� �������� 
	// 
	// ���� ��������� ������� ������������ ��������� �� 
	// ������������ std::multiset
	//

	for (const/*<-(�� �����������)*/ auto& el : collection)
	{
		sortedCollection.insert(el);
	}

	for (const/*<-(�� �����������)*/ auto& el : sortedCollection)
	{
		std::cout << el.getVal() << ' ';
	}

	return 0;
}