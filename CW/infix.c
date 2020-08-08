#include <math.h>
#define BUFSIZ 1000

#include "common.c"
#include "xqueue.c"
#include "xstack.c"

int precedence (char ch) {
    switch (ch) { 
        case '-':
            return 4;
        case '+':
            return 3;
        case '/':
            return 2;
        case '*':
            return 1;
        case '^':
            return 0;
    }
}

double calculate (Data* data1, Data* data2, Data* opr) {
    double ans = 0;
    switch (opr->str[0]) { 
        case '-':
            ans = data1->num - data2->num;
            break;
        case '+':
            ans = data1->num + data2->num;
            break;
        case '/':
            ans = data2->num / data2->num;
            break;
        case '*':
            ans = data1->num * data2->num;
            break;
        case '^':
            ans = pow(data1->num, data2->num);
    }

    free(data1);
    free(data2);
    free(opr);
    return ans;
}

double perform_arthametic_operation () {
    Data *data = queue_pop();
    Stack opr_stack, num_stack;

    stack_init(&num_stack);
    stack_init(&opr_stack);

    while (data != NULL) {
        if (data->flag == 1) {
            stack_num_push(&num_stack, data->num);
        } else {
            Data* opr_peek_data = stack_peek(&opr_stack);

            if (data->str[0] == ')') {
                Data* opr_data = stack_pop(&opr_stack);
                while (opr_data->str[0] != '(') {
                    double ans = calculate (stack_pop(&num_stack), stack_pop(&num_stack), opr_data);
                    stack_num_push(&num_stack, ans);
                    opr_data = stack_pop(&opr_stack);
                }
                free(opr_data);
            } else if (data->str[0] != '(' && opr_peek_data != NULL && precedence(data->str[0]) > precedence(opr_peek_data->str[0])) {
                double ans = calculate (stack_pop(&num_stack), stack_pop(&num_stack), stack_pop(&opr_stack));
                stack_num_push(&num_stack, ans);
                stack_push(&opr_stack, data->str);
                free(opr_peek_data);
            } else {
                stack_push(&opr_stack, data->str);
            }
        }

        free(data);
        data = queue_pop();
    }

    free(data);

    while (stack_is_empty(&opr_stack) == 0) {
        double ans = calculate (stack_pop(&num_stack), stack_pop(&num_stack), stack_pop(&opr_stack));
        stack_num_push(&num_stack, ans);
    }

    return (stack_pop(&num_stack))->num;
}

void parse_infix (char* infix) {
    int i = 0;
    char ch;
    int len = strlen(infix);

    for (i = 0; i < len; i++) {
        ch = infix[i];
        if (ch == '*' && infix[i+1] == '*') {
            ch = '^';
            i++;
        }
        queue_push(&ch);
    }
    
    queue_display();
}

int main () {
    char buf[BUFSIZ];

    fgets(buf, sizeof buf, stdin);
    sanitize_input(buf);
    parse_infix(buf);

    double ans = perform_arthametic_operation();
    printf("\nAnswer: %lf", ans);
}