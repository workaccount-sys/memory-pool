#include <iostream>
#include <cstddef>
#include <new>
#include <memory>

struct FreeNode{
	FreeNode* next = nullptr;
};

FreeNode* initialize(FreeNode* arr,int SIZE){

	FreeNode* head = &arr[0];

	for(int i = 0;i < SIZE; i++){
		if(i != SIZE-1){
			arr[i].next = &arr[i+1];
		}else{
			arr[i].next = nullptr;
		}
	}

	return head;
}

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

	constexpr std::size_t SIZE = 5;

	void* memory = ::operator new(sizeof(FreeNode) * SIZE);

	std::byte* raw = static_cast<std::byte*>(memory);

	for(std::size_t i = 0; i < SIZE; i++){
		std::byte* address = raw + sizeof(FreeNode) * i;
		FreeNode* node = new (address) FreeNode{};
		node->next = head;
		head = node;
	}

	FreeNode* lolkek = head;
	while(lolkek != nullptr){
		std::cout << "Old - " << lolkek << '\n';
		lolkek = lolkek->next;
	}

	auto kek = allocate(head);
	auto kek2 = allocate(head);
	
	deallocate(head, kek);
	
	lolkek = head;

	while(lolkek != nullptr){
		std::cout << "New - " << lolkek << '\n';
		lolkek = lolkek->next;
	}

	for(std::size_t i = 0; i < SIZE; i++){
		std::byte* address = raw + sizeof(FreeNode) * i;
		FreeNode* kek = reinterpret_cast<FreeNode*>(address);
		std::destroy_at(std::addressof(*kek));
	}

	::operator delete(memory);
	
	return 0;
}
