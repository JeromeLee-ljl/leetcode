// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include "../include/tools.cpp"

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes,
                      int* returnSize) {
    *returnSize = 0;
    *columnSizes = (int*)malloc(sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        (*columnSizes)[i] = 0;
    }
    char*** groups = (char***)malloc(sizeof(char**) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        groups[i] = (char**)malloc(sizeof(char*) * strsSize);
    }
    char** target = (char**)malloc(sizeof(char*) * strsSize);

    int str_i, group_i;
    for (str_i = 0; str_i < strsSize; str_i++) {
        int length = strlen(strs[str_i]);
        char* copy = (char*)malloc(sizeof(char) * (length + 1));
        strcpy(copy, strs[str_i]);

        select_sort(copy, 0, length);
        for (group_i = 0; group_i < *returnSize; group_i++) {
            // if (compare_str(copy, target[group_i]) == 0) break;
            if (compare_str(copy, target[group_i]) == 0) break;
        }
        groups[group_i][(*columnSizes)[group_i]] = strs[str_i];
        (*columnSizes)[group_i]++;
        if (group_i == *returnSize) {  // new group
            target[group_i] = copy;
            (*returnSize)++;
        } else {
            free(copy);
        }
    }
    for (group_i = 0; group_i < *returnSize; group_i++) {
        free(target[group_i]);
    };
    free(target);
    return groups;
}
char*** groupAnagrams2(char** strs, int strsSize, int** columnSizes,
                       int* returnSize) {
    *returnSize = 0;
    *columnSizes = (int*)malloc(sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        (*columnSizes)[i] = 0;
    }
    char*** groups = (char***)malloc(sizeof(char**) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        groups[i] = (char**)malloc(sizeof(char*) * strsSize);
    }
    int** flags = (int**)malloc(sizeof(int*) * strsSize);

    int str_i, group_i, i;
    for (str_i = 0; str_i < strsSize; str_i++) {
        char* str = strs[str_i];
        int* flag = (int*)malloc(sizeof(int) * 26);
        for (i = 0; i < 26; i++) flag[i] = 0;
        int length = strlen(str);
        for (i = 0; i < length; i++) {
            flag[str[i] - 'a']++;
        }
        for (group_i = 0; group_i < *returnSize; group_i++) {
            for (i = 0; i < 26; i++) {
                if (flags[group_i][i] != flag[i])
                    break;  // str 与 groups[group_i] 不匹配，下一组
            }
            if (i == 26) break;  // str 与 groups[group_i] 匹配
        }
        groups[group_i][(*columnSizes)[group_i]] = str;
        (*columnSizes)[group_i]++;
        if (group_i == *returnSize) {  // new group
            flags[group_i] = flag;
            (*returnSize)++;
        }
    }
    free(flags);
    return groups;
}

// typedef struct {
//     int count;             // the number of different letters
//     int letter_count[26];  // the number of every letter
// } StrInfo;

// StrInfo* get_str_info(char str[]) {  // O(l)
//     StrInfo* info = (StrInfo*)malloc(sizeof(StrInfo));
//     info->count = 0;
//     for (int i = 0; i < 26; i++) {
//         info->letter_count[i] = 0;
//     }
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (info->letter_count[str[i] - 'a']++ == 0) info->count++;
//     }
//     return info;
// }

// int str_info_similar(StrInfo* info_a, StrInfo* info_b) {  // O(26)
//     if (info_a->count != info_b->count) return 0;
//     for (int i = 0; i < 26; i++) {
//         if (info_a->letter_count[i] != info_b->letter_count[i]) return 0;
//     }
//     return 1;
// }

// char*** groupAnagrams3(char** strs, int strsSize, int** columnSizes,
//                        int* returnSize) {
//     *returnSize = 0;
//     *columnSizes = (int*)malloc(sizeof(int) * strsSize);
//     for (int i = 0; i < strsSize; i++) {
//         (*columnSizes)[i] = 0;
//     }
//     char*** groups = (char***)malloc(sizeof(char**) * strsSize);

