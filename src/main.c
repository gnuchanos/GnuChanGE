#include <python3.13/Python.h>
#include <stdio.h>
#include <raylib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Kullanım: %s script.py\n", argv[0]);
        return 1;
    }

    Py_Initialize();



    // Python script file
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Dosya açılamadı: %s\n", argv[1]);
        Py_Finalize();
        return 1;
    }






    // Python script dosyasını çalıştır
    int res = PyRun_SimpleFile(fp, argv[1]);
    printf("This is Just binding sorry :( \n");
    fclose(fp);
    Py_Finalize();
    return res;
}