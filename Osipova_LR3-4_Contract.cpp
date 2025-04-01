#include <cmath> 
#include <iomanip>
#include <M:\\Programming\\LR\\LR3_Class_Method\\Methods.h>

//конструкторы
Polynom::Polynom()
{
	deg = rand() % 5 + 1; //получение случайной степени полинома 
	koef.resize(deg, 0); //изменение размера вектора с установлением значения по умолчанию 0 
	//установление элементам вектора случайных значений 
	generate(koef.begin(), koef.end(), []() { return rand() % 100; });
}

Polynom::Polynom(unsigned k)
{
	deg = k; //создание полинома с заданной степенью 
	koef.resize(deg, 0); //изменение размера вектора с установлением значения по умолчанию 0 
	//установление элементам вектора случайных значений
	generate(koef.begin(), koef.end(), [] () { return rand() % 100; });
}
	//создание полинома заданной степени с заданным массивом коэффициентов 
Polynom::Polynom(unsigned k, vector<double> mas) : Polynom(k) {
	setPolynom(k, mas);
}
	//создание полинома путем копирования
Polynom::Polynom(const Polynom& other)
	: deg(other.deg), koef(other.koef) {}

void Polynom::CalculateValue(double x = 1.0)//вычисление значения полинома для заданного х
{
	double s;
	int i;
	for (s = koef[0], i = 1; i <= deg; i++)
		s = s + koef[i] * pow(x, i);
	std::cout << "f(" << x << ") = ";
	std::cout << s << std::endl;
}

//переопределение операции сложения
Polynom Polynom::operator+(const Polynom& other) const {
	Polynom result;
	result.deg = max(deg, other.deg); // Mаксимальная степень pезультата 
	result.koef.resize(result.deg + 1, 0.0); // Размер вектора = степень + 1
	// Складываем коэффициенты при одинаковых степенях
	for (unsigned exponent = 0; exponent <= result.deg; ++exponent) {
		double this_coeff = 0.0;
		if (exponent <= deg) {
			// Индекс коэффициента при степени exponent в текущем полиноме 
			unsigned idx = deg - exponent;
			this_coeff = koef[idx];
		}
		double other_coeff = 0.0;
		if (exponent <= other.deg) {
			// Индекс коэффициента при степени exponent в другом полиноме 
			unsigned idx = other.deg - exponent;
			other_coeff = other.koef[idx];
		}
		// Индекс в результате (хранится в порядке убывания степеней) 
		unsigned result_idx = result.deg - exponent;
		result.koef[result_idx] = this_coeff + other_coeff;
	}
	return result;
}

//переопределение оператора вывода на консоль 
ostream& operator<<(ostream& mystream, const Polynom& obj)
{
	bool firstTerm = true; // флак для первого члена полинома

	for (size_t i = 0; i < obj.koef.size(); i++) {
		double coeff = obj.koef[i];
		// Пропускаем нулевые хоэффициенты
		if (abs(coeff) < 1e-10) continue;
		// Выводим знак коэффициента
		if (!firstTerm) mystream << (coeff > 0 ? "+" : " - ");
		else {
			if (coeff < 0) mystream << "-";
			firstTerm = false;
		}

		// Выводим коэффициент (без знака) 
		double absCoeff = abs(coeff);
		// Не выводим 1 перед х^0
		if (absCoeff != 1.0 || i == obj.koef.size() - 1) mystream << fixed << setprecision(2) << absCoeff;

		// Выводим переменную х и степень
		if (i < obj.koef.size() - 1) {
			mystream << "x";
			if (i < obj.koef.size() - 2) mystream << "A" << (obj.koef.size() - 1 - i);

		}
	}
// Если все коэффициенты нулевые
	if (firstTerm) mystream << "0" << endl;
	return mystream;
}

//переопределение оператора ввода с консоли
istream& operator>>(istream& mystream, Polynom& obj)
{
	int i;
	string st;
	cout << "Enter Degree: ";
	getline(mystream, st);
	obj.deg = stoi(st);
	cout << endl;
	obj.koef.clear();
	for (i = obj.deg; i >= 0; i--)
	{
		cout << "Enter koeff " << i << ": ";
		getline(mystream, st);
		obj.koef.push_back(stod(st));
	}
	return mystream;
}