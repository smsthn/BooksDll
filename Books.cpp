#include "stdafx.h"
#include "Books.h"
#include <iostream>

BookNmSpc::Books::Books()
{
}
//Add And Modify Methods
/// <summary>
/// Adds A New Book With 0 As Pages
/// </summary>
/// <param name="name"></param>
/// <param name="tags"></param>
/// <param name="catagory"></param>
/// <param name="reading_status"></param>
void BookNmSpc::Books::add_book(const std::string& name, const std::string& catagory, const std::string& reading_status, std::vector<std::string>* tags, int32_t page_number, std::vector<std::string>*  book_notes)
{
	all_books.push_back(std::make_unique<BookNmSpc::Book>(name, catagory, reading_status, tags, page_number, book_notes));
}
void BookNmSpc::Books::remove_book(const std::string& book_name)
{
	for (auto itr = all_books.begin(); itr != all_books.end(); itr++)
	{
		if (itr->get()->m_name == book_name)
		{
			all_books.erase(itr);
			return;
		}
	}
}
void BookNmSpc::Books::modify_book(const std::string& old_name, const std::string& name, const std::string& catagory, const std::string& reading_status, std::vector<std::string>* tags, int32_t page_number)
{
	for (auto itr = all_books.begin(); itr != all_books.end(); itr++)
	{
		if (itr->get()->m_name == old_name)
		{
			itr->get()->m_name = name;
			itr->get()->m_tags = std::move(*tags);
			itr->get()->m_catagory = catagory;
			itr->get()->m_reading_status = reading_status;
			itr->get()->m_page_number = page_number;
			return;
		}
	}
}
void BookNmSpc::Books::add_tag(std::string tag)
{
	all_tags.push_back(tag);
}

void BookNmSpc::Books::add_book_note(const std::string & book_name,const std::string & note)
{
	for (BookPtr& book : all_books) {
		if (book->m_name == book_name)book->m_book_notes.push_back(note);
	}
}

void BookNmSpc::Books::remove_book_note(const std::string & book_name, int32_t index)
{
	for (BookPtr& book : all_books) {
		if (book->m_name == book_name)book->m_book_notes.erase(book->m_book_notes.begin()+index);
	}
}




//

//Getters
std::vector<std::string> BookNmSpc::Books::get_all_catagories()
{
	return std::vector<std::string>();
}

std::vector<std::string> BookNmSpc::Books::get_all_reading_status()
{
	return std::vector<std::string>();
}
/// <summary>
/// Gets A List Of All The Books
/// </summary>
/// <returns> a Temporary String List Of All The BOoks</returns>
std::vector<std::string> BookNmSpc::Books::get_all_books()
{
	std::vector<std::string> books_names_list;
	for (auto& book : all_books) {
		books_names_list.push_back(book->m_name);
	}
	return books_names_list;
}
/// <summary>
/// Gets A List Of All The Tags
/// </summary>
/// <returns>A Const Reference To The Tags String Vector</returns>
const std::vector<std::string>& BookNmSpc::Books::get_all_tags()
{
	return all_tags;
}
/// <summary>
/// Returns A Vecotr Of The Filtered Books
/// </summary>
/// <param name="selected_name"></param>
/// <param name="selected_tags"></param>
/// <param name="selected_catagory"></param>
/// <param name="selected_reading_status"></param>
/// <returns></returns>
std::vector<std::string> BookNmSpc::Books::get_filtered_books_list(std::vector<std::string> selected_tags, std::string selected_catagory, std::string selected_reading_status)
{
	typedef std::string Str;
	auto checkTags = [&](BookNmSpc::BookPtr& book, std::vector<std::string> slctd_tags, Str slctd_ctgry, Str slctd_rd_stt) {
		bool tags_check = true;
		if (!slctd_tags.empty())
		{
			for (const auto& tag : slctd_tags) {
				tags_check &= std::find(book->m_tags.begin(), book->m_tags.end(), tag) != book->m_tags.end();
			}
		}
		bool ctgry_check = (book->m_catagory == slctd_ctgry) || (slctd_ctgry == "Any");
		bool rd_stt_check = (book->m_reading_status == slctd_rd_stt) || (slctd_rd_stt == "Any");

		return tags_check && ctgry_check && rd_stt_check;
	};
	std::vector<std::string> books_filtered_list;
	for (auto& book : all_books) {
		if (checkTags(book, selected_tags, selected_catagory, selected_reading_status))
		{
			books_filtered_list.push_back(book->m_name);
		}
	}
	return books_filtered_list;
}
//

//The Books Factory Methods : "Global", P.S :Don't Forget To Delete

/// <summary>
/// Creats TheBooks
/// </summary>
/// <returns>Pointer To A Newly Created Books Instance</returns>
std::unique_ptr<BookNmSpc::BooksInterface> create_the_books()
{
	return std::make_unique<BookNmSpc::Books>();
}
/// <summary>
/// Deletes The Created Books Object
/// </summary>
/// <param name="the_book"></param>
/// <returns></returns>
BOOKSDLL_API void delete_the_books(BookNmSpc::BooksInterface * the_book)
{
	delete the_book;
}

BOOKSDLL_API const std::vector<std::string>& get_all_catagories()
{
	return all_catagories;
}

BOOKSDLL_API const std::vector<std::string>& get_all_reading_status()
{
	return all_reading_status;
}

