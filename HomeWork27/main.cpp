#include <iostream>
#include <string>

struct Movie {
	std::string title = "No movie";
	int year = 1970;
	std::string genre = "No genre";
	unsigned int duration = 0;
	unsigned int price = 0;
};

void print_movie(Movie MV) {
	std::cout << "Название фильма:\t\t" << MV.title << '\n';
	std::cout << "Год выхода:\t\t\t" << MV.year << '\n';
	std::cout << "Жанр фильма:\t\t\t" << MV.genre << '\n';
	std::cout << "Продолжительность фильма:\t" << MV.duration << " мин.\n";
	std::cout << "Цена за диск:\t\t\t" << MV.price << " руб.\n";
}

Movie expensive(Movie MV[], const int length) {
	int max = MV[0].price;
	int index = 0;
	for (int i = 1; i < length; i++)
		if (max < MV[i].price) {
			max = MV[i].price;
			index = i;
		}

	return MV[index];
}

void update_info(Movie& MV) {
	int n;
	std::cout << "Выберите, какую информацию о фильме\n" <<
		"необходимо обновить:\n";
	std::cout << "1. Название;\n";
	std::cout << "2. Год выхода;\n";
	std::cout << "3. Жанр;\n";
	std::cout << "4. Продолжительность;\n";
	std::cout << "5. Цена за диск;\n";
	std::cout << "Ввод -> ";
	std::cin >> n;

	switch (n) {
	case 1: {
		std::cout << "Введите новое название фильма:\nВвод -> ";
		std::cin >> MV.title;
		std::cout << "Информация обновлена.\n";
		break;
	}
	case 2: {
		std::cout << "Введите новый год выхода:\nВвод -> ";
		std::cin >> MV.year;
		std::cout << "Информация обновлена.\n";
		break;
	}
	case 3: {
		std::cout << "Введите новый жанр фильма:\nВвод -> ";
		std::cin >> MV.genre;
		std::cout << "Информация обновлена.\n";
		break;
	}
	case 4: {
		std::cout << "Введите новую продолжительность фильма:\nВвод -> ";
		std::cin >> MV.duration;
		std::cout << "Информация обновлена.\n";
		break;
	}
	case 5: {
		std::cout << "Введите новую цену диска:\nВвод -> ";
		std::cin >> MV.price;
		std::cout << "Информация обновлена.\n";
		break;
	}
	default: std::cout << "Введена не корректная информация!\n";
	}

}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Вывод полей структуры

	std::cout << "Задача 1.\n\n";
	Movie mv1{"Stree Fighter",1994,"Action",100, 255};
	print_movie(mv1);
	std::cout << "\n\n";

	// Задача 2. Самый дорогой диск с кино
	std::cout << "Задача 2.\n\n";
	const int size = 3;
	Movie arrMV[size]{
		mv1,
		{"Predator",1987,"Action",107, 300},
		{"The Terminarot",1984,"Action",107,155}
	};

	Movie expnMV;

	expnMV = expensive(arrMV, size);

	print_movie(expnMV);
	std::cout << std::endl;


	// Задача 3. Функция обновления полей в структуре
	std::cout << "Задача 3.\n";

	update_info(mv1);

	print_movie(mv1);
	std::cout << std::endl;

	return 0;
}