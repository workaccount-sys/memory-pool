#include <iostream>

struct FreeNode{
	FreeNode* next = nullptr;
};

FreeNode* deallocate(FreeNode*& head, FreeNode* returnedNode){
	returnedNode->next = head;
	head = returnedNode;
	return head;
}

FreeNode* allocate(FreeNode*& head)
{
	if(head != nullptr)
	{

		FreeNode* newHead = head;
		head = head->next;
		newHead->next = nullptr;
		return newHead;	
	}else{
		std::cout << "Freelist is empty" << '\n';
		return nullptr;
	}
}

int main() 
{
	FreeNode* head = nullptr;

	const int SIZE = 5;

	FreeNode arr[SIZE];

	head = arr;

	for(int i = 0; i < SIZE; i++){
		if(i != SIZE-1){
			arr[i].next = &arr[i+1];
		}else{
			arr[i].next = nullptr;
		}
	}

	for(int i = 0; i < SIZE; i++){
		std::cout << arr[i].next << '\n';
	}

	return 0;
}
