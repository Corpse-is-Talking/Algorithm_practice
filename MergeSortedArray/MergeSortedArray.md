알고리즘 데이터구조연습 5회차
===========================

* ### **문제출처 :  LeetCode: MergeSortedArray (Sorting)**
     #### - ***Difficulty: Easy***

    * Visual Studio 에서도 sample answer을 확인할수 있도록, main함수를 만들어놓았다.


* ### ***Feeback***
1. 문제에서 주는 상황을 이용하자!!
문제에서는, 정렬된 2개의 vector num1 과 num2를 주었는데, num1의 배열 뒤쪽은 num2 배열 길이만큼 0이 추가되있었다. 이는 정렬을 뒤쪽부터 사용하라는 일종의 힌트를 준 것같다. 정렬을 앞쪽부터 하다가, 코드가 복잡해졌는데, 역순으로하니 코드가 훨씬 간결해졌다.
#
2. 간단한 MergeSort 복습
MergeSort는 주어진 배열을 반으로 자르고 자르고 잘라서 가장작은 단위에서 Sorting 한후에, 재귀적으로 가장 위까지 Sorting하는 algorithm이다. Sorting 속도는 O(nlogn)으로 빠른 편이지만, 메모리복잡도도 역시 O(nlog)이고, QuickSort 알고리즘이 메모리면에서도 더 효율적이고, 데이터가 적당히 섞였다는 가정하에 실험적으로 Quicksort가 Mergesort보다 빠르기 때문에, 대부분의 라이브러리에서는 Quicksort를 쓴다고 한다 .
#
* ### ***Example***
1.  6-5-4-3-2-1 인 배열을 merge sort로 정렬 해보면, 
1단계: 654/ 321로 나뉜다.
2단계: 65/4/32/1 로 나뉘게 된다.
3단계: -/-/4/-/1
4단계: 6/5/-/3/2/- ( 가장 낮은단계부터 Sorting이 시작된다.)
5단계: 5/6/-/2/3/- ->4/5/6/1/2/3->1/2/3/4/5/6(나눴던 역순서대로 재귀적으로 진행이 된다.)

2. 간단한 Code with C++
````cpp
vector<int> MergeSort(vector<int> & vec)
{
    if(vec.size()==1)
        return vec;
    
    for(int i=0; i<vec.size()/2; i++)
    {
        vec1.push_back(vec[i]);
    }
    for(int i=vec.size/2; i<vec.size(); i++)
    {
        vec2.push_back(vec2[i]);
    }
    vec1=MergeSort(vec1); ///Sort left
    vec2=MergeSort(vec2); //Sort right
    vector<int> merged;
    int i=0,j=0,index=0;//Sort total
    while(i<vec1.size() &&j<vec2.size());
    {
        if(vec1[i]>vec2[j])
            {
                merged[index]=vec2[j];
                j++;
            }
        else
            {
                merged[index]=vec1[i];
                i++;   
            }
        index++;
    }
    if(i<vec1.size())
        vector<int> merged[index]=vec1[i];
    if(j<vec2.size())
        vector<int> merged[index]=vec2[j];
    return merged;
}
void Merge()
{
    vector<int> tosort={6,5,4,3,2,1};
    merged=Mergesort(tosort);
}
````