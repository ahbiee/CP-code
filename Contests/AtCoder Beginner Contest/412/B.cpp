#include <iostream>
#include <string>
#include <cctype> // for islower()

int main() {
    std::string S, T;
    std::cin >> S >> T;

    // 1. 從 S 中提取所有小寫字母，組成一個新的字串 S_prime
    std::string S_prime = "";
    for (char c : S) {
        if (std::islower(c)) {
            S_prime += c;
        }
    }

    // 2. 判斷 T 是否為 S_prime 的子序列
    int t_ptr = 0; // 指向 T 的當前字元索引
    int s_ptr = 0; // 指向 S_prime 的當前字元索引

    while (t_ptr < T.length()) {
        if (S_prime.find(T.at(t_ptr))) {
            t_ptr++;
        } else {
            break;
        }
    }

    // 如果 t_ptr 最終到達了 T 的末尾，表示 T 是 S_prime 的子序列
    if (t_ptr == T.length()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
