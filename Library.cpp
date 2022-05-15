#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const char PASS[] = "00000000";
class Book{
	char* author;
	char* title;
	char* text;
	char* description;
	int rating;
	char* ISBN;
public:
	Book()
	{
		author = nullptr;
		title = nullptr;
		text = nullptr;
		description = nullptr;
		rating = 0;
		ISBN = nullptr;
	}
	void copyFrom(const Book& other)
	{
		author = new char[strlen(other.author)+1];
		strcpy(author, other.author);
		title = new char[strlen(other.title) + 1];
		strcpy(title, other.title);
		text = new char[strlen(other.text) + 1];
		strcpy(text, other.text);
		description = new char[strlen(other.description) + 1];
		strcpy(description, other.description);
		rating = other.rating;
		ISBN = new char[strlen(other.ISBN) + 1];
		strcpy(ISBN, other.ISBN);
	}
	void free()
	{
		delete[] author;
		delete[] title;
		delete[] text;
		delete[] description;
		delete[] ISBN;
	}
	Book(const Book& other)
	{
		copyFrom(other);
	}
	Book(char* author, char* title, char* text, char* description, int rating, char* ISBN)
	{
		this->author = nullptr;
		this->title = nullptr;
		this->text = nullptr;
		this->description = nullptr;
		this->rating = 0;
		this->ISBN = nullptr;
		setAuthor(author);
		setTitle(title);
		setText(text);
		setDescription(description);
		setRating(rating);
		setISBN(ISBN);
	}
	const char* getAuthor() const
	{
		return author;
	}
	const char* getTitle() const
	{
		return title;
	}
	const int getRating() const
	{
		return rating;
	}
	const char* getISBN() const
	{
		return ISBN;
	}
	const char* getDescription() const
	{
		return description;
	}
	const char* getText() const
	{
		return text;
	}
	void setRating(int rating)
	{
		if (rating > 0 && rating < 10)
		{
			this->rating = rating;
		}
		else{ this->rating = 0; }
	}
	void setISBN(char* ISBN)
	{
		delete[] this->ISBN;
		this->ISBN = new char[strlen(ISBN) + 1];
		strcpy(this->ISBN, ISBN);
	}
	void setAuthor(char* author)
	{
		delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
	}
	void setTitle(char* title)
	{
		delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
	void setText(char* text)
	{
		delete[] this->text;
		this->text = new char[strlen(text) + 1];
		strcpy(this->text, text);
	}
	void setDescription(char* description)
	{
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
	}
	Book& operator=(Book& other)
	{
		free();
		copyFrom(other);
		return *this;
	}
	~Book()
	{
		free();
	}
};
class Library{
public:
	Book* books;
	int numberOfBooks;

