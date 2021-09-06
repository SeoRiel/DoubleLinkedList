#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList myList;
	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 5);

	PrintMonsters(myList);

	Delete(myList, "Wolf");

	std::cout << GetCountMonsters(myList) << std::endl;
	DeleteAll(myList);
}