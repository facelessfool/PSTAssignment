#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define is_digit(c) (c <= '9' && c >= '0')
#define to_digit(c) (c-'0')

// FLAG=0 <--- Data is string itself
// FLAG=1 <--- Data is converted to double
typedef struct {
	double num;
	char* str;
	int flag;
} Data;

typedef struct Node {
	Data *data;
	struct Node *next;
} Node;

typedef struct {
    Node* top;
} Stack;

Data* parse_data (char *str) {
	Data *data = (Data*) malloc(sizeof(Data));
	
	if (is_digit(str[0])) {
		data->num = to_digit(str[0]);
		data->flag = 1;
		return data;
	}

	data->str = (char*) malloc(sizeof(char));
	data->str[0] = str[0];
	data->str[1] = '\0';
	data->flag = 0;
	return data;
}

void sanitize_input (char* input) {
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }
}

// Create new node with appropriate data
Node* new_node (char* str) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = parse_data(str);
	node->next = NULL;
	return node;
}

Node* new_num_node (double num) {
	Node *node = (Node*) malloc(sizeof(Node));
	
    Data *data = (Data*) malloc(sizeof(Data));
    data->flag = 1;
    data->num = num;

    node->data = data;
	node->next = NULL;
	return node;
}

void print(Data *data) {
	if (data == NULL) return;
	if (data->flag)
		printf("%lf", data->num);
	else
		printf("%s", data->str);
}