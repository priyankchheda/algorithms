/**
 * Print all subsequences of a string
 *
 * Given a string s, print all possible subsequences of the given string in
 * an iterative manner.
 *
 * Input : abc
 * Output : a, b, c, ab, ac, bc, abc
 *
 * URL: https://www.geeksforgeeks.org/print-subsequences-string-iterative-
 *      method/
 */

#include <iostream>

int main()
{
    std::string s = "abc";
    int no_of_subsequence = (1 << s.size()) - 1;
    for (int i = 1; i <= no_of_subsequence; i++) {
        int temp = i;
        int j= 0;
        while (temp > 0) {
            if (temp & 1)
                std::cout << s[j];
            j++;
            temp = temp >> 1;
        }
        std::cout << " ";
    }
    std::cout << "\n";
    return 0;
}
