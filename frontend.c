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

	if (strcmp(SetName, "<empty>") == 0) {
		printf("<empty>");
		return;
	}
	if (SetName[0] == '\0') {
		printf("<empty>");
		return;
	}
	printf("%s = ", SetName);

	if (ht == NULL) {
		printf("{}");
		return;
	}

	printf("{ ");
	bool isFirstElementPrinted = false;
	for (int i = 0; i < ht->size; i++) {
		//printf("[%d]: ", i);
		Node* head = ht->array[i];
		while (head != NULL) {
			//printf("-> ");
			if (isFirstElementPrinted) printf(", ");
			printShortData(head->value);  // Вывод текущих данных
			isFirstElementPrinted = true;
			head = head->next;
		}
	}
	printf("}");

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
void printNode(SetNode* node, bool ShowHashTable) {
	printf("[%d]  ", node->num+1);
	printSet(node->ht, node->name);
	printf("\n");
	if (ShowHashTable) printHashTable(node->ht);
}
void printList(ListOfSets* list) {
	printf("                                         List of sets\n\n\n");
	for (int i = 0; i < list->size; i++) {
		printNode(&(list->SetArray[i]), false);
	}

}


int MainMenuOptions() {
	printf("\n\n1-9 - choose set; ESC - exit; SPACE-Process two sets\n");
	return _getch();
}
void OptionPeekedMenu(int key, ListOfSets* list) {
	if (key == 27) {
		exit(0);
	}
	else if (48<=key && key<= 57) { // 1
		SetOptinsMunu(list, key - 49);
	}
	else if (key == 32) {
		SetOptinsMunu(list, 32);
	}
}

bool ProcessTwoSets(ListOfSets* list, int index1,int index2) {
	printf("Chosen sets:\n\n");
	index1 -= 48; //char to ascii
	index2 -= 48;
	printNode(&list->SetArray[index1 - 1], false);
	printNode(&list->SetArray[index2 - 1], false);
	pritnf("Enter operation: 1-merge, -...");
	int peeked = _getch();
	char NewName[64] = { '\0' };
	printf("Enter name of new set");
	scanf("%[^\n]%*c", NewName);
	if (peeked == 49) {
		HashTable* NewHashTable = MergeHashTables(list->SetArray[index1].ht, list->SetArray[index2].ht);
		//free first and second 
		// pointer to lower element = new ht 
		//TODO

	}

}
bool SetOptinsMunu(ListOfSets* list, int index) {
	if (index == 32) {
		system("cls");
		int Set1, Set2;
		printf("Select thirst set to further operation");
		Set1 = _getch() - 49;
		printf("Select second set to further operation");
		Set2 = _getch() - 49;
		if (!(48 <= Set1 && Set1 <= 57 && 48 <= Set2 && Set2 <= 57)) return false;
		
		if (ProcessTwoSets(list, Set1, Set2)) return true;
		else return false;
	}

	system("cls");
	//printf("[%d] - ", index);
	if (list->SetArray[index].ht == NULL) {
		list->SetArray[index].ht = CreateHashTable(32);
		printf("Set is empty. Please, enter name to new set: ");
		scanf("%[^\n]%*c", list->SetArray[index].name);
		printf("\nNew set successfully created!\n\n");

	}
	printNode(&list->SetArray[index], false);
	printf("\n\n1-Add new element\n2-Delete existing element");
	int peeked = _getch();
	if (peeked == 49) {
		


		if (InputNewElement(list->SetArray[index].ht)) {
			printf("Successfully added!\n\n");
			return true;
		}
		else {
			printf("Something went wrong with adding new element...");
			return false;
		}
	}
	else if (peeked == 50) {
		if (DeleteElement(list->SetArray[index].ht)) {
			printf("Successfully deleted!\n");
			return true;
		}
		else {
			printf("There is some error with deletion, probably element does not exist in set\n\n");
			return false;
		}
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
		data.type = INT_TYPE;
		printf("\nEnter value (integger): ");
		scanf("%d", &data.Int);
		InsertHashTable(ht, data);
	}
	else if (peeked == 50) {
		data.type = CHAR_TYPE;
		printf("\nEnter value (string): ");
		data.Char = (char*)malloc(64 * sizeof(char));
		scanf("%s", data.Char);
		InsertHashTable(ht, data);
	}
	else if (peeked == 51) {
		data.type = FLOAT_TYPE;
		printf("\nEnter value (float): ");
		scanf("%f", &data.Float);
		InsertHashTable(ht, data);
	} else return false;
	
	return true; //element successfully added
}

bool DeleteElement(HashTable* ht) {
	printf("Enter element for deletion\n1-INTEGGER\n2-STRING\n3-FLOAT\n\n");
	Data data;
	int peeked = _getch();
	if (peeked == 49) {
		data.type = INT_TYPE;
		printf("\nEnter value (integger): ");
		scanf("%d", &data.Int);
		removeElement(ht, data);
	}
	else if (peeked == 50) {
		data.type = CHAR_TYPE;
		printf("\nEnter value (string): ");
		data.Char = (char*)malloc(64 * sizeof(char));
		scanf("%s", data.Char);
		removeElement(ht, data);
	}
	else if (peeked == 51) {
		data.type = FLOAT_TYPE;
		printf("\nEnter value (float): ");
		scanf("%f", &data.Float);
		removeElement(ht, data);
	}
	else return false;

	return true; //element successfully added
}