#pragma once

#ifdef BOOKSDLL_EXPORTS  
#define BOOKSDLL_API __declspec(dllexport)   
#else  
#define BOOKSDLL_API __declspec(dllimport)   
#endif  

#include <string>
#include <vector>
#include <memory>
namespace BookNmSpc {

	 struct Book {


		std::string m_name;
		std::vector<std::string> m_tags;
		int32_t m_page_number;
		std::string m_catagory;
		std::string m_reading_status;
		std::vector<std::string> m_book_notes;
		//Book(std::string name, std::vector<std::string> tags, std::string catagory, std::string reading_status):m_name(name),m_tags(tags),m_catagory(catagory),m_reading_status(reading_status) {}
		Book(const std::string& name, const std::string& catagory,const std::string& reading_status, std::vector<std::string>* tags = nullptr , int32_t page_number = 0, std::vector<std::string>* book_notes = nullptr) :m_name(name), m_tags(tags!=nullptr?std::move(*tags):std::vector<std::string>(0)), m_catagory(catagory), m_reading_status(reading_status),m_page_number(page_number), m_book_notes(book_notes != nullptr ? std::move(*book_notes) : std::vector<std::string>(0)) {}
		Book() {}
		
	};
}

