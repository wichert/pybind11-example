#pragma once

#include <string>

struct Base {
    enum Value {
        one,
        two,
        three
    };

    Base();
    Value getA() const {
        return a;
    }

    void setA(Value v) {
        a = v;
    }

    std::string callPureVirtual() {
        return pureVirtual();
    }

protected:
    virtual std::string pureVirtual() = 0;
    virtual std::string virt();

    Value a;
};


struct Child : public Base {
protected:
    std::string virt() override;
    std::string pureVirtual() override;
};