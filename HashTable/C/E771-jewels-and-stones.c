// time:  O(len(J) + len(S))
// space: O(1)

int numJewelsInStones(char* J, char* S) {
    int ht[52] = {0};
    int res = 0;
    for(int i = 0; J[i] != '\0'; i++)
        if(J[i] >= 'a' && J[i] <= 'z')
            ht[J[i] - 'a'] = 1;
        else ht[26 + J[i] - 'A'] = 1;

    for(int i = 0; S[i] != '\0'; i++)
        if(S[i] >= 'a' && S[i] <= 'z'){
            if(ht[S[i] - 'a'])
                res ++;
        }
        else if(ht[26 + S[i] - 'A'])
            res ++;

    return res;
}