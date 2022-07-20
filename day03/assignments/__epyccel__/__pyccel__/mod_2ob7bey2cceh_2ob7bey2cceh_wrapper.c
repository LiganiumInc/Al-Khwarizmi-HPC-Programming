#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void bind_c_pressure_poisson_cel(int64_t, int64_t, double*, double, double, int64_t, int64_t, double*, int64_t);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *pressure_poisson_cel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    double dx;
    double dy;
    t_ndarray b = {.shape = NULL};
    int64_t nit;
    PyArrayObject *p_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *b_tmp;
    PyObject *nit_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "dx",
        "dy",
        "b",
        "nit",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!O", kwlist, &PyArray_Type, &p_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &b_tmp, &nit_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    bind_c_pressure_poisson_cel(nd_ndim(&p, 0), nd_ndim(&p, 1), nd_data(&p), dx, dy, nd_ndim(&b, 0), nd_ndim(&b, 1), nd_data(&b), nit);
    result = Py_BuildValue("");
    free_pointer(p);
    free_pointer(b);
    return result;
}
/*........................................*/

/*........................................*/
static int32_t exec_func(PyObject *m)
{
    return 0;
}
/*........................................*/

/*........................................*/

static PyMethodDef mod_2ob7bey2cceh_2ob7bey2cceh_methods[] = {
    {
        "pressure_poisson_cel",
        (PyCFunction)pressure_poisson_cel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_2ob7bey2cceh_2ob7bey2cceh_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_2ob7bey2cceh_2ob7bey2cceh_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_2ob7bey2cceh_2ob7bey2cceh",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_2ob7bey2cceh_2ob7bey2cceh_methods,
    mod_2ob7bey2cceh_2ob7bey2cceh_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_2ob7bey2cceh_2ob7bey2cceh(void)
{
    import_array();
    return PyModuleDef_Init(&mod_2ob7bey2cceh_2ob7bey2cceh_module);
}
