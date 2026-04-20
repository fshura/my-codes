#include "tbook.h"

void add(std::vector<Contact>& contacts){
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
void all(const std::vector<Contact>& contacts){
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
void del(std::vector<Contact>& contacts){
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
		std::cout << "Ошибка! Введите номер контакта.";
	}
	if(temp >= 0 && static_cast<unsigned long long>(temp) <= SIZE_MAX){
		iDel = static_cast<size_t>(temp);
	} else {
		std::cout << "Ошибка! Введите номер контакта.";
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

void sortAZ(std::vector<Contact>& contacts){
	if(contacts.empty()){
		std::cout << "Список контактов пуст.";
		return;
	}
	std::sort(contacts.begin(),contacts.end(),
	[] (const Contact& a, const Contact& b){
		return a.name < b.name;
	});
}

void importTBook(std::vector<Contact>& contacts){
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

void exportTBook(const std::vector<Contact>& contacts){
	std::ofstream out("tbook.txt");
	if(out.is_open()){
		for(size_t i = 0;i<contacts.size();i++){
			out << contacts[i].name << ';' << contacts[i].number;
		}
	}
	out.close();
}
