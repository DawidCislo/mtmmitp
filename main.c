#include <LPC21xx.H>
#include <stdio.h>

typedef enum CompResult
{ DIFFERENT , EQUAL } CompResult;

void CopyString(char cSource[],char cDestination[])
{
	unsigned char ucCounter;
	for(ucCounter = 0 ; cSource[ucCounter] != '\0' ; ucCounter++)
	{
		cDestination[ucCounter] = cSource[ucCounter];
	}
	cDestination[ucCounter] = '\0';
}

void TestOf_CopyString (void)
{
	unsigned char ucCounter;
	char cTestSource[] = "Test 1";
	char cTestDestination[7];
	printf("CopyString\n\n");
	printf("Test 1 - Porownanie zawartosci wynikow\n");
	//Test 1 uruchomi funkcje, a po zakonczeniu sie jej wykonywania sprawdzi
	//po kolei kazdy bajt i wyswietli "Error" przy kazdym bledzie, jesli 
	//wszystko bedzie przekopiowane pomyslnie test wyswietli "OK"
	CopyString(cTestSource, cTestDestination);
	for(ucCounter = 0 ; ucCounter < 8 ; ucCounter++)
	{
		if (cTestDestination[ucCounter] != cTestSource[ucCounter])
		{
			printf("Error\n");
		}
	}
	printf("OK\n");
}

enum CompResult eCompareString(char cStr1[], char cStr2[])
{
	unsigned char ucCounter;
	for(ucCounter = 0 ; cStr1[ucCounter] != '\0' ; ucCounter++)
	{
		if(cStr1[ucCounter] != cStr2[ucCounter])
		{
			return DIFFERENT;
		}
	}
	return EQUAL;
}

void TestOf_eCompareString (void)
{
	char cTest1[] = "ABCDEFGH";
	char cTest2[] = "ACBHGFDE";
	printf("eCompareString\n\n");
	printf("Test 1 - Sprawdzenie dla takich samych lancuchow\n");
	//Test 2 uruchomi funkcje dla takich samych lancuchow i sprawdzi
	//czy zwroci ona EQUAL, jesli tak to wyswietli "OK" jesli nie to "Error"
	if (eCompareString(cTest1,cTest1) == EQUAL)
	{
		printf("OK\n");
	}
	else
	{
		printf("Error\n");
	}
	printf("Test 2 - Spwardzenie dla roznych lancuchow\n");
	//Test 2 uruchomi funkcje dla roznych lancuchow i sprawdzi czy
	//zwroci ona DIFFERENT, jesli tak to wysiwetli "OK" jesli nie to "Error"
	if (eCompareString(cTest1,cTest2) == DIFFERENT)
	{
		printf("OK\n");
	}
	else
	{
		printf("Error\n");
	}
}

void AppendString(char cSourceStr[], char cDestinationStr[])
{
	unsigned char ucEnd;
	for(ucEnd=0 ; cDestinationStr[ucEnd] != '\0' ; ucEnd++){}
	CopyString(cSourceStr, cDestinationStr+ucEnd);
}

void TestOf_AppendString (void)
{
	char cTestDestination[] = "Test";
	char cTestSource[] = " OK";
	char cTestOutput[] = "Test OK";
	printf("AppendString\n\n");
	printf("Test 1 - Sprawdzenie wyniku\n");
	//Test 1 uruchomi funkcje laczaca cTestSource do cTestDestination a nastepnie
	//za pomoca funkcji eCompareString porowna wynik do cTestOutput - poprawnego
	//wyniku, jesli beda takie same test wyswietli "OK", jesli nie to "Error"
	AppendString(cTestSource, cTestDestination);
	if (eCompareString(cTestDestination, cTestOutput) == EQUAL)
	{
		printf("OK\n");
	}
	else
	{
		printf("Error\n");
	}
}

void ReplaceCharactersInString(char cString[], char cOldChar, char cNewChar)
{
	unsigned char ucCounter;
	for(ucCounter = 0 ; cString[ucCounter] != '\0' ; ucCounter++)
	{
		if(cString[ucCounter] == cOldChar)
		{
			cString[ucCounter] = cNewChar;
		}
	}
}

void TestOf_ReplaceCharactersInString (void)
{
	char cTestInput[] = "ABCxEF";
	char cTestOutput[] = "ABCDEF";
	printf("ReplaceCharactersInString\n\n");
	printf("Test 1 - Sprawdzanie wyniku\n");
	//Test 1 uruchomi funkcje zamieniajaca 'x' na 'D' i za pomoca funkcji
	//eCompareString porowna z prawidlowym wynikiem.
	ReplaceCharactersInString(cTestInput, 'x', 'D');
	if (eCompareString(cTestInput, cTestOutput) == EQUAL)
	{
		printf("OK\n");
	}
	else
	{
		printf("Error\n");
	}
}

int main (void)
{
	printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH\n\n\n");
	TestOf_CopyString();
	TestOf_eCompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharactersInString();
}
