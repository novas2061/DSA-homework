#include <iostream>
#include <map>
using namespace std;

class Student {
public:
    Student() : id(0), name(""), group("") {}

    Student(int id, string name, string group) {
        setID(id);
        setName(name);
        setGroup(group);
    }

    void setID(int id) {
        this->id = id;
    }

    void setName(string name) {
        if (name.length() <= 100) {
            this->name = name;
        } else {
            this->name = "";
        }
    }

    void setGroup(string group) {
        if (group.length() <= 30) {
            this->group = group;
        } else {
            this->group = "";
        }
    }

    int getID() {
        return id;
    }

    string getName() {
        return name;
    }

    string getGroup() {
        return group;
    }

private:
    int id;
    string name;
    string group;
};

class StudentManagement {
public:
    void Insert(int id, string name, string group) {
        studentList[id] = Student(id, name, group);
    }

    void Delete(int id) {
        if (studentList.find(id) != studentList.end()) {
            studentList.erase(id);
        }
    }

    string Infor(int id) {
        string ans;
        if (studentList.find(id) != studentList.end()) {
            ans = studentList[id].getName() + "," + studentList[id].getGroup();
        } else {
            ans = "NA,NA";
        }
        return ans;
    }

private:
    map<int, Student> studentList;
};

int main() {
    StudentManagement manager;
    int t;
    cin >> t;
    while(t--) {
        string operation;
        char c;
        while (cin >> c && c != '(') {
            operation += c;
        }

        string idString;
        while(cin >> c && c != ',' && c != ')') {
                idString += c;
        }

        int id = stoi(idString);

        if (operation == "Insert") {
            string name, group;

            while(cin >> c && c != ',') {
                name += c;
            }
            cin.ignore();
            while(cin >> c && c != ')') {
                group += c;
            }
            manager.Insert(id, name, group);
            
        } else if (operation == "Delete") {
            manager.Delete(id);
        } else {
            cout << manager.Infor(id);
        }
    }
    return 0;
}
