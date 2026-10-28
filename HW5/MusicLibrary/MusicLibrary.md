# 问题

*葛沐昊 2025010563*

---

1. `Playlist::getPlayCount()`函数中若不存在`title`，会将其插入且`operator[]`不支持const。应该为先检索是否存在，再返回值的逻辑。

---

2. `Playlist::generateRecommendations()`函数中，`songs.push_back()`会将`shared_ptr`对象解引用后放入`vector`，导致对象切片和信息丢失。应直接将`shared_ptr`对象放入`vector`中。

---

3. `Playlist::generateRecommendations()`函数中，`songs`会将自身元素放入`vector`，且可能导致迭代器全部失效，应单开新`vector`储存。

---

4. `Playlist::removeByArtist()`函数中删除`vector`中元素会导致外层循环迭代器失效。


---

5. `Playlist::importSong()`中同一裸指针构造两个`shared_ptr`，会导致双重释放。

---

6. `Playlist::transferSong()`函数执行后，再次访问`song`，执行`display()`，有空指针解引用的风险。