#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX 100
#define INCREMENT 10

typedef int ElemType;

typedef struct Sqlist {
	ElemType* list;
	int length;
	int listsize;
	int increamentsize;
}Sqlist;

void InitialList_Sq(Sqlist* l);
void DestroyList_Sq(Sqlist* l);
void ClearList_Sq(Sqlist* l);
int ListEmpty_Sq(Sqlist l);
int ListLength_Sq(Sqlist l);
void GetElem_Sq(Sqlist l, int i,ElemType* e);
int LocateElem_Sq(Sqlist l, ElemType e);
void PriorElem_Sq(Sqlist l,ElemType cur_e,ElemType* pre_e);
void NextElem_Sq(Sqlist l, ElemType cur_e, ElemType* next_e);
void ListInsert_Sq(Sqlist* l, int i, ElemType e);
void ListDelete_Sq(Sqlist* l, int i, ElemType* e);
void ListTraverse(Sqlist l);

void IncrementList_Sq(Sqlist* l) {
	ElemType* list = (ElemType*)malloc(sizeof(ElemType) * (l->listsize + l->increamentsize));
	memcpy(list, l->list, l->listsize);
	free(l->list);
	l->list = list;
	l->listsize += l->increamentsize;
}

int main() {
	//---------------------------------------
	int arr[] = { 4,5,8,7,9,5,1 };
	Sqlist l;
	InitialList_Sq(&l);
	memcpy(l.list, arr, 7*sizeof(int));
	l.length = 7;
	ListTraverse(l);
	return 0;
}

void InitialList_Sq(Sqlist* l) {
	l->list = (ElemType*)malloc(sizeof(ElemType) * MAX);
	l->length = 0;
	l->listsize = MAX;
	l->increamentsize = INCREMENT;
}

void DestroyList_Sq(Sqlist* l) {
	free(l);
}

void ClearList_Sq(Sqlist* l) {
	l->length = 0;
}

int ListEmpty_Sq(Sqlist l) {
	if (l.length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int ListLength_Sq(Sqlist l) {
	if (ListEmpty_Sq) {
		printf("EMPTY");
	}
	return l.length;
}

void GetElem_Sq(Sqlist l, int i, ElemType* e) {
	if (i < 1) {
		printf("INPUT ERROR!");
		return;
	}
	if (i > ListLength_Sq(l)) {
		printf("TOO BIG!");
		return;
	}
	*e = l.list[i - 1];
}

int LocateElem_Sq(Sqlist l, ElemType e) {
	for (int i = 0; i < l.length; i++) {
		if (l.list[i] == e) {
			return i + 1;
		}
		return 0;
	}
}
void PriorElem_Sq(Sqlist l, ElemType cur_e, ElemType* pre_e) {
	if (LocateElem_Sq(l,cur_e)>1) {
		*pre_e = l.list[LocateElem_Sq(l,cur_e) - 2];
	}
	else {
		printf("NO PRE");
	}
}
void NextElem_Sq(Sqlist l, ElemType cur_e, ElemType* next_e) {
	if (LocateElem_Sq(l,cur_e) < l.length) {
		*next_e = l.list[LocateElem_Sq(l,cur_e)];

	}
	else {
		printf("NO NEXT");
	}
}

void ListInsert_Sq(Sqlist* l, int i, ElemType e) {
	if (l->length == l->listsize) {
		IncrementList_Sq(l);
	}
	for (int j = l->length; j > i; j--) {
		l->list[j] = l->list[j - 1];
	}
	l->list[i] = e;
	l->length += 1;

}

void ListDelete_Sq(Sqlist* l, int i, ElemType* e) {
	if (ListEmpty_Sq) {
		printf("EMPTY");

		return;
	}
	*e = l->list[i - 1];
	for (int j = i - 1; j < l->length; j++) {
		l->list[j] = l->list[j + 1];
	}
	l->length--;

}
void ListTraverse(Sqlist l) {
	for (int i = 0; i < l.length; i++) {
		printf("%d  ", l.list[i]);
	}
}




















