/* Interface to execute compiled code */

#ifndef Kao_H
#define Kao_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_FUNC(int) Kao_TestHack(char* name);
PyAPI_FUNC(int) Kao_ListContain(PyObject *list, PyObject *obj);
PyAPI_DATA(int) Hack_flag;

#ifdef __cplusplus
}
#endif
#endif /* !Py_EVAL_H */
