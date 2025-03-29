#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// 1. Basic Sorting Comparators
bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

// 2. Custom Object Comparators
struct Person {
    string name;
    int age;
};

bool byAge(const Person& a, const Person& b) {
    return a.age < b.age;
}

bool byName(const Person& a, const Person& b) {
    return a.name < b.name;
}

// 3. Multiple Criteria Comparators
struct Student {
    string name;
    int grade;
    int age;
};

bool complexCompare(const Student& a, const Student& b) {
    if(a.grade != b.grade) {
        return a.grade > b.grade;
    }
    return a.age < b.age;
}

// 4. NEW: Comparators for vector<pair<int, int>>
bool byFirst(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;  // Sort by first element ascending
}

bool bySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;  // Sort by second element ascending
}

bool bySum(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first + a.second) < (b.first + b.second);  // Sort by sum
}

bool complexPair(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first != b.first) {
        return a.first < b.first;  // Sort by first if different
    }
    return a.second > b.second;  // If first equal, sort second descending
}

int main() {
    // 1. Basic Sorting Demo
    vector<int> numbers = {5, 2, 8, 1, 9};
    cout << "1. Basic Sorting:" << endl;
    sort(numbers.begin(), numbers.end(), ascending);
    cout << "Ascending: ";
    for(int num : numbers) cout << num << " ";
    cout << endl;

    sort(numbers.begin(), numbers.end(), descending);
    cout << "Descending: ";
    for(int num : numbers) cout << num << " ";
    cout << endl << endl;

    // 2. Custom Object Demo
    vector<Person> people = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20}
    };
    cout << "2. Person Sorting:" << endl;
    sort(people.begin(), people.end(), byAge);
    cout << "By age:" << endl;
    for(const auto& p : people) cout << p.name << " " << p.age << endl;

    sort(people.begin(), people.end(), byName);
    cout << "By name:" << endl;
    for(const auto& p : people) cout << p.name << " " << p.age << endl;
    cout << endl;

    // 3. Multiple Criteria Demo
    vector<Student> students = {
        {"Alice", 85, 20},
        {"Bob", 90, 22},
        {"Charlie", 85, 19}
    };
    cout << "3. Student Sorting:" << endl;
    sort(students.begin(), students.end(), complexCompare);
    for(const auto& s : students) {
        cout << s.name << " Grade:" << s.grade << " Age:" << s.age << endl;
    }
    cout << endl;

    // 4. Pair Sorting Demo
    vector<pair<int, int>> pairs = {
        {2, 5},
        {1, 3},
        {2, 1},
        {1, 7}
    };
    cout << "4. Pair Sorting:" << endl;

    // Sort by first element
    sort(pairs.begin(), pairs.end(), byFirst);
    cout << "By first element:" << endl;
    for(const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;  // Output: (1,3) (1,7) (2,5) (2,1)

    // Sort by second element
    sort(pairs.begin(), pairs.end(), bySecond);
    cout << "By second element:" << endl;
    for(const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;  // Output: (2,1) (1,3) (2,5) (1,7)

    // Sort by sum
    sort(pairs.begin(), pairs.end(), bySum);
    cout << "By sum:" << endl;
    for(const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;  // Output: (1,3) (2,1) (2,5) (1,7)

    // Complex sorting (first asc, second desc)
    sort(pairs.begin(), pairs.end(), complexPair);
    cout << "Complex (first asc, second desc):" << endl;
    for(const auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;  // Output: (1,7) (1,3) (2,5) (2,1)

    // 5. Lambda Demo
    vector<int> numbers2 = {5, 2, 8, 1, 9};
    cout << "\n5. Lambda Sorting:" << endl;
    sort(numbers2.begin(), numbers2.end(), 
        [](int a, int b) {
            bool a_even = a % 2 == 0;
            bool b_even = b % 2 == 0;
            if(a_even != b_even) return a_even > b_even;
            return a < b;
        });
    cout << "Even first: ";
    for(int num : numbers2) cout << num << " ";
    cout << endl;

    return 0;
}