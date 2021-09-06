#include "DoubleLinkedList.h"
#include <iostream>

Monster* CreateMonster(DoubleLinkedList& list, std::string name, int hp)
{
	// 새로만든 몬스터의 정보를 저장할 변수
	Monster* element = new Monster;
	element->name = name;
	element->hp = hp;
	element->pNext = element->pPrev = nullptr;

	if (list.pTail == nullptr)
	{
		list.pHead = list.pTail = element;
	}
	else
	{
		element->pPrev = list.pTail;
		list.pTail->pNext = element;
		list.pTail = element;
	}

	return element;
}

void PrintMonsters(const DoubleLinkedList& list)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->hp << std::endl;
		element = element->pNext;
	}
}

int GetCountMonsters(const DoubleLinkedList& list)
{
	Monster* element{ list.pHead };
	int count{};

	// Travers
	while (element != nullptr)
	{
		count++;
		element = element->pNext;
	}

	return count;
}

Monster* FindMonster(const DoubleLinkedList& list, std::string findName)
{
	Monster* element{ list.pHead };

	while (element != nullptr)
	{
		if (element->name == findName)
		{
			return element;
		}
		element = element->pNext;
	}

	return nullptr;
}

void DeleteAll(DoubleLinkedList& list)
{
	Monster* element{ list.pHead };
	Monster* next;

	while (element != nullptr)
	{
		next = element->pNext;
		delete element;

		element = next;
	}

	list.pHead = list.pTail = nullptr;
}

bool Delete(DoubleLinkedList& list, std::string name)
{
	Monster* element = FindMonster(list, name);

	if (element != nullptr)
	{
		// 1. pHead = pTail
		// 2. pHead = element
		// 3. pTail = element
		// 4. else

		if (element == list.pHead)
		{
			list.pHead = element->pNext;
			element->pNext->pPrev = nullptr;
		}
		else
		{

		}

		if (element == list.pTail)
		{
			list.pTail = element->pPrev;
			element->pPrev->pNext = nullptr;
		}
		else
		{
			element->pPrev->pNext = element->pNext;
			element->pNext->pPrev = element->pPrev;
		}

		// 기본 작업
		delete element;
		return true;
	}

	return false;
}
