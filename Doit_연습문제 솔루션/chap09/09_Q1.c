/* Q1 Purge 함수 작성 */

/*--- 비교 함수를 사용하여 같은 노드를 삭제 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y))
{
	Node *ptr = list->head;

	while (ptr != NULL) {
		Node *ptr2 = ptr;
		Node *pre = ptr;

		while (pre->next != NULL) {
			ptr2 = pre->next;
			if (!compare(&ptr->data, &ptr2->data)) {//ptr로 값비교함ptr2랑
				pre->next = ptr2->next;// 두개건너뛰어 버블수정
				free(ptr2);
			}
			else {
				pre = ptr2;// 버블 수정
			}
		}
		ptr = ptr->next;//ptr하나씩 옮겨가면서 비교
	}
	list->crnt = list->head;
}