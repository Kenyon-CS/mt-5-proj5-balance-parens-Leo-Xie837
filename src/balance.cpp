#include "balance.hpp"
#include <string>

static bool is_balanced_rec(const std::string& s, int idx, int open) {
    // TODO: implement recursively.
    // - If open < 0 => false
    // - If idx == s.size() => open == 0
    // - If '(' => recurse open+1
    // - If ')' => recurse open-1
    // - else ignore
    if (open < 0) {
        return false;
    }
    if (idx == s.size()) {
        return open == 0;
    }

    char current_char = s[idx];
    int next_open = open; 
    if (current_char == '(') {
        next_open = open + 1;
    } else if (current_char == ')') {

        next_open = open - 1;
    }
    return is_balanced_rec(s, idx + 1, next_open);
}

bool is_balanced(const std::string& s) {
    return is_balanced_rec(s, 0, 0);
}
