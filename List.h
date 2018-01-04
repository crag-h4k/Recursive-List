#pragma once

#include <cstdlib>
#include "Node.h"

using namespace std;

namespace list_2
{
	class List
	{
		private:
			Node *head;

			void destroy(Node *n){
				if (n->next != nullptr){
					destroy(n->next);
				}
				delete n;
			}

			Node* add(Node *n, int d){
				if (n == nullptr){
					return new Node(d);
				}
				else {
					n->next= add(n->next, d);
				}
				return n;
			}

			void printNode(Node *n){
				cout << n->data << endl;
				if (n->next != nullptr){
					printNode(n->next);
				}
			}

			Node* insertNode(Node *n, int d){
				if (n == nullptr){
					return new Node(d);
				}
				else if (d > n->data){
					n->next= insertNode(n->next, d);
				}
				else {
					Node* temp = n;
					n = new Node(d);
					n->next = temp;
				}
				return n;
			}

			bool findNode(Node *n, int d){
				if (n->data == d){
					return true;
				}
				else if(n->next != nullptr){
					return findNode(n->next, d);
				}
				return false;
			}

			int getSize(Node *n, int i = 0){
				if (n != nullptr){
					++i;
					return getSize(n->next, i);
				}
				return i;
			}

		public:
			// postcondition: list is initialized
			List(){head= NULL;}
			// postcondition: all nodes are destroyed using recursion
			~List(){
				destroy(head);
			}

			// postcondition: add element d at the end of the list
			//                using recursion
			void addEnd(int d){
				head = add(head, d);
			}
			// postcondition: print the list ussing recursion
			void print(){
				if (head != nullptr)
				printNode(head);
			}
			// precondition: list is in sorted order
			//                 (don't use addEnd with this function)
			// postcondition: d is inserted into the list so the list maintains
			//                sorted order. using recursison.
			void insert(int d){
				head = insertNode(head, d);
			}
			// postcondition: if d is in the list then find returns true
			//                else find returns false
			bool find (int d){
				return findNode(head, d);
			}

			// postcondition: size is returned. Must be calculated using recursion.
			int size(){
				return getSize(head);
			}

	};
}
