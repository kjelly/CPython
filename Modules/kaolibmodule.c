#include <Python.h>
 
static PyObject* say_hello(PyObject* self, PyObject* args)
{
    const char* name;
 
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
 
    printf("Hello %s!\n", name);
 
    Py_RETURN_NONE;
}

static PyObject* show_refcnt(PyObject* self, PyObject* args)
{
    PyObject *obj;
 
    if (!PyArg_ParseTuple(args, "O", &obj))
        return NULL;
    printf("reference count: %d\n", obj->ob_refcnt);
 
    Py_RETURN_NONE;
}

static PyObject* add_int(PyObject* self, PyObject* args)
{
    int sum = 0;
    int i;
    int count = PyTuple_Size(args);
    PyIntObject *int_obj;
    PyObject *obj;
    for (i = 0;i < count; i++){
        obj = PyTuple_GetItem(args, i);
        if (PyInt_Check(obj)){
          int_obj = (PyIntObject*) obj;
          sum += int_obj->ob_ival;
        }
        

    }
 
    return Py_BuildValue("i", sum);
}
 
 
static PyMethodDef HelloMethods[] =
{
     {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
     {"show_refcnt", show_refcnt, METH_VARARGS, "show object reference count."},
     {"add_int", add_int, METH_VARARGS, "show object reference count."},
     {NULL, NULL, 0, NULL}
};
 
PyMODINIT_FUNC
 
initkaolib(void)
{
     (void) Py_InitModule("kaolib", HelloMethods);
}
 
