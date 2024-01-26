// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produces the 
// compilation listing

#include <cstdio>
#include <string>
#include <queue>

using namespace std;

#include "listing.h"

std::queue<std::string> lexicalErrorQueue, syntaticErrorQueue, semanticErrorQueue;


static int lineNumber;
static string error = "";
static int totalErrors = 0;
static int lexicalErrorCount = 0;
static int semanticErrorCount = 0;
static int syntaticErrorCount = 0;

static void displayErrors();

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine()
{
	printf("\r");
	displayErrors();
	
	if (totalErrors > 0)
	{
		printf("Total Errors: %d\n", totalErrors);
		printf("Lexical Errors: %d\n", lexicalErrorCount);
		printf("Semantic Errors: %d\n", semanticErrorCount);
		printf("Syntactic Errors: %d\n", syntaticErrorCount);
	}
	else
	{
		printf("Compiled Successfully\n");
	}
	return totalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message)
{
	string messages[] = { "Lexical Error, Invalid Character ", "",
		"Semantic Error, ", "Semantic Error, Duplicate ",
		"Semantic Error, Undeclared " };

	error = messages[errorCategory] + message;
	
	switch (errorCategory)
	{
		case LEXICAL:
		     lexicalErrorQueue.push(message[errorCategory] + message);
		     lexicalErrorCount++;
		     break;
		case SYNTAX:
		     syntaticErrorQueue.push(message[errorCategory] + message);
		     syntaticErrorCount++;
		     break;
		case GENERAL_SEMANTIC:
		     semanticErrorQueue.push(message[errorCategory] + message);
		     semanticErrorCount++;
		     break; 
		default:
		     break;   	
	} 
	totalErrors++;
}

void displayErrors()
{
	
	if (error != "")
		printf("%s\n", error.c_str());
	error = "";
	

}
