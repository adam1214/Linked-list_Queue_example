#include<stdio.h>
#include<stdlib.h>
struct node {
	char data[50];
	struct node* next;
};

struct node* Q_HEAD = NULL;
struct node* Q_TAIL = NULL;
int Q_NUM = 0;
char item[50] = { '\0' };

void Push(char d[],int len) {
	if (Q_HEAD == NULL) {
		Q_HEAD = (struct node*)malloc(sizeof(struct node));
		for (int i = 0; i < len; i++)
		{
			Q_HEAD->data[i] = d[i];
		}
		Q_HEAD->data[len] = '\0';
		Q_HEAD->next = NULL;
		Q_TAIL = Q_HEAD;
	}
	else {
		struct node* ptr = (struct node*)malloc(sizeof(struct node));
		for (int i = 0; i < len; i++)
		{
			ptr->data[i] = d[i];
		}
		ptr->data[len] = '\0';
		ptr->next = NULL;
		Q_TAIL->next = ptr;
		Q_TAIL = ptr;
	}
	Q_NUM++;
}

char* Pop(char* item) {
	struct node* ptr = Q_HEAD;
	for (int i = 0; i < 50; i++)
	{
		item[i] = ptr->data[i];
	}

	Q_HEAD = ptr->next;
	free(ptr);
	Q_NUM--;
	return item;
}

int isEmpty(void) {
	if (Q_NUM == 0) return 1;
	else return 0;
}

int main()
{
	Push("123",strlen("123"));
	Push("4567", strlen("4567"));
	struct node* ptr = Q_HEAD;
	for (; ptr != NULL; ptr = ptr->next)
	{
		printf("%s\n", ptr->data);
	}
	/*printf("%s\n", Pop(item));
	Push(item, strlen(item));
	printf("%s\n", Pop(item));
	printf("%s\n", Pop(item));*/
	system("pause");
	return 0;
}