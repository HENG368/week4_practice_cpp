#include <iosteam>
#include <string>
#include "stack.hpp"

int main() {
    stack st(4);
    string test = "({)})";
    st.insert(test);
    cout << st.isBalanced() << endl;
}
