#pragma once

#include <iostream>

using namespace std;


typedef struct arraystacknodetype
{
	char data;
//	arraystacknodetype* link;
}stacknode;

typedef struct arraystacktype
{
	int maxelementcount;
	int currentelementcount;
	stacknode* element;
}stack;

stacknode* peekas(stack* pstack);
stacknode* popas(stack* pstack);
bool arraystackfull(stack* pstack);
bool pushas(stack* pstack, stacknode element);
stack* creatarraystack(int size);
void showarraydata(stack* pstak);