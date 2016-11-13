/*
Hamza Chaudhry, Niloofar Oliaei
Dr. Mohammad Kuhail
November 13, 2016
Project 2B Open Project
*/
#pragma once
#include <map>
#include <vector>
#include <iostream>


using namespace std; 




class User 
{
private:
	int IdentificationNumber;
	string name;
public:
	User() 
	{
		IdentificationNumber = 0;
		name = "";
	};
	User(int ID, string names) { 
		IdentificationNumber = ID;
		name = names;
	};
	void addBook(long isbn, int rating);
	template<class K, class T>
	void compare(map <K, T> simUser_map , map <int, User> User_map, int numUsers);
	bool findISBN(long isbn, int rating);
	bool findISBN(long isbn);
	void setID(int ID);
	int getID();
	void setName(string n);
	string getName();
	vector<long> ISBN_vector;
	map <long, int> ratings_map;

};

class simUser {
private:
	
	int similarity = 1;
public:
	User* storedUser;
	simUser() { storedUser = new User; }
	simUser(User* users) {
		storedUser = users;
	};
	void increment() {
		similarity += 1;
	};
	int Getsimilarity() {
		return similarity;
	};
	vector<long> similarISBN;
};
