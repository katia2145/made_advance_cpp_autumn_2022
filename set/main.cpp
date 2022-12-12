#include "set_lib/lib.h"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    Set<int> t;
    Set<double> td = Set<double>({1.0, -1.0, 2.4});
    cout << "empty " << td.empty() << endl;
    cout << "empty " << t.empty() << endl;
    t.insert(20);
    cout << t.size() << endl;
    Set<int> t1;
    t1 = t;

    Set<int> dCopy(t);

    cout << "add 25" << endl;
    t.insert(25);
    cout << "add 15" << endl;
    t.insert(15);
    cout << "add 10" << endl;
    t.insert(10);
    cout << "add 30" << endl;
    t.insert(30);
    cout << "add 5" << endl;
    t.insert(5);
    cout << "add 35" << endl;
    t.insert(35);
    cout << "add 35" << endl;

    cout << t.size() << endl;
    cout << "empty " << t.empty() << endl;
    // t.insert(67);
    // t.insert(43);
    // t.insert(21);
    // t.insert(10);
    // t.insert(89);
    // t.insert(38);
    // t.insert(69);

    cout << "for" << endl;

    Set<int>::iterator it = t.begin();
    Set<int>::iterator it_end = t.end();

    Set<int>::iterator it_5 = t.find(5);
    std::cout << "find: " << *it_5 << "\n";

    Set<int>::iterator it_55 = t.lower_bound(4);
    std::cout << "lower_bound 4" << *it_55 << "\n";

    Set<int>::iterator it_10 = t.lower_bound(6);
    std::cout << "lower_bound 6" << *it_10 << "\n";

    std::cout << "First value: " << *it << "\n";
    std::cout << "Second value: " << *(++it) << "\n";
    std::cout << "Previous value: " << *(--it) << "\n";


    for (const auto& n : t)
        std::cout << "n " << n << endl;

    cout << "okokok\n";
    // t.display();
    // t.remove(5);
    // t.remove(35);
    // t.remove(65);
    // t.remove(89);
    // t.remove(43);
    // t.remove(88);
    // t.remove(20);
    // t.remove(38);
    // t.display();
}