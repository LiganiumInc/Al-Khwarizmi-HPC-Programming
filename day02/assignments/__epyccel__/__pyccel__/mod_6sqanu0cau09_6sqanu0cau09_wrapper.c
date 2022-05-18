#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


int64_t iter_factorial(int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *iter_factorial_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    int64_t fact;
    PyObject *n_tmp;
    PyObject *fact_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &n_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeInt(n_tmp))
    {
        n = PyInt64_to_Int64(n_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    fact = iter_factorial(n);
    fact_tmp = Int64_to_PyLong(&fact);
    result = Py_BuildValue("O", fact_tmp);
    Py_DECREF(fact_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_6sqanu0cau09_6sqanu0cau09_methods[] = {
    {
        "iter_factorial",
        (PyCFunction)iter_factorial_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_6sqanu0cau09_6sqanu0cau09_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_6sqanu0cau09_6sqanu0cau09_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_6sqanu0cau09_6sqanu0cau09",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_6sqanu0cau09_6sqanu0cau09_methods,
    mod_6sqanu0cau09_6sqanu0cau09_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_6sqanu0cau09_6sqanu0cau09(void)
{
    import_array();
    return PyModuleDef_Init(&mod_6sqanu0cau09_6sqanu0cau09_module);
}
