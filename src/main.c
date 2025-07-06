#include <python3.13/Python.h>
#include <stdio.h>
#include <wchar.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Kullanım: %s script.py\n", argv[0]);
        return 1;
    }

    PyConfig config;
    PyConfig_InitPythonConfig(&config);

    // Gömülü Python dizinini ve çalıştırılabilir dosyayı doğru ayarla
    wchar_t *home = Py_DecodeLocale("./Python", NULL);
    wchar_t *program = Py_DecodeLocale("./gcRunner", NULL);

    config.home = home;
    config.program_name = program;

    PyStatus status = Py_InitializeFromConfig(&config);
    if (PyStatus_Exception(status)) {
        Py_ExitStatusException(status);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp) {
        PyRun_SimpleFile(fp, argv[1]);
        fclose(fp);
    } else {
        fprintf(stderr, "Dosya bulunamadı: %s\n", argv[1]);
    }

    Py_FinalizeEx();
    PyConfig_Clear(&config);

    return 0;
}