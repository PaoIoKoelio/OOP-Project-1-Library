#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const char* PASS = "00000000";
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
	}
	Book(const Book& other)
	{
		copyFrom(other);
	}
	Book(char* author, char* title, char* text, char* description, int rating, char* ISBN)
	{
		setAuthor(author);
		setTitle(title);
		setText(text);
		setDescription(description);
		setRating(rating);
		setISBN(ISBN);
	}
	char* getAuthor() const
	{
		return author;
	}
	char* getTitle() const
	{
		return title;
	}
	int getRating() const
	{
		return rating;
	}
	char* getISBN() const
	{
		return ISBN;
	}
	char* getDescription() const
	{
		return description;
	}
	char* getText() const
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
		this->author = new char[strlen(ISBN) + 1];
		strcpy(this->ISBN, ISBN);
	}
	void setAuthor(char* author)
	{
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
	}
	void setTitle(char* title)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
	void setText(char* text)
	{
		this->text = new char[strlen(text) + 1];
		this->text = text;
	}
	void setDescription(char* description)
	{
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
	}
	Book& operator=(Book& other)
	{
		free();
		copyFrom(other);
		return other;
	}
	~Book()
	{
		free();
	}
};
class User{
	char* name;
	char* password;
	bool adminAccess;
public:
	void setAccess(bool adminAccess)
	{
		this->adminAccess = adminAccess;
	}
	bool getAccess() const
	{
		return adminAccess;
	}
	char* getName() const
	{
		return name;
	}
	void writeToFile()
	{
		ofstream file("users Info.dat");
		file.write((const char*)&name, sizeof(name));
		file.write((const char*)&password, sizeof(password));
		file.write((const char*)&adminAccess, sizeof(adminAccess));
	}
	
	//void setPassword()
	//{
	//	cout << "Give password";
	//	char* userPass;
	//	cin.getline(userPass, 10);
	//	password = new char[strlen(password) + 1];
	//	strcpy(password, userPass);
	//	if (checkPassword(password))
	//	{
	//		setAccess(1);
	//	}
	//	setAccess(0);
	//}
};
class Library{
	Book* books;
	int numberOfBooks;
public:
	Library()
	{
		books = nullptr;
		numberOfBooks = 0;
	}
	Library(Book* books, int numberOfBooks)
	{
		
	}

