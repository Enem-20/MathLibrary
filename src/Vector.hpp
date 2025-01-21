#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cstddef>
#include <type_traits>
#include <cmath>
#include <stdexcept>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
//consteval
template <Arithmetic T, size_t N>
class Vector {
private:
    std::array<T, N> components;
public:
    constexpr Vector() : components{0} 
    , x (components[0])
    , y (components[0])
    , z (components[0])
    , w (components[0])
    {}

    template <typename... Args>
    requires (sizeof...(Args) == N && (std::is_convertible_v<Args, T> && ...))
    constexpr Vector(Args... args)
    : components{static_cast<T>(args)...}
    , x ((components.size() > 0) ? components[0] : components[0])
    , y ((components.size() > 1) ? components[1] : components[0])
    , z ((components.size() > 2) ? components[2] : components[0])
    , w ((components.size() > 3) ? components[3] : components[0])
    {
        if constexpr(std::is_convertible_v<std::tuple_element_t<0,std::tuple<Args...>>, int>) {
            x = 10;
        }
    }

    constexpr size_t size() const { return N; }

    constexpr T get(size_t index) const {
        return components[index];
    }

    constexpr void set(size_t index, T value) {
        components[index] = value;
    }

    constexpr T length() const {
        T sum = 0;
        for (const auto& e : components) {
            sum += e * e;
        }
        return std::sqrt(sum);
    }

    constexpr T& operator[](size_t index) {
        return components[index];
    }

    constexpr const T& operator[](size_t index) const {
        return components[index];
    }

    constexpr auto operator*(const Vector<T, N>& other) const{
        static_assert((N > 1) && (N < 4), "For calculate vector multipling vector size must be greater than 1 and lower than 4");
        if constexpr (N == 2) {//pseudoscalar
            return Vector<T, 1>(x*other.y-y*other.x);
        }
        else {
            return Vector<T, N>(y*other.z-z*other.y, z*other.x-x*other.z, x*other.y-y*other.x);
        }
        
    }

    constexpr float operator^(const Vector<T, N>& other) const {
        auto scalar = x*other.x;
        for(size_t i=1; i < N; ++i) {
            scalar += (*this)[i] * other[i];
        }        
        return scalar;
    }

    constexpr void normize() {
        float _length = length();
        for(auto& component : components) {
            component /= _length;
        }
    }

    T& x;
    T& y;
    T& z;
    T& w;
};

#endif