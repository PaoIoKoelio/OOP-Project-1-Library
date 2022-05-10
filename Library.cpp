#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const char* PASS = "00000000";
class Book{
	char* author;
	char* title;
	char* text;
	char* synopsis;
	int rating;
	char* ISBN;
public:
	Book()
	{
		author = nullptr;
		title = nullptr;
		text = nullptr;
		synopsis = nullptr;
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
		synopsis = new char[strlen(other.synopsis) + 1];
		strcpy(synopsis, other.synopsis);
		rating = other.rating;
		ISBN = new char[strlen(other.ISBN) + 1];
		strcpy(ISBN, other.ISBN);
	}
	void free()
	{
		delete[] author;
		delete[] title;
		delete[] text;
		delete[] synopsis;
	}
	Book(const Book& other)
	{
		copyFrom(other);
	}
	Book(char* author, char* title, char* text, char* synopsis, int rating, char* ISBN)
	{
		setAuthor(author);
		setTitle(title);
		setText(text);
		setSynopsis(synopsis);
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
	char* getSynopsis() const
	{
		return synopsis;
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
	void setSynopsis(char* synopsis)
	{
		this->synopsis = new char[strlen(synopsis) + 1];
		strcpy(this->synopsis, synopsis);
	}
	Book& operator=(const Book& other)
	{
		free();
		copyFrom(other);
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
	bool checkPassword(char* password)
	{
		if (strcmp(password, PASS) == 0)
		{
			return 1;
		}
		return 0;
	}
	void setPassword()
	{
		cout << "Give password";
		char* userPass;
		cin.getline(userPass, 10);
		password = new char[strlen(password) + 1];
		strcpy(password, userPass);
		if (checkPassword(password))
		{
			setAccess(1);
		}
		setAccess(0);
	}
};
class Library{
	Book* books;
	int numberOfBooks;
	Library()
	{
		books = nullptr;
		numberOfBooks = 0;
	}
	Library(Book* books, int numberOfBooks)
	{
		
	}
public:
	void sortBooks()
	{
		char sortDir;
		char sortType;
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
		}
	}
	void addBook(User u)
	{
		if (u.getAccess())
		{
			char* author = new char[100];
			cin.getline(author, strlen(author));
			char* title = new char[100];
			cin.getline(title, strlen(title));
			char* synopsis = new char[100];
			cin.getline(synopsis, strlen(synopsis));
			char* textFile = new char[100];
			cin.getline(textFile, strlen(textFile));
			char* text = new char[100000000];
			cin.getline(text, strlen(text));
			ofstream file(textFile);
			file.put(*(text));
			int rating;
			cin >> rating;
			char* ISBN = new char[10];
			cin.getline(ISBN, strlen(ISBN));
			Book b(author, title, synopsis, textFile, rating, ISBN);
			numberOfBooks++;
			books[numberOfBooks - 1] = b;
			ofstream booksFile("books.dat", ios::binary, ios::app);
			booksFile.write((const char*)&author, sizeof(author));
			booksFile.write((const char*)&title, sizeof(title));
			booksFile.write((const char*)&textFile, sizeof(textFile));
			booksFile.write((const char*)&synopsis, sizeof(synopsis));
			booksFile.write((const char*)&rating, sizeof(rating));
			booksFile.write((const char*)&ISBN, sizeof(ISBN));
		}
		else{ cout << "No access"<<endl; }
	}
	void deleteBook()
	{
		char* delTitle;
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
		char* showTitle;
		cin.getline(showTitle, 100);
		char command;
		cin >> command;
		for (int i = 0; i < numberOfBooks; i++)
		{
			if (showTitle == books[i].getTitle())
			{
				if (command == 'r')
				{
					int numberOfRows;
					cin >> numberOfRows;
					ifstream file(books[i].getText());
					for (int j = 0; j < numberOfRows; j++)
					{
						char row[100];
						file.get(row, 100);
					}
				}

				if (command == 's')
				{
					ifstream file(books[i].getText());
					char sentence[100];
					file.get(sentence, 100, '.'||'?'||'!');
				}
			}
		}
	}
	void getInfo()
	{
		char command;
		cin >> command;
		if (command == 'a')
		{
			char* searchAuthor;
			cin.get(searchAuthor, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchAuthor, books[i].getAuthor())==0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getSynopsis();
				}
			}
		}
		if (command == 't')
		{
			char* searchTitle;
			cin.get(searchTitle, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchTitle, books[i].getTitle()) == 0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getSynopsis();
				}
			}
		}
		if (command == 'i')
		{
			char* searchISBN;
			cin.get(searchISBN, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strcmp(searchISBN, books[i].getISBN()) == 0)
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getSynopsis();
				}
			}
		}
		if (command == 's')
		{
			char* searchSynopsis;
			cin.get(searchSynopsis, 100);
			for (int i = 0; i < numberOfBooks; i++)
			{
				if (strstr(books[i].getSynopsis(), searchSynopsis))
				{
					cout << books[i].getAuthor();
					cout << books[i].getTitle();
					cout << books[i].getISBN();
					cout << books[i].getSynopsis();
				}
			}
		}
	}
	void start(User& u)
	{
		
		
	}
};

int main()
{

	return 0;
}

