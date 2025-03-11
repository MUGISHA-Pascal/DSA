#include <iostream>
using namespace std;
struct MemoryBlock{
    size_t size;
    bool isFree;
    MemoryBlock* next;
    MemoryBlock(size_t size) : size(size) ,isFree(true),next(nullptr){}
};
class MemoryAllocator{
    private:
         MemoryBlock* head;
    public:
    MemoryAllocator():head(nullptr){}
         void * allocate(size_t size){
            MemoryBlock* current= head;
            MemoryBlock*  prev = nullptr;
            while(current != nullptr){
                if(current->isFree  && current->size >= size){
                    current->isFree = false;
                    return (void*)(current + 1);
                }
                prev = current;
                current= current->next;
            }
            
         }
}
