/*
Hamza Chaudhry, Niloofar Oliaei
Dr. Mohammad Kuhail
November 13, 2016
Project 2B Open Project
*/

#include "User.h"


template<class K, class T>
void User::compare(map <K, T> simUser_map,  std::map <int, User> User_map, int numUsers)
{
	for ( int i = 0; i < ISBN_vector.size(); i++) {
		for (int x = 0; x < numUsers; x++) {
			if (User_map[x].findISBN(ISBN_vector[i],  ratings_map[ISBN_vector[i]])) {
				if (simUser_map.empty()) {
					User* tempUser = &User_map[x];
					simUser temp(tempUser);
					simUser_map[x] = temp;
				}
				else {
					if (simUser_map.find(x) == simUser_map.end()) {
						simUser temp(&User_map[x]);
						simUser_map[x] = temp;
					}
					else {
						simUser_map[x].increment();
					}
				}
			}
		}
	}
}
bool User::findISBN(long isbn, int rating) 
{
	if (ratings_map[isbn] == rating)
	{
		return true;
	}
	else
	{
		return false;

	}
}
bool User::findISBN(long isbn)
{
	if (ratings_map.find(isbn) != ratings_map.end())
	{
		return true;
	}
	else
	{
		return false;

	}
}
void User::addBook(long isbn, int rating) 
{
	ISBN_vector.push_back(isbn);
	ratings_map[isbn] = rating;
}
void User::setID(int ID) 
{
	IdentificationNumber = ID;
}
int User::getID() 
{
	return IdentificationNumber;
}
void User::setName(string n) 
{
	name = n;
}
string User::getName() 
{
	return name;
}
