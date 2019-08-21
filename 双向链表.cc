#include <iostream>
#include <vector>
using namespace std;

class Node_dou {
 public:
  int val = 0;
  Node_dou* next = nullptr;
  Node_dou* pre = nullptr;
};

void print_list(Node_dou* p) {
  Node_dou* n = p;  // 临时变量
  while (n) {
    cout << n->val;  // 不用打印换行符
    n = n->next;
    if (n != nullptr) {
      // 如果不是最后一个节点，那就打印一下箭头
      cout << " ==> ";
    }
  }
}

// 检查链表p的元素是否和vals里面的元素一一相等，注意链表大小不等也是不相等
// 这个函数可以用来当做后面函数的测试函数
bool list_check(Node_dou* p, const std::vector<int>& vals) {
  Node_dou* n = p;
  auto a = vals.begin();
  while (n != nullptr && a != vals.end()) {
    if (n->val != *a) {
      return false;
    } else {
      // step in
      n = n->next;
      a++;
    }
  }
  if (n == nullptr && a == vals.end()) {
    return true;
  } else {
    return false;
  }
}

// 使用vals 创建一个链表，如果vals为空，返回空指针nullptr
Node_dou* create_list(const std::vector<int>& vals) {
  if (vals.empty()) {
    return nullptr;
  } else {
    Node_dou* head = new Node_dou();
    head->val = vals[0];
    auto pre_node = head;
    for (auto i = vals.begin() + 1; i != vals.end(); i++) {
      Node_dou* cur_node = new Node_dou();
      cur_node->val = *i;
      pre_node->next = cur_node;
      cur_node->pre = pre_node;
      pre_node = cur_node;
    }
    return head;
  }
};

Node_dou* remove_front(Node_dou* p) {
  if (!p) {
    return nullptr;
  }

  else {
    Node_dou* p1 = p;
    p = p->next;
    delete p1;
    return p;
  }
};

Node_dou* remove_back(Node_dou* p) {
  if (!p) {
    return nullptr;
  } else if (p->next == nullptr) {
    delete p;
    return nullptr;
  } else {
    Node_dou* p1 = p;
    while (p1->next->next != nullptr) {
      p1 = p1->next;
    }
    Node_dou* p2 = p1->next;
    p1->next = nullptr;
    delete p2;
    return p;
  }
};

// 创建一个num个节点，节点值都为val的链表
Node_dou* create_list(int num, int val) {
  Node_dou* head = new Node_dou();
  Node_dou* pre_node = head;
  for (int i = 0; i < num; i++) {
    Node_dou* cur_node = new Node_dou();
    cur_node->val = val;
    pre_node->next = cur_node;
    cur_node->pre = pre_node;
    pre_node = cur_node;
  }
  return remove_front(head);
};

// delete整个链表
void delete_list(Node_dou* p) {
  while (p) {
    Node_dou* p0 = p;
    p = p->next;
    delete p0;
  }
};

// 在链表中查找，是否有值为val的节点，没有返回false
// 如果p是空指针，返回false
bool find_list(Node_dou* p, int val) {
  if (!p) {
    return false;
  }

  else {
    while (p) {
      if (p->val == val) {
        return true;
      }
      p = p->next;
    }
    return false;
  }
};

// 在链表中查找，是否有值为val的节点，如果有找到并删除它（自己画个图模拟一下，注意删除的时候要保证链表不能断开了），然后返回true，没有返回false
// 如果p是空指针，返回false
bool find_and_remove_list(Node_dou* p, int val) {
  bool is_find_val = false;
  Node_dou* new_head = new Node_dou();
  new_head->next = p;
  Node_dou* pre = new_head;
  while (pre->next) {
    if (pre->next->val == val) {
      is_find_val = true;
      Node_dou* p2 = pre->next;
      pre->next = pre->next->next;
      delete p2;
    } else {
      pre = pre->next;
    }
  }
  remove_front(new_head);
  return is_find_val;
};

int list_size(Node_dou* p) {
  int size = 0;
  while (p) {
    p = p->next;
    size++;
  }
  return size;
}

void copy_list_to_vec(Node_dou* p, std::vector<int>& vals) {
  while (p != nullptr) {
    vals.push_back(p->val);
    p = p->next;
  }
}

// 反转链表
// 如果p是空指针，返回nullptr
Node_dou* reverse_list(Node_dou* p) {
  if (p == nullptr || p->next == nullptr) {
    return p;
  }
  {
    while (p->next != nullptr) p = p->next;

    Node_dou* p0 = p;
    while (p) {
      Node_dou* tmp = p->pre;
      p->pre = p->next;
      p->next = tmp;
      p = p->next;
    }
    return p0;
  }
}

int main() {
  vector<int> v{1, 2};
  Node_dou* p = create_list(v);
  print_list(p);
  Node_dou* p1 = create_list(6, 5);
  print_list(p1);
  p = reverse_list(p);
  print_list(p);
}