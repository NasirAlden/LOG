#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


void log(char message[100])
{
	time_t t;
	time(&t);
	struct tm* timeInfo;
	timeInfo = localtime(&t);
	char strTime[100];
	sprintf(strTime, "[%d/%d/%d-%d:%d] -", timeInfo->tm_year + 1900,
		timeInfo->tm_mon + 1, timeInfo->tm_mday,timeInfo->tm_hour,timeInfo->tm_min);

	FILE* f = fopen("firstLog.log", "a");

	strcat(strTime, message);
	printf("%s", strTime);
	while (fputs(strTime, f) != NULL)
	{

	}
	fclose(f);
}

void logError(char* message) {
	char str[100] = "Error!! - ";
	strcat(str, message);
	strcpy(message, str);
	log(message);
}

void logEvent(char message[100]) {
	char str[100] = "[Event] - ";
	strcat(str, message);
	strcpy(message, str);
	log(message);
}



int main()
{
	int num;
	printf("insert integer number please:");
	int input=scanf("%d", &num);

	FILE* f = fopen("firstLog.log", "a");
	char userNumStr[100];

	char msgToLog[100] = "Program start..\n";
	logEvent(msgToLog);

	strcpy(msgToLog, "User had inserted number..\n");
	logEvent(msgToLog);
	sprintf(userNumStr, "%d\n", num);
	log(userNumStr);
	int userNumInt = atoi(userNumStr);
	fclose(f);

	FILE* f2 = fopen("secondLog.log", "a");
	if (!f2)
	{
		strcpy(msgToLog, "Error opening the file (secondLog.log)!");
		logError(msgToLog);
	}
	else
	{
		strcpy(msgToLog, "The file (secondLog.log) opened succsesfully!\n");
		logEvent(msgToLog);
		char fromOneToNumStr[100] = "";
		for (int i = 1; i <= userNumInt; i++)
		{
			sprintf(fromOneToNumStr, "%s %d ", fromOneToNumStr, i);
		}
		strcat(fromOneToNumStr,"\n");
		sprintf(msgToLog,"%s",fromOneToNumStr);
		log(msgToLog);
		strcpy(msgToLog, "Writing to the second log file is Done !!\n");
		fputs(fromOneToNumStr, f2); 
		logEvent(msgToLog);

		fclose(f2);
	}
	strcpy(msgToLog, "Program end..\n\n\n");
	logEvent(msgToLog);

	return 0;
}