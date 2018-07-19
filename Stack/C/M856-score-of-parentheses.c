// time:  O(n)
// space: O(1)

int scoreOfParentheses(char* S){
	int layer = 0;
	int score = 0;
	for(int i = 0; S[i]!=0; i++){
		if(S[i] == '('){
			if(S[i+1] == ')')
				score += 1 << layer;
			layer ++;
		}
		else layer--;
	}
	return score;
}

// time:  O(n)
// space: O(n)

typedef struct{
	int stack_array[30];
	int top;
}Stack;
void Pop(Stack *s, int *n){
	s->top--;
	*n = s->stack_array[s->top];
}
void Push(Stack *s, int n){
	s->stack_array[s->top] = n;
	s->top++;
}
int scoreOfParentheses(char* S){
	Stack s;
	s.top = 0;
	int t1, t2;
	int score = 0;
	for(int i = 0; S[i]!=0; i++){
		if(S[i] == '(')
			Push(&s, 0);
		else{
			Pop(&s, &t1);
			if(t1){
				t1 *= 2;
				Pop(&s, &t2);
			}else{
				t1 = 1;
			}
			if(s.top != 0){
				Pop(&s, &t2);
				if(t2 == 0) Push(&s, t2);
			}else t2 = 0;
			Push(&s, t1 + t2);
		}
	}
	return s.stack_array[0];
}
