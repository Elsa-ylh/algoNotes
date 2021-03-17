//选择排序
void selectSort(){
    for(int i = 0; i < n; i++){
        int k = i;
        for(int j = k; j < n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

//插入排序
void insertSort(){
    for(int i = 1; i < n; i++){
        int temp = A[i], j = i;
        while(j > 0 && temp < A[j - 1]){
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

//冒泡排序
void bubbleSort(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n - i - 1; j++){
            if(A[j] > A[j + 1]){
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
