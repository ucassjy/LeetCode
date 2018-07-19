// time:  O(n)
// space: O(n)

typedef struct{
	int stack_array[1000];
	int top;
}Stack;
void Pop(Stack *s, int *n){
	*n = s->stack_array[s->top];
	s->top--;
}
void Push(Stack *s, int n){
	s->stack_array[++s->top] = n;
}
int calPoints(char** ops, int opsSize){
	Stack s;
	s.top = 0;
	int score = 0;
	int t1, t2, t3;
	for(int i=0; i<opsSize; i++){
		if(ops[i][0] == 'C'){
			Pop(&s, &t1);
			score -= t1;
		}else if(ops[i][0] == 'D'){
			t1 = s.stack_array[s.top] * 2;
			Push(&s, t1);
			score += t1;
		}else if(ops[i][0] == '+'){
			Pop(&s, &t1);  Pop(&s, &t2);
			t3 = t1 + t2;
			Push(&s, t2); Push(&s, t1); Push(&s, t3);
			score += t3;
		}else{
			t1 = atoi(ops[i]);
			Push(&s, t1);
			score += t1;
		}
	}
	return score;
}
