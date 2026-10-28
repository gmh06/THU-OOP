# 问题

*葛沐昊 2025010563*

---

- （样例）正确性问题 1：AgentCompany::getCEO 函数返回的是 CEOAgent 类型对象，但返回值类型却是基类 Agent，在这一过程中发生了对象切片，会造成信息损失。

---

- 正确性问题：AgentCompany::resetCTO 函数执行后，默认赋值会浅拷贝指针，导致其成员变量 tech_plans 指针被覆盖后内存泄漏。另外函数结束后 new_cto 析构，对应指针变为悬空指针，在析构 cto 时有二次释放的风险。应当补写拷贝赋值运算符。

---

- 设计合理性：AgentCompany::ceo 与 AgentCompany::cto 均设为 public 对外暴露，不符合权限最小的原理。应改为 private 权限。

---

- 设计合理性：CEOAgent 与 CTOAgent 对 基类 Agent 的继承没有实质上的继承。应当将 Agent::work 设为虚函数并在派生类中分别重写覆盖。且应将成员变量 type_plans 与 plan_count，构造与析构函数，都在基类中实现，派生类仅需简单继承即可。