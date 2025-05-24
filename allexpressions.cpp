#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

// INFIX TO POSTFIX
string INFIX_POSTFIX(string s) {
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        } else if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

// INFIX TO PREFIX
string INFIX_PREFIX(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') s[i] = '(';
        else if (s[i] == '(') s[i] = ')';
    }
    string ans = INFIX_POSTFIX(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

// PREFIX TO INFIX
string PREFIX_INFIX(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

// POSTFIX TO INFIX
string POSTFIX_INFIX(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op2 + s[i] + op1 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

// PREFIX TO POSTFIX
string PREFIX_POSTFIX(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        }
    }
    return st.top();
}

// POSTFIX TO PREFIX
string POSTFIX_PREFIX(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = s[i] + op2 + op1;
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    int choice;
    string input;

    do {
        cout << "\nChoose the operation you want to perform:\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Prefix to Infix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Prefix to Postfix\n";
        cout << "6. Postfix to Prefix\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter the expression: ";
            cin >> input;
        }

        switch (choice) {
            case 1:
                cout << "Postfix: " << INFIX_POSTFIX(input) << endl;
                break;
            case 2:
                cout << "Prefix: " << INFIX_PREFIX(input) << endl;
                break;
            case 3:
                cout << "Infix: " << PREFIX_INFIX(input) << endl;
                break;
            case 4:
                cout << "Infix: " << POSTFIX_INFIX(input) << endl;
                break;
            case 5:
                cout << "Postfix: " << PREFIX_POSTFIX(input) << endl;
                break;
            case 6:
                cout << "Prefix: " << POSTFIX_PREFIX(input) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
