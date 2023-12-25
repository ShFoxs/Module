#include <iostream>
#include <memory>

// Абстрактний клас для виробу A
class ProductA {
public:
    virtual void produce() const = 0;
    virtual ~ProductA() = default;
};

// Абстрактний клас для виробу B
class ProductB {
public:
    virtual void produce() const = 0;
    virtual ~ProductB() = default;
};

// Конкретний клас виробу A1
class ConcreteProductA1 : public ProductA {
public:
    void produce() const override {
        std::cout << "Producing Product A1" << std::endl;
    }
};

// Конкретний клас виробу A2
class ConcreteProductA2 : public ProductA {
public:
    void produce() const override {
        std::cout << "Producing Product A2" << std::endl;
    }
};

// Конкретний клас виробу B1
class ConcreteProductB1 : public ProductB {
public:
    void produce() const override {
        std::cout << "Producing Product B1" << std::endl;
    }
};

// Конкретний клас виробу B2
class ConcreteProductB2 : public ProductB {
public:
    void produce() const override {
        std::cout << "Producing Product B2" << std::endl;
    }
};

// Абстрактна фабрика для виробів A і B
class AbstractFactory {
public:
    virtual std::unique_ptr<ProductA> createProductA() const = 0;
    virtual std::unique_ptr<ProductB> createProductB() const = 0;
    virtual ~AbstractFactory() = default;
};

// Конкретна фабрика для виробів A1 і B1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<ProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<ProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// Конкретна фабрика для виробів A2 і B2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<ProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<ProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

// Клас, який використовує абстрактну фабрику для створення виробів
class Client {
private:
    std::unique_ptr<ProductA> productA;
    std::unique_ptr<ProductB> productB;

public:
    Client(const AbstractFactory& factory) {
        productA = factory.createProductA();
        productB = factory.createProductB();
    }

    void run() const {
        productA->produce();
        productB->produce();
    }
};

int main() {
    // Використання фабрики 1
    ConcreteFactory1 factory1;
    Client client1(factory1);
    std::cout << "Client 1:" << std::endl;
    client1.run();

    std::cout << std::endl;

    // Використання фабрики 2
    ConcreteFactory2 factory2;
    Client client2(factory2);
    std::cout << "Client 2:" << std::endl;
    client2.run();

    return 0;
}