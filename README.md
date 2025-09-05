# C++ Module 06 - Type Conversion & Casting

## 📋 Proje Amacı

Bu proje, C++ dilinde tip dönüşümleri ve casting işlemlerini öğrenmek için tasarlanmıştır. Üç farklı egzersiz ile C++'ın güçlü tip sistemi ve güvenli tip dönüşümleri konularında pratik yapma imkanı sunar.

## 🎯 Öğrenme Hedefleri

- **Scalar Type Conversion**: String literal'ları C++ temel tiplerine dönüştürme
- **Memory Serialization**: Pointer'ları integer'a ve geri dönüştürme
- **Runtime Type Identification**: Dynamic casting ve RTTI kullanımı

## 📊 Proje Yapısı

| Egzersiz | Klasör | Açıklama | Ana Teknoloji |
|----------|--------|----------|---------------|
| **ex00** | `ex00/` | Scalar Type Converter | Static Methods, Type Validation |
| **ex01** | `ex01/` | Serializer/Deserializer | reinterpret_cast, Memory Management |
| **ex02** | `ex02/` | Type Identification | dynamic_cast, RTTI, Polymorphism |

## 🛠️ Kullanılan Teknolojiler

### C++ Standartları
- **C++98**: Tüm projeler C++98 standardı kullanılarak geliştirilmiştir
- **Compiler Flags**: `-Wall -Wextra -Werror -std=c++98`

### Temel C++ Özellikleri
- **Classes & Objects**: OOP prensipleri
- **Static Methods**: Utility sınıfları
- **Inheritance**: Base class ve derived class'lar
- **Virtual Functions**: Polymorphism
- **Memory Management**: new/delete operatörleri

### Type Casting
- **static_cast**: Güvenli tip dönüşümleri
- **reinterpret_cast**: Pointer-memory dönüşümleri
- **dynamic_cast**: Runtime tip kontrolü

### STL Kütüphaneleri
- **std::string**: String işlemleri
- **std::iostream**: Input/Output işlemleri
- **std::sstream**: String stream işlemleri
- **std::limits**: Tip limitleri
- **std::cstdlib**: C standard kütüphanesi

### Build System
- **Makefile**: Otomatik derleme sistemi
- **GNU Make**: Build tool

## 📁 Dosya Yapısı

```
cpp06/
├── ex00/                    # Scalar Converter
│   ├── ScalarConverter.hpp  # Header file
│   ├── ScalarConverter.cpp  # Implementation
│   ├── main.cpp            # Test program
│   └── Makefile            # Build configuration
├── ex01/                    # Serializer
│   ├── Serializer.hpp      # Header file
│   ├── Serializer.cpp      # Implementation
│   ├── main.cpp            # Test program
│   └── Makefile            # Build configuration
├── ex02/                    # Type Identification
│   ├── Base.hpp            # Base class
│   ├── Base.cpp            # Base implementation
│   ├── A.hpp, B.hpp, C.hpp # Derived classes
│   ├── Identify.cpp        # Identification functions
│   ├── main.cpp            # Test program
│   └── Makefile            # Build configuration
├── README.md               # Bu dosya
└── EXERCISES.md            # Detaylı egzersiz açıklamaları
```

## 🚀 Hızlı Başlangıç

1. **Projeyi klonlayın**:
   ```bash
   git clone <repository-url>
   cd cpp06
   ```

2. **Egzersizleri derleyin**:
   ```bash
   cd ex00 && make
   cd ../ex01 && make
   cd ../ex02 && make
   ```

3. **Test edin**:
   ```bash
   # ex00 - Scalar Converter
   ./ex00/convert "42"
   
   # ex01 - Serializer
   ./ex01/serializer
   
   # ex02 - Type Identification
   ./ex02/identify
   ```

## 📚 Detaylı Açıklamalar

Her egzersiz için detaylı açıklamalar, algoritma analizi ve kullanım örnekleri için `EXERCISES.md` dosyasını inceleyin.

## ⚠️ Önemli Notlar

- Tüm projeler C++98 standardı ile uyumludur
- Memory leak'lerden kaçınmak için dikkatli olun
- Exception handling gerekli durumlarda kullanılmıştır
- Compiler warnings'ler error olarak değerlendirilir

## 🎓 Öğrenme Çıktıları

Bu projeyi tamamladıktan sonra:
- C++ tip sistemini anlayacaksınız
- Güvenli tip dönüşümlerini öğreneceksiniz
- Memory management konularında deneyim kazanacaksınız
- RTTI ve polymorphism kavramlarını pekiştireceksiniz
