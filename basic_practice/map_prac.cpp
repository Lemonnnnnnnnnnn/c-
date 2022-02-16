#include "iostream"
#include <vector>
#include <map>

using namespace std;

using Map_i_s = map<int, string>;

void remove(Map_i_s &m_map, int target)
{
    cout << endl
         << "元素删除" << endl;

    // if(m_map.erase(target)){
    //     cout << target << " was removed" << endl;
    // }else{
    //     cout << target << " was not found" << endl;
    // }
    auto iter = m_map.erase(begin(m_map) , --end(m_map));
    // cout << iter->second << endl;
}

void search(Map_i_s m_map, int target)
{
    cout << endl
         << "元素查找" << endl;
    Map_i_s ::iterator l_it = m_map.find(2);
    if (l_it != m_map.end())
    {
        cout << "Found , the value is " << l_it->second << endl;
    }
    else
    {
        cout << "Do not Found" << endl;
    }
}

void traversal(Map_i_s m_map)
{
    cout << endl
         << "反向迭代" << endl;
    Map_i_s ::reverse_iterator iter; // 生成反向迭代对象iter ， 当迭代器增加时，它们会向容器的开头移动
    /*
    rbegin() 返回一个反向迭代器，指向map的最后一个元素
    rend()返回一个反向迭代器，指向第一个元素之前的位置
    */
    for (iter = m_map.rbegin(); iter != m_map.rend(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << endl
         << "正向迭代" << endl;
    Map_i_s ::iterator it = m_map.begin();
    Map_i_s ::iterator itEnd = m_map.end();
    while (it != itEnd)
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

int main(int argc, char const *argv[])
{
    // Map_i_s mapPerson;
    // mapPerson.insert(pair<int, string>(1, "Jim"));
    // mapPerson[2] = "Helly";
    // mapPerson.insert(Map_i_s::value_type(3, "Beir"));
    Map_i_s mapPerson{{1, "Jim"}, {2, "Helly"}, {3, "Beir"}}; 

    // search(mapPerson, 2);
    //  remove(mapPerson, 2);
    traversal(mapPerson);

    return 0;
}
