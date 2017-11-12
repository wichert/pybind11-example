pybind11 example
================

This project is an example of using `pybind11
<http://pybind11.readthedocs.io/en/stable/>`_ to expose a C++ library
to Python. It features a number of nice-to-haves:

* a ``setup.py`` file that can build and install the module following
  standard Python practices.
* Unit tests using `pytest <https://docs.pytest.org>`_
* Compatible with both Python 2 and Python 3
* Standard ``.gitignore`` and ``.editorconfig`` files.
* a README :)

To test the module do the following:

.. code-block:: shell

   # Create a virtual environment
   python3 -m venv .
   # Build and install the package
   bin/pip install .
   # Install pytest so we can run the tests
   bin/pip install pytest

If you use Python 2 use ``virtualenv .`` instead of ``python3 -m venv``. You
will need to have `virtualenv <https://pypi.org/project/virtualenv/>`_
installed for that to work.
 
You can now run the tests to confirm everything works:

.. code-block:: shell

    bin/py.test -v
    =========================== test session starts ===========================
    platform darwin -- Python 3.6.3, pytest-3.2.3, py-1.4.34, pluggy-0.4.0 -- /Users/wichert/Development/pbt/bin/python3
    cachedir: .cache
    rootdir: /Users/wichert/Development/pbt, inifile: setup.cfg
    collected 8 items

    tests/test_base.py::test_can_create_base_instance PASSED
    tests/test_base.py::test_a_getter_and_setter PASSED
    tests/test_base.py::test_a_property PASSED
    tests/test_base.py::test_virtual_method PASSED
    tests/test_base.py::test_pure_virtual_not_implemented PASSED
    tests/test_base.py::test_derived_class PASSED
    tests/test_child.py::test_virtual_method PASSED
    tests/test_child.py::test_pure_virtual_implementation PASSED

    ======================== 8 passed in 0.02 seconds =========================


If you make a code change you will need to re-build and install. You can
do this using pip:

.. code-block:: shell

    bin/pip install --upgrade .

or by using ``setup.py`` directly:

.. code-block:: shell

    bin/python setup.py install

