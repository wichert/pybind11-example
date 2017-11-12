PYTHON	?= python
SOURCES	:= $(wildcard src/*.{cc,h})

all:: bin/py.test


bin/pip bin/python bin/py.test: 
	$(PYTHON) -m venv .
	bin/pip install pytest

stamp-build: bin/python $(SOURCES)
	bin/python setup.py install
	touch stamp-build

check: bin/py.test stamp-build
	bin/py.test -v

clean::
	-rm -rf .cache .eggs
	-rm -rf bin include lib share var .Python 
	-rm -rf build dist wouter.egg-info tests/__pycache__
	-rm -f pip-selfcheck.json pyvenv.cfg stamp-build

.PHONY: all build check clean

