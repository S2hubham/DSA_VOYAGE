#include <bits/stdc++.h> 
using namespace std;

//--------------CONTAINERS---------
/*void pairs()
{
    pair<int, int> p = {1, 3};
    pair<int, pair<int, int>> q = {1, {2, 9}};
    pair<int, int> arr[] = {{1, 2}, {2, 3}};
    cout << p.first << " " << p.second << endl;
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;
    cout << arr[1].second;
}*/

/*void vectors(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.emplace_back(2);
    //two simple ways of accessing vector elements
    cout<<v.at(0)<<endl;
    cout<<v[0]<<" "<<v[1]<<endl;

    vector<pair<int, int>> vec;
    vec.push_back({20, 21});
    vec.emplace_back(30, 40);
    cout<<vec[0].first<<" "<<vec[1].second<<endl;

    vector<int> a(5, 100);
    vector<int> b(a);
    vector<int> c(5); //puts zero value by default
    c.emplace_back(67);
    for(int i=0; i<6; i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    //accessing elements of vector using iterator
    vector<int>::iterator it = a.begin();
    it++;
    cout<<*it<<" "<<endl;
    //vector<int>::iterator it = a.end();
    //vector<int>::iterator it = a.rend();
    //vector<int>::iterator it = a.rbegin();

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    //or
    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    //erasing
    v.erase(v.begin()+1);
    v.erase(v.begin()+1, v.begin()+4);
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    //inserting
    vector<int> m(5, 2);          //{2,2,2,2,2}
    m.insert(m.begin(), 300);     //{300,2,2,2,2,2} //position, value
    m.insert(m.begin()+1, 2, 99); //{300,99,99,2,2,2,2,2} //position, number of insertion, value to be repeateed
    vector<int> copy(2, 59);      //{59,59}
    m.insert(m.begin(), copy.begin(), copy.end());  //{59,59,300,99,99,2,2,2,2,2}
    for(auto it : m){
        cout<<it<<" ";
    }
    cout<<endl;

    //size
    cout<<m.size()<<endl;

    m.pop_back(); //removes last element

    m.swap(v);  //swaps contents of two vectors

    m.clear();  //clears entire array

    cout<<m.empty();   //1(true)-if not empty else 0(flase)

    reverse(arr.begin() + (index + 1), arr.end());
}*/

/*void exp_list(){
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);

    for(auto it = ls.begin(); it != ls.end(); it++){
        cout<<*it<<" ";
    }
    //(begin, end, rend, rbegin, swap, size, insert, clear)functions are same as vectors
}*/

/*void e_deque(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();
    //(begin, end, rend, rbegin, swap, size, insert, clear)functions are same as vectors
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout<<*it<<" ";
    }
}*/

/*void _stack(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.emplace(4);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;

    stack<int> s1, s2;
    s1.swap(s2);
}*/

/*void que(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.emplace(4);
    q.back() += 5;
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    queue<int> s1, s2;
    s1.swap(s2);
}*/

/*void p_que(){
    //max-heap
    priority_queue<int> q;
    q.push(1);
    q.push(3);
    q.emplace(4);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    //size, swap, empty functions are same as queue

    //min-heap
    priority_queue<int, vector<int>, greater<int>()> pq;
    pq.push(1);
    pq.push(3);
    pq.emplace(4);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
}*/

/*void explainSet()
{
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1, 2}
    st.insert(2);  // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3);

    // {1, 2, 3, 4, 5}
    auto it = st.find(6);

    // {1, 4, 5}
    st.erase(5); // erases 5 // takes logarithmic time
    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);
}*/

/*void _MultiSet() {
    // Everything is same as set
    // only stores duplicate elements also
    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // (1, 1)
    ms.insert(1); // {1, 1, 1}
    ms.erase(1); // all 1's erased
    int cnt = ms.count(1);
    // only a single one erased
    ms.erase(ms.find(1));
    // ms.erase(ms.find(1), ms.find(1)+2);
    // rest all function same as set
}*/

/*void explainUSet()
{
    unordered_set<int> st;
    // lower_bound and upper_bound function does not works, rest all functions are same
    // as above, it does not stores in any particular order it has a better complexity than set in most cases, except some when collision happens
}*/

/*void explainMap()
{

    map<int, int> mpp;

    map<int, pair<int, int>> mpp;

    map<pair<int, int>, int> mpp;

    //storing
    mpp[1] = 2;
    mpp.emplace({3, 1});

    mpp.insert({2, 4});

    mpp[{2, 3}] = 10;

    //accessing
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout << *(it).second;

    auto it = mpp.find(5);

    // This is the syntax
    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
}*/

/*void explainMultimap() {
// everything same as map, only it can store multiple keys
// only mpp[key] cannot be used here

void explainUnorderedMap() {
// same as set and unordered_Set difference.

}*/

//------------------IMP ALGO--------
/*bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // if they are same
    if (p1.first > p2.first)
        return true;
    return false;
}*/

/*void algo()
{
    int n;
    // sort  (it cannot sort map)
    // syntax : sort(start_index, last_index + 1)
    vector<int> v;
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    v.push_back(399);
    v.push_back(3);

    // asc
    //  sort(v.begin(), v.end());
    //  sort(v.begin()+2, v.end());
    // desc
    sort(v.begin(), v.end(), greater<int>());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending
    sort(v.begin(), v.end()+n, comp);

    // {4,1}, {2, 1}, {1, 2}};

    
    int num = 7;
    int cnt = __builtin_popcount(num); // Returns the number of set bits in the binary representation of num
    cout << "Number of set bits in " << num << " is: " << cnt << endl;

    long long num_ll = 165786578687;
    int cnt_ll = __builtin_popcountll(num_ll); // Returns the number of set bits in the binary representation of num_ll
    cout << "Number of set bits in " << num_ll << " is: " << cnt_ll << endl;

    //always get sorted data for permutation to get all permutations
    string s = "123";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout<<endl;

    // int maxi/mini = *max_element(a, a + n);
    int maxi = *max_element(v.begin(), v.end());
    int mini = *min_element(v.begin(), v.end());
    cout<<maxi<<" "<<mini;
}*/

int main()
{
    // CONTAINERS
    //   vectors();
    //   exp_list();
    //   e_deque();
    //   _stack();
    //   que();
    //   p_que();
    //  _MultiSet();
    //  explainSet();
    //  explainUSet();
    //  explainMap();
    //  explainMultimap();
    //  explainUnorderedMap();

    // ALGO
    // algo();
}