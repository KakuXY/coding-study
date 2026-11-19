/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
 */


// @lcpr-template-start
using namespace std;
#include <bits/stdc++.h>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    using node = ListNode;
    node* dummy = new node();
    node* tail = dummy;
    auto cmp = [](node* a, node* b) { return a->val > b->val; };
    priority_queue<node*, vector<node*>, decltype(cmp)> pq(cmp);
    for (auto &list : lists) if (list) pq.push(list);
    while (!pq.empty()) {
      auto s = pq.top();
      pq.pop();
      tail->next = s;
      tail = tail->next;
      if (s->next) pq.push(s->next);
    }
    return dummy->next;
  }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

