#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <climits>
#include <algorithm>
#include <fstream>
#include <sstream>

int countContact = 0;

struct Contact{
	std::string name;
	std::string number;
};

std::vector<Contact> contacts;

void add(){
	std::string nameInput,numberInput;
	std::cout << "Введите имя(0.Выход): ";
	std::cin >> nameInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if(nameInput == "0"){
		return;
	}
	std::cout << "Введите номер: ";
	std::cin >> numberInput;
	contacts.push_back({nameInput,numberInput});
	std::cout << "Контакт добавлен.\n\n";
};
void all(){
	if(contacts.empty()){
		std::cout << "Список контактов пуст.";
		return;
	}
	std::cout << "Список контактов: \n";
	for(size_t i = 0;i<contacts.size();i++){
		std::cout << i+1 << ". Имя: " << contacts[i].name <<
				  "\n   Номер: " << contacts[i].number << "\n";
	}
	std::cout << "\n";
}
void del(){
	if(contacts.empty()){
		std::cout << "Список контактов пуст.";
		return;
	}
	int temp;
	size_t iDel;
	
	std::cout << "Введите номер контакта в списке контактов(0.Выход): ";
	std::cin >> temp;
	
	if(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Ошибка! Введите число.";
		del();
	}
	if(temp >= 0 && static_cast<unsigned long long>(temp) <= SIZE_MAX){
		iDel = static_cast<size_t>(temp);
	} else {
		std::cout << "Ошибка! Введите положительное число.";
		del();
	}
	if(iDel == 0){
		return;
	}
	if(iDel <= contacts.size()){
	contacts.erase(contacts.begin()+iDel-1);
	std::cout << "Контакт номер " << iDel << " удалён.\n";
	} else {
		std::cout << "Такого контакта нет.\n\n";
	}
}

void sortAZ(){
	std::sort(contacts.begin(),contacts.end(),
	[] (const Contact& a, const Contact& b){
		return a.name < b.name;
	});
}

void importTBook(){
	std::ifstream in("tbook.txt");
	if(in.is_open()){
		std::string line;
		Contact item;
		while(std::getline(in,line)){
			std::stringstream ss(line);
			
			std::getline(ss,item.name,';');
			std::getline(ss,item.number);
			contacts.push_back(item);
		}
		std::cout << "Контакты успешно импортированы.";
	}
	in.close();
}

void exportTBook(){
	std::ofstream out("tbook.txt");
	if(out.is_open()){
		for(size_t i = 0;i<contacts.size();i++){
			out << contacts[i].name << ';' << contacts[i].number;
		}
	}
	out.close();
}

int main(){
	char action=' ';
	while(action!='0'){
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
				add();
				break;
			case '2':
				all();
				break;
			case '3':
				del();
				break;
			case '4':
				sortAZ();
				break;
			case '5':
				importTBook();
				break;
			case '6':
				exportTBook();
				break;
			case '0':
				std::cout << "Выход...\n";
				return 0;
			default:
				std::cout << "Некорректное действие\n";
				break;
		}
	}

}
