#include "Python.h"

int Hack_flag = 0;
int Kao_TestHackFlag(int data){
    return (data & Hack_flag) != 0;

}
int Kao_TestHack(char *name){
    
    PyObject *sys_attr = PySys_GetObject(name);
    return (sys_attr != NULL);
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
