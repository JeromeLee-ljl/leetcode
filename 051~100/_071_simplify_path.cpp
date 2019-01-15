// Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the
// canonical path. In a UNIX-style file system, a period . refers to the current directory.
// Furthermore, a double period .. moves the directory up a level. For more information, see:
// Absolute path vs relative path in Linux/Unix Note that the returned canonical path must always
// begin with a slash /, and there must be only a single slash / between two directory names. The
// last directory name (if it exists) must not end with a trailing /. Also, the canonical path must
// be the shortest string representing the absolute path.

// Example 1:
// Input: "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.

// Example 2:
// Input: "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the
// highest level you can go.

// Example 3:
// Input: "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

// Example 4:
// Input: "/a/./b/../../c/"
// Output: "/c"

// Example 5:
// Input: "/a/../../b/../c//.//"
// Output: "/c"

// Example 6:
// Input: "/a//b////c/d//././/.."
// Output: "/a/b/c"

#include "../include/tools.cpp"

char* simplifyPath1(char* path) {
    int len = strlen(path);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    res[0] = '/';
    int res_i = 1;
    for (int p_i = 1; p_i <= len; p_i++) {
        if (path[p_i] == '/') {
            if (res[res_i - 1] != '/') res[res_i++] = path[p_i];
            continue;
        }
        if (path[p_i] == '.' && (path[p_i + 1] == '/' || path[p_i + 1] == '\0')) continue;  //'.'
        if (path[p_i] == '.' && path[p_i + 1] == '.' &&
            (path[p_i + 2] == '/' || path[p_i + 2] == '\0')) {  //  '..'
            p_i++;
            if (res_i == 1) continue;
            res_i--;
            while (res_i > 1 && res[res_i - 1] != '/') res_i--;
            continue;
        }
        res[res_i++] = path[p_i];
        while (p_i < len && path[p_i + 1] != '/') {
            res[res_i++] = path[++p_i];
        }
    }
    if (res_i > 2 && res[res_i - 2] == '/') res[res_i - 2] = '\0';  // delete last '/'
    return res;
}

char* simplifyPath2(char* path) {
    // char* res = (char*)malloc(sizeof(char) * (strlen(path) + 1));
    // res[0] = '/';
    char* res = path;
    int res_i = 1;
    for (int p_i = 1; path[p_i - 1] != '\0'; p_i++) {
        if (res[res_i - 1] == '/') {
            if (path[p_i] == '/') continue;  //  '/////' -> '/'
            if (path[p_i] == '.') {
                if (path[p_i + 1] == '/' || path[p_i + 1] == '\0') continue;  //  '.'
                if ((path[p_i + 2] == '/' || path[p_i + 2] == '\0') &&
                    path[p_i + 1] == '.') {  //  '..'
                    p_i++;
                    if (res_i == 1) continue;
                    while (res[--res_i - 1] != '/') {
                    }
                    continue;
                }
            }
            if (path[p_i] == '\0' && res_i > 1) res_i--;  //  delete last '/'
        }
        res[res_i++] = path[p_i];
    }
    return res;
}

char* simplifyPath(char* path) {
    // char* res = (char*)malloc(sizeof(char) * (strlen(path) + 1));
    // res[0] = '/';
    char* res = path;
    for (int p_i = 1, r_i = 1; path[p_i - 1] != '\0'; p_i++) {
        if (res[r_i - 1] == '/') {
            if (path[p_i] == '/') continue;           //  skip extra '/'
            if (path[p_i] == '\0' && r_i > 1) r_i--;  //  delete last '/'
            if (path[p_i] == '.' && (path[p_i + 1] == '/' || path[p_i + 1] == '\0')) continue;  //  skip '.'
            if (path[p_i] == '.' && (path[p_i + 2] == '/' || path[p_i + 2] == '\0') && path[p_i + 1] == '.') {  //  '..'
                p_i++;
                if (r_i == 1) continue;
                while (res[--r_i - 1] != '/');
                continue;
            }
        }
        res[r_i++] = path[p_i];
    }
    return res;
}

int main(int argc, char const* argv[]) {
    char a[] = "/home/";
    char b[] = "/../";
    char c[] = "/home//foo/";
    char d[] = "/a/./b/../../c/";
    char e[] = "/a/../../b/../c//.//";
    char f[] = "/a//b////c/d//././/..";
    char g[] = "/...";
    printf("a:%s\n", simplifyPath(a));
    printf("b:%s\n", simplifyPath(b));
    printf("c:%s\n", simplifyPath(c));
    printf("d:%s\n", simplifyPath(d));
    printf("e:%s\n", simplifyPath(e));
    printf("f:%s\n", simplifyPath(f));
    printf("g:%s\n", simplifyPath(g));

    getchar();
    return 0;
}
