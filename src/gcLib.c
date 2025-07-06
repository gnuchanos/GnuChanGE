#include <stdio.h>
#include <python3.13/Python.h>
#include "raylib.h"





// This is extra custom fuctions
static PyObject* TwoNumber(PyObject* self, PyObject* args) {
    int num1, num2;

    if (!PyArg_ParseTuple(args, "ii", &num1, &num2)) {
        return NULL;
    }

    return PyLong_FromLong(num1 + num2);
}

static PyObject* gc_GetRandomValue_int(PyObject* self, PyObject* args) {
    int Min, Max;

    if (!PyArg_ParseTuple(args, "ii", &Min, &Max)) {
        return NULL;
    }

    if (Min > Max) {
        PyErr_SetString(PyExc_ValueError, "Min cannot be greater than Max");
        return NULL;
    }
    
    int RandomNumber = GetRandomValue(Min, Max);

    return PyLong_FromLong(RandomNumber);
}

static PyObject* gc_GetRandomValue_float(PyObject* self, PyObject* args) {
    float Min, Max;

    if (!PyArg_ParseTuple(args, "ff", &Min, &Max)) {
        return NULL;
    }

    if (Min > Max) {
        PyErr_SetString(PyExc_ValueError, "Min cannot be greater than Max");
        return NULL;
    }
    
    float RandomNumber = Min + ((float)rand() / RAND_MAX) * (Max - Min);

    return PyFloat_FromDouble(RandomNumber);
}






// Raylib extra function
static PyObject* gc_SetTargetFPS(PyObject* self, PyObject* args) {
    int FPS;

    if (!PyArg_ParseTuple(args, "i", &FPS)) {
        return NULL;
    }

    SetTargetFPS(FPS); 
    Py_RETURN_NONE;
}





// Raylib Window System
static PyObject* gc_InitWindow(PyObject* self, PyObject* args) {
    int width, height;
    const char* title;

    if (!PyArg_ParseTuple(args, "iis", &width, &height, &title)) {
        return NULL;
    }

    InitWindow(width, height, title);
    Py_RETURN_NONE;
}

static PyObject* gc_WindowShouldClose(PyObject* self, PyObject* args) {
    if (WindowShouldClose()) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}




// Start Draw Here
static PyObject* gc_BeginDrawing(PyObject* self, PyObject* args) {
    BeginDrawing();
    Py_RETURN_NONE;
}

static PyObject* gc_ClearBackground(PyObject* self, PyObject* args) {
    int r, g, b, a;
    if (!PyArg_ParseTuple(args, "iiii", &r, &g, &b, &a))
        return NULL;
    ClearBackground((Color){r, g, b, a});
    Py_RETURN_NONE;
}



// This is Drawing Objects

// Color
// CLITERAL(Color){ 200, 200, 200, 255 }
static PyObject* gc_DrawText(PyObject* self, PyObject* args) {
    const char* text;
    int x, y, fontSize;
    PyObject* rgba_list;

    if (!PyArg_ParseTuple(args, "siiiO", &text, &x, &y, &fontSize, &rgba_list)) {
        return NULL;
    }

    // rgba_list'in liste olup olmadığını kontrol et
    if (!PyList_Check(rgba_list)) {
        PyErr_SetString(PyExc_TypeError, "Expected a list for rgba");
        return NULL;
    }

    if (PyList_Size(rgba_list) != 4) {
        PyErr_SetString(PyExc_ValueError, "RGBA list must have exactly 4 elements");
        return NULL;
    }

    int r, g, b, a;
    PyObject* item;

    item = PyList_GetItem(rgba_list, 0);
    r = (int)PyLong_AsLong(item);
    item = PyList_GetItem(rgba_list, 1);
    g = (int)PyLong_AsLong(item);
    item = PyList_GetItem(rgba_list, 2);
    b = (int)PyLong_AsLong(item);
    item = PyList_GetItem(rgba_list, 3);
    a = (int)PyLong_AsLong(item);

    Color color = (Color){ r, g, b, a };

    DrawText(text, x, y, fontSize, color);

    Py_RETURN_NONE;
}

static PyObject* gc_DrawFPS(PyObject* self, PyObject* args) {
    int x, y;

    if (!PyArg_ParseTuple(args, "ii", &x, &y)) { return NULL; }

    DrawFPS(x, y);

    Py_RETURN_NONE;
}

// End Draw Here
static PyObject* gc_EndDrawing(PyObject* self, PyObject* args) {
    EndDrawing();
    Py_RETURN_NONE;
}

static PyObject* gc_CloseWindow(PyObject* self, PyObject* args) {
    CloseWindow();
    Py_RETURN_NONE;
}






// Method listesi

static PyMethodDef gcMethods[] = {
    // Extra
    {"TwoNumber", TwoNumber, METH_VARARGS, "Rock Math"},
    {"gc_GetRandomValue_int", gc_GetRandomValue_int, METH_VARARGS, "Rock Math"},
    {"gc_GetRandomValue_float", gc_GetRandomValue_float, METH_VARARGS, "Rock Math"},
    

    // Window
    {"gc_InitWindow", gc_InitWindow, METH_VARARGS, NULL},
    {"gc_CloseWindow", gc_CloseWindow, METH_NOARGS, NULL},
    {"gc_WindowShouldClose", gc_WindowShouldClose, METH_NOARGS, NULL},

    // Draw
    {"gc_BeginDrawing", gc_BeginDrawing, METH_NOARGS, NULL},
    {"gc_EndDrawing", gc_EndDrawing, METH_NOARGS, NULL},

    // background
    {"gc_ClearBackground", gc_ClearBackground, METH_VARARGS, NULL},

    // Draw Object
    {"gc_DrawText", gc_DrawText, METH_VARARGS, NULL},
    {"gc_DrawFPS", gc_DrawFPS, METH_VARARGS, NULL},

    // Raylib Extra
    {"gc_SetTargetFPS", gc_SetTargetFPS, METH_VARARGS, NULL},


    // What is this
    {NULL, NULL, 0, NULL}
};

// Modül tanımı

static struct PyModuleDef gcModule = {
    PyModuleDef_HEAD_INIT,
    "gcLib_GnuLinux",
    "Test module with raylib bindings and misc functions",
    -1,
    gcMethods
};

PyMODINIT_FUNC PyInit_gcLib_GnuLinux(void) {
    printf("It's working YEY\n");
    return PyModule_Create(&gcModule);
}
