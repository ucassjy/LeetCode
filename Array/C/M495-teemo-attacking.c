// time:  O(n)
// space: O(1)

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if(timeSeriesSize == 0)  return 0;
    
    int res = 0;
    int td = 0;
    for(int i = 1; i < timeSeriesSize; i++){
        td = timeSeries[i] - timeSeries[i-1];
        if(td >= duration)
            res += duration;
        else res += td;
    }
    res += duration;
    return res;
}