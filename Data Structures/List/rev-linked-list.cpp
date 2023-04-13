#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// reverse the linked list
ListNode* reverseList(ListNode* head) {

    if(head == NULL)
        return NULL;

    ListNode*curr1,*curr2;

    curr1 = head;
    curr2 = head->next;

    while(1)
    {
        if(curr2 == NULL)
        {
            head->next = NULL;
            return curr1;
        }
        ListNode*tmp = curr2->next;
        curr2->next = curr1;
        curr1 = curr2;
        curr2 = tmp;
    }


}
// reverse the portion of list between position left and right
ListNode* reverseBetween(ListNode* head, int left, int right)
{
        if(left == right)
            return head;
        ListNode*pp,*ll,*rr,*nn;
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode*curr = head;

        if(left == 1)
        {
            ListNode*curr1 = head;
            ListNode*curr2 = head->next;
            int p2 = 2;
            while(1)
            {
                ListNode*tmp = curr2->next;
                curr2->next = curr1;
                curr1 = curr2;
                curr2 = tmp;
                if(p2 == right)
                {
                    head->next = tmp;
                    return curr1;
                }
                p2++;
            }
        }

        int pos = 1;
        for(int i=0;i<(left-2);i++)
        {
            curr = curr->next;
        }
        pp = curr;
        ll = pp->next;
        int p2 = left+1;
        ListNode*curr1 = pp->next;
        ListNode*curr2 = curr1->next;
        while(1)
        {
            ListNode*tmp = curr2->next;
            curr2->next = curr1;
            curr1 = curr2;
            curr2 = tmp;
            if(p2 == right)
            {
                rr = curr1;
                nn = curr2;
                break;
            }
            p2++;
        }
        pp->next = rr;
        ll->next = nn;

        return head;


}
// delete all elements with value = val
ListNode* removeElements(ListNode* head, int val) {

        while( head!=NULL && head->val == val)
        {
            ListNode*tmp = head;
            head = head->next;
            delete tmp;
        }

        if(head == NULL)
            return head;

        ListNode*curr = head;

        while(curr != NULL)
        {
            int del = 0;
            if(curr->next!=NULL && curr->next->val == val)
            {
                ListNode*tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                del = 1;
            }
            if(!del)
                curr = curr->next;
        }

        return head;

}
// swap values of kth node from first and kth node from last
ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a,*b;
        if(head->next == NULL)
            return head;
        int n = 0;
        ListNode*curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        int pos = 1;
        curr = head;
        while(curr != NULL)
        {
            if(pos == k)
            {
                a = curr;
            }
            if(pos == n-k+1)
            {
                b = curr;
            }
            curr = curr->next;
            pos++;
        }

        swap(a->val,b->val);

        return head;

}

// return next greater node in Linked List using Stack
vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode*curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        vector<int>ans(n);
        stack<pair<int,int>>S;
        curr = head;
        int pos = 0;
        while(curr != NULL)
        {
            int v = curr->val;
            while(!S.empty() && v > S.top().first)
            {
                ans[S.top().second] = v;
                S.pop();
            }
            S.push(make_pair(v,pos));
            curr = curr->next;
            pos++;
        }

        return ans;
}
// delete the middle node
ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
        {
            return NULL;
        }
        if(head->next->next == NULL)
        {
            delete head->next;
            head->next = NULL;
            return head;
        }
        int n = 0;
        ListNode*cur;
        cur = head;
        while(cur != NULL)
        {
            n++;
            cur = cur->next;
        }
        int p = n/2;
        cur = head;
        int pos = 0;
        while(cur != NULL)
        {
            if(pos == (p-1))
            {
                ListNode*tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return head;
            }
            cur = cur->next;
            pos++;
        }
        return head;
}

// rotate list to right by k places
ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        int n = 0;
        ListNode*curr,*tail;
        curr = head;
        while(curr != NULL)
        {
            n++;
            if(curr->next == NULL)
            {
                tail = curr;
            }
            curr = curr->next;
        }

        k%=n;

        if(k==0)
        return head;

        int pos = 1;
        curr = head;
        while(curr != NULL)
        {
            if(pos == (n-k))
            {
                ListNode*tmp = curr->next;
                curr->next = NULL;
                tail->next = head;
                return tmp;
            }
            curr = curr->next;
            pos++;
        }
        return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = n;
        n = 0;
        ListNode*curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        m = n-m+1;

        if(m==1)
        {
            ListNode*tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        curr = head;
        int pos = 1;
        while(curr != NULL)
        {
            if(pos == (m-1))
            {
                ListNode*tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
                break;
            }
            curr = curr->next;
            pos++;
        }

        return head;

}

// delete duplicates from a sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        while(head->next!=NULL && head->val == head->next->val)
        {
            ListNode*tmp = head;
            head = head->next;
            delete tmp;
        }
        ListNode*prev;
        ListNode*curr = head;
        if(head==NULL || head->next == NULL)
            return head;
        prev = head;
        curr = head->next;
        while(curr != NULL)
        {
            if(curr->next!=NULL && curr->next->val == curr->val)
            {
                ListNode*tmp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete tmp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
}

ListNode*LLfromArray(vector<int>a)
{
    int n = a.size();
    if(n==0)
        return NULL;
    ListNode*h = new ListNode(a[0]);
    ListNode*prev = h;
    for(int i=1;i<n;i++)
    {
        ListNode*curr = new ListNode(a[i]);
        prev->next = curr;
        prev = curr;
    }
    prev->next = NULL;
    return h;
}

void printList(ListNode*head)
{
    ListNode*curr = head;
    cout<<"   ";
    while(curr != NULL)
    {
        cout<<curr->val<<"   ";
        curr = curr->next;
    }
    cout<<endl;
}

int main()
{
    vector<int>a;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"\nEnter the elements: \n\n";
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        a.push_back(p);
    }
    ListNode*L = LLfromArray(a);
    ListNode*rev = reverseList(L);
    cout<<"\nReversed Elements: \n\n";
    printList(rev);
}

/*

5
3 2 7 4 9

*/
