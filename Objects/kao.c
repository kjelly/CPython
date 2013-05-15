#include "Python.h"
int Kao_TestHack(char* name){
    
    PyObject *list = PySys_GetObject("argv");
    PyObject *obj = PyString_FromString(name);
    return Kao_ListContain(list, obj);
}


int Kao_ListContain(PyObject *list, PyObject *obj){
    PyObject *item;
    Py_ssize_t size;
    int result = 0;
    Py_ssize_t i;
    if ( list != NULL){
        size = PyList_Size(list);
        for(i = 0; i < size ; i++){
            item = PyList_GetItem(list, i);
            if ( PyObject_Cmp(item, obj, &result) != -1){
                if (result == 0){
                    return 1;
                }
            }
        }
    }
    return 0;
    
}