//     StrInfo** groups_info = (StrInfo**)malloc(sizeof(StrInfo*) * strsSize);
//     StrInfo** strs_info = (StrInfo**)malloc(sizeof(StrInfo*) * strsSize);

//     int str_i, group_i;
//     for (str_i = 0; str_i < strsSize; str_i++) {
//         strs_info[str_i] = get_str_info(strs[str_i]);
//         for (group_i = 0; group_i < *returnSize; group_i++) {
//             if (str_info_similar(strs_info[str_i], groups_info[group_i])) {
//                 break;
//             }
//         }
//         if (group_i == *returnSize) {  // new group
//             groups[group_i] = (char**)malloc(sizeof(char*) * strsSize);
//             groups_info[group_i] = strs_info[str_i];
//             (*returnSize)++;
//         }
//         groups[group_i][(*columnSizes)[group_i]++] = strs[str_i];
//     }
//     for (str_i = 0; str_i < strsSize; str_i++) {
//         free(strs_info[str_i]);
//     }
//     free(strs_info);
//     free(groups_info);
//     return groups;
// }

typedef struct {
    char* str;
    int position;
} Info;

void adjustdown(Info* infoes[], int k, int length) {
    Info* tmp = infoes[k];
    for (int i = k * 2 + 1; i < length; i = i * 2 + 1) {
        if (i + 1 < length &&
            compare_str(infoes[i]->str, infoes[i + 1]->str) == -1)
            i++;
        if (compare_str(tmp->str, infoes[i]->str) >= 0) break;
        infoes[k] = infoes[i];
        k = i;
    }
    infoes[k] = tmp;
}
void build_max_heap(Info* infoes[], int length) {
    for (int i = length / 2; i >= 0; i--) {
        adjustdown(infoes, i, length);
    }
}

void heap_sort(Info* infoes[], int length) {
    build_max_heap(infoes, length);
    for (int i = length - 1; i > 0; i--) {
        Info* tmp = infoes[0];
        infoes[0] = infoes[i];
        infoes[i] = tmp;
        adjustdown(infoes, 0, i);
    }
}

int partition(Info* infoes[], int low, int high) {
    Info* pivot = infoes[low];
    while (low < high) {
        while (low < high && compare_str(infoes[high]->str, pivot->str) >= 0) {
            high--;
        }
        infoes[low] = infoes[high];
        while (low < high && compare_str(infoes[low]->str, pivot->str) < 0) {
            low++;
        }
        infoes[high] = infoes[low];
    }
    infoes[low] = pivot;
    return low;
}

void quick_sort(Info* infoes[], int low, int high) {
    if (low < high) {
        int pivot = partition(infoes, low, high);
        quick_sort(infoes, low, pivot);
        quick_sort(infoes, pivot + 1, high);
    }
}

int partition_char(char str[], int low, int high) {
    char pivot = str[low];
    while (low < high) {
        while (low < high && str[high] >= pivot) {
            high--;
        }
        str[low] = str[high];
        while (low < high && str[low] < pivot) {
            low++;
        }
        str[high] = str[low];
    }
    str[low] = pivot;
    return low;
}

void quick_sort_char(char str[], int low, int high) {
    if (low < high) {
        int pivot = partition_char(str, low, high);
        quick_sort_char(str, low, pivot);
        quick_sort_char(str, pivot + 1, high);
    }
}

