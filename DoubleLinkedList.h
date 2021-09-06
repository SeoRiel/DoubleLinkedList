#pragma once
#include <string>

struct Monster
{
	std::string name;
	int hp{ 0 };

	Monster* pNext{ nullptr };
	Monster* pPrev{ nullptr };
};

struct DoubleLinkedList
{
	Monster* pHead{};
	Monster* pTail{};
};

// 함수의 선언
Monster* CreateMonster(DoubleLinkedList& list, std::string name, int hp);
void PrintMonsters(const DoubleLinkedList& list);
int GetCountMonsters(const DoubleLinkedList& list);
Monster* FindMonster(const DoubleLinkedList& list, std::string findName);
void DeleteAll(DoubleLinkedList& list);
bool Delete(DoubleLinkedList& list, std::string name);