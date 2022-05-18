#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void matrix_prod(t_ndarray A, t_ndarray B, t_ndarray C, int64_t N, int64_t M);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *matrix_prod_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray A = {.shape = NULL};
    t_ndarray B = {.shape = NULL};
    t_ndarray C = {.shape = NULL};
    int64_t N;
    int64_t M;
    PyArrayObject *A_tmp;
    PyArrayObject *B_tmp;
    PyArrayObject *C_tmp;
    PyObject *N_tmp;
    PyObject *M_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "A",
        "B",
        "C",
        "N",
        "M",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!OO", kwlist, &PyArray_Type, &A_tmp, &PyArray_Type, &B_tmp, &PyArray_Type, &C_tmp, &N_tmp, &M_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(A_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        A = pyarray_to_ndarray(A_tmp);
    }
    if (!pyarray_check(B_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        B = pyarray_to_ndarray(B_tmp);
    }
    if (!pyarray_check(C_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        C = pyarray_to_ndarray(C_tmp);
    }
    if (PyIs_NativeInt(N_tmp))
    {
        N = PyInt64_to_Int64(N_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(M_tmp))
    {
        M = PyInt64_to_Int64(M_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    matrix_prod(A, B, C, N, M);
    result = Py_BuildValue("");
    free_pointer(A);
    free_pointer(B);
    free_pointer(C);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_ghcwqb2s6c8i_ghcwqb2s6c8i_methods[] = {
    {
        "matrix_prod",
        (PyCFunction)matrix_prod_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_ghcwqb2s6c8i_ghcwqb2s6c8i_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_ghcwqb2s6c8i_ghcwqb2s6c8i_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_ghcwqb2s6c8i_ghcwqb2s6c8i",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_ghcwqb2s6c8i_ghcwqb2s6c8i_methods,
    mod_ghcwqb2s6c8i_ghcwqb2s6c8i_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_ghcwqb2s6c8i_ghcwqb2s6c8i(void)
{
    import_array();
    return PyModuleDef_Init(&mod_ghcwqb2s6c8i_ghcwqb2s6c8i_module);
}