char*** groupAnagrams4(char** strs, int strsSize, int** columnSizes,
                       int* returnSize) {
    // init group_infoes
    Info** group_infoes = (Info**)malloc(sizeof(Info*) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        int length = strlen(strs[i]);
        char* copy = (char*)malloc(sizeof(char) * (length + 1));
        strcpy(copy, strs[i]);
        quick_sort_char(copy, 0, length - 1);
        // select_sort(copy, 0, length);

        group_infoes[i] = (Info*)malloc(sizeof(Info));
        group_infoes[i]->str = copy;
        group_infoes[i]->position = i;
    }

    // heap_sort(group_infoes, strsSize);
    quick_sort(group_infoes, 0, strsSize - 1);

    // init return value
    *returnSize = 0;
    *columnSizes = (int*)malloc(sizeof(int) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        (*columnSizes)[i] = 0;
    }
    char*** groups = (char***)malloc(sizeof(char**) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        groups[i] = (char**)malloc(sizeof(char*) * strsSize);
    }

    // divide into groups
    groups[0][0] = strs[group_infoes[0]->position];
    (*columnSizes)[0] = 1;
    for (int i = 1; i < strsSize; i++) {
        if (compare_str(group_infoes[i]->str, group_infoes[i - 1]->str) !=
            0) {  // new group
            (*returnSize)++;
        }
        groups[*returnSize][(*columnSizes)[*returnSize]++] =
            strs[group_infoes[i]->position];
    }
    (*returnSize)++;

    // free group_infoes
    for (int i = 1; i < strsSize; i++) {
        free(group_infoes[i]->str);
        free(group_infoes[i]);
    }
    free(group_infoes);
    return groups;
}

////////////////////////////////////////////////////////////////////////////////
typedef struct {
    unsigned long length;
    unsigned char letter_count[26];  // the number of every letter   26
    char count;                      // the number of different letters
    unsigned int hash_code;
} StrInfo;

#define MAP_SIZE 1 << 10
#define MAP_KEY_TYPE StrInfo
#define MAP_VALUE_TYPE int
typedef struct node {
    MAP_KEY_TYPE* key;
    MAP_VALUE_TYPE value;
    struct node* next_conflict;
} MapNode;
typedef struct {
    short hash_code[MAP_SIZE];
    unsigned short hash_code_length;
    MapNode* nodes[MAP_SIZE];
} Map;

StrInfo* str_info_create(const char str[]) {  // O(l)
    StrInfo* info = (StrInfo*)malloc(sizeof(StrInfo));
    memset(info, 0, sizeof(StrInfo));

    info->length = strlen(str);
    for (int i = 0; i < info->length; i++) {
        if (info->letter_count[str[i] - 'a']++ == 0) info->count++;
    }
    return info;
}

int str_info_equ(StrInfo* info_a, StrInfo* info_b) {  // O(3) or O(6)
    long* p_a = (long*)info_a;
    long* p_b = (long*)info_b;
    int len = sizeof(StrInfo) / sizeof(long);  // 对齐
    for (int i = 0; i < len; i++) {
        if (*p_a++ != *p_b++) return 0;
    }
    return 1;
}

Map* map_create() {
    Map* map = (Map*)malloc(sizeof(Map));
    memset(map, 0, sizeof(Map));
    return map;
}

void map_free(Map* map) {  // O(groups size)
    MapNode *node, *pre;
    for (int i = 0; i < map->hash_code_length; i++) {
        node = map->nodes[map->hash_code[i]];
        while (node != NULL) {
            pre = node;
            node = node->next_conflict;
            free(pre);
        }
    }
    free(map);
}

int map_hash_code(MAP_KEY_TYPE* key) {  // O(26)  todo
    unsigned int hash = 1, seed = 131, len = sizeof(MAP_KEY_TYPE) / sizeof(int);
    unsigned int* p_int = (unsigned int*)key;
    for (int i = 0; i < len; i++) {
        hash = hash * seed + p_int[i];
    }
    return hash % MAP_SIZE;
}

int map_find_by_key(Map* map, MAP_KEY_TYPE* key, MAP_VALUE_TYPE* p_value) {
    int hash_code = map_hash_code(key);
    key->hash_code = hash_code;
    for (MapNode* n = map->nodes[hash_code]; n != NULL; n = n->next_conflict) {
        if (str_info_equ(n->key, key)) {
            *p_value = n->value;
            return 1;
        }
    }
    return 0;
}

