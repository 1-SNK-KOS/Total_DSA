 // Iterative solution
 /*
 if(heap.size()==0)return -1;
    // The top most element of heap is he largest.
    int ans=heap[0];

    // Removing the last element in heap and inserting it in top.
    heap[0]=heap.back();
    heap.pop_back();

    // Edge case.
    if(heap.size()==0)return ans;
    // Shifting the current element down till its correct position.
    int pos=0;
    while(true)
    {
        int left=pos*2+1;
        int right=pos*2+2;
        int leftvalue=0,rightvalue=0;

        // To avoid segementation fault.
        if(left<heap.size())leftvalue=heap[left];
        if(right<heap.size())rightvalue=heap[right];

        // Swapping it by the larger value.
        if(leftvalue<=heap[pos] && rightvalue<=heap[pos])
        {
            // As it is larger than both its children it is at its correct position.
            break;
        }
        else if(leftvalue>=rightvalue)
        {
            swap(heap[pos],heap[left]);
            pos=left;
        }
        else
        {
            swap(heap[pos],heap[right]);
            pos=right;            
        }
    }
    return ans;
*/

// Recursive Solution
/*
 void heapify(vector<int> &heap ,int size ,int i){
int largest = i;
int left = i*2+1;
int right = i*2+2;

if(left<size && heap[largest]<heap[left]){
    largest = left;
}
if(right<size && heap[largest]<heap[right]){
    largest = right;
}
if(largest!=i){
    swap(heap[largest],heap[i]);
    heapify(heap,size,largest);
}
}


int pop(vector<int> &heap)
{
    // Write you code here.
    if(heap.size()==0)return -1;
    int ans = heap[0];
    int n = heap.size();
    
    heap[0] = heap[n-1];
    heap.pop_back();
    heapify(heap,n-1,0);

    return ans;
}
*/