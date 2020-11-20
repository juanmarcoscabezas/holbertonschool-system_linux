#include <Python.h>

/**
 * print_python_list -This function pirnts some basic info about PY Lists
 * @p: PY objects
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t list_size = PyList_Size(p);
	Py_ssize_t i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", list_size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < list_size; i++)
	{
		printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
	}
}
