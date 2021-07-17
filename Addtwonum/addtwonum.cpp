#include <iostream>
#include <vector>
#include <map>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    } //will act as a constructor
    ListNode(int x) : val(x), next(nullptr) {}
    //will also act as a constructor
    ListNode(int x, ListNode *next) : val(x), next(next){};
    // will also act as a constructor.
};
class Solution
    {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            //l_sum for sum list
            ListNode * l_sum= new ListNode(0);
            ListNode *temp=l_sum;
            int sum=0;
            while(l1||l2)
            {
                //if one's calculation is over than, we do things with the other one
                sum/=10; //if sum is under 10 it will become 0 else 1.
                if(l1!=nullptr)
                    {
                        sum+=l1->val;
                        l1=l1->next;
                    }
                if(l2!=nullptr)
                {
                    sum+=l2->val;
                    l2=l2->next;

                }
                l_sum->next=new ListNode(sum%10);
                //if sum wa 19 then 9 will be added to the nextsum
                l_sum=l_sum->next;
            }
            if(sum/10==1)
                l_sum->next=new ListNode(1); //for last case
            return temp->next;
            
        }        
    };
    int main(void)
    {
        //for sample problm
        ListNode * l1= new ListNode(2);
        ListNode *temp= l1;
        temp->next=new ListNode(4);
        temp=temp->next;
        temp->next=new ListNode(3);
        ListNode * l2= new ListNode(5);
        ListNode *temp2= l2;
        temp2->next=new ListNode(6);
        temp2=temp2->next;
        temp2->next=new ListNode(4);

        Solution s;
        ListNode * ans=s.addTwoNumbers(l1,l2);
        while(ans!=nullptr)
        {
            cout<<ans->val<<endl;
            ans=ans->next;
        }

    }