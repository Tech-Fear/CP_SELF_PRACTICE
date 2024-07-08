bool isPos(int barier,vector<int> &A,int B ){
    int n =  A.size();
    int currSt = 1, pges = 0;
    for(int i=0; i<n; i++){
        if(A[i] > barier) return false;
        if(A[i] + pges > barier){
            currSt++;
            pges = A[i];
            if(currSt > B){
                return false;
            }
        }
        else{
            pges += A[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
   
    int n = A.size();
    int sum = 0;
    for(int i=0; i<n ;i++){
        sum += A[i];
    }
    int l = A[0];
    int h = sum, ans=-1;
    if(B>n)return -1;
    while(l <= h){
        int mid = (l+h)>>1;
        if(isPos(mid, A, B)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
