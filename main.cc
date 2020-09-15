#include <iostream>

#include "lru_cache.h"

void print(LRUCache<int, int>& lru) {
  auto curr = lru.First();
  for (size_t i = 0; i < lru.size(); ++i, curr = curr->next) {
    auto k = curr->key;
    auto v = curr->val;
    std::cout << "key: " << k << " val: " << v << std::endl;
  }
}

int main() {
  LRUCache<int, int> lru;
  lru.Put(1, 10);
  lru.Put(2, 20);
  lru.Put(3, 30);
  print(lru);

  auto ptr = lru.Get(2);
  std::cout << *ptr << std::endl;
  print(lru);

  ptr = lru.GetSilently(1);
  std::cout << *ptr << std::endl;
  print(lru);
  return 0;
}
