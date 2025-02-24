# Minheap
The given code implements a MinHeap data structure and includes various operations such as 
inserting an element, extracting the minimum element, and sorting an array using the MinHeap. 
The insert() function in Minheap is used to insert the elements into the heap. It first checks if 
the heap is already full by comparing the heap_size with the capacity. If the heap is full, it prints 
an error message and returns from the function.  
If the heap is not full, the new element is inserted at the end of the heap. The variable i is 
assigned the value of heap_size, which represents the index where the new element will be 
inserted. The value of the element is assigned to harr[i], which stores the new element in the 
heap array. Then, the heap_size is incremented to account for the newly added element. 
After inserting the element, the function fixes the min-heap property by comparing the new 
element with its parent. The loop continues as long as the current index i is not the root (index 
0) and the value at the parent index (harr[parent(i)]) is greater than the value at the current 
index (harr[i]). 
extractmin() function is used to extract the minimum elements from the heap. If the heap has 
more than one element, the minimum element is stored in the variable root (initially set to 
harr[0]). The last element in the heap (harr[heap_size - 1]) is moved to the root position 
(harr[0]) to replace the minimum element. After replacing the root element, heap_size is 
decremented by 1 to indicate that one element has been removed from the heap. The 
MinHeapify function is called with the root index (0) to restore the min heap property. This 
function rearranges the elements to ensure that the smallest element is at the root position
