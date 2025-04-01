#include <ctime>

#include <M:\\Osipova_Program\\Osipova_LR3-4_Contract\\Osipova_LR3-4_Contract.cpp>



using namespace std;



int main()

{
	//генерация начального случайного значения    
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	map<int, MenuItem> menu =

	{
		{1, {"Create Polynom Constructor default", createPolDefault}},
		{2, {"Create Polynom Constructor with degree", createPolDeg}},
		{3, {"Create Polynom Constructor with degree & coefficients", createPolDegCoeff} },
			{ 4, {"Create Polynom with consol", createPolCons} },
			{ 5, {"Show array of Polynom", showArrayPol(vectorOfallPolynoms)} },

			{ 6, {"Calculate value of Polynom", calcvalPol} },

			{ 7, {"Add of Polynoms", addPolynoms} },

			{ 8, {"Sum of array the Polynoms", sumArrPolynoms} },
	};

	unsigned choice = 0; // Переменная для хранения выбора пользователя



	// Основной цикл программы

	//while (true) {

	cout << "Меню:" << endl;

	//Вывод всех пунктов меню

	for (const auto& item : menu) {
		std::cout << "Task " << item.first << ", " << item.second.title << std::endl;

	}
		std::cout << "0. Выход" << std::endl; // Пункт для выхода из программы    
		return 0;

}