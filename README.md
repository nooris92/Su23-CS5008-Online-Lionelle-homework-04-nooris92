# HW README

Name: Issa Noor

Github Account name: nooris91

Link to Assignment on Github: (copy and paste the link to your assignment repo here)

https://github.com/Su23-CS5008-Online-Lionelle/homework-04-nooris91.git

How many hours did it take you to complete this assignment (estimate)? 

3 to 4 days to understand the concepts

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  

No, I have done this on my own with the help of learning modules.

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  

Yes, I have seen things to clear some points on:

w3schools

GeeksforGeeks

stackoverflow

(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## Understanding Time Complexity

1. Using a markdown table and markdown/latex math, show the BigO for Arrays, Singly Linked Lists, Doubly Linked Lists (so total of 3). For the columns, you will look at the Worst Case Time Complexity for Access, Search/Find, Insertion, and Deletion. 

| Data Structure     | Access	| Search/Find	| Insertion	| Deletion |
| ------------------ | ------ | ----------- | --------- | -------- |
| Array              | O(1)	  | O(n)	      | O(n)	    | O(n)     |
| Singly Linked List | O(n)	  | O(n)	      | O(1)*	    | O(1)*    |
| Doubly Linked List | O(n)	  | O(n)	      | O(1)*	    | O(1)*    |

2. Usually for singly and doubly linked lists, we reference both the head and tail for speed considerations. What would be the cost if you only had your head referenced, and you wanted to push to the tail of either?  $O(?)$

If we only have the head referenced and you want to push to the tail of either a singly linked list or a doubly linked list, the time complexity would be O(n) as you only have access to the head node and you would need to traverse the complete list from the head to reach the tail.

3. Name an example where an array is better than a linked list, and an example where a linked list is better than an array. Make sure to reference the big O as part of your reasoning. 

Arrays allow constant-time access to elements based on their index, which takes O(1) time. This makes arrays more efficient than the linked lists when random access is needed. For example, if we need to access elements in some specific order, arrays would be a better choice than the linked lists.

On the other hand, the Linked lists have better time complexity for insertion and deletion operations as compared to the arrays. Insertion or deletion at the beginning of a linked list takes O(1) time, while the same operations in an array would require shifting all subsequent elements, ehich takes O(n) time complexity.

Note: Make sure look at your finished markdown in the browser hosted on github or via a markdown preview extension. To confirm the notation is showing up properly. Double check the resources section in the instructions if you need help with markdown tables. 
