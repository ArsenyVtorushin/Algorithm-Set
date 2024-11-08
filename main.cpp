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
	MyClass(double val) :val_(::ceil(val)) {} // ceil - округление (из С)
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
		// в переменную tmp помещаем число от 1 до 10
		// с дробной частью от 0,1 до 1,0

		collection.emplace_back(tmp); // emplace_back принимает сразу аргументы, а push_back - надо сначала создать обьект и его уже передавать
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

	// чтобы класс мог быть помещен в set он должен
	//сравниваться на <
	std::multiset<MyClass> sortedCollection;

	// std::set - хранит элементы в отсортированном виде 
	// и хранит только уникальные элементы 
	// 
	// если требуется хранить неуникальные множества то 
	// использовать std::multiset
	//

	for (const/*<-(не обязательно)*/ auto& el : collection)
	{
		sortedCollection.insert(el);
	}

	for (const/*<-(не обязательно)*/ auto& el : sortedCollection)
	{
		std::cout << el.getVal() << ' ';
	}

	return 0;
}