Quick select algorithm:

Intention: select the pivot and set the lowest elements to the right of pivot and lowest to the right.

Procedure:

1. Go with quick sort approach - Quick select function
2. In the while(1) loop, 
	- call the partition function
	- if the index returned by the partition function is equal k-1, we are done. break the loop
	- if the index returned by the partition function is lower, then move towards the left - idx--.
	- if the index returned by the partition function is higher, then move towards right - idx++
3. While(1) loop is continued and partition function is called again with the updated low and high pointers
4. Return the kth element which is kth largest element
5. If the smallest is asked, then return size-ks

Partition function:
1. partition function includes 3 parameters - arr, low, high
2. set the pivot - first element as the pivot
3. initialize the left and right pointers as low +1 and high respectively
4. if the element to the left is higher than the pivot, increment left
5. if the element to the right is lower than the pivot, increment right
6. if the element to the left is lower and right is higher than pivot, swap the elements as we are sorting in decending order
7. step 4 to 6 would be done under while(left <= right)
8. Once the while loop is over, swap the lower element with right - generally, pivot is replaced with lower.
9. return the right index value which is the pivot index.