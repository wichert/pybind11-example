from wouter import Child


def test_virtual_method():
    c = Child()
    assert c.virt() == 'Child::virt()'


def test_pure_virtual_implementation():
    c = Child()
    assert c.pure_virtual() == 'Child::pureVirtual()'
    assert c.call_pure_virtual() == 'Child::pureVirtual()'
