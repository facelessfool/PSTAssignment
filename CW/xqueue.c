Node *rear = NULL;

void queue_push (char* str) {
	Node *node = new_node(str);
	node->next = rear;
	rear = node;
}

Data* queue_pop () {
	if (rear == NULL){
		return NULL;
	}

	Node *temp = rear;
	Node *prev_temp = NULL;
	while (temp->next != NULL) {
		prev_temp = temp;
		temp = temp->next;
	}

	if (prev_temp != NULL) {
		prev_temp->next = NULL;
	} else {
		rear = NULL;
	}

	return temp->data;
}

void queue_display () {
	if (rear == NULL) {
		printf("\n[Queue is Empty]");
		return;
	}

	Node *temp = rear;
	printf("\nRear => ");
	while (temp != NULL) {
		print(temp->data);
		temp = temp->next;
		if (temp != NULL)
			printf(", ");
	}
	printf(" <= Front\n");
}