#include <iostream>
#include <string>
using namespace std;

// Abstract Class
class LibraryItem
{
public:
  virtual void display() = 0;
};

// Book Class
class Book : public LibraryItem
{
private:
  string title;
  string author;
  int pages;

public:
  Book() {}

  Book(string t, string a, int p)
  {
    title = t;
    author = a;
    pages = p;
  }

  string getTitle()
  {
    return title;
  }

  int getPages()
  {
    return pages;
  }

  void display()
  {
    cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
  }
};

// Newspaper Class
class Newspaper : public LibraryItem
{
private:
  string name;
  string date;
  string edition;

public:
  Newspaper() {}

  Newspaper(string n, string d, string e)
  {
    name = n;
    date = d;
    edition = e;
  }

  string getName()
  {
    return name;
  }

  string getEdition()
  {
    return edition;
  }

  void display()
  {
    cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
  }
};

// Template Linear Search for Book
template <class T>
T *linearSearchByTitle(T arr[], int size, string key)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i].getTitle() == key)
    {
      return &arr[i];
    }
  }
  return NULL;
}

// Template Linear Search for Newspaper
template <class T>
T *linearSearchByName(T arr[], int size, string key)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i].getName() == key)
    {
      return &arr[i];
    }
  }
  return NULL;
}

// Library Class
class Library
{
private:
  Book books[10];
  Newspaper newspapers[10];
  int bookCount = 0;
  int newspaperCount = 0;

public:
  void addBook(Book b)
  {
    books[bookCount++] = b;
  }

  void addNewspaper(Newspaper n)
  {
    newspapers[newspaperCount++] = n;
  }

  void displayCollection()
  {
    cout << "Books:\n";
    for (int i = 0; i < bookCount; i++)
      books[i].display();

    cout << "\nNewspapers:\n";
    for (int i = 0; i < newspaperCount; i++)
      newspapers[i].display();
  }

  // Selection Sort for Books
  void sortBooksByPages()
  {
    for (int i = 0; i < bookCount - 1; i++)
    {
      int minIndex = i;

      for (int j = i + 1; j < bookCount; j++)
      {
        if (books[j].getPages() < books[minIndex].getPages())
        {
          minIndex = j;
        }
      }

      Book temp = books[i];
      books[i] = books[minIndex];
      books[minIndex] = temp;
    }
  }

  // Selection Sort for Newspapers
  void sortNewspapersByEdition()
  {
    for (int i = 0; i < newspaperCount - 1; i++)
    {
      int minIndex = i;

      for (int j = i + 1; j < newspaperCount; j++)
      {
        if (newspapers[j].getEdition() < newspapers[minIndex].getEdition())
        {
          minIndex = j;
        }
      }

      Newspaper temp = newspapers[i];
      newspapers[i] = newspapers[minIndex];
      newspapers[minIndex] = temp;
    }
  }

  Book *searchBookByTitle(string title)
  {
    return linearSearchByTitle(books, bookCount, title);
  }

  Newspaper *searchNewspaperByName(string name)
  {
    return linearSearchByName(newspapers, newspaperCount, name);
  }
};

int main()
{
  // Create book objects
  Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
  Book book2("To Kill a Mockingbird", "Harper Lee", 324);

  // Create newspaper objects
  Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
  Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

  // Create a library object
  Library library;

  // Add books and newspapers to the library
  library.addBook(book1);
  library.addBook(book2);
  library.addNewspaper(newspaper1);
  library.addNewspaper(newspaper2);

  // Display the entire collection
  cout << "Before Sorting:\n";
  library.displayCollection();

  // Sort books by pages and newspapers by edition
  library.sortBooksByPages();
  library.sortNewspapersByEdition();

  cout << "\nAfter Sorting:\n";
  library.displayCollection();

  // Search for a book by title
  Book *foundBook = library.searchBookByTitle("The Catcher in the Rye");
  if (foundBook)
  {
    cout << "\nFound Book:\n";
    foundBook->display();
  }
  else
  {
    cout << "\nBook not found.\n";
  }

  // Search for a newspaper by name
  Newspaper *foundNewspaper = library.searchNewspaperByName("The Times");
  if (foundNewspaper)
  {
    cout << "\nFound Newspaper:\n";
    foundNewspaper->display();
  }
  else
  {
    cout << "\nNewspaper not found.\n";
  }

  return 0;
}