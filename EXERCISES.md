# C++ Module 06 - Detaylı Egzersiz Açıklamaları

## 📚 İçindekiler

- [Exercise 00: Scalar Converter](#exercise-00-scalar-converter)
- [Exercise 01: Serializer](#exercise-01-serializer)
- [Exercise 02: Type Identification](#exercise-02-type-identification)

---

## Exercise 00: Scalar Converter

### 🎯 Amaç
String literal'ları C++ temel veri tiplerine (char, int, float, double) dönüştüren bir converter sınıfı oluşturmak.

### 🛠️ Teknolojiler
- **Static Methods**: Sınıf instantiation'ı olmadan kullanım
- **Type Validation**: Input doğrulama
- **Exception Handling**: Hatalı input'lar için exception
- **String Parsing**: std::stringstream ve std::strtod
- **Special Literals**: nan, inf değerleri

### 📁 Dosya Yapısı
```
ex00/
├── ScalarConverter.hpp  # Sınıf tanımı
├── ScalarConverter.cpp  # Implementasyon
├── main.cpp            # Test programı
└── Makefile            # Build konfigürasyonu
```

### 🔧 Derleme ve Çalıştırma

#### Derleme
```bash
cd ex00
make
```

#### Çalıştırma
```bash
./convert <literal>
```

#### Örnek Kullanımlar
```bash
./convert "42"          # Integer
./convert "42.0f"       # Float
./convert "42.0"        # Double
./convert "a"           # Character
./convert "nan"         # Special literal
./convert "+inf"        # Positive infinity
./convert "-inf"        # Negative infinity
```

### 🧠 Algoritma Analizi

#### 1. Input Validation
```cpp
void validateInput(const std::string &input)
{
    if (isSpecialLiteral(input) || input.length() == 1)
        return;
    
    const std::string allowed = "0123456789f.+-";
    // Sadece geçerli karakterlere izin ver
}
```

#### 2. Special Literal Detection
```cpp
bool isSpecialLiteral(const std::string &input)
{
    return (input == "nan" || input == "nanf" ||
            input == "+inf" || input == "-inf" ||
            input == "+inff" || input == "-inff");
}
```

#### 3. Type Conversion Flow
1. **Input Validation**: Geçerli karakter kontrolü
2. **Special Literal Check**: nan, inf kontrolü
3. **Character Detection**: Tek karakter kontrolü
4. **Numeric Parsing**: Sayısal değer parsing'i
5. **Output Formatting**: Uygun format ile çıktı

### ⚠️ Dikkat Edilmesi Gerekenler

- **Non-displayable Characters**: ASCII 32-126 arası olmayan karakterler
- **Overflow Protection**: int sınırları aşımı kontrolü
- **Precision Handling**: Float/Double precision gösterimi
- **Exception Safety**: Hatalı input'lar için güvenli handling

### 🧪 Test Senaryoları

| Input | char | int | float | double |
|-------|------|-----|-------|--------|
| "42" | '*' | 42 | 42.0f | 42.0 |
| "42.5f" | impossible | impossible | 42.5f | 42.5 |
| "a" | 'a' | 97 | 97.0f | 97.0 |
| "nan" | impossible | impossible | nanf | nan |

---

## Exercise 01: Serializer

### 🎯 Amaç
Pointer'ları integer'a serialize edip, tekrar pointer'a deserialize eden bir sistem oluşturmak.

### 🛠️ Teknolojiler
- **reinterpret_cast**: Pointer-memory dönüşümleri
- **uintptr_t**: Pointer boyutunda integer tipi
- **Memory Management**: new/delete operatörleri
- **Static Methods**: Utility sınıfı

### 📁 Dosya Yapısı
```
ex01/
├── Serializer.hpp  # Sınıf ve Data struct tanımı
├── Serializer.cpp  # Implementasyon
├── main.cpp        # Test programı
└── Makefile        # Build konfigürasyonu
```

### 🔧 Derleme ve Çalıştırma

#### Derleme
```bash
cd ex01
make
```

#### Çalıştırma
```bash
./serializer
```

### 🧠 Algoritma Analizi

#### 1. Data Structure
```cpp
struct Data
{
    int age;
    std::string name;
};
```

#### 2. Serialization Process
```cpp
uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
```

#### 3. Deserialization Process
```cpp
Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
```

### 🔄 İşlem Akışı

1. **Data Creation**: Dinamik Data objesi oluşturma
2. **Serialization**: Pointer → uintptr_t dönüşümü
3. **Deserialization**: uintptr_t → Pointer dönüşümü
4. **Verification**: Orijinal ve restore edilen data karşılaştırması
5. **Cleanup**: Memory temizliği

### ⚠️ Dikkat Edilmesi Gerekenler

- **Memory Safety**: Pointer'ların geçerli olması
- **Type Safety**: reinterpret_cast güvenliği
- **Platform Dependency**: uintptr_t boyutu platform'a bağlı
- **Memory Leaks**: delete operatörü kullanımı

### 🧪 Test Çıktısı
```
Original Data:
 Name: Asim
 Age : 25

Restored Data:
 Name: Asim
 Age : 25
```

---

## Exercise 02: Type Identification

### 🎯 Amaç
Runtime'da Base pointer'ının hangi derived class'a ait olduğunu tespit etmek.

### 🛠️ Teknolojiler
- **dynamic_cast**: Runtime tip kontrolü
- **RTTI (Runtime Type Information)**: Tip bilgisi
- **Polymorphism**: Virtual functions
- **Exception Handling**: dynamic_cast exception'ları
- **Random Generation**: std::rand, std::srand

### 📁 Dosya Yapısı
```
ex02/
├── Base.hpp        # Base class
├── Base.cpp        # Base implementasyonu
├── A.hpp, B.hpp, C.hpp  # Derived classes
├── Identify.cpp    # Identification fonksiyonları
├── main.cpp        # Test programı
└── Makefile        # Build konfigürasyonu
```

### 🔧 Derleme ve Çalıştırma

#### Derleme
```bash
cd ex02
make
```

#### Çalıştırma
```bash
./identify
```

### 🧠 Algoritma Analizi

#### 1. Class Hierarchy
```cpp
class Base { virtual ~Base(); };
class A : public Base {};
class B : public Base {};
class C : public Base {};
```

#### 2. Random Object Generation
```cpp
Base* generate(void)
{
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}
```

#### 3. Pointer Identification
```cpp
void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) { std::cout << "A" << std::endl; return; }
    if (dynamic_cast<B*>(p)) { std::cout << "B" << std::endl; return; }
    if (dynamic_cast<C*>(p)) { std::cout << "C" << std::endl; return; }
}
```

#### 4. Reference Identification
```cpp
void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; } catch (...) {}
}
```

### 🔄 İşlem Akışı

1. **Random Seed**: std::srand ile seed ayarlama
2. **Object Generation**: Rastgele derived class objesi oluşturma
3. **Pointer Identification**: dynamic_cast ile pointer tip tespiti
4. **Reference Identification**: dynamic_cast ile reference tip tespiti
5. **Memory Cleanup**: delete operatörü ile temizlik

### ⚠️ Dikkat Edilmesi Gerekenler

- **Virtual Destructor**: Base class'ta virtual destructor gerekli
- **RTTI Enable**: Compiler'da RTTI aktif olmalı
- **Exception Handling**: Reference casting'de exception yakalama
- **Memory Management**: new/delete eşleşmesi

### 🧪 Test Çıktısı Örnekleri
```
A
A
```
veya
```
B
B
```
veya
```
C
C
```

### 🔍 Dynamic Cast Detayları

#### Pointer Casting
- **Başarılı**: Geçerli pointer döner
- **Başarısız**: nullptr döner

#### Reference Casting
- **Başarılı**: Geçerli reference döner
- **Başarısız**: std::bad_cast exception fırlatır

### 📊 Performans Notları

- **RTTI Overhead**: Runtime tip kontrolü ek maliyet
- **Virtual Table**: Her sınıf için vtable gerekli
- **Exception Cost**: Reference casting'de exception maliyeti

---

## 🎓 Genel Öğrenme Çıktıları

### Teknik Beceriler
- C++ tip sistemi anlayışı
- Memory management becerileri
- Exception handling deneyimi
- Build system kullanımı

### Kavramsal Anlayış
- Type safety prensipleri
- Polymorphism kavramları
- RTTI mekanizması
- Casting güvenliği

### Best Practices
- RAII prensipleri
- Exception safety
- Memory leak prevention
- Code organization
