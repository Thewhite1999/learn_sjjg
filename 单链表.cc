#include <iostream>
#include <vector>
using namespace std;

class Node {
 public:
  int val = 0;
  Node* next = nullptr;
};

// 用来打印链表
void print_list(Node* p) {
  Node* n = p;  // 临时变量
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
bool list_check(Node* p, const std::vector<int>& vals) {
  Node* n = p;
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
Node* create_list(const std::vector<int>& vals) {
  if (vals.empty()) {
    return nullptr;
  } else {
    Node* head = new Node();
    head->val = vals[0];
    for (auto i = vals.begin() + 1, auto pre_node = head; i != vals.end();
         i++) {
      Node* cur_node = new Node();
      cur_node->val = *i;
      pre_node->next = cur_node;
      pre_node = cur_node;
    }
    return head;
  }
};

// 创建一个num个节点，节点值都为val的链表
Node* create_list(int num, int val) {
  Node* head = new Node();
  Node* pre_node = head;
  for (int i = 0; i < num; i++) {
    Node* cur_node = new Node();
    cur_node->val = val;
    pre_node->next = cur_node;
    pre_node = cur_node;
  }
  return remove_front(head);
};

// delete整个链表
void delete_list(Node* p) {
  while (p) {
    Node* p0 = p;
    p = p->next;
    delete p0;
  }
};

// 在p尾部添加一个val 为 val的节点, 如果p是空指针，返回空指针
Node* list_push_back(Node* p, int val) {
  if (!p) {
    return nullptr;
  }

  else {
    Node* p1 = p;
    while (p1->next != nullptr) {
      p1 = p1->next;
    }
    Node* p2 = new Node;
    p2->val = val;
    p1->next = p2;
    return p;
  }
};

// 在p头部添加一个val为val的节点，返回新的头部,如果p是空指针，返回空指针
Node* list_push_front(Node* p, int val) {
  if (!p) {
    return nullptr;
  }

  else {
    Node* head = new Node;
    head->next = p;
    head->val = val;
    return head;
  }
};

// 删除p最后一个节点（注意要delete掉），如果p是空指针，返回空指针
Node* remove_back(Node* p) {
  if (!p) {
    return nullptr;
  } else if (p->next == nullptr) {
    delete p;
    return nullptr;
  } else {
    Node* p1 = p;
    while (p1->next->next != nullptr) {
      p1 = p1->next;
    }
    Node* p2 = p1->next;
    p1->next = nullptr;
    delete p2;
    return p;
  }
};

// 删除p第一个节点（注意要delete掉），如果p是空指针，返回空指针
Node* remove_front(Node* p) {
  if (!p) {
    return nullptr;
  }

  else {
    Node* p1 = p;
    p = p->next;
    delete p1;
    return p;
  }
};

// 在链表中查找，是否有值为val的节点，没有返回false
// 如果p是空指针，返回false
bool find_list(Node* p, int val) {
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
bool find_and_remove_list(Node* p, int val) {
  bool is_find_val = false;
  Node* new_head = new Node();
  new_head->next = p;
  Node* pre = new_head;
  while (pre->next) {
    if (pre->next->val == val) {
      is_find_val = true;
      Node* p2 = pre->next;
      pre->next = pre->next->next;
      delete p2;
    } else {
      pre = pre->next;
    }
  }
  remove_front(new_head);
  return is_find_val;
};

int list_size(Node* p) {
  int size = 0;
  while (p) {
    p = p->next;
    size++;
  }
  return size;
}

void copy_list_to_vec(Node* p, std::vector<int>& vals) {
  while (p != nullptr) {
    vals.push_back(p->val);
    p = p->next;
  }
}

// 反转链表
// 如果p是空指针，返回nullptr
/*Node* reverse_list(Node* p) {
  std::vector<int> vals;
  copy_list_to_vec(p, vals);
  for (int i = vals.size() - 1, auto tmp = p; i >= 0; --i, tmp = tmp->next)
    tmp->val = vals[i];
  return p;
}*/

Node* reverse_list(Node* p) {
  if (p == nullptr || p->next == nullptr) {
    return p;
  }
  {
    Node* p1 = p;
    Node* p2 = p->next;
    while (p2 != nullptr) {
      Node* tmp = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = tmp;
    }
    p->next = nullptr;
    return p1;
  }
}

int main() {
  Node* p = create_list(5, 6);
  vector<int> v{1, 2, 3, 4, 5, 6, 7};
  p = create_list(v);
  cout << find_and_remove_list(p, 6) << endl;
}