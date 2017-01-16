#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * example:$ ./a.out -c md readme.txt
 * output: readme.md
 *
 * -a添加扩展名 -c修改扩展名
 * md 新扩展名
 * readme.txt 要修改的文件名
 *
 */
int main(int argc, const char *argv[]) {
    if (argc < 4) {
        puts("格式请参考  $ ./a.out -c md readme.txt");
        return EXIT_FAILURE;
    }

    enum OPTIONS {
        ADD, CHANGE
    };
    int opt = ADD;
    while (*++argv != NULL && **argv == '-') {
        switch (*++*argv) {
            case 'a' :
                opt = ADD;
                break;
            case 'c' :
                opt = CHANGE;
                break;
            default:
                return EXIT_FAILURE;
                break;
        }
    }

    const char *ext = *argv;

    while (*++argv != NULL) {
        switch (opt) {
            case ADD: {
                printf("%s.%s\n", *argv, ext);
                break;
            }
            case CHANGE: {

                char * cpy = calloc(strlen(*argv), sizeof(char)) + 1;
                strcpy(cpy,*argv);

                char *dot_at = strrchr(cpy, '.');
                if (dot_at == NULL) {
                    printf("%s format Err.\n", cpy);
                    continue;
                }
                *dot_at = '\0';
                printf("%s.%s\n", cpy, ext);
                break;
            }
            default:
                puts("ERR");
                break;
        }
    }

    return EXIT_SUCCESS;
}
