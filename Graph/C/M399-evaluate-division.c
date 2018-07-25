/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char*** equations, int equationsRowSize, int equationsColSize, double* values, int valuesSize, char*** queries, int queriesRowSize, int queriesColSize, int* returnSize) {
    *returnSize = queriesRowSize;
    double *res = (double*)malloc(queriesRowSize * sizeof(double));
    
    char** vex = (char**)malloc(64 * sizeof(char*));
    double arc[64][64] = {0.0};
    int id[2] = {0};
    int f = 0;
    for(int i = 0; i < equationsRowSize; i++){
        for(int j = 0; j < 2; j++){
            int u;
            for(u = 0; u < f; u++)
                if(!strcmp(vex[u], equations[i][j])){
                    break;
                }
            if(u == f){
                vex[f] = equations[i][j];
                f++;
            }
            id[j] = u;
        }
        arc[id[0]][id[1]] = values[i];
        arc[id[1]][id[0]] = 1 / values[i];
    }
    
    for(int i = 0; i < queriesRowSize; i++){
        res[i] = -1.0;
        for(id[0] = 0; id[0] < f; id[0]++)
            if(!strcmp(vex[id[0]], queries[i][0]))
                break;
        for(id[1] = 0; id[1] < f; id[1]++)
            if(!strcmp(vex[id[1]], queries[i][1]))
                break;
        if(id[0] == f || id[1] == f)
            continue;
        if(!strcmp(queries[i][0], queries[i][1])){
            res[i] = 1.0;
            continue;
        }
        
        int arr[64] = {0};
        int usd[64] = {0};
        int j = 0;
        int k = 0;
        arr[k] = id[0];  k++;  usd[id[0]] = 1;
        for(;arc[id[0]][j] == 0.0; j++);
        do{
            if(usd[j] == 0){
                arr[k] = j;  k++;
                usd[j] = 1;
                if(j == id[1])  break;
                for(j = 0; arc[arr[k-1]][j] == 0.0; j++);
            }else{
                for(j++; j < 64 && arc[arr[k-1]][j] == 0.0; j++);
                if(j == 64){
                    k--;
                    for(j = 0; j != arr[k]; j++);
                }
            }
        }while(k != 0);
        for(int l = 0; l < k-1; l++)
            res[i] *= arc[arr[l]][arr[l+1]];
        if(k) res[i] *= -1.0;
    }
    
    return res;
}