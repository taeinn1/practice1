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
	ListNode* p = cln(e);  //값저장할거아님 = 할당받을 필요X
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
