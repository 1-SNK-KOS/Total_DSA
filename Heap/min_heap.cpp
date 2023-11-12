/*class minHeap {
public:
    int capacity, heapSize;
    int *heapArray;

    // Constructor to initialize the heap.
    minHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        heapArray = new int[capacity];
    }

    // Function to get the index of the parent node.
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Function to get the index of the left child node.
    int left(int i) {
        return (2 * i + 1);
    }

    // Function to get the index of the right child node.
    int right(int i) {
        return (2 * i + 2);
    }

    // Extract the minimum element from the heap.
    int extractMinElement() {
        if (heapSize <= 0) {
            // Indicate that the heap is empty.
            return -1;
        }
        if (heapSize == 1) {
            heapSize--;
            // Return the only element in the heap.
            return heapArray[0];
        }

        // Store the root element.
        int root = heapArray[0];

        heapSize--;
        heapArray[0] = heapArray[heapSize];
        heapArray[heapSize] = 0;

        // Restore the heap property.
        heapify(0);

        return root;
    }

    // Delete an element at a given index.
    void deleteElement(int ind)
    {
        if (ind < heapSize)
        {
            // Decrease the key to the minimum possible value.
            decreaseKeyElement(ind, INT_MIN);

            // Remove the element from the heap.
            extractMinElement();
        }
    }

    // Insert a new element into the heap.
    void insert(int val) {
        int ind = heapSize;
        heapSize++;
        heapArray[ind] = val;

        // Restore the heap property by swapping with parent if necessary.
        while (ind != 0 and heapArray[ind] < heapArray[parent(ind)]) {
            swap(heapArray[ind], heapArray[parent(ind)]);
            ind = parent(ind);
        }
    }

    // Delete an element at a given index by decreasing its key to INT_MIN.
    void deleteKey(int ind)
    {
        if (ind < heapSize)
        {
            // Decrease the key to the minimum possible value.
            decreaseKeyElement(ind, INT_MIN);

            // Remove the element from the heap.
            extractMinElement();
        }
    }

    // Decrease the value of an element at a given index.
    void decreaseKeyElement(int ind, int new_val)
    {
        // Update the element's value.
        heapArray[ind] = new_val;
        while (ind != 0 && heapArray[parent(ind)] > heapArray[ind])
        {
            // Swap with parent if violating heap property.
            swap(heapArray[ind], heapArray[parent(ind)]);
            ind = parent(ind);
        }
    }

    // Heapify the heap from a given index.
    void heapify(int ind)
    {
        int l = left(ind);
        int r = right(ind);
        int smallest = ind;

        // Find the index of the smallest element among current node, left child, and right child.
        if (l < heapSize and heapArray[l] < heapArray[smallest])
            smallest = l;
        if (r < heapSize and heapArray[r] < heapArray[smallest])
            smallest = r;

        // If the smallest element is not the current node, swap and recursively heapify.
        if (smallest != ind)
        {
            swap(heapArray[ind], heapArray[smallest]);
            heapify(smallest);
        }
    }
};
*/
/*
// My Code
class minHeap {
    vector<int>heap;
public:

    // Constructor for the class.

    minHeap(int size) {
        // Write your code here.
        // vector<int>heap(size);
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
    if(heap.size()==0)return -1;
    int ans = heap[0];
    int n = heap.size();
    
    heap[0] = heap[n-1];
    heap.pop_back();
    heapify(heap,n-1,0);

    return ans;
       
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind >= heap.size()) return ;
        int n = heap.size();
        heap[ind] = heap[n-1];
        heap.pop_back();
         
        if(heap.size() == 0) return;
        heapify(heap,heap.size(),ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        heap.push_back(val);

       int idx = heap.size()-1;
       
       while(idx>0){
        int parent = (idx-1)/2 ;

        if(heap[parent]>heap[idx]){
            swap(heap[parent],heap[idx]);
            idx = parent;
            }
            else{
                return;
            }
         }

    }

     void heapify(vector<int> &heap ,int size ,int i){
   int smallest = i;
   int left = i*2+1;
   int right = i*2+2;

   if(left<size && heap[smallest]>heap[left]){
    smallest = left;
   }
   if(right<size && heap[smallest]>heap[right]){
    smallest = right;
   }
  if(smallest!=i){
    swap(heap[smallest],heap[i]);
    heapify(heap,size,smallest);
  }
}

   
};
*/
