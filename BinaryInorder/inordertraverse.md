알고리즘 데이터구조연습 3회차
===========================

* ### **문제 출처 LeetCode: InorderTraverse (DFS,Binary Tree)**

    #### - ***Difficulty : Easy***
    * Visual Studio 에서도 sample answer을 체크할 수 있도록, main함수를 따로 만들어놓았다. 

    * 기억을 되살릴겸 파트별로 쉬운 문제부터 다시 풀고있는데, Inorder, Preorder, Postorder 정의를 다 까먹어서 정의만 다시공부하고 구현했다. 구현하는건 재귀를 사용했었던게 기억이나서 재귀를 이용하니 그리 어렵진 않았다.


    #### - ***FeedBack***
    ![1024px-Binary_tree svg](https://user-images.githubusercontent.com/75593825/126117483-a4598af7-58b3-4fdb-8690-f7ab792a93ea.png)

    
    
    
    
    
    Binary Tree Example
    
    
    출처:  https://en.wikipedia.org/wiki/Binary_tree
    
### **1. Inorder Traversal** : 왼쪽자식-> 부모 ->오른쪽자식

````
위 사진에서 Inorder순서대로 출력한다면, 
2->7->5->6->11->2->5->4->9 순서로 출력될것이다.
````
Inorder 순서대로 vector에 저장하는 간단한 재귀를 이용한 코드를 작성해본다면
    
    
````cpp
    void inorder(TreeNode*root, vector<int> & vec){
        if(root==nullptr) return;
        inorder(root->left, vec); 
        vec.push_back(root->val);
        inorder(root->right,vec);
        }
````


 ### **2. Postorder Traversal** :  왼쪽자식-> 오른쪽자식 -> 부모


````
위 사진에서 Postorder순서대로 출력한다면, 
2->5->11->6->7->4->9->5->2 순서로 출력될것이다.
````
Postorder 순서대로 vector에 저장하는 간단한 재귀를 이용한 코드를 작성해본다면
````cpp
void Postorder(TreeNode*root, vector<int> & vec){
    if(root==nullptr) return;
    Postorder(root->left, vec); 
    Postorder(root->right,vec);
    vec.push_back(root->val);
    }
  ````
### **3. Preorder Traversal**: 부모-> 왼쪽자식 -> 오른쪽 자식
````
위 사진에서 Preorder순서대로 출력한다면,       
2->7->2->6->5->11->5->9->4 순서로 출력될것이다.
````
Preorder 순서대로 vector에 저장하는 간단한 재귀를 이용한 코드를 작성해본다면
````cpp
    void Preorder(TreeNode*root, vector<int> & vec){
        if(root==nullptr) return;
        vec.push_back(root->val);
        Preorder(root->left, vec); 
        Preorder(root->right,vec);
        }
````
