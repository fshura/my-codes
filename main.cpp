#include "tbook.h"

int main(){
	std::vector<Contact> contacts;
	char action=' ';
	do {
		std::cout << "1. Создать контакт\n"
				  << "2. Вывести все контакты\n"
				  << "3. Удалить контакт\n"
				  << "4. Отсортировать в алфавитном порядке\n"
				  << "5. Импортировать контакты\n"
				  << "6. Экспортировать контакты\n"
				  << "0. Выход\n\n"
				  << "Выберите действие: ";
		std::cin >> action;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(action){
			case '1':
				add(contacts);
				break;
			case '2':
				all(contacts);
				break;
			case '3':
				del(contacts);
				break;
			case '4':
				sortAZ(contacts);
				break;
			case '5':
				importTBook(contacts);
				break;
			case '6':
				exportTBook(contacts);
				break;
			case '0':
				std::cout << "Выход...\n";
				return 0;
			default:
				std::cout << "Некорректное действие\n";
				break;
		}
	} while(action!=0);

}
