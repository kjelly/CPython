#include "Python.h"
int Kao_Test(void){
    PyObject *item;
    PyObject *obj = PySys_GetObject("argv");
    PyObject *hack = PyString_FromString("hack");
    Py_ssize_t size;
    int flag = 0;
    int result = 0;
    if ( obj != NULL){
        size = PyList_Size(obj);
        Py_ssize_t i;
        for(i = 0; i < size ; i++){
            item = PyList_GetItem(obj, i);
            if ( PyObject_Cmp(item, hack, &result) != -1){
                if (result == 0){
                    flag = 1;
                }
            }
        }
    }
    return flag;
}