	Library()
	{
		books = nullptr;
		numberOfBooks = 0;
	}
	void sortBooks()
	{
		cout << "u-upwards sort" << endl<<"d-downwards sort"<<endl;
		char sortDir;
		cin >> sortDir;
		cout << "a-sort by author" << endl << "t-sort by title" << endl << "r-sort by rating" << endl;
		char sortType;
		cin >> sortType;
		if (sortDir == 'u')
		{
			if (sortType == 'a')
			{
				for (int j = 0; j < numberOfBooks; j++)
				{
					for (int i = 0; i < numberOfBooks - j - 1; i++)
					{
						if (strcmp(books[i].getAuthor(), books[i + 1].getAuthor()) == 1)
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}
			if (sortType == 't')
			{
				for (int j = 0; j < numberOfBooks; j++)
				{
					for (int i = 0; i < numberOfBooks - j - 1; i++)
					{
						if (strcmp(books[i].getTitle(), books[i + 1].getTitle()) == 1)
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}
			if (sortType == 'r')
			{
				for (int j = 0; j < numberOfBooks; j++)
				{
					for (int i = 0; i < numberOfBooks - j - 1; i++)
					{
						if (books[i].getRating()>books[i + 1].getRating())
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}
			
		}
		if (sortDir == 'd')
		{
			if (sortType == 'a')
			{
				for (int j = 0; j < numberOfBooks - 1; j++)
				{
					for (int i = j; i < numberOfBooks - 1; i++)
					{
						if (strcmp(books[i].getAuthor(), books[i + 1].getAuthor()) == -1)
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}
			if (sortType == 't')
			{
				for (int j = 0; j < numberOfBooks - 1; j++)
				{
					for (int i = j; i < numberOfBooks - 1; i++)
					{
						if (strcmp(books[i].getTitle(), books[i + 1].getTitle()) == -1)
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}
			if (sortType == 'r')
			{
				for (int j = 0; j < numberOfBooks - 1; j++)
				{
					for (int i = j; i < numberOfBooks - 1; i++)
					{
						if (books[i].getRating()>books[i + 1].getRating())
						{
							Book tmp = books[i + 1];
							books[i + 1] = books[i];
							books[i] = tmp;
						}
					}
				}
			}	
		}
		for (int i = 0; i < numberOfBooks;i++)
		{
			cout << "Author:" << books[i].getAuthor() << endl;
			cout << "Title:" << books[i].getTitle() << endl;
			cout << "ISBN:" << books[i].getISBN() << endl;
		}
	}
	void castBooksToClass()
	{
		ifstream file("books.txt");
		numberOfBooks = getAmmountOfBooksInFile(file);
		books = new Book[numberOfBooks];
		file.seekg(0, ios::beg);
		char buff[10000];
		int i = 0;
		while (!file.eof())
		{
			file.getline(buff, 10000, '@');
			cout << buff<<endl;
			books[i].setAuthor(buff);
			file.getline(buff, 10000, '@');
			cout << buff << endl;
			books[i].setTitle(buff);
			file.getline(buff, 10000, '@');
			cout << buff << endl;
			books[i].setDescription(buff);
			file.getline(buff, 10000, '@');
			cout << buff << endl;
			books[i].setRating(atoi(buff));
			file.getline(buff, 10000, '@');
			cout << buff << endl;
			books[i].setISBN(buff);
			i++;
		}
		file.close();
	}
	void addBook()
	{
		cout << "Author:";
		char newauthor[100];
		cin.getline(newauthor, 100);

		cout << "Title:";
		char newtitle[100];
		cin.getline(newtitle, 100);

		cout << "Description:";
		char newdescription[100];
		cin.getline(newdescription, 100);

		cout << "text file name:";
		char newtextFile[100];
		cin.getline(newtextFile, 100);

		cout << "text(write @ at the end):";
		char newtext[10000];
		cin.getline(newtext, 10000, '@');

		ofstream file(newtextFile);
		file << newtext;
		file.close();

		int newrating;
		cout << "Rating:";
		cin >> newrating;

		cin.get();
		cout << "ISBN:";
		char newISBN[100];
		cin.getline(newISBN, 100);

		ofstream booksFile("books.txt", ios::app);
		booksFile << newauthor << "@";
		booksFile << newtitle << "@";
		booksFile << newtextFile << "@";
		booksFile << newdescription << "@";
		booksFile << newrating << "@";
		booksFile << newISBN << "@";
		booksFile.close();

		Book b(newauthor, newtitle, newtextFile, newdescription, newrating, newISBN);
		numberOfBooks++;
		Book* temp = new Book[numberOfBooks];
		for (int i = 0; i < numberOfBooks-1; i++)
		{
			temp[i] = books[i];
		}
		temp[numberOfBooks - 1] = b;
		delete[] books;
		books = temp;
	}
	void deleteBook()
	{
		cin.get();
		cout << "type the title of the book you want to delete:";
		char delTitle[100];
		cin.getline(delTitle, 100);
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (strcmp(delTitle, books[i].getTitle())==0)
			{
				for (int j = i; j < numberOfBooks-1; j++)
				{
					books[i] = books[i + 1];
				}
				books[numberOfBooks].free();
				numberOfBooks--;
			}
		}
		ofstream file("books.txt");
		for (int i = 0; i < numberOfBooks; i++)
		{
			file << books[i].getAuthor() << '@';
			file << books[i].getTitle() << '@';
			file << books[i].getText() << '@';
			file << books[i].getDescription() << '@';
			file << books[i].getRating() << '@';
			file << books[i].getISBN() << '@';
		}
		//cout << "Do you want to delete the file with the book's text?(y or n):";
		//char delFile;
		//cin >> delFile;
		//if (delFile=='y')
		//{
		//	
		//}

	}
	void showBook()
	{
		cout << "Enter title of book:";
		char showTitle[100];
		cin.getline(showTitle, 100);
		cout << "r-show book by rows"<<endl<<"s-show book by sentences"<<endl<<"rows or sentences:";
		char command;
		cin >> command;
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (strcmp(showTitle, books[i].getTitle())==0)
			{
				ifstream file(books[i].getText());
				if (command == 'r')
				{
					cout << "How many rows:";
					int numberOfRows;
					cin >> numberOfRows;
					char row[100];
					while (!file.eof())
					{
						for (int j = 0; j < numberOfRows; j++)
						{
							
							file.get(row, 100);
							cout << row<<endl;
						}
						cout << "Continue?:";
						char nextPage;
						cin >> nextPage;
						if (nextPage == 'y')
						{
							continue;
						}
						else if (nextPage == 'n')
						{
							break;
						}
					}
				}
				else if (command == 's')
				{
					char nextSentence;
					while (!file.eof())
					{
						char character = '0';
						while (character != '?' && character != '.' && character != '!')
						{
							file.get(character);
							cout << character;
						}
						cout << endl;
						cout << "Continue?:";
						cin >> nextSentence;
						if (nextSentence=='y')
						{
							continue;
						}
						else if (nextSentence == 'n')
						{
							break;
						}
					}
				}
				file.close();
			}
		}
	}
	size_t getAmmountOfBooksInFile(ifstream& file)
	{
		size_t counter=0;
		while (!file.eof())
		{
			char ch;
			file >> ch;
			if (ch = '@')
			{
				counter++;
			}
		}
		cout << counter / 6;
		return counter / 6;
	}
	void getInfo()
	{
		cout << "a-Type author of the book" << endl << "t-Type title of the book" << endl << "i-Type ISBN of the book" << endl << "d-Type Part of the description of the book"<<endl;
		cout << "Enter command:";
		cin.get();
		char command;
		cin >> command;
		if (command == 'a')
		{
			cin.get();
			char searchAuthor[100];
			cin.get(searchAuthor, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchAuthor, books[i].getAuthor())==0)
				{
					cout << "Author:" << books[i].getAuthor() << endl;
					cout << "Title:" << books[i].getTitle() << endl;
					cout << "ISBN:" << books[i].getISBN() << endl;
					cout << "Description:" << books[i].getDescription() << endl;
				}
			}
		}
		if (command == 't')
		{
			cin.get();
			char searchTitle[100];
			cin.get(searchTitle, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchTitle, books[i].getTitle()) == 0)
				{
					cout << "Author:"<<books[i].getAuthor()<<endl;
					cout <<	"Title:" <<books[i].getTitle()<<endl;	
					cout <<"ISBN:" <<books[i].getISBN()<<endl;
					cout <<"Description:" <<books[i].getDescription()<<endl;
				}
			}
		}
		if (command == 'i')
		{
			cin.get();
			char searchISBN[100];
			cin.get(searchISBN, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchISBN, books[i].getISBN()) == 0)
				{
					cout << "Author:" << books[i].getAuthor() << endl;
					cout << "Title:" << books[i].getTitle() << endl;
					cout << "ISBN:" << books[i].getISBN() << endl;
					cout << "Description:" << books[i].getDescription() << endl;
				}
			}
		}
		if (command == 'd')
		{
			cin.get();
			char searchDescription[100];
			cin.get(searchDescription, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strstr(books[i].getDescription(), searchDescription))
				{
					cout << "Author:" << books[i].getAuthor() << endl;
					cout << "Title:" << books[i].getTitle() << endl;
					cout << "ISBN:" << books[i].getISBN() << endl;
					cout << "Description:" << books[i].getDescription() << endl;
				}
			}
		}
	}
	bool checkPassword(char* password)
	{
		if (strcmp(password, PASS) == 0)
		{
			return 1;
		}
		return 0;
	}
	
	void start()
	{
		char newpas[20];
		char command;
		cout << "Command guide:" << endl << "a-add a book" << endl << "r-remove a book" << endl << "s-sort books" << endl << "i-show info for book" << endl << "f-find Book" << endl << "c-close" << endl << "h-help"<<endl;
		while (true)
		{
			cout << "Enter command:";
			cin >> command;
			if (command == 'h')
			{
				cout << "Command guide:" << endl << "a-add a book" << endl << "r-remove a book" << endl << "s-sort books" << endl << "i-show info for book" << endl << "f-find Book" << endl << "c-close" << endl << "h-help" << endl;
			}
			else if (command == 'c')
			{
				break;
			}
			else if (command == 's')
			{
				sortBooks();
			}
			else if (command == 'r')
			{
				cout << "Enter password:";
				cin.ignore();
				cin.getline(newpas, 20);
				if (checkPassword(newpas))
				{
					deleteBook();
				}
				else{ cout << "No access"<<endl; }
			}
			else if (command == 'a')
			{
				cout << "Enter password:";
				cin.ignore();
				cin.getline(newpas, 20);
				if (checkPassword(newpas))
				{
					addBook();
				}
				else{ cout << "No access"<<endl; }
			}
			else if (command == 'i')
			{
				getInfo();
			}
			else if (command == 'f')
			{
				cin.ignore();
				showBook();
			}
		}
	}
};

int main()
{
	Library l;
	//l.castBooksToClass();
	l.start();

	return 0;
}

