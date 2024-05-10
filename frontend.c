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

	printf("\n\n");
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
	printf("\nChosen sets:\n\n");
	printNode(&list->SetArray[index1], false);
	printNode(&list->SetArray[index2], false);
	printf("\nEnter operation: 1-Union, 2-Intersection, 3-Difference\n");
	int peeked = _getch();
	SetNode node;

	if (peeked == 49) {
		
		
		node = MergeTwoSets(&list->SetArray[index1], &list->SetArray[index2]);
		node.num = 0;
		sprintf(node.name, "\n\nUnioned set \"% s - % s\"", list->SetArray[index1].name, list->SetArray[index2].name);
		printNode(&node, false);
		freeHashTable(node.ht, node.ht->size);
	}
	else if (peeked == 50) { // Intersection

		node = IntersectTwoSets(&list->SetArray[index1], &list->SetArray[index2]);
		node.num = 0;
		sprintf(node.name, "\n\Intersected set \"% s - % s\"", list->SetArray[index1].name, list->SetArray[index2].name);
		printNode(&node, false);
	}
	_getch();
}
bool SetOptinsMunu(ListOfSets* list, int index) {
	if (index == 32) {
		//system("cls");
		int Set1, Set2;
		printf("Select thirst set to further operation  ");
		scanf("%d*c", &Set1);
		printf("Select second set to further operation  ");
		scanf("%d*c", &Set2);
		//printf("set1 = %d\nset2 = %d", Set1, Set2);
		//_getch();
		system("cls"); 
		if (!(1<=Set1 && Set1<=10 && 1 <= Set2 && Set2 <= 10)) return false;
		
		if (ProcessTwoSets(list, Set1-1, Set2-1)) return true;
		else return false;
	}

	system("cls");
	//printf("[%d] - ", index);
	if (list->SetArray[index].ht == NULL) {
		list->SetArray[index].ht = CreateHashTable(32);
		printf("Set is empty. Please, enter name to new set: ");
		//_getch();
		scanf("%[^\n]%*c", list->SetArray[index].name);
		printf("\nNew set successfully created!\n\n");

	}
	printNode(&list->SetArray[index], false);
	printf("\n\n1-Add new element\n2-Delete element\n3-Show hashtable");
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
			printf("Element is not contained in the set!\n\n");
			_getch();
			return false;
		}
	}
	else if (peeked == 51) {
		system("cls");
		printNode(&list->SetArray[index], true);
		printf("\n\nEnter any key to return to main menu..");
		_getch();
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
		scanf("%d%*c", &data.Int);
		InsertHashTable(ht, data);
	}
	else if (peeked == 50) {
		data.type = CHAR_TYPE;
		printf("\nEnter value (string): ");
		data.Char = (char*)malloc(64 * sizeof(char));
		scanf("%[^\n]%*c", data.Char);
		InsertHashTable(ht, data);
	}
	else if (peeked == 51) {
		data.type = FLOAT_TYPE;
		printf("\nEnter value (float): ");
		scanf("%f%*c", &data.Float);
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
		scanf("%d%*c", &data.Int);
		return removeElement(ht, data);
	}
	else if (peeked == 50) {
		data.type = CHAR_TYPE;
		printf("\nEnter value (string): ");
		data.Char = (char*)malloc(64 * sizeof(char));
		scanf("%[^\n]%*c", data.Char);
		return removeElement(ht, data);
	}
	else if (peeked == 51) {
		data.type = FLOAT_TYPE;
		printf("\nEnter value (float): ");
		scanf("%f%*c", &data.Float);
		return removeElement(ht, data);
	}
	else return false;

	return true; //element successfully deleted
}
SetNode MergeTwoSets(SetNode* Set1, SetNode* Set2) {
	SetNode ResultSet;
	ResultSet.ht = MergeHashTables(Set1->ht, Set2->ht);
	strcpy(ResultSet.name, Set1->name);
	
	return ResultSet;
	//freeSetNode(set1);
	//reeSetNode(set2);
	//return setnode;
}
SetNode IntersectTwoSets(SetNode* set1, SetNode* set2) {
	SetNode result;
	result.ht = IntersectHashTables(set1->ht, set2->ht);


	return result;
}