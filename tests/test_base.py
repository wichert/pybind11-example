from wouter import Base
from wouter import Value
import pytest


def test_can_create_base_instance():
    Base()


def test_a_getter_and_setter():
    b = Base()
    assert b.getA() == Value.one
    b.setA(Value.two)
    assert b.getA() == Value.two


def test_a_property():
    b = Base()
    assert b.a == Value.one
    b.a = Value.three
    assert b.a == Value.three


def test_virtual_method():
    b = Base()
    assert b.virt() == 'Base::virt()'


def test_pure_virtual_not_implemented():
    b = Base()
    with pytest.raises(RuntimeError):
        b.pure_virtual()


def test_derived_class():

    class MyClass(Base):
        def pure_virtual(self):
            return 'MyClass::pure_virtual()'
    
    m = MyClass()
    assert m.pure_virtual() == 'MyClass::pure_virtual()'
    assert m.call_pure_virtual() == 'MyClass::pure_virtual()'
