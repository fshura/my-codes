#ifndef tbook_h
#define tbook_h

#include <iostream>
#include <string>
#include <vector>

struct Contact{
	std::string name;
	std::string number;
};

void add(std::vector<Contact>& contacts);
void all(const std::vector<Contact>& contacts);
void del(std::vector<Contact>& contacts);
void sortAZ(std::vector<Contact>& contacts);
void importTBook(std::vector<Contact>& contacts);
void exportTBook(const std::vector<Contact>& contacts);

#endif
