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
	FreeNode node_a{};
	FreeNode node_b{};
	FreeNode node_c{};

	head = &node_a;
	node_a.next = &node_b;
	node_b.next = &node_c;

	//while(node_ptr != nullptr)
	//{
	//	std::cout << node_ptr << '\n';
	//	node_ptr = node_ptr->next;
	//}

	std::cout << allocate(head) << '\n';
	std::cout << allocate(head) << '\n';
	std::cout << allocate(head) << '\n';
	std::cout << allocate(head) << '\n';	

	return 0;
}
