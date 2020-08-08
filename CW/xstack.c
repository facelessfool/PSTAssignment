void stack_init (Stack* stack) {
	stack->top = NULL;
}

void stack_push (Stack* stack, char* str) {
	Node *node = new_node(str);
	node->next = stack->top;
	stack->top = node;
}

void stack_num_push (Stack* stack, double num) {
	Node *node = new_num_node(num);
	node->next = stack->top;
	stack->top = node;
}

Data* stack_pop (Stack* stack) {
	if (stack->top == NULL){
		return NULL;
	}

	Data *data = (stack->top)->data;
	
	Node *temp = stack->top;
	stack->top = (stack->top)->next;

	return data;
}

Data* stack_peek (Stack* stack) {
	if (stack->top == NULL){
		return NULL;
	}

	Data *data = (stack->top)->data;
	return data;
}

int stack_is_empty (Stack* stack) {
	return stack->top == NULL;
}

void stack_display(Stack* stack) {
	if (stack->top == NULL) {
		printf("\n[Stack is Empty]");
		return;
	}

	Node *temp = stack->top;
	printf("\n");
	while (temp != NULL) {
		print(temp->data);
		temp = temp->next;
		if (temp != NULL)
			printf(" => ");
	}
}