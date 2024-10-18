#include "List.h"
#include <iostream>
#include <cassert>

int main()
{
    // 创建一个空列表
    List<int> lst;

    // 尝试在一个空列表上调用 front() 和 back()
    try {
        std::cout << "First element of empty list: " << lst.front() << std::endl;
        std::cout << "Last element of empty list: " << lst.back() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // 向列表中添加元素
    for (int i = 0; i < 10; ++i)
    {
        lst.push_back(i);
    }

    // 打印列表中的所有元素
    std::cout << "Elements after adding 10 elements:" << std::endl;
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // 删除列表的最后一个元素
    lst.pop_back();

    // 再次打印列表中的所有元素
    std::cout << "Elements after popping last element:" << std::endl;
    for (auto it : lst)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // 测试前置和后置自减
    auto it = lst.end();
    --it;
    std::cout << "Element before end: " << *it << std::endl;

    // 测试构造函数
    List<int> lst2 = {1, 2, 3, 4, 5};
    std::cout << "Initialized list:" << std::endl;
    for (auto &x : lst2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 测试移动构造
    List<int> lst3 = std::move(lst2);
    std::cout << "Moved list:" << std::endl;
    for (auto &x : lst3)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 测试移动赋值
    List<int> lst4 = {5, 6};
    lst4 = std::move(lst3);
    std::cout << "Moved assigned list:" << std::endl;
    for (auto &x : lst4)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    auto foundIt = lst.find(5);
    if (foundIt != lst.end())
    {
        // 计算距离
        int distance = 0;
        auto tmpIt = lst.begin();
        while (tmpIt != foundIt)
        {
            ++distance;
            ++tmpIt;
        }
        std::cout << "Found element 5 at index: " << distance << std::endl;
    }
    else
    {
        std::cout << "Element 5 not found." << std::endl;
    }
        
    auto notFoundIt = lst.find(-1);
    if (notFoundIt != lst.end())
    {
        // 计算距离
        int distance = 0;
        auto tmpIt = lst.begin();
        while (tmpIt != notFoundIt)
        {
            ++distance;
            ++tmpIt;
        }
        std::cout << "Found element -1 at index: " << distance << std::endl;
    }
    else
    {
        std::cout << "Element -1 not found." << std::endl;
    }

    // 尝试删除不存在的元素
    List<int>::iterator it1 = lst.find(15);
    if (it1 != lst.end()) {
        lst.erase(it);
    } else {
        std::cout << "Element 15 not found in the list." << std::endl;
    }

    // 使用已删除元素的迭代器
    List<int>::iterator it2 = lst.begin();
    ++it2;
    lst.erase(it2);
    try {
        std::cout << "Value at deleted iterator: " << *it2 << std::endl;
    } catch (...) {
        std::cout << "Accessing deleted iterator caused an error." << std::endl;
    }

    lst.erase(it);
    std::cout << "list after being erased:" << std::endl;
    for (auto &x : lst)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;

    return 0;
}
