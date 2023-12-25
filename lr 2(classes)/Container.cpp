#include "Container.h"

template class Container<Continent>;
template class Container<Country>;
template class Container<Subject>;
template class Container<City>;
template class Container<Company>;
template class Container<Branch>;
template class Container<AbstractElement>;


template <typename T>
void Container<T>::addElement(T* element) {
    elements.push_back(element);
}


template <typename T>
void Container<T>::displayElements() const {
    for (const auto& element : elements) {
        std::cout << element->info() << std::endl;
    }
}

