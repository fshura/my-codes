#include <iostream>
#include <string>
#include <vector>

int countContact = 0;


struct Contact{
	int index;
	std::string name;
	std::string number;
};
std::vector<Contact> contacts;
int iAdd = 1;

void add(){
	std::cin.ignore();
	std::string nameInput,numberInput;
	std::cout << "Введите имя: ";
	std::cin >> nameInput;
	std::cout << "Введите номер: ";
	std::cin >> numberInput;
	Contact newContact = {iAdd,nameInput,numberInput};
	contacts.push_back({iAdd,nameInput,numberInput});
	std::cout << "Контакт номер "<< iAdd << " добавлен.\n\n";
	iAdd++;
};
void all(){
	std::cout << "Список контактов: \n";
	for(const auto& contact : contacts){
		std::cout << contact.index << ". Имя: " << contact.name <<
				  "\n   Номер: " << contact.number << "\n";
	}
	std::cout << "\n";
}
void del(){
	int iDel;
	std::cout << "Введите номер контакта в списке контактов: ";
	std::cin >> iDel;
	contacts.erase(contacts.begin()+iDel-1);
	iAdd--;
}
int main(){
	char action='0';
	while(action!='4'){
		std::cout << "1. Создать контакт\n"
				  << "2. Вывести все контакты\n"
				  << "3. Удалить контакт\n"
				  << "4. Выход\n\n"
				  << "Выберите действие: ";
		std::cin >> action;
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
	}
	}
std::cout << "Выход...\n";
return 0;
}
