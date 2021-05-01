/*Create a C++ project. Download and add the attached .h and .cpp to the project. 
Write an implementation file to implement the namespace declared in the attached CSCI361Proj5.h. 
Name the implementation file as YourNameProj5.cpp and add it to the project.  
Run the project to see your grade.

Author: "Name Goes Here!"
Version: 3/18/2021
*/


#include "CSCI361Proj5.h"

namespace FHSULINKEDLIST
{
	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: The value returned is the number of nodes in the linked
	* list. The list itself is unaltered.
	*/
	size_t list_length(const Node* head_ptr)
	{
		// initialize count to 0
		size_t count = 0;
		// loop over the list pointed by head_ptr
		while (head_ptr != NULL)
		{
			count++;
			head_ptr = head_ptr->link;
		}

		return count;
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: A new node containing the given entry has been added at
	* the head of the linked list; head_ptr now points to the head of the new,
	* longer linked list.
	*/
	void list_head_insert(Node*& head_ptr, const Node::Item& entry)
	{
		// create a new Node with entry as data
		Node* node = new Node;
		node->data = entry;
		node->link = head_ptr; // set link of node to head_ptr
		head_ptr = node; // update head_ptr to node
	}

	/*
	* Precondition: previous_ptr points to a node in a linked list.
	* Postcondition: A new node containing the given entry has been added
	* after the node that previous_ptr points to.
	*/
	void list_insert(Node* previous_ptr, const Node::Item& entry)
	{
		// create a new Node with entry as data
		Node* node = new Node;
		node->data = entry;
		node->link = previous_ptr->link; // set link of node to link of previous ptr
		previous_ptr->link = node; // update link of previous ptr
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: The pointer returned points to the first node containing
	* the specified target in its data member. If there is no such node, the
	* null pointer is returned. The list itself is unaltered.
	*/
	Node* list_search(Node* head_ptr, const Node::Item& target)
	{
		Node* curr = head_ptr; // set curr to head_ptr
		// loop over the list
		while (curr != NULL)
		{
			if (curr->data == target) // target found, exit the loop
				break;
			curr = curr->link;
		}

		return curr; // return the curr node
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list, and
	* position > 0.
	* Postcondition: The pointer returned points to the node at the specified
	* position in the list. (The head node is position 1, the next node is
	* position 2, and so on). If there is no such position, then the null
	* pointer is returned. The list itself is unaltered.
	*/
	Node* list_locate(Node* head_ptr, size_t position)
	{
		Node* curr = head_ptr; // set curr to head_ptr
		size_t curr_pos = 1; // set curr_pos to 1
		// loop over the list till the end of list
		while (curr != NULL && curr_pos < position)
		{
			curr_pos++;
			curr = curr->link;
		}

		return curr; // return the curr node
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list, with at
	* least one node.
	* Postcondition: The head node has been removed and returned to the heap;
	* head_ptr is now the head pointer of the new, shorter linked list.
	*/
	void list_head_remove(Node*& head_ptr)
	{
		Node* node = head_ptr; // set node to head_ptr
		head_ptr = head_ptr->link; // update head_ptr to node next to head_ptr
		// delete the node
		node->link = NULL;
		delete node;
		node = NULL;
	}

	/*
	* Precondition: previous_ptr points to a node in a linked list, and this
	* is not the tail node of the list.
	* Postcondition: The node after previous_ptr has been removed from the
	* linked list.
	*/
	void list_remove(Node* previous_ptr)
	{
		// set node to node after previous_node
		Node* node = previous_ptr->link;
		previous_ptr->link = node->link; // update previous_ptr link to node after node
		// delete node
		node->link = NULL;
		delete node;
		node = NULL;
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: All nodes of the list have been returned to the heap,
	* and the head_ptr is now NULL.
	*/
	void list_clear(Node*& head_ptr)
	{
		// loop over the list pointed by head_ptr deleting head_ptr until empty
		while (head_ptr != NULL)
		{
			list_head_remove(head_ptr);
		}
	}

	/*
	* Precondition: source_ptr is the head pointer of a linked list.
	* Postcondition: head_ptr is the head pointer for
	* a new list that contains the same items as the list pointed to by
	*/
	void list_copy(Node* source_ptr, Node*& head_ptr)
	{
		list_clear(head_ptr); // delete the current list pointed by head_ptr

		// set curr_src to head of source_ptr
		Node* curr_src = source_ptr;
		// set curr_head to head_ptr
		Node* curr_head = head_ptr;

		// loop over source_ptr list
		while (curr_src != NULL)
		{
			if (curr_head == NULL) // head_ptr is empty, insert curr_src's data at head_ptr_
			{
				list_head_insert(head_ptr, curr_src->data);
				curr_head = head_ptr; // set curr_head to head_ptr
			}
			else // head_ptr is not empty
			{
				list_insert(curr_head, curr_src->data);// insert curr_src's data after curr_head
				curr_head = curr_head->link; // set curr_head to newly inserted node
			}

			curr_src = curr_src->link; // move curr_src to next node in source_ptr
		}
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: The return value is the count of the number of times
	* target appears as the data portion of a node on the linked list.
	* The linked list itself is unchanged.
	*/
	size_t list_occurrences(Node* head_ptr, const Node::Item& target)
	{
		size_t count = 0; // set count to 0
		Node* curr = head_ptr; // set curr to head_ptr
		// loop over the list, counting the number of times target is found
		while (curr != NULL)
		{
			if (curr->data == target)
				count++;
			curr = curr->link;
		}

		return count;
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list.
	* Postcondition: A new node containing the given entry has been added at
	* the tail of the linked list; if this happens to be the first node of
	* the linked list, then head_ptr now points to this node (otherwise
	* head_ptr is unchanged).
	*/
	void list_tail_attach(Node*& head_ptr, const Node::Item& entry)
	{
		if (head_ptr == NULL) // empty list, insert entry at head
			list_head_insert(head_ptr, entry);
		else
		{
			// set curr to head_ptr
			Node* curr = head_ptr;
			// loop over the list to get the last node
			while (curr->link != NULL)
				curr = curr->link;

			// create a new node after the last node
			curr->link = new Node;
			curr->link->data = entry; // set its data to entry
			curr->link->link = NULL; // set its link to NULL
		}
	}

	/*
	* Precondition: head_ptr is the head pointer of a linked list, with at
	* least one node.
	* Postcondition: The tail node has been removed and returned to the heap;
	* if the list is now empty, then head_ptr is null; otherwise head_ptr
	* is unchanged.
	*/
	void list_tail_remove(Node*& head_ptr)
	{
		if (head_ptr->link == NULL) // list contains only 1 node, call function to remove head
			list_head_remove(head_ptr);
		else
		{
			// set curr to head_ptr and pre to node previous of curr
			Node* curr = head_ptr;
			Node* prev = NULL;
			// loop to get the last node in curr and second last node in prev
			while (curr->link != NULL)
			{
				prev = curr;
				curr = curr->link;
			}

			// set link of prev to NULL
			prev->link = NULL;
			// delete the curr node
			delete(curr);
			curr = NULL;
		}
	}

	/*
	* Precondition: source_ptr is the head pointer of a linked list
	* Postcondition: The value returned is the head pointer for
	* a new list that contains copies of the first n nodes from the list
	* that source_ptr points to. If there less than n nodes in source list,
	* just copy all nodes and done
	*/
	Node* list_copy_front(Node* source_ptr, size_t n)
	{
		Node* head_ptr = NULL; // set head_ptr to null
		// if number of nodes in source_ptr <= n, copy entire source_ptr list to head_ptr
		if (list_length(source_ptr) <= n)
		{
			list_copy(source_ptr, head_ptr);
		}
		else
		{
			size_t count = 0; // set count to 0
			Node* curr_src = source_ptr; // set curr_src to head of source_ptr
			Node* curr_head = head_ptr; // set curr_head to head_ptr

			// loop over the source_ptr inserting n nodes into head_ptr
			while (count < n)
			{
				count++; // increment count
				if (curr_head == NULL) // head_ptr is empty, set curr_src's data to head_ptr
				{
					list_head_insert(head_ptr, curr_src->data);
					curr_head = head_ptr;
				}
				else // non-empty head_ptr, insert curr_src's data after curr_head
				{
					list_insert(curr_head, curr_src->data);
					curr_head = curr_head->link; // set curr_head to the last node
				}

				curr_src = curr_src->link;
			}
		}

		return head_ptr;
	}
}