	void sortBooks()
	{
		char sortDir;
		cin >> sortDir;
		char sortType;
		cin >> sortType;
		if (sortDir == 'u')
		{
			if (sortType = 'a')
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
			if (sortType = 't')
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
			if (sortType = 'r')
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
		if (sortType == 'd')
		{
			if (sortType = 'a')
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
			if (sortType = 't')
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
			if (sortType='r')
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
			for (int i = 0; i < numberOfBooks;i++)
			{
				cout << books[i].getAuthor();
				cout << books[i].getTitle();
				cout << books[i].getISBN();
			}
		}
	}
	void castBooksToClass(Library& l)
	{
		ifstream file("books.txt");
		char* buff = new char[10000];
		while (!file.eof())
		{
			int i = 0;
			file.getline(buff, strlen(buff), '@');
			l.books[i].setAuthor(buff);
			file.getline(buff, strlen(buff), '@');
			l.books[i].setTitle(buff);
			file.getline(buff, strlen(buff), '@');
			l.books[i].setDescription(buff);
			file.getline(buff, strlen(buff), '@');
			l.books[i].setRating(atoi(buff));
			file.getline(buff, strlen(buff), '@');
			l.books[i].setISBN(buff);
			i++;
		}
		delete[] buff;

	}
	void addBook()
	{
		cin.get();
		cout << "Author:";
		char* newauthor = new char[100];
		cin.getline(newauthor, strlen(newauthor));
		cout << "Title:";
		char* newtitle = new char[100];
		cin.getline(newtitle, strlen(newtitle));
		cout << "Description:";
		char* newdescription = new char[100];
		cin.getline(newdescription, strlen(newdescription));
		cout << "text file name:";
		char* newtextFile = new char[100];
		cin.getline(newtextFile, strlen(newtextFile));
		cout << "text:";
		char* newtext = new char[10000];
		cin.getline(newtext, strlen(newtext));
		ofstream file(newtextFile);
		file << newtext;
		file.close();
		int newrating;
		cout << "Rating:";
		cin >> newrating;
		cin.get();
		cout << "ISBN:";
		char* newISBN = new char[100];
		cin.getline(newISBN, strlen(newISBN));
		Book b(newauthor, newtitle, newdescription, newtextFile, newrating, newISBN);
		numberOfBooks++;
		books[numberOfBooks - 1] = b;
		ofstream booksFile("books.txt");
		booksFile << newauthor << "@";
		booksFile << newtitle << "@";
		booksFile << newdescription << "@";
		booksFile << newtextFile << "@";
		booksFile << newrating << "@";
		booksFile << newISBN << "@";
		//ofstream booksFile("books.dat", ios::binary);
		//size_t authorSize = strlen(newauthor);
		//booksFile.write((const char*)authorSize, sizeof(authorSize));
		//booksFile.write((const char*)&newauthor, authorSize);
		//size_t titleSize = strlen(newtitle);
		//booksFile.write((const char*)titleSize, sizeof(titleSize));
		//booksFile.write((const char*)&newtitle, titleSize);
		//size_t textFileSize = strlen(newtextFile);
		//booksFile.write((const char*)textFileSize, sizeof(textFileSize));
		//booksFile.write((const char*)&newtextFile, textFileSize);
		//size_t desSize = strlen(newdescription);
		//booksFile.write((const char*)desSize, sizeof(desSize));
		//booksFile.write((const char*)&newdescription, desSize);
		//booksFile.write((const char*)&newrating, sizeof(newrating));
		//size_t ISBNSize = strlen(newISBN);
		//booksFile.write((const char*)&newISBN, ISBNSize);
		//booksFile.write((const char*)&newISBN, sizeof(newISBN));
		delete[] newtext;
		delete[] newauthor;
		delete[] newdescription;
		delete[] newISBN;
		delete[] newtitle;
		delete[] newtextFile;
		booksFile.close();
	}
	void deleteBook()
	{
		cin.get();
		cout << "type the title of the book you wan to delete: ";
		char* delTitle = new char[100];
		cin.getline(delTitle, 100);
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (delTitle == books[i].getTitle())
			{
				for (int j = i; j < numberOfBooks-1; j++)
				{
					books[i] = books[i + 1];
				}
				books[numberOfBooks].free();
				numberOfBooks--;
			}
		}
	}
	void showBook()
	{
		cout << "Enter title of book:"<<endl;
		cin.get();
		char* showTitle=new char[100];
		cin.getline(showTitle, 100);
		cout << "r-show book by rows"<<endl<<"s-show book by sentences"<<endl<<"rows or sentences:";
		char command;
		cin >> command;
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (showTitle == books[i].getTitle())
			{
				ifstream file(books[i].getText());
				if (command == 'r')
				{
					int numberOfRows;
					cin >> numberOfRows;
					for (int j = 0; j < numberOfRows; j++)
					{
						char* row=new char[10000];
						file.get(row, strlen(row));
					}
				}

				if (command == 's')
				{
						char nextSentence;
						while (!file.eof())
						{
							char character = '0';
							while (character != '?' && character != '.' && character != '!')
							{
								file >> character;
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
			}
		}
		delete[] showTitle;
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
			char* searchAuthor=new char[100];
			cin.get(searchAuthor, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchAuthor, books[i].getAuthor())==0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getDescription();
				}
			}
		}
		if (command == 't')
		{
			cin.get();
			char* searchTitle=new char[100];
			cin.get(searchTitle, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchTitle, books[i].getTitle()) == 0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getDescription();
				}
			}
		}
		if (command == 'i')
		{
			cin.get();
			char* searchISBN=new char[100];
			cin.get(searchISBN, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchISBN, books[i].getISBN()) == 0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getDescription();
				}
			}
		}
		if (command == 'd')
		{
			cin.get();
			char* searchDescription=new char[100];
			cin.get(searchDescription, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strstr(books[i].getDescription(), searchDescription))
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getDescription();
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
				deleteBook();
			}
			else if (command == 'a')
			{
				addBook();
			}
			else if (command == 'i')
			{
				getInfo();
			}
			else if (command == 'f')
			{
				showBook();
			}
		}
	}
};

int main()
{
	Library l;
	l.start();

	return 0;
}

