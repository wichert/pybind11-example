#include <pybind11/pybind11.h>
#include "base.hh"


namespace py = pybind11;


// Trampoline class for pybind to tell it how to deal with virtual functions.
class PyBase : public Base {
public:
    using Base::Base;

protected:
    std::string virt() override {
        PYBIND11_OVERLOAD(std::string, Base, virt );
    }

    std::string pureVirtual() override {
        // We use PYBIND11_OVERLOAD_PURE_NAME instead of PYBIND11_OVERLOAD_PURE
        // since the method has a different name in Python.
        PYBIND11_OVERLOAD_PURE_NAME(
            std::string, // C++ return type
            Base, // super class
            "pure_virtual", // Python method name
            pureVirtual // C++ method name
        );
    }
};


// Helper class for pybind to expose protected methods publicly.
class PublishBase : public Base {
public:
    using Base::virt;
    using Base::pureVirtual;
};


// Helper functiont to expose C++ things to Python.
// In this example you would normally put this code directly in the
// PYBIND11_MODULE block, but for larger libraries you will want to
// use functions in separate files to expose different parts of your
// C++ library. 
void exposeClasses(py::module m) {
    py::class_<Base, PyBase> base(m, "Base");

    base
        .def(py::init<>())
        // You normally does not use getter and setter functions, but use a property.
        .def("getA", &Base::getA)
        .def("setA", &Base::setA)
        .def_property("a", &Base::getA, &Base::setA)
        .def("virt", &PublishBase::virt)
        // Note that we use a different (PEP8-style) naming scheme in Python
        // to look more like a standard Python library.
        .def("pure_virtual", &PublishBase::pureVirtual)
        .def("call_pure_virtual", &Base::callPureVirtual)
        ;

    py::class_<Child>(m, "Child", base)
        .def(py::init<>())
        ;
}


PYBIND11_MODULE(wouter, m) {
    m.doc() = "Wouter's module";

    py::enum_<Base::Value>(m, "Value")
        .value("one", Base::one)
        .value("two", Base::two)
        .value("three", Base::three)
        ;
    
    exposeClasses(m);
}

