// testDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Books.h"
#include <vector>
#include <iostream>
#include <memory>
int main()
{
	BookNmCls::Dab books =  std::move(create_the_books());
	
	std::vector<std::string> tags;
	BookNmSpc::Book brook("name", tags, "ctgry", "rs");
	std::cout << "JUST A TEST" + brook.m_name+"\n";
	books->add_book("name", tags, "ctgry", "rs");
	books->add_book("name", tags, "ctgry", "rs");
	std::vector<std::string> sad = books->get_all_books();
	std::cout << sad.size();
	for ( std::string book : sad) {
		std::cout << book <<"\n";
	}
	books->remove_book("name");
	sad = books->get_all_books();
	for (std::string book : get_all_catagories()) {
		std::cout << book << "\n";
		
	}
	std::vector<std::string> strv = all_reading_status;
	for (std::string book : strv) {
		std::cout << book << "\n";

	}
	int i = 0;
	while (i<100000000000)
	{
		i++;
	}


    return 0;
}

