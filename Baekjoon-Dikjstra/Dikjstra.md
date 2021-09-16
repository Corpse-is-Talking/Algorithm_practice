알고리즘 데이터구조연습 4회차
===========================

* ### **문제출처 :  백준: 최단경로 (Dikjstra)**
    #### - ***Difficulty: Easy***




* ### ***Feeback***
    **1. 주어지는 input data를 어떤식으로 처리할것인가에 대한생각.** 
    - 문제에서는 V(vertices) W(Weight)의 개수와, 시작노드, 그리고 노드와 노드사이의 거리(Weight에 관한 정보를 주었다) 이를 한번에 표현하기 위해서 작성한 코드를 보자
    ```cpp
    int v_num=0, e_num=0, start_node=0; //initialization before calculation
	cin >> v_num>>e_num >> start_node; //get input
	vector<vector<pair<int,int>>> vec(v_num+1); // create vector of each node holding information of distance to other node
	vector<int>distance(v_num+1,1000000); //initialized as infinity (or a big number)
	// get data
    ```` 

    - 역시 vector 을 이용해서 받은 데이터를 저장하였으며, 노드와 노드사이의 거리를 저장하기위해 pair<int,int>를 사용하였다.

    **2. 최대 or 최소의 값이 필요할때는 Priority-que를 생각**
    - 다익스트라 알고리즘에서는, 현재 노드 주변에 있는 노드들의 거리를 update 해주고 난뒤, que에 집어넣고, que에서 꺼낼때의 우선순위는 starting node 로부터의 거리가 짧은것을 우선순위로 꺼내게 된다.
    이때 활용할 수 있는 데이터구조가 priority_que<pair<int,int>> 이다.
    (pair<int,int>의 첫번째 element는 distance에 관한정보, 두번째 element는 node에관한 정보이다>)
    ##### 주의!!! 
    priority_que.top()은 que 에서의 maximum 값을 가져오기때문에, 만약 최소값을 가진 element 부터 pop 하고 싶다면, que에 push 할때 -를 붙혀서 push 하자!  
    #
    Code Example:

    ````cpp
    while(!que.empty()){

	int cur_dis=-que.top().first; //will be distance minus because its max heap but we want the  min dis
	int cur_node= que.top().second; //will get the current node 
	que.pop();
    
	for(int i=0; i<vec[cur_node].size(); i++)
	{
	int node=vec[cur_node][i].first;
	int dis=vec[cur_node][i].second;
	if(distance[node]<=distance[cur_node]+dis) //update.
		continue;
	else
		{
		distance[node]=distance[cur_node]+dis; //update if distance can be reduced via other route.
		}
		que.push(make_pair( -distance[node],node)); //push the updated note to the que.
	
	}		
	}
    ````