void map_add(Map* map, MAP_KEY_TYPE* key, MAP_VALUE_TYPE value) {
    int hash_code = key->hash_code;
    if (map->nodes[hash_code] == NULL) {
        map->hash_code[map->hash_code_length++] = hash_code;
    }
    MapNode* node = (MapNode*)malloc(sizeof(MapNode));
    node->key = key;
    node->value = value;
    node->next_conflict = map->nodes[hash_code];
    map->nodes[hash_code] = node;
}

char*** groupAnagrams5(char** strs, int strsSize, int** columnSizes,
                       int* returnSize) {
    // init return value
    char*** groups = (char***)malloc(sizeof(char**) * strsSize);
    *returnSize = 0;
    *columnSizes = (int*)malloc(sizeof(int) * strsSize);
    memset(*columnSizes, 0, sizeof(int) * strsSize);
    // grouping
    Map* map = map_create();
    StrInfo** infoes = (StrInfo**)malloc(sizeof(StrInfo*) * strsSize);
    for (int i = 0, group_i; i < strsSize; i++) {
        infoes[i] = str_info_create(strs[i]);
        if (!map_find_by_key(map, infoes[i], &group_i)) {  // new group
            group_i = (*returnSize)++;
            map_add(map, infoes[i], group_i);
            groups[group_i] = (char**)malloc(sizeof(char*) * strsSize);
        }
        groups[group_i][(*columnSizes)[group_i]++] = strs[i];
    }
    // free map and infoes
    map_free(map);
    for (int i = 0; i < strsSize; i++) {
        free(infoes[i]);
    }
    free(infoes);
    return groups;
}

int main(int argc, char const* argv[]) {
    // int strsSize = 6;
    // char* strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // ,"fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"};
    int strsSize = 80;
    char* strs[80] = {"nozzle",
                      "punjabi",
                      "waterlogged",
                      "imprison",
                      "crux",
                      "numismatists",
                      "sultans",
                      "rambles",
                      "deprecating",
                      "aware",
                      "outfield",
                      "marlborough",
                      "guardrooms",
                      "roast",
                      "wattage",
                      "shortcuts",
                      "confidential",
                      "reprint",
                      "foxtrot",
                      "dispossession",
                      "floodgate",
                      "unfriendliest",
                      "semimonthlies",
                      "dwellers",
                      "sshortcut",
                      "wastrels",
                      "dippers",
                      "engrossing",
                      "undertakings",
                      "unforeseen",
                      "oscilloscopes",
                      "pioneers",
                      "geller",
                      "neglects",
                      "cultivates",
                      "mantegna",
                      "elicit",
                      "couriered",
                      "shielded",
                      "shrew",
                      "heartening",
                      "lucks",
                      "teammates",
                      "jewishness",
                      "documentaries",
                      "subliming",
                      "sultan",
                      "redo",
                      "recopy",
                      "flippancy",
                      "rothko",
                      "conductor",
                      "e",
                      "carolingian",
                      "outmanoeuvres",
                      "gewgaw",
                      "saki",
                      "sarah",
                      "snooping",
                      "hakka",
                      "highness",
                      "mewling",
                      "spender",
                      "blockhead",
                      "detonated",
                      "cognac",
                      "congaing",
                      "prissy",
                      "loathes",
                      "bluebell",
                      "involuntary",
                      "aping",
                      "sadly",
                      "jiving",
                      "buffalo",
                      "chided",
                      "instalment",
                      "boon",
                      "ashikaga",
                      "enigmas"};

    int* columnSizes;
    int returnSize;

    char*** groups = groupAnagrams5(strs, strsSize, &columnSizes, &returnSize);

    printf("{\n");
    for (int i = 0; i < returnSize; i++) {
        printf("  ");
        print_array(groups[i], columnSizes[i]);
    }
    printf("}");

    getchar();
    return 0;
}
