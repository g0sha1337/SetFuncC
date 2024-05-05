#define _CRT_SECURE_NO_WARNINGS
#include "frontend.h"



void printData(Data data) {
	switch (data.type) {
	case INT_TYPE:
		printf("Int: %d", data.Int);
		break;
	case CHAR_TYPE:
		printf("Char: %s", data.Char);
		break;
	case FLOAT_TYPE:
		printf("Float: %f", data.Float);
		break;
	}
}
void printShortData(Data data) {
	switch (data.type) {
	case INT_TYPE:
		printf("%d ", data.Int);
		break;
	case CHAR_TYPE:
		printf("%s ", data.Char);
		break;
	case FLOAT_TYPE:
		printf("%f ", data.Float);
		break;
	}
}
void printHashTable(HashTable* table) {
	if (table == NULL) {
		//printf("HASHTABLE IS EMPTY!\n\n");
		return;
	}

	printf("HashTable\n\n");
	for (int i = 0; i < table->size; i++) {
		printf("[%d]: ", i);
		Node* head = table->array[i];
		while (head != NULL) {
			printf("-> ");
			printData(head->value);  // Вывод текущих данных
			head = head->next;
		}
		printf("\n");
		//printf("NULL\n");
	}
}

void printSet(HashTable* ht,char* SetName) {

	if (strcmp(SetName, "<empty>") == 0) return;
	printf("%s = ", SetName);

	if (ht == NULL) {
		printf("{}");
		return;
	}

	printf("{ ");

	for (int i = 0; i < ht->size; i++) {
		//printf("[%d]: ", i);
		Node* head = ht->array[i];
		while (head != NULL) {
			//printf("-> ");
			if (i != 0) printf(", ");
			printShortData(head->value);  // Вывод текущих данных
			head = head->next;
		}
	}
	printf("}\n\n");

}
void AskNameOfSet(char* str) {
	//char* name = (char*)malloc(64 * sizeof(char)); //TODO: add free to 
	//if (!name) {
	//	printf("Some error with allocating memory..");
	//	exit(-1);
	//}
	printf("Enter name of new set:  ");
	fscanf_s("%[^\n]%*c", str);
	

	//return name;
}
void printNode(SetNode* node) {
	printf("[%d]  ", node->num);
	printSet(node->ht, node->name);
	printf("\n");
	printHashTable(node->ht);
}
void printList(ListOfSets* list) {
	printf("                                         List of sets\n\n\n");
	for (int i = 0; i < list->size; i++) {
		printNode(&(list->SetArray[i]));
	}

}


int MainMenuOptions() {
	printf("\n\n1-9 - choose set; ESC - exit\n");
	return _getch();
}
void OptionPeekedMenu(int key, ListOfSets* list) {
	if (key == 27) {
		exit(0);
	}
	else if (key == 49) { // 1
		SetOptinsMunu(list, key - 49);
	}
}

bool SetOptinsMunu(ListOfSets* list, int index) {
	system("cls");
	printf("[%d] - ", index);
	printNode(&list->SetArray[index]);
	printf("\n\n1-Add new element\n2-Delete existing element\n");
	int peeked = _getch();
	if (peeked == 49) {
		//add element
	}
	else if (peeked == 50) {
		//delete element
	}
	else {
		printf("worng key peeked...");
		return false;
	}
	return true;
}


bool InputNewElement(HashTable* ht) {
	printf("Enter type of element that you wanna add\n1-INTEGGER\n2-STRING\n3-FLOAT\n\n");
	Data data;
	int peeked = _getch();
	if (peeked == 49) {
		data.type == INT_TYPE;
		printf("\nEnter value: ");
		scanf_s("%d", &data.Int);
		InsertHashTable(ht, data);
	}
	else if (peeked == 50) {
		data.type == CHAR_TYPE;
		//TODO
	}
	else if (peeked == 51) {
		data.type == FLOAT_TYPE;
		//TODO
	}
	else return false;
	return true;
}