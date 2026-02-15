#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"


static ListNode* cln(LstElement *e) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p) {
		p->element = *e;
		p->next = NULL;
	}
	return p;
}

ListNode* fpren(List* list, ListNode* next) {
	ListNode* p, *r;   //값저장안하니 말록필요없음
	p = list->head;
	r = NULL;    //head가 next일경우 대비
	while (p!=NULL && p!=next) { //구조체끼리는 대입연산만 가능. (+, == 불가)
		r = p;
		p = p->next;
	}
	if (p) {
		return r;
	}
	// p가 끝이어도(next를 못찾아도)r을 리턴해야함 (이거하지마_> return NULL;
	//왜냐. 그럼 head가 next인거랑 똑같은 결과라서.
}




List* LstCreate(void) {
	List* ls = (List*)malloc(sizeof(List));
	if (ls) {
		ls->head = ls->tail = NULL;
		return ls;
	}
	return NULL;
}

int LstEmpty(const List* list) {
	if (list && list->head == list->tail == NULL) //이것 자체를 return
		return 1;
	else
		return 0;
}

int LstPushFront(List* list, const LstElement* e) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (list && p) {
		p->element = *e;
		p->next = list->head->next;
		list->head = p;
		if (LstEmpty(list))
			list->tail = p;

		return 1;
	}
	return 0;
}

int LstPushBack(List* list, const LstElement* e) {
	if (list) {
		ListNode* p = cln(e);
		if (LstEmpty) {
			list->head = list->tail = p;
		}
		else {
			list->tail->next = p;//tail이 가리키고있던 꼬리노드의 link도 변경
			list->tail = p;
		}
		return 1;
	}
	return 0;
}

int LstGetEntry(List* list, int pos, LstElement* e) {
	ListNode* p; // = cln(e);  //값저장할거아님 = 할당받을 필요X
	p = list->head;              //= 그냥 ListNode* p=list->head
	int num = 0;
	if (pos >= 0)
		while (1) {
			if (num++ == pos) {
				*e = p->element;
				free(p);
				return 1;
			}
			if (p == list->tail && num != pos)
				free(p);
				return 0;

		}
}

int LstInsertBefore(List* list, ListNode* next, const LstElement* e) {
	ListNode* node = cln(e);
	if (list) {
		ListNode* p = list->head;
		while (p) {
			if (p == next) {
				LstPushFront(list, e);
				return 1;
			}
			else if (p->next == next) {
				node->next = p->next;
				p->next = node;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}
}


int LstInsertBefore(List* list, ListNode* next, const LstElement* e) {
	if (list && next && list->head) {
		ListNode* p;
		if (p) {
			p = fpren(list, next);
			if (p) {
				if (p != list->tail)
					return 0;
				return LstInsertAfter(list, p, e);
				/*위 한줄 대신 썼던 것
				if (p != list->tail) {
					if (r) {
						p->next = r;
						r->next = next;
						return 1;
					}
					return 0;
				}*/
			}
			else {
				return LstPushFront(list, e);
			}
		}
	}
	return 0;
}

int LstInsertAfter(List* list, ListNode* previous, const LstElement* e) {
	//ListNode* p = fpren(list, previous);
	//위의 애는 틀림. 왜냐면 이미 삽입에 필요한 노드(앞노드. previous)가 주어졌는데 또찾는셈이라. 심지어 앞의 앞노드임
	ListNode* r = cln(e), * p;
	//만약 아래서 실패시 낭비됨. if 성공시로 옮기면 굿

	if (list && previous) {
		//위는 리스트포인터가 할당되었는지만 확인할뿐, 리스트 내부에 previous가 존재하는지는 확인하지 않음
		p = list->head;
		while (p && p != previous) {
			p = p->next;
		}
		if (p) {
			if (r) {
				r->next = previous->next;
				previous->next = r;
				return 1;
			}
		}
	}
	return 0;
}


int LstInsert(List* list, int pos, const LstElement* e) {
	if (list && list->head &&pos!=0) {
		ListNode* p=list->head;
		int i = 0;
		while (i != pos && p) {
			p = p->next;
			i++;
		}
		if (i = pos) {
			LstInsertAfter(list, p, e);
			return 1;
		}
		else {
			return 0;
		}

	}
}

void LstPrint(List* list, PrintFunc print) {
	ListNode* p = list->head;
	while (p) {
		print(&(p->element));
		p = p->next;
	}
}

int LstDelete(List* list, ListNode* node) {
	if (list && node && list->head) {
		ListNode* p = fpren(list, node);
		if (p == NULL) {
			list->head = list->tail = 0;
			free(node);
			return 1;
		}
		else if (p == list->tail) {
			return 0;
		}
		if (p->next == list->tail) {
			list->tail = p;
		}

		p->next = node->next;
		free(node);
		return 1;
	}
	return 0;
}


void LstClear(List* list) {
	if (list && list->head) {
		ListNode* p;
		while (list->head) {
			p = list->head->next;
			free(list->head);
			list->head = p;
		}
	}
	//리스트 내부를 free하려면 노드 하나하나를 건너가며 free해줘야하는구나.
	//하긴 노드 하나하나는 개별적인 독립체고 연결만 된거니까
}

ListNode* LstFindNode(List* list, const LstElement* e, CompareFunc compare);
