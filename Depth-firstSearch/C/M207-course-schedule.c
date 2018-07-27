// time:  O(n^2)
// space: O(n^2)

bool dfs(int numCourses, int i, int j, int** oud, int* visited, int** noRing){
    if(visited[i])  return false;
    visited[i] = 1;
    
    for(; j < numCourses; j++){
        if(oud[i][j]){
            if((*noRing)[j])  continue;
            for(int k = 0; k < numCourses; k++){
                if(oud[j][k]){
                    if((*noRing)[k])  continue;
                    if(!dfs(numCourses, j, k, oud, visited, noRing))
                        return false;
                    break;
                }
            }
        }
    }
    (*noRing)[i] = 1;
    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes) {
    int* visited = (int*)malloc(numCourses * sizeof(int));
    int* noRing = (int*)malloc(numCourses * sizeof(int));
    int** oud = (int**)malloc(numCourses * sizeof(int*));
    
    memset(visited, 0, numCourses * sizeof(int));
    memset(noRing, 0, numCourses * sizeof(int));
    for(int i = 0; i < numCourses; i++){
        oud[i] = (int*)malloc(numCourses * sizeof(int));
        memset(oud[i], 0, numCourses * sizeof(int));
    }
    
    for(int i = 0; i < prerequisitesRowSize; i++){
        oud[prerequisites[i][1]][prerequisites[i][0]] = 1;
    }
    
    for(int i = 0; i < numCourses; i++){
        if(noRing[i])  continue;
        for(int j = 0; j < numCourses; j++){
            if(oud[i][j]){
                if(noRing[j])  continue;
                if(!dfs(numCourses, i, j, oud, visited, &noRing))
                    return false;
                break;
            }
        }
    }
    
    return true;
}

// faster solution
struct ListNode* addElement(struct ListNode* root, int val)
{
    struct ListNode* newNode, *lastNode;
    newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (root == NULL)
        return newNode;

    lastNode = root;
    while (lastNode->next)
        lastNode = lastNode->next;
    lastNode->next = newNode;
    return root;
}

int getListLength(struct ListNode* head)
{
    int length = 0;
    while (head)
    {
        head = head->next;
        length++;
    }
    return length;
}

bool isCylic(int course, int *visited, int *reStack, struct ListNode **lists)
{
    struct ListNode *current = lists[course];

    visited[course] = 1;
    reStack[course] = 1;

    while (current)
    {
        if (visited[current->val] == 0)
        {
            if (isCylic(current->val, visited, reStack, lists) == true)
                return true;
        }
        else if (reStack[current->val] == 1)
            return true;

        current = current->next;
    }

    reStack[course] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes) {
    int i;
    int *visited = calloc(numCourses, sizeof(int));
    int *reStack = calloc(numCourses, sizeof(int));
    struct ListNode **lists = calloc(numCourses, sizeof(struct ListNode*));

    // construct list

    for (i = 0; i < prerequisitesRowSize; i++)
        lists[prerequisites[i][0]] = addElement(lists[prerequisites[i][0]], prerequisites[i][1]);

    // traverse each un-visited nood to check if any loop exists
    for (i = 0; i < numCourses; i++)
    {
        if (lists[i] == NULL)
            continue;
        if (visited[i])
            continue;
        if (isCylic(i, visited, reStack, lists) == true)
            return false;
    }

    return true;
}
