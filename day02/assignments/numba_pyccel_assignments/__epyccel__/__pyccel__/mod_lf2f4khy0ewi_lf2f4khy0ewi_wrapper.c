#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t bind_c_solve_2d_diff_pyccel(int64_t n0_u, int64_t n1_u, double *u, int64_t n0_un, int64_t n1_un, double *un, int64_t nt, double dt, double dx, double dy, double nu);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *solve_2d_diff_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray u = {.shape = NULL};
    t_ndarray un = {.shape = NULL};
    int64_t nt;
    double dt;
    double dx;
    double dy;
    double nu;
    int64_t Out_0001;
    PyArrayObject *u_tmp;
    PyArrayObject *un_tmp;
    PyObject *nt_tmp;
    PyObject *dt_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *nu_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "u",
        "un",
        "nt",
        "dt",
        "dx",
        "dy",
        "nu",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!OOOOO", kwlist, &PyArray_Type, &u_tmp, &PyArray_Type, &un_tmp, &nt_tmp, &dt_tmp, &dx_tmp, &dy_tmp, &nu_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(un_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        un = pyarray_to_ndarray(un_tmp);
    }
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
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
    if (PyIs_NativeFloat(nu_tmp))
    {
        nu = PyDouble_to_Double(nu_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Out_0001 = bind_c_solve_2d_diff_pyccel(nd_ndim(&u, 0), nd_ndim(&u, 1), nd_data(&u), nd_ndim(&un, 0), nd_ndim(&un, 1), nd_data(&un), nt, dt, dx, dy, nu);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(u);
    free_pointer(un);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_lf2f4khy0ewi_lf2f4khy0ewi_methods[] = {
    {
        "solve_2d_diff_pyccel",
        (PyCFunction)solve_2d_diff_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_lf2f4khy0ewi_lf2f4khy0ewi_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_lf2f4khy0ewi_lf2f4khy0ewi_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_lf2f4khy0ewi_lf2f4khy0ewi",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_lf2f4khy0ewi_lf2f4khy0ewi_methods,
    mod_lf2f4khy0ewi_lf2f4khy0ewi_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_lf2f4khy0ewi_lf2f4khy0ewi(void)
{
    import_array();
    return PyModuleDef_Init(&mod_lf2f4khy0ewi_lf2f4khy0ewi_module);
}